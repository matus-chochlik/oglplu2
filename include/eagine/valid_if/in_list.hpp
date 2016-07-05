/**
 *  @file eagine/valid_if/in_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_IN_LIST_1509260923_HPP
#define EAGINE_VALID_IF_IN_LIST_1509260923_HPP

#include "decl.hpp"

namespace eagine {

// in range
template <typename T, typename Range>
struct valid_if_in_list_policy
{
	Range _choices;

	valid_if_in_list_policy(const Range& choices)
	 : _choices(choices)
	{ }

	bool operator ()(const T& value) const
	noexcept
	{
		for(const T& choice : _choices)
		{
			if(value == choice)
			{
				return true;
			}
		}
		return false;
	}

	struct do_log
	{
		const Range* _choices;

		inline
		do_log(const valid_if_in_list_policy<T, Range>& p)
		noexcept
		 : _choices(&p._choices)
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value '" << v << "', "
				<< "other than one of the values [";

			bool first = true;
			for(const T& choice : *_choices)
			{
				log << (first?"":", ") << "'" << choice << "'";
				first = false;
			}
			log	<< "] is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value other than one of specified choices is invalid"
			);
		}
	};
};

template <typename T, typename Range>
using valid_if_in_list = valid_if<T, valid_if_in_list_policy<T, Range>>;

} // namespace eagine

#endif // include guard
