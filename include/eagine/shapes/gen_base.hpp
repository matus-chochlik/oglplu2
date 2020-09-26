/**
 *  @file eagine/shapes/gen_base.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_GEN_BASE_HPP
#define EAGINE_SHAPES_GEN_BASE_HPP

#include "../assert.hpp"
#include "../compare.hpp"
#include "../math/primitives.hpp"
#include "../span.hpp"
#include "../types.hpp"
#include "drawing.hpp"
#include "gen_capabilities.hpp"
#include "vertex_attrib.hpp"
#include <eagine/config/basic.hpp>
#include <array>
#include <memory>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
using drawing_variant = span_size_t;
//------------------------------------------------------------------------------
struct generator_intf {

    generator_intf() = default;
    generator_intf(generator_intf&&) noexcept = default;
    generator_intf(const generator_intf&) = default;
    auto operator=(generator_intf&&) = delete;
    auto operator=(const generator_intf&) = delete;
    virtual ~generator_intf() = default;

    virtual auto attrib_bits() noexcept -> vertex_attrib_bits = 0;

    auto has(vertex_attrib_kind attrib) noexcept {
        return bool(attrib_bits() | attrib);
    }

    virtual auto enable(generator_capability cap, bool value = true) noexcept
      -> bool = 0;

    auto disable(generator_capability cap) noexcept {
        return enable(cap, false);
    }

    virtual auto is_enabled(generator_capability cap) noexcept -> bool = 0;

    auto strips_allowed() noexcept -> bool {
        return is_enabled(generator_capability::element_strips);
    }

    auto fans_allowed() noexcept -> bool {
        return is_enabled(generator_capability::element_fans);
    }

    auto primitive_restart() noexcept -> bool {
        return is_enabled(generator_capability::primitive_restart);
    }

    virtual auto vertex_count() -> span_size_t = 0;

    virtual auto attribute_variants(vertex_attrib_kind) -> span_size_t = 0;

    virtual auto variant_name(vertex_attrib_variant vav) -> string_view = 0;

    auto find_variant(vertex_attrib_kind attrib, string_view name)
      -> vertex_attrib_variant {
        const span_size_t n = attribute_variants(attrib);
        span_size_t index{-1};
        for(span_size_t i = 0; i < n; ++i) {
            if(are_equal(name, variant_name({attrib, i}))) {
                index = i;
                break;
            }
        }
        return {attrib, index};
    }

    virtual auto values_per_vertex(vertex_attrib_variant) -> span_size_t = 0;

    virtual auto attrib_type(vertex_attrib_variant vav) -> attrib_data_type = 0;

    virtual auto is_attrib_normalized(vertex_attrib_variant vav) -> bool = 0;

    virtual void attrib_values(vertex_attrib_variant, span<byte> dest) = 0;
    virtual void attrib_values(vertex_attrib_variant, span<std::int16_t>) = 0;
    virtual void attrib_values(vertex_attrib_variant, span<std::int32_t>) = 0;
    virtual void attrib_values(vertex_attrib_variant, span<std::uint16_t>) = 0;
    virtual void attrib_values(vertex_attrib_variant, span<std::uint32_t>) = 0;
    virtual void attrib_values(vertex_attrib_variant, span<float> dest) = 0;

    virtual auto draw_variant_count() -> span_size_t = 0;

    auto draw_variant(span_size_t index) -> drawing_variant {
        return index;
    }

    virtual auto index_type(drawing_variant) -> index_data_type = 0;

    auto index_type() {
        return index_type(0);
    }

    virtual auto index_count(drawing_variant) -> span_size_t = 0;

    auto index_count() {
        return index_count(0);
    }

    virtual void indices(drawing_variant, span<std::uint8_t> dest) = 0;
    void indices(span<std::uint8_t> dest) {
        indices(0, dest);
    }

    virtual void indices(drawing_variant, span<std::uint16_t> dest) = 0;
    void indices(span<std::uint16_t> dest) {
        indices(0, dest);
    }

    virtual void indices(drawing_variant, span<std::uint32_t> dest) = 0;
    void indices(span<std::uint32_t> dest) {
        indices(0, dest);
    }

    virtual auto operation_count(drawing_variant) -> span_size_t = 0;
    auto operation_count() {
        return operation_count(0);
    }

    virtual void instructions(drawing_variant, span<draw_operation> dest) = 0;
    void instructions(span<draw_operation> dest) {
        return instructions(0, dest);
    }

    virtual auto bounding_sphere() -> math::sphere<float, true>;

    virtual void ray_intersections(
      drawing_variant,
      span<const math::line<float, true>> rays,
      span<optionally_valid<float>> intersections);

    void ray_intersections(
      span<const math::line<float, true>> rays,
      span<optionally_valid<float>> intersections) {
        return ray_intersections(0, rays, intersections);
    }

    auto
    ray_intersection(drawing_variant var, const math::line<float, true>& ray)
      -> optionally_valid<float> {
        optionally_valid<float> result{};
        ray_intersections(var, view_one(ray), cover_one(result));
        return result;
    }

    auto ray_intersection(const math::line<float, true>& ray)
      -> optionally_valid<float> {
        optionally_valid<float> result{};
        ray_intersections(0, view_one(ray), cover_one(result));
        return result;
    }
};
//------------------------------------------------------------------------------
class generator_base : public generator_intf {
private:
    vertex_attrib_bits _attr_bits;
    generator_capabilities _caps;

protected:
    generator_base(vertex_attrib_bits attr_bits) noexcept
      : _attr_bits(attr_bits) {}

public:
    auto attrib_bits() noexcept -> vertex_attrib_bits final {
        return _attr_bits;
    }

    auto enable(generator_capability cap, bool value) noexcept -> bool final {
        if(value) {
            _caps |= cap;
        } else {
            _caps &= cap;
        }
        return true;
    }

    auto is_enabled(generator_capability cap) noexcept -> bool final {
        return _caps.has(cap);
    }

    auto attribute_variants(vertex_attrib_kind attrib) -> span_size_t override {
        return has(attrib) ? 1U : 0U;
    }

    auto variant_name(vertex_attrib_variant) -> string_view override {
        return {};
    }

    auto has_variant(vertex_attrib_variant vav) -> bool {
        EAGINE_ASSERT(vav.has_valid_index());
        return vav.index() < attribute_variants(vav.attrib);
    }

    auto values_per_vertex(vertex_attrib_variant vav) -> span_size_t override {
        return has_variant(vav) ? attrib_values_per_vertex(vav) : 0U;
    }

    auto value_count(vertex_attrib_variant vav) -> span_size_t {
        return vertex_count() * values_per_vertex(vav);
    }

    auto attrib_type(vertex_attrib_variant) -> attrib_data_type override {
        return attrib_data_type::float_;
    }

    auto is_attrib_normalized(vertex_attrib_variant) -> bool override {
        return false;
    }

    void attrib_values(vertex_attrib_variant, span<byte>) override {
        EAGINE_UNREACHABLE("Generator failed to get byte attribute values.");
    }

    void attrib_values(vertex_attrib_variant, span<std::int16_t>) override {
        EAGINE_UNREACHABLE("Generator failed to get int16 attribute values.");
    }

    void attrib_values(vertex_attrib_variant, span<std::int32_t>) override {
        EAGINE_UNREACHABLE("Generator failed to get int32 attribute values.");
    }

    void attrib_values(vertex_attrib_variant, span<std::uint16_t>) override {
        EAGINE_UNREACHABLE("Generator failed to get uint16 attribute values.");
    }

    void attrib_values(vertex_attrib_variant, span<std::uint32_t>) override {
        EAGINE_UNREACHABLE("Generator failed to get uint32 attribute values.");
    }

    void attrib_values(vertex_attrib_variant, span<float>) override {
        EAGINE_UNREACHABLE("Generator failed to get float attribute values.");
    }

    auto draw_variant_count() -> span_size_t override {
        return 1;
    }

    auto index_type(drawing_variant) -> index_data_type override;

    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;
};
//------------------------------------------------------------------------------
class centered_unit_shape_generator_base : public generator_base {
protected:
    centered_unit_shape_generator_base(vertex_attrib_bits attr_bits) noexcept
      : generator_base(attr_bits) {}

public:
    void attrib_values(vertex_attrib_variant vav, span<float> dest) override;
};
//------------------------------------------------------------------------------
static inline auto operator+(
  std::unique_ptr<generator_intf>&& l,
  std::unique_ptr<generator_intf>&& r) noexcept
  -> std::array<std::unique_ptr<generator_intf>, 2> {
    return {{std::move(l), std::move(r)}};
}
//------------------------------------------------------------------------------
template <std::size_t N, std::size_t... I>
static inline auto _add_to_array(
  std::array<std::unique_ptr<generator_intf>, N>&& l,
  std::unique_ptr<generator_intf>&& r,
  std::index_sequence<I...>) noexcept
  -> std::array<std::unique_ptr<generator_intf>, N + 1> {
    return {{std::move(l[I])..., std::move(r)}};
}
//------------------------------------------------------------------------------
template <std::size_t N>
static inline auto operator+(
  std::array<std::unique_ptr<generator_intf>, N>&& l,
  std::unique_ptr<generator_intf>&& r) noexcept
  -> std::array<std::unique_ptr<generator_intf>, N + 1> {
    return _add_to_array(
      std::move(l), std::move(r), std::make_index_sequence<N>());
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/gen_base.inl>
#endif

#endif // EAGINE_SHAPES_GEN_BASE_HPP
