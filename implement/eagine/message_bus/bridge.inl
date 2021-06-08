/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/base64.hpp>
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

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// bridge_state
//------------------------------------------------------------------------------
class bridge_state : public std::enable_shared_from_this<bridge_state> {
public:
    bridge_state(const valid_if_positive<span_size_t>& max_data_size)
      : _max_read{extract_or(max_data_size, 2048) * 2} {}
    bridge_state(bridge_state&&) = delete;
    bridge_state(const bridge_state&) = delete;
    auto operator=(bridge_state&&) = delete;
    auto operator=(const bridge_state&) = delete;
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

    auto input_usable() noexcept {
        std::unique_lock lock{_input_mutex};
        return _input.good();
    }

    auto output_usable() noexcept {
        std::unique_lock lock{_output_mutex};
        return _output.good();
    }

    auto is_usable() noexcept {
        return input_usable() && output_usable();
    }

    void push(message_id msg_id, const message_view& message) {
        std::unique_lock lock{_output_mutex};
        _outgoing.back().push(msg_id, message);
    }

    void notify_output_ready() {
        _output_ready.notify_one();
    }

    auto forwarded_messages() const noexcept {
        return _forwarded_messages;
    }

    auto dropped_messages() const noexcept {
        return _dropped_messages;
    }

    auto decode_errors() const noexcept {
        return _decode_errors;
    }

    void send_output() {
        auto handler =
          [this](message_id msg_id, message_age msg_age, message_view message) {
              if(EAGINE_UNLIKELY(message.add_age(msg_age).too_old())) {
                  ++_dropped_messages;
              } else {
                  default_serializer_backend backend(_sink);
                  serialize_message_header(msg_id, message, backend);

                  span_size_t i = 0;
                  do_dissolve_bits(
                    make_span_getter(i, message.data()),
                    [this](byte b) {
                        const auto encode{make_base64_encode_transform()};
                        if(auto opt_c{encode(b)}) {
                            this->_output << extract(opt_c);
                            return true;
                        }
                        return false;
                    },
                    6);

                  _output << '\n' << std::flush;
                  ++_forwarded_messages;
              }
              return true;
          };
        auto& queue = [this]() -> message_storage& {
            std::unique_lock lock{_output_mutex};
            _output_ready.wait(lock);
            _outgoing.swap();
            return _outgoing.front();
        }();
        queue.fetch_all({construct_from, handler});
    }

    using fetch_handler = message_storage::fetch_handler;

    auto fetch_messages(fetch_handler handler) {
        auto& queue = [this]() -> message_storage& {
            std::unique_lock lock{_input_mutex};
            _incoming.swap();
            return _incoming.front();
        }();
        return queue.fetch_all(handler);
    }

    void recv_input() {
        if(auto pos{_source.scan_for('\n', _max_read)}) {
            block_data_source source(_source.top(extract(pos)));
            default_deserializer_backend backend(source);
            identifier class_id{};
            identifier method_id{};
            _recv_dest.clear_data();
            const auto errors = deserialize_message_header(
              class_id, method_id, _recv_dest, backend);

            if(EAGINE_UNLIKELY(errors)) {
                ++_decode_errors;
            } else {
                _buffer.ensure(source.remaining().size());
                span_size_t i = 0;
                span_size_t o = 0;
                if(do_concentrate_bits(
                     make_span_getter(
                       i, source.remaining(), make_base64_decode_transform()),
                     make_span_putter(o, cover(_buffer)),
                     6)) {
                    _recv_dest.store_content(head(view(_buffer), o));
                }

                std::unique_lock lock{_input_mutex};
                _incoming.back().push({class_id, method_id}, _recv_dest);
            }
            _source.pop(extract(pos) + 1);
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
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

    memory::buffer _buffer{};
    double_buffer<message_storage> _outgoing{};
    double_buffer<message_storage> _incoming{};
    stored_message _recv_dest{};
    span_size_t _forwarded_messages{0};
    span_size_t _dropped_messages{0};
    span_size_t _decode_errors{0};
};
//------------------------------------------------------------------------------
// bridge
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_uptime_seconds() -> std::int64_t {
    return std::chrono::duration_cast<std::chrono::seconds>(
             std::chrono::steady_clock::now() - _startup_time)
      .count();
}
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
auto bridge::add_connection(std::unique_ptr<connection> conn) -> bool {
    _connection = std::move(conn);
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::_setup_from_config() {
    // TODO: use app_config()
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_id_assigned(const message_view& message)
  -> message_handling_result {
    if(!has_id()) {
        _id = message.target_id;
        log_debug("assigned bridge id ${id} by router").arg(EAGINE_ID(id), _id);
    }
    return was_handled;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_id_confirmed(const message_view& message)
  -> message_handling_result {
    if(has_id()) {
        if(_id != message.target_id) {
            log_error("mismatching current and confirmed ids")
              .arg(EAGINE_ID(current), _id)
              .arg(EAGINE_ID(confirmed), message.target_id);
        }
    } else {
        log_warning("confirming unset id ${newId}")
          .arg(EAGINE_ID(confirmed), message.target_id);
    }
    return was_handled;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_ping(const message_view& message, bool to_connection)
  -> message_handling_result {
    if(has_id()) {
        if(_id == message.target_id) {
            message_view response{};
            response.setup_response(message);
            response.set_source_id(_id);
            if(to_connection) {
                _do_push(EAGINE_MSGBUS_ID(pong), response);
            } else {
                _send(EAGINE_MSGBUS_ID(pong), response);
            }
            return was_handled;
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_topo_bridge_conn(
  const message_view& message,
  bool to_connection) -> message_handling_result {
    if(to_connection) {
        bridge_topology_info info{};
        if(default_deserialize(info, message.content())) {
            info.opposite_id = _id;
            auto temp{default_serialize_buffer_for(info)};
            if(auto serialized{default_serialize(info, cover(temp))}) {
                message_view response{message, extract(serialized)};
                _send(EAGINE_MSGBUS_ID(topoBrdgCn), response);
                return was_handled;
            }
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_topology_query(
  const message_view& message,
  bool to_connection) -> message_handling_result {
    bridge_topology_info info{};
    info.bridge_id = _id;
    info.instance_id = _instance_id;
    auto temp{default_serialize_buffer_for(info)};
    if(auto serialized{default_serialize(info, cover(temp))}) {
        message_view response{extract(serialized)};
        response.setup_response(message);
        if(to_connection) {
            _do_push(EAGINE_MSGBUS_ID(topoBrdgCn), response);
        } else {
            _send(EAGINE_MSGBUS_ID(topoBrdgCn), response);
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_stats_query(const message_view& message, bool to_connection)
  -> message_handling_result {
    _stats.forwarded_messages = _forwarded_messages_i2c;
    _stats.dropped_messages = _dropped_messages_i2c;
    _stats.uptime_seconds = _uptime_seconds();

    const auto now = std::chrono::steady_clock::now();
    const std::chrono::duration<float> seconds{now - _forwarded_since_stat};
    if(EAGINE_LIKELY(seconds.count() > 15.F)) {
        _forwarded_since_stat = now;

        _stats.messages_per_second = static_cast<std::int32_t>(
          float(_stats.forwarded_messages - _prev_forwarded_messages) /
          seconds.count());
        _prev_forwarded_messages = _stats.forwarded_messages;
    }

    auto bs_buf{default_serialize_buffer_for(_stats)};
    if(auto serialized{default_serialize(_stats, cover(bs_buf))}) {
        message_view response{extract(serialized)};
        response.setup_response(message);
        response.set_source_id(_id);
        if(to_connection) {
            _do_push(EAGINE_MSGBUS_ID(statsBrdg), response);
        } else {
            _send(EAGINE_MSGBUS_ID(statsBrdg), response);
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_handle_special(
  message_id msg_id,
  const message_view& message,
  bool to_connection) -> message_handling_result {
    if(EAGINE_UNLIKELY(is_special_message(msg_id))) {
        log_debug("bridge handling special message ${message}")
          .arg(EAGINE_ID(bridge), _id)
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(target), message.target_id)
          .arg(EAGINE_ID(source), message.source_id);

        if(msg_id.has_method(EAGINE_ID(assignId))) {
            return _handle_id_assigned(message);
        } else if(msg_id.has_method(EAGINE_ID(confirmId))) {
            return _handle_id_confirmed(message);
        } else if(msg_id.has_method(EAGINE_ID(ping))) {
            return _handle_ping(message, to_connection);
        } else if(msg_id.has_method(EAGINE_ID(topoBrdgCn))) {
            return _handle_topo_bridge_conn(message, to_connection);
        } else if(msg_id.has_method(EAGINE_ID(topoQuery))) {
            return _handle_topology_query(message, to_connection);
        } else if(msg_id.has_method(EAGINE_ID(statsQuery))) {
            return _handle_stats_query(message, to_connection);
        } else if(msg_id.has_method(EAGINE_ID(msgFlowInf))) {
            return was_handled;
        }
    }
    return should_be_forwarded;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_do_send(message_id msg_id, message_view& message) -> bool {
    message.add_hop();
    if(EAGINE_LIKELY(_connection)) {
        if(_connection->send(msg_id, message)) {
            log_trace("forwarding message ${message} to connection")
              .arg(EAGINE_ID(message), msg_id)
              .arg(EAGINE_ID(data), message.data());
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_send(message_id msg_id, message_view& message) -> bool {
    EAGINE_ASSERT(has_id());
    message.set_source_id(_id);
    return _do_send(msg_id, message);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_do_push(message_id msg_id, message_view& message) -> bool {
    if(EAGINE_LIKELY(_state)) {
        message.add_hop();
        _state->push(msg_id, message);
        log_trace("forwarding message ${message} to stream")
          .arg(EAGINE_ID(message), msg_id)
          .arg(EAGINE_ID(data), message.data());
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_forward_messages() -> work_done {
    some_true something_done{};

    auto forward_conn_to_output =
      [this](message_id msg_id, message_age msg_age, message_view message) {
          _message_age_sum_c2o += message.add_age(msg_age).age().count();
          if(EAGINE_UNLIKELY(message.too_old())) {
              ++_dropped_messages_c2o;
              return true;
          }
          if(EAGINE_UNLIKELY(++_forwarded_messages_c2o % 1000000 == 0)) {
              const auto now{std::chrono::steady_clock::now()};
              const std::chrono::duration<float> interval{
                now - _forwarded_since_c2o};

              if(EAGINE_LIKELY(interval > decltype(interval)::zero())) {
                  const auto msgs_per_sec{1000000.F / interval.count()};
                  const auto avg_msg_age =
                    _message_age_sum_c2o /
                    float(_forwarded_messages_c2o + _dropped_messages_c2o + 1);

                  log_chart_sample(EAGINE_ID(msgPerSecO), msgs_per_sec);
                  log_stat("forwarded ${count} messages to output queue")
                    .arg(EAGINE_ID(count), _forwarded_messages_c2o)
                    .arg(EAGINE_ID(dropped), _dropped_messages_c2o)
                    .arg(EAGINE_ID(interval), interval)
                    .arg(EAGINE_ID(avgMsgAge), avg_msg_age)
                    .arg(EAGINE_ID(msgsPerSec), msgs_per_sec);
              }

              _forwarded_since_c2o = now;
          }
          if(this->_handle_special(msg_id, message, false) == was_handled) {
              return true;
          }
          return this->_do_push(msg_id, message);
      };

    if(EAGINE_LIKELY(_connection)) {
        something_done(_connection->fetch_messages(
          {construct_from, forward_conn_to_output}));
    }
    _state->notify_output_ready();

    auto forward_input_to_conn =
      [this](message_id msg_id, message_age msg_age, message_view message) {
          _message_age_sum_i2c += message.add_age(msg_age).age().count();
          if(EAGINE_UNLIKELY(message.too_old())) {
              ++_dropped_messages_i2c;
              return true;
          }
          if(EAGINE_UNLIKELY(++_forwarded_messages_i2c % 1000000 == 0)) {
              const auto now{std::chrono::steady_clock::now()};
              const std::chrono::duration<float> interval{
                now - _forwarded_since_i2c};

              if(EAGINE_LIKELY(interval > decltype(interval)::zero())) {
                  const auto msgs_per_sec{1000000.F / interval.count()};
                  const auto avg_msg_age =
                    _message_age_sum_i2c /
                    float(_forwarded_messages_i2c + _dropped_messages_i2c + 1);

                  _stats.message_age_milliseconds =
                    static_cast<std::int32_t>(avg_msg_age * 1000.F);

                  log_chart_sample(EAGINE_ID(msgPerSecI), msgs_per_sec);
                  log_stat("forwarded ${count} messages from input")
                    .arg(EAGINE_ID(count), _forwarded_messages_i2c)
                    .arg(EAGINE_ID(dropped), _dropped_messages_i2c)
                    .arg(EAGINE_ID(interval), interval)
                    .arg(EAGINE_ID(avgMsgAge), avg_msg_age)
                    .arg(EAGINE_ID(msgsPerSec), msgs_per_sec);
              }

              _forwarded_since_i2c = now;
          }
          if(this->_handle_special(msg_id, message, true) == was_handled) {
              return true;
          }
          this->_do_send(msg_id, message);
          return true;
      };

    if(EAGINE_LIKELY(_state)) {
        something_done(
          _state->fetch_messages({construct_from, forward_input_to_conn}));
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_recoverable_state() const noexcept -> bool {
    return std::cin.good() && std::cout.good();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_check_state() -> work_done {
    some_true something_done{};

    if(EAGINE_UNLIKELY(!(_state && _state->is_usable()))) {
        if(_recoverable_state() && _connection) {
            if(auto max_data_size = _connection->max_data_size()) {
                ++_state_count;
                _state = std::make_shared<bridge_state>(extract(max_data_size));
                _state->start();
                something_done();
            }
        }
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::_update_connections() -> work_done {
    some_true something_done{};

    if(EAGINE_LIKELY(_connection)) {
        if(EAGINE_UNLIKELY(!has_id() && _no_id_timeout)) {
            log_debug("requesting bridge id");
            _connection->send(EAGINE_MSGBUS_ID(requestId), {});
            _no_id_timeout.reset();
            something_done();
        }
        if(_connection->update()) {
            something_done();
            _no_connection_timeout.reset();
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::update() -> work_done {
    some_true something_done{};

    const bool had_id = has_id();
    something_done(_check_state());
    something_done(_update_connections());
    something_done(_forward_messages());

    // if processing the messages assigned the id
    if(EAGINE_UNLIKELY(has_id() && !had_id)) {
        log_debug("announcing id ${id}").arg(EAGINE_ID(id), _id);
        message_view msg;
        _send(EAGINE_MSGBUS_ID(announceId), msg);
        something_done();
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge::is_done() const noexcept -> bool {
    return no_connection_timeout() || !_recoverable_state();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::say_bye() {
    const auto msgid = EAGINE_MSGBUS_ID(byeByeBrdg);
    message_view msg{};
    msg.set_source_id(_id);
    if(_connection) {
        _connection->send(msgid, msg);
        _connection->update();
    }
    if(_state) {
        _do_push(msgid, msg);
        _state->notify_output_ready();
        std::this_thread::sleep_for(std::chrono::seconds{1});
    }
    _forward_messages();
    _update_connections();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::cleanup() {
    if(_connection) {
        _connection->cleanup();
    }
    const auto avg_msg_age_c2o =
      _message_age_sum_c2o /
      float(_forwarded_messages_c2o + _dropped_messages_c2o + 1);
    const auto avg_msg_age_i2c =
      _message_age_sum_i2c /
      float(_forwarded_messages_i2c + _dropped_messages_i2c + 1);

    if(_state) {
        log_stat("forwarded ${count} messages in total to output stream")
          .arg(EAGINE_ID(count), _state->forwarded_messages())
          .arg(EAGINE_ID(dropped), _state->dropped_messages())
          .arg(EAGINE_ID(decodeErr), _state->decode_errors())
          .arg(EAGINE_ID(stateCount), _state_count);
    }

    log_stat("forwarded ${count} messages in total to output queue")
      .arg(EAGINE_ID(count), _forwarded_messages_c2o)
      .arg(EAGINE_ID(dropped), _dropped_messages_c2o)
      .arg(EAGINE_ID(avgMsgAge), avg_msg_age_c2o);

    log_stat("forwarded ${count} messages in total to connection")
      .arg(EAGINE_ID(count), _forwarded_messages_i2c)
      .arg(EAGINE_ID(dropped), _dropped_messages_i2c)
      .arg(EAGINE_ID(avgMsgAge), avg_msg_age_i2c);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::finish() {
    say_bye();
    timeout too_long{adjusted_duration(std::chrono::seconds{1})};
    while(!too_long) {
        update();
    }
    cleanup();
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
