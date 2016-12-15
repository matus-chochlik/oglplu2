/**
 *  @file eagine/vect/diff.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_DIFF_1509260923_HPP
#define EAGINE_VECT_DIFF_1509260923_HPP

#include "abs.hpp"

namespace eagine {
namespace vect {

template <typename T, int N, bool V>
struct diff
{
	typedef data_t<T, N, V> _dT;
	typedef data_param_t<T, N, V> _dpT;

	static
	_dT apply(_dpT a, _dpT b)
	noexcept {
		return vect::abs<T, N, V>::apply(a-b);
	}
};

// TODO: some optimizations ?

} // namespace vect
} // namespace eagine

#endif //include guard

