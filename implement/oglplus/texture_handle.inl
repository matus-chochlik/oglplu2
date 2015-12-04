/**
 *  @file oglplus/texture.inl
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
#if defined(GL_ARB_bindless_texture)
inline
outcome<texture_handle_arb>
texture_handle_ops::
get_texture_handle_arb(texture_name tex)
noexcept
{
	GLuint64 th = OGLPLUS_GLFUNC(GetTextureHandleARB)(get_raw_name(tex));
	OGLPLUS_VERIFY(
		GetTextureHandleARB,
		gl_object(tex),
		always
	);
	return {texture_handle_arb{th}};
}
//------------------------------------------------------------------------------
inline
outcome<texture_handle_arb>
texture_handle_ops::
get_texture_sampler_handle_arb(texture_name tex, sampler_name sam)
noexcept
{
	GLuint64 th = OGLPLUS_GLFUNC(GetTextureSamplerHandleARB)(
		get_raw_name(tex),
		get_raw_name(sam)
	);
	OGLPLUS_VERIFY(
		GetTextureSamplerHandleARB,
		gl_subject(sam).
		gl_object(tex),
		always
	);
	return {texture_handle_arb{th}};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_NV_bindless_texture)
inline
outcome<texture_handle_nv>
texture_handle_ops::
get_texture_handle_nv(texture_name tex)
noexcept
{
	GLuint64 th = OGLPLUS_GLFUNC(GetTextureHandleNV)(get_raw_name(tex));
	OGLPLUS_VERIFY(
		GetTextureHandleNV,
		gl_object(tex),
		always
	);
	return {texture_handle_nv{th}};
}
//------------------------------------------------------------------------------
inline
outcome<texture_handle_nv>
texture_handle_ops::
get_texture_sampler_handle_nv(texture_name tex, sampler_name sam)
noexcept
{
	GLuint64 th = OGLPLUS_GLFUNC(GetTextureSamplerHandleNV)(
		get_raw_name(tex),
		get_raw_name(sam)
	);
	OGLPLUS_VERIFY(
		GetTextureSamplerHandleNV,
		gl_subject(sam).
		gl_object(tex),
		always
	);
	return {texture_handle_nv{th}};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_ARB_bindless_texture)
inline
outcome<void>
make_texture_handle_resident(texture_handle_arb th)
noexcept
{
	OGLPLUS_GLFUNC(MakeTextureHandleResidentARB)(get_raw_handle(th));
	OGLPLUS_VERIFY_SIMPLE(MakeTextureHandleResidentARB, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_NV_bindless_texture)
inline
outcome<void>
make_texture_handle_resident(texture_handle_nv th)
noexcept
{
	OGLPLUS_GLFUNC(MakeTextureHandleResidentNV)(get_raw_handle(th));
	OGLPLUS_VERIFY_SIMPLE(MakeTextureHandleResidentNV, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_ARB_bindless_texture)
inline
outcome<void>
make_texture_handle_non_resident(texture_handle_arb th)
noexcept
{
	OGLPLUS_GLFUNC(MakeTextureHandleNonResidentARB)(get_raw_handle(th));
	OGLPLUS_VERIFY_SIMPLE(MakeTextureHandleNonResidentARB, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_NV_bindless_texture)
inline
outcome<void>
make_texture_handle_non_resident(texture_handle_nv th)
noexcept
{
	OGLPLUS_GLFUNC(MakeTextureHandleNonResidentNV)(get_raw_handle(th));
	OGLPLUS_VERIFY_SIMPLE(MakeTextureHandleNonResidentNV, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
//------------------------------------------------------------------------------

