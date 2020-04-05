/**
 *  @file oglplus/shapes/adapted_gen.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_ADAPTED_GEN_HPP
#define OGLPLUS_SHAPES_ADAPTED_GEN_HPP

#include "../gl_api.hpp"
#include "../math/primitives.hpp"
#include "drawing.hpp"
#include <eagine/memory/buffer.hpp>
#include <eagine/shapes/gen_base.hpp>
#include <eagine/shapes/vertex_attrib.hpp>
#include <eagine/span.hpp>
#include <memory>

namespace eagine {
namespace oglp {
namespace shapes {
//------------------------------------------------------------------------------
class adapted_generator {
private:
    using generator_intf = eagine::shapes::generator_intf;
    std::unique_ptr<generator_intf> _gen{};

public:
    template <typename A>
    adapted_generator(
      const basic_gl_api<A>&, std::unique_ptr<generator_intf>&&);

    template <typename A, typename Gen>
    adapted_generator(const basic_gl_api<A>& api, std::unique_ptr<Gen>&& gen)
      : adapted_generator(
          api, std::unique_ptr<generator_intf>(std::move(gen))) {
    }

    span_size_t vertex_count() const {
        return _gen->vertex_count();
    }

    span_size_t values_per_vertex(
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index) const {
        return _gen->values_per_vertex(attrib, variant_index);
    }

    span_size_t value_count(
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index) const {
        return vertex_count() * values_per_vertex(attrib, variant_index);
    }

    template <typename A>
    data_type attrib_type(
      const basic_gl_api<A>& api,
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index) const {
        return translate(api, _gen->attrib_type(attrib, variant_index));
    }

    template <typename A>
    true_false is_attrib_normalized(
      const basic_gl_api<A>& api,
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index) const {
        return translate(
          api, _gen->is_attrib_normalized(attrib, variant_index));
    }

    span_size_t attrib_type_size(
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index) const {
        return type_size(_gen->attrib_type(attrib, variant_index));
    }

    span_size_t attrib_data_block_size(
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index) const {
        return value_count(attrib, variant_index) *
               attrib_type_size(attrib, variant_index);
    }

    void attrib_data(
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index,
      memory::block data) const;

    bool is_indexed() const {
        return _gen->index_count() > 0;
    }

    span_size_t index_count() const {
        return _gen->index_count();
    }

    span_size_t index_type_size() const {
        return type_size(_gen->index_type());
    }

    span_size_t index_data_block_size() const {
        return index_count() * index_type_size();
    }

    void index_data(memory::block data) const;

    span_size_t operation_count() const {
        return _gen->operation_count();
    }

    template <typename A>
    void attrib_setup(
      const basic_gl_api<A>& api,
      vertex_array_name vao,
      buffer_name buf,
      vertex_attrib_location loc,
      eagine::shapes::vertex_attrib_kind attrib,
      span_size_t variant_index,
      memory::buffer& temp) const;

    template <typename A>
    void instructions(const basic_gl_api<A>&, span<draw_operation>) const;

    sphere bounding_sphere() const {
        return _gen->bounding_sphere();
    }

    optionally_valid<float> ray_intersection(const line& ray) const {
        return _gen->ray_intersection(ray);
    }

    optionally_valid<float> ray_intersection(
      const optionally_valid<line>& opt_ray) const {
        if(opt_ray) {
            return ray_intersection(extract(opt_ray));
        }
        return {};
    }
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglp
} // namespace eagine

#include <oglplus/shapes/adapted_gen.inl>

#endif // OGLPLUS_SHAPES_ADAPTED_GEN_HPP
