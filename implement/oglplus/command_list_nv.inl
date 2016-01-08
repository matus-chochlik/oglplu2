/**
 *  @file oglplus/command_list_nv.inl
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
command_list_nv_ops::
command_list_segments(command_list_nv_name clst, GLuint segments)
noexcept
{
	OGLPLUS_GLFUNC(CommandListSegmentsNV)(
		get_raw_name(clst),
		segments
	);
	OGLPLUS_VERIFY(
		CommandListSegmentsNV,
		gl_object(clst),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
command_list_nv_ops::
compile_command_list(command_list_nv_name clst)
noexcept
{
	OGLPLUS_GLFUNC(CompileCommandListNV)(get_raw_name(clst));
	OGLPLUS_VERIFY(
		CompileCommandListNV,
		gl_object(clst),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
command_list_nv_ops::
call_command_list(command_list_nv_name clst)
noexcept
{
	OGLPLUS_GLFUNC(CallCommandListNV)(get_raw_name(clst));
	OGLPLUS_VERIFY(
		CallCommandListNV,
		gl_object(clst),
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
obj_gen_del_ops<tag::command_list_nv>::
_gen(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(CreateCommandListsNV)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(CreateCommandListsNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::command_list_nv>::
_delete(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteCommandListsNV)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteCommandListsNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::command_list_nv>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsCommandListNV)(name);
	OGLPLUS_VERIFY_SIMPLE(IsCommandListNV,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
