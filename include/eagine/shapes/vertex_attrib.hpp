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

#include "../bitfield.hpp"
#include "../types.hpp"
#include <array>
#include <cstdint>
#include <type_traits>
#include <utility>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
enum class vertex_attrib_kind : std::uint16_t {
    object_id = 1U << 0U,
    position = 1U << 1U,
    normal = 1U << 2U,
    tangential = 1U << 3U,
    bitangential = 1U << 4U,
    pivot = 1U << 5U,
    vertex_pivot = 1U << 6U,
    box_coord = 1U << 7U,
    face_coord = 1U << 8U,
    wrap_coord = 1U << 9U,
    color = 1U << 10U,
    emission = 1U << 11U,
    weight = 1U << 12U,
    occlusion = 1U << 13U,
    material_id = 1U << 14U
    // also fix all_vertex_attrib_bits
};
//------------------------------------------------------------------------------
using vertex_attrib_bits = bitfield<vertex_attrib_kind>;
//------------------------------------------------------------------------------
static constexpr inline auto all_vertex_attrib_bits() noexcept {
    return vertex_attrib_bits{(1u << 15u) - 1u};
}
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
// + vertex_attrib_and_location
static constexpr inline vertex_attribs_and_locations<1> operator+(
  const vertex_attrib_and_location& a) noexcept {
    return {{a}};
}
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
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::emission:
            return 4;
        case vertex_attrib_kind::position:
        case vertex_attrib_kind::normal:
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::box_coord:
            return 3;
        case vertex_attrib_kind::wrap_coord:
            return 2;
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::occlusion:
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
