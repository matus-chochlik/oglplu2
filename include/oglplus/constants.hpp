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
#include "utils/indexed_enum.hpp"
#include "limited_value.hpp"

namespace oglplus {

#ifdef GL_TEXTURE0
typedef limited_value<
	GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
	indexed_enum_value<GL_TEXTURE0>
> texture_unit;
#endif

#ifdef GL_DRAW_BUFFER0
typedef limited_value<
	GL_MAX_DRAW_BUFFERS,
	indexed_enum_value<GL_DRAW_BUFFER0>
> draw_buffer;
#endif

struct constants
 : enum_values
{
#ifdef GL_TEXTURE0
static constexpr const indexed_enum_base<
	GL_TEXTURE0
> texture0 = {};
#endif

#ifdef GL_DRAW_BUFFER0
static constexpr const indexed_enum_base<
	GL_DRAW_BUFFER0
> draw_buffer0 = {};
#endif

#ifdef GL_CLIP_DISTANCE0
static constexpr const indexed_enum_base<
	GL_CLIP_DISTANCE0
> clip_distance0 = {};
#endif

#ifdef GL_COLOR_ATTACHMENT0
static constexpr const indexed_enum_base<
	GL_COLOR_ATTACHMENT0
> color_attachment0 = {};
#endif

};// struct constants
} // namespace oglplus

#endif // include guard
