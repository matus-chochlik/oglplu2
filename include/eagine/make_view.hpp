/**
 *  @file eagine/make_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MAKE_VIEW_1509260923_HPP
#define EAGINE_MAKE_VIEW_1509260923_HPP

#include "array_view.hpp"

namespace eagine {

template <typename T>
static inline
array_view<T> make_view(T *data, std::size_t n)
noexcept
{
	return {data, n};
}

template <typename T, std::size_t N>
static inline
array_view<T> make_view(T (&data)[N])
noexcept
{
	return {data, N};
}

// TODO std::vector, std::array, ...

} // namespace eagine

#endif // include guard
