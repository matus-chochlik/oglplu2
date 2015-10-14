/**
 *  @file eagine/vect/esum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_ESUM_1509260923_HPP
#define EAGINE_VECT_ESUM_1509260923_HPP

#include "config.hpp"
#if EAGINE_VECT_OPTS
#include "hsum.hpp"
#else
#include "data.hpp"
#endif

namespace eagine {
namespace vect {

template <typename T, unsigned N, bool V>
struct esum
{
private:
	typedef data_param_t<T, N, V> _dpT;

	template <unsigned U>
	using _uint = std::integral_constant<unsigned, U>;

	template <bool B>
	using _bool = std::integral_constant<bool, B>;

	template <unsigned M, bool B>
	static inline
	T _hlp(_dpT v, _uint<M>, _bool<B>)
	noexcept
	{
		static_assert(M == N, "");
		T r = T(0);
		for(unsigned i=0; i<N; ++i)
		{
			r += v[i];
		}
		return r;
	}

#if EAGINE_VECT_OPTS
	template <bool B>
	static constexpr inline
	T _hlp(_dpT v, _uint<1>, _bool<B>)
	noexcept
	{
		return v[0];
	}

	template <unsigned M>
	static inline
	T _hlp(_dpT v, _uint<M>, std::true_type)
	noexcept
	{
		static_assert(M == N, "");
		return hsum<T, N, V>::apply(v)[N-1];
	}
#endif
public:
	static inline
	T apply(_dpT v)
	noexcept
	{
		return _hlp(v, _uint<N>(), has_vect_data<T, N, V>());
	}
};

} // namespace vect
} // namespace eagine

#endif //include guard

