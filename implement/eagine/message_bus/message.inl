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
auto serialized_message_storage::fetch_some(fetch_handler handler, span_size_t n)
  -> bool {
    bool fetched_some = false;
    for(auto& message : _messages) {
        if(n-- <= 0) {
            break;
        }
        if(handler(view(message))) {
            _buffers.eat(std::move(message));
        }
    }
    _messages.erase(
      std::remove_if(
        _messages.begin(),
        _messages.end(),
        [](auto& buf) { return buf.empty(); }),
      _messages.end());
    return fetched_some;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto serialized_message_storage::fetch_all(fetch_handler handler) -> bool {
    bool fetched_some = false;
    bool keep_some = false;
    for(auto& message : _messages) {
        if(handler(view(message))) {
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
            [](auto& buf) { return buf.empty(); }),
          _messages.end());
    } else {
        _messages.clear();
    }
    return fetched_some;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto serialized_message_storage::pack_into(memory::block dest)
  -> std::tuple<bit_set, span_size_t> {
    bit_set result{0U};
    bit_set current{1U};
    span_size_t done{0};

    for(auto& message : _messages) {
        if(current == 0U) {
            break;
        }
        if(auto packed{store_data_with_size(view(message), dest)}) {
            dest = skip(dest, packed.size());
            done += packed.size();
            result |= current;
        }
        current <<= 1U;
    }
    zero(dest);

    return {result, done};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void serialized_message_storage::cleanup(bit_set to_be_removed) {
    _messages.erase(
      std::remove_if(
        _messages.begin(),
        _messages.end(),
        [this, &to_be_removed](auto& message) mutable {
            const bool do_remove = (to_be_removed & 1U) == 1U;
            if(do_remove) {
                _buffers.eat(std::move(message));
            }
            to_be_removed >>= 1U;
            return do_remove;
        }),
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
    string_serializer_backend backend(sink);
    auto errors = serialize_message(msg_id, message, backend);
    if(!errors) {
        user.log_trace("enqueuing message ${message} to be sent")
          .arg(EAGINE_ID(message), msg_id);
        serialized.push(sink.done());
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
  fetch_handler handler,
  span_size_t batch) -> bool {
    unpacked.fetch_all(handler);
    auto unpacker = [this, &user, &handler](memory::const_block data) {
        for_each_data_with_size(data, [this, &user](memory::const_block blk) {
            unpacked.push_if(
              [&user, blk](message_id& msg_id, stored_message& message) {
                  block_data_source source(blk);
                  string_deserializer_backend backend(source);
                  const auto errors =
                    deserialize_message(msg_id, message, backend);
                  if(!errors) {
                      user.log_trace("fetched message ${message}")
                        .arg(EAGINE_ID(message), msg_id);
                      return true;
                  } else {
                      user.log_error("failed to deserialize message)")
                        .arg(EAGINE_ID(errorBits), errors.bits())
                        .arg(EAGINE_ID(block), blk);
                      return false;
                  }
              });
        });
        unpacked.fetch_all(handler);
        return true;
    };

    return packed.fetch_some({construct_from, unpacker}, batch);
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
