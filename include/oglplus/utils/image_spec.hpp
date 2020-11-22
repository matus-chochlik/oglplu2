/**
 *  @file oglplus/utils/image_spec.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_SPEC_HPP
#define OGLPLUS_UTILS_IMAGE_SPEC_HPP

#include "../gl_api/enum_types.hpp"
#include <eagine/assert.hpp>
#include <eagine/memory/block.hpp>
#include <eagine/span.hpp>

namespace eagine::oglp {

class image_dimensions {
private:
    gl_types::sizei_type _width{1};
    gl_types::sizei_type _height{1};
    gl_types::sizei_type _depth{1};
    gl_types::sizei_type _channels{1};

public:
    image_dimensions(
      gl_types::sizei_type w,
      gl_types::sizei_type h,
      gl_types::sizei_type d,
      gl_types::sizei_type c) noexcept
      : _width(w)
      , _height(h)
      , _depth(d)
      , _channels(c) {
        EAGINE_ASSERT(_width > 0 && _height > 0 && _depth > 0);
    }

    auto is_1d() const noexcept -> bool {
        return _width > 1 && _height == 1 && _depth == 1;
    }

    auto is_2d() const noexcept -> bool {
        return _width > 1 && _height > 1 && _depth == 1;
    }

    auto is_3d() const noexcept -> bool {
        return _width > 1 && _height > 1 && _depth > 1;
    }

    auto width() const noexcept -> gl_types::sizei_type {
        return _width;
    }

    auto height() const noexcept -> gl_types::sizei_type {
        return _height;
    }

    auto depth() const noexcept -> gl_types::sizei_type {
        return _depth;
    }

    auto channels() const noexcept -> gl_types::sizei_type {
        return _channels;
    }
};

class image_pixel_format {
private:
    pixel_format _format;
    pixel_internal_format _internal_format;

public:
    image_pixel_format(pixel_format fmt, pixel_internal_format ifmt) noexcept
      : _format(fmt)
      , _internal_format(ifmt) {}

    image_pixel_format(pixel_format fmt) noexcept
      : _format(fmt)
      , _internal_format(pixel_internal_format(GLenum(fmt))) {}

    auto format() const noexcept -> pixel_format {
        return _format;
    }

    auto internal_format() const noexcept -> pixel_internal_format {
        return _internal_format;
    }
};

class image_pixel_data {
private:
    pixel_data_type _type;
    memory::const_block _pixels;
    span_size_t _elem_size;

public:
    image_pixel_data(
      pixel_data_type pix_type,
      memory::const_block pix_data,
      span_size_t type_size) noexcept
      : _type(pix_type)
      , _pixels(pix_data)
      , _elem_size(type_size) {
        EAGINE_ASSERT(_elem_size > 0);
    }

    auto type() const noexcept -> pixel_data_type {
        return _type;
    }

    auto data() const noexcept -> memory::const_block {
        return _pixels;
    }

    auto elem_size() const noexcept -> span_size_t {
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
      , image_pixel_data(pix_data) {}
};

} // namespace eagine::oglp

#endif // OGLPLUS_UTILS_IMAGE_SPEC_HPP
