/**
 *  @file oglplus/path_nv.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SAMPLER_1509260923_HPP
#define OGLPLUS_SAMPLER_1509260923_HPP

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
