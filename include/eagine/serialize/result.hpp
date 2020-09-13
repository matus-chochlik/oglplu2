/**
 *  @file eagine/serialize/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_RESULT_HPP
#define EAGINE_SERIALIZE_RESULT_HPP

#include "../bitfield.hpp"
#include "../reflect/map_enumerators.hpp"
#include "../valid_if/indicated.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
enum class serialization_error_code : std::uint8_t {
    not_supported = 1U << 0U,
    too_much_data = 1U << 1U,
    incomplete_write = 1U << 2U,
    data_sink_error = 1U << 3U,
    backend_error = 1U << 4U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(identity<serialization_error_code>, Selector) noexcept {
    return enumerator_map_type<serialization_error_code, 5>{
      {{"not_supported", serialization_error_code::not_supported},
       {"too_much_data", serialization_error_code::too_much_data},
       {"incomplete_write", serialization_error_code::incomplete_write},
       {"data_sink_error", serialization_error_code::data_sink_error},
       {"backend_error", serialization_error_code::backend_error}}};
}
//------------------------------------------------------------------------------
enum class deserialization_error_code : std::uint16_t {
    not_supported = 1U << 0U,
    not_enough_data = 1U << 1U,
    unexpected_data = 1U << 2U,
    incomplete_read = 1U << 3U,
    missing_element = 1U << 4U,
    excess_element = 1U << 5U,
    missing_member = 1U << 6U,
    excess_member = 1U << 7U,
    invalid_format = 1U << 8U,
    data_source_error = 1U << 9U,
    backend_error = 1U << 10U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(identity<deserialization_error_code>, Selector) noexcept {
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
using serialization_errors = bitfield<serialization_error_code>;
using deserialization_errors = bitfield<deserialization_error_code>;
//------------------------------------------------------------------------------
template <typename T>
using serialization_result =
  valid_if_indicated<T, serialization_errors, bool, false>;
//------------------------------------------------------------------------------
template <typename T>
static inline serialization_errors
get_errors(const serialization_result<T>& result) noexcept {
    return result.policy()._indicator;
}
//------------------------------------------------------------------------------
template <typename T>
using deserialization_result =
  valid_if_indicated<T, deserialization_errors, bool, false>;
//------------------------------------------------------------------------------
template <typename T>
static inline deserialization_errors
get_errors(const deserialization_result<T>& result) noexcept {
    return result.policy()._indicator;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_RESULT_HPP
