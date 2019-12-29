/**
 *  @file eagine/msg_bus/message.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_MESSAGE_HPP
#define EAGINE_MSG_BUS_MESSAGE_HPP

#include "../assert.hpp"
#include "../identifier.hpp"
#include "../memory/buffer_pool.hpp"
#include "../memory/span_algo.hpp"
#include "../types.hpp"
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
enum class message_priority { idle, low, normal, high, critical };
//------------------------------------------------------------------------------
struct message_info {
    message_priority priority{message_priority::normal};

    message_info& set_priority(message_priority new_priority) noexcept {
        priority = new_priority;
        return *this;
    }
};
//------------------------------------------------------------------------------
struct message_view : message_info {
    memory::const_block data;

    constexpr message_view() noexcept = default;
    constexpr message_view(memory::const_block init) noexcept
      : data{init} {
    }
    constexpr message_view(message_info info, memory::const_block init) noexcept
      : message_info{std::move(info)}
      , data{init} {
    }
};
//------------------------------------------------------------------------------
struct stored_message : message_info {

    memory::buffer data{};

    stored_message(message_view message, memory::buffer buf) noexcept
      : message_info{message}
      , data{std::move(buf)} {
        data.resize(message.data.size());
        memory::copy(view(message.data), cover(data));
    }

    operator message_view() const {
        return {*this, view(data)};
    }
};
//------------------------------------------------------------------------------
class message_storage {
public:
    using fetch_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    void push(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        _messages.emplace_back(
          class_id,
          method_id,
          stored_message{message, _buffers.get(message.data.size())});
    }

    void fetch_all(fetch_handler handler) {
        bool keep_some = false;
        for(auto& [class_id, method_id, message] : _messages) {
            if(handler(class_id, method_id, message)) {
                class_id = 0;
                method_id = 0;
                _buffers.eat(std::move(message.data));
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
    }

private:
    memory::buffer_pool _buffers;
    std::vector<std::tuple<identifier_t, identifier_t, stored_message>>
      _messages;
};
//------------------------------------------------------------------------------
class message_priority_queue {
public:
    using handler_type = callable_ref<bool(stored_message&)>;

    void push(const message_view& message) {
        auto pos = std::lower_bound(
          _messages.begin(),
          _messages.end(),
          message.priority,
          [](auto& msg, auto pri) { return msg.priority < pri; });

        _messages.emplace(pos, message, _buffers.get(message.data.size()));
    }

    bool process_one(handler_type handler) {
        if(!_messages.empty()) {
            if(handler(_messages.back())) {
                _buffers.eat(std::move(_messages.back().data));
                _messages.pop_back();
                return true;
            }
        }
        return false;
    }

    span_size_t process_all(handler_type handler) {
        span_size_t count{0};
        std::size_t pos = 0;
        while(pos < _messages.size()) {
            if(handler(_messages[pos])) {
                ++count;
                _buffers.eat(std::move(_messages[pos].data));
                _messages.erase(_messages.begin() + pos);
            } else {
                ++pos;
            }
        }
        return count;
    }

private:
    memory::buffer_pool _buffers;
    std::vector<stored_message> _messages;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_MESSAGE_HPP

