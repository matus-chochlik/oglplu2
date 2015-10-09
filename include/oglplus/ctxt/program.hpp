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

namespace oglplus {
namespace ctxt {

struct program_ops
{
	static
	outcome<void>
	attach_shader(program_name program, shader_name shader)
	noexcept
	{
		OGLPLUS_GLFUNC(AttachShader)(
			get_raw_name(program),
			get_raw_name(shader)
		);
		OGLPLUS_VERIFY(
			AttachShader,
			gl_subject(program).
			gl_object(shader),
			warning
		);
		return {};
	}

	static
	outcome<void>
	detach_shader(program_name program, shader_name shader)
	noexcept
	{
		OGLPLUS_GLFUNC(DetachShader)(
			get_raw_name(program),
			get_raw_name(shader)
		);
		OGLPLUS_VERIFY(
			DetachShader,
			gl_subject(program).
			gl_object(shader),
			warning
		);
		return {};
	}

	static
	outcome<void>
	link(program_name program)
	noexcept
	{
		OGLPLUS_GLFUNC(LinkProgram)(get_raw_name(program));
		OGLPLUS_VERIFY(LinkProgram, gl_object(program), warning);
		return {};
	}

	static
	outcome<void>
	use(program_name program)
	noexcept
	{
		OGLPLUS_GLFUNC(UseProgram)(get_raw_name(program));
		OGLPLUS_VERIFY(UseProgram, gl_object(program), warning);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
