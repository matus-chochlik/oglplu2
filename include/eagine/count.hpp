/**
 *  @file eagine/count.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_COUNT_1509260923_HPP
#define EAGINE_COUNT_1509260923_HPP

namespace eagine {

template <typename Int = unsigned>
class count_t
{
private:
	Int _c;
public:
	constexpr inline
	count_t(void)
	noexcept
	 : _c(0)
	{ }

	typedef Int value_type;

	constexpr
	value_type value(void) const
	noexcept
	{
		return _c;
	}

	constexpr
	operator value_type (void) const
	noexcept
	{
		return _c;
	}

	template <typename ... P>
	void operator()(const P& ...)
	noexcept
	{
		++_c;
	}
};

} // namespace eagine

#endif // include guard
