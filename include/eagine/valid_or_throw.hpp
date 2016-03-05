/**
 *  @file eagine/valid_or_throw.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_OR_THROW_1509260923_HPP
#define EAGINE_VALID_OR_THROW_1509260923_HPP

#include "valid_if.hpp"
#include <stdexcept>
#include <sstream>

namespace eagine {

template <typename T, typename P, typename A, typename L>
inline
valid_if<T, P, A, L>&
valid_or_throw(valid_if<T, P, A, L>& vi)
{
	vi.call_if_invalid(
		[](const L& do_log, const T& v)
		{
			std::stringstream ss;
			do_log(ss, v);
			throw std::runtime_error(ss.str());
		}
	);
	return vi;
}

template <typename T, typename C, typename P, typename A, typename L>
inline
in_class_valid_if<T, C, P, A, L>&
valid_or_throw(in_class_valid_if<T, C, P, A, L>& vi, const C& cls)
{
	vi.call_if_invalid(
		[](const L& do_log, const T& v, const C& c)
		{
			std::stringstream ss;
			do_log(ss, v, c);
			throw std::runtime_error(ss.str());
		}, cls
	);
	return vi;
}

} // namespace eagine

#endif // include guard
