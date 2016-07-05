/**
 *  @file eagine/valid_if/not_zero.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_NOT_ZERO_1509260923_HPP
#define EAGINE_VALID_IF_NOT_ZERO_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// not-zero
template <typename T>
struct valid_if_nz_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (value > T(0)) || (value < T(0));
	}

	struct do_log
	{
		inline
		do_log(const valid_if_nz_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T&) const
		{
			log << "Value zero is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Value zero is invalid");
		}
	};
};

template <typename T>
using valid_if_not_zero = valid_if<T, valid_if_nz_policy<T>>;

// nonzero
template <typename T>
using nonzero_t = valid_if_not_zero<T>;

template <typename T>
static inline
nonzero_t<T> nonzero(T v)
noexcept
{
	return {v};
}

} // namespace eagine

#endif // include guard
