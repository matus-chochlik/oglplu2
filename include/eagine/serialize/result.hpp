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
    not_supported = 1 << 0,
    too_much_data = 1 << 1,
    incomplete_write = 1 << 2,
    data_sink_error = 1 << 3,
    backend_error = 1 << 4
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<serialization_error_code>, Selector) noexcept {
    return enumerator_map_type<serialization_error_code, 5>{
      {{"not_supported", serialization_error_code::not_supported},
       {"too_much_data", serialization_error_code::too_much_data},
       {"incomplete_write", serialization_error_code::incomplete_write},
       {"data_sink_error", serialization_error_code::data_sink_error},
       {"backend_error", serialization_error_code::backend_error}}};
}
//------------------------------------------------------------------------------
enum class deserialization_error_code : std::uint16_t {
    not_supported = 1 << 0,
    not_enough_data = 1 << 1,
    unexpected_data = 1 << 2,
    incomplete_read = 1 << 3,
    missing_element = 1 << 4,
    excess_element = 1 << 5,
    missing_member = 1 << 6,
    excess_member = 1 << 7,
    invalid_format = 1 << 8,
    data_source_error = 1 << 9,
    backend_error = 1 << 10
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<deserialization_error_code>, Selector) noexcept {
    return enumerator_map_type<deserialization_error_code, 11>{
      {{"not_supported", serialization_error_code::not_supported},
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
using deserialization_result =
  valid_if_indicated<T, deserialization_errors, bool, false>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_RESULT_HPP

