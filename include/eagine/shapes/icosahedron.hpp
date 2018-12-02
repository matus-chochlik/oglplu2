/**
 *  @file eagine/shapes/icosahedron.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_ICOSAHEDRON_1509260923_HPP
#define EAGINE_SHAPES_ICOSAHEDRON_1509260923_HPP

#include <cassert>
#include <eagine/config/basic.hpp>
#include "gen_base.hpp"

namespace eagine {
namespace shapes {

class unit_icosahedron_gen : public centered_unit_shape_generator_base {
private:
    typedef centered_unit_shape_generator_base _base;

    static vertex_attrib_bits _attr_mask() noexcept;

    static vertex_attrib_bits _shared_attrs() noexcept;

    bool _only_shared_attribs() const noexcept;

public:
    unit_icosahedron_gen(vertex_attrib_bits attr_bits) noexcept;

    span_size_t vertex_count() override;

    void positions(const span<float>& dest) noexcept;

    void attrib_values(
      vertex_attrib_kind attr, const span<float>& dest) override;

    index_data_type index_type() override;

    span_size_t index_count() override;

    void indices(const span<unsigned>& dest) override;

    span_size_t operation_count() override;

    void instructions(const span<draw_operation>& ops) override;
};

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/icosahedron.inl>
#endif

#endif // include guard
