/**
 *  @file oglplus/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CONSTANTS_1509260923_HPP
#define OGLPLUS_CONSTANTS_1509260923_HPP

#include "enum/values.hpp"
#include "enum/indexed_values.hpp"

namespace oglplus {

struct constants
 : enum_values
 , indexed_enum_values
{
	using indexed_enum_values::texture0;
	using indexed_enum_values::draw_buffer0;
	using indexed_enum_values::color_attachment0;
#if defined(GL_CLIP_DISTANCE0)
	using indexed_enum_values::clip_distance0;
#endif
};

} // namespace oglplus

#endif // include guard
