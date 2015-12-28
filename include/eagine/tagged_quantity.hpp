/**
 *  @file eagine/tagged_quantity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TAGGED_QUANTITY_1509260923_HPP
#define EAGINE_TAGGED_QUANTITY_1509260923_HPP

#include "type_traits.hpp"
#include "units/default.hpp"
#include <cmath>

namespace eagine {

template <typename T, typename U>
class tagged_quantity
{
private:
	static_assert(std::is_arithmetic<T>::value, "");
	T _v;

	template <typename, typename>
	friend class tagged_quantity;
public:
	typedef U unit_type;
	typedef T value_type;

	tagged_quantity(void) = default;

	explicit constexpr inline
	tagged_quantity(T v)
	noexcept
	 : _v(v)
	{ }

	template <
		typename X,
		typename UX,
		typename = std::enable_if_t<
			std::is_convertible<X, T>::value &&
			units::is_convertible<UX, U>::value
		>
	>
	constexpr inline
	tagged_quantity(tagged_quantity<X, UX> tq)
	noexcept
	 : _v(units::value_conv<UX, U>()(tq._v))
	{ }

	constexpr inline
	T value(void) const
	noexcept
	{
		return _v;
	}

	template <
		typename X,
		typename = std::enable_if_t<std::is_convertible<T, X>::value>
	>
	explicit constexpr inline
	operator X (void) const
	noexcept
	{
		return X(_v);
	}

	template <
		typename X,
		typename UX,
		typename = std::enable_if_t<
			std::is_convertible<X, T>::value &&
			units::is_convertible<UX, U>::value
		>
	>
	tagged_quantity& operator += (const tagged_quantity<X, UX>& q)
	noexcept
	{
		_v += units::value_conv<UX, U>()(q._v);
		return *this;
	}

	template <
		typename X,
		typename UX,
		typename = std::enable_if_t<
			std::is_convertible<X, T>::value &&
			units::is_convertible<UX, U>::value
		>
	>
	tagged_quantity& operator -= (const tagged_quantity<X, UX>& q)
	noexcept
	{
		_v -= units::value_conv<UX, U>()(q._v);
		return *this;
	}
};

template <typename T, typename U>
static inline T value(const tagged_quantity<T, U>& q)
{
	return q.value();
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator == (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	return value(a) == units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator != (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	return value(a) != units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator <  (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	return value(a) <  units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator <= (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	return value(a) <= units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator >  (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	return value(a) >  units::value_conv<U2, U1>()(value(b));
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
std::enable_if_t<units::is_convertible_v<U2, U1>, bool>
operator >= (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	return value(a) >= units::value_conv<U2, U1>()(value(b));
}

template <typename T, typename U>
constexpr inline
tagged_quantity<T, U>
operator + (const tagged_quantity<T, U>& a)
{
	return tagged_quantity<T, U>{value(a)};
}

template <typename T, typename U>
constexpr inline
tagged_quantity<T, U>
operator - (const tagged_quantity<T, U>& a)
{
	return tagged_quantity<T, U>{-value(a)};
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
tagged_quantity<decltype(T1()+T2()), units::add_result_t<U1, U2>>
operator + (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	typedef units::add_result_t<U1, U2> UR;
	return tagged_quantity<decltype(T1()+T2()), UR>{
		units::value_conv<U1, UR>()(value(a))+
		units::value_conv<U2, UR>()(value(b))
	};
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
tagged_quantity<decltype(T1()-T2()), units::sub_result_t<U1, U2>>
operator - (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	typedef units::sub_result_t<U1, U2> UR;
	return tagged_quantity<decltype(T1()-T2()), UR>{
		units::value_conv<U1, UR>()(value(a))-
		units::value_conv<U2, UR>()(value(b))
	};
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
tagged_quantity<decltype(T1()*T2()), units::mul_result_t<U1, U2>>
operator * (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	typedef units::mul_result_t<U1, U2> UR;
	return tagged_quantity<decltype(T1()*T2()), UR>{
		units::value_conv<U1, UR>()(value(a))*
		units::value_conv<U2, UR>()(value(b))
	};
}

template <typename T1, typename U, typename T2>
constexpr inline
tagged_quantity<decltype(T1()*T2()), U>
operator * (const tagged_quantity<T1, U>& a, const T2& c)
{
	return tagged_quantity<decltype(T1()*T2()), U>{value(a) * c};
}

template <typename T1, typename T2, typename U>
constexpr inline
tagged_quantity<decltype(T1()*T2()), U>
operator * (const T1& c, const tagged_quantity<T2, U>& a)
{
	return tagged_quantity<decltype(T1()*T2()), U>{c* value(a)};
}

template <typename T1, typename U1, typename T2, typename U2>
constexpr inline
tagged_quantity<decltype(T1()/T2()), units::div_result_t<U1, U2>>
operator / (
	const tagged_quantity<T1, U1>& a,
	const tagged_quantity<T2, U2>& b
)
{
	typedef units::div_result_t<U1, U2> UR;
	return tagged_quantity<decltype(T1()/T2()), UR>{
		units::value_conv<U1, UR>()(value(a))/
		units::value_conv<U2, UR>()(value(b))
	};
}

template <typename T1, typename U, typename T2>
constexpr inline
tagged_quantity<decltype(T1()/T2()), U>
operator / (const tagged_quantity<T1, U>& a, const T2& c)
{
	return tagged_quantity<decltype(T1()/T2()), U>{value(a) / c};
}

} // namespace eagine

#endif // include guard
