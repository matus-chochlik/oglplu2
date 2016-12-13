/**
 *  @file eagine/types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPES_1509260923_HPP
#define EAGINE_TYPES_1509260923_HPP

#include <limits>
#include <cstdint>
#include <cassert>
#include "span_fwd.hpp"
#include "type_traits.hpp"
#include "valid_if/nonnegative.hpp"

namespace eagine {

// byte type
typedef unsigned char byte;

// alignment type used by std
using std_align_t = std::size_t ;
// size type used by std
using std_size_t = std::size_t ;
// signed size type
using span_size_t = std::ptrdiff_t;
// valid size type
using valid_span_size = valid_if_nonnegative<span_size_t>;

template <typename T>
static constexpr inline
T safe_size_t_cast(T v)
noexcept { return v; }

template <
	typename T,
	typename F,
	typename = std::enable_if_t<
		std::is_integral<F>::value &&
		!std::is_same<T, F>::value
	>
> static constexpr inline
T safe_size_t_cast(F v)
noexcept {
	assert(T(v) >= std::numeric_limits<T>::min());
	assert(T(v) <= std::numeric_limits<T>::max());
	return static_cast<T>(v);
}


// convert to std alignment type
template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
static constexpr inline
std_align_t std_align(T v)
noexcept { return safe_size_t_cast<std_align_t>(v); }

// convert to std size type
template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
static constexpr inline
std_size_t std_size(T v)
noexcept { return safe_size_t_cast<std_size_t>(v); }

// convert to span size type
template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
static constexpr inline
span_size_t span_size(T v)
noexcept { return safe_size_t_cast<span_size_t>(v); }

template <typename T>
static constexpr inline
span_size_t span_align_of(void)
noexcept {
	return span_size(alignof(T));
}

template <typename T>
static constexpr inline
span_size_t span_size_of(void)
noexcept {
	return span_size(sizeof(T));
}

template <typename T, typename S>
static constexpr inline
span_size_t span_size_of(S n)
noexcept {
	return span_size(sizeof(T))*span_size(n);
}

// range_index_type
template <typename R>
struct range_index_type
{
	using type = typename R::size_type;
};

template <typename T, span_size_t I>
struct range_index_type<gsl::span<T, I>>
{
	using type = span_size_t;
};

template <typename T, span_size_t I>
struct range_index_type<gsl::basic_string_span<T, I>>
{
	using type = span_size_t;
};

template <typename R>
using range_index_t = typename range_index_type<R>::type;

template <typename R, typename T>
static constexpr inline
range_index_t<R> range_index(T i)
noexcept { return safe_size_t_cast<range_index_t<R>>(i); }

} // namespace eagine

#endif // include guard
