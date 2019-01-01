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
#include "../span.hpp"
#include "../types.hpp"
#include "drawing.hpp"
#include "vertex_attrib.hpp"

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
struct generator_params {
    bool allow_strips{true};
    bool allow_fans{true};
    bool allow_primitive_restart{false};

    generator_params() noexcept = default;
};
//------------------------------------------------------------------------------
struct generator_intf {
    generator_intf() = default;
    generator_intf(const generator_intf&) = default;
    virtual ~generator_intf() = default;

    virtual vertex_attrib_bits attrib_bits() noexcept = 0;

    virtual generator_params& parameters() noexcept = 0;

    bool strips_allowed() noexcept {
        return parameters().allow_strips;
    }

    bool fans_allowed() noexcept {
        return parameters().allow_fans;
    }

    bool primitive_restart() noexcept {
        return parameters().allow_primitive_restart;
    }

    bool has(vertex_attrib_kind attr) noexcept {
        return bool(attrib_bits() | attr);
    }

    virtual span_size_t vertex_count() = 0;

    virtual span_size_t values_per_vertex(vertex_attrib_kind attr) = 0;

    virtual void attrib_values(vertex_attrib_kind attr, span<float> dest) = 0;

    virtual index_data_type index_type() = 0;

    virtual span_size_t index_count() = 0;

    virtual void indices(span<unsigned> dest) = 0;

    virtual span_size_t operation_count() = 0;

    virtual void instructions(span<draw_operation> dest) = 0;
};
//------------------------------------------------------------------------------
class generator_base : public generator_intf {
private:
    vertex_attrib_bits _attr_bits;
    generator_params _params;

protected:
    generator_base(vertex_attrib_bits attr_bits) noexcept
      : _attr_bits(attr_bits) {
    }

public:
    vertex_attrib_bits attrib_bits() noexcept final {
        return _attr_bits;
    }

    generator_params& parameters() noexcept final {
        return _params;
    }

    span_size_t values_per_vertex(vertex_attrib_kind attr) override {
        return has(attr) ? attrib_values_per_vertex(attr) : 0u;
    }

    span_size_t value_count(vertex_attrib_kind attr) {
        return vertex_count() * values_per_vertex(attr);
    }

    void attrib_values(vertex_attrib_kind, span<float>) override {
        EAGINE_UNREACHABLE(
          "Generator failed to handle the specified attribute kind.");
    }
};
//------------------------------------------------------------------------------
class centered_unit_shape_generator_base : public generator_base {
protected:
    centered_unit_shape_generator_base(vertex_attrib_bits attr_bits) noexcept
      : generator_base(attr_bits) {
    }

public:
    void attrib_values(vertex_attrib_kind attr, span<float> dest) override {
        if(attr == vertex_attrib_kind::box_coord) {
            this->attrib_values(vertex_attrib_kind::position, dest);
            for(float& x : dest) {
                x += 0.5f;
            }
        } else {
            generator_base::attrib_values(attr, dest);
        }
    }
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_GEN_BASE_HPP
