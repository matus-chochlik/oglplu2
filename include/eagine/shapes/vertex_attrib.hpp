/**
 *  @file eagine/shapes/vertex_attrib.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_VERTEX_ATTRIB_1509260923_HPP
#define EAGINE_SHAPES_VERTEX_ATTRIB_1509260923_HPP

#include "../bitfield.hpp"
#include "../all_are_same.hpp"
#include "../type_traits.hpp"
#include "../int_sequence.hpp"
#include <array>

namespace eagine {
namespace shapes {

enum class vertex_attrib_kind : unsigned
{
	position       = 1 <<  0,
	normal         = 1 <<  1,
	tangential     = 1 <<  2,
	bitangential   = 1 <<  3,
	box_coord      = 1 <<  4,
	wrap_coord     = 1 <<  5,
	face_coord     = 1 <<  6
};

typedef bitfield<vertex_attrib_kind> vertex_attrib_bits;

// vertex_attrib_kind | vertex_attrib_kind 
static constexpr inline
vertex_attrib_bits
operator | (vertex_attrib_kind a, vertex_attrib_kind b)
noexcept
{
	return {a, b};
}

// vertex_attrib_and_location
struct vertex_attrib_and_location
{
	vertex_attrib_kind attrib;
	int location;

	operator std::array<const vertex_attrib_and_location, 1> (void) const
	noexcept
	{
		return {{*this}};
	}
};

// vertex_attrib_kind | location
static constexpr inline
vertex_attrib_and_location
operator | (vertex_attrib_kind attrib, int location)
noexcept
{
	return {attrib, location};
}

// vertex_attrib_and_location + vertex_attrib_and_location 
static constexpr inline
std::array<const vertex_attrib_and_location, 2>
operator + (
	const vertex_attrib_and_location& a,
	const vertex_attrib_and_location& b
) noexcept
{
	return {{a, b}};
}

// vertex_attrib_kind + vertex_attrib_kind
static constexpr inline
std::array<const vertex_attrib_and_location, 2>
operator + (vertex_attrib_kind a, vertex_attrib_kind b)
noexcept
{
	return (a|0)+(b|1);
}

// append_attrib
template <std::size_t N, std::size_t ... I>
static constexpr inline
std::array<const vertex_attrib_and_location, N+1>
do_append_attrib(
	const std::array<const vertex_attrib_and_location, N>& a,
	const vertex_attrib_and_location& b,
	std::index_sequence<I...>
) noexcept
{
	return {{a[I]..., b}};
}

// array<vertex_attrib_and_location, N> + vertex_attrib_and_location 
template <std::size_t N>
static constexpr inline
std::array<const vertex_attrib_and_location, N+1>
operator + (
	const std::array<const vertex_attrib_and_location, N>& a,
	const vertex_attrib_and_location& b
) noexcept
{
	return do_append_attrib(a, b, std::make_index_sequence<N>());
}

// array<vertex_attrib_kind> + vertex_attrib_kind
template <std::size_t N>
static constexpr inline
std::array<const vertex_attrib_and_location, N+1>
operator + (
	std::array<const vertex_attrib_and_location, N> a,
	vertex_attrib_kind b
) noexcept
{
	return a+(b|N);
}

// get_attrib_bits
template <std::size_t N>
static inline
vertex_attrib_bits
get_attrib_bits(const std::array<const vertex_attrib_and_location, N>& vaals)
noexcept
{
	vertex_attrib_bits res;

	for(const vertex_attrib_and_location& vaal: vaals)
	{
		res = res | vaal.attrib;
	}

	return res;
}

// attrib_values_per_vertex
static inline
unsigned
attrib_values_per_vertex(vertex_attrib_kind attr)
noexcept
{
	switch(attr)
	{
		case vertex_attrib_kind::position:
		case vertex_attrib_kind::normal:
		case vertex_attrib_kind::tangential:
		case vertex_attrib_kind::bitangential:
		case vertex_attrib_kind::face_coord:
		case vertex_attrib_kind::box_coord:
			return 3u;
		case vertex_attrib_kind::wrap_coord:
			return 2u;
	}
	return 0u;
}

} // namespace shapes
} // namespace eagine

#endif // include guard
