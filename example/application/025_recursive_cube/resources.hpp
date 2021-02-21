/// @example application/025_recursive_cube/resources.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef OGLPLUS_EXAMPLE_RESOURCES_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_RESOURCES_HPP

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/fwd.hpp>
#include <eagine/double_buffer.hpp>
#include <eagine/quantities.hpp>
#include <oglplus/shapes/drawing.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class cube_program {
private:
    oglp::owned_program_name prog;
    oglp::uniform_location projection_loc;
    oglp::uniform_location modelview_loc;
    oglp::uniform_location light_pos_loc;
    oglp::uniform_location cube_tex_loc;

    radians_t<float> rad{0.F};

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void set_texture(video_context&, oglp::gl_types::int_type);
    void set_projection(video_context&, const oglp::tmat<float, 4, 4, true>&);
    void update(execution_context&, video_context&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_normal_location(video_context&, oglp::vertex_attrib_location);
    void bind_tex_coord_location(video_context&, oglp::vertex_attrib_location);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class cube_geometry {
private:
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name normals;
    oglp::owned_buffer_name tex_coords;
    oglp::owned_buffer_name indices;

    std::vector<oglp::shape_draw_operation> ops;

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);
    void draw(video_context&);

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto normal_loc() noexcept {
        return oglp::vertex_attrib_location{1};
    }

    static auto tex_coord_loc() noexcept {
        return oglp::vertex_attrib_location{2};
    }
};
//------------------------------------------------------------------------------
// draw buffers
//------------------------------------------------------------------------------
class cube_draw_buffers {
private:
    const oglp::gl_types::sizei_type tex_side{512};

    struct _buffer_objects {
        oglp::gl_types::int_type tex_unit{};
        oglp::owned_texture_name tex{};
        oglp::owned_renderbuffer_name rbo{};
        oglp::owned_framebuffer_name fbo{};
    };

    double_buffer<_buffer_objects> objs{};

public:
    void init(execution_context&, video_context&);
    void clean_up(video_context&);

    auto back_fbo() const noexcept {
        return oglp::framebuffer_name{objs.back().fbo};
    }

    auto front_tex_unit() const noexcept {
        return objs.front().tex_unit;
    }

    auto side() const noexcept {
        return tex_side;
    }

    void swap() {
        objs.swap();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
