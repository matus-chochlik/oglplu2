/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/double_buffer.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/message_bus/message.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <eagine/serialize/istream_source.hpp>
#include <eagine/serialize/ostream_sink.hpp>
#include <condition_variable>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
// bridge_state
//------------------------------------------------------------------------------
class bridge_state : public std::enable_shared_from_this<bridge_state> {
public:
    bridge_state(const valid_if_positive<span_size_t>& max_data_size)
      : _max_read{extract_or(max_data_size, 512) * 2} {
    }
    bridge_state(bridge_state&&) = delete;
    bridge_state(const bridge_state&) = delete;
    bridge_state& operator=(bridge_state&&) = delete;
    bridge_state& operator=(const bridge_state&) = delete;
    ~bridge_state() noexcept {
        _output_ready.notify_all();
    }

    auto weak_ref() noexcept {
        return std::weak_ptr(this->shared_from_this());
    }

    auto make_input_main() {
        return [selfref{weak_ref()}]() {
            while(auto self{selfref.lock()}) {
                self->recv_input();
            }
        };
    }

    auto make_output_main() {
        return [selfref{weak_ref()}]() {
            while(auto self{selfref.lock()}) {
                self->send_output();
            }
        };
    }

    void start() {
        std::thread(make_input_main()).detach();
        std::thread(make_output_main()).detach();
    }

    bool input_usable() noexcept {
        std::unique_lock lock{_input_mutex};
        return _input.good();
    }

    bool output_usable() noexcept {
        std::unique_lock lock{_output_mutex};
        return _output.good();
    }

    bool is_usable() noexcept {
        return input_usable() && output_usable();
    }

    void push(message_id msg_id, const message_view& message) {
        std::unique_lock lock{_output_mutex};
        _outgoing.front().push(msg_id, message);
    }

    void notify_output_ready() {
        _output_ready.notify_one();
    }

    void send_output() {
        {
            std::unique_lock lock{_output_mutex};
            _output_ready.wait(lock);
            _outgoing.swap();
        }
        auto handler = [this](message_id msg_id, const message_view& message) {
            string_serializer_backend backend(_sink);
            serialize_message(msg_id, message, backend);
            _output << '\n';
            return true;
        };
        _outgoing.back().fetch_all(fetch_handler(handler));
        _output << std::flush;
    }

    using fetch_handler = message_storage::fetch_handler;

    bool fetch_messages(fetch_handler handler) {
        {
            std::unique_lock lock{_input_mutex};
            _incoming.swap();
        }
        return _incoming.back().fetch_all(handler);
    }

    void recv_input() {
        if(auto pos{_source.scan_for('\n', _max_read)}) {
            block_data_source source(_source.top(extract(pos)));
            string_deserializer_backend backend(source);
            message_id msg_id{};
            _recv_dest.clear_data();
            const auto errors =
              deserialize_message(msg_id, _recv_dest, backend);
            if(!errors) {
                std::unique_lock lock{_input_mutex};
                _incoming.front().push(msg_id, _recv_dest);
            }
            _source.pop(extract(pos) + 1);
        }
    }

private:
    const span_size_t _max_read;

    std::mutex _input_mutex{};
    std::mutex _output_mutex{};

    std::condition_variable _output_ready{};

    std::istream& _input{std::cin};
    std::ostream& _output{std::cout};

    istream_data_source _source{_input};
    ostream_data_sink _sink{_output};

    double_buffer<message_storage> _outgoing{};
    double_buffer<message_storage> _incoming{};
    stored_message _recv_dest{};
};
//------------------------------------------------------------------------------
// bridge
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::add_certificate_pem(memory::const_block blk) {
    if(_context) {
        _context->add_own_certificate_pem(blk);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::add_ca_certificate_pem(memory::const_block blk) {
    if(_context) {
        _context->add_ca_certificate_pem(blk);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::add_connection(std::unique_ptr<connection> conn) {
    _connections.emplace_back(std::move(conn));
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::_setup_from_args(const program_args&) {
    // TODO
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_handle_special(message_id msg_id, message_view message) {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        _log.debug("handling special message ${message}")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(msg_id.has_method(EAGINE_ID(assignId))) {
            if(!has_id()) {
                _id = message.target_id;
                _log.debug("assigned id ${id}").arg(EAGINE_ID(id), _id);
            }
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_do_send(message_id msg_id, message_view message) {
    message.add_hop();
    for(auto& connection : _connections) {
        EAGINE_ASSERT(connection);
        if(connection->send(msg_id, message)) {
            _log.trace("forwarding message ${message} to connection")
              .arg(EAGINE_ID(message), msg_id)
              .arg(EAGINE_ID(data), message.data);
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_send(message_id msg_id, message_view message) {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_id);
    return _do_send(msg_id, message);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_do_push(message_id msg_id, message_view message) {
    if(EAGINE_LIKELY(_state)) {
        message.add_hop();
        _state->push(msg_id, message);
        _log.trace("forwarding message ${message} to stream")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(data), message.data);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_forward_messages() {
    some_true something_done{};

    auto forward_conn_to_output =
      [this](message_id msg_id, const message_view& message) {
          if(EAGINE_UNLIKELY(++_forwarded_messages_c2o % 100000 == 0)) {
              _log.stat("forwarded ${count} messages to output")
                .arg(EAGINE_ID(count), _forwarded_messages_c2o);
          }
          if(this->_handle_special(msg_id, message)) {
              return true;
          }
          return this->_do_push(msg_id, message);
      };

    for(auto& conn : _connections) {
        if(EAGINE_LIKELY(conn && conn->is_usable())) {
            something_done(conn->fetch_messages(
              connection::fetch_handler(forward_conn_to_output)));
        }
    }
    _state->notify_output_ready();

    auto forward_input_to_conn =
      [this](message_id msg_id, const message_view& message) {
          if(EAGINE_UNLIKELY(++_forwarded_messages_i2c % 100000 == 0)) {
              _log.stat("forwarded ${count} messages from input")
                .arg(EAGINE_ID(count), _forwarded_messages_i2c);
          }
          if(this->_handle_special(msg_id, message)) {
              return true;
          }
          this->_do_send(msg_id, message);
          return true;
      };

    if(EAGINE_LIKELY(_state)) {
        something_done(_state->fetch_messages(
          connection::fetch_handler(forward_input_to_conn)));
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_check_state() {
    some_true something_done{};

    if(EAGINE_UNLIKELY(!(_state && _state->is_usable()))) {
        span_size_t max_size{0};
        for(auto& conn : _connections) {
            if(auto max_data_size = conn->max_data_size()) {
                max_size = math::maximum(max_size, extract(max_data_size));
            }
        }
        _state = std::make_shared<bridge_state>(max_size);
        _state->start();
        something_done();
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_update_connections() {
    some_true something_done{};

    for(auto& conn : _connections) {
        if(EAGINE_LIKELY(conn)) {
            if(conn->update()) {
                something_done();
                _no_connection_timeout.reset();
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::update() {
    some_true something_done{};

    const bool had_id = has_id();
    something_done(_check_state());
    something_done(_update_connections());
    something_done(_forward_messages());

    // if processing the messages assigned the id
    if(EAGINE_UNLIKELY(has_id() && !had_id)) {
        _log.debug("announcing id ${id}").arg(EAGINE_ID(id), _id);
        _send(EAGINE_MSG_ID(eagiMsgBus, announceId), {});
        something_done();
    }

    return something_done;
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

