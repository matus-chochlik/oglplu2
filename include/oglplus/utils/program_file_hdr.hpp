/**
 *  @file oglplus/utils/program_file_hdr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_FILE_HDR_HPP
#define OGLPLUS_UTILS_PROGRAM_FILE_HDR_HPP

#include <eagine/file_magic_number.hpp>
#include <eagine/memory/offset_span.hpp>
#include <array>

namespace oglplus {
//------------------------------------------------------------------------------
struct shader_source_header {
    eagine::file_magic_number<'o', 'g', 'l', '+', 's', 'h', 'd', 'r'> magic;
    eagine::memory::offset_span<const char> source_text = {};
    GLenum shader_type = GL_NONE;

    constexpr shader_source_header() noexcept = default;
};
//------------------------------------------------------------------------------
struct program_source_header {
    eagine::file_magic_number<'o', 'g', 'l', '+', 'p', 'r', 'o', 'g'> magic;
    eagine::memory::offset_span<
      const eagine::memory::offset_ptr<const shader_source_header>>
      shader_sources = {};

    constexpr program_source_header() noexcept = default;
};
//------------------------------------------------------------------------------
} // namespace oglplus

#endif // OGLPLUS_UTILS_PROGRAM_FILE_HDR_HPP
