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
    data_sink_error = 1 << 1,
    backend_error = 1 << 2
};
//------------------------------------------------------------------------------
enum class deserialization_error_code : std::uint8_t {
    not_enough_data = 1 << 0,
    missing_element = 1 << 1,
    excess_element = 1 << 2,
    missing_member = 1 << 3,
    excess_member = 1 << 4,
    backend_error = 1 << 5
};
//------------------------------------------------------------------------------
using serialization_result = bitfield<serialization_error_code>;
using deserialization_result = bitfield<deserialization_error_code>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_RESULT_HPP

