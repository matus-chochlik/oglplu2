/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/bool_aggregate.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <eagine/serialize/block_sink.hpp>
#include <eagine/serialize/block_source.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// buffer blob i/o
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
buffer_blob_io::buffer_blob_io(memory::buffer buf) noexcept
  : _buf{std::move(buf)} {
    zero(cover(_buf));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
buffer_blob_io::buffer_blob_io(memory::buffer buf, memory::const_block src)
  : _buf{std::move(buf)} {
    copy(src, cover(_buf));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto buffer_blob_io::is_at_eod(span_size_t offs) -> bool {
    return offs >= _buf.size();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto buffer_blob_io::total_size() -> span_size_t {
    return _buf.size();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto buffer_blob_io::fetch_fragment(span_size_t offs, memory::block dst)
  -> span_size_t {
    const auto src = head(skip(view(_buf), offs), dst.size());
    copy(src, dst);
    return src.size();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto buffer_blob_io::store_fragment(span_size_t offs, memory::const_block src)
  -> bool {
    auto dst = skip(cover(_buf), offs);
    if(EAGINE_LIKELY(src.size() <= dst.size())) {
        copy(src, dst);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto buffer_blob_io::check_stored(span_size_t offs, memory::const_block blk)
  -> bool {
    return are_equal(head(skip(view(_buf), offs), blk.size()), blk);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto buffer_blob_io::release_buffer() noexcept -> memory::buffer {
    return std::move(_buf);
}
//------------------------------------------------------------------------------
// blob manipulator
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::cleanup() -> bool {
    some_true something_done{};
    auto predicate = [this, &something_done](auto& pending) {
        if(pending.max_time.is_expired()) {
            if(auto buf_io{pending.buffer_io()}) {
                _buffers.eat(extract(buf_io).release_buffer());
            }
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
auto pending_blob::done_size() const noexcept -> span_size_t {
    span_size_t result = 0;
    for(const auto& [bgn, end] : done_parts.front()) {
        result += end - bgn;
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::is_complete() const noexcept -> bool {
    if(done_parts.front().size() == 1) {
        const auto [bgn, end] = done_parts.front().front();
        return (bgn == 0) && (end >= total_size());
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::merge_fragment(span_size_t bgn, memory::const_block fragment)
  -> bool {
    const auto end = bgn + fragment.size();
    done_parts.swap();
    auto& dst = done_parts.front();
    auto& src = done_parts.back();
    dst.clear();

    bool result = true;

    if(src.empty()) {
        dst.emplace_back(bgn, end);
        result &= store(bgn, fragment);
    }
    bool new_done = false;
    for(const auto& [src_bgn, src_end] : src) {
        if(bgn < src_bgn) {
            if(end < src_bgn) {
                if(!new_done) {
                    dst.emplace_back(bgn, end);
                    result &= store(bgn, fragment);
                    new_done = true;
                }
                dst.emplace_back(src_bgn, src_end);
            } else if(end <= src_end) {
                if(!new_done) {
                    dst.emplace_back(bgn, src_end);
                    result &= store(bgn, head(fragment, src_bgn - bgn));
                    new_done = true;
                }
                result &= check(src_bgn, skip(fragment, src_bgn - bgn));
            } else {
                if(!new_done) {
                    dst.emplace_back(bgn, end);
                    result &= store(bgn, head(fragment, src_bgn - bgn));
                    result &= store(src_end, skip(fragment, src_end - bgn));
                    new_done = true;
                }
                result &= check(
                  src_bgn,
                  head(skip(fragment, src_bgn - bgn), src_end - src_bgn));
            }
        } else if(bgn <= src_end) {
            if(end <= src_end) {
                dst.emplace_back(src_bgn, src_end);
                new_done = true;
                result &= check(bgn, fragment);
            } else {
                dst.emplace_back(src_bgn, end);
                result &= store(src_end, skip(fragment, src_end - bgn));
                result &= check(bgn, head(fragment, src_end - bgn));
                new_done = true;
            }
        } else {
            dst.emplace_back(src_bgn, src_end);
        }
    }

    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::make_io(span_size_t total_size)
  -> std::unique_ptr<blob_io> {
    return std::make_unique<buffer_blob_io>(_buffers.get(total_size));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::push_incoming_fragment(
  message_id msg_id,
  identifier_t source_id,
  std::uint32_t blob_id,
  std::int64_t offset,
  std::int64_t total_size,
  io_getter get_io,
  memory::const_block fragment,
  message_priority priority) -> bool {

    auto pos = std::find_if(
      _incoming.begin(), _incoming.end(), [blob_id](const auto& pending) {
          return pending.blob_id == blob_id;
      });
    if(pos != _incoming.end()) {
        auto& pending = *pos;
        if(EAGINE_LIKELY(pending.total_size() == span_size(total_size))) {
            if(EAGINE_LIKELY(pending.msg_id == msg_id)) {
                pending.max_time.reset();
                if(EAGINE_UNLIKELY(pending.priority < priority)) {
                    pending.priority = priority;
                }
                if(pending.merge_fragment(span_size(offset), fragment)) {
                    log_trace("merged blob fragment")
                      .arg(EAGINE_ID(blobId), blob_id)
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(size), fragment.size())
                      .arg_func([&](logger_backend& backend) {
                          backend.add_float(
                            EAGINE_ID(complete),
                            EAGINE_ID(Progress),
                            0.f,
                            float(pending.done_size()),
                            float(pending.total_size()));
                      });
                } else {
                    log_warning("failed to merge blob fragment")
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(size), fragment.size());
                }
            } else {
                log_debug("message id mismatch in blob fragment message")
                  .arg(EAGINE_ID(pending), pending.msg_id)
                  .arg(EAGINE_ID(message), msg_id);
            }
        } else {
            log_debug("total size mismatch in blob fragment message")
              .arg(EAGINE_ID(pending), pending.total_size())
              .arg(EAGINE_ID(message), total_size);
        }
    } else {
        if(auto io{get_io(msg_id, span_size(total_size), *this)}) {
            _incoming.emplace_back();
            auto& pending = _incoming.back();
            pending.msg_id = msg_id;
            pending.source_id = source_id;
            pending.blob_id = blob_id;
            pending.io = std::move(io);
            pending.current_position = 0;
            pending.max_time = timeout{std::chrono::seconds(60)};
            pending.priority = priority;
            pending.done_parts.front().clear();
            if(pending.merge_fragment(span_size(offset), fragment)) {
                log_trace("merged first blob fragment")
                  .arg(EAGINE_ID(blobId), blob_id)
                  .arg(EAGINE_ID(offset), offset)
                  .arg(EAGINE_ID(size), fragment.size())
                  .arg_func([&](logger_backend& backend) {
                      backend.add_float(
                        EAGINE_ID(complete),
                        EAGINE_ID(Progress),
                        0.f,
                        float(pending.done_size()),
                        float(pending.total_size()));
                  });
            }
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::process_incoming(
  blob_manipulator::io_getter get_io,
  const message_view& message) -> bool {

    identifier class_id{};
    identifier method_id{};
    std::uint32_t blob_id{0U};
    std::int64_t offset{0};
    std::int64_t total_size{0};

    auto header = std::tie(class_id, method_id, blob_id, offset, total_size);
    block_data_source source{message.data};
    default_deserializer_backend backend(source);
    auto errors = deserialize(header, backend);
    const message_id msg_id{class_id, method_id};
    if(EAGINE_LIKELY(!errors)) {
        if(EAGINE_LIKELY(total_size <= _max_blob_size)) {
            if((offset >= 0) && (offset < total_size)) {
                const auto fragment = source.remaining();
                const auto max_frag_size = span_size(total_size - offset);
                if(EAGINE_LIKELY(fragment.size() <= max_frag_size)) {
                    return push_incoming_fragment(
                      msg_id,
                      message.source_id,
                      blob_id,
                      offset,
                      total_size,
                      get_io,
                      fragment,
                      message.priority);
                } else {
                    log_error("invalid blob fragment size ${size}")
                      .arg(EAGINE_ID(size), fragment.size())
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(total), total_size);
                }
            } else {
                log_error("invalid blob fragment offset ${offset}")
                  .arg(EAGINE_ID(offset), offset)
                  .arg(EAGINE_ID(total), total_size);
            }
        } else {
            log_warning("blob is too big ${total_size}")
              .arg(EAGINE_ID(total), total_size)
              .arg(EAGINE_ID(offset), _max_blob_size);
        }
    } else {
        log_error("failed to deserialize header of blob")
          .arg(EAGINE_ID(errors), errors)
          .arg(EAGINE_ID(data), message.data);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::message_size(
  const pending_blob& pending,
  span_size_t max_message_size) const noexcept -> span_size_t {
    switch(pending.priority) {
        case message_priority::critical:
        case message_priority::high:
        case message_priority::normal:
            break;
        case message_priority::low:
            return max_message_size / 2;
        case message_priority::idle:
            return max_message_size / 4;
    }
    return max_message_size - 64;
}
//------------------------------------------------------------------------------
inline auto blob_manipulator::_scratch_block(span_size_t size)
  -> memory::block {
    return cover(_scratch_buffer.resize(size));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::push_outgoing(
  message_id msg_id,
  identifier_t source_id,
  identifier_t target_id,
  std::unique_ptr<blob_io> io,
  std::chrono::seconds max_time,
  message_priority priority) -> message_sequence_t {
    _outgoing.emplace_back();
    auto& pending = _outgoing.back();
    pending.msg_id = msg_id;
    pending.source_id = source_id;
    pending.target_id = target_id;
    pending.blob_id = ++_blob_id_sequence;
    pending.io = std::move(io);
    pending.current_position = 0;
    pending.max_time = timeout{max_time};
    pending.priority = priority;
    return limit_cast<identifier_t>(pending.blob_id);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::push_outgoing(
  message_id msg_id,
  identifier_t source_id,
  identifier_t target_id,
  memory::const_block src,
  std::chrono::seconds max_time,
  message_priority priority) -> message_sequence_t {
    return push_outgoing(
      msg_id,
      source_id,
      target_id,
      std::make_unique<buffer_blob_io>(_buffers.get(src.size()), src),
      max_time,
      priority);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::process_outgoing(
  send_handler do_send,
  span_size_t max_message_size) -> bool {
    some_true something_done{};

    const auto msg_id = EAGINE_MSGBUS_ID(blobFrgmnt);

    for(auto& pending : _outgoing) {
        if(!pending.is_at_eod()) {
            const auto header = std::make_tuple(
              pending.msg_id.class_(),
              pending.msg_id.method(),
              pending.blob_id,
              limit_cast<std::int64_t>(pending.current_position),
              limit_cast<std::int64_t>(pending.total_size()));

            block_data_sink sink(
              _scratch_block(message_size(pending, max_message_size)));
            default_serializer_backend backend(sink);

            auto errors = serialize(header, backend);
            if(!errors) {

                if(auto written_size{
                     pending.fetch(pending.current_position, sink.free())}) {

                    sink.mark_used(written_size);
                    pending.current_position += written_size;
                    message_view message(sink.done());
                    message.set_source_id(pending.source_id);
                    message.set_target_id(pending.target_id);
                    message.set_priority(pending.priority);
                    something_done(do_send(msg_id, message));
                } else {
                    log_error("failed to write fragment of blob ${message}")
                      .arg(EAGINE_ID(message), pending.msg_id);
                }
            } else {
                log_error("failed to serialize header of blob ${message}")
                  .arg(EAGINE_ID(errors), errors)
                  .arg(EAGINE_ID(message), pending.msg_id);
            }
        }
    }

    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::fetch_all(blob_manipulator::fetch_handler handle_fetch)
  -> span_size_t {

    span_size_t done_count{0};
    auto predicate = [this, &done_count, &handle_fetch](auto& pending) {
        if(pending.is_complete()) {
            log_debug("handling complete blob ${id}")
              .arg(EAGINE_ID(id), pending.blob_id)
              .arg(EAGINE_ID(message), pending.msg_id)
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), pending.total_size());

            if(auto buf_io{pending.buffer_io()}) {
                auto blob = extract(buf_io).release_buffer();
                message_view message{view(blob)};
                message.set_source_id(pending.source_id);
                message.set_target_id(pending.target_id);
                message.set_sequence_no(pending.blob_id);
                message.set_priority(pending.priority);
                handle_fetch(pending.msg_id, pending.age(), message);
                _buffers.eat(std::move(blob));
            } else if(auto fin_io{pending.finish_io()}) {
                message_info info{};
                info.set_source_id(pending.source_id);
                info.set_target_id(pending.target_id);
                info.set_sequence_no(pending.blob_id);
                info.set_priority(pending.priority);
                extract(fin_io).handle_finished(
                  pending.msg_id, pending.age(), info);
            }
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
} // namespace eagine::msgbus
