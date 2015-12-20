/**
 *  @file eagine/bitfield.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BITFIELD_1509260923_HPP
#define EAGINE_BITFIELD_1509260923_HPP

#include "type_traits.hpp"

namespace eagine {

template <typename Bit>
class bitfield
{
private:
	typedef std::underlying_type_t<Bit> BF;
	BF _bits;
public:
	typedef BF value_type;

	constexpr
	bitfield(void)
	 : _bits(0)
	{ }

	constexpr explicit
	bitfield(BF bits)
	 : _bits(bits)
	{ }

	constexpr
	bitfield(Bit _bit)
	 : _bits(BF(_bit))
	{ }

	constexpr
	bitfield(Bit _bit_a, Bit _bit_b)
	 : _bits(BF(_bit_a) | BF(_bit_b))
	{ }

	explicit constexpr inline
	operator value_type(void) const
	noexcept
	{
		return _bits;
	}

	constexpr inline
	bool has(Bit bit) const
	noexcept
	{
		return (_bits & BF(bit)) == BF(bit);
	}

	friend constexpr inline
	bool operator == (bitfield a, bitfield b)
	noexcept
	{
		return a._bits == b._bits;
	}

	friend constexpr inline
	bool operator != (bitfield a, bitfield b)
	noexcept
	{
		return a._bits != b._bits;
	}

	friend constexpr inline
	bitfield operator | (bitfield a, bitfield b)
	noexcept
	{
		return bitfield{a._bits | b._bits};
	}

	friend constexpr inline
	bitfield operator & (bitfield a, bitfield b)
	noexcept
	{
		return bitfield{a._bits & b._bits};
	}
};

} // namespace eagine

#endif // include guard
