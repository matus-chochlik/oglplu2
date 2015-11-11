/**
 *  @file oglplus/renderbuffer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/renderbuffer_target_bq.inl"
#endif

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
renderbuffer_ops::
bind_renderbuffer(renderbuffer_target target, renderbuffer_name rbo)
noexcept
{
	OGLPLUS_GLFUNC(BindRenderbuffer)(
		GLenum(target),
		get_raw_name(rbo)
	);
	OGLPLUS_VERIFY(
		BindRenderbuffer,
		gl_enum_value(target).
		gl_object(rbo),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<renderbuffer_name>
renderbuffer_ops::
renderbuffer_binding(renderbuffer_target target)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), renderbuffer_name(GLuint(result));
}
//------------------------------------------------------------------------------
inline
outcome<void>
renderbuffer_ops::
renderbuffer_storage(
	renderbuffer_target target,
	pixel_data_internal_format ifmt,
	GLsizei width,
	GLsizei height
) noexcept
{
	OGLPLUS_GLFUNC(RenderbufferStorage)(
		GLenum(target),
		GLenum(ifmt),
		width, height
	);
	OGLPLUS_VERIFY(
		RenderbufferStorage,
		//gl_object(renderbuffer_binding(target)). TODO
		gl_enum_value(ifmt),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
renderbuffer_ops::
renderbuffer_storage(
	renderbuffer_name rbo,
	pixel_data_internal_format ifmt,
	GLsizei width,
	GLsizei height
) noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedRenderbufferStorage)(
#else
	OGLPLUS_GLFUNC(NamedRenderbufferStorageEXT)(
#endif
		get_raw_name(rbo),
		GLenum(ifmt),
		width, height
	);
	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedRenderbufferStorage),
		gl_object(rbo).
		gl_enum_value(ifmt),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
renderbuffer_ops::
renderbuffer_storage_multisample(
	renderbuffer_target target,
	GLsizei samples,
	pixel_data_internal_format ifmt,
	GLsizei width,
	GLsizei height
) noexcept
{
	OGLPLUS_GLFUNC(RenderbufferStorageMultisample)(
		GLenum(target),
		samples,
		GLenum(ifmt),
		width, height
	);
	OGLPLUS_VERIFY(
		RenderbufferStorage,
		//gl_object(renderbuffer_binding(target)). TODO
		gl_enum_value(ifmt),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
renderbuffer_ops::
renderbuffer_storage_multisample(
	renderbuffer_name rbo,
	GLsizei samples,
	pixel_data_internal_format ifmt,
	GLsizei width,
	GLsizei height
) noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedRenderbufferStorageMultisample)(
#else
	OGLPLUS_GLFUNC(NamedRenderbufferStorageMultisampleEXT)(
#endif
		get_raw_name(rbo),
		samples,
		GLenum(ifmt),
		width, height
	);
	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedRenderbufferStorageMultisample),
		gl_object(rbo).
		gl_enum_value(ifmt),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
renderbuffer_ops::
get_renderbuffer_parameter_iv(
	renderbuffer_target target,
	oglplus::renderbuffer_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetRenderbufferParameteriv)(
		GLenum(target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetRenderbufferParameteriv,
		//gl_object(texture_binding(target)). TODO
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
renderbuffer_ops::
get_renderbuffer_parameter_iv(
	renderbuffer_name buf,
	oglplus::renderbuffer_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(GetNamedRenderbufferParameteriv)(
#else
	OGLPLUS_GLFUNC(GetNamedRenderbufferParameterivEXT)(
#endif
		get_raw_name(buf),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(GetNamedRenderbufferParameteriv),
		gl_object(buf).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
template <typename R, typename T, typename RNT>
inline
outcome<R>
renderbuffer_ops::
return_renderbuffer_parameter_i(
	const RNT& rnt,
	oglplus::renderbuffer_parameter parameter
) noexcept
{
	GLint result;
	return get_renderbuffer_parameter_iv(
		rnt,
		parameter,
		{&result, 1}
	), R(T(result));
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_width(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_WIDTH)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_height(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_HEIGHT)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_red_size(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_RED_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_green_size(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_GREEN_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_blue_size(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_BLUE_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_alpha_size(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_ALPHA_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_depth_size(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_DEPTH_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_stencil_size(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_STENCIL_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<GLsizei>
renderbuffer_ops::
renderbuffer_samples(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_SAMPLES)
	);
}
//------------------------------------------------------------------------------
template <typename RNT>
inline
outcome<pixel_data_internal_format>
renderbuffer_ops::
renderbuffer_internal_format(const RNT& rnt)
noexcept
{
	return return_renderbuffer_parameter_i<
		pixel_data_internal_format,
		GLenum
	>(
		rnt, 
		renderbuffer_parameter(GL_RENDERBUFFER_INTERNAL_FORMAT)
	);
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::renderbuffer>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenRenderbuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenRenderbuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::renderbuffer>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteRenderbuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteRenderbuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::renderbuffer>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsRenderbuffer)(name);
	OGLPLUS_VERIFY_SIMPLE(IsRenderbuffer,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
