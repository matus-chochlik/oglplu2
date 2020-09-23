/**
 *  @file oglplus/utils/program_file.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_FILE_HPP
#define OGLPLUS_UTILS_PROGRAM_FILE_HPP

#include "../gl_api/enum_types.hpp"
#include "../glsl/source_ref.hpp"
#include "program_file_hdr.hpp"
#include <eagine/assert.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/memory/block.hpp>
#include <eagine/string_span.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
class shader_source_block {
private:
    structured_memory_block<const shader_source_header> _header;

public:
    shader_source_block(memory::const_block blk)
      : _header(blk) {}

    shader_source_block(const shader_source_header* ptr)
      : _header(as_bytes(view_one(ptr))) {}

    auto is_valid() const noexcept -> bool {
        return _header->magic.is_valid();
    }

    auto type() const noexcept -> shader_type {
        EAGINE_ASSERT(is_valid());
        return shader_type(_header->shader_type);
    }

    auto source_text() const noexcept -> string_view {
        EAGINE_ASSERT(is_valid());
        return {
          _header->source_text.data(), span_size(_header->source_text.size())};
    }

    operator glsl_source_ref() const noexcept {
        EAGINE_ASSERT(is_valid());
        return glsl_source_ref(_header->source_text);
    }
};
//------------------------------------------------------------------------------
class shader_source_file
  : protected_member<file_contents>
  , public shader_source_block {
public:
    shader_source_file(file_contents&& fc)
      : protected_member<file_contents>(std::move(fc))
      , shader_source_block(get_the_member()) {}

    shader_source_file(string_view path)
      : shader_source_file(file_contents(path)) {}

    shader_source_file(const std::string& path)
      : shader_source_file(string_view(path)) {}
};
//------------------------------------------------------------------------------
class program_source_block {
private:
    structured_memory_block<const program_source_header> _header;

public:
    program_source_block(memory::const_block blk)
      : _header(blk) {}

    auto is_valid() const noexcept -> bool {
        return _header->magic.is_valid();
    }

    auto shader_source_count() const noexcept -> span_size_t {
        EAGINE_ASSERT(is_valid());
        return _header->shader_sources.size();
    }

    auto shader_source(span_size_t index) const noexcept
      -> shader_source_block {
        EAGINE_ASSERT(is_valid());
        EAGINE_ASSERT(index < _header->shader_sources.size());
        return {_header->shader_sources[index]};
    }
};
//------------------------------------------------------------------------------
class program_source_file
  : protected_member<file_contents>
  , public program_source_block {
public:
    program_source_file(file_contents&& fc)
      : protected_member<file_contents>(std::move(fc))
      , program_source_block(get_the_member()) {}

    program_source_file(string_view path)
      : program_source_file(file_contents(path)) {}

    program_source_file(const std::string& path)
      : program_source_file(string_view(path)) {}
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_UTILS_PROGRAM_FILE_HPP
