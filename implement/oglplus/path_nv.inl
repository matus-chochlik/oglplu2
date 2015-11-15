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
inline
outcome<void>
path_nv_ops::
path_string(
	path_nv_name path,
	path_format_nv format,
	array_view<const char> path_str
) noexcept
{
	OGLPLUS_GLFUNC(PathStringNV)(
		get_raw_name(path),
		GLenum(format),
		GLsizei(path_str.size()),
		static_cast<const void*>(path_str.data())
	);
	OGLPLUS_VERIFY(
		PathStringNV,
		gl_enum_value(format).
		gl_object(path),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
path_nv_ops::
path_svg_string(path_nv_name path, array_view<const char> str)
noexcept
{
	return path_string(path, path_format_nv(GL_PATH_FORMAT_SVG_NV), str);
}
//------------------------------------------------------------------------------
inline
outcome<void>
path_nv_ops::
path_ps_string(path_nv_name path, array_view<const char> str)
noexcept
{
	return path_string(path, path_format_nv(GL_PATH_FORMAT_PS_NV), str);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
path_nv_ops::
is_point_in_fill_path(path_nv_name path, GLuint mask, GLfloat x, GLfloat y)
noexcept
{
	boolean result = OGLPLUS_GLFUNC(IsPointInFillPathNV)(
		get_raw_name(path),
		mask, x, y
	);
	OGLPLUS_VERIFY(
		IsPointInFillPathNV,
		gl_object(path),
		debug
	);
	return {result};
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
path_nv_ops::
is_point_in_stroke_path(path_nv_name path, GLfloat x, GLfloat y)
noexcept
{
	boolean result = OGLPLUS_GLFUNC(IsPointInStrokePathNV)(
		get_raw_name(path),
		x, y
	);
	OGLPLUS_VERIFY(
		IsPointInStrokePathNV,
		gl_object(path),
		debug
	);
	return {result};
}
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
path_nv_ops::
get_path_length(path_nv_name path, GLsizei start_segment, GLsizei num_segments)
noexcept
{
	GLfloat result = OGLPLUS_GLFUNC(GetPathLengthNV)(
		get_raw_name(path),
		start_segment,
		num_segments
	);
	OGLPLUS_VERIFY(
		GetPathLengthNV,
		gl_object(path),
		debug
	);
	return {result};
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
path_nv_ops::
point_along_path(
	path_nv_name path,
	GLsizei start_seg,
	GLsizei num_segs,
	GLfloat distance,
	GLfloat& ref_x,
	GLfloat& ref_y,
	GLfloat& ref_tg_x,
	GLfloat& ref_tg_y
) noexcept
{
	boolean result = OGLPLUS_GLFUNC(PointAlongPathNV)(
		get_raw_name(path),
		start_seg, num_segs,
		distance,
		&ref_x, &ref_y,
		&ref_tg_x, &ref_tg_y
	);
	OGLPLUS_VERIFY(
		PointAlongPathNV,
		gl_object(path),
		debug
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
