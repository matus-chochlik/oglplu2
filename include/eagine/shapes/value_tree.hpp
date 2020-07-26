/**
 *  @file eagine/shapes/value_tree.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_VALUE_TREE_HPP
#define EAGINE_SHAPES_VALUE_TREE_HPP

#include "../config/basic.hpp"
#include "../logging/logger.hpp"
#include "../value_tree/wrappers.hpp"
#include "gen_base.hpp"
#include <map>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class value_tree_loader : public centered_unit_shape_generator_base {
private:
    using _base = centered_unit_shape_generator_base;
    logger _log{};

    valtree::compound _source{};
    std::string _temp{};
    std::map<vertex_attrib_variant, std::string> _variant_names{};

    static vertex_attrib_bits _attr_mask(const valtree::compound&) noexcept;

    template <typename T>
    void _attrib_values(vertex_attrib_variant, span<T>);

public:
    value_tree_loader(valtree::compound source, logger&) noexcept;

    span_size_t vertex_count() override;

    span_size_t attribute_variants(vertex_attrib_kind attrib) override;

    string_view variant_name(vertex_attrib_variant) override;

    span_size_t values_per_vertex(vertex_attrib_variant) override;

    attrib_data_type attrib_type(vertex_attrib_variant vav) override;

    bool is_attrib_normalized(vertex_attrib_variant) override;

    void attrib_values(vertex_attrib_variant, span<byte>) override;
    void attrib_values(vertex_attrib_variant, span<float>) override;

    index_data_type index_type(drawing_variant) override;

    span_size_t index_count(drawing_variant) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;
    void indices(drawing_variant, span<std::uint32_t> dest) override;

    span_size_t operation_count(drawing_variant) override;

    void instructions(drawing_variant, span<draw_operation> ops) override;
};
//------------------------------------------------------------------------------
static inline auto from_value_tree(valtree::compound source, logger& log) {
    return std::make_unique<value_tree_loader>(std::move(source), log);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/value_tree.inl>
#endif

#endif // EAGINE_SHAPES_VALUE_TREE_HPP
