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
using valid_span_size_t = valid_if_nonnegative<span_size_t>;

// convert to std alignment type
static constexpr inline
std_align_t std_align(std_align_t v)
noexcept { return v; }

static constexpr inline
std_align_t std_align(span_size_t v)
noexcept {
	assert(v >= 0);
	assert(std_align_t(v) <= std::numeric_limits<std_align_t>::max());
	return static_cast<std_align_t>(v);
}

// convert to std size type
static constexpr inline
std_size_t std_size(std_size_t v)
noexcept { return v; }

static constexpr inline
std_size_t std_size(span_size_t v)
noexcept {
	assert(v >= 0);
	assert(std_size_t(v) <= std::numeric_limits<std_size_t>::max());
	return static_cast<std_size_t>(v);
}

// convert to span size type
static constexpr inline
span_size_t span_size(span_size_t v)
noexcept { return v; }

static constexpr inline
span_size_t span_size(std::size_t v)
noexcept {
	assert(v <= std::size_t(std::numeric_limits<span_size_t>::max()));
	return static_cast<span_size_t>(v);
}

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

template <typename T>
static constexpr inline
span_size_t span_size_of(span_size_t n)
noexcept {
	return span_size(sizeof(T))*n;
}

template <typename T>
static constexpr inline
span_size_t span_size_of(std::size_t n)
noexcept {
	return span_size(sizeof(T)*n);
}

} // namespace eagine

#endif // include guard
