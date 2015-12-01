/**
 *  @file oglplus/state_nv.inl
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
state_nv_ops::
state_capture(state_nv_name ste, old_primitive_type mode)
noexcept
{
	OGLPLUS_GLFUNC(StateCaptureNV)(
		get_raw_name(ste),
		GLenum(mode)
	);
	OGLPLUS_VERIFY(
		StateCaptureNV,
		gl_enum_value(mode).
		gl_object(ste),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<GLuint>
state_nv_ops::
get_command_header(command_token_nv token_id, GLuint size)
noexcept
{
	GLuint result = OGLPLUS_GLFUNC(GetCommandHeaderNV)(
		GLenum(token_id),
		GLenum(size)
	);
	OGLPLUS_VERIFY(
		GetCommandHeaderNV,
		gl_enum_value(token_id),
		always
	);
	return {result};
}
//------------------------------------------------------------------------------
inline
outcome<GLushort>
state_nv_ops::
get_stage_index(shader_type stage)
noexcept
{
	GLushort result = OGLPLUS_GLFUNC(GetStageIndexNV)(GLenum(stage));
	OGLPLUS_VERIFY(
		GetStageIndexNV,
		gl_enum_value(stage),
		always
	);
	return {result};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::state_nv>::
_gen(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(CreateStatesNV)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(CreateStatesNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::state_nv>::
_delete(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteStatesNV)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteStatesNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::state_nv>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsStateNV)(name);
	OGLPLUS_VERIFY_SIMPLE(IsStateNV,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
