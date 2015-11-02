/**
 *  @file oglplus/framebuffer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/framebuffer_target_bq.inl"
#endif

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<framebuffer_name>
framebuffer_ops::
framebuffer_binding(framebuffer_target target)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), framebuffer_name(GLuint(result));
}
//------------------------------------------------------------------------------
inline
outcome<framebuffer_status>
framebuffer_ops::
check_framebuffer_status(framebuffer_target target)
noexcept
{
	GLenum result = OGLPLUS_GLFUNC(CheckFramebufferStatus)(GLenum(target));
	if(result == 0)
	{
		OGLPLUS_VERIFY(
			CheckFramebufferStatus,
			gl_enum_value(target),
			debug
		);
	}
	return {framebuffer_status(result)};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<framebuffer_status>
framebuffer_ops::
check_framebuffer_status(framebuffer_name fbo, framebuffer_target target)
noexcept
{
#ifdef GL_VERSION_4_5
	GLenum result = OGLPLUS_GLFUNC(CheckNamedFramebufferStatus)(
#else
	GLenum result = OGLPLUS_GLFUNC(CheckNamedFramebufferStatusEXT)(
#endif
		get_raw_name(fbo),
		GLenum(target)
	);
	if(result == 0)
	{
		OGLPLUS_VERIFY(
			OGLPLUS_GL_DSA_FUNC_NAME(CheckNamedFramebufferStatus),
			gl_object(fbo).
			gl_enum_value(target),
			debug
		);
	}
	return {framebuffer_status(result)};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
framebuffer_ops::
draw_buffer(color_buffer buf)
noexcept
{
	OGLPLUS_GLFUNC(DrawBuffer)(GLenum(buf));
	OGLPLUS_VERIFY(
		DrawBuffer,
		gl_enum_value(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
framebuffer_ops::
framebuffer_draw_buffer(framebuffer_name fbo, color_buffer buf)
noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedFramebufferDrawBuffer)(
#else
	OGLPLUS_GLFUNC(FramebufferDrawBufferEXT)(
#endif
		get_raw_name(fbo),
		GLenum(buf)
	);
	OGLPLUS_VERIFY(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedFramebufferDrawBuffer),
		gl_object(fbo).
		gl_enum_value(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
framebuffer_ops::
read_buffer(color_buffer buf)
noexcept
{
	OGLPLUS_GLFUNC(ReadBuffer)(GLenum(buf));
	OGLPLUS_VERIFY(
		ReadBuffer,
		gl_enum_value(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
framebuffer_ops::
framebuffer_read_buffer(framebuffer_name fbo, color_buffer buf)
noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedFramebufferReadBuffer)(
#else
	OGLPLUS_GLFUNC(FramebufferReadBufferEXT)(
#endif
		get_raw_name(fbo),
		GLenum(buf)
	);
	OGLPLUS_VERIFY(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedFramebufferReadBuffer),
		gl_object(fbo).
		gl_enum_value(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::framebuffer>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenFramebuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenFramebuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::framebuffer>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteFramebuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteFramebuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::framebuffer>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsFramebuffer)(name);
	OGLPLUS_VERIFY_SIMPLE(IsFramebuffer,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
