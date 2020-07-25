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
    generator_intf& operator=(generator_intf&&) = delete;
    generator_intf& operator=(const generator_intf&) = delete;
    virtual ~generator_intf() = default;

    virtual vertex_attrib_bits attrib_bits() noexcept = 0;

    bool has(vertex_attrib_kind attrib) noexcept {
        return bool(attrib_bits() | attrib);
    }

    virtual bool enable(
      generator_capability cap, bool value = true) noexcept = 0;

    bool disable(generator_capability cap) noexcept {
        return enable(cap, false);
    }

    virtual bool is_enabled(generator_capability cap) noexcept = 0;

    bool strips_allowed() noexcept {
        return is_enabled(generator_capability::element_strips);
    }

    bool fans_allowed() noexcept {
        return is_enabled(generator_capability::element_fans);
    }

    bool primitive_restart() noexcept {
        return is_enabled(generator_capability::primitive_restart);
    }

    virtual span_size_t vertex_count() = 0;

    virtual span_size_t attribute_variants(vertex_attrib_kind attrib) = 0;

    virtual string_view variant_name(vertex_attrib_variant vav) = 0;

    vertex_attrib_variant find_variant(
      vertex_attrib_kind attrib, string_view name) {
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

    virtual span_size_t values_per_vertex(vertex_attrib_variant vav) = 0;

    virtual attrib_data_type attrib_type(vertex_attrib_variant vav) = 0;

    virtual bool is_attrib_normalized(vertex_attrib_variant vav) = 0;

    virtual void attrib_values(vertex_attrib_variant vav, span<byte> dest) = 0;
    virtual void attrib_values(vertex_attrib_variant vav, span<float> dest) = 0;

    virtual span_size_t draw_variant_count() = 0;

    drawing_variant draw_variant(span_size_t index) {
        return index;
    }

    virtual index_data_type index_type(drawing_variant) = 0;
    index_data_type index_type() {
        return index_type(0);
    }

    virtual span_size_t index_count(drawing_variant) = 0;
    span_size_t index_count() {
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

    virtual span_size_t operation_count(drawing_variant) = 0;
    span_size_t operation_count() {
        return operation_count(0);
    }

    virtual void instructions(drawing_variant, span<draw_operation> dest) = 0;
    void instructions(span<draw_operation> dest) {
        return instructions(0, dest);
    }

    virtual math::sphere<float, true> bounding_sphere();

    virtual void ray_intersections(
      drawing_variant,
      span<const math::line<float, true>> rays,
      span<optionally_valid<float>> intersections);

    void ray_intersections(
      span<const math::line<float, true>> rays,
      span<optionally_valid<float>> intersections) {
        return ray_intersections(0, rays, intersections);
    }

    optionally_valid<float> ray_intersection(
      drawing_variant var, const math::line<float, true>& ray) {
        optionally_valid<float> result{};
        ray_intersections(var, view_one(ray), cover_one(result));
        return result;
    }

    optionally_valid<float> ray_intersection(
      const math::line<float, true>& ray) {
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
      : _attr_bits(attr_bits) {
    }

public:
    vertex_attrib_bits attrib_bits() noexcept final {
        return _attr_bits;
    }

    bool enable(generator_capability cap, bool value) noexcept final {
        if(value) {
            _caps |= cap;
        } else {
            _caps &= cap;
        }
        return true;
    }

    bool is_enabled(generator_capability cap) noexcept final {
        return _caps.has(cap);
    }

    span_size_t attribute_variants(vertex_attrib_kind attrib) override {
        return has(attrib) ? 1U : 0U;
    }

    string_view variant_name(vertex_attrib_variant) override {
        return {};
    }

    bool has_variant(vertex_attrib_variant vav) {
        EAGINE_ASSERT(vav.has_valid_index());
        return vav.index() < attribute_variants(vav.attrib);
    }

    span_size_t values_per_vertex(vertex_attrib_variant vav) override {
        return has_variant(vav) ? attrib_values_per_vertex(vav) : 0U;
    }

    span_size_t value_count(vertex_attrib_variant vav) {
        return vertex_count() * values_per_vertex(vav);
    }

    attrib_data_type attrib_type(vertex_attrib_variant) override {
        return attrib_data_type::float_;
    }

    bool is_attrib_normalized(vertex_attrib_variant) override {
        return false;
    }

    void attrib_values(vertex_attrib_variant, span<byte>) override {
        EAGINE_UNREACHABLE("Generator failed to get byte attribute values.");
    }

    void attrib_values(vertex_attrib_variant, span<float>) override {
        EAGINE_UNREACHABLE("Generator failed to get float attribute values.");
    }

    span_size_t draw_variant_count() override {
        return 1;
    }

    index_data_type index_type(drawing_variant) override;

    span_size_t index_count(drawing_variant) override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;
};
//------------------------------------------------------------------------------
class centered_unit_shape_generator_base : public generator_base {
protected:
    centered_unit_shape_generator_base(vertex_attrib_bits attr_bits) noexcept
      : generator_base(attr_bits) {
    }

public:
    void attrib_values(vertex_attrib_variant vav, span<float> dest) override;
};
//------------------------------------------------------------------------------
static inline std::array<std::unique_ptr<generator_intf>, 2> operator+(
  std::unique_ptr<generator_intf>&& l,
  std::unique_ptr<generator_intf>&& r) noexcept {
    return {{std::move(l), std::move(r)}};
}
//------------------------------------------------------------------------------
template <std::size_t N, std::size_t... I>
static inline std::array<std::unique_ptr<generator_intf>, N + 1> _add_to_array(
  std::array<std::unique_ptr<generator_intf>, N>&& l,
  std::unique_ptr<generator_intf>&& r,
  std::index_sequence<I...>) noexcept {
    return {{std::move(l[I])..., std::move(r)}};
}
//------------------------------------------------------------------------------
template <std::size_t N>
static inline std::array<std::unique_ptr<generator_intf>, N + 1> operator+(
  std::array<std::unique_ptr<generator_intf>, N>&& l,
  std::unique_ptr<generator_intf>&& r) noexcept {
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
