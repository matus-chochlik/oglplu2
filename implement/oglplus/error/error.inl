/**
 *  @file oglplus/error/error.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oglplus {
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::string
error::_make_msg(error_info& info) {
    switch(info.gl_error_code()) {
	case GL_OUT_OF_MEMORY:
	    return {"OpenGL out of memory"};
	case GL_INVALID_ENUM:
	    return {"Invalid OpenGL enum argument"};
	case GL_INVALID_VALUE:
	    return {"OpenGL numeric argument out of range"};
	case GL_INVALID_OPERATION:
	    return {"Invalid OpenGL operation"};
	case GL_INVALID_FRAMEBUFFER_OPERATION:
	    return {"Invalid OpenGL framebuffer operation"};
#ifdef GL_STACK_OVERFLOW
	case GL_STACK_OVERFLOW:
	    return {"OpenGL stack overflow"};
#endif
#ifdef GL_STACK_UNDERFLOW
	case GL_STACK_UNDERFLOW:
	    return {"OpenGL stack underflow"};
#endif
#ifdef GL_TABLE_TOO_LARGE
	case GL_TABLE_TOO_LARGE:
	    return {"OpenGL table too large"};
#endif
	default:;
    }
    return {"Unknown OpenGL error"};
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
inline error::error(error_info&& info)
  : std::runtime_error(_make_msg(info))
  , _info(std::move(info)) {
}
//------------------------------------------------------------------------------
} // namespace oglplus
