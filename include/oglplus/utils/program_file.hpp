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

class shader_source_view {
private:
    using _h = shader_source_header;

    eagine::extracted<const shader_source_header> _header;
    mutable const GLchar* _text = nullptr;
    const GLsizei _size = 0;

public:
    shader_source_view(
      eagine::extracted<const shader_source_header> hdr) noexcept
      : _header(hdr)
      , _text(accomodate<const GLchar>(_header[&_h::source_text].or_default())
                .data())
      , _size(eagine::limit_cast<GLsizei>(
          _header[&_h::source_text].or_default().size())) {
    }

    shader_source_view(eagine::memory::offset_ptr<const _h> ptr)
      : shader_source_view(extract(ptr)) {
    }

    shader_source_view(eagine::memory::const_block blk)
      : shader_source_view(extract(accomodate<const _h>(blk))) {
    }

    bool is_valid() const noexcept {
        return _header.is_valid() && _header->magic.is_valid();
    }

    auto shader_type() const noexcept {
        return oglplus::shader_type(_header[&_h::shader_type] / GL_NONE);
    }

    string_view source_text() const noexcept {
        return {
          _header->source_text.data(), span_size(_header->source_text.size())};
    }

    operator glsl_source_ref() const noexcept {
        return glsl_source_ref(1, &_text, &_size);
    }
}; // namespace oglplus

class shader_source_block : public shader_source_view {
private:
    eagine::memory::const_block _block;

    auto _header() const noexcept {
        return extract(accomodate<const shader_source_header>(_block));
    }

public:
    shader_source_block(const_memory_block blk)
      : shader_source_view(blk) {
    }
};

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

    shader_source_view shader_source(span_size_t index) const noexcept {
        assert(is_valid());
        assert(index < shader_source_count());
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

} // namespace oglplus

#endif // include guard
