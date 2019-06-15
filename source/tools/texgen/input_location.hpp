/**
 *  @file texgen/input_location.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_INPUT_LOCATION_HPP
#define TEXGEN_INPUT_LOCATION_HPP

#include <oglplus/utils/string_span.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
class input_location {
public:
private:
    span_size_t _line;
    span_size_t _column;
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus

#endif // TEXGEN_INPUT_LOCATION_HPP
