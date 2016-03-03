/**
 *  @file oglplus/utils/program_file_hdr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_FILE_HDR_1509260923_HPP
#define OGLPLUS_UTILS_PROGRAM_FILE_HDR_1509260923_HPP

#include <eagine/offset_ptr.hpp>
#include "valid_if.hpp"
#include <array>

namespace oglplus {

struct shader_source_header
{
	static constexpr
	std::array<char,16> get_magic(void)
	noexcept
	{
		return {{
			 'o', 'g', 'l', '+', 's', 'h', 'd','r',
			'\0','\0','\0','\0','\0','\0','\0','\0'
		}};
	}

	std::array<char,16> magic;
	eagine::offset_array<const char> source_text;
	GLenum shader_type;

	constexpr
	shader_source_header(void)
	noexcept
	 : magic(get_magic())
	 , shader_type(GL_NONE)
	{ }
};

struct program_source_header
{
	static constexpr
	std::array<char,16> get_magic(void)
	noexcept
	{
		return {{
			 'o', 'g', 'l', '+', 'p', 'r', 'o','g',
			'\0','\0','\0','\0','\0','\0','\0','\0'
		}};
	}

	std::array<char,16> magic;
	eagine::offset_array<
		const eagine::offset_ptr<
			const shader_source_header
		>
	> shader_sources;

	constexpr
	program_source_header(void)
	noexcept
	 : magic(get_magic())
	{ }
};

} // namespace oglplus

#endif // include guard
