/**
 *  @file eagine/byteset.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BYTESET_1509260923_HPP
#define EAGINE_BYTESET_1509260923_HPP

#include <eagine/types.hpp>
#include <eagine/memory_block.hpp>
#include <eagine/std/utility.hpp>
#include <eagine/std/type_traits.hpp>

namespace eagine {

template <std::size_t N>
class byteset {
public:
	static_assert(N > 0, "byteset size must be greater than zero");
	using size_type = span_size_t;
	using value_type = unsigned char;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;

	using iterator = value_type*;
	using const_iterator = const value_type*;

	constexpr
	byteset(void) = default;
	
	template <
		typename ... B,
		typename = std::enable_if_t<
			(sizeof...(B) == N) &&
			(sizeof...(B) != 0) &&
			std::conjunction_v<
				std::true_type,
				std::is_convertible<B, value_type>...
			>
		>
	>
	explicit constexpr inline
	byteset(B ... b)
	noexcept
	 : _bytes{value_type(b)...}
	{ }

	pointer data(void)
	noexcept { return _bytes; }

	constexpr
	const_pointer data(void) const
	noexcept { return _bytes; }

	constexpr
	size_type size(void) const
	noexcept { return N; }

	const_memory_block block(void) const
	noexcept { return {data(), size()}; }

	constexpr
	reference operator[](size_type i)
	noexcept { return _bytes[i]; }

	constexpr
	const_reference operator[](size_type i) const
	noexcept { return _bytes[i]; }

	constexpr
	reference front(void)
	noexcept { return _bytes[0]; }

	constexpr
	const_reference front(void) const
	noexcept { return _bytes[0]; }

	constexpr
	reference back(void)
	noexcept { return _bytes[N-1]; }

	constexpr
	const_reference back(void) const
	noexcept { return _bytes[N-1]; }

	iterator begin(void)
	noexcept { return _bytes+0; }

	iterator end(void)
	noexcept { return _bytes+N; }

	constexpr
	const_iterator begin(void) const
	noexcept { return _bytes+0; }

	constexpr
	const_iterator end(void) const
	noexcept { return _bytes+N; }

	friend constexpr inline
	int compare(const byteset& a, const byteset& b)
	noexcept { return _do_cmp(a, b, std::make_index_sequence<N>{}); }

	friend constexpr inline
	bool operator == (const byteset& a, const byteset& b)
	noexcept { return compare(a, b) == 0; }

	friend constexpr inline
	bool operator != (const byteset& a, const byteset& b)
	noexcept { return compare(a, b) != 0; }

	friend constexpr inline
	bool operator <  (const byteset& a, const byteset& b)
	noexcept { return compare(a, b) <  0; }

	friend constexpr inline
	bool operator <= (const byteset& a, const byteset& b)
	noexcept { return compare(a, b) <= 0; }

	friend constexpr inline
	bool operator >  (const byteset& a, const byteset& b)
	noexcept { return compare(a, b) >  0; }

	friend constexpr inline
	bool operator >= (const byteset& a, const byteset& b)
	noexcept { return compare(a, b) >= 0; }
private:
	value_type _bytes[N];

	static constexpr inline
	int _cmp_byte(value_type a, value_type b)
	noexcept { return (a == b)?0:(a < b)?-1:1; }

	static constexpr inline
	int _do_cmp(
		const byteset&,
		const byteset&,
		std::index_sequence<>
	) noexcept { return 0; }

	template <std::size_t I, std::size_t ... In>
	static constexpr inline
	int _do_cmp(
		const byteset& a,
		const byteset& b,
		std::index_sequence<I, In...>
	) {
		return (a._bytes[I] == b._bytes[I])?
			_do_cmp(a, b, std::index_sequence<In...>{}):
			_cmp_byte(a._bytes[I], b._bytes[I]);
	}
};

} // namespace eagine

#endif // include guard
