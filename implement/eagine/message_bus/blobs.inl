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
void pending_blob::init() {
    zero(cover(blob));
    current = view(blob);
    done_parts.front().clear();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool pending_blob::merge_fragment(
  span_size_t bgn, memory::const_block fragment) {
    const auto end = bgn + fragment.size();
    done_parts.swap();
    auto& dst = done_parts.front();
    auto& src = done_parts.back();
    dst.clear();

    bool result = true;

    if(src.empty()) {
        dst.emplace_back(bgn, end);
        copy(fragment, head(skip(cover(blob), bgn), end - bgn));
    }
    bool new_done = false;
    for(const auto [src_bgn, src_end] : src) {
        if(bgn < src_bgn) {
            if(end < src_bgn) {
                if(!new_done) {
                    dst.emplace_back(bgn, end);
                    copy(fragment, head(skip(cover(blob), bgn), end - bgn));
                    new_done = true;
                }
                dst.emplace_back(src_bgn, src_end);
            } else if(end <= src_end) {
                if(!new_done) {
                    dst.emplace_back(bgn, src_end);
                    copy(
                      head(fragment, src_bgn - bgn),
                      head(skip(cover(blob), bgn), src_bgn - bgn));
                    new_done = true;
                }
                result &= are_equal(
                  skip(fragment, src_bgn - bgn),
                  head(skip(view(blob), src_bgn), end - src_bgn));
            } else {
                if(!new_done) {
                    dst.emplace_back(bgn, end);
                    copy(
                      head(fragment, src_bgn - bgn),
                      head(skip(cover(blob), bgn), src_bgn - bgn));
                    copy(
                      skip(fragment, src_end - bgn),
                      head(skip(cover(blob), src_end), end - src_end));
                    new_done = true;
                }
                result &= are_equal(
                  head(skip(fragment, src_bgn - bgn), src_end - src_bgn),
                  head(skip(view(blob), src_bgn), src_end - src_bgn));
            }
        } else if(bgn <= src_end) {
            if(end <= src_end) {
                dst.emplace_back(src_bgn, src_end);
                new_done = true;
                result &=
                  are_equal(fragment, head(skip(view(blob), bgn), end - bgn));
            } else {
                dst.emplace_back(src_bgn, end);
                copy(
                  skip(fragment, src_end - bgn),
                  head(skip(cover(blob), src_end), end - src_end));
                new_done = true;
                result &= are_equal(
                  head(fragment, src_end - bgn),
                  head(skip(view(blob), bgn), src_end - bgn));
            }
        } else {
            dst.emplace_back(src_bgn, src_end);
        }
    }

    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::push_incoming_fragment(
  identifier_t class_id,
  identifier_t method_id,
  identifier_t source_id,
  identifier_t blob_id,
  std::int64_t offset,
  std::int64_t total_size,
  memory::const_block fragment,
  message_priority priority) {

    auto pos = std::find_if(
      _incoming.begin(), _incoming.end(), [blob_id](const auto& pending) {
          return pending.blob_id == blob_id;
      });
    if(pos != _incoming.end()) {
        auto& pending = *pos;
        if(EAGINE_LIKELY(pending.blob.size() == span_size(total_size))) {
            if(EAGINE_LIKELY(pending.class_id == class_id)) {
                if(EAGINE_LIKELY(pending.method_id == method_id)) {
                    pending.max_time.reset();
                    if(EAGINE_UNLIKELY(pending.priority < priority)) {
                        pending.priority = priority;
                    }
                    pending.merge_fragment(span_size(offset), fragment);
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
              .arg(EAGINE_ID(pending), identifier(pending.blob.size()))
              .arg(EAGINE_ID(message), identifier(total_size));
        }
    } else {
        _incoming.emplace_back();
        auto& pending = _incoming.back();
        pending.class_id = class_id;
        pending.method_id = method_id;
        pending.endpoint_id = source_id;
        pending.blob_id = blob_id;
        pending.blob = _buffers.get(span_size(total_size));
        pending.max_time = timeout{std::chrono::seconds(60)};
        pending.priority = priority;
        pending.init();
        pending.merge_fragment(span_size(offset), fragment);
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::process_incoming(
  blob_manipulator::filter_function filter, const message_view& message) {
    identifier class_id{};
    identifier method_id{};
    identifier_t blob_id{0U};
    std::int64_t offset{0};
    std::int64_t total_size{0};

    auto header = std::tie(class_id, method_id, blob_id, offset, total_size);
    block_data_source source{message.data};
    default_deserializer_backend backend(source);
    auto errors = deserialize(header, backend);
    if(EAGINE_LIKELY(!errors)) {
        if(EAGINE_LIKELY(total_size <= _max_blob_size)) {
            const bool should_accept =
              !filter || filter(class_id.value(), method_id.value());
            if(should_accept) {
                if((offset >= 0) && (offset < total_size)) {
                    const auto fragment = source.remaining();
                    const auto max_frag_size = span_size(total_size - offset);
                    if(EAGINE_LIKELY(fragment.size() <= max_frag_size)) {
                        return push_incoming_fragment(
                          class_id.value(),
                          method_id.value(),
                          message.source_id,
                          blob_id,
                          offset,
                          total_size,
                          fragment,
                          message.priority);
                    } else {
                        _log.debug("invalid blob fragment size ${size}")
                          .arg(EAGINE_ID(size), fragment.size())
                          .arg(EAGINE_ID(offset), offset)
                          .arg(EAGINE_ID(total), total_size);
                    }
                } else {
                    _log.debug("invalid blob fragment offset ${offset}")
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(total), total_size);
                }
            }
        } else {
            _log.debug("invalid blob fragment offset ${offset}")
              .arg(EAGINE_ID(offset), offset)
              .arg(EAGINE_ID(total), total_size);
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
span_size_t blob_manipulator::message_size(
  const pending_blob& pending, span_size_t max_message_size) const noexcept {
    switch(pending.priority) {
        case message_priority::critical:
            break;
        case message_priority::high:
        case message_priority::normal:
            return max_message_size / 2;
        case message_priority::low:
            return max_message_size / 4;
        case message_priority::idle:
            return max_message_size / 8;
    }
    return max_message_size;
}
//------------------------------------------------------------------------------
inline memory::block blob_manipulator::_scratch_block(span_size_t size) {
    return cover(_scratch_buffer.resize(size));
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
    pending.endpoint_id = target_id;
    pending.blob_id = ++_blob_id_sequence;
    pending.blob = _buffers.get(blob.size());
    copy(blob, cover(pending.blob));
    pending.current = {view(pending.blob)};
    pending.max_time = timeout{max_time};
    pending.priority = priority;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool blob_manipulator::process_outgoing(
  send_handler do_send, span_size_t max_message_size) {
    some_true something_done{};

    const auto msg_id = EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt);

    for(auto& pending : _outgoing) {
        if(pending.current.tail()) {
            const auto header = std::make_tuple(
              identifier(pending.class_id),
              identifier(pending.method_id),
              pending.blob_id,
              limit_cast<std::int64_t>(pending.current.split_position()),
              limit_cast<std::int64_t>(pending.blob.size()));

            block_data_sink sink(
              _scratch_block(message_size(pending, max_message_size)));
            default_serializer_backend backend(sink);

            auto errors = serialize(header, backend);
            if(!errors) {
                if(auto written = sink.write_some(pending.current)) {
                    pending.current = extract(written);
                    message_view message(sink.done());
                    message.set_target_id(pending.endpoint_id);
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
EAGINE_LIB_FUNC
span_size_t blob_manipulator::fetch_all(
  blob_manipulator::fetch_handler handle_fetch) {

    span_size_t done_count{0};
    auto predicate = [this, &done_count, &handle_fetch](auto& pending) {
        if(pending.is_complete()) {
            message_view message{view(pending.blob)};
            message.set_source_id(pending.endpoint_id);
            message.set_priority(pending.priority);
            handle_fetch(pending.class_id, pending.method_id, message);
            _buffers.eat(std::move(pending.blob));
            ++done_count;
            return true;
        }
        return false;
    };

    _incoming.erase(
      std::remove_if(_incoming.begin(), _incoming.end(), predicate),
      _incoming.end());

    return done_count;
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

