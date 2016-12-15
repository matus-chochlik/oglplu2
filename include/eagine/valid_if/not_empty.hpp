/**
 *  @file eagine/valid_if/not_empty.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_NOT_EMPTY_1509260923_HPP
#define EAGINE_VALID_IF_NOT_EMPTY_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// not empty
template <typename T>
struct valid_if_not_empty_policy
{
	constexpr
	bool operator ()(const T& range) const
	noexcept {
		return !range.empty();
	}

	struct do_log
	{
		template <typename X>
		constexpr inline
		do_log(X)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T&) const {
			log << "Empty range, string or container is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept {
			EAGINE_ABORT("Empty range or container is invalid");
		}
	};
};

template <typename T>
using valid_if_not_empty = valid_if<T, valid_if_not_empty_policy<T>>;

} // namespace eagine

#endif // include guard
