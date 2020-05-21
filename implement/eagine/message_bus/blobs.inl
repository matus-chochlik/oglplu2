/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <eagine/serialize/block_sink.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::cleanup() {
    some_true something_done{};
    auto predicate = [this, &something_done](auto& pending) {
        if(pending.max_time.is_elapsed()) {
            _buffers.eat(std::move(pending.blob));
            something_done();
            return true;
        }
        return false;
    };

    _incoming.erase(
      std::remove_if(_incoming.begin(), _incoming.end(), predicate),
      _incoming.end());

    _outgoing.erase(
      std::remove_if(_outgoing.begin(), _outgoing.end(), predicate),
      _outgoing.end());

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void blob_manipulator::push_outgoing(
  identifier_t class_id,
  identifier_t method_id,
  identifier_t target_id,
  memory::const_block blob,
  std::chrono::seconds max_time,
  message_priority priority) {
    _outgoing.emplace_back();
    auto& pending = _outgoing.back();
    pending.class_id = class_id;
    pending.method_id = method_id;
    pending.target_id = target_id;
    pending.blob_id = _blob_id_sequence++;
    pending.blob = _buffers.get(blob.size());
    copy(blob, cover(pending.blob));
    pending.current = {view(pending.blob)};
    pending.max_time = timeout{max_time};
    pending.priority = priority;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void blob_manipulator::for_each_outgoing(handler handle) {
    for(auto& pending : _outgoing) {
        handle(pending);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::process_outgoing(
  send_handler do_send, span_size_t, logger& log) {
    some_true something_done{};

    const auto msg_id = EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt);
    // TODO: variable fragment size depending on priority and message_size
    std::array<byte, 4096> temp{};

    for(auto& pending : _outgoing) {
        if(pending.current.tail()) {
            const auto header = std::make_tuple(
              identifier(pending.class_id),
              identifier(pending.method_id),
              pending.blob_id,
              pending.current.split_position());

            block_data_sink sink(cover(temp));
            default_serializer_backend backend(sink);
            auto errors = serialize(header, backend);
            if(!errors) {
                if(auto written = sink.write_some(pending.current)) {
                    pending.current = extract(written);
                    message_view message(sink.done());
                    message.set_target_id(pending.target_id);
                    message.set_priority(pending.priority);
                    something_done(
                      do_send(msg_id.class_id(), msg_id.method_id(), message));
                } else {
                    log.debug("failed to write fragment of blob ${message}")
                      .arg(EAGINE_ID(errors), get_errors(written))
                      .arg(
                        EAGINE_ID(message),
                        message_id_tuple(pending.class_id, pending.method_id));
                }
            } else {
                log.debug("failed to serialize header of blob ${message}")
                  .arg(EAGINE_ID(errors), errors)
                  .arg(
                    EAGINE_ID(message),
                    message_id_tuple(pending.class_id, pending.method_id));
            }
        }
    }

    return something_done;
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

