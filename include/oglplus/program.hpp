/**
 *  @file oglplus/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_1509260923_HPP
#define OGLPLUS_PROGRAM_1509260923_HPP

#include "shader.hpp"

#ifndef GL_PROGRAM
#define GL_PROGRAM 0x82E2
#endif

namespace oglplus {
namespace tag {

using program = gl_obj_tag<GL_PROGRAM>;

} // namespace tag

using program_name = object_name<tag::program>;

namespace oper {

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
	link_program(program_name prog)
	noexcept
	{
		OGLPLUS_GLFUNC(LinkProgram)(get_raw_name(prog));
		OGLPLUS_VERIFY(LinkProgram, gl_object(prog), always);
		return {};
	}

	static
	outcome<void>
	use_program(program_name prog)
	noexcept
	{
		OGLPLUS_GLFUNC(UseProgram)(get_raw_name(prog));
		OGLPLUS_VERIFY(UseProgram, gl_object(prog), always);
		return {};
	}

	static
	outcome<void>
	get_program_iv(
		program_name prog,
		program_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<true_false>
	get_program_delete_status(program_name prog)
	noexcept;

	static
	outcome<true_false>
	get_program_link_status(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_program_info_log_length(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_program_info_log(program_name prog, array_view<char> dest)
	noexcept;
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<program_name>
 : obj_zero_dsa_ops<program_name>
{
	typedef oper::program_ops _ops;

	outcome<obj_dsa_ops&>
	attach(shader_name shdr)
	noexcept
	{
		return {_ops::attach_shader(*this, shdr), *this};
	}

	outcome<obj_dsa_ops&>
	detach(shader_name shdr)
	noexcept
	{
		return {_ops::detach_shader(*this, shdr), *this};
	}

	outcome<obj_dsa_ops&>
	link(void)
	noexcept
	{
		return {_ops::link_program(*this), *this};
	}

	outcome<true_false>
	link_status(void) const
	noexcept
	{
		return _ops::get_program_link_status(*this);
	}

	outcome<true_false>
	delete_status(void) const
	noexcept
	{
		return _ops::get_program_delete_status(*this);
	}

	outcome<GLsizei>
	info_log_length(void) const
	noexcept
	{
		return _ops::get_program_info_log_length(*this);
	}

	outcome<GLsizei>
	info_log(array_view<char> dest) const
	noexcept
	{
		return _ops::get_program_info_log(*this, dest);
	}
};

// obj_gen_del_ops
template <>
struct obj_gen_del_ops<tag::program>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept;

	static
	outcome<bool> _is_a(GLuint name)
	noexcept;
};

using program = object_owner<tag::program>;

static const object_zero_and_ops<tag::program>
	no_program = {};

} // namespace oglplus

#include <oglplus/program.inl>

#endif // include guard
