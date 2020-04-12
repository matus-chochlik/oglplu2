/**
 *  @file oglplus/shapes/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_DRAWING_HPP
#define OGLPLUS_SHAPES_DRAWING_HPP

#include "../config/basic.hpp"
#include "../gl_api.hpp"
#include <eagine/shapes/drawing.hpp>
#include <eagine/span.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename A>
primitive_type translate(
  const basic_gl_api<A>&, shapes::primitive_type) noexcept;
//------------------------------------------------------------------------------
template <typename A>
data_type translate(const basic_gl_api<A>&, shapes::attrib_data_type) noexcept;
//------------------------------------------------------------------------------
template <typename A>
index_data_type translate(
  const basic_gl_api<A>&, shapes::index_data_type) noexcept;
//------------------------------------------------------------------------------
template <typename A>
span_size_t type_size(
  const basic_gl_api<A>&, shapes::attrib_data_type) noexcept;
//------------------------------------------------------------------------------
template <typename A>
span_size_t type_size(const basic_gl_api<A>&, shapes::index_data_type) noexcept;
//------------------------------------------------------------------------------
class shape_draw_operation {
private:
    primitive_type _mode{0};
    index_data_type _idx_type{0};
    gl_types::int_type _first{0};
    gl_types::sizei_type _count{0};
    gl_types::uint_type _phase{0};
    gl_types::uint_type _primitive_restart_index{0};
    gl_types::int_type _patch_vertices{3};
    bool _primitive_restart{false};
    bool _cw_face_winding{false};

    gl_types::const_void_ptr_type _idx_ptr() const noexcept;

public:
    constexpr shape_draw_operation() noexcept = default;

    template <typename A>
    shape_draw_operation(
      const basic_gl_api<A>& api,
      const shapes::draw_operation& draw_op) noexcept;

    auto phase() const noexcept {
        return _phase;
    }

    template <typename A>
    bool is_indexed(const basic_gl_api<A>& api) const noexcept {
        const basic_gl_constants<A>& GL = api;
        return _idx_type != GL.none;
    }

    template <typename A>
    void draw(const basic_gl_api<A>& api) const noexcept;
};
//------------------------------------------------------------------------------
template <typename A>
void draw_using_instructions(
  const basic_gl_api<A>& api, span<const shape_draw_operation> ops) noexcept;
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#include <oglplus/shapes/drawing.inl>

#endif // OGLPLUS_SHAPES_DRAWING_HPP
