/**
 *  @file oglplus/command_list_nv.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_COMMAND_LIST_NV_1509260923_HPP
#define OGLPLUS_COMMAND_LIST_NV_1509260923_HPP

#include "command_list_nv_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/boolean.hpp"

namespace oglplus {
namespace oper {

struct command_list_nv_ops
{
	// TODO:
};

} // namespace oper

template <>
struct obj_dsa_ops<tag::command_list_nv>
 : obj_zero_dsa_ops<tag::command_list_nv>
{
	typedef oper::command_list_nv_ops _ops;

	using obj_zero_dsa_ops<tag::command_list_nv>::obj_zero_dsa_ops;

};

template <>
struct obj_gen_del_ops<tag::command_list_nv>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using command_list_nv = object_owner<tag::command_list_nv>;
template <std::size_t N>
using command_list_nv_array = object_array_owner<tag::command_list_nv, N>;

} // namespace oglplus

#include <oglplus/command_list_nv.inl>

#endif // include guard
