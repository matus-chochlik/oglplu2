/**
 *  @file eagine/attrib_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ATTRIB_LIST_1509260923_HPP
#define EAGINE_ATTRIB_LIST_1509260923_HPP

#include <array>
#include "span.hpp"
#include "type_traits.hpp"
#include "int_sequence.hpp"

namespace eagine {

template <typename Traits, std::size_t N = 0>
class attribute_list;

template <typename Traits>
struct attribute_list_key_value
{
	typedef typename Traits::value_type value_type;

	value_type _key, _value;

	constexpr inline
	attribute_list_key_value(value_type key, value_type value)
	noexcept
	 : _key(key)
	 , _value(value)
	{ }
};

template <typename Traits, std::size_t N>
struct attribute_list_base;

template <typename Traits>
struct attribute_list_base<Traits, 0>
{
	typedef typename Traits::value_type value_type;

	static
	const value_type* data(void)
	noexcept
	{
		static const value_type term = Traits::terminator();
		return &term;
	}
};

template <typename Traits>
struct attribute_list_base<Traits, 2>
{
	std::array<typename Traits::value_type, 3> _elements;

	typedef typename Traits::value_type value_type;

	constexpr
	attribute_list_base(
		const attribute_list_base<Traits, 0>&,
		value_type key,
		value_type value,
		std::index_sequence<>
	) noexcept
	 : _elements{{key, value, Traits::terminator()}}
	{ }

	const value_type* data(void) const
	noexcept
	{
		return _elements.data();
	}
};

template <typename Traits, std::size_t N>
struct attribute_list_base
{
	std::array<typename Traits::value_type, N+1> _elements;

	typedef typename Traits::value_type value_type;

	template <
		std::size_t M,
		std::size_t ... I,
		typename = std::enable_if_t<(M+2 == N) && (sizeof...(I) == M)>
	>
	constexpr
	attribute_list_base(
		const attribute_list_base<Traits, M>& head,
		value_type key,
		value_type value,
		std::index_sequence<I...>
	) noexcept
	 : _elements{{head._elements[I]..., key, value, Traits::terminator()}}
	{ }

	const value_type* data(void) const
	noexcept
	{
		return _elements.data();
	}
};

template <typename Traits, std::size_t N>
class attribute_list
{
public:
	typedef typename Traits::value_type value_type;
private:
	attribute_list_base<Traits, N> _base;
public:
	attribute_list(void) = default;

	template <
		std::size_t M,
		typename = std::enable_if_t<M+2 == N>
	>
	constexpr
	attribute_list(
		const attribute_list_base<Traits, M>& head,
		value_type key,
		value_type value
	) noexcept
	 : _base(head, key, value, std::make_index_sequence<M>())
	{ }

	static constexpr inline
	std::size_t size(void)
	noexcept
	{
		return N+1;
	}

	const value_type* data(void) const
	noexcept
	{
		return _base.data();
	}

	span<const value_type> get(void) const
	noexcept
	{
		return {data(), span_size_type(size())};
	}

	constexpr
	attribute_list<Traits, N+2> append(
		const attribute_list_key_value<Traits>& key_val
	) noexcept
	{
		return {_base, key_val._key, key_val._value};
	}
};


} // namespace eagine

#endif // include guard
