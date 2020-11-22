/**
 *  @file oglplus/utils/image_file_hdr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_FILE_HDR_HPP
#define OGLPLUS_UTILS_IMAGE_FILE_HDR_HPP

#include "../gl_api/enum_types.hpp"
#include <eagine/file_magic_number.hpp>
#include <eagine/memory/offset_span.hpp>
#include <eagine/valid_if/positive.hpp>
#include <array>

namespace eagine::oglp {

struct image_data_header {
    file_magic_number<'o', 'g', 'l', '+', 't', 'e', 'x', 'i'> magic;
    gl_types::sizei_type width{0}, height{0}, depth{0}, channels{0};
    gl_types::enum_type format{0}, internal_format{0};
    gl_types::enum_type data_type{0};

    memory::offset_span<const gl_types::ubyte_type> pixels{};

    constexpr image_data_header() noexcept = default;

    image_data_header(
      valid_if_positive<gl_types::sizei_type> w,
      valid_if_positive<gl_types::sizei_type> h,
      valid_if_positive<gl_types::sizei_type> d,
      valid_if_positive<gl_types::sizei_type> c) noexcept
      : width(w.value())
      , height(h.value())
      , depth(d.value())
      , channels(c.value()) {}
};

} // namespace eagine::oglp

#endif // OGLPLUS_UTILS_IMAGE_FILE_HDR_HPP
