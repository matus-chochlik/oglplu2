/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MESSAGE_HPP
#define EAGINE_MESSAGE_BUS_MESSAGE_HPP

#include "../assert.hpp"
#include "../bitfield.hpp"
#include "../callable_ref.hpp"
#include "../main_ctx_fwd.hpp"
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
/// @brief Indicates if the specified message id denotes a special message bus message.
/// @ingroup msgbus
static constexpr auto is_special_message(message_id msg_id) noexcept {
    return msg_id.has_class(EAGINE_ID(eagiMsgBus));
}
//------------------------------------------------------------------------------
/// @brief Returns the special broadcast message bus endpoint id.
/// @ingroup msgbus
static constexpr auto broadcast_endpoint_id() noexcept -> identifier_t {
    return 0U;
}
//------------------------------------------------------------------------------
/// @brief Alias for message timestamp type.
/// @ingroup msgbus
/// @see message_age
using message_timestamp = std::chrono::steady_clock::time_point;
//------------------------------------------------------------------------------
/// @brief Alias for message age type.
/// @ingroup msgbus
/// @see message_timestamp
using message_age = std::chrono::duration<float>;
//------------------------------------------------------------------------------
/// @brief Message priority enumeration.
/// @ingroup msgbus
enum class message_priority : std::uint8_t {
    /// @brief Idle, sent only when no messages with higher priority are enqueued.
    idle,
    /// @brief Low message priority.
    low,
    /// @brief Normal, default message priority.
    normal,
    /// @brief High, sent before messages with lower priority.
    high,
    /// @brief Critical, sent as soon as possible.
    critical
};
//------------------------------------------------------------------------------
/// @brief Message priority ordering.
/// @ingroup msgbus
/// @relates message_priority
static inline auto operator<(message_priority l, message_priority r) noexcept
  -> bool {
    using U = std::underlying_type_t<message_priority>;
    return U(l) < U(r);
}
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<message_priority>, Selector) noexcept {
    return enumerator_map_type<message_priority, 5>{
      {{"critical", message_priority::critical},
       {"high", message_priority::high},
       {"normal", message_priority::normal},
       {"low", message_priority::low},
       {"idle", message_priority::idle}}};
}
//------------------------------------------------------------------------------
/// @brief Message cryptography-related flag bits enumeration.
/// @ingroup msgbus
/// @see message_crypto_flags
enum class message_crypto_flag : std::uint8_t {
    /// @brief Assymetric cipher is used (symmetric otherwise).
    asymmetric = 1U << 0U,
    /// @brief The message header is signed.
    signed_header = 1U << 1U,
    /// @brief The message content is signed.
    signed_content = 1U << 2U
};
/// @brief  Alias for message crypto flags bitfield.
/// @ingroup msgbus
using message_crypto_flags = bitfield<message_crypto_flag>;
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<message_crypto_flag>, Selector) noexcept {
    return enumerator_map_type<message_crypto_flag, 3>{
      {{"asymmetric", message_crypto_flag::asymmetric},
       {"signed_header", message_crypto_flag::signed_header},
       {"signed_content", message_crypto_flag::signed_content}}};
}
//------------------------------------------------------------------------------
/// @brief Structure storing information about a sigle message bus message
/// @ingroup msgbus
/// @see message_view
/// @see stored_message
struct message_info {
    static constexpr auto invalid_id() noexcept -> identifier_t {
        return 0U;
    }

    /// @brief Returns the source endpoint identifier.
    /// @see target_id
    /// @see set_source_id
    identifier_t source_id{broadcast_endpoint_id()};

    /// @brief Returns the target endpoint identifier.
    /// @see source_id
    /// @see set_target_id
    identifier_t target_id{broadcast_endpoint_id()};

    /// @brief Returns the identifier of the used serializer.
    /// @see set_serializer_id
    /// @see has_serializer_id
    identifier_t serializer_id{invalid_id()};

    /// @brief Alias for the sequence number type.
    /// @see set_sequence_no
    using sequence_t = message_sequence_t;

    /// @brief The message sequence number.
    /// @see set_sequence_no
    sequence_t sequence_no{0U};

    /// @brief Alias for type used to store the message hop count.
    using hop_count_t = std::int8_t;

    /// @brief The message hop counter.
    /// @see add_hop
    /// @see too_many_hops
    /// Counts how many times the message passed through a router or a bridge.
    hop_count_t hop_count{0};

    /// @brief Alias for type used to store the message age in quarter seconds.
    using age_t = std::int8_t;

    /// @brief The message age in quarter seconds.
    /// @see age
    /// @see add_age
    /// @see too_old
    /// Accumulated time the message spent in various queues.
    age_t age_quarter_seconds{0};

    /// @brief The message priority.
    /// @see set_priority
    message_priority priority{message_priority::normal};

    /// @brief The message cryptography flags.
    message_crypto_flags crypto_flags{};

    auto assign(const message_info& that) noexcept -> auto& {
        return *this = that;
    }

    /// @brief Indicates that the message made too many hops.
    /// @see hop_count
    /// @see add_hop
    auto too_many_hops() const noexcept -> bool {
        return hop_count >= hop_count_t(64);
    }

    /// @brief Increments the hop counter.
    /// @see hop_count
    /// @see too_many_hops
    auto add_hop() noexcept -> auto& {
        EAGINE_ASSERT(hop_count < std::numeric_limits<hop_count_t>::max());
        ++hop_count;
        return *this;
    }

    /// @brief Indicates that the message is too old.
    /// @see age
    /// @see add_age
    auto too_old() const noexcept -> bool {
        switch(priority) {
            case message_priority::idle:
                return age_quarter_seconds > 10 * 4;
            case message_priority::low:
                return age_quarter_seconds > 20 * 4;
            case message_priority::normal:
                return age_quarter_seconds > 30 * 4;
            case message_priority::high:
                return age_quarter_seconds == std::numeric_limits<age_t>::max();
            case message_priority::critical:
                break;
        }
        return false;
    }

    /// @brief Adds to the age seconds counter.
    /// @see age
    /// @see too_old
    auto add_age(message_age age) noexcept -> auto& {
        const float added_quarter_seconds = (age.count() + 0.20F) * 4.F;
        if(auto new_age{convert_if_fits<age_t>(
             int(age_quarter_seconds) + int(added_quarter_seconds))}) {
            age_quarter_seconds = extract(new_age);
        } else {
            age_quarter_seconds = std::numeric_limits<age_t>::max();
        }
        return *this;
    }

    /// @brief Returns the message age
    /// @see too_old
    /// @see add_age
    auto age() const noexcept -> message_age {
        return message_age{float(age_quarter_seconds) * 0.25F};
    }

    /// @brief Sets the priority of this message.
    auto set_priority(message_priority new_priority) noexcept -> auto& {
        priority = new_priority;
        return *this;
    }

    /// @brief Sets the source endpoint identifier.
    auto set_source_id(identifier_t id) noexcept -> auto& {
        source_id = id;
        return *this;
    }

    /// @brief Sets the target endpoint identifier.
    auto set_target_id(identifier_t id) noexcept -> auto& {
        target_id = id;
        return *this;
    }

    /// @brief Tests if a data serializer with the specified id was used.
    /// @see serializer_id
    /// @see set_serializer_id
    auto has_serializer_id(identifier id) const noexcept -> bool {
        return serializer_id == id.value();
    }

    /// @brief Sets the id of the used data content serializer.
    /// @see serializer_id
    /// @see has_serializer_id
    auto set_serializer_id(identifier id) noexcept -> auto& {
        serializer_id = id.value();
        return *this;
    }

    /// @brief Sets the sequence number of this message (has message-type specific meaning).
    /// @see sequence_no
    auto set_sequence_no(message_sequence_t no) noexcept -> auto& {
        sequence_no = no;
        return *this;
    }

    /// @brief Sets the target id to be the source id from info, copies sequence number.
    /// @see source_id
    /// @see target_id
    /// @see sequence_no
    auto setup_response(const message_info& info) noexcept -> auto& {
        target_id = info.source_id;
        sequence_no = info.sequence_no;
        age_quarter_seconds = info.age_quarter_seconds;
        priority = info.priority;
        return *this;
    }
};
//------------------------------------------------------------------------------
/// @brief Combines message information and a non-owning view to message content.
/// @ingroup msgbus
class message_view : public message_info {
public:
    /// @brief Default constructor.
    constexpr message_view() noexcept = default;

    /// @brief Construction from a const memory block.
    constexpr message_view(memory::const_block init) noexcept
      : _data{init} {}

    /// @brief Construction from a mutable memory block.
    constexpr message_view(memory::block init) noexcept
      : _data{init} {}

    /// @brief Construction from a string view.
    constexpr message_view(string_view init) noexcept
      : _data{as_bytes(init)} {}

    /// @brief Construction from a message info and a const memory block.
    constexpr message_view(message_info info, memory::const_block init) noexcept
      : message_info{info}
      , _data{init} {}

    /// @brief Indicates if the header or the content is signed.
    /// @see signature
    auto is_signed() const noexcept -> bool {
        return crypto_flags.has(message_crypto_flag::signed_content) ||
               crypto_flags.has(message_crypto_flag::signed_header);
    }

    /// @brief Returns a const view of the storage buffer.
    auto data() const noexcept -> memory::const_block {
        return _data;
    }

    /// @brief Returns the message signature.
    /// @see is_signed
    /// @see content
    auto signature() const noexcept -> memory::const_block {
        if(is_signed()) {
            return skip(data(), skip_data_with_size(data()));
        }
        return {};
    }

    /// @brief Returns a const view of the data content of the message.
    /// @see signature
    /// @see text_content
    /// @see const_content
    auto content() const noexcept -> memory::const_block {
        if(EAGINE_UNLIKELY(is_signed())) {
            return get_data_with_size(data());
        }
        return data();
    }

    /// @brief Returns the content as a const string view.
    /// @see content
    auto text_content() const noexcept {
        return as_chars(content());
    }

private:
    /// @brief View of the message data content.
    memory::const_block _data;
};
//------------------------------------------------------------------------------
/// @brief Combines message information and an owned message content buffer.
/// @ingroup msgbus
class stored_message : public message_info {
public:
    /// @brief Default constructor.
    stored_message() = default;

    /// @brief Construction from a message view and storage buffer.
    /// Adopts the buffer and copies the content from the message view into it.
    stored_message(message_view message, memory::buffer buf) noexcept
      : message_info{message}
      , _buffer{std::move(buf)} {
        memory::copy_into(view(message.data()), _buffer);
    }

    /// @brief Conversion to message view.
    operator message_view() const {
        return {*this, data()};
    }

    /// @brief Copies the remaining data from the specified serialization source.
    template <typename Source>
    void fetch_all_from(Source& source) {
        _buffer.clear();
        source.fetch_all(_buffer);
    }

    /// @brief Copies the content from the given block into the internal buffer.
    void store_content(memory::const_block blk) {
        memory::copy_into(blk, _buffer);
    }

    template <typename Backend, typename Value>
    auto do_store_value(const Value& value, span_size_t max_size) -> bool;

    /// @brief Serializes and stores the specified value (up to max_size).
    template <typename Value>
    auto store_value(const Value& value, span_size_t max_size) -> bool;

    template <typename Backend, typename Value>
    auto do_fetch_value(Value& value) -> bool;

    /// @brief Deserializes the stored content into the specified value.
    template <typename Value>
    auto fetch_value(Value& value) -> bool;

    /// @brief Returns a mutable view of the storage buffer.
    auto storage() noexcept -> memory::block {
        return cover(_buffer);
    }

    /// @brief Returns a const view of the storage buffer.
    auto data() const noexcept -> memory::const_block {
        return view(_buffer);
    }

    /// @brief Indicates if the header or the content is signed.
    /// @see signature
    auto is_signed() const noexcept -> bool {
        return crypto_flags.has(message_crypto_flag::signed_content) ||
               crypto_flags.has(message_crypto_flag::signed_header);
    }

    /// @brief Returns the message signature.
    /// @see is_signed
    /// @see content
    auto signature() const noexcept -> memory::const_block {
        if(is_signed()) {
            return skip(data(), skip_data_with_size(data()));
        }
        return {};
    }

    /// @brief Returns a mutable view of the data content of the message.
    /// @see signature
    auto content() noexcept -> memory::block {
        if(EAGINE_UNLIKELY(is_signed())) {
            return get_data_with_size(storage());
        }
        return storage();
    }

    /// @brief Returns a const view of the data content of the message.
    /// @see signature
    /// @see text_content
    /// @see const_content
    auto content() const noexcept -> memory::const_block {
        if(EAGINE_UNLIKELY(is_signed())) {
            return get_data_with_size(data());
        }
        return data();
    }

    /// @brief Returns a const view of the data content of the message.
    /// @see signature
    /// @see content
    /// @see text_content
    auto const_content() const noexcept -> memory::const_block {
        return content();
    }

    /// @brief Returns the content as a mutable string view.
    /// @see content
    auto text_content() noexcept {
        return as_chars(content());
    }

    /// @brief Returns the content as a const string view.
    /// @see content
    auto text_content() const noexcept {
        return as_chars(content());
    }

    /// @brief Returns the content as a const string view.
    /// @see content
    /// @see text_content
    /// @see const_content
    auto const_text_content() const noexcept {
        return as_chars(const_content());
    }

    /// @brief Clears the content of the storage buffer.
    void clear_data() noexcept {
        _buffer.clear();
    }

    /// @brief Releases and returns the storage buffer (without clearing it).
    auto release_buffer() noexcept -> memory::buffer {
        return std::move(_buffer);
    }

    /// @brief Stores the specified data and signs it.
    auto store_and_sign(
      memory::const_block data,
      span_size_t max_size,
      context&,
      main_ctx_object&) -> bool;

    /// @brief Verifies the signatures of this message.
    auto verify_bits(context&, main_ctx_object&) const noexcept
      -> verification_bits;

private:
    memory::buffer _buffer{};
};
//------------------------------------------------------------------------------
/// @brief Class storing message bus messages.
/// @ingroup msgbus
/// @see serialized_message_storage
class message_storage {
public:
    /// @brief Default constructor.
    message_storage() {
        _messages.reserve(64);
    }

    /// @brief Indicates if the storage is empty.
    auto empty() const noexcept -> bool {
        return _messages.empty();
    }

    /// @brief Returns the coung of messages in the storage.
    auto count() const noexcept -> span_size_t {
        return span_size(_messages.size());
    }

    /// @brief Pushes a message into this storage.
    void push(message_id msg_id, const message_view& message) {
        _messages.emplace_back(
          msg_id,
          stored_message{message, _buffers.get(message.data().size())},
          _clock_t::now());
    }

    /// @brief Pushes a new message and lets a function to fill it.
    ///
    /// The function's Boolean return value indicates if the message should be kept.
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
            if(!function(msg_id, insert_time, message)) {
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

    /// @brief Alias for the message fetch handler.
    /// @see fetch_all
    ///
    /// The return value indicates if the message is considered handled
    /// and should be removed.
    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    /// @brief Fetches all currently stored messages and calls handler on them.
    auto fetch_all(fetch_handler handler) -> bool;

    /// @brief Alias for message cleanup callable predicate.
    /// @see cleanup
    ///
    /// The return value indicates if a message should be removed.
    using cleanup_predicate = callable_ref<bool(message_age)>;

    /// @brief Removes messages based on the result of the specified predicate.
    void cleanup(cleanup_predicate predicate);

private:
    using _clock_t = std::chrono::steady_clock;
    memory::buffer_pool _buffers;
    std::vector<std::tuple<message_id, stored_message, message_timestamp>>
      _messages;
};
//------------------------------------------------------------------------------
class message_pack_info {
public:
    using bit_set = std::uint64_t;

    message_pack_info(span_size_t total_size) noexcept
      : _total_size{limit_cast<std::uint16_t>(total_size)} {}

    operator bool() const noexcept {
        return !is_empty();
    }

    auto is_empty() const noexcept -> bool {
        return _packed_bits == 0U;
    }

    auto bits() const noexcept -> bit_set {
        return _packed_bits;
    }

    auto count() const noexcept -> span_size_t {
        span_size_t result = 0;
        auto bits = _packed_bits;
        while(bits) {
            ++result;
            bits &= (bits - 1U);
        }
        return result;
    }

    auto used() const noexcept -> span_size_t {
        return span_size(_packed_size);
    }

    auto total() const noexcept -> span_size_t {
        return span_size(_total_size);
    }

    auto usage() const noexcept {
        return float(used()) / float(total());
    }

    void add(span_size_t msg_size, bit_set current_bit) noexcept {
        _packed_size += limit_cast<std::uint16_t>(msg_size);
        _packed_bits |= current_bit;
    }

private:
    bit_set _packed_bits{0U};
    std::uint16_t _packed_size{0};
    const std::uint16_t _total_size{0};
};
//------------------------------------------------------------------------------
class serialized_message_storage {
public:
    /// The return value indicates if the message is considered handled
    /// and should be removed.
    using fetch_handler =
      callable_ref<bool(message_timestamp, memory::const_block)>;

    serialized_message_storage() {
        _messages.reserve(32);
    }

    auto empty() const noexcept -> bool {
        return _messages.empty();
    }

    auto count() const noexcept -> span_size_t {
        return span_size(_messages.size());
    }

    auto top() const noexcept -> memory::const_block {
        if(!_messages.empty()) {
            return view(std::get<0>(_messages.front()));
        }
        return {};
    }

    void pop() noexcept {
        EAGINE_ASSERT(!_messages.empty());
        _buffers.eat(std::move(std::get<0>(_messages.front())));
        _messages.erase(_messages.begin());
    }

    void push(memory::const_block message) {
        EAGINE_ASSERT(!message.empty());
        auto buf = _buffers.get(message.size());
        memory::copy_into(message, buf);
        _messages.emplace_back(std::move(buf), _clock_t::now());
    }

    auto fetch_all(fetch_handler handler) -> bool;

    auto pack_into(memory::block dest) -> message_pack_info;

    void cleanup(const message_pack_info& to_be_removed);

private:
    using _clock_t = std::chrono::steady_clock;
    memory::buffer_pool _buffers;
    std::vector<std::tuple<memory::buffer, message_timestamp>> _messages;
};
//------------------------------------------------------------------------------
class endpoint;
//------------------------------------------------------------------------------
class message_context {
public:
    message_context(endpoint& ep) noexcept
      : _bus{ep} {}

    constexpr message_context(endpoint& ep, message_id mi) noexcept
      : _bus{ep}
      , _msg_id{std::move(mi)} {}

    auto bus_node() const noexcept -> endpoint& {
        return _bus;
    }

    auto msg_id() const noexcept -> const message_id& {
        return _msg_id;
    }

    auto set_msg_id(message_id msg_id) noexcept -> message_context& {
        _msg_id = std::move(msg_id);
        return *this;
    }

private:
    endpoint& _bus;
    message_id _msg_id{};
};
//------------------------------------------------------------------------------
class message_priority_queue {
public:
    using handler_type =
      callable_ref<bool(const message_context&, stored_message&)>;

    message_priority_queue() {
        _messages.reserve(128);
    }

    auto size() const noexcept {
        return _messages.size();
    }

    auto push(const message_view& message) -> stored_message& {
        auto pos = std::lower_bound(
          _messages.begin(),
          _messages.end(),
          message.priority,
          [](auto& msg, auto pri) { return msg.priority < pri; });

        return *_messages.emplace(
          pos, message, _buffers.get(message.data().size()));
    }

    auto process_one(const message_context& msg_ctx, handler_type handler)
      -> bool {
        if(!_messages.empty()) {
            if(handler(msg_ctx, _messages.back())) {
                _buffers.eat(_messages.back().release_buffer());
                _messages.pop_back();
                return true;
            }
        }
        return false;
    }

    auto process_all(const message_context& msg_ctx, handler_type handler)
      -> span_size_t {
        span_size_t count{0};
        std::size_t pos = 0;
        while(pos < _messages.size()) {
            if(handler(msg_ctx, _messages[pos])) {
                ++count;
                _buffers.eat(_messages[pos].release_buffer());
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
class connection_outgoing_messages {
public:
    auto count() const noexcept -> span_size_t {
        return _serialized.count();
    }

    auto empty() const noexcept -> bool {
        return _serialized.empty();
    }

    auto enqueue(
      main_ctx_object& user,
      message_id,
      const message_view&,
      memory::block) -> bool;

    auto pack_into(memory::block dest) -> message_pack_info {
        return _serialized.pack_into(dest);
    }

    void cleanup(const message_pack_info& packed) {
        _serialized.cleanup(packed);
    }

private:
    serialized_message_storage _serialized{};
};
//------------------------------------------------------------------------------
class connection_incoming_messages {
public:
    using fetch_handler =
      callable_ref<bool(message_id, message_age, const message_view&)>;

    auto empty() const noexcept -> bool {
        return _packed.empty();
    }

    auto count() const noexcept -> span_size_t {
        return _packed.count();
    }

    void push(memory::const_block data) {
        _packed.push(data);
    }

    auto fetch_messages(main_ctx_object& user, fetch_handler handler) -> bool;

private:
    serialized_message_storage _packed{};
    message_storage _unpacked{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/message.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_MESSAGE_HPP
