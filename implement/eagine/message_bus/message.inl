/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/serialize/size_and_data.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
bool stored_message::sign_message(context&, logger&) {
    // TODO
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
verification_bits stored_message::verify_bits(context&, logger&) const
  noexcept {
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool message_storage::fetch_all(fetch_handler handler) {
    bool fetched_some = false;
    bool keep_some = false;
    for(auto& [class_id, method_id, message] : _messages) {
        if(handler(class_id, method_id, message)) {
            class_id = 0;
            method_id = 0;
            _buffers.eat(message.release_buffer());
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
            [](auto& t) {
                return (std::get<0>(t) == 0) && (std::get<1>(t) == 0);
            }),
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

