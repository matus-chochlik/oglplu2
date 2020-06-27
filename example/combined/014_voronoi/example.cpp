/**
 *  example combined/014_voronoi/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "../example.hpp"
#include "resources.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// example_voronoi
//------------------------------------------------------------------------------
class example_voronoi : public example {
private:
    screen_geometry screen;
    voronoi_program voi_prog;
    random_texture rand_tex;

    float ofs_x_dir{1.F};
    float ofs_y_dir{1.F};
    float offset_x{-0.5F};
    float offset_y{0.0F};
    float scale_dir{1.F};
    float scale{10.F};
    float aspect{1.0F};

    static constexpr const float min_scale{1.F};
    static constexpr const float max_scale{100.F};

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void pointer_motion(const example_context& ctx) final;
    void pointer_scrolling(const example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void user_idle(const example_context& ctx) final;
    void render(const example_context&) final;
    seconds_t<float> default_timeout() final;
};
//------------------------------------------------------------------------------
// example_voronoi
//------------------------------------------------------------------------------
bool example_voronoi::check_requirements(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();
    // TODO
    return r(gl.disable) && r(gl.clear_color) && r(gl.create_shader) &&
           r(GL.vertex_shader) && r(GL.fragment_shader);
}
//------------------------------------------------------------------------------
void example_voronoi::init(example_context& ctx) {

    screen.init(ctx);
    voi_prog.init(ctx);
    rand_tex.init(ctx);

    const auto& [gl, GL] = ctx.gl();

    gl.bind_attrib_location(voi_prog.prog, screen.position_loc, "Position");
    gl.bind_attrib_location(voi_prog.prog, screen.tex_coord_loc, "TexCoord");

    gl.uniform2f(voi_prog.offset_loc, offset_x, offset_y);
    gl.uniform2f(voi_prog.scale_loc, aspect * scale, scale);

    gl.disable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_voronoi::pointer_motion(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    if(state.pointer_dragging()) {
        offset_x -= 2 * state.norm_pointer_x().delta() * scale;
        offset_y -= 2 * state.norm_pointer_y().delta() * scale;

        gl.uniform2f(voi_prog.offset_loc, offset_x, offset_y);
    }
}
//------------------------------------------------------------------------------
void example_voronoi::pointer_scrolling(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    scale *= float(std::pow(2, -state.norm_pointer_z().delta()));
    if(scale < min_scale) {
        scale = min_scale;
    }
    if(scale > max_scale) {
        scale = max_scale;
    }

    gl.uniform2f(voi_prog.scale_loc, scale * aspect, scale);
}
//------------------------------------------------------------------------------
void example_voronoi::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    gl.viewport(state.width(), state.height());

    aspect = state.aspect();
    gl.uniform2f(voi_prog.scale_loc, scale * aspect, scale);
}
//------------------------------------------------------------------------------
void example_voronoi::user_idle(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& gl = ctx.gl();

    if(state.user_idle_time() > seconds_(1)) {
        const float s = value(state.frame_duration()) * 60;

        scale *= std::pow(1.F + 0.05F * s, scale_dir);
        if(scale < min_scale) {
            scale_dir *= -1.F;
            ofs_x_dir *= -1.F;
            ofs_y_dir *= ofs_x_dir;
            scale = min_scale;
        }
        if(scale > max_scale) {
            scale_dir *= -1.F;
            ofs_y_dir *= -1.F;
            ofs_x_dir *= ofs_y_dir;
            scale = max_scale;
        }

        offset_x += ofs_x_dir * s * scale / 30;
        offset_y += ofs_y_dir * s * scale / 30;

        gl.uniform2f(voi_prog.offset_loc, offset_x, offset_y);
        gl.uniform2f(voi_prog.scale_loc, scale * aspect, scale);
    }
}
//------------------------------------------------------------------------------
seconds_t<float> example_voronoi::default_timeout() {
    return seconds_(30);
}
//------------------------------------------------------------------------------
void example_voronoi::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    gl.draw_arrays(GL.triangle_strip, 0, 4);
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return std::make_unique<oglp::example_voronoi>();
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.rand_seed(2345);
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
