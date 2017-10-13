/**
 *  @file oglplus/oper/blending.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <algorithm>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
blending_state::
blend_equation(oglplus::blend_equation equation)
noexcept {
	OGLPLUS_GLFUNC(BlendEquation)(GLenum(equation));
	OGLPLUS_VERIFY(
		BlendEquation,
		gl_enum_value(equation),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline
outcome<void>
blending_state::
blend_equation(GLuint buf, oglplus::blend_equation equation)
noexcept {
	OGLPLUS_GLFUNC(BlendEquationi)(buf, GLenum(equation));
	OGLPLUS_VERIFY(
		BlendEquation,
		gl_enum_value(equation).
		gl_index(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
