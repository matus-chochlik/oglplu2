/**
 *  @file eagine/shapes/combined.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_COMBINED_HPP
#define EAGINE_SHAPES_COMBINED_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class combined_gen : public generator_intf {
private:
    std::vector<std::unique_ptr<generator_intf>> _gens;

    template <typename T>
    void _indices(drawing_variant, span<T> dest);

    template <typename T>
    void _attrib_values(vertex_attrib_variant, span<T>);

public:
    combined_gen(std::vector<std::unique_ptr<generator_intf>>&& gens) noexcept
      : _gens{std::move(gens)} {}

    auto add(std::unique_ptr<generator_intf>&& gen) && -> combined_gen&&;

    auto attrib_bits() noexcept -> vertex_attrib_bits final;

    auto enable(generator_capability cap, bool value) noexcept -> bool final;

    auto is_enabled(generator_capability cap) noexcept -> bool final;

    auto vertex_count() -> span_size_t override;

    auto attribute_variants(vertex_attrib_kind attrib) -> span_size_t override;

    auto variant_name(vertex_attrib_variant) -> string_view override;

    auto values_per_vertex(vertex_attrib_variant) -> span_size_t override;

    auto attrib_type(vertex_attrib_variant) -> attrib_data_type override;

    auto is_attrib_normalized(vertex_attrib_variant) -> bool override;

    void attrib_values(vertex_attrib_variant, span<byte>) override;
    void attrib_values(vertex_attrib_variant, span<std::int16_t>) override;
    void attrib_values(vertex_attrib_variant, span<std::int32_t>) override;
    void attrib_values(vertex_attrib_variant, span<std::uint16_t>) override;
    void attrib_values(vertex_attrib_variant, span<std::uint32_t>) override;
    void attrib_values(vertex_attrib_variant, span<float>) override;

    auto draw_variant_count() -> span_size_t override;

    auto index_type(drawing_variant) -> index_data_type override;

    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;

    auto operation_count(drawing_variant) -> span_size_t override;

    void instructions(drawing_variant, span<draw_operation> ops) override;

    void ray_intersections(
      drawing_variant,
      span<const math::line<float, true>> rays,
      span<optionally_valid<float>> intersections) override;
};
//------------------------------------------------------------------------------
static inline auto combine(std::unique_ptr<generator_intf>&& gen) {
    std::vector<std::unique_ptr<generator_intf>> v;
    v.reserve(1);
    v.emplace_back(std::move(gen));
    return std::make_unique<combined_gen>(std::move(v));
}
//------------------------------------------------------------------------------
template <std::size_t N>
static inline auto
combine(std::array<std::unique_ptr<generator_intf>, N>&& gens) {
    std::vector<std::unique_ptr<generator_intf>> v;
    v.reserve(N);
    for(auto& gen : gens) {
        v.emplace_back(std::move(gen));
    }
    return std::make_unique<combined_gen>(std::move(v));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/combined.inl>
#endif

#endif // EAGINE_SHAPES_COMBINED_HPP
