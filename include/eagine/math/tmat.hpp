/**
 *  @file eagine/math/tmat.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_TMAT_1509260923_HPP
#define EAGINE_MATH_TMAT_1509260923_HPP

#include "matrix.hpp"
#include "matrix_identity.hpp"
#include "../all_are_same.hpp"

namespace eagine {
namespace math {

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct tmat : matrix<T, C, R, RM, V>
{
private:
	typedef matrix<T, C, R, RM, V> _base;
public:
	constexpr inline
	tmat(void)
	noexcept
	 : _base(identity<_base>())
	{ }

	constexpr inline
	tmat(const _base& m)
	noexcept
	 : _base(m)
	{ }

	inline
	tmat(const T* d, unsigned n)
	noexcept
	 : _base(_base::from(d, n))
	{ }

	inline
	tmat(const T(&d)[C*R])
	noexcept
	 : _base(_base::from(d, C*R))
	{ }
private:
	template <
		typename ... P,
		typename = std::enable_if_t<
			((sizeof...(P)) == (C*R)) &&
			all_are_convertible_to<T, P...>::value
		>
	>
	static inline
	_base _make(P&& ... p)
	{
		T d[C*R] = {T(p)...};
		return _base::from(d, C*R);
	}
public:
	template <
		typename ... P,
		typename = std::enable_if_t<
			((sizeof...(P)) == (R*C)) &&
			all_are_convertible_to<T, P...>::value
		>
	>
	inline
	tmat(P&& ... p)
	 : _base(_make(std::forward<P>(p)...))
	{ }

	template <
		typename ... P,
		typename = std::enable_if_t<((sizeof...(P)) == (RM?R:C))>
	>
	constexpr inline
	tmat(const vector<P, RM?C:R, V>&... v)
	noexcept
	 : _base{{v._v...}}
	{ }

	template <
		typename P,
		unsigned M,
		unsigned N,
		typename = std::enable_if_t<
			std::is_convertible<P,T>::value &&
			(C<=M) && (R<=N)
		>
	>
	constexpr inline
	tmat(const matrix<P,M,N,RM,V>& m)
	noexcept
	 : _base(_base::from(m))
	{ }
};

} // namespace math

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct is_known_matrix_type<math::tmat<T, C, R, RM, V>>
 : std::is_scalar<T>
{ };

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct canonical_compound_type<math::tmat<T, C, R, RM, V>>
 : identity<std::remove_cv_t<T[C][R]>>
{ };

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct compound_view_maker<math::tmat<T, C, R, RM, V>>
{
	inline
	auto operator()(const math::tmat<T, C, R, RM, V>& m) const
	noexcept
	{
		return vect::view<T, RM?C:R, V>::apply(m._v);
	}
};

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct is_row_major<math::tmat<T,C,R,RM,V>>
 : bool_constant<RM>
{ };


} // namespace eagine

#endif //include guard

