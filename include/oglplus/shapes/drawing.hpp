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

namespace eagine::oglp {
//------------------------------------------------------------------------------
template <typename A>
auto translate(const basic_gl_api<A>&, shapes::primitive_type) noexcept
  -> primitive_type;
//------------------------------------------------------------------------------
template <typename A>
auto translate(const basic_gl_api<A>&, shapes::attrib_data_type) noexcept
  -> data_type;
//------------------------------------------------------------------------------
template <typename A>
auto translate(const basic_gl_api<A>&, shapes::index_data_type) noexcept
  -> index_data_type;
//------------------------------------------------------------------------------
template <typename A>
auto type_size(const basic_gl_api<A>&, shapes::attrib_data_type) noexcept
  -> span_size_t;
//------------------------------------------------------------------------------
template <typename A>
auto type_size(const basic_gl_api<A>&, shapes::index_data_type) noexcept
  -> span_size_t;
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

    auto _idx_ptr() const noexcept -> gl_types::const_void_ptr_type;

public:
    constexpr shape_draw_operation() noexcept = default;

    template <typename A>
    shape_draw_operation(
      const basic_gl_api<A>& api,
      const shapes::draw_operation& draw_op) noexcept;

    auto offset_first(span_size_t offs) noexcept -> auto& {
        _first += offs;
        return *this;
    }

    auto phase() const noexcept {
        return _phase;
    }

    template <typename A>
    auto is_indexed(const basic_gl_api<A>& api) const noexcept -> bool {
        const basic_gl_constants<A>& GL = api;
        return _idx_type != GL.none;
    }

    template <typename A>
    void draw(const basic_gl_api<A>& api) const noexcept;
};
//------------------------------------------------------------------------------
struct shape_draw_subset {
    span_size_t first{0};
    span_size_t count{0};
};
//------------------------------------------------------------------------------
template <typename A>
void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops) noexcept;
//------------------------------------------------------------------------------
template <typename A>
void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  const shape_draw_subset& subs) noexcept;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#include <oglplus/shapes/drawing.inl>

#endif // OGLPLUS_SHAPES_DRAWING_HPP
