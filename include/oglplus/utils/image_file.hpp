/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef OGLPLUS_UTILS_IMAGE_FILE_HPP
#define OGLPLUS_UTILS_IMAGE_FILE_HPP

#include "image_file_hdr.hpp"
#include "image_spec.hpp"
#include <eagine/file_contents.hpp>
#include <eagine/string_span.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
class texture_image_block {
private:
    structured_memory_block<const image_data_header> _header;

public:
    texture_image_block(memory::const_block blk)
      : _header(blk) {}

    texture_image_block(const image_data_header* ptr)
      : _header(as_bytes(view_one(ptr))) {}

    auto is_valid() const noexcept -> bool {
        return _header->magic.is_valid();
    }

    auto dimensions() const noexcept -> image_dimensions {
        return image_dimensions(
          _header->width, _header->height, _header->depth, _header->channels);
    }

    auto format() const noexcept -> image_pixel_format {
        return image_pixel_format(
          pixel_format(_header->format),
          pixel_internal_format(_header->internal_format));
    }

    auto format(pixel_internal_format ifmt) const noexcept
      -> image_pixel_format {
        return image_pixel_format(pixel_format(_header->format), ifmt);
    }

    auto pixel_data() const noexcept -> image_pixel_data {
        return image_pixel_data(
          pixel_data_type(_header->data_type),
          as_bytes(_header->pixels),
          sizeof(GLubyte));
    }

    auto spec() const noexcept -> image_spec {
        return {dimensions(), format(), pixel_data()};
    }

    auto spec(pixel_internal_format ifmt) const noexcept {
        return image_spec(dimensions(), format(ifmt), pixel_data());
    }

    inline operator image_spec() const noexcept {
        return spec();
    }
};
//------------------------------------------------------------------------------
class texture_image_file
  : protected_member<file_contents>
  , public texture_image_block {
public:
    texture_image_file(file_contents&& fc)
      : protected_member<file_contents>(std::move(fc))
      , texture_image_block(get_the_member()) {}

    texture_image_file(string_view path)
      : texture_image_file(file_contents(path)) {}

    texture_image_file(const std::string& path)
      : texture_image_file(string_view(path)) {}
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_UTILS_IMAGE_FILE_HPP
