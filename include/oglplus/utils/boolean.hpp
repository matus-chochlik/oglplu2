/**
 *  @file oglplus/utils/boolean.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_BOOLEAN_1509260923_HPP
#define OGLPLUS_UTILS_BOOLEAN_1509260923_HPP

#include "../enum_types.hpp"

namespace oglplus {

struct boolean
{
	GLboolean _v;

	constexpr inline
	boolean(bool v)
	noexcept
	 : _v(v?GL_TRUE:GL_FALSE)
	{ }

	constexpr inline
	boolean(true_false v)
	noexcept
	 : _v(GLboolean(v))
	{ }

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return _v == GL_TRUE;
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return _v == GL_FALSE;
	}

	constexpr inline
	operator GLboolean (void) const
	noexcept
	{
		return _v;
	}
};

} // namespace oglplus

#endif // include guard
