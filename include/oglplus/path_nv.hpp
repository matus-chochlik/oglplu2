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

namespace oglplus {
namespace oper {

struct path_nv_ops
{
};

} // namespace oper

template <>
struct obj_dsa_ops<path_nv_name>
 : obj_zero_dsa_ops<path_nv_name>
{
	typedef oper::path_nv_ops _ops;

	using obj_zero_dsa_ops<path_nv_name>::obj_zero_dsa_ops;

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
