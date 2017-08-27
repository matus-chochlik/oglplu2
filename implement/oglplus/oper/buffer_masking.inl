/**
 *  @file oglplus/oper/buffer_masking.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_masking_state::
color_mask(boolean r, boolean g, boolean b, boolean a)
noexcept
{
	OGLPLUS_GLFUNC(ColorMask)(
		GLboolean(r),
		GLboolean(g),
		GLboolean(b),
		GLboolean(a)
	);
	OGLPLUS_VERIFY_SIMPLE(ColorMask,debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_masking_state::
color_mask(const rgba_mask& m)
noexcept
{
	OGLPLUS_GLFUNC(ColorMask)(
		GLboolean(m._v[0]),
		GLboolean(m._v[1]),
		GLboolean(m._v[2]),
		GLboolean(m._v[3])
	);
	OGLPLUS_VERIFY_SIMPLE(ColorMask,debug);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline
outcome<void>
buffer_masking_state::
color_mask_i(GLuint buffer, boolean r, boolean g, boolean b, boolean a)
noexcept
{
	OGLPLUS_GLFUNC(ColorMaski)(
		buffer,
		GLboolean(r),
		GLboolean(g),
		GLboolean(b),
		GLboolean(a)
	);
	OGLPLUS_VERIFY(
		ColorMaski,
		gl_index(buffer),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_masking_state::
color_mask_i(GLuint buffer, const rgba_mask& m)
noexcept
{
	OGLPLUS_GLFUNC(ColorMaski)(
		buffer,
		GLboolean(m._v[0]),
		GLboolean(m._v[1]),
		GLboolean(m._v[2]),
		GLboolean(m._v[3])
	);
	OGLPLUS_VERIFY(
		ColorMaski,
		gl_index(buffer),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_masking_state::
depth_mask(boolean mask)
noexcept
{
	OGLPLUS_GLFUNC(DepthMask)(GLboolean(mask));
	OGLPLUS_VERIFY_SIMPLE(DepthMask,debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_masking_state::
stencil_mask(GLuint mask)
noexcept
{
	OGLPLUS_GLFUNC(StencilMask)(mask);
	OGLPLUS_VERIFY_SIMPLE(StencilMask,debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_masking_state::
stencil_mask_separate(single_face face, GLuint mask)
noexcept
{
	OGLPLUS_GLFUNC(StencilMaskSeparate)(GLenum(face), mask);
	OGLPLUS_VERIFY_SIMPLE(StencilMaskSeparate,debug);
	return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
