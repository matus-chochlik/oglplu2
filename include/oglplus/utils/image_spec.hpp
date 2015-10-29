/**
 *  @file oglplus/utils/image_spec.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_SPEC_1509260923_HPP
#define OGLPLUS_UTILS_IMAGE_SPEC_1509260923_HPP

#include "../enum/types.hpp"
#include "../data_type.hpp"
#include "array_view.hpp"
#include "memory_block.hpp"
#include <cassert>

namespace oglplus {

class image_dimensions
{
private:
	GLsizei _width;
	GLsizei _height;
	GLsizei _depth;
public:
	constexpr
	image_dimensions(GLsizei w, GLsizei h, GLsizei d)
	noexcept
	 : _width(w)
	 , _height(h)
	 , _depth(d)
	{
		assert(_width > 0 && _height > 0 && _depth > 0);
	}

	constexpr
	image_dimensions(GLsizei w, GLsizei h)
	noexcept
	 : image_dimensions(w, h, 1)
	{ }

	constexpr
	image_dimensions(GLsizei w)
	noexcept
	 : image_dimensions(w, 1)
	{ }

	GLsizei width(void) const
	noexcept
	{
		return _width;
	}

	GLsizei height(void) const
	noexcept
	{
		return _height;
	}

	GLsizei depth(void) const
	noexcept
	{
		return _depth;
	}
};

class image_pixel_format
{
private:
	GLenum _format;
	GLenum _internal_format;
public:
	constexpr
	image_pixel_format(
		pixel_data_format fmt,
		pixel_data_internal_format ifmt
	) noexcept
	 : _format(GLenum(fmt))
	 , _internal_format(GLenum(ifmt))
	{ }

	constexpr
	image_pixel_format(pixel_data_format fmt)
	noexcept
	 : _format(GLenum(fmt))
	 , _internal_format(GLenum(fmt))
	{ }

	GLenum format(void) const
	noexcept
	{
		return _format;
	}

	GLenum internal_format(void) const
	noexcept
	{
		return _internal_format;
	}
};

class image_pixel_data
{
private:
	GLenum _type;
	const_memory_block _pixels;
	std::size_t _elem_size;
public:
	template <typename T>
	image_pixel_data(array_view<T> pix_view)
	noexcept
	 : _type(get_data_type<T>())
	 , _pixels(pix_view.data(), pix_view.size())
	 , _elem_size(sizeof(T))
	{ }

	image_pixel_data(
		pixel_data_type pix_type,
		const_memory_block pix_data,
		std::size_t type_size
	) noexcept
	 : _type(GLenum(pix_type))
	 , _pixels(pix_data)
	 , _elem_size(type_size)
	{
		assert(_elem_size > 0);
	}

	GLenum type(void) const
	noexcept
	{
		return _type;
	}

	const GLvoid* data(void) const
	noexcept
	{
		return _pixels.addr();
	}

	std::size_t size(void) const
	noexcept
	{
		return _pixels.size();
	}

	std::size_t elem_size(void) const
	noexcept
	{
		return _elem_size;
	}
};

class image_spec
 : public image_dimensions
 , public image_pixel_format
 , public image_pixel_data
{
public:
	image_spec(
		const image_dimensions& dims,
		const image_pixel_format& fmt,
		const image_pixel_data& pix_data
	) noexcept
	 : image_dimensions(dims)
	 , image_pixel_format(fmt)
	 , image_pixel_data(pix_data)
	{ }
};

} // namespace oglplus

#endif // include guard
