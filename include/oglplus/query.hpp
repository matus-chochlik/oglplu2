/**
 *  @file oglplus/query.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_QUERY_1509260923_HPP
#define OGLPLUS_QUERY_1509260923_HPP

#include "query_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/boolean.hpp"

namespace oglplus {
namespace oper {

struct query_ops
{
	// TODO
};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::query>
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

using query = object_owner<tag::query>;
template <std::size_t N>
using query_array = object_array_owner<tag::query, N>;

} // namespace oglplus

#include <oglplus/query.inl>

#endif // include guard
