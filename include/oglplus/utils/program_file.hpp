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
#include "cstr_ref.hpp"
#include <eagine/file_contents.hpp>

namespace oglplus {

class program_source_file
{
private:
	eagine::structured_file_content<program_source_header> _header;
public:
	program_source_file(const cstr_ref& path)
	 : _header(path)
	{ }

	program_source_file(eagine::file_contents&& fc)
	 : _header(std::move(fc))
	{ }
};

} // namespace oglplus

#endif // include guard
