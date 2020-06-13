/**
 *  @file oglplus/shapes/generator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_GENERATOR_HPP
#define OGLPLUS_SHAPES_GENERATOR_HPP

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
//------------------------------------------------------------------------------
class shape_generator {
private:
    using generator_intf = shapes::generator_intf;
    std::unique_ptr<generator_intf> _gen{};

public:
    template <typename A>
    shape_generator(const basic_gl_api<A>&, std::unique_ptr<generator_intf>&&);

    template <typename A, typename Gen>
    shape_generator(const basic_gl_api<A>& api, std::unique_ptr<Gen>&& gen)
      : shape_generator(api, std::unique_ptr<generator_intf>(std::move(gen))) {
    }

    shapes::vertex_attrib_variant find_variant(
      shapes::vertex_attrib_kind attrib, string_view name) const {
        return _gen->find_variant(attrib, name);
    }

    shapes::vertex_attrib_variant find_variant_or(
      shapes::vertex_attrib_kind attrib,
      string_view name,
      span_size_t index) const {
        if(auto found{find_variant(attrib, name)}) {
            return found;
        }
        return {attrib, index};
    }

    span_size_t vertex_count() const {
        return _gen->vertex_count();
    }

    span_size_t values_per_vertex(shapes::vertex_attrib_variant vav) const {
        return _gen->values_per_vertex(vav);
    }

    span_size_t value_count(shapes::vertex_attrib_variant vav) const {
        return vertex_count() * values_per_vertex(vav);
    }

    template <typename A>
    data_type attrib_type(
      const basic_gl_api<A>& api, shapes::vertex_attrib_variant vav) const {
        return translate(api, _gen->attrib_type(vav));
    }

    template <typename A>
    true_false is_attrib_normalized(
      const basic_gl_api<A>& api, shapes::vertex_attrib_variant vav) const {
        return translate(api, _gen->is_attrib_normalized(vav));
    }

    span_size_t attrib_type_size(shapes::vertex_attrib_variant vav) const {
        return type_size(_gen->attrib_type(vav));
    }

    span_size_t attrib_data_block_size(
      shapes::vertex_attrib_variant vav) const {
        return value_count(vav) * attrib_type_size(vav);
    }

    void attrib_data(shapes::vertex_attrib_variant, memory::block data) const;

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
      shapes::vertex_attrib_variant attrib_variant,
      memory::buffer& temp) const;

    template <typename A>
    void index_setup(
      const basic_gl_api<A>& api, buffer_name buf, memory::buffer& temp) const;

    template <typename A>
    void instructions(const basic_gl_api<A>&, span<shape_draw_operation>) const;

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
} // namespace oglp
} // namespace eagine

#include <oglplus/shapes/generator.inl>

#endif // OGLPLUS_SHAPES_GENERATOR_HPP
