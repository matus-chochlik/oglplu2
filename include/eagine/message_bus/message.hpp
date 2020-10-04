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
#include "../bitfield.hpp"
#include "../callable_ref.hpp"
#include "../logging/fwd.hpp"
#include "../memory/buffer_pool.hpp"
#include "../memory/copy.hpp"
#include "../memory/span_algo.hpp"
#include "../message_id.hpp"
#include "../reflect/map_enumerators.hpp"
#include "../serialize/size_and_data.hpp"
#include "context_fwd.hpp"
#include "types.hpp"
#include "verification.hpp"
#include <chrono>
#include <cstdint>
#include <limits>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
#define EAGINE_MSGBUS_ID(METHOD) EAGINE_MSG_ID(eagiMsgBus, METHOD)
//------------------------------------------------------------------------------
static constexpr inline auto is_special_message(message_id msg_id) noexcept {
    return msg_id.has_class(EAGINE_ID(eagiMsgBus));
}
//------------------------------------------------------------------------------
static constexpr inline auto broadcast_endpoint_id() noexcept -> identifier_t {
    return 0U;
}
//------------------------------------------------------------------------------
using message_age = std::chrono::duration<float>;
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
constexpr auto
enumerator_mapping(identity<message_priority>, Selector) noexcept {
    return enumerator_map_type<message_priority, 5>{
      {{"critical", message_priority::critical},
       {"high", message_priority::high},
       {"normal", message_priority::normal},
       {"low", message_priority::low},
       {"idle", message_priority::idle}}};
}
//------------------------------------------------------------------------------
enum class message_crypto_flag : std::uint8_t {
    asymmetric,
    signed_header,
    signed_content
};
using message_crypto_flags = bitfield<message_crypto_flag>;
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(identity<message_crypto_flag>, Selector) noexcept {
    return enumerator_map_type<message_crypto_flag, 3>{
      {{"asymmetric", message_crypto_flag::asymmetric},
       {"signed_header", message_crypto_flag::signed_header},
       {"signed_content", message_crypto_flag::signed_content}}};
}
//------------------------------------------------------------------------------
struct message_info {
    static constexpr auto invalid_id() noexcept -> identifier_t {
        return 0U;
    }

    identifier_t source_id{invalid_id()};
    identifier_t target_id{invalid_id()};
    identifier_t serializer_id{invalid_id()};

    using sequence_t = message_sequence_t;
    sequence_t sequence_no{0U};

    using hop_count_t = std::int8_t;
    hop_count_t hop_count{0};

    message_priority priority{message_priority::normal};

    message_crypto_flags crypto_flags{};

    auto assign(const message_info& that) noexcept -> auto& {
        return *this = that;
    }

    auto too_many_hops() const noexcept -> bool {
        return hop_count >= hop_count_t(64);
    }

    auto add_hop() noexcept -> auto& {
        EAGINE_ASSERT(hop_count < std::numeric_limits<hop_count_t>::max());
        ++hop_count;
        return *this;
    }

    auto set_priority(message_priority new_priority) noexcept -> auto& {
        priority = new_priority;
        return *this;
    }

    auto set_source_id(identifier_t id) noexcept -> auto& {
        source_id = id;
        return *this;
    }

    auto set_target_id(identifier_t id) noexcept -> auto& {
        target_id = id;
        return *this;
    }

    auto has_serializer_id(identifier id) const noexcept -> bool {
        return serializer_id == id.value();
    }

    auto set_serializer_id(identifier id) noexcept -> auto& {
        serializer_id = id.value();
        return *this;
    }

    auto set_sequence_no(message_sequence_t no) noexcept -> auto& {
        sequence_no = no;
        return *this;
    }

    auto setup_response(const message_info& info) noexcept -> auto& {
        target_id = info.source_id;
        sequence_no = info.sequence_no;
        return *this;
    }
};
//------------------------------------------------------------------------------
struct message_view : message_info {
    memory::const_block data;

    constexpr message_view() noexcept = default;
    constexpr message_view(memory::const_block init) noexcept
      : data{init} {}
    constexpr message_view(memory::block init) noexcept
      : data{init} {}
    constexpr message_view(string_view init) noexcept
      : data{as_bytes(init)} {}
    constexpr message_view(message_info info, memory::const_block init) noexcept
      : message_info{info}
      , data{init} {}
};
//------------------------------------------------------------------------------
class stored_message : public message_info {
private:
    memory::buffer _buffer{};

public:
    stored_message() = default;

    stored_message(message_view message, memory::buffer buf) noexcept
      : message_info{message}
      , _buffer{std::move(buf)} {
        memory::copy_into(view(message.data), _buffer);
    }

    operator message_view() const {
        return {*this, data()};
    }

    template <typename Source>
    void fetch_all_from(Source& source) {
        _buffer.clear();
        source.fetch_all(_buffer);
    }

    template <typename Backend, typename Value>
    auto do_store_value(const Value& value, span_size_t max_size) -> bool;

    template <typename Value>
    auto store_value(const Value& value, span_size_t max_size) -> bool;

    template <typename Backend, typename Value>
    auto do_fetch_value(Value& value) -> bool;

    template <typename Value>
    auto fetch_value(Value& value) -> bool;

    auto storage() noexcept -> memory::block {
        return cover(_buffer);
    }

    auto data() const noexcept -> memory::const_block {
        return view(_buffer);
    }

    auto is_signed() const noexcept -> bool {
        return crypto_flags.has(message_crypto_flag::signed_content) ||
               crypto_flags.has(message_crypto_flag::signed_header);
    }

    auto signature() const noexcept -> memory::const_block {
        if(is_signed()) {
            return skip(data(), skip_data_with_size(data()));
        }
        return {};
    }

    auto content() noexcept -> memory::block {
        if(EAGINE_UNLIKELY(is_signed())) {
            return get_data_with_size(storage());
        }
        return storage();
    }

    auto content() const noexcept -> memory::const_block {
        if(EAGINE_UNLIKELY(is_signed())) {
            return get_data_with_size(data());
        }
        return data();
    }

    auto text_content() noexcept {
        return as_chars(content());
    }

    auto text_content() const noexcept {
        return as_chars(content());
    }

    void clear_data() noexcept {
        _buffer.clear();
    }

    auto release_buffer() noexcept -> memory::buffer {
        return std::move(_buffer);
    }

    auto store_and_sign(
      memory::const_block data,
      span_size_t max_size,
      context&,
      logger&) -> bool;

    auto verify_bits(context&, logger&) const noexcept -> verification_bits;
};
//------------------------------------------------------------------------------
class message_storage {
public:
    message_storage() {
        _messages.reserve(64);
    }

    auto empty() const noexcept -> bool {
        return _messages.empty();
    }

    auto size() const noexcept -> span_size_t {
        return span_size(_messages.size());
    }

    void push(message_id msg_id, const message_view& message) {
        _messages.emplace_back(
          msg_id,
          stored_message{message, _buffers.get(message.data.size())},
          _clock_t::now());
    }

    template <typename Function>
    auto push_if(Function function, span_size_t req_size = 0) -> bool {
        _messages.emplace_back(
          message_id{},
          stored_message{{}, _buffers.get(req_size)},
          _clock_t::now());
        auto& [msg_id, message, insert_time] = _messages.back();
        EAGINE_MAYBE_UNUSED(insert_time);
        bool rollback = false;
        try {
            if(!function(msg_id, message)) {
                rollback = true;
            }
        } catch(...) {
            rollback = true;
        }
        if(rollback) {
            _buffers.eat(message.release_buffer());
            _messages.pop_back();
            return false;
        }
        return true;
    }

    /// The return value indicates if the message is considered handled
    /// and should be removed.
    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    auto fetch_all(fetch_handler handler) -> bool;

    using cleanup_predicate = callable_ref<bool(message_age)>;

    void cleanup(cleanup_predicate predicate);

private:
    using _clock_t = std::chrono::steady_clock;
    using _timestamp_t = _clock_t::time_point;
    memory::buffer_pool _buffers;
    std::vector<std::tuple<message_id, stored_message, _timestamp_t>> _messages;
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

    auto empty() const noexcept -> bool {
        return _messages.empty();
    }

    auto size() const noexcept -> span_size_t {
        return span_size(_messages.size());
    }

    auto top() const noexcept -> memory::const_block {
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
        memory::copy_into(message, buf);
        _messages.emplace_back(std::move(buf));
    }

    auto fetch_some(fetch_handler handler, span_size_t n) -> bool;
    auto fetch_all(fetch_handler handler) -> bool;

    using bit_set = std::uint64_t;

    auto pack_into(memory::block dest) -> bit_set;

    void cleanup(bit_set to_be_removed);

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

    auto process_one(handler_type handler) -> bool {
        if(!_messages.empty()) {
            if(handler(_messages.back())) {
                _buffers.eat(_messages.back().release_buffer());
                _messages.pop_back();
                return true;
            }
        }
        return false;
    }

    template <typename Handler>
    auto do_process_all(Handler& handler) -> span_size_t {
        span_size_t count{0};
        std::size_t pos = 0;
        while(pos < _messages.size()) {
            if(handler(_messages[pos])) {
                ++count;
                _buffers.eat(_messages[pos].release_buffer());
                _messages.erase(_messages.begin() + pos);
            } else {
                ++pos;
            }
        }
        return count;
    }

    auto process_all(handler_type handler) -> span_size_t {
        return do_process_all(handler);
    }

private:
    memory::buffer_pool _buffers;
    std::vector<stored_message> _messages;
};
//------------------------------------------------------------------------------
struct connection_outgoing_messages {
    using bit_set = serialized_message_storage::bit_set;

    serialized_message_storage serialized{};

    auto enqueue(logger& log, message_id, const message_view&, memory::block)
      -> bool;

    auto pack_into(memory::block dest) -> bit_set {
        return serialized.pack_into(dest);
    }

    void cleanup(bit_set to_be_removed) {
        serialized.cleanup(to_be_removed);
    }
};
//------------------------------------------------------------------------------
struct connection_incoming_messages {
    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    serialized_message_storage packed{};
    message_storage unpacked{};

    auto empty() const noexcept -> bool {
        return packed.empty();
    }

    void push(memory::const_block data) {
        packed.push(data);
    }

    auto
    fetch_messages(logger& log, fetch_handler handler, span_size_t batch = 64)
      -> bool;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/message.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_MESSAGE_HPP
