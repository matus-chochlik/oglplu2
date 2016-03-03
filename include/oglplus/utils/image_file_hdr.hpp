/**
 *  @file oglplus/utils/image_file_hdr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_FILE_HDR_1509260923_HPP
#define OGLPLUS_UTILS_IMAGE_FILE_HDR_1509260923_HPP

#include <eagine/file_magic_number.hpp>
#include <eagine/offset_ptr.hpp>
#include "valid_if.hpp"
#include <array>

namespace oglplus {

struct image_data_header
{
	eagine::file_magic_number<'o', 'g', 'l', '+', 't', 'e', 'x','i'> magic;
	GLsizei width, height, depth;
	GLenum format, internal_format;
	GLenum data_type;

	eagine::offset_array<const GLubyte> pixels;

	constexpr
	image_data_header(void)
	noexcept
	 : width(0)
	 , height(0)
	 , depth(0)
	 , format(GL_NONE)
	 , internal_format(GL_NONE)
	 , data_type(GL_NONE)
	 , pixels()
	{ }

	image_data_header(
		valid_if_positive<GLsizei> w,
		valid_if_positive<GLsizei> h,
		valid_if_positive<GLsizei> d
	) noexcept
	 : width(w.value())
	 , height(h.value())
	 , depth(d.value())
	 , format(GL_NONE)
	 , internal_format(GL_NONE)
	 , data_type(GL_NONE)
	 , pixels()
	{ }
};

} // namespace oglplus

#endif // include guard
