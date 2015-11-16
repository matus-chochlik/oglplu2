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

#include "program_name.hpp"
#include "shader_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "glsl/source_ref.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"
#include "enum/types.hpp"

namespace oglplus {
namespace oper {

struct program_ops
{
	static
	outcome<void>
	attach_shader(program_name prog, shader_name shdr)
	noexcept;

	static
	outcome<void>
	detach_shader(program_name prog, shader_name shdr)
	noexcept;

	static
	outcome<void>
	link_program(program_name prog)
	noexcept;

	static
	outcome<void>
	use_program(program_name prog)
	noexcept;

	static
	outcome<program_name>
	current_program(void)
	noexcept;

	static
	outcome<void>
	get_program_iv(
		program_name prog,
		program_parameter param,
		array_view<GLint> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_program_parameter_i(program_name, program_parameter parameter)
	noexcept;

	static
	outcome<boolean>
	program_delete_status(program_name prog)
	noexcept;

	static
	outcome<boolean>
	program_link_status(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	program_info_log_length(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	program_info_log(program_name prog, array_view<char> dest)
	noexcept;
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<tag::program>
 : obj_zero_dsa_ops<tag::program>
{
	typedef oper::program_ops _ops;

	using obj_zero_dsa_ops<tag::program>::obj_zero_dsa_ops;

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

	outcome<boolean>
	link_status(void) const
	noexcept
	{
		return _ops::program_link_status(*this);
	}

	outcome<boolean>
	delete_status(void) const
	noexcept
	{
		return _ops::program_delete_status(*this);
	}

	outcome<GLsizei>
	info_log_length(void) const
	noexcept
	{
		return _ops::program_info_log_length(*this);
	}

	outcome<GLsizei>
	info_log(array_view<char> dest) const
	noexcept
	{
		return _ops::program_info_log(*this, dest);
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
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using program = object_owner<tag::program>;
template <std::size_t N>
using program_array = object_array_owner<tag::program, N>;

static const object_zero_and_ops<tag::program>
	no_program = {};

} // namespace oglplus

#include <oglplus/program.inl>

#endif // include guard
