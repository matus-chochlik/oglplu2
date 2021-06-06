/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/serialize.hpp>
#include <eagine/serialize/block_sink.hpp>
#include <eagine/serialize/block_source.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
// buffer blob I/O
//------------------------------------------------------------------------------
class buffer_blob_io : public blob_io {
public:
    buffer_blob_io(memory::buffer buf) noexcept
      : _buf{std::move(buf)} {
        zero(cover(_buf));
    }

    buffer_blob_io(memory::buffer buf, memory::const_block src)
      : _buf{std::move(buf)} {
        copy(src, cover(_buf));
    }

    auto is_at_eod(span_size_t offs) -> bool final {
        return offs >= _buf.size();
    }

    auto total_size() -> span_size_t final {
        return _buf.size();
    }

    auto fetch_fragment(span_size_t offs, memory::block dst)
      -> span_size_t final {
        const auto src = head(skip(view(_buf), offs), dst.size());
        copy(src, dst);
        return src.size();
    }

    auto store_fragment(span_size_t offs, memory::const_block src)
      -> bool final {
        auto dst = skip(cover(_buf), offs);
        if(EAGINE_LIKELY(src.size() <= dst.size())) {
            copy(src, dst);
            return true;
        }
        return false;
    }

    auto check_stored(span_size_t offs, memory::const_block blk) -> bool final {
        return are_equal(head(skip(view(_buf), offs), blk.size()), blk);
    }

    auto release_buffer() noexcept -> memory::buffer {
        return std::move(_buf);
    }

private:
    memory::buffer _buf;
};
//------------------------------------------------------------------------------
// pending blob
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::buffer_io() noexcept -> buffer_blob_io* {
    return dynamic_cast<buffer_blob_io*>(io.get());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::sent_size() const noexcept -> span_size_t {
    span_size_t result = 0;
    for(const auto& [bgn, end] : todo_parts()) {
        result += end - bgn;
    }
    return total_size - result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::received_size() const noexcept -> span_size_t {
    span_size_t result = 0;
    for(const auto& [bgn, end] : done_parts()) {
        result += end - bgn;
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::total_size_mismatch(span_size_t size) const noexcept
  -> bool {
    return (total_size != 0) && (total_size != size);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::sent_everything() const noexcept -> bool {
    if(!todo_parts().empty()) {
        EAGINE_ASSERT(io);
        return io->is_at_eod(std::get<0>(todo_parts().front()));
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC auto pending_blob::received_everything() const noexcept
  -> bool {
    auto& done = done_parts();
    if(done.size() == 1) {
        const auto [bgn, end] = done.front();
        return (bgn == 0) && (total_size != 0) && (end >= total_size);
    }
    return (total_size != 0) && done.empty();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto pending_blob::merge_fragment(span_size_t bgn, memory::const_block fragment)
  -> bool {
    const auto end = bgn + fragment.size();
    fragment_parts.swap();
    auto& dst = done_parts();
    const auto& src = todo_parts();
    dst.clear();

    bool result = true;
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
                if(new_done) {
                    std::get<1>(dst.back()) = src_end;
                } else {
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
    if(!new_done) {
        dst.emplace_back(bgn, end);
        result &= store(bgn, fragment);
    }
    latest_update = std::chrono::steady_clock::now();

    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void pending_blob::merge_resend_request(span_size_t bgn, span_size_t end) {
    if(end == 0) {
        end = total_size;
    }
    if(bgn < end) {
        fragment_parts.swap();
        auto& dst = todo_parts();
        const auto& src = done_parts();
        dst.clear();

        bool new_done = false;

        for(const auto& [src_bgn, src_end] : src) {
            if(bgn < src_bgn) {
                if(end < src_bgn) {
                    if(!new_done) {
                        dst.emplace_back(bgn, end);
                        new_done = true;
                    }
                    dst.emplace_back(src_bgn, src_end);
                } else if(end <= src_end) {
                    if(new_done) {
                        std::get<1>(dst.back()) = src_end;
                    } else {
                        dst.emplace_back(bgn, src_end);
                        new_done = true;
                    }
                } else {
                    if(!new_done) {
                        dst.emplace_back(bgn, end);
                        new_done = true;
                    }
                }
            } else if(bgn <= src_end) {
                if(end <= src_end) {
                    dst.emplace_back(src_bgn, src_end);
                    new_done = true;
                } else {
                    dst.emplace_back(src_bgn, end);
                    new_done = true;
                }
            } else {
                dst.emplace_back(src_bgn, src_end);
            }
        }
        if(!new_done) {
            dst.emplace_back(bgn, end);
        }
    }
}
//------------------------------------------------------------------------------
// blob manipulator
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::update(blob_manipulator::send_handler do_send)
  -> work_done {
    const auto now = std::chrono::steady_clock::now();
    some_true something_done{};

    _incoming.erase(
      std::remove_if(
        _incoming.begin(),
        _incoming.end(),
        [this, now, do_send, &something_done](auto& pending) {
            bool should_erase = false;
            if(pending.max_time.is_expired()) {
                extract(pending.io).handle_cancelled();
                if(auto buf_io{pending.buffer_io()}) {
                    _buffers.eat(extract(buf_io).release_buffer());
                }
                something_done();
                should_erase = true;
            } else if(std::chrono::seconds{2} > now - pending.latest_update) {
                auto& done = pending.done_parts();
                if(!done.empty()) {
                    const auto bgn = std::get<1>(done[0]);
                    const auto end = done.size() > 1 ? std::get<1>(done[0])
                                                     : pending.total_size;
                    const std::tuple<identifier_t, std::uint64_t, std::uint64_t>
                      params{pending.source_blob_id, bgn, end};
                    auto buffer{default_serialize_buffer_for(params)};
                    auto serialized{default_serialize(params, cover(buffer))};
                    EAGINE_ASSERT(serialized);
                    message_view resend_request{extract(serialized)};
                    resend_request.set_target_id(pending.source_id);
                    pending.latest_update = now;
                    something_done(do_send(_resend_msg_id, resend_request));
                }
            }
            return should_erase;
        }),
      _incoming.end());

    _outgoing.erase(
      std::remove_if(
        _outgoing.begin(),
        _outgoing.end(),
        [this, &something_done](auto& pending) {
            if(pending.max_time.is_expired()) {
                if(auto buf_io{pending.buffer_io()}) {
                    _buffers.eat(extract(buf_io).release_buffer());
                }
                something_done();
                return true;
            }
            return false;
        }),
      _outgoing.end());

    return something_done;
}
//------------------------------------------------------------------------------
auto blob_manipulator::make_io(span_size_t total_size)
  -> std::unique_ptr<blob_io> {
    if(total_size < _max_blob_size) {
        return std::make_unique<buffer_blob_io>(_buffers.get(total_size));
    }
    log_warning("blob is too big ${total_size}")
      .arg(EAGINE_ID(total), EAGINE_ID(ByteSize), total_size)
      .arg(EAGINE_ID(offset), _max_blob_size);
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::_make_io(
  message_id,
  span_size_t total_size,
  blob_manipulator&) -> std::unique_ptr<blob_io> {
    return make_io(total_size);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::expect_incoming(
  message_id msg_id,
  identifier_t source_id,
  blob_id_t target_blob_id,
  std::shared_ptr<blob_io> io,
  std::chrono::seconds max_time) -> bool {
    log_debug("expecting incoming fragment")
      .arg(EAGINE_ID(source), source_id)
      .arg(EAGINE_ID(tgtBlobId), target_blob_id)
      .arg(EAGINE_ID(timeout), max_time);

    _incoming.emplace_back();
    auto& pending = _incoming.back();
    pending.msg_id = msg_id;
    pending.source_id = source_id;
    pending.source_blob_id = 0U;
    pending.target_blob_id = target_blob_id;
    pending.io = std::move(io);
    pending.latest_update = std::chrono::steady_clock::now();
    pending.max_time = timeout{max_time};
    pending.priority = message_priority::normal;
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::push_incoming_fragment(
  message_id msg_id,
  identifier_t source_id,
  blob_id_t source_blob_id,
  blob_id_t target_blob_id,
  std::int64_t offset,
  std::int64_t total_size,
  io_getter get_io,
  memory::const_block fragment,
  message_priority priority) -> bool {

    auto pos = std::find_if(
      _incoming.begin(),
      _incoming.end(),
      [source_id, source_blob_id](const auto& pending) {
          return (pending.source_id == source_id) &&
                 (pending.source_blob_id == source_blob_id);
      });
    if(pos == _incoming.end()) {
        pos = std::find_if(
          _incoming.begin(),
          _incoming.end(),
          [msg_id, source_id, target_blob_id](const auto& pending) {
              return (pending.msg_id == msg_id) &&
                     (pending.target_blob_id == target_blob_id) &&
                     ((pending.source_id == source_id) ||
                      (pending.source_id == broadcast_endpoint_id()));
          });
        if(pos != _incoming.end()) {
            auto& pending = *pos;
            if(pending.source_id == broadcast_endpoint_id()) {
                pending.source_id = source_id;
            }
            pending.source_blob_id = source_blob_id;
            pending.priority = priority;
            pending.total_size = limit_cast<span_size_t>(total_size);
            log_debug("updating expected blob fragment")
              .arg(EAGINE_ID(source), source_id)
              .arg(EAGINE_ID(srcBlobId), source_blob_id)
              .arg(EAGINE_ID(tgtBlobId), target_blob_id)
              .arg(EAGINE_ID(total), EAGINE_ID(ByteSize), total_size)
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), fragment.size());
        }
    }
    if(pos != _incoming.end()) {
        auto& pending = *pos;
        if(EAGINE_LIKELY(!pending.total_size_mismatch(span_size(total_size)))) {
            if(EAGINE_LIKELY(pending.msg_id == msg_id)) {
                pending.max_time.reset();
                if(EAGINE_UNLIKELY(pending.priority < priority)) {
                    pending.priority = priority;
                }
                if(pending.merge_fragment(span_size(offset), fragment)) {
                    log_debug("merged blob fragment")
                      .arg(EAGINE_ID(source), source_id)
                      .arg(EAGINE_ID(srcBlobId), source_blob_id)
                      .arg(EAGINE_ID(parts), pending.done_parts().size())
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(size), fragment.size());
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
              .arg(EAGINE_ID(pending), EAGINE_ID(ByteSize), pending.total_size)
              .arg(EAGINE_ID(message), EAGINE_ID(ByteSize), total_size);
        }
    } else {
        if(auto io{get_io(msg_id, span_size(total_size), *this)}) {
            _incoming.emplace_back();
            auto& pending = _incoming.back();
            pending.msg_id = msg_id;
            pending.source_id = source_id;
            pending.source_blob_id = source_blob_id;
            pending.target_blob_id = target_blob_id;
            pending.io = std::move(io);
            pending.total_size = limit_cast<span_size_t>(total_size);
            pending.max_time = timeout{adjusted_duration(
              std::chrono::seconds{60}, memory_access_rate::high)};
            pending.priority = priority;
            pending.done_parts().clear();
            if(pending.merge_fragment(span_size(offset), fragment)) {
                log_debug("merged first blob fragment")
                  .arg(EAGINE_ID(source), source_id)
                  .arg(EAGINE_ID(srcBlobId), source_blob_id)
                  .arg(EAGINE_ID(tgtBlobId), target_blob_id)
                  .arg(EAGINE_ID(parts), pending.done_parts().size())
                  .arg(EAGINE_ID(offset), offset)
                  .arg(EAGINE_ID(size), fragment.size());
            }
        } else {
            log_warning("failed to create blob I/O object")
              .arg(EAGINE_ID(source), source_id)
              .arg(EAGINE_ID(srcBlobId), source_blob_id)
              .arg(EAGINE_ID(tgtBlobId), target_blob_id)
              .arg(EAGINE_ID(offset), offset)
              .arg(EAGINE_ID(size), fragment.size());
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
    blob_id_t source_blob_id{0U};
    blob_id_t target_blob_id{0U};
    std::int64_t offset{0};
    std::int64_t total_size{0};

    auto header = std::tie(
      class_id, method_id, source_blob_id, target_blob_id, offset, total_size);
    block_data_source source{message.content()};
    default_deserializer_backend backend(source);
    auto errors = deserialize(header, backend);
    const message_id msg_id{class_id, method_id};
    if(EAGINE_LIKELY(!errors)) {
        if((offset >= 0) && (offset < total_size)) {
            const auto fragment = source.remaining();
            const auto max_frag_size = span_size(total_size - offset);
            if(EAGINE_LIKELY(fragment.size() <= max_frag_size)) {
                return push_incoming_fragment(
                  msg_id,
                  message.source_id,
                  source_blob_id,
                  target_blob_id,
                  offset,
                  total_size,
                  get_io,
                  fragment,
                  message.priority);
            } else {
                log_error("invalid blob fragment size ${size}")
                  .arg(EAGINE_ID(size), fragment.size())
                  .arg(EAGINE_ID(offset), offset)
                  .arg(EAGINE_ID(total), EAGINE_ID(ByteSize), total_size);
            }
        } else {
            log_error("invalid blob fragment offset ${offset}")
              .arg(EAGINE_ID(offset), offset)
              .arg(EAGINE_ID(total), EAGINE_ID(ByteSize), total_size);
        }
    } else {
        log_error("failed to deserialize header of blob")
          .arg(EAGINE_ID(errors), errors)
          .arg(EAGINE_ID(data), message.content());
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::process_incoming(const message_view& message) -> bool {
    return process_incoming(EAGINE_THIS_MEM_FUNC_REF(_make_io), message);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::process_resend(const message_view& message) -> bool {
    std::tuple<identifier_t, std::uint64_t, std::uint64_t> params{};
    if(default_deserialize(params, message.content())) {
        const auto source_blob_id = std::get<0>(params);
        const auto bgn = limit_cast<span_size_t>(std::get<1>(params));
        const auto end = limit_cast<span_size_t>(std::get<2>(params));
        log_debug("received resend request from ${target}")
          .arg(EAGINE_ID(target), message.source_id)
          .arg(EAGINE_ID(srcBlobId), source_blob_id)
          .arg(EAGINE_ID(begin), bgn)
          .arg(EAGINE_ID(end), end);
        const auto pos = std::find_if(
          _outgoing.begin(), _outgoing.end(), [source_blob_id](auto& pending) {
              return pending.source_blob_id == source_blob_id;
          });
        if(pos != _outgoing.end()) {
            pos->merge_resend_request(bgn, end);
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::cancel_incoming(identifier_t target_blob_id) -> bool {
    const auto pos = std::find_if(
      _incoming.begin(), _incoming.end(), [target_blob_id](auto& pending) {
          return pending.target_blob_id == target_blob_id;
      });
    if(pos != _incoming.end()) {
        auto& pending = *pos;
        extract(pending.io).handle_cancelled();
        if(auto buf_io{pending.buffer_io()}) {
            _buffers.eat(extract(buf_io).release_buffer());
        }
        _incoming.erase(pos);
        return true;
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
            return max_message_size - 92;
        case message_priority::high:
            return max_message_size / 2 - 64;
        case message_priority::normal:
            return max_message_size / 3 - 48;
        case message_priority::low:
            return max_message_size / 4 - 32;
        case message_priority::idle:
            return max_message_size / 8 - 12;
    }
    return 0;
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
  blob_id_t target_blob_id,
  std::shared_ptr<blob_io> io,
  std::chrono::seconds max_time,
  message_priority priority) -> blob_id_t {
    EAGINE_ASSERT(io);
    _outgoing.emplace_back();
    auto& pending = _outgoing.back();
    pending.msg_id = msg_id;
    pending.source_id = source_id;
    pending.target_id = target_id;
    pending.source_blob_id = ++_blob_id_sequence;
    pending.target_blob_id = target_blob_id;
    pending.total_size = extract(io).total_size();
    pending.io = std::move(io);
    pending.max_time = timeout{max_time};
    pending.priority = priority;
    pending.todo_parts().emplace_back(0, pending.total_size);
    return pending.source_blob_id;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::push_outgoing(
  message_id msg_id,
  identifier_t source_id,
  identifier_t target_id,
  blob_id_t target_blob_id,
  memory::const_block src,
  std::chrono::seconds max_time,
  message_priority priority) -> blob_id_t {
    return push_outgoing(
      msg_id,
      source_id,
      target_id,
      target_blob_id,
      std::make_unique<buffer_blob_io>(_buffers.get(src.size()), src),
      max_time,
      priority);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto blob_manipulator::process_outgoing(
  send_handler do_send,
  span_size_t max_message_size) -> work_done {
    some_true something_done{};

    for(auto& pending : _outgoing) {
        if(!pending.sent_everything()) {
            auto& [bgn, end] = pending.todo_parts().back();
            EAGINE_ASSERT(end != 0);

            const auto header = std::make_tuple(
              pending.msg_id.class_(),
              pending.msg_id.method(),
              pending.source_blob_id,
              pending.target_blob_id,
              limit_cast<std::int64_t>(bgn),
              limit_cast<std::int64_t>(pending.total_size));

            block_data_sink sink(
              _scratch_block(message_size(pending, max_message_size)));
            default_serializer_backend backend(sink);

            auto errors = serialize(header, backend);
            if(!errors) {

                const auto offset = bgn;
                if(auto written_size{pending.fetch(offset, sink.free())}) {

                    sink.mark_used(written_size);
                    bgn += written_size;
                    if(bgn >= end) {
                        pending.todo_parts().pop_back();
                    }
                    message_view message(sink.done());
                    message.set_source_id(pending.source_id);
                    message.set_target_id(pending.target_id);
                    message.set_priority(pending.priority);
                    something_done(do_send(_fragment_msg_id, message));

                    log_debug("sent blob fragment")
                      .arg(EAGINE_ID(source), pending.source_id)
                      .arg(EAGINE_ID(srcBlobId), pending.source_blob_id)
                      .arg(EAGINE_ID(parts), pending.todo_parts().size())
                      .arg(EAGINE_ID(offset), offset)
                      .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), written_size);
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
auto blob_manipulator::handle_complete() -> span_size_t {

    span_size_t done_count{0};
    auto predicate = [this, &done_count](auto& pending) {
        if(pending.received_everything()) {
            log_debug("handling complete blob ${id}")
              .arg(EAGINE_ID(source), pending.source_id)
              .arg(EAGINE_ID(srcBlobId), pending.source_blob_id)
              .arg(EAGINE_ID(message), pending.msg_id)
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), pending.total_size);

            message_info info{};
            info.set_source_id(pending.source_id);
            info.set_target_id(pending.target_id);
            info.set_sequence_no(pending.target_blob_id);
            info.set_priority(pending.priority);
            extract(pending.io)
              .handle_finished(pending.msg_id, pending.age(), info);
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
EAGINE_LIB_FUNC
auto blob_manipulator::fetch_all(blob_manipulator::fetch_handler handle_fetch)
  -> span_size_t {

    span_size_t done_count{0};
    auto predicate = [this, &done_count, &handle_fetch](auto& pending) {
        if(pending.received_everything()) {
            log_debug("fetching complete blob ${id}")
              .arg(EAGINE_ID(source), pending.source_id)
              .arg(EAGINE_ID(srcBlobId), pending.source_blob_id)
              .arg(EAGINE_ID(message), pending.msg_id)
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), pending.total_size);

            if(auto buf_io{pending.buffer_io()}) {
                auto blob = extract(buf_io).release_buffer();
                message_view message{view(blob)};
                message.set_source_id(pending.source_id);
                message.set_target_id(pending.target_id);
                message.set_sequence_no(pending.target_blob_id);
                message.set_priority(pending.priority);
                handle_fetch(pending.msg_id, pending.age(), message);
                _buffers.eat(std::move(blob));
            } else {
                message_info info{};
                info.set_source_id(pending.source_id);
                info.set_target_id(pending.target_id);
                info.set_sequence_no(pending.target_blob_id);
                info.set_priority(pending.priority);
                extract(pending.io)
                  .handle_finished(pending.msg_id, pending.age(), info);
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
