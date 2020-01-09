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
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
enum class serialization_error_code : std::uint8_t {
    too_much_data = 1 << 0,
    incomplete_write = 1 << 1,
    data_sink_error = 1 << 2,
    backend_error = 1 << 3
};
//------------------------------------------------------------------------------
enum class deserialization_error_code : std::uint16_t {
    not_enough_data = 1 << 0,
    unexpected_data = 1 << 1,
    incomplete_read = 1 << 2,
    missing_element = 1 << 3,
    excess_element = 1 << 4,
    missing_member = 1 << 5,
    excess_member = 1 << 6,
    invalid_format = 1 << 7,
    data_source_error = 1 << 8,
    backend_error = 1 << 9
};
//------------------------------------------------------------------------------
using serialization_result = bitfield<serialization_error_code>;
using deserialization_result = bitfield<deserialization_error_code>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_RESULT_HPP

