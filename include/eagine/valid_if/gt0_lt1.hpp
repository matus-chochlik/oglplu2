/**
 *  @file eagine/valid_if/gt0_lt1.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_GT0_LT1_1509260923_HPP
#define EAGINE_VALID_IF_GT0_LT1_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// in (0, 1)
template <typename T>
struct valid_if_gt0_lt1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept {
		return (T(0) < value) && (value < T(1));
	}

	struct do_log
	{
		template <typename X>
		constexpr inline
		do_log(X)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const {
			log	<< "Value " << v << ", "
				<< "outside of interval (0,1) is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept {
			EAGINE_ABORT(
			"Value outside of interval (0,1) is invalid"
			);
		}
	};
};

template <typename T>
using valid_if_gt0_lt1 = valid_if<T, valid_if_gt0_lt1_policy<T>>;

} // namespace eagine

#endif // include guard
