/**
 *  @file oglplus/data_type.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_DATA_TYPE_1509260923_HPP
#define OGLPLUS_DATA_TYPE_1509260923_HPP

#include "enum/types.hpp"
#include "utils/identity.hpp"
#include <type_traits>

namespace oglplus {

template <typename T>
struct is_gl_data_type
 : std::false_type
{ };

template <>
struct is_gl_data_type<GLbyte>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLbyte>)
noexcept
{
	return data_type(GL_BYTE);
}

template <>
struct is_gl_data_type<GLubyte>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLubyte>)
noexcept
{
	return data_type(GL_UNSIGNED_BYTE);
}

template <>
struct is_gl_data_type<GLshort>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLshort>)
noexcept
{
	return data_type(GL_SHORT);
}

template <>
struct is_gl_data_type<GLushort>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLushort>)
noexcept
{
	return data_type(GL_UNSIGNED_SHORT);
}

template <>
struct is_gl_data_type<GLint>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLint>)
noexcept
{
	return data_type(GL_INT);
}

template <>
struct is_gl_data_type<GLuint>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLuint>)
noexcept
{
	return data_type(GL_UNSIGNED_INT);
}

template <>
struct is_gl_data_type<GLfloat>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLfloat>)
noexcept
{
	return data_type(GL_FLOAT);
}

#ifdef GL_DOUBLE
template <>
struct is_gl_data_type<GLdouble>
 : std::true_type
{ };

static constexpr inline
data_type get_data_type(identity<GLdouble>)
noexcept
{
	return data_type(GL_DOUBLE);
}
#endif

template <typename T>
static constexpr inline
data_type get_data_type(void)
noexcept
{
	return get_data_type(identity<std::remove_cv_t<T>>());
}

} // namespace oglplus

#endif // include guard
