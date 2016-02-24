/**
 *  @file oglplus/utils/image_file.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_FILE_1509260923_HPP
#define OGLPLUS_UTILS_IMAGE_FILE_1509260923_HPP

#include "image_spec.hpp"
#include "cstr_ref.hpp"
#include <eagine/offset_ptr.hpp>
#include <eagine/file_contents.hpp>

namespace oglplus {

struct image_data_header
{
	GLsizei width, height, depth;
	GLenum internal_format, format;
	GLenum data_type;

	eagine::offset_array<const GLubyte> pixels;

	constexpr
	image_data_header(void)
	noexcept
	 : width(0)
	 , height(0)
	 , depth(0)
	 , internal_format(GL_NONE)
	 , format(GL_NONE)
	 , data_type(GL_NONE)
	 , pixels()
	{ }
};

class texture_image_file
{
private:
	eagine::structured_file_content<image_data_header> _header;
public:
	texture_image_file(const cstr_ref& path)
	 : _header(path)
	{ }

	image_dimensions dimensions(void) const
	noexcept
	{
		return image_dimensions(
			_header->width,
			_header->height,
			_header->depth
		);
	}

	image_pixel_format pixel_format(void) const
	noexcept
	{
		return image_pixel_format(
			pixel_data_format(_header->format),
			pixel_data_internal_format(_header->internal_format)
		);
	}

	image_pixel_data pixel_data(void) const
	noexcept
	{
		return image_pixel_data(
			pixel_data_type(_header->data_type),
			eagine::memory::data_block_of(_header->pixels),
			sizeof(GLubyte)
		);
	}

	inline
	image_spec spec(void) const
	noexcept
	{
		return image_spec(dimensions(), pixel_format(), pixel_data());
	}

	inline
	operator image_spec (void) const
	noexcept
	{
		return spec();
	}
};

} // namespace oglplus

#endif // include guard
