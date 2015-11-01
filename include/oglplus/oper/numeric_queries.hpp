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
	get_boolean_v(numeric_query query, array_view<GLboolean> data)
	noexcept
	{
		assert(data.size() > 0);
		OGLPLUS_GLFUNC(GetBooleanv)(
			GLenum(query),
			data.data()
		);
		OGLPLUS_VERIFY(
			GetBooleanv,
			gl_enum_value(query),
			always
		);
		return {};
	}

	static
	outcome<boolean>
	get_boolean(numeric_query query)
	noexcept
	{
		GLboolean result = 0;
		return get_boolean_v(query, {&result, 1}), boolean(result);
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
	outcome<GLint>
	get_integer(numeric_query query)
	noexcept
	{
		GLint result = 0;
		return get_integer_v(query, {&result, 1}), result;
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

	static
	outcome<GLfloat>
	get_float(numeric_query query)
	noexcept
	{
		GLfloat result = 0;
		return get_float_v(query, {&result, 1}), result;
	}
};

} // namespace oper
} // namespace oglplus

#endif // include guard
