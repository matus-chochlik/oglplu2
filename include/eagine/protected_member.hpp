/**
 *  @file eagine/protected_member.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_PROTECTED_MEMBER_1509260923_HPP
#define EAGINE_PROTECTED_MEMBER_1509260923_HPP

#include "identity.hpp"
#include <utility>

namespace eagine {

template <typename T, typename Selector = identity<T>>
class protected_member
{
private:
	T _member;
protected:
	template <typename ... P>
	protected_member(P&& ... p)
	 : _member(std::forward<P>(p)...)
	{ }
public:
	T& get_the_member(Selector = Selector())
	noexcept
	{
		return _member;
	}

	const T& get_the_member(Selector = Selector()) const
	noexcept
	{
		return _member;
	}
};

template <typename Selector, typename T>
static inline
T& get_member(
	protected_member<T, Selector>& pm,
	Selector selector = Selector()
) noexcept
{
	return pm.get_the_member(selector);
}

template <typename Selector, typename T>
static inline
const T& get_member(
	const protected_member<T, Selector>& pm,
	Selector selector = Selector()
) noexcept
{
	return pm.get_the_member(selector);
}

} // namespace eagine


#endif // include guard
