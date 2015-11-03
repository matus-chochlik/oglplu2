/**
 *  @file oglplus/enum/indexed_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_INDEXED_TYPES_1509260923_HPP
#define OGLPLUS_ENUM_INDEXED_TYPES_1509260923_HPP

#include "../utils/indexed_enum.hpp"
#include "../utils/limited_value.hpp"

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

#ifdef GL_CLIP_DISTANCE0
typedef limited_value<
	GL_MAX_CLIP_PLANES,
	indexed_enum_value<GL_CLIP_DISTANCE0>
> clip_plane;
#endif

#ifdef GL_CLIP_DISTANCE0
typedef limited_value<
	GL_MAX_COLOR_ATTACHMENTS,
	indexed_enum_value<GL_COLOR_ATTACHMENT0>
> framebuffer_color_attachment;
#endif

} // namespace oglplus

#endif // include guard
