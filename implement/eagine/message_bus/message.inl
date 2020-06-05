/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/message_bus/context.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
bool stored_message::store_and_sign(
  memory::const_block data, span_size_t max_size, context& ctx, logger& log) {

    auto& ssl = ctx.ssl();
    if(ok md_type{ssl.message_digest_sha256()}) {
        _buffer.resize(max_size);
        if(auto used = store_data_with_size(data, storage())) {
            if(ok md_ctx{ssl.new_message_digest()}) {
                auto cleanup{ssl.delete_message_digest.raii(md_ctx)};

                if(ctx.message_digest_sign_init(md_ctx, md_type)) {
                    ssl.message_digest_sign_update(md_ctx, data);

                    auto free{skip(storage(), used.size())};
                    if(ok sig{ssl.message_digest_sign_final(md_ctx, free)}) {
                        crypto_flags |= message_crypto_flag::asymmetric;
                        crypto_flags |= message_crypto_flag::signed_content;
                        _buffer.resize(used.size() + sig.get().size());
                        return true;
                    } else {
                        log.debug("failed to finish ssl sign context")
                          .arg(EAGINE_ID(freeSize), free.size())
                          .arg(EAGINE_ID(reason), (!sig).message());
                    }
                } else {
                    log.debug("failed to init ssl sign context");
                }
            } else {
                log.debug("failed to create ssl message digest")
                  .arg(EAGINE_ID(reason), (!md_ctx).message());
            }
        } else {
            log.debug("not enough space for message signature")
              .arg(EAGINE_ID(maxSize), max_size);
        }
    } else {
        log.debug("failed to get ssl message digest type")
          .arg(EAGINE_ID(reason), (!md_type).message());
    }
    copy_into(data, _buffer);
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
verification_bits stored_message::verify_bits(context&, logger&) const
  noexcept {
    return {};
}
//------------------------------------------------------------------------------
// message_storage
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool message_storage::fetch_all(fetch_handler handler) {
    bool fetched_some = false;
    bool keep_some = false;
    for(auto& [msg_id, message] : _messages) {
        if(handler(msg_id, message)) {
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
bool serialized_message_storage::fetch_some(
  fetch_handler handler, span_size_t n) {
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
bool serialized_message_storage::fetch_all(fetch_handler handler) {
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
serialized_message_storage::bit_set serialized_message_storage::pack_into(
  memory::block dest) {
    bit_set result{0U};
    bit_set current{1U};

    for(auto& message : _messages) {
        if(current == 0U) {
            break;
        }
        if(auto packed = store_data_with_size(view(message), dest)) {
            dest = skip(dest, packed.size());
            result |= current;
        }
        current <<= 1U;
    }
    zero(dest);

    return result;
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
} // namespace msgbus
} // namespace eagine

