/**
 *  @file eagine/input_data.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/scope_exit.hpp>
#include <eagine/memory/copy.hpp>
#include <fstream>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
static inline
void do_read_stream_data(std::istream& input, memory::buffer& dest)
{
	try
	{
		input.seekg(0, std::ios::end);
		dest.resize(memory::buffer::size_type(input.tellg()));
		input.seekg(0, std::ios::beg);
		input.read(
			static_cast<char*>(dest.data()),
			static_cast<std::streamsize>(dest.size())
		);
	}
	catch(std::ios_base::failure&)
	{
		std::vector<char> temp;
		temp.insert(
			temp.begin(),
			std::istreambuf_iterator<char>(input),
			std::istreambuf_iterator<char>()
		);
		dest.resize(memory::buffer::size_type(temp.size()));
		memory::copy(memory::data_block_of(temp), dest);
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void read_stream_data(std::istream& input, memory::buffer& dest)
{
	std::ios_base::iostate oldexc = input.exceptions();
	auto reset_exc = finally([&input, oldexc]{input.exceptions(oldexc);});
	input.exceptions(std::ios::failbit | std::ios::badbit);

	do_read_stream_data(input, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void read_file_data(const cstr_ref& path, memory::buffer& dest)
{
	std::ifstream file;
	std::ios_base::iostate oldexc = file.exceptions();
	auto reset_exc = finally([&file, oldexc]{file.exceptions(oldexc);});
	file.exceptions(std::ios::failbit | std::ios::badbit);
	file.open(path.c_str(), std::ios::in | std::ios::binary);

	do_read_stream_data(file, dest);
}
//------------------------------------------------------------------------------
} // namespace eagine
