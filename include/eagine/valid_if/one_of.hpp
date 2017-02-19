/**
 *  @file eagine/valid_if/one_of.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_ONE_OF_1509260923_HPP
#define EAGINE_VALID_IF_ONE_OF_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// one of
template <typename T, T ... C>
struct valid_if_one_of_policy
{
	bool operator ()(const T& value) const
	noexcept {
		const T choices[] = {C...};
		for(const T& choice : choices) {
			if(value == choice) {
				return true;
			}
		}
		return false;
	}

	struct do_log
	{
		template <typename X>
		constexpr inline
		do_log(X&&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const {
			log	<< "Value " << v << ", "
				<< "other than one of the values [";

			const T choices[] = {C...};
			bool first = true;
			for(const T& choice : choices) {
				log << (first?"":", ") << choice;
				first = false;
			}
			log	<< "] is invalid";
		}
	};
};

template <typename T, T ... C>
using valid_if_one_of = valid_if<T, valid_if_one_of_policy<T, C...>>;

} // namespace eagine

#endif // include guard
