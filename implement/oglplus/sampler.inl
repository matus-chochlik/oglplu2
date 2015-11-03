/**
 *  @file oglplus/sampler.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<sampler_name>
sampler_ops::
sampler_binding(texture_unit unit)
noexcept
{
	OGLPLUS_GLFUNC(ActiveTexture)(GLenum(unit));
	OGLPLUS_VERIFY(
		ActiveTexture,
		gl_enum_value(unit),
		always
	);
	GLint result;
	return numeric_queries::get_integer_v(
		binding_query(GL_SAMPLER_BINDING),
		{&result, 1}
	), sampler_name(GLuint(result));
}
//------------------------------------------------------------------------------
inline
outcome<void>
sampler_ops::
sampler_parameter_i(
	sampler_name sam,
	oglplus::sampler_parameter param,
	GLint value
) noexcept
{
	OGLPLUS_GLFUNC(SamplerParameteri)(
		get_raw_name(sam),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		SamplerParameteri,
		gl_object(sam).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
sampler_ops::
get_sampler_parameter_iv(
	sampler_name sam,
	oglplus::sampler_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetSamplerParameteriv)(
		get_raw_name(sam),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetSamplerParameteriv,
		gl_object(sam).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
sampler_ops::
sampler_parameter_f(
	sampler_name sam,
	oglplus::sampler_parameter param,
	GLfloat value
) noexcept
{
	OGLPLUS_GLFUNC(SamplerParameterf)(
		get_raw_name(sam),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		SamplerParameterf,
		gl_object(sam).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
sampler_ops::
get_sampler_parameter_fv(
	sampler_name sam,
	oglplus::sampler_parameter param,
	array_view<GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetSamplerParameterfv)(
		get_raw_name(sam),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetSamplerParameterfv,
		gl_object(sam).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::sampler>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenSamplers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenSamplers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::sampler>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteSamplers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteSamplers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::sampler>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsSampler)(name);
	OGLPLUS_VERIFY_SIMPLE(IsSampler,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
