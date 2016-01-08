/**
 *  @file oglplus/oper/numeric_queries.inl
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
inline
outcome<void>
numeric_queries::
get_integer_v(binding_query query, span<GLint> data)
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
//------------------------------------------------------------------------------
inline
outcome<void>
numeric_queries::
get_boolean_v(numeric_query query, span<GLboolean> data)
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
//------------------------------------------------------------------------------
inline
outcome<boolean>
numeric_queries::
get_boolean(numeric_query query)
noexcept
{
	GLboolean result = 0;
	return get_boolean_v(query, {&result, 1}), boolean(result);
}
//------------------------------------------------------------------------------
inline
outcome<void>
numeric_queries::
get_integer_v(numeric_query query, span<GLint> data)
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
//------------------------------------------------------------------------------
inline
outcome<GLint>
numeric_queries::
get_integer(numeric_query query)
noexcept
{
	GLint result = 0;
	return get_integer_v(query, {&result, 1}), result;
}
//------------------------------------------------------------------------------
inline
outcome<void>
numeric_queries::
get_float_v(numeric_query query, span<GLfloat> data)
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
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
numeric_queries::
get_float(numeric_query query)
noexcept
{
	GLfloat result = 0;
	return get_float_v(query, {&result, 1}), result;
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
