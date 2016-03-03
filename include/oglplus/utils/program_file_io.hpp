/**
 *  @file oglplus/utils/program_file_io.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_FILE_IO_1509260923_HPP
#define OGLPLUS_UTILS_PROGRAM_FILE_IO_1509260923_HPP

#include "program_file_hdr.hpp"
#include "memory_block.hpp"
#include "string_span.hpp"
#include <iostream>

namespace oglplus {

inline
void write_and_pad_shader_source_header(
	std::ostream& output,
	shader_source_header& header,
	std::size_t source_text_size,
	std::size_t& spos
)
{
	std::size_t algn(alignof(shader_source_header));

	while(spos % algn != 0)
	{
		output.put('\0');
		++spos;
	}

	algn = 64;
	assert(sizeof(shader_source_header) <= std::size_t(algn));

	eagine::memory::const_address hdraddr(&header);

	header.source_text = eagine::offset_array<const char>(
		static_cast<const char*>(hdraddr+std::ptrdiff_t(algn)),
		source_text_size
	);

	output.write(static_cast<const char*>(hdraddr), sizeof(header));
	spos += sizeof(header);

	while(spos % algn != 0)
	{
		output.put('\0');
		++spos;
	}
}

inline
void write_and_pad_shader_source_header(
	std::ostream& output,
	shader_source_header& header,
	std::size_t source_text_size
)
{
	std::size_t spos = 0;

	if(output.tellp() >= 0)
	{
		spos = std::size_t(output.tellp());
	}

	write_and_pad_shader_source_header(
		output,
		header,
		source_text_size,
		spos
	);
}

inline
void write_shader_source(
	std::ostream& output,
	shader_source_header& header,
	const cstring_span<>& source_text
)
{
	write_and_pad_shader_source_header(
		output,
		header,
		std::size_t(source_text.size())
	);

	output.write(source_text.data(), std::streamsize(source_text.size()));
}

} // namespace oglplus

#endif // include guard
