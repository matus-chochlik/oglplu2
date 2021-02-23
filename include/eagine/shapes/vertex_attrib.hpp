/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
/// @brief Shape vertex attribute kind enumeration.
/// @ingroup shapes
enum class vertex_attrib_kind : std::uint16_t {
    /// @brief The object id attributes (typically unique integer).
    object_id = 1U << 0U,
    /// @brief Vertex position.
    position = 1U << 1U,
    /// @brief Vertex normal vector.
    normal = 1U << 2U,
    /// @brief Vertex tangential vector.
    tangential = 1U << 3U,
    /// @brief Vertex bi-tangential vector.
    bitangential = 1U << 4U,
    /// @brief Shape pivot point.
    pivot = 1U << 5U,
    /// @brief Pivot of vertex pivot point.
    pivot_pivot = 1U << 6U,
    /// @brief Vertex pivot point.
    vertex_pivot = 1U << 7U,
    /// @brief Normalized coordinate within shape bounding box.
    box_coord = 1U << 8U,
    /// @brief Generic face coordinate.
    face_coord = 1U << 9U,
    /// @brief UV-texture wrapping coordinate.
    wrap_coord = 1U << 10U,
    /// @brief Vertex color value.
    color = 1U << 11U,
    /// @brief Generic vertex weight value.
    weight = 1U << 12U,
    /// @brief Vertex (ambient) light occlusion value.
    occlusion = 1U << 13U,
    /// @brief Face polygon id value (multiple faces can belong to the same polygon)
    polygon_id = 1U << 14U,
    /// @brief Face material id value.
    material_id = 1U << 15U
    // also fix all_vertex_attrib_bits
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<vertex_attrib_kind>, Selector) noexcept {
    return enumerator_map_type<vertex_attrib_kind, 16>{
      {{"object_id", vertex_attrib_kind::object_id},
       {"position", vertex_attrib_kind::position},
       {"normal", vertex_attrib_kind::normal},
       {"tangential", vertex_attrib_kind::tangential},
       {"bitangential", vertex_attrib_kind::bitangential},
       {"pivot", vertex_attrib_kind::pivot},
       {"pivot_pivot", vertex_attrib_kind::pivot_pivot},
       {"vertex_pivot", vertex_attrib_kind::vertex_pivot},
       {"box_coord", vertex_attrib_kind::box_coord},
       {"face_coord", vertex_attrib_kind::face_coord},
       {"wrap_coord", vertex_attrib_kind::wrap_coord},
       {"color", vertex_attrib_kind::color},
       {"weight", vertex_attrib_kind::weight},
       {"occlusion", vertex_attrib_kind::occlusion},
       {"polygon_id", vertex_attrib_kind::polygon_id},
       {"material_id", vertex_attrib_kind::material_id}}};
}
//------------------------------------------------------------------------------
/// @brief Alias for vertex_attrib_kind bitfield type.
/// @ingroup shapes
using vertex_attrib_bits = bitfield<vertex_attrib_kind>;
//------------------------------------------------------------------------------
/// @brief Returns vertex_attrib_bits value with all bits set.
/// @ingroup shapes
static constexpr auto all_vertex_attrib_bits() noexcept -> vertex_attrib_bits {
    return vertex_attrib_bits{(1U << 16U) - 1U};
}
//------------------------------------------------------------------------------
/// @brief Bitwise-or operator for vertex_attrib_kind bits.
/// @ingroup shapes
static constexpr auto
operator|(vertex_attrib_kind a, vertex_attrib_kind b) noexcept
  -> vertex_attrib_bits {
    return {a, b};
}
//------------------------------------------------------------------------------
/// @brief Class designating an vertex attribute variant in a shape generator.
/// @ingroup shapes
/// @see vertex_attrib_variants
class vertex_attrib_variant {
public:
    /// @brief Construction from vertex attribute kind enumerator.
    constexpr vertex_attrib_variant(vertex_attrib_kind a)
      : _attrib{a} {}

    /// @brief Construction from vertex attribute kind enumerator and index.
    constexpr vertex_attrib_variant(vertex_attrib_kind a, span_size_t v)
      : _attrib{a}
      , _index{std::int16_t(v)} {}

    /// @brief Construction from vertex attribute kind and another attribute variant.
    constexpr vertex_attrib_variant(
      vertex_attrib_kind a,
      vertex_attrib_variant vav)
      : _attrib{a}
      , _index{vav._index} {}

    /// @brief Return the attribute kind.
    constexpr auto attribute() const noexcept -> vertex_attrib_kind {
        return _attrib;
    }

    /// @brief Check if the stored index is valid.
    constexpr auto has_valid_index() const noexcept {
        return _index >= 0;
    }

    /// @brief Check if the stored index is valid.
    /// @see has_valid_index
    constexpr explicit operator bool() const noexcept {
        return has_valid_index();
    }

    /// @brief Returns the index of the attribute variant.
    constexpr auto index() const noexcept -> span_size_t {
        return _index;
    }

    constexpr
    operator std::array<const vertex_attrib_variant, 1>() const noexcept {
        return {{*this}};
    }

    constexpr auto as_tuple() const noexcept {
        return std::make_tuple(_attrib, _index);
    }

    /// @brief Equality comparison.
    friend constexpr auto
    operator==(vertex_attrib_variant l, vertex_attrib_variant r) noexcept {
        return l.as_tuple() == r.as_tuple();
    }

    /// @brief Nonequality comparison.
    friend constexpr auto
    operator!=(vertex_attrib_variant l, vertex_attrib_variant r) noexcept {
        return l.as_tuple() != r.as_tuple();
    }

    /// @brief Less-than comparison.
    friend constexpr auto
    operator<(vertex_attrib_variant l, vertex_attrib_variant r) noexcept {
        return l.as_tuple() < r.as_tuple();
    }

    /// @brief Variant and kind equality comparison.
    friend constexpr auto
    operator==(vertex_attrib_variant l, vertex_attrib_kind r) noexcept {
        return l._attrib == r;
    }

    /// @brief Variant and kind nonequality comparison.
    friend constexpr auto
    operator!=(vertex_attrib_variant l, vertex_attrib_kind r) noexcept {
        return l._attrib != r;
    }

private:
    vertex_attrib_kind _attrib;
    std::int16_t _index{0};
};
//------------------------------------------------------------------------------
/// @brief Operator for constructing of vertex_attrib_variant from kind and index.
/// @ingroup shapes
static constexpr auto
operator/(vertex_attrib_kind attrib, span_size_t variant_index) noexcept
  -> vertex_attrib_variant {
    return {attrib, variant_index};
}
//------------------------------------------------------------------------------
/// @brief Array of several vertex attribute variant instances.
/// @ingroup shapes
/// @see vertex_attrib_variant
template <std::size_t N>
using vertex_attrib_variants = std::array<const vertex_attrib_variant, N>;
//------------------------------------------------------------------------------
/// @brief Operator for creating of single element array of vertex attrib variant.
/// @ingroup shapes
/// @see vertex_attrib_variant
/// @see vertex_attrib_variants
static constexpr auto operator+(vertex_attrib_variant a) noexcept
  -> vertex_attrib_variants<1> {
    return {{a}};
}
//------------------------------------------------------------------------------
/// @brief Operator for creating of two element array of vertex attrib variants.
/// @ingroup shapes
/// @see vertex_attrib_variant
/// @see vertex_attrib_variants
static constexpr auto
operator+(vertex_attrib_variant a, vertex_attrib_variant b) noexcept
  -> vertex_attrib_variants<2> {
    return {{a, b}};
}
//------------------------------------------------------------------------------
// append_attrib
template <std::size_t N, std::size_t... I>
static constexpr auto do_append_attrib(
  const vertex_attrib_variants<N>& a,
  vertex_attrib_variant b,
  std::index_sequence<I...>) noexcept {
    return vertex_attrib_variants<N + 1>{{a[I]..., b}};
}
//------------------------------------------------------------------------------
/// @brief Operator for concatenation of vertex attrib variants into an array.
/// @ingroup shapes
/// @see vertex_attrib_variant
/// @see vertex_attrib_variants
template <std::size_t N>
static constexpr auto
operator+(const vertex_attrib_variants<N>& a, vertex_attrib_variant b) noexcept
  -> vertex_attrib_variants<N + 1> {
    return do_append_attrib(a, b, std::make_index_sequence<N>());
}
//------------------------------------------------------------------------------
/// @brief Extracts vertex attribute kind bits from and vertex attribute variants array.
/// @ingroup shapes
/// @see vertex_attrib_bits
template <std::size_t N>
static inline auto
get_attrib_bits(const vertex_attrib_variants<N>& vaals) noexcept
  -> vertex_attrib_bits {
    vertex_attrib_bits res;

    for(const vertex_attrib_variant& vaal : vaals) {
        res = res | vaal.attribute();
    }

    return res;
}
//------------------------------------------------------------------------------
/// @brief Gets the default number of values per vertex for an attribute kind.
/// @ingroup shapes
static inline auto attrib_values_per_vertex(vertex_attrib_kind attr) noexcept
  -> span_size_t {
    switch(attr) {
        case vertex_attrib_kind::color:
            return 4;
        case vertex_attrib_kind::position:
        case vertex_attrib_kind::normal:
        case vertex_attrib_kind::tangential:
        case vertex_attrib_kind::bitangential:
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::pivot_pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::face_coord:
        case vertex_attrib_kind::box_coord:
            return 3;
        case vertex_attrib_kind::wrap_coord:
            return 2;
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::occlusion:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::polygon_id:
        case vertex_attrib_kind::material_id:
            return 1;
    }
    return 0;
}
//------------------------------------------------------------------------------
/// @brief Gets the default number of values per vertex for an attribute variant.
/// @ingroup shapes
static inline auto attrib_values_per_vertex(vertex_attrib_variant vav) noexcept {
    return attrib_values_per_vertex(vav.attribute());
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_VERTEX_ATTRIB_HPP
