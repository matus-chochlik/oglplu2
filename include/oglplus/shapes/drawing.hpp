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
#include "../gl_api/enum_types.hpp"
#include "../utils/span.hpp"
#include <eagine/shapes/drawing.hpp>

namespace eagine {
namespace oglp {
namespace shapes {

class draw_operation {
private:
    static primitive_type _translate(eagine::shapes::primitive_type) noexcept;

    static data_type _translate(eagine::shapes::index_data_type) noexcept;

    static span_size_t _byte_mult(eagine::shapes::index_data_type) noexcept;

    primitive_type _mode;
    data_type _idx_type;
    GLint _first{0};
    GLsizei _count{0};
    [[maybe_unused]] GLuint _phase{0};
    [[maybe_unused]] GLuint _primitive_restart_index{0};
    [[maybe_unused]] GLint _patch_vertices{3};
    [[maybe_unused]] bool _primitive_restart : 1;
    bool _cw_face_winding : 1;

    const void* _idx_ptr() const noexcept;

public:
    constexpr draw_operation() noexcept
      : _mode(primitive_type(GL_NONE))
      , _idx_type(data_type(GL_NONE))
      , _primitive_restart(false)
      , _cw_face_winding(false) {
    }

    draw_operation(const shapes::draw_operation& draw_op) noexcept;

    bool indexed() const noexcept;

    outcome<void> draw() const noexcept;
};

outcome<void> draw_using_instructions(span<const draw_operation> ops) noexcept;

} // namespace shapes
} // namespace oglp
} // namespace eagine

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/drawing.inl>
#endif

#endif // OGLPLUS_SHAPES_DRAWING_HPP
