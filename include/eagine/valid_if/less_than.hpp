/**
 *  @file eagine/valid_if/less_than.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_LESS_THAN_1509260923_HPP
#define EAGINE_VALID_IF_LESS_THAN_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// less-than
template <typename T, T Cmp>
struct valid_if_lt_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept {
		return value < Cmp;
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
				<< "greater then or equal to " << Cmp << " "
				<< "is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept {
			EAGINE_ABORT(
			"Value greater than or equal to the limit is invalid"
			);
		}
	};
};

template <typename T, T Cmp>
using valid_if_less_than = valid_if<T, valid_if_lt_policy<T, Cmp>>;

} // namespace eagine

#endif // include guard
