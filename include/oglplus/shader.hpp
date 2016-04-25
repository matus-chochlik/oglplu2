/**
 *  @file oglplus/shader.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SHADER_1509260923_HPP
#define OGLPLUS_SHADER_1509260923_HPP

#include "shader_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "glsl/source_ref.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"
#include "enum/types.hpp"

namespace eagine {

template <>
struct object_subtype<oglplus::tag::shader>
{
	typedef oglplus::shader_type type;
};

} // namespace eagine

namespace oglplus {

using shader_name = object_name<tag::shader>;

namespace oper {

struct shader_ops
{
	static
	outcome<void>
	shader_source(shader_name shdr, const glsl_source_ref& source)
	noexcept;

	static
	outcome<void>
	compile_shader(shader_name shdr)
	noexcept;

	static
	outcome<void>
	report_shader_compile_error(shader_name shdr)
	noexcept;

	static
	outcome<void>
	get_shader_iv(
		shader_name shdr,
		shader_parameter param,
		span<GLint> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_shader_i(shader_name shdr, shader_parameter parameter)
	noexcept;

	static
	outcome<shader_type>
	shader_type(shader_name shdr)
	noexcept;

	static
	outcome<boolean>
	shader_delete_status(shader_name shdr)
	noexcept;

	static
	outcome<boolean>
	shader_compile_status(shader_name shdr)
	noexcept;

	static
	outcome<GLsizei>
	shader_info_log_length(shader_name shdr)
	noexcept;

	static
	outcome<GLsizei>
	shader_info_log(shader_name shdr, span<char> dest)
	noexcept;
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<tag::shader>
 : obj_zero_dsa_ops<tag::shader>
{
	typedef oper::shader_ops _ops;

	using obj_zero_dsa_ops<tag::shader>::obj_zero_dsa_ops;

	outcome<shader_type>
	type(void) const
	noexcept
	{
		return _ops::shader_type(*this);
	}

	outcome<obj_dsa_ops&>
	source(const glsl_source_ref& source)
	noexcept
	{
		return {_ops::shader_source(*this, source), *this};
	}

	outcome<obj_dsa_ops&>
	compile(void)
	noexcept
	{
		return {_ops::compile_shader(*this), *this};
	}

	outcome<obj_dsa_ops&>
	report_compile_error(void)
	noexcept
	{
		return {_ops::report_shader_compile_error(*this), *this};
	}

	outcome<boolean>
	compile_status(void) const
	noexcept
	{
		return _ops::shader_compile_status(*this);
	}

	outcome<boolean>
	delete_status(void) const
	noexcept
	{
		return _ops::shader_delete_status(*this);
	}

	outcome<GLsizei>
	info_log_length(void) const
	noexcept
	{
		return _ops::shader_info_log_length(*this);
	}

	outcome<GLsizei>
	info_log(span<char> dest) const
	noexcept
	{
		return _ops::shader_info_log(*this, dest);
	}
};

// obj_gen_del_ops
template <>
struct obj_gen_del_ops<tag::shader>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names, shader_type type)
	noexcept;

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using shader = object_owner<tag::shader>;
template <std::size_t N>
using shader_array = object_array_owner<tag::shader, N>;

} // namespace oglplus

#include <oglplus/shader.inl>

#endif // include guard
