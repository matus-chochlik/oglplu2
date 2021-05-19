/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/message_bus/serialize.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
auto stored_message::store_and_sign(
  memory::const_block data,
  span_size_t max_size,
  context& ctx,
  main_ctx_object& user) -> bool {

    if(ok md_type{ctx.default_message_digest()}) {
        auto& ssl = ctx.ssl();
        _buffer.resize(max_size);
        if(auto used{store_data_with_size(data, storage())}) {
            if(ok md_ctx{ssl.new_message_digest()}) {
                auto cleanup{ssl.delete_message_digest.raii(md_ctx)};

                if(EAGINE_LIKELY(
                     ctx.message_digest_sign_init(md_ctx, md_type))) {
                    if(EAGINE_LIKELY(
                         ssl.message_digest_sign_update(md_ctx, data))) {

                        auto free{skip(storage(), used.size())};
                        if(ok sig{
                             ssl.message_digest_sign_final(md_ctx, free)}) {
                            crypto_flags |= message_crypto_flag::asymmetric;
                            crypto_flags |= message_crypto_flag::signed_content;
                            _buffer.resize(used.size() + sig.get().size());
                            return true;
                        } else {
                            user.log_debug("failed to finish ssl signature")
                              .arg(EAGINE_ID(freeSize), free.size())
                              .arg(EAGINE_ID(reason), (!sig).message());
                        }
                    } else {
                        user.log_debug("failed to update ssl signature");
                    }
                } else {
                    user.log_debug("failed to init ssl sign context");
                }
            } else {
                user.log_debug("failed to create ssl message digest")
                  .arg(EAGINE_ID(reason), (!md_ctx).message());
            }
        } else {
            user.log_debug("not enough space for message signature")
              .arg(EAGINE_ID(maxSize), max_size);
        }
    } else {
        user.log_debug("failed to get ssl message digest type")
          .arg(EAGINE_ID(reason), (!md_type).message());
    }
    copy_into(data, _buffer);
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto stored_message::verify_bits(context& ctx, main_ctx_object&) const noexcept
  -> verification_bits {
    return ctx.verify_remote_signature(content(), signature(), source_id);
}
//------------------------------------------------------------------------------
// message_storage
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto message_storage::fetch_all(fetch_handler handler) -> bool {
    bool fetched_some = false;
    bool keep_some = false;
    for(auto& [msg_id, message, insert_time] : _messages) {
        const message_age msg_age{_clock_t::now() - insert_time};
        if(handler(msg_id, msg_age, message)) {
            _buffers.eat(message.release_buffer());
            msg_id = {};
            fetched_some = true;
        } else {
            keep_some = true;
        }
    }
    if(keep_some) {
        _messages.erase(
          std::remove_if(
            _messages.begin(),
            _messages.end(),
            [](auto& t) { return !std::get<0>(t).is_valid(); }),
          _messages.end());
    } else {
        _messages.clear();
    }
    return fetched_some;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void message_storage::cleanup(cleanup_predicate predicate) {
    _messages.erase(
      std::remove_if(
        _messages.begin(),
        _messages.end(),
        [predicate](auto& t) {
            const message_age msg_age{_clock_t::now() - std::get<2>(t)};
            return predicate(msg_age);
        }),
      _messages.end());
}
//------------------------------------------------------------------------------
// serialized_message_storage
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto serialized_message_storage::fetch_all(fetch_handler handler) -> bool {
    bool fetched_some = false;
    bool keep_some = false;
    for(auto& [message, timestamp] : _messages) {
        if(handler(timestamp, view(message))) {
            _buffers.eat(std::move(message));
            fetched_some = true;
        } else {
            keep_some = true;
        }
    }
    if(keep_some) {
        _messages.erase(
          std::remove_if(
            _messages.begin(),
            _messages.end(),
            [](auto& entry) { return std::get<0>(entry).empty(); }),
          _messages.end());
    } else {
        _messages.clear();
    }
    return fetched_some;
}
//------------------------------------------------------------------------------
class message_packing_context {
public:
    using bit_set = message_pack_info::bit_set;

    message_packing_context(memory::block blk) noexcept
      : _blk{blk}
      , _info{_blk.size()} {}

    auto info() const noexcept -> const message_pack_info& {
        return _info;
    }

    auto dest() noexcept {
        return _blk;
    }

    auto is_full() const noexcept {
        return _current_bit == 0U;
    }

    void add(span_size_t size) noexcept {
        _blk = skip(_blk, size);
        _info.add(size, _current_bit);
    }

    void next() noexcept {
        _current_bit <<= 1U;
    }

    void finalize() noexcept {
        zero(_blk);
    }

private:
    bit_set _current_bit{1U};
    memory::block _blk;
    message_pack_info _info;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto serialized_message_storage::pack_into(memory::block dest)
  -> message_pack_info {
    message_packing_context packing{dest};

    for(auto& [message, timestamp] : _messages) {
        EAGINE_MAYBE_UNUSED(timestamp);
        if(packing.is_full()) {
            break;
        }
        if(auto packed{store_data_with_size(view(message), packing.dest())}) {
            packing.add(packed.size());
        }
        packing.next();
    }
    packing.finalize();

    return packing.info();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void serialized_message_storage::cleanup(const message_pack_info& packed) {
    auto to_be_removed = packed.bits();
    span_size_t i = 0;

    // don't try to "optimize" this into the remove_if predicate
    while(to_be_removed) {
        if((to_be_removed & 1U) == 1U) {
            _buffers.eat(std::move(std::get<0>(_messages[i])));
        }
        ++i;
        to_be_removed >>= 1U;
    }
    _messages.erase(
      std::remove_if(
        _messages.begin(),
        _messages.end(),
        [](auto& entry) mutable { return std::get<0>(entry).empty(); }),
      _messages.end());
}
//------------------------------------------------------------------------------
// connection_outgoing_messages
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto connection_outgoing_messages::enqueue(
  main_ctx_object& user,
  message_id msg_id,
  const message_view& message,
  memory::block temp) -> bool {

    block_data_sink sink(temp);
    default_serializer_backend backend(sink);
    auto errors = serialize_message(msg_id, message, backend);
    if(!errors) {
        user.log_trace("enqueuing message ${message} to be sent")
          .arg(EAGINE_ID(message), msg_id);
        _serialized.push(sink.done());
        return true;
    }
    user.log_error("failed to serialize message ${message}")
      .arg(EAGINE_ID(message), msg_id);
    return false;
}
//------------------------------------------------------------------------------
// connection_incoming_messages
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto connection_incoming_messages::fetch_messages(
  main_ctx_object& user,
  fetch_handler handler) -> bool {
    _unpacked.fetch_all(handler);
    auto unpacker = [this, &user, &handler](
                      message_timestamp data_ts, memory::const_block data) {
        for_each_data_with_size(
          data, [this, &user, data_ts](memory::const_block blk) {
              _unpacked.push_if([&user, data_ts, blk](
                                  message_id& msg_id,
                                  message_timestamp& msg_ts,
                                  stored_message& message) {
                  block_data_source source(blk);
                  default_deserializer_backend backend(source);
                  const auto errors =
                    deserialize_message(msg_id, message, backend);
                  if(!errors) {
                      user.log_trace("fetched message ${message}")
                        .arg(EAGINE_ID(message), msg_id);
                      msg_ts = data_ts;
                      return true;
                  } else {
                      user.log_error("failed to deserialize message)")
                        .arg(EAGINE_ID(errorBits), errors.bits())
                        .arg(EAGINE_ID(block), blk);
                      return false;
                  }
              });
          });
        _unpacked.fetch_all(handler);
        return true;
    };

    return _packed.fetch_all({construct_from, unpacker});
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
