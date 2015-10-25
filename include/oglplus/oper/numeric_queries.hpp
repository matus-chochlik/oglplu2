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
#include "../utils/array_view.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct numeric_queries
{
	static
	outcome<void>
	get_integer_v(binding_query query, array_view<GLint> data)
	noexcept
	{
		assert(data.size() > 0);
		OGLPLUS_GLFUNC(GetIntegerv)(
			GLenum(query),
			data.data()
		);
		OGLPLUS_VERIFY(
			GetIntegerv,
			gl_enum_value(query),
			always
		);
		return {};
	}

	static
	outcome<void>
	get_integer_v(numeric_query query, array_view<GLint> data)
	noexcept
	{
		assert(data.size() > 0);
		OGLPLUS_GLFUNC(GetIntegerv)(
			GLenum(query),
			data.data()
		);
		OGLPLUS_VERIFY(
			GetIntegerv,
			gl_enum_value(query),
			always
		);
		return {};
	}

	static
	outcome<void>
	get_float_v(numeric_query query, array_view<GLfloat> data)
	noexcept
	{
		assert(data.size() > 0);
		OGLPLUS_GLFUNC(GetFloatv)(
			GLenum(query),
			data.data()
		);
		OGLPLUS_VERIFY(
			GetFloatv,
			gl_enum_value(query),
			always
		);
		return {};
	}
};

} // namespace oper
} // namespace oglplus

#endif // include guard
