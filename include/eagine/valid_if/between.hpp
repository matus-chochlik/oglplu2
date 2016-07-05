/**
 *  @file eagine/valid_if/between.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_BETWEEN_1509260923_HPP
#define EAGINE_VALID_IF_BETWEEN_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// between [min, max]
template <typename T, T Min, T Max>
struct valid_if_btwn_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (Min <= value) && (value <= Max);
	}

	struct do_log
	{
		inline
		do_log(const valid_if_btwn_policy<T, Min, Max>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", not between "
				<< Min << " and " << Max << " is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value outside of the specified limits is invalid"
			);
		}
	};
};

template <typename T, T Min, T Max>
using valid_if_between = valid_if<T, valid_if_btwn_policy<T, Min, Max>>;

} // namespace eagine

#endif // include guard
