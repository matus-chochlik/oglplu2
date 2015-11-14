/**
 *  @file oglplus/path_nv.inl
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
template <typename T>
inline
outcome<void>
path_nv_ops::
path_commands(
	path_nv_name path,
	array_view<const GLubyte> commands,
	array_view<const T> coords
) noexcept
{
	OGLPLUS_GLFUNC(PathCommandsNV)(
		get_raw_name(path),
		GLsizei(commands.size()),
		commands.data(),
		GLsizei(coords.size()),
		GLenum(get_data_type<T>()),
		static_cast<const void*>(coords.data())
	);
	OGLPLUS_VERIFY(
		PathCommandsNV,
		gl_object(path),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
template <typename T>
inline
outcome<void>
path_nv_ops::
path_commands(path_nv_name path, const path_nv_spec<T>& spec)
noexcept
{
	return path_commands<T>(path, spec._commands, spec._coords);
}
//------------------------------------------------------------------------------
template <typename T>
inline
outcome<void>
path_nv_ops::
path_sub_commands(
	path_nv_name path,
	GLsizei command_start,
	GLsizei commands_to_delete,
	array_view<const GLubyte> commands,
	array_view<const T> coords
) noexcept
{
	OGLPLUS_GLFUNC(PathSubCommandsNV)(
		get_raw_name(path),
		command_start,
		commands_to_delete,
		GLsizei(commands.size()),
		commands.data(),
		GLsizei(coords.size()),
		GLenum(get_data_type<T>()),
		static_cast<const void*>(coords.data())
	);
	OGLPLUS_VERIFY(
		PathSubCommandsNV,
		gl_object(path),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
template <typename T>
inline
outcome<void>
path_nv_ops::
path_sub_commands(
	path_nv_name path,
	GLsizei command_start,
	GLsizei commands_to_delete,
	const path_nv_spec<T>& spec
) noexcept
{
	return path_sub_commands<T>(
		path,
		command_start, commands_to_delete,
		spec._commands, spec._coords
	);
}
//------------------------------------------------------------------------------
template <typename T>
inline
outcome<void>
path_nv_ops::
path_coords(path_nv_name path, array_view<const T> coords)
noexcept
{
	OGLPLUS_GLFUNC(PathCoordsNV)(
		get_raw_name(path),
		GLsizei(coords.size()),
		GLenum(get_data_type<T>()),
		static_cast<const void*>(coords.data())
	);
	OGLPLUS_VERIFY(
		PathCoordsNV,
		gl_object(path),
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
obj_gen_del_ops<tag::path_nv>::
_gen(array_view<GLuint> names)
noexcept
{
	GLuint base = OGLPLUS_GLFUNC(GenPathsNV)(GLsizei(names.size()));
	for(std::size_t i=0; i<names.size(); ++i)
	{
		names[i] = base+GLuint(i);
	}
	OGLPLUS_VERIFY_SIMPLE(GenPathsNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::path_nv>::
_delete(array_view<GLuint> names)
noexcept
{
	if(names.begin() != names.end())
	{
		OGLPLUS_GLFUNC(DeletePathsNV)(
			*names.begin(),
			GLsizei(names.size())
		);
		OGLPLUS_VERIFY_SIMPLE(DeletePathsNV,debug);
	}
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::path_nv>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsPathNV)(name);
	OGLPLUS_VERIFY_SIMPLE(IsPathNV,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
