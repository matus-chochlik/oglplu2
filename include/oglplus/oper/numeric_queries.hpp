/**
 *  @file oglplus/oper/numeric_queries.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_NUMERIC_QUERIES_1509260923_HPP
#define OGLPLUS_OPER_NUMERIC_QUERIES_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../utils/span.hpp"
#include "../utils/boolean.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct numeric_queries
{
	static
	outcome<void>
	get_integer_v(binding_query query, span<GLint> data)
	noexcept;

	static
	outcome<void>
	get_boolean_v(numeric_query query, span<GLboolean> data)
	noexcept;

	static
	outcome<boolean>
	get_boolean(numeric_query query)
	noexcept;

	static
	outcome<void>
	get_integer_v(numeric_query query, span<GLint> data)
	noexcept;

	static
	outcome<GLint>
	get_integer(numeric_query query)
	noexcept;

	static
	outcome<void>
	get_float_v(numeric_query query, span<GLfloat> data)
	noexcept;

	static
	outcome<GLfloat>
	get_float(numeric_query query)
	noexcept;
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/numeric_queries.inl>

#endif // include guard
