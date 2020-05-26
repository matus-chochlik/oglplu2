/**
 *  @file eagine/message_bus/message.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_MESSAGE_HPP
#define EAGINE_MESSAGE_BUS_MESSAGE_HPP

#include "../assert.hpp"
#include "../callable_ref.hpp"
#include "../identifier.hpp"
#include "../memory/buffer_pool.hpp"
#include "../memory/span_algo.hpp"
#include "../reflect/map_enumerators.hpp"
#include "../serialize/size_and_data.hpp"
#include "types.hpp"
#include <cstdint>
#include <limits>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
enum class message_priority : std::uint8_t {
    idle,
    low,
    normal,
    high,
    critical
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<message_priority>, Selector) noexcept {
    return enumerator_map_type<message_priority, 5>{
      {{"critical", message_priority::critical},
       {"high", message_priority::high},
       {"normal", message_priority::normal},
       {"low", message_priority::low},
       {"idle", message_priority::idle}}};
}
//------------------------------------------------------------------------------
struct message_info {
    static constexpr identifier_t inline invalid_id() noexcept {
        return 0U;
    }

    identifier_t source_id{invalid_id()};
    identifier_t target_id{invalid_id()};
    identifier_t serializer_id{invalid_id()};

    using sequence_t = message_sequence_t;
    sequence_t sequence_no{0U};

    message_priority priority{message_priority::normal};

    using hop_count_t = std::int8_t;
    hop_count_t hop_count{0};

    message_info& assign(const message_info& that) noexcept {
        return *this = that;
    }

    message_info& set_priority(message_priority new_priority) noexcept {
        priority = new_priority;
        return *this;
    }

    message_info& set_source_id(identifier_t id) noexcept {
        source_id = id;
        return *this;
    }

    message_info& set_target_id(identifier_t id) noexcept {
        target_id = id;
        return *this;
    }

    message_info& set_serializer_id(identifier id) noexcept {
        serializer_id = id.value();
        return *this;
    }

    message_info& set_sequence_no(message_sequence_t no) noexcept {
        sequence_no = no;
        return *this;
    }

    message_info& setup_response(const message_info& info) noexcept {
        target_id = info.source_id;
        sequence_no = info.sequence_no;
        return *this;
    }

    bool too_many_hops() const noexcept {
        return hop_count >= hop_count_t(64);
    }

    message_info& add_hop() noexcept {
        EAGINE_ASSERT(hop_count < std::numeric_limits<hop_count_t>::max());
        ++hop_count;
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
    constexpr message_view(memory::block init) noexcept
      : data{init} {
    }
    constexpr message_view(string_view init) noexcept
      : data{as_bytes(init)} {
    }
    constexpr message_view(message_info info, memory::const_block init) noexcept
      : message_info{info}
      , data{init} {
    }
};
//------------------------------------------------------------------------------
struct stored_message : message_info {

    memory::buffer data{};

    stored_message() = default;

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
    /// The return value indicates if the message is considered handled
    /// and should be removed.
    using fetch_handler =
      callable_ref<bool(identifier_t, identifier_t, const message_view&)>;

    message_storage() {
        _messages.reserve(64);
    }

    bool empty() const noexcept {
        return _messages.empty();
    }

    span_size_t size() const noexcept {
        return span_size(_messages.size());
    }

    void push(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        _messages.emplace_back(
          class_id,
          method_id,
          stored_message{message, _buffers.get(message.data.size())});
    }

    template <typename Function>
    bool push_if(Function function, span_size_t req_size = 0) {
        _messages.emplace_back(
          identifier_t{0},
          identifier_t{0},
          stored_message{{}, _buffers.get(req_size)});
        auto& [class_id, method_id, message] = _messages.back();
        bool rollback = false;
        try {
            if(!function(class_id, method_id, message)) {
                rollback = true;
            }
        } catch(...) {
            rollback = true;
        }
        if(rollback) {
            _buffers.eat(std::move(message.data));
            _messages.pop_back();
            return false;
        }
        return true;
    }

    bool fetch_all(fetch_handler handler) {
        bool fetched_some = false;
        bool keep_some = false;
        for(auto& [class_id, method_id, message] : _messages) {
            if(handler(class_id, method_id, message)) {
                class_id = 0;
                method_id = 0;
                _buffers.eat(std::move(message.data));
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

private:
    memory::buffer_pool _buffers;
    std::vector<std::tuple<identifier_t, identifier_t, stored_message>>
      _messages;
};
//------------------------------------------------------------------------------
class serialized_message_storage {
public:
    /// The return value indicates if the message is considered handled
    /// and should be removed.
    using fetch_handler = callable_ref<bool(memory::const_block)>;

    serialized_message_storage() {
        _messages.reserve(32);
    }

    bool empty() const noexcept {
        return _messages.empty();
    }

    span_size_t size() const noexcept {
        return span_size(_messages.size());
    }

    memory::const_block top() const noexcept {
        if(!_messages.empty()) {
            return view(_messages.front());
        }
        return {};
    }

    void pop() noexcept {
        EAGINE_ASSERT(!_messages.empty());
        _buffers.eat(std::move(_messages.front()));
        _messages.erase(_messages.begin());
    }

    void push(memory::const_block message) {
        EAGINE_ASSERT(!message.empty());
        auto buf = _buffers.get(message.size());
        buf.resize(message.size());
        memory::copy(message, cover(buf));
        _messages.emplace_back(std::move(buf));
    }

    bool fetch_some(fetch_handler handler, span_size_t n) {
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

    bool fetch_all(fetch_handler handler) {
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

    using bit_set = std::uint64_t;

    bit_set pack_into(memory::block dest) {
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

    void cleanup(bit_set to_be_removed) {
        _messages.erase(
          std::remove_if(
            _messages.begin(),
            _messages.end(),
            [this, to_be_removed](auto& message) mutable {
                const bool do_remove = (to_be_removed & 1U) == 1U;
                if(do_remove) {
                    _buffers.eat(std::move(message));
                }
                to_be_removed >>= 1U;
                return do_remove;
            }),
          _messages.end());
    }

private:
    memory::buffer_pool _buffers;
    std::vector<memory::buffer> _messages;
};
//------------------------------------------------------------------------------
class message_priority_queue {
public:
    using handler_type = callable_ref<bool(stored_message&)>;

    message_priority_queue() {
        _messages.reserve(128);
    }

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

    template <typename Handler>
    span_size_t do_process_all(Handler& handler) {
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

    span_size_t process_all(handler_type handler) {
        return do_process_all(handler);
    }

private:
    memory::buffer_pool _buffers;
    std::vector<stored_message> _messages;
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_MESSAGE_HPP

