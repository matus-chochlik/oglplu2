/**
 *  @file eagine/vect/abs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_ABS_1509260923_HPP
#define EAGINE_VECT_ABS_1509260923_HPP

#include "data.hpp"
#include <cmath>

namespace eagine {
namespace vect {

template <typename T, unsigned N, bool V>
struct abs
{
	static
	data_t<T, N, V>
	apply(data_t<T, N, V> v)
	noexcept
	{
		for(unsigned i=0; i<N; ++i)
		{
			using std::abs;
			v[i] = abs(v[i]);
		}
		return v;
	}
};

} // namespace vect
} // namespace eagine

#endif //include guard

