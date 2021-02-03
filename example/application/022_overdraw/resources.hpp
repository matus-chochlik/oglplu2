/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_EXAMPLE_RESOURCES_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_RESOURCES_HPP

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/fwd.hpp>
#include <oglplus/shapes/drawing.hpp>
#include <vector>

namespace eagine::application {
class example;
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
class draw_program {
private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _camera_loc;

public:
    void init(example&);
    void set_projection(example&);

    void bind_position_location(example&, oglp::vertex_attrib_location);

    void use(example&);
};
//------------------------------------------------------------------------------
class screen_program {
private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _screen_size_loc;

public:
    void init(example&);

    void bind_position_location(example&, oglp::vertex_attrib_location);
    void set_screen_size(example&);

    void use(example&);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class shape_geometry {
private:
    const int count = 8;

    oglp::owned_vertex_array_name _vao;

    oglp::owned_buffer_name _positions;
    oglp::owned_buffer_name _indices;

    oglp::owned_buffer_name _offsets;

    std::vector<oglp::shape_draw_operation> _ops{};

public:
    void init(example&);
    void draw(example&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }
};
//------------------------------------------------------------------------------
// draw buffers
//------------------------------------------------------------------------------
class draw_buffers {
private:
    oglp::gl_types::sizei_type _width{0};
    oglp::gl_types::sizei_type _height{0};
    oglp::gl_types::int_type _tex_unit{};
    oglp::owned_texture_name _tex{};
    oglp::owned_renderbuffer_name _rbo{};
    oglp::owned_framebuffer_name _fbo{};

public:
    void init(example&);
    void resize(example&);

    auto tex_unit() const noexcept {
        return _tex_unit;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
