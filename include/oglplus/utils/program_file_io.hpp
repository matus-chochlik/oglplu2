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
#include "span.hpp"
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
	while(spos % alignof(shader_source_header) != 0)
	{
		output.put('\0');
		++spos;
	}

	// if changing this also change shader_block
	// in write_and_pad_program_source_header
	const std::size_t size = 48;
	std::size_t done = 0;
	assert(size >= sizeof(shader_source_header));

	eagine::memory::const_address hdraddr(&header);

	header.source_text.reset(hdraddr+std::ptrdiff_t(size),source_text_size);

	output.write(static_cast<const char*>(hdraddr), sizeof(header));
	spos += sizeof(header);
	done += sizeof(header);

	while(done < size)
	{
		output.put('\0');
		++spos;
		++done;
	}
}

inline
void write_shader_source(
	std::ostream& output,
	shader_source_header& header,
	const_memory_block source_text,
	std::size_t& spos
)
{
	write_and_pad_shader_source_header(
		output,
		header,
		std::size_t(source_text.size()),
		spos
	);

	output.write(
		reinterpret_cast<const char*>(source_text.data()),
		std::streamsize(source_text.size())
	);
	output.put('\0');
	spos += std::size_t(source_text.size()+1);
}

inline
void write_shader_source(
	std::ostream& output,
	shader_source_header& header,
	const_memory_block source_text
)
{
	std::size_t spos = 0;

	if(output.tellp() >= 0)
	{
		spos = std::size_t(output.tellp());
	}

	write_shader_source(output, header, source_text, spos);
}

inline
void write_and_pad_program_source_header(
	std::ostream& output,
	program_source_header& header,
	const span<const std::size_t>& shader_source_lengths,
	std::size_t& spos
)
{
	while(spos % alignof(program_source_header) != 0)
	{
		output.put('\0');
		++spos;
	}

	const std::size_t size = 48;
	std::size_t done = 0;
	assert(size >= sizeof(shader_source_header));

	eagine::memory::const_address hdraddr(&header);

	header.shader_sources.reset(
		hdraddr+std::ptrdiff_t(size),
		std::size_t(shader_source_lengths.size()) // shader count
	);

	output.write(static_cast<const char*>(hdraddr), sizeof(header));
	spos += sizeof(header);
	done += sizeof(header);

	while(done < size)
	{
		output.put('\0');
		++spos;
		++done;
	}

	std::size_t algn = alignof(shader_source_header);
	std::ptrdiff_t offs =
		std::ptrdiff_t(shader_source_lengths.size())*
		std::ptrdiff_t(sizeof(std::ptrdiff_t));

	if(offs % 16 != 0)
	{
		offs += 16 - (offs % 16);
	}

	for(std::size_t len : shader_source_lengths)
	{
		output.write(
			reinterpret_cast<const char*>(&offs),
			std::streamsize(sizeof(offs))
		);
		spos += sizeof(offs);
		done += sizeof(offs);

		// if changing this also change size
		// in write_and_pad_shader_source_header
		std::size_t shader_block_size = 48;
		shader_block_size += len;

		if(std::size_t misalign = shader_block_size % algn)
		{
			shader_block_size += (algn - misalign);
		}

		offs += std::ptrdiff_t(shader_block_size);
		offs -= std::ptrdiff_t(sizeof(std::ptrdiff_t));
	}

	while(spos % 16 != 0)
	{
		output.put('\0');
		++spos;
	}
}

} // namespace oglplus

#endif // include guard
