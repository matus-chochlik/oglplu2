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
    void _indices(span<T> dest);

public:
    combined_gen(std::vector<std::unique_ptr<generator_intf>>&& gens) noexcept
      : _gens{std::move(gens)} {
    }

    combined_gen&& add(std::unique_ptr<generator_intf>&& gen) &&;

    vertex_attrib_bits attrib_bits() noexcept final;

    bool enable(generator_capability cap, bool value) noexcept final;

    bool is_enabled(generator_capability cap) noexcept final;

    span_size_t vertex_count() override;

    span_size_t attribute_variants(vertex_attrib_kind attrib) override;

    span_size_t values_per_vertex(vertex_attrib_kind, span_size_t) override;

    attrib_data_type attrib_type(vertex_attrib_kind, span_size_t) override;

    bool is_attrib_normalized(vertex_attrib_kind, span_size_t) override;

    void attrib_values(vertex_attrib_kind, span_size_t, span<float>) override;

    index_data_type index_type() override;

    span_size_t index_count() override;

    void indices(span<std::uint8_t> dest) override;

    void indices(span<std::uint16_t> dest) override;

    void indices(span<std::uint32_t> dest) override;

    span_size_t operation_count() override;

    void instructions(span<draw_operation> ops) override;

    void ray_intersections(
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
static inline auto combine(
  std::array<std::unique_ptr<generator_intf>, N>&& gens) {
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
