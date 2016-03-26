/**
 *  @file oglplus/utils/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_PROGRAM_1509260923_HPP
#define OGLPLUS_UTILS_PROGRAM_1509260923_HPP

#include "program_file.hpp"
#include "../program.hpp"
#include "../shader.hpp"

namespace oglplus {

static inline
void build_program(program& prog, const program_source_file& prog_src)
{
	for(std::size_t i=0, n=prog_src.shader_source_count(); i<n; ++i)
	{
		shader shdr(prog_src.shader_type(i));
		shdr.source(prog_src.shader_source(i));
		shdr.compile();
		shdr.report_compile_error();
		prog.attach(shdr);
	}
	prog.link();
	prog.report_link_error();
}

} // namespace oglplus

#endif // include guard
