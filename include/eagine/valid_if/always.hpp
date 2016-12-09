/**
 *  @file eagine/valid_if/always.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_ALWAYS_1509260923_HPP
#define EAGINE_VALID_IF_ALWAYS_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// always
struct always_valid_policy
{
	template <typename T>
	constexpr inline
	bool operator ()(T) const
	noexcept { return true; }

	struct do_log
	{
		template <typename X>
		constexpr inline
		do_log(X)
		noexcept
		{ }

		template <typename Log, typename T>
		void operator ()(Log&, const T&) const { }
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept {
			EAGINE_ABORT("Never should get here!");
		}
	};
};

template <typename T>
using always_valid = valid_if<T, always_valid_policy>;

} // namespace eagine

#endif // include guard
