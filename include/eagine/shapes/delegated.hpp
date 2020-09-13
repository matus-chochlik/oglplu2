/**
 *  @file eagine/shapes/delegated.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_DELEGATED_HPP
#define EAGINE_SHAPES_DELEGATED_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <memory>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class delegated_gen : public generator_intf {
private:
    std::unique_ptr<generator_intf> _gen;

public:
    delegated_gen(std::unique_ptr<generator_intf>&& gen) noexcept
      : _gen(std::move(gen)) {}

    vertex_attrib_bits attrib_bits() noexcept final {
        return _gen->attrib_bits();
    }

    bool enable(generator_capability cap, bool value) noexcept final {
        return _gen->enable(cap, value);
    }

    bool is_enabled(generator_capability cap) noexcept final {
        return _gen->is_enabled(cap);
    }

    span_size_t vertex_count() override {
        return _gen->vertex_count();
    }

    span_size_t attribute_variants(vertex_attrib_kind attrib) override {
        return _gen->attribute_variants(attrib);
    }

    string_view variant_name(vertex_attrib_variant vav) override {
        return _gen->variant_name(vav);
    }

    span_size_t values_per_vertex(vertex_attrib_variant vav) override {
        return _gen->values_per_vertex(vav);
    }

    attrib_data_type attrib_type(vertex_attrib_variant vav) override {
        return _gen->attrib_type(vav);
    }

    bool is_attrib_normalized(vertex_attrib_variant vav) override {
        return _gen->is_attrib_normalized(vav);
    }

    void attrib_values(vertex_attrib_variant vav, span<byte> dest) override {
        _gen->attrib_values(vav, dest);
    }

    void
    attrib_values(vertex_attrib_variant vav, span<std::int16_t> dest) override {
        _gen->attrib_values(vav, dest);
    }

    void
    attrib_values(vertex_attrib_variant vav, span<std::int32_t> dest) override {
        _gen->attrib_values(vav, dest);
    }

    void attrib_values(vertex_attrib_variant vav, span<std::uint16_t> dest)
      override {
        _gen->attrib_values(vav, dest);
    }

    void attrib_values(vertex_attrib_variant vav, span<std::uint32_t> dest)
      override {
        _gen->attrib_values(vav, dest);
    }

    void attrib_values(vertex_attrib_variant vav, span<float> dest) override {
        _gen->attrib_values(vav, dest);
    }

    span_size_t draw_variant_count() override {
        return _gen->draw_variant_count();
    }

    index_data_type index_type(drawing_variant var) override {
        return _gen->index_type(var);
    }

    span_size_t index_count(drawing_variant var) override {
        return _gen->index_count(var);
    }

    void indices(drawing_variant var, span<std::uint8_t> dest) override {
        _gen->indices(var, dest);
    }

    void indices(drawing_variant var, span<std::uint16_t> dest) override {
        _gen->indices(var, dest);
    }

    void indices(drawing_variant var, span<std::uint32_t> dest) override {
        _gen->indices(var, dest);
    }

    span_size_t operation_count(drawing_variant var) override {
        return _gen->operation_count(var);
    }

    void instructions(drawing_variant var, span<draw_operation> ops) override {
        _gen->instructions(var, ops);
    }

    math::sphere<float, true> bounding_sphere() override {
        return _gen->bounding_sphere();
    }
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_DELEGATED_HPP
