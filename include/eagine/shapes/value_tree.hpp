/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_VALUE_TREE_HPP
#define EAGINE_SHAPES_VALUE_TREE_HPP

#include "../config/basic.hpp"
#include "../main_ctx_object.hpp"
#include "../value_tree/wrappers.hpp"
#include "gen_base.hpp"
#include <map>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Loader that fetches shape data from a value tree (JSON, YAML, etc.)
/// @ingroup shapes
/// @see from_value_tree
/// @see valtree::compound
/// @see valtree::attribute
/// @see valtree::from_json_text
/// @see valtree::from_yaml_text
class value_tree_loader
  : public main_ctx_object
  , public centered_unit_shape_generator_base {
public:
    value_tree_loader(valtree::compound source, main_ctx_parent) noexcept;

    auto vertex_count() -> span_size_t override;

    auto attribute_variants(vertex_attrib_kind) -> span_size_t override;

    auto variant_name(vertex_attrib_variant) -> string_view override;

    auto values_per_vertex(vertex_attrib_variant) -> span_size_t override;

    auto attrib_type(vertex_attrib_variant vav) -> attrib_data_type override;

    auto is_attrib_normalized(vertex_attrib_variant) -> bool override;

    void attrib_values(vertex_attrib_variant, span<byte>) override;
    void attrib_values(vertex_attrib_variant, span<std::int16_t>) override;
    void attrib_values(vertex_attrib_variant, span<std::int32_t>) override;
    void attrib_values(vertex_attrib_variant, span<std::uint16_t>) override;
    void attrib_values(vertex_attrib_variant, span<std::uint32_t>) override;
    void attrib_values(vertex_attrib_variant, span<float>) override;

    auto index_type(drawing_variant) -> index_data_type override;

    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;
    void indices(drawing_variant, span<std::uint32_t> dest) override;

    auto operation_count(drawing_variant) -> span_size_t override;

    void instructions(drawing_variant, span<draw_operation> ops) override;

private:
    using _base = centered_unit_shape_generator_base;

    valtree::compound _source{};
    std::string _temp{};
    std::map<vertex_attrib_variant, std::string> _variant_names{};

    static auto _attr_mask(const valtree::compound&) noexcept
      -> vertex_attrib_bits;

    template <typename T>
    void _attrib_values(vertex_attrib_variant, span<T>);
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of value_tree_loader.
/// @ingroup shapes
/// @see unit_cube
/// @see unit_round_cube
/// @see unit_sphere
/// @see unit_icosahedron
/// @see unit_screen
/// @see unit_torus
/// @see unit_twisted_torus
static inline auto
from_value_tree(valtree::compound source, main_ctx_parent parent) {
    return std::make_unique<value_tree_loader>(std::move(source), parent);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/value_tree.inl>
#endif

#endif // EAGINE_SHAPES_VALUE_TREE_HPP
