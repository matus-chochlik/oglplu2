/**
 *  @file oglplus/texture.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/texture_target_bq.inl"
#endif
//------------------------------------------------------------------------------
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
inline
outcome<texture_unit>
texture_ops::
active_texture(void)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		numeric_query(GL_ACTIVE_TEXTURE),
		{&result, 1}
	), texture_unit(GLenum(result));
}
//------------------------------------------------------------------------------
inline
outcome<texture_name>
texture_ops::
texture_binding(texture_target target)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), texture_name(GLuint(result));
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
//------------------------------------------------------------------------------

