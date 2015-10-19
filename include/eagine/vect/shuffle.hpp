/**
 *  @file eagine/vect/shuffle.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_SHUFFLE_1509260923_HPP
#define EAGINE_VECT_SHUFFLE_1509260923_HPP

#include "data.hpp"

namespace eagine {
namespace vect {

template <int ... I>
struct shuffle_mask
{ };

#if EAGINE_USE_SIMD && defined(__GNUC__) && !defined(__clang__)
template <typename T, unsigned N, bool V>
struct mask : _vec_data<T, N, V>
{ };

template <unsigned N, bool V>
struct mask<float, N, V> : _vec_data<std::int32_t, N, V>
{ };

template <unsigned N, bool V>
struct mask<double, N, V> : _vec_data<std::int64_t, N, V>
{ };
#endif

template <typename T, unsigned N, bool V>
struct shuffle
{
private:
	typedef data_t<T, N, V> _dT;
	typedef data_param_t<T, N, V> _dpT;

	template <int ... I>
	static constexpr inline
	_dT _do_apply(
		_dpT v,
		shuffle_mask<I...>,
		std::false_type
	) noexcept
	{
		return data_t<T, N, V>{v[I]...};
	}

	template <int ... I>
	static constexpr inline
	_dT _do_apply(
		_dpT v,
		shuffle_mask<I...>,
		std::true_type
	) noexcept
	{
#if EAGINE_USE_SIMD && defined(__clang__)
		return _dT(__builtin_shufflevector(v, v, I...));
#elif EAGINE_USE_SIMD && defined(__GNUC__)
		typedef typename mask<T, N, V>::type _mT;
		return __builtin_shuffle(v, _mT{I...});
#else
		return _do_apply(
			v,
			shuffle_mask<I...>(),
			std::false_type()
		);
#endif
	}
public:
	template <int ... I>
	static constexpr inline
	_dT apply(
		_dpT v,
		shuffle_mask<I...> m = {}
	) noexcept
	{
		return _do_apply(v, m, has_vect_data<T, N, V>());
	}
};

template <typename T, unsigned N, bool V>
struct shuffle2
{
private:
	typedef typename data<T, N, V>::type _dT;
	typedef data_param_t<T, N, V> _dpT;

	template <unsigned U>
	using _uint = std::integral_constant<unsigned, U>;

	template <unsigned M, int ... I>
	static inline
	_dT _do_apply(
		_dpT v1,
		_dpT v2,
		shuffle_mask<I...>,
		_uint<M>,
		std::false_type
	) noexcept
	{
		return typename data<T, N, V>::type{
			I<0?T(0):(
				unsigned(I)<N?
					v1[unsigned(I)]:
					v2[unsigned(I)%N]
			)...
		};
	}

	template <unsigned M, int ... I>
	static inline
	_dT _do_apply(
		_dpT v1,
		_dpT v2,
		shuffle_mask<I...>,
		_uint<M>,
		std::true_type
	) noexcept
	{
#if EAGINE_USE_SIMD && defined(__clang__)
		return _dT(__builtin_shufflevector(v1,v2, I...));
#elif EAGINE_USE_SIMD && defined(__GNUC__)
		typedef typename mask<T, N, V>::type _mT;
		return __builtin_shuffle(v1, v2, _mT{I...});
#else
		return _do_apply(
			v1, v2,
			shuffle_mask<I...>(),
			_uint<M>(),
			std::false_type()
		);
#endif
	}

	template <int ... I>
	static inline
	_dT _do_apply(
		_dpT v1,
		_dpT v2,
		shuffle_mask<I...>,
		_uint<3u>,
		std::true_type
	) noexcept
	{
#if EAGINE_USE_SIMD && defined(__clang__)
		return _dT(__builtin_shufflevector(v1,v2, I>=3?I+1:I...));
#elif EAGINE_USE_SIMD && defined(__GNUC__)
		typedef typename mask<T, N, V>::type _mT;
		return __builtin_shuffle(v1, v2, _mT{(I>=3?I+1:I)...});
#else
		return _do_apply(
			v1, v2,
			shuffle_mask<I...>(),
			_uint<3>(),
			std::false_type()
		);
#endif
	}
public:

	template <int ... I>
	static inline
	_dT apply(
		_dpT v1,
		_dpT v2,
		shuffle_mask<I...> m = {}
	) noexcept
	{
		return _do_apply(
			v1, v2, m,
			_uint<N>(),
			has_vect_data<T, N, V>()
		);
	}
};

} // namespace vect
} // namespace eagine

#endif //include guard

