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
inline
outcome<void>
texture_ops::
active_texture(texture_unit unit)
noexcept
{
#if !OGLPLUS_NO_LIMIT_CHECKS
	if(auto over_limit = failure(check_below_limit(unit)))
	{
		return std::move(over_limit);
	}
#endif
	OGLPLUS_GLFUNC(ActiveTexture)(GLenum(unit));
	OGLPLUS_VERIFY(
		ActiveTexture,
		gl_enum_value(unit),
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
obj_gen_del_ops<tag::texture>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenTextures)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenTextures,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::texture>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteTextures)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteTextures,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<bool>
obj_gen_del_ops<tag::texture>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsTexture)(name);
	OGLPLUS_VERIFY_SIMPLE(IsTexture,debug);
	return res == GL_TRUE;
}
//------------------------------------------------------------------------------
} // namespace oglplus
