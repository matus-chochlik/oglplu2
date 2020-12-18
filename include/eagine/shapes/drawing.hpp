/**
 *  @file eagine/shapes/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_DRAWING_HPP
#define EAGINE_SHAPES_DRAWING_HPP

#include "../identifier.hpp"
#include "../reflect/map_enumerators.hpp"
#include "../types.hpp"

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
using value_tree_tag = EAGINE_TAG_TYPE(ValueTree);
//------------------------------------------------------------------------------
enum class primitive_type : std::uint8_t {
    points,
    lines,
    line_strip,
    line_loop,
    triangles,
    triangle_strip,
    triangle_fan,
    quads,
    tetrahedrons,
    patches
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<primitive_type>, Selector) noexcept {
    return enumerator_map_type<primitive_type, 10>{
      {{"points", primitive_type::points},
       {"lines", primitive_type::lines},
       {"line_strip", primitive_type::line_strip},
       {"line_loop", primitive_type::line_loop},
       {"triangles", primitive_type::triangles},
       {"triangle_strip", primitive_type::triangle_strip},
       {"triangle_fan", primitive_type::triangle_fan},
       {"quads", primitive_type::quads},
       {"tetrahedrons", primitive_type::tetrahedrons},
       {"patches", primitive_type::patches}}};
}
//------------------------------------------------------------------------------
enum class attrib_data_type {
    none,
    ubyte,
    int_16,
    int_32,
    uint_16,
    uint_32,
    float_
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<attrib_data_type>, Selector) noexcept {
    return enumerator_map_type<attrib_data_type, 7>{
      {{"none", attrib_data_type::none},
       {"ubyte", attrib_data_type::ubyte},
       {"int_16", attrib_data_type::int_16},
       {"int_32", attrib_data_type::int_32},
       {"uint_16", attrib_data_type::uint_16},
       {"uint_32", attrib_data_type::uint_32},
       {"float_", attrib_data_type::float_}}};
}
//------------------------------------------------------------------------------
constexpr auto
enumerator_mapping(type_identity<attrib_data_type>, value_tree_tag) noexcept {
    return enumerator_map_type<attrib_data_type, 6>{
      {{"ubyte", attrib_data_type::ubyte},
       {"int_16", attrib_data_type::int_16},
       {"int_32", attrib_data_type::int_32},
       {"uint_16", attrib_data_type::uint_16},
       {"uint_32", attrib_data_type::uint_32},
       {"float", attrib_data_type::float_}}};
}
//------------------------------------------------------------------------------
enum class index_data_type : std::uint8_t {
    none = 0,
    unsigned_8 = 8,
    unsigned_16 = 16,
    unsigned_32 = 32
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<index_data_type>, Selector) noexcept {
    return enumerator_map_type<index_data_type, 4>{
      {{"none", index_data_type::none},
       {"unsigned_8", index_data_type::unsigned_8},
       {"unsigned_16", index_data_type::unsigned_16},
       {"unsigned_32", index_data_type::unsigned_32}}};
}
//------------------------------------------------------------------------------
constexpr auto
enumerator_mapping(type_identity<index_data_type>, value_tree_tag) noexcept {
    return enumerator_map_type<index_data_type, 3>{
      {{"none", index_data_type::none},
       {"unsigned_16", index_data_type::unsigned_16},
       {"unsigned_32", index_data_type::unsigned_32}}};
}
//------------------------------------------------------------------------------
static inline auto operator<(index_data_type l, index_data_type r) noexcept {
    using UT = std::underlying_type_t<index_data_type>;
    return UT(l) < UT(r);
}
//------------------------------------------------------------------------------
static inline auto operator>(index_data_type l, index_data_type r) noexcept {
    using UT = std::underlying_type_t<index_data_type>;
    return UT(l) > UT(r);
}
//------------------------------------------------------------------------------
static inline auto operator<=(index_data_type l, index_data_type r) noexcept {
    using UT = std::underlying_type_t<index_data_type>;
    return UT(l) <= UT(r);
}
//------------------------------------------------------------------------------
static inline auto operator>=(index_data_type l, index_data_type r) noexcept {
    using UT = std::underlying_type_t<index_data_type>;
    return UT(l) >= UT(r);
}
//------------------------------------------------------------------------------
struct draw_operation {
    span_size_t first{0};
    span_size_t count{0};
    std::uint32_t phase{0};
    std::uint32_t primitive_restart_index{0};
    std::uint16_t patch_vertices{3};
    primitive_type mode{primitive_type::points};
    index_data_type idx_type{index_data_type::none};
    bool primitive_restart : 1;
    bool cw_face_winding : 1;

    constexpr draw_operation() noexcept
      : primitive_restart(false)
      , cw_face_winding(false) {}
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_DRAWING_HPP
