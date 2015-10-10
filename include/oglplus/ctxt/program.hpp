/**
 *  @file oglplus/ctxt/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_PROGRAM_1509260923_HPP
#define OGLPLUS_CTXT_PROGRAM_1509260923_HPP

#include "../program.hpp"
#include "../shader.hpp"

namespace oglplus {
namespace ctxt {

struct program_ops
{
	static
	outcome<void>
	attach_shader(program_name prog, shader_name shdr)
	noexcept
	{
		OGLPLUS_GLFUNC(AttachShader)(
			get_raw_name(prog),
			get_raw_name(shdr)
		);
		OGLPLUS_VERIFY(
			AttachShader,
			gl_subject(prog).
			gl_object(shdr),
			debug
		);
		return {};
	}

	static
	outcome<void>
	detach_shader(program_name prog, shader_name shdr)
	noexcept
	{
		OGLPLUS_GLFUNC(DetachShader)(
			get_raw_name(prog),
			get_raw_name(shdr)
		);
		OGLPLUS_VERIFY(
			DetachShader,
			gl_subject(prog).
			gl_object(shdr),
			debug
		);
		return {};
	}

	static
	outcome<void>
	link(program_name prog)
	noexcept
	{
		OGLPLUS_GLFUNC(LinkProgram)(get_raw_name(prog));
		OGLPLUS_VERIFY(LinkProgram, gl_object(prog), always);
		return {};
	}

	static
	outcome<void>
	use(program_name prog)
	noexcept
	{
		OGLPLUS_GLFUNC(UseProgram)(get_raw_name(prog));
		OGLPLUS_VERIFY(UseProgram, gl_object(prog), always);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
