/**
 *  @file oglplus/gl.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#if OGLPLUS_USE_GLEW || OGLPLUS_USE_GL3W
#include <stdexcept>
#endif

namespace oglplus {
//------------------------------------------------------------------------------
#ifndef OGLPLUS_NO_GL
//------------------------------------------------------------------------------
#if OGLPLUS_USE_GLCOREARB_H || OGLPLUS_USE_GL3_GL3_H || OGLPLUS_USE_GLES3_GL3_H
OGLPLUS_LIB_FUNC
api_initializer::
api_initializer(int, int)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
api_initializer::
~api_initializer(void)
{ }
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GLEW
OGLPLUS_LIB_FUNC
api_initializer::
api_initializer(int, int)
{
	glewExperimental = GL_TRUE;
	GLenum init_result = glewInit();
	glGetError();
	if(init_result != GLEW_OK)
	{
		throw std::runtime_error(
			"OpenGL/GLEW initialization error."
		);
	}
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
api_initializer::
~api_initializer(void)
{ }
//------------------------------------------------------------------------------
# elif OGLPLUS_USE_GL3W
OGLPLUS_LIB_FUNC
api_initializer::
api_initializer(int gl_ver_major, int gl_ver_minor)
{
	auto init_failed = gl3wInit();
	glGetError();
	if(init_failed)
	{
		throw std::runtime_error(
			"OpenGL/GL3W initialization error."
		);
	}
	if(!gl3wIsSupported(gl_ver_major, gl_ver_minor))
	{
		throw std::runtime_error(
			"Requested OpenGL version not supported"
		);
	}
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
api_initializer::
~api_initializer(void)
{ }
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
#endif // NO_GL
} // namespace oglplus
//------------------------------------------------------------------------------

