/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_RESULT_HPP
#define EAGINE_SERIALIZE_RESULT_HPP

#include "../bitfield.hpp"
#include "../reflect/map_enumerators.hpp"
#include "../valid_if/indicated.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Serialization error code bits enumeration.
/// @ingroup serialization
/// @see serialization_errors
/// @see serializer_backend
/// @see serializer_data_sink
enum class serialization_error_code : std::uint8_t {
    /// @brief Value type or format not supported.
    not_supported = 1U << 0U,
    /// @brief Too much data to fit into serialization data sink.
    too_much_data = 1U << 1U,
    /// @brief Incomplete write, remaining data should be written later.
    incomplete_write = 1U << 2U,
    /// @brief Internal error in the serialization data sink.
    data_sink_error = 1U << 3U,
    /// @brief Internal error in the serialization backend.
    backend_error = 1U << 4U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<serialization_error_code>, Selector) noexcept {
    return enumerator_map_type<serialization_error_code, 5>{
      {{"not_supported", serialization_error_code::not_supported},
       {"too_much_data", serialization_error_code::too_much_data},
       {"incomplete_write", serialization_error_code::incomplete_write},
       {"data_sink_error", serialization_error_code::data_sink_error},
       {"backend_error", serialization_error_code::backend_error}}};
}
//------------------------------------------------------------------------------
/// @brief Deserialization error code bits enumeration.
/// @ingroup serialization
/// @see deserialization_errors
/// @see deserializer_backend
/// @see deserializer_data_sink
enum class deserialization_error_code : std::uint16_t {
    /// @brief Value type or format not supported.
    not_supported = 1U << 0U,
    /// @brief Not enough data to deserialize the value.
    not_enough_data = 1U << 1U,
    /// @brief Superfluous data in the deserialization source.
    unexpected_data = 1U << 2U,
    /// @brief Incomplete read, remaining data should be read later.
    incomplete_read = 1U << 3U,
    /// @brief Missing data for container element.
    missing_element = 1U << 4U,
    /// @brief Superfluous data for container element.
    excess_element = 1U << 5U,
    /// @brief Missing data for class data member.
    missing_member = 1U << 6U,
    /// @brief Superfluous data for class data member.
    excess_member = 1U << 7U,
    /// @brief Invalid data format.
    invalid_format = 1U << 8U,
    /// @brief Internal error in the deserialization data source.
    data_source_error = 1U << 9U,
    /// @brief Internal error in the deserialization backend.
    backend_error = 1U << 10U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  type_identity<deserialization_error_code>,
  Selector) noexcept {
    return enumerator_map_type<deserialization_error_code, 11>{
      {{"not_supported", deserialization_error_code::not_supported},
       {"not_enough_data", deserialization_error_code::not_enough_data},
       {"unexpected_data", deserialization_error_code::unexpected_data},
       {"incomplete_read", deserialization_error_code::incomplete_read},
       {"missing_element", deserialization_error_code::missing_element},
       {"excess_element", deserialization_error_code::excess_element},
       {"missing_member", deserialization_error_code::missing_member},
       {"excess_member", deserialization_error_code::excess_member},
       {"invalid_format", deserialization_error_code::invalid_format},
       {"data_source_error", deserialization_error_code::data_source_error},
       {"backend_error", deserialization_error_code::backend_error}}};
}
//------------------------------------------------------------------------------
/// @brief Alias for serialization error bitfield.
/// @ingroup serialization
/// @see serialization_result
/// @see deserialization_errors
using serialization_errors = bitfield<serialization_error_code>;

/// @brief Alias for deserialization error bitfield.
/// @ingroup serialization
/// @see deserialization_result
/// @see serialization_errors
using deserialization_errors = bitfield<deserialization_error_code>;
//------------------------------------------------------------------------------
/// @brief Alias for result type of serialization operations.
/// @ingroup serialization
/// @see deserialization_result
/// @see get_errors
template <typename T>
using serialization_result =
  valid_if_indicated<T, serialization_errors, bool, false>;
//------------------------------------------------------------------------------
/// @brief Returns the error bitfield from a serialization result.
/// @ingroup serialization
template <typename T>
static inline auto get_errors(const serialization_result<T>& result) noexcept
  -> serialization_errors {
    return result.policy()._indicator;
}
//------------------------------------------------------------------------------
/// @brief Alias for result type of deserialization operations.
/// @ingroup serialization
/// @see serialization_result
/// @see get_errors
template <typename T>
using deserialization_result =
  valid_if_indicated<T, deserialization_errors, bool, false>;
//------------------------------------------------------------------------------
/// @brief Returns the error bitfield from a deserialization result.
/// @ingroup serialization
template <typename T>
static inline auto get_errors(const deserialization_result<T>& result) noexcept
  -> deserialization_errors {
    return result.policy()._indicator;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_RESULT_HPP
