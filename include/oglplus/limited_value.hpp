/**
 *  @file oglplus/limited_value.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_LIMITED_VALUE_1509260923_HPP
#define OGLPLUS_LIMITED_VALUE_1509260923_HPP

#include "utils/gl_func.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "enum_types.hpp"

namespace oglplus {

template <GLenum Query>
struct limited_value;

template <GLenum Query>
outcome<GLint>
limit(const limited_value<Query>&)
noexcept
{
	GLint value = 0;
	OGLPLUS_GLFUNC(GetIntegerv)(Query, &value);
	OGLPLUS_VERIFY(
		GetIntegerv,
		gl_enum_value(limit_query(Query)),
		debug
	);
	return {value};
}

template <GLenum Query>
struct limited_value
{
	GLint _value;

	constexpr
	limited_value(GLint value)
	noexcept
	 : _value(value)
	{ }
};

template <GLenum Query>
static inline
outcome<GLint>
get_value(limited_value<Query> lv)
noexcept
{
	outcome<GLint> lim = limit(lv);
	if(lim.failed())
	{
		return lim.release_handler();
	}
	if(!(lv._value < lim.get()))
	{
		return deferred_error_handler(
			error_info(GL_INVALID_VALUE)
				.gl_enum_value(limit_query(Query))
				.source_file(__FILE__)
				.source_line(__LINE__)
		);
	}
	return {lv._value};
}

} // namespace oglplus

#endif // include guard
