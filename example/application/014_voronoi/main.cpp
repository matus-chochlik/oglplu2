/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/embed.hpp>
#include <eagine/timeout.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/math/vector.hpp>

#include "resources.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
class example_voronoi : public application {
public:
    example_voronoi(execution_context& ctx, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void cleanup() noexcept final;

    void dampening(const input&);
    void dragging(const input&);
    void zoom(const input&);
    void pan_x(const input&);
    void pan_y(const input&);

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds(30)};

    screen_geometry screen;
    voronoi_program voi_prog;
    random_texture rand_tex;

    float ofs_x_dir{1.F};
    float ofs_y_dir{1.F};
    float offset_x{-0.5F};
    float offset_y{0.0F};
    float scale_dir{1.F};
    float scale{1.0F};
    float aspect{1.0F};
    bool dampen_motion{false};
    bool is_dragging{false};

    auto motion_adjust() const noexcept {
        return dampen_motion ? 0.2 : 1.0;
    }

    static constexpr const float min_scale{1.F};
    static constexpr const float max_scale{100.0F};
};
//------------------------------------------------------------------------------
example_voronoi::example_voronoi(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {

    screen.init(ec, vc);
    voi_prog.init(ec, vc);
    rand_tex.init(ec, vc);

    auto& [gl, GL] = _video.gl_api();

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);
    gl.disable(GL.depth_test);

    ec.connect_inputs()
      .connect_input(
        EAGINE_MSG_ID(Motion, Dampening),
        {this, EAGINE_THIS_MEM_FUNC_C(dampening)})
      .connect_input(
        EAGINE_MSG_ID(Cursor, Dragging),
        {this, EAGINE_THIS_MEM_FUNC_C(dragging)})
      .connect_input(
        EAGINE_MSG_ID(View, Zoom), {this, EAGINE_THIS_MEM_FUNC_C(zoom)})
      .connect_input(
        EAGINE_MSG_ID(View, PanX), {this, EAGINE_THIS_MEM_FUNC_C(pan_x)})
      .connect_input(
        EAGINE_MSG_ID(View, PanY), {this, EAGINE_THIS_MEM_FUNC_C(pan_y)})
      .map_inputs()
      .map_input(
        EAGINE_MSG_ID(Motion, Dampening),
        EAGINE_MSG_ID(Keyboard, LeftCtrl),
        input_setup().trigger())
      .map_input(
        EAGINE_MSG_ID(Cursor, Dragging),
        EAGINE_MSG_ID(Cursor, Button0),
        input_setup().trigger())
      .map_input(
        EAGINE_MSG_ID(View, Zoom),
        EAGINE_MSG_ID(Wheel, ScrollY),
        input_setup().relative())
      .map_input(
        EAGINE_MSG_ID(View, Zoom),
        EAGINE_MSG_ID(Keyboard, KpPlus),
        input_setup().trigger().multiply(0.25))
      .map_input(
        EAGINE_MSG_ID(View, Zoom),
        EAGINE_MSG_ID(Keyboard, KpMinus),
        input_setup().trigger().multiply(0.25).invert())
      .map_input(
        EAGINE_MSG_ID(View, PanX),
        EAGINE_MSG_ID(Keyboard, Left),
        input_setup().trigger().multiply(0.25))
      .map_input(
        EAGINE_MSG_ID(View, PanX),
        EAGINE_MSG_ID(Keyboard, Right),
        input_setup().trigger().multiply(0.25).invert())
      .map_input(
        EAGINE_MSG_ID(View, PanY),
        EAGINE_MSG_ID(Keyboard, Down),
        input_setup().trigger().multiply(0.25))
      .map_input(
        EAGINE_MSG_ID(View, PanY),
        EAGINE_MSG_ID(Keyboard, Up),
        input_setup().trigger().multiply(0.25).invert())
      .map_input(
        EAGINE_MSG_ID(View, PanX),
        EAGINE_MSG_ID(Cursor, MotionX),
        input_setup().relative().multiply(2).only_if(is_dragging))
      .map_input(
        EAGINE_MSG_ID(View, PanY),
        EAGINE_MSG_ID(Cursor, MotionY),
        input_setup().relative().multiply(2).only_if(is_dragging))
      .switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_voronoi::on_video_resize() noexcept {
    auto& gl = _video.gl_api();

    aspect = _video.surface_aspect();
    gl.viewport(_video.surface_size());
    gl.uniform2f(voi_prog.scale_loc, scale * aspect, scale);
}
//------------------------------------------------------------------------------
void example_voronoi::dampening(const input& i) {
    dampen_motion = bool(i);
}
//------------------------------------------------------------------------------
void example_voronoi::dragging(const input& i) {
    is_dragging = bool(i);
}
//------------------------------------------------------------------------------
void example_voronoi::zoom(const input& i) {
    scale *= float(std::pow(2, -i.get() * motion_adjust()));
    if(scale < min_scale) {
        scale = min_scale;
    }
    if(scale > max_scale) {
        scale = max_scale;
    }

    auto& gl = _video.gl_api();
    gl.uniform2f(voi_prog.scale_loc, scale * aspect, scale);
}
//------------------------------------------------------------------------------
void example_voronoi::pan_x(const input& i) {
    offset_x -= float(i.get() * scale * motion_adjust());

    auto& gl = _video.gl_api();
    gl.uniform2f(voi_prog.offset_loc, offset_x, offset_y);
}
//------------------------------------------------------------------------------
void example_voronoi::pan_y(const input& i) {
    offset_y -= float(i.get() * scale * motion_adjust());

    auto& gl = _video.gl_api();
    gl.uniform2f(voi_prog.offset_loc, offset_x, offset_y);
}
//------------------------------------------------------------------------------
void example_voronoi::update() noexcept {
    auto& state = _ctx.state();
    auto& [gl, GL] = _video.gl_api();

    if(!state.user_is_idle()) {
        _is_done.reset();
    } else if(state.user_idle_time() > std::chrono::seconds(1)) {
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

    gl.clear(GL.color_buffer_bit);
    gl.draw_arrays(GL.triangle_strip, 0, 4);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_voronoi::cleanup() noexcept {
    screen.init(_ctx, _video);
    voi_prog.init(_ctx, _video);
    rand_tex.init(_ctx, _video);
}
//------------------------------------------------------------------------------
class example_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.no_audio().require_input().require_video();
        return true;
    }

    auto check_requirements(video_context& vc) -> bool {
        auto& [gl, GL] = vc.gl_api();

        return gl.disable && gl.clear_color && gl.create_shader &&
               gl.shader_source && gl.compile_shader && gl.create_program &&
               gl.attach_shader && gl.link_program && gl.use_program &&
               gl.gen_buffers && gl.bind_buffer && gl.buffer_data &&
               gl.gen_vertex_arrays && gl.bind_vertex_array &&
               gl.get_attrib_location && gl.vertex_attrib_pointer &&
               gl.enable_vertex_attrib_array && gl.draw_arrays &&
               GL.vertex_shader && GL.fragment_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_voronoi>(ec, vc)};
                }
            }
        }
        return {};
    }
};
//------------------------------------------------------------------------------
auto establish(main_ctx&) -> std::unique_ptr<launchpad> {
    return {std::make_unique<example_launchpad>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
