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
#include "identity.hpp"
#include <initializer_list>
#include <type_traits>

namespace eagine {

template <typename T>
static inline
array_view<T>
make_view(identity<T> = {})
noexcept
{
	return {nullptr, 0};
}

template <typename T>
static inline
array_view<T>
make_view(T *data, std::size_t n)
noexcept
{
	return {data, n};
}

template <typename T, std::size_t N>
static inline
array_view<T>
make_view(T (&data)[N])
noexcept
{
	return {data, N};
}

template <typename T>
static inline
array_view<const T>
make_view(std::initializer_list<T> il)
noexcept
{
	return {il.begin(), il.size()};
}

template <typename Container, typename V = typename Container::value_type>
static inline
array_view<V>
make_view(Container& c)
noexcept
{
	return {c.data(), c.size()};
}

template <typename Container, typename P = typename Container::const_pointer>
static inline
array_view<typename std::remove_pointer<P>::type>
make_view(const Container& c)
noexcept
{
	return {c.data(), c.size()};
}

} // namespace eagine

#endif // include guard
