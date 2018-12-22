/**
 *  @file oglplus/utils/program_file.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_FILE_1509260923_HPP
#define OGLPLUS_UTILS_PROGRAM_FILE_1509260923_HPP

#include "../enum/types.hpp"
#include "../glsl/source_ref.hpp"
#include "memory_block.hpp"
#include "program_file_hdr.hpp"
#include "span.hpp"
#include "string_span.hpp"
#include <eagine/file_contents.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
class shader_source_block {
private:
    eagine::structured_memory_block<const shader_source_header> _header;

public:
    shader_source_block(const_memory_block blk)
      : _header(blk) {
    }

    shader_source_block(const shader_source_header* ptr)
      : _header(as_bytes(eagine::view_one(ptr))) {
    }

    bool is_valid() const noexcept {
        return _header->magic.is_valid();
    }

    auto shader_type() const noexcept {
        assert(is_valid());
        return oglplus::shader_type(_header->shader_type);
    }

    string_view source_text() const noexcept {
        assert(is_valid());
        return {
          _header->source_text.data(), span_size(_header->source_text.size())};
    }

    operator glsl_source_ref() const noexcept {
        assert(is_valid());
        return glsl_source_ref(_header->source_text);
    }
};
//------------------------------------------------------------------------------
class shader_source_file
  : eagine::protected_member<eagine::file_contents>
  , public shader_source_block {
public:
    shader_source_file(eagine::file_contents&& fc)
      : eagine::protected_member<eagine::file_contents>(std::move(fc))
      , shader_source_block(get_the_member()) {
    }

    shader_source_file(string_view path)
      : shader_source_file(eagine::file_contents(path)) {
    }

    shader_source_file(const std::string& path)
      : shader_source_file(string_view(path)) {
    }
};
//------------------------------------------------------------------------------
class program_source_block {
private:
    eagine::structured_memory_block<const program_source_header> _header;

public:
    program_source_block(const_memory_block blk)
      : _header(blk) {
    }

    bool is_valid() const noexcept {
        return _header->magic.is_valid();
    }

    span_size_t shader_source_count() const noexcept {
        assert(is_valid());
        return _header->shader_sources.size();
    }

    shader_source_block shader_source(span_size_t index) const noexcept {
        assert(is_valid());
        assert(index < _header->shader_sources.size());
        return {_header->shader_sources[index]};
    }

    oglplus::shader_type shader_type(span_size_t index) const noexcept {
        assert(is_valid());
        assert(index < shader_source_count());
        return oglplus::shader_type(
          _header->shader_sources[index]->shader_type);
    }

    string_view shader_source_text(span_size_t index) const noexcept {
        assert(is_valid());
        assert(index < shader_source_count());
        return {_header->shader_sources[index]->source_text};
    }
};
//------------------------------------------------------------------------------
class program_source_file
  : eagine::protected_member<eagine::file_contents>
  , public program_source_block {
public:
    program_source_file(eagine::file_contents&& fc)
      : eagine::protected_member<eagine::file_contents>(std::move(fc))
      , program_source_block(get_the_member()) {
    }

    program_source_file(string_view path)
      : program_source_file(eagine::file_contents(path)) {
    }

    program_source_file(const std::string& path)
      : program_source_file(string_view(path)) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglplus

#endif // include guard
