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

#include "program_file_hdr.hpp"
#include "string_span.hpp"
#include "cstr_ref.hpp"
#include "../glsl/source_ref.hpp"
#include "../enum/types.hpp"
#include <eagine/file_contents.hpp>

namespace oglplus {

class shader_source_block
{
private:
	eagine::structured_memory_block<const shader_source_header> _header;
	mutable const GLchar* _text;
	const GLsizei _size;
public:
	shader_source_block(eagine::const_memory_block blk)
	 : _header(blk)
	 , _text(reinterpret_cast<const GLchar*>(_header->source_text.data()))
	 , _size(GLsizei(_header->source_text.size()))
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _header->magic.is_valid();
	}

	auto shader_type(void) const
	noexcept
	{
		return oglplus::shader_type(_header->shader_type);
	}

	cstr_ref source_text(void) const
	noexcept
	{
		return {
			_header->source_text.data(),
			_header->source_text.size()
		};
	}

	operator glsl_source_ref (void) const
	noexcept
	{
		return glsl_source_ref(1, &_text, &_size);
	}
};

class shader_source_file
 : eagine::protected_member<eagine::file_contents>
 , public shader_source_block
{
public:
	shader_source_file(eagine::file_contents&& fc)
	 : eagine::protected_member<eagine::file_contents>(std::move(fc))
	 , shader_source_block(get_the_member())
	{ }

	shader_source_file(const cstr_ref& path)
	 : shader_source_file(eagine::file_contents(path))
	{ }
};

class program_source_file
{
private:
	eagine::structured_file_content<const program_source_header> _header;
	eagine::offset_ptr_array_facade<const shader_source_header> _sources;
public:
	program_source_file(eagine::file_contents&& fc)
	 : _header(std::move(fc))
	 , _sources(_header->shader_sources)
	{ }

	program_source_file(const cstr_ref& path)
	 : _header(path)
	 , _sources(_header->shader_sources)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _header->magic.is_valid();
	}

	std::size_t shader_source_count(void) const
	noexcept
	{
		assert(is_valid());
		return _sources.size();
	}

	shader_source_block
	shader_source(std::size_t index) const
	noexcept
	{
		assert(is_valid());
		assert(index < shader_source_count());
		return eagine::memory::block_of(_sources[index]);
	}

	oglplus::shader_type
	shader_type(std::size_t index) const
	noexcept
	{
		assert(is_valid());
		assert(index < shader_source_count());
		return oglplus::shader_type(_sources[index].shader_type);
	}

	cstr_ref
	shader_source_text(std::size_t index) const
	noexcept
	{
		assert(is_valid());
		assert(index < shader_source_count());
		return {
			_sources[index].source_text.data(),
			_sources[index].source_text.size()
		};
	}
};

} // namespace oglplus

#endif // include guard
