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
	static
	outcome<void>
	begin_query(query_target target, query_name qry)
	noexcept;

	static
	outcome<void>
	end_query(query_target target)
	noexcept;

#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	begin_conditional_render(query_name, conditional_render_mode mode)
	noexcept;

	static
	outcome<void>
	end_conditional_render(void)
	noexcept;
#endif

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	static
	outcome<void>
	query_counter(query_name qry, query_target target)
	noexcept;

	static
	outcome<void>
	query_timestamp(query_name qry)
	noexcept;
#endif

	static
	outcome<void>
	get_query_object_iv(
		query_name qry,
		oglplus::query_parameter param,
		span<GLint> values
	) noexcept;

	static
	outcome<void>
	get_query_object_uiv(
		query_name qry,
		oglplus::query_parameter param,
		span<GLuint> values
	) noexcept;

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	static
	outcome<void>
	get_query_object_i64v(
		query_name qry,
		oglplus::query_parameter param,
		span<GLint64> values
	) noexcept;

	static
	outcome<void>
	get_query_object_ui64v(
		query_name qry,
		oglplus::query_parameter param,
		span<GLuint64> values
	) noexcept;
#endif

	static
	outcome<boolean>
	query_result_available(query_name qry)
	noexcept;

#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	query_result(query_name qry, GLint& result)
	noexcept;
#endif

	static
	outcome<void>
	query_result(query_name qry, GLuint& result)
	noexcept;

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	static
	outcome<void>
	query_result(query_name qry, GLint64& result)
	noexcept;

	static
	outcome<void>
	query_result(query_name qry, GLuint64& result)
	noexcept;
#endif
};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::query>
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

using query = object_owner<tag::query>;
template <std::size_t N>
using query_array = object_array_owner<tag::query, N>;

} // namespace oglplus

#include <oglplus/query.inl>

#endif // include guard
