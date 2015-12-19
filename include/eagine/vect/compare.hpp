/**
 *  @file eagine/vect/compare.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_COMPARE_1509260923_HPP
#define EAGINE_VECT_COMPARE_1509260923_HPP

#include "data.hpp"

namespace eagine {
namespace vect {

template <typename T, unsigned N, bool V>
struct is_zero
{
	typedef data_t<T, N, V> _dT;
	typedef data_param_t<T, N, V> _dpT;

	static
	bool apply(_dpT v)
	noexcept
	{
		for(unsigned i=0; i<N; ++i)
		{
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"
#endif
			if(v[i] != 0)
#ifdef __clang__
#pragma clang diagnostic pop 
#endif
			{
				return false;
			}
		}
		return true;
	}
};

// TODO: some optimizations ?

} // namespace vect
} // namespace eagine

#endif //include guard

