/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <eagine/serialize/block_sink.hpp>
#include <eagine/serialize/block_source.hpp>

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
bool blob_manipulator::push_incoming_fragment(
  identifier_t class_id,
  identifier_t method_id,
  identifier_t source_id,
  identifier_t blob_id,
  std::int64_t offset,
  std::int64_t total,
  memory::const_block fragment,
  message_priority priority) {

    auto pos = std::find_if(
      _incoming.begin(), _incoming.end(), [blob_id](const auto& pending) {
          return pending.blob_id == blob_id;
      });
    if(pos != _incoming.end()) {
        auto& pending = *pos;
        if(EAGINE_LIKELY(pending.blob.size() == span_size(total))) {
            if(EAGINE_LIKELY(pending.class_id == class_id)) {
                if(EAGINE_LIKELY(pending.class_id == class_id)) {
                    pending.max_time.reset();
                    if(EAGINE_UNLIKELY(pending.priority < priority)) {
                        pending.priority = priority;
                    }
                    // TODO
                    EAGINE_MAYBE_UNUSED(source_id);
                    EAGINE_MAYBE_UNUSED(offset);
                    EAGINE_MAYBE_UNUSED(fragment);
                    return true;
                } else {
                    _log.debug("method_id mismatch in blob fragment message")
                      .arg(EAGINE_ID(pending), identifier(pending.method_id))
                      .arg(EAGINE_ID(message), identifier(method_id));
                }
            } else {
                _log.debug("class_id mismatch in blob fragment message")
                  .arg(EAGINE_ID(pending), identifier(pending.class_id))
                  .arg(EAGINE_ID(message), identifier(class_id));
            }
        } else {
            _log.debug("total size mismatch in blob fragment message")
              .arg(EAGINE_ID(pending), identifier(pending.class_id))
              .arg(EAGINE_ID(message), identifier(class_id));
        }
    } else {
        _incoming.emplace_back();
        auto& pending = _outgoing.back();
        pending.class_id = class_id;
        pending.method_id = method_id;
        pending.blob_id = blob_id;
        pending.blob = _buffers.get(span_size(total));
        zero(cover(pending.blob));
        pending.current = {view(pending.blob)};
        pending.max_time = timeout{std::chrono::seconds(60)};
        pending.priority = priority;
        // TODO
        EAGINE_MAYBE_UNUSED(source_id);
        EAGINE_MAYBE_UNUSED(offset);
        EAGINE_MAYBE_UNUSED(fragment);
        return true;
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::process_incoming(
  blob_manipulator::fetch_handler, const message_view& message) {
    identifier class_id{};
    identifier method_id{};
    identifier_t blob_id{0U};
    std::int64_t offset{0};
    std::int64_t total{0};

    auto header = std::tie(class_id, method_id, blob_id, offset, total);
    block_data_source source{message.data};
    default_deserializer_backend backend(source);
    auto errors = deserialize(header, backend);
    if(EAGINE_LIKELY(!errors)) {
        if(EAGINE_LIKELY(total <= _max_blob_size)) {
            if((offset >= 0) && (offset < total)) {
                const auto fragment = source.remaining();
                const auto max_frag_size = span_size(total - offset);
                if(EAGINE_LIKELY(fragment.size() <= max_frag_size)) {
                    push_incoming_fragment(
                      class_id.value(),
                      method_id.value(),
                      blob_id,
                      message.source_id,
                      offset,
                      total,
                      fragment,
                      message.priority);
                    return true;
                } else {
                    _log.debug("invalid blob fragment size ${size}")
                      .arg(EAGINE_ID(size), fragment.size())
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(total), total);
                }
            } else {
                _log.debug("invalid blob fragment offset ${offset}")
                  .arg(EAGINE_ID(offset), offset)
                  .arg(EAGINE_ID(total), total);
            }
        } else {
            _log.debug("invalid blob fragment offset ${offset}")
              .arg(EAGINE_ID(offset), offset)
              .arg(EAGINE_ID(total), total);
        }
    } else {
        _log.debug("failed to deserialize header of blob")
          .arg(EAGINE_ID(errors), errors)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::process_outgoing(send_handler do_send, span_size_t) {
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
              limit_cast<std::int64_t>(pending.current.split_position()),
              limit_cast<std::int64_t>(pending.blob.size()));

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
                    _log.debug("failed to write fragment of blob ${message}")
                      .arg(EAGINE_ID(errors), get_errors(written))
                      .arg(
                        EAGINE_ID(message),
                        message_id_tuple(pending.class_id, pending.method_id));
                }
            } else {
                _log.debug("failed to serialize header of blob ${message}")
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

