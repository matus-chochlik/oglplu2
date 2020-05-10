/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/message_bus/message.hpp>
#include <eagine/message_bus/serialize.hpp>
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
    bridge_state() = default;

    auto weak_ref() noexcept {
        return std::weak_ptr(this->shared_from_this());
    }

    auto make_output_main() {
        return [selfref{weak_ref()}]() {
            while(auto self{selfref.lock()}) {
                self->send_output();
            }
        };
    }

    void start() {
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

    void push(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        std::unique_lock lock{_output_mutex};
        _outgoing.push(class_id, method_id, message);
        _output_ready.notify_one();
    }

    void send_output() {
        std::unique_lock lock{_output_mutex};
        _output_ready.wait(lock, [this]() { return !_outgoing.empty(); });
        _outgoing.fetch_all(
          {this, EAGINE_MEM_FUNC_C(bridge_state, _handle_send)});
    }

private:
    bool _handle_send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        ostream_data_sink sink(_output << '!');
        string_serializer_backend backend(sink);
        serialize_message(class_id, method_id, message, backend);
        _output << '\n';
        return true;
    }

    std::mutex _input_mutex{};
    std::mutex _output_mutex{};

    std::condition_variable _output_ready{};

    std::istream& _input{std::cin};
    std::ostream& _output{std::cout};

    message_storage _outgoing{};
};
//------------------------------------------------------------------------------
// bridge
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
bool bridge::_handle_special(
  identifier_t class_id, identifier_t method_id, message_view message) {
    if(EAGINE_UNLIKELY(EAGINE_ID(eagiMsgBus).matches(class_id))) {
        if(EAGINE_ID(assignId).matches(method_id)) {
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
bool bridge::_do_send(
  identifier_t class_id, identifier_t method_id, message_view message) {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_id);
    for(auto& connection : _connections) {
        EAGINE_ASSERT(connection);
        if(connection->send(class_id, method_id, message)) {
            _log.trace("sending message ${message}")
              .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_do_forward_message(
  identifier_t class_id, identifier_t method_id, message_view message) {
    if(EAGINE_LIKELY(_state)) {
        _state->push(class_id, method_id, message);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_forward_messages() {
    some_true something_done{};

    auto handler = [this](
                     identifier_t class_id,
                     identifier_t method_id,
                     const message_view& message) {
        if(this->_handle_special(class_id, method_id, message)) {
            return true;
        }
        return this->_do_forward_message(class_id, method_id, message);
    };

    for(auto& conn : _connections) {
        if(EAGINE_LIKELY(conn && conn->is_usable())) {
            something_done(
              conn->fetch_messages(connection::fetch_handler(handler)));
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_check_state() {
    some_true something_done{};

    if(EAGINE_UNLIKELY(!(_state && _state->is_usable()))) {
        _state = std::make_shared<bridge_state>();
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
        _do_send(EAGINE_MSG_ID(eagiMsgBus, announceId), {});
        something_done();
    }

    return something_done;
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

