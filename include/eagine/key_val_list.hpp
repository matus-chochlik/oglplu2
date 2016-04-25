/**
 *  @file eagine/key_val_list.hpp
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
class key_value_list;

template <typename Traits>
struct key_value_list_element
{
	typedef typename Traits::key_type key_type;
	typedef typename Traits::value_type value_type;

	key_type _key;
	value_type _value;

	constexpr inline
	key_value_list_element(key_type key, value_type value)
	noexcept
	 : _key(key)
	 , _value(value)
	{ }
};

template <typename Traits, std::size_t N>
struct key_value_list_base;

template <typename Traits>
struct key_value_list_base<Traits, 0>
{
	typedef typename Traits::value_type value_type;

	key_value_list_base(void) = default;

	static
	const value_type* data(void)
	noexcept
	{
		static const value_type term = Traits::terminator();
		return &term;
	}
};

template <typename Traits>
struct key_value_list_base<Traits, 2>
{
	std::array<typename Traits::value_type, 3> _elements;

	typedef typename Traits::key_type key_type;
	typedef typename Traits::conv_type conv_type;
	typedef typename Traits::value_type value_type;

	constexpr
	key_value_list_base(key_type key, value_type value)
	noexcept
	 : _elements{{value_type(conv_type(key)), value, Traits::terminator()}}
	{ }

	constexpr
	key_value_list_base(
		const key_value_list_base<Traits, 0>&,
		key_type key,
		value_type value,
		std::index_sequence<>
	) noexcept
	 : _elements{{value_type(conv_type(key)), value, Traits::terminator()}}
	{ }

	const value_type* data(void) const
	noexcept
	{
		return _elements.data();
	}
};

template <typename Traits, std::size_t N>
struct key_value_list_base
{
	std::array<typename Traits::value_type, N+1> _elements;

	typedef typename Traits::key_type key_type;
	typedef typename Traits::conv_type conv_type;
	typedef typename Traits::value_type value_type;

	template <
		std::size_t M,
		std::size_t ... I,
		typename = std::enable_if_t<(M+2 == N) && (sizeof...(I) == M)>
	>
	constexpr
	key_value_list_base(
		const key_value_list_base<Traits, M>& head,
		key_type key,
		value_type value,
		std::index_sequence<I...>
	) noexcept
	 : _elements{{
		head._elements[I]...,
		value_type(conv_type(key)), value,
		Traits::terminator()
	}}
	{ }

	const value_type* data(void) const
	noexcept
	{
		return _elements.data();
	}
};

template <typename Traits, std::size_t N>
class key_value_list
{
public:
	typedef typename Traits::key_type key_type;
	typedef typename Traits::value_type value_type;
private:
	key_value_list_base<Traits, N> _base;
public:
	key_value_list(void) = default;

	template <
		std::size_t M,
		typename = std::enable_if_t<M+2 == N>
	>
	constexpr
	key_value_list(
		const key_value_list_base<Traits, M>& head,
		key_type key,
		value_type value
	) noexcept
	 : _base(head, key, value, std::make_index_sequence<M>())
	{ }

	key_value_list(const key_value_list_element<Traits>& head)
	noexcept
	 : _base(head._key, head._value)
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
	key_value_list<Traits, N+2> append(
		const key_value_list_element<Traits>& key_val
	) const
	noexcept
	{
		return {_base, key_val._key, key_val._value};
	}
};

template <typename Traits>
static constexpr inline
key_value_list<Traits, 4> operator + (
	const key_value_list_element<Traits>& l,
	const key_value_list_element<Traits>& r
) noexcept
{
	return key_value_list<Traits, 2>(l).append(r);
}

template <typename Traits, std::size_t N>
static constexpr inline
key_value_list<Traits, N+2> operator + (
	const key_value_list<Traits, N>& l,
	const key_value_list_element<Traits>& r
) noexcept
{
	return l.append(r);
}

} // namespace eagine

#endif // include guard
