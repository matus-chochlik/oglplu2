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

namespace oglplus {

static constexpr inline
data_type get_data_type(identity<GLbyte>)
noexcept
{
	return data_type(GL_BYTE);
}

static constexpr inline
data_type get_data_type(identity<GLubyte>)
noexcept
{
	return data_type(GL_UNSIGNED_BYTE);
}

static constexpr inline
data_type get_data_type(identity<GLshort>)
noexcept
{
	return data_type(GL_SHORT);
}

static constexpr inline
data_type get_data_type(identity<GLushort>)
noexcept
{
	return data_type(GL_UNSIGNED_SHORT);
}

static constexpr inline
data_type get_data_type(identity<GLint>)
noexcept
{
	return data_type(GL_INT);
}

static constexpr inline
data_type get_data_type(identity<GLuint>)
noexcept
{
	return data_type(GL_UNSIGNED_INT);
}

static constexpr inline
data_type get_data_type(identity<GLfloat>)
noexcept
{
	return data_type(GL_FLOAT);
}

#ifdef GL_DOUBLE
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
	return get_data_type(identity<T>());
}

} // namespace oglplus

#endif // include guard
