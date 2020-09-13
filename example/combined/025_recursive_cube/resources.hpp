/**
 *  example combined/025_recursive_cube/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/double_buffer.hpp>
#include <eagine/quantities.hpp>
#include <oglplus/shapes/drawing.hpp>

namespace eagine {
class example_context;
namespace oglp {
class example_orbiting_camera;
//------------------------------------------------------------------------------
// program
//------------------------------------------------------------------------------
class cube_program {
private:
    owned_program_name prog;
    uniform_location projection_loc;
    uniform_location modelview_loc;
    uniform_location light_pos_loc;
    uniform_location cube_tex_loc;

    radians_t<float> rad{0.f};

public:
    void init(example_context& ctx);
    void set_texture(const example_context& ctx, gl_types::int_type);
    void
    set_projection(const example_context& ctx, const tmat<float, 4, 4, true>&);
    void update(const example_context& ctx);

    void bind_position_location(
      const example_context& ctx,
      vertex_attrib_location loc);
    void bind_normal_location(
      const example_context& ctx,
      vertex_attrib_location loc);
    void bind_tex_coord_location(
      const example_context& ctx,
      vertex_attrib_location loc);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class cube_geometry {
private:
    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name normals;
    owned_buffer_name tex_coords;
    owned_buffer_name indices;

    std::vector<shape_draw_operation> ops;

public:
    void init(example_context& ctx);
    void draw(const example_context& ctx);

    static auto position_loc() noexcept {
        return vertex_attrib_location{0};
    }

    static auto normal_loc() noexcept {
        return vertex_attrib_location{1};
    }

    static auto tex_coord_loc() noexcept {
        return vertex_attrib_location{2};
    }
};
//------------------------------------------------------------------------------
// draw buffers
//------------------------------------------------------------------------------
class cube_draw_buffers {
private:
    const gl_types::sizei_type tex_side{512};

    struct _buffer_objects {
        gl_types::int_type tex_unit{};
        owned_texture_name tex{};
        owned_renderbuffer_name rbo{};
        owned_framebuffer_name fbo{};
    };

    double_buffer<_buffer_objects> objs{};

public:
    void init(example_context& ctx);

    auto back_fbo() const noexcept {
        return framebuffer_name{objs.back().fbo};
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
} // namespace oglp
} // namespace eagine
