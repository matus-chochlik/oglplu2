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

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "glsl/source_ref.hpp"
#include "utils/gl_func.hpp"
#include "enum_types.hpp"

#ifndef GL_SHADER
#define GL_SHADER 0x82E1
#endif

namespace oglplus {
namespace tag {

using shader = gl_obj_tag<GL_SHADER>;

} // namespace tag
} // namespace oglplus

namespace eagine {

template <>
struct object_subtype<oglplus::tag::shader>
{
	typedef oglplus::shader_type type;
};

} // namespace eagine

namespace oglplus {

using shader_name = object_name<tag::shader>;

namespace ctxt {

struct shader_ops
{
	static
	outcome<void>
	shader_source(shader_name shdr, const glsl_source_ref& source)
	noexcept
	{
		OGLPLUS_GLFUNC(ShaderSource)(
			get_raw_name(shdr),
			source.count(),
			source.parts(),
			source.lengths()
		);
		OGLPLUS_VERIFY(ShaderSource, gl_object(shdr), always);
		return {};
	}

	static
	outcome<void>
	compile_shader(shader_name shdr)
	noexcept
	{
		OGLPLUS_GLFUNC(CompileShader)(get_raw_name(shdr));
		OGLPLUS_VERIFY(CompileShader, gl_object(shdr), always);
		return {};
	}
};

} // namespace ctxt

// obj_dsa_ops
template <>
struct obj_dsa_ops<shader_name>
 : obj_zero_dsa_ops<shader_name>
{
	typedef ctxt::shader_ops _ops;

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
};

// obj_gen_del_ops
template <>
struct obj_gen_del_ops<tag::shader>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names, shader_type type)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept;

	static
	outcome<bool> _is_a(GLuint name)
	noexcept;
};

using shader = object_owner<tag::shader>;

} // namespace oglplus

#include <oglplus/shader.inl>

#endif // include guard
