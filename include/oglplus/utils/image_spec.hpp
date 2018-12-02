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

#include "../data_type.hpp"
#include "../enum/types.hpp"
#include "memory_block.hpp"
#include "span.hpp"
#include <cassert>

namespace oglplus {

class image_dimensions {
private:
    GLsizei _width;
    GLsizei _height;
    GLsizei _depth;

public:
    image_dimensions(GLsizei w, GLsizei h, GLsizei d) noexcept
      : _width(w)
      , _height(h)
      , _depth(d) {
        assert(_width > 0 && _height > 0 && _depth > 0);
    }

    image_dimensions(GLsizei w, GLsizei h) noexcept
      : image_dimensions(w, h, 1) {
    }

    image_dimensions(GLsizei w) noexcept
      : image_dimensions(w, 1) {
    }

    GLsizei width() const noexcept {
        return _width;
    }

    GLsizei height() const noexcept {
        return _height;
    }

    GLsizei depth() const noexcept {
        return _depth;
    }
};

class image_pixel_format {
private:
    pixel_data_format _format;
    pixel_data_internal_format _internal_format;

public:
    image_pixel_format(
      pixel_data_format fmt, pixel_data_internal_format ifmt) noexcept
      : _format(fmt)
      , _internal_format(ifmt) {
    }

    image_pixel_format(pixel_data_format fmt) noexcept
      : _format(fmt)
      , _internal_format(pixel_data_internal_format(GLenum(fmt))) {
    }

    pixel_data_format format() const noexcept {
        return _format;
    }

    pixel_data_internal_format internal_format() const noexcept {
        return _internal_format;
    }
};

class image_pixel_data {
private:
    pixel_data_type _type;
    const_memory_block _pixels;
    span_size_t _elem_size;

public:
    template <typename T, span_size_t N>
    image_pixel_data(span<T, N> pix_view) noexcept
      : _type(pixel_data_type(GLenum(get_data_type<T>())))
      , _pixels(pix_view.data(), span_size(pix_view.size()))
      , _elem_size(sizeof(T)) {
    }

    image_pixel_data(
      pixel_data_type pix_type,
      const_memory_block pix_data,
      span_size_t type_size) noexcept
      : _type(pix_type)
      , _pixels(pix_data)
      , _elem_size(type_size) {
        assert(_elem_size > 0);
    }

    pixel_data_type type() const noexcept {
        return _type;
    }

    const_memory_block data() const noexcept {
        return _pixels;
    }

    span_size_t elem_size() const noexcept {
        return _elem_size;
    }
};

class image_spec
  : public image_dimensions
  , public image_pixel_format
  , public image_pixel_data {
public:
    image_spec(
      const image_dimensions& dims,
      const image_pixel_format& fmt,
      const image_pixel_data& pix_data) noexcept
      : image_dimensions(dims)
      , image_pixel_format(fmt)
      , image_pixel_data(pix_data) {
    }
};

} // namespace oglplus

#endif // include guard
