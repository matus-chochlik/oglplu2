/**
 *  @file oglplus/path_nv.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PATH_NV_1509260923_HPP
#define OGLPLUS_PATH_NV_1509260923_HPP

#include "path_nv_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"
#include "path_nv_spec.hpp"
#include "data_type.hpp"

namespace oglplus {
namespace oper {

struct path_nv_ops
{
	template <typename T>
	static
	outcome<void>
	path_commands(
		path_nv_name path,
		array_view<const GLubyte> commands,
		array_view<const T> coords
	) noexcept;

	template <typename T>
	static
	outcome<void>
	path_commands(path_nv_name path, const path_nv_spec<T>& spec)
	noexcept;

	template <typename T>
	static
	outcome<void>
	path_sub_commands(
		path_nv_name path,
		GLsizei command_start,
		GLsizei commands_to_delete,
		array_view<const GLubyte> commands,
		array_view<const T> coords
	) noexcept;

	template <typename T>
	static
	outcome<void>
	path_sub_commands(
		path_nv_name path,
		GLsizei command_start,
		GLsizei commands_to_delete,
		const path_nv_spec<T>& spec
	) noexcept;

	template <typename T>
	static
	outcome<void>
	path_coords(path_nv_name path, array_view<const T> coords)
	noexcept;

	static
	outcome<void>
	path_string(
		path_nv_name,
		path_format_nv format,
		array_view<const char> path_str
	) noexcept;

	static
	outcome<void>
	path_svg_string(path_nv_name, array_view<const char> path_str)
	noexcept;

	static
	outcome<void>
	path_ps_string(path_nv_name, array_view<const char> path_str)
	noexcept;

	static
	outcome<boolean>
	is_point_in_fill_path(path_nv_name, GLuint mask, GLfloat x, GLfloat y)
	noexcept;

	static
	outcome<boolean>
	is_point_in_stroke_path(path_nv_name, GLfloat x, GLfloat y)
	noexcept;

	static
	outcome<GLfloat>
	get_path_length(path_nv_name, GLsizei start_seg, GLsizei num_segs)
	noexcept;

	static
	outcome<boolean>
	point_along_path(
		path_nv_name,
		GLsizei start_seg,
		GLsizei num_segs,
		GLfloat distance,
		GLfloat& ref_x,
		GLfloat& ref_y,
		GLfloat& ref_tg_x,
		GLfloat& ref_tg_y
	) noexcept;

	static
	outcome<void>
	stencil_fill_path(path_nv_name, path_fill_mode_nv mode, GLuint mask)
	noexcept;

	static
	outcome<void>
	cover_fill_path(path_nv_name, path_fill_cover_mode_nv mode)
	noexcept;

	static
	outcome<void>
	stencil_stroke_path(path_nv_name, GLint reference, GLuint mask)
	noexcept;

	static
	outcome<void>
	cover_stroke_path(path_nv_name, path_stroke_cover_mode_nv mode)
	noexcept;

	static
	outcome<void>
	path_parameter_i(
		path_nv_name path,
		oglplus::path_parameter_nv param,
		GLint value
	) noexcept;

	static
	outcome<void>
	path_parameter_f(
		path_nv_name path,
		oglplus::path_parameter_nv param,
		GLfloat value
	) noexcept;

	static
	outcome<void>
	get_path_parameter_iv(
		path_nv_name path,
		oglplus::path_parameter_nv param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	get_path_parameter_fv(
		path_nv_name path,
		oglplus::path_parameter_nv param,
		array_view<GLfloat> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_path_parameter_i(path_nv_name, path_parameter_nv param)
	noexcept;

	template <typename R>
	static
	outcome<R>
	return_path_parameter_f(path_nv_name, path_parameter_nv param)
	noexcept;

	static
	outcome<GLfloat>
	path_computed_length(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_stroke_width(path_nv_name, GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	path_stroke_width(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_miter_limit(path_nv_name, GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	path_miter_limit(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_join_style(path_nv_name, path_join_style_nv value)
	noexcept;

	static
	outcome<path_join_style_nv>
	path_join_style(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_initial_end_cap(path_nv_name, path_cap_style_nv value)
	noexcept;

	static
	outcome<path_cap_style_nv>
	path_initial_end_cap(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_terminal_end_cap(path_nv_name, path_cap_style_nv value)
	noexcept;

	static
	outcome<path_cap_style_nv>
	path_terminal_end_cap(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_initial_dash_cap(path_nv_name, path_cap_style_nv value)
	noexcept;

	static
	outcome<path_cap_style_nv>
	path_initial_dash_cap(path_nv_name)
	noexcept;

	static
	outcome<void>
	path_terminal_dash_cap(path_nv_name, path_cap_style_nv value)
	noexcept;

	static
	outcome<path_cap_style_nv>
	path_terminal_dash_cap(path_nv_name)
	noexcept;
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::path_nv, Derived, Base>
 : Base
{
private:
	Derived& _self()
	noexcept
	{
		return *static_cast<Derived*>(this);
	}

	typedef oper::path_nv_ops _ops;
protected:
	using Base::Base;
public:
	template <typename T>
	outcome<Derived&>
	commands(array_view<const GLubyte> cmds, array_view<const T> coords)
	noexcept
	{
		return {_ops::path_commands(*this, cmds, coords), _self()};
	}

	template <typename T>
	outcome<Derived&>
	commands(const path_nv_spec<T>& spec)
	noexcept
	{
		return {_ops::path_commands(*this, spec), _self()};
	}

	template <typename T>
	outcome<Derived&>
	sub_commands(
		GLsizei cmd_start,
		GLsizei cmds_to_delete,
		array_view<const GLubyte> cmds,
		array_view<const T> coords
	) noexcept
	{
		return {_ops::path_sub_commands(
			*this,
			cmd_start, cmds_to_delete,
			cmds, coords
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	sub_commands(
		GLsizei cmd_start,
		GLsizei cmds_to_delete,
		const path_nv_spec<T>& spec
	) noexcept
	{
		return {_ops::path_sub_commands(
			*this,
			cmd_start, cmds_to_delete,
			spec
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	coords(array_view<const T> crds)
	noexcept
	{
		return {_ops::path_coords(*this, crds), _self()};
	}

	outcome<Derived&>
	string(path_format_nv format, array_view<const char> path_str)
	noexcept
	{
		return {_ops::path_string(*this, format, path_str), _self()};
	}

	outcome<Derived&>
	svg_string(array_view<const char> path_str)
	noexcept
	{
		return {_ops::path_svg_string(*this, path_str), _self()};
	}

	outcome<Derived&>
	ps_string(array_view<const char> path_str)
	noexcept
	{
		return {_ops::path_ps_string(*this, path_str), _self()};
	}

	outcome<boolean>
	is_point_in_fill(GLuint mask, GLfloat x, GLfloat y)
	noexcept
	{
		return _ops::is_point_in_fill_path(*this, mask, x, y);
	}

	outcome<boolean>
	is_point_in_stroke(GLfloat x, GLfloat y)
	noexcept
	{
		return _ops::is_point_in_stroke_path(*this, x, y);
	}

	outcome<GLfloat>
	get_length(GLsizei start_seg, GLsizei num_segs)
	noexcept
	{
		return _ops::get_path_length(*this, start_seg, num_segs);
	}

	outcome<boolean>
	point_along(
		GLsizei start_seg,
		GLsizei num_segs,
		GLfloat distance,
		GLfloat& ref_x,
		GLfloat& ref_y,
		GLfloat& ref_tg_x,
		GLfloat& ref_tg_y
	) noexcept
	{
		return _ops::point_along_path(
			*this,
			start_seg, num_segs,
			distance,
			ref_x, ref_y,
			ref_tg_x, ref_tg_y
		);
	}

	outcome<Derived&>
	stencil_fill(path_fill_mode_nv mode, GLuint mask)
	noexcept
	{
		return {_ops::stencil_fill_path(*this, mode, mask), _self()};
	}

	outcome<Derived&>
	cover_fill(path_fill_cover_mode_nv mode)
	noexcept
	{
		return {_ops::cover_fill_path(*this, mode), _self()};
	}

	outcome<Derived&>
	stencil_stroke(GLint ref, GLuint mask)
	noexcept
	{
		return {_ops::stencil_stroke_path(*this, ref, mask), _self()};
	}

	outcome<Derived&>
	cover_stroke(path_stroke_cover_mode_nv mode)
	noexcept
	{
		return {_ops::cover_stroke_path(*this, mode), _self()};
	}

	outcome<GLfloat>
	computed_length(void) const
	noexcept
	{
		return _ops::path_computed_length(*this);
	}

	outcome<Derived&>
	stroke_width(GLfloat value)
	noexcept
	{
		return {_ops::path_stroke_width(*this, value), _self()};
	}

	outcome<GLfloat>
	stroke_width(void) const
	noexcept
	{
		return _ops::path_stroke_width(*this);
	}

	outcome<Derived&>
	miter_limit(GLfloat value)
	noexcept
	{
		return {_ops::path_miter_limit(*this, value), _self()};
	}

	outcome<GLfloat>
	miter_limit(void) const
	noexcept
	{
		return _ops::path_miter_limit(*this);
	}

	outcome<Derived&>
	join_style(path_join_style_nv value)
	noexcept
	{
		return {_ops::path_join_style(*this, value), _self()};
	}

	outcome<path_join_style_nv>
	join_style(void)
	noexcept
	{
		return _ops::path_join_style(*this);
	}

	outcome<Derived&>
	initial_end_cap(path_cap_style_nv value)
	noexcept
	{
		return {_ops::path_initial_end_cap(*this, value),_self()};
	}

	outcome<path_cap_style_nv>
	initial_end_cap(void)
	noexcept
	{
		return _ops::path_initial_end_cap(*this);
	}

	outcome<Derived&>
	terminal_end_cap(path_cap_style_nv value)
	noexcept
	{
		return {_ops::path_terminal_end_cap(*this, value),_self()};
	}

	outcome<path_cap_style_nv>
	terminal_end_cap(void)
	noexcept
	{
		return _ops::path_terminal_end_cap(*this);
	}

	outcome<Derived&>
	initial_dash_cap(path_cap_style_nv value)
	noexcept
	{
		return {_ops::path_initial_dash_cap(*this, value),_self()};
	}

	outcome<path_cap_style_nv>
	initial_dash_cap(void)
	noexcept
	{
		return _ops::path_initial_dash_cap(*this);
	}

	outcome<Derived&>
	terminal_dash_cap(path_cap_style_nv value)
	noexcept
	{
		return {_ops::path_terminal_dash_cap(*this, value),_self()};
	}

	outcome<path_cap_style_nv>
	terminal_dash_cap(void)
	noexcept
	{
		return _ops::path_terminal_dash_cap(*this);
	}
};

template <>
struct obj_dsa_ops<path_nv_name>
 : obj_member_ops<
	tag::path_nv,
	obj_dsa_ops<path_nv_name>,
	obj_zero_dsa_ops<path_nv_name>
>
{
	using obj_member_ops<
		tag::path_nv,
		obj_dsa_ops<path_nv_name>,
		obj_zero_dsa_ops<path_nv_name>
	>::obj_member_ops;
};

template <>
struct obj_gen_del_ops<tag::path_nv>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using path_nv = object_owner<tag::path_nv>;

static const object_zero_and_ops<tag::path_nv>
	no_path_nv = {};

} // namespace oglplus

#include <oglplus/path_nv.inl>

#endif // include guard
