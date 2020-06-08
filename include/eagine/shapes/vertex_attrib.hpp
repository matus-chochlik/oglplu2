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
#include "../reflect/map_enumerators.hpp"
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
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<vertex_attrib_kind>, Selector) noexcept {
    return enumerator_map_type<vertex_attrib_kind, 15>{
      {{"object_id", vertex_attrib_kind::object_id},
       {"position", vertex_attrib_kind::position},
       {"normal", vertex_attrib_kind::normal},
       {"tangential", vertex_attrib_kind::tangential},
       {"bitangential", vertex_attrib_kind::bitangential},
       {"pivot", vertex_attrib_kind::pivot},
       {"vertex_pivot", vertex_attrib_kind::vertex_pivot},
       {"box_coord", vertex_attrib_kind::box_coord},
       {"face_coord", vertex_attrib_kind::face_coord},
       {"wrap_coord", vertex_attrib_kind::wrap_coord},
       {"color", vertex_attrib_kind::color},
       {"emission", vertex_attrib_kind::emission},
       {"weight", vertex_attrib_kind::weight},
       {"occlusion", vertex_attrib_kind::occlusion},
       {"material_id", vertex_attrib_kind::material_id}}};
}
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
// vertex_attrib_variant
struct vertex_attrib_variant {
    vertex_attrib_kind attrib;
    std::int16_t _index{0};

    constexpr vertex_attrib_variant(vertex_attrib_kind a)
      : attrib{a} {
    }

    constexpr vertex_attrib_variant(vertex_attrib_kind a, span_size_t v)
      : attrib{a}
      , _index{std::int16_t(v)} {
    }

    constexpr vertex_attrib_variant(
      vertex_attrib_kind a, vertex_attrib_variant vav)
      : attrib{a}
      , _index{vav._index} {
    }

    constexpr bool has_valid_index() const noexcept {
        return _index >= 0;
    }

    constexpr span_size_t index() const noexcept {
        return _index;
    }

    constexpr operator std::array<const vertex_attrib_variant, 1>() const
      noexcept {
        return {{*this}};
    }

    friend constexpr bool operator==(
      vertex_attrib_variant l, vertex_attrib_kind r) noexcept {
        return l.attrib == r;
    }

    friend constexpr bool operator!=(
      vertex_attrib_variant l, vertex_attrib_kind r) noexcept {
        return l.attrib != r;
    }
};
//------------------------------------------------------------------------------
// vertex_attrib_kind / variant_index{}
static constexpr inline vertex_attrib_variant operator/(
  vertex_attrib_kind attrib, span_size_t variant_index) noexcept {
    return {attrib, variant_index};
}
//------------------------------------------------------------------------------
template <std::size_t N>
using vertex_attrib_variants = std::array<const vertex_attrib_variant, N>;
//------------------------------------------------------------------------------
// + vertex_attrib_variant
static constexpr inline vertex_attrib_variants<1> operator+(
  vertex_attrib_variant a) noexcept {
    return {{a}};
}
//------------------------------------------------------------------------------
// vertex_attrib_variant + vertex_attrib_variant
static constexpr inline vertex_attrib_variants<2> operator+(
  vertex_attrib_variant a, vertex_attrib_variant b) noexcept {
    return {{a, b}};
}
//------------------------------------------------------------------------------
// append_attrib
template <std::size_t N, std::size_t... I>
static constexpr inline vertex_attrib_variants<N + 1> do_append_attrib(
  const vertex_attrib_variants<N>& a,
  vertex_attrib_variant b,
  std::index_sequence<I...>) noexcept {
    return {{a[I]..., b}};
}
//------------------------------------------------------------------------------
// array<vertex_attrib_variant, N> + vertex_attrib_variant
template <std::size_t N>
static constexpr inline vertex_attrib_variants<N + 1> operator+(
  const vertex_attrib_variants<N>& a, vertex_attrib_variant b) noexcept {
    return do_append_attrib(a, b, std::make_index_sequence<N>());
}
//------------------------------------------------------------------------------
// get_attrib_bits
template <std::size_t N>
static inline vertex_attrib_bits get_attrib_bits(
  const vertex_attrib_variants<N>& vaals) noexcept {
    vertex_attrib_bits res;

    for(const vertex_attrib_variant& vaal : vaals) {
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
static inline span_size_t attrib_values_per_vertex(
  vertex_attrib_variant vav) noexcept {
    return attrib_values_per_vertex(vav.attrib);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_VERTEX_ATTRIB_HPP
