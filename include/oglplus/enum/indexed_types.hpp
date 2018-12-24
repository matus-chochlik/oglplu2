/**
 *  @file oglplus/enum/indexed_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_INDEXED_TYPES_HPP
#define OGLPLUS_ENUM_INDEXED_TYPES_HPP

#include "../utils/indexed_enum.hpp"
#include "../utils/limited_value.hpp"

namespace oglplus {

#ifdef GL_TEXTURE0
using texture_unit = limited_value<
  GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
  indexed_enum_value<GL_TEXTURE0>>;
#endif

#ifdef GL_DRAW_BUFFER0
using draw_buffer =
  limited_value<GL_MAX_DRAW_BUFFERS, indexed_enum_value<GL_DRAW_BUFFER0>>;
#endif

#ifdef GL_CLIP_DISTANCE0
using clip_plane =
  limited_value<GL_MAX_CLIP_DISTANCES, indexed_enum_value<GL_CLIP_DISTANCE0>>;
#endif

#ifdef GL_COLOR_ATTACHMENT0
using framebuffer_color_attachment = limited_value<
  GL_MAX_COLOR_ATTACHMENTS,
  indexed_enum_value<GL_COLOR_ATTACHMENT0>>;
#endif

} // namespace oglplus

#endif // OGLPLUS_ENUM_INDEXED_TYPES_HPP
