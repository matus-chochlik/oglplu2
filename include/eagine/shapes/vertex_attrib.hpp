/**
 *  @file eagine/shapes/vertex_attrib.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_VERTEX_ATTRIB_HPP
#define EAGINE_SHAPES_VERTEX_ATTRIB_HPP

#include "../all_are_same.hpp"
#include "../bitfield.hpp"
#include "../types.hpp"
#include <array>
#include <type_traits>
#include <utility>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
enum class vertex_attrib_kind : unsigned {
    object_id = 1 << 0,
    position = 1 << 1,
    normal = 1 << 2,
    tangential = 1 << 3,
    bitangential = 1 << 4,
    pivot = 1 << 5,
    box_coord = 1 << 6,
    face_coord = 1 << 7,
    wrap_coord_0 = 1 << 8,
    wrap_coord_1 = 1 << 9,
    wrap_coord_2 = 1 << 10,
    wrap_coord_3 = 1 << 11,
    material_id = 1 << 12
};
//------------------------------------------------------------------------------
using vertex_attrib_bits = bitfield<vertex_attrib_kind>;
//------------------------------------------------------------------------------
// vertex_attrib_kind | vertex_attrib_kind
static constexpr inline vertex_attrib_bits operator|(
  vertex_attrib_kind a, vertex_attrib_kind b) noexcept {
    return {a, b};
}
//------------------------------------------------------------------------------
// vertex_attrib_and_location
struct vertex_attrib_and_location {
    vertex_attrib_kind attrib;
    int location;

    operator std::array<const vertex_attrib_and_location, 1>() const noexcept {
        return {{*this}};
    }
};
//------------------------------------------------------------------------------
// vertex_attrib_kind | location
static constexpr inline vertex_attrib_and_location operator|(
  vertex_attrib_kind attrib, int location) noexcept {
    return {attrib, location};
}
//------------------------------------------------------------------------------
template <std::size_t N>
using vertex_attribs_and_locations =
  std::array<const vertex_attrib_and_location, N>;
//------------------------------------------------------------------------------
// vertex_attrib_and_location + vertex_attrib_and_location
static constexpr inline vertex_attribs_and_locations<2> operator+(
  const vertex_attrib_and_location& a,
  const vertex_attrib_and_location& b) noexcept {
    return {{a, b}};
}
//------------------------------------------------------------------------------
// vertex_attrib_kind + vertex_attrib_kind
static constexpr inline vertex_attribs_and_locations<2> operator+(
  vertex_attrib_kind a, vertex_attrib_kind b) noexcept {
    return (a | 0) + (b | 1);
}
//------------------------------------------------------------------------------
// append_attrib
template <std::size_t N, std::size_t... I>
static constexpr inline vertex_attribs_and_locations<N + 1> do_append_attrib(
  const vertex_attribs_and_locations<N>& a,
  const vertex_attrib_and_location& b,
  std::index_sequence<I...>) noexcept {
    return {{a[I]..., b}};
}
//------------------------------------------------------------------------------
// array<vertex_attrib_and_location, N> + vertex_attrib_and_location
template <std::size_t N>
static constexpr inline vertex_attribs_and_locations<N + 1> operator+(
  const vertex_attribs_and_locations<N>& a,
  const vertex_attrib_and_location& b) noexcept {
    return do_append_attrib(a, b, std::make_index_sequence<N>());
}
//------------------------------------------------------------------------------
// array<vertex_attrib_kind> + vertex_attrib_kind
template <std::size_t N>
static constexpr inline vertex_attribs_and_locations<N + 1> operator+(
  vertex_attribs_and_locations<N> a, vertex_attrib_kind b) noexcept {
    return a + (b | N);
}
//------------------------------------------------------------------------------
// get_attrib_bits
template <std::size_t N>
static inline vertex_attrib_bits get_attrib_bits(
  const vertex_attribs_and_locations<N>& vaals) noexcept {
    vertex_attrib_bits res;

    for(const vertex_attrib_and_location& vaal : vaals) {
        res = res | vaal.attrib;
    }

    return res;
}
//------------------------------------------------------------------------------
// attrib_values_per_vertex
static inline span_size_t attrib_values_per_vertex(
  vertex_attrib_kind attr) noexcept {
    switch(attr) {
        case vertex_attrib_kind::position:
        case vertex_attrib_kind::normal:
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::box_coord:
            return 3;
        case vertex_attrib_kind::wrap_coord_0:
        case vertex_attrib_kind::wrap_coord_1:
        case vertex_attrib_kind::wrap_coord_2:
        case vertex_attrib_kind::wrap_coord_3:
            return 2;
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::material_id:
            return 1;
    }
    return 0;
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_VERTEX_ATTRIB_HPP
