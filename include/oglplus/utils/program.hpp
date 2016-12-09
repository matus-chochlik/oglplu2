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
shader build_shader(const shader_source_block& shdr_src)
{
	shader shdr(shdr_src.shader_type());
	shdr.source(shdr_src);
	shdr.compile();
	shdr.report_compile_error();
	return std::move(shdr);
}

static inline
void build_program(program& prog, const program_source_block& prog_src)
{
	for(span_size_t i=0, n=prog_src.shader_source_count(); i<n; ++i)
	{
		prog.attach(build_shader(prog_src.shader_source(i)));
	}
	prog.link();
	prog.report_link_error();
}

static inline
program build_program(const program_source_block& prog_src)
{
	program prog;
	build_program(prog, prog_src);
	return std::move(prog);
}

} // namespace oglplus

#endif // include guard
