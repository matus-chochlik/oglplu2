/// @example application/006_writing/main.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/camera.hpp>
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/embed.hpp>
#include <eagine/math/curve.hpp>
#include <eagine/memory/flatten.hpp>
#include <eagine/timeout.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_writing : public application {
public:
    example_writing(execution_context&, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void clean_up() noexcept final;

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds{30}};

    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::gl_types::sizei_type point_count{0};

    oglp::owned_program_name prog;
};
//------------------------------------------------------------------------------
example_writing::example_writing(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    // vertex shader
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    oglp::owned_shader_name vs;
    gl.create_shader(GL.vertex_shader) >> vs;
    auto cleanup_vs = gl.delete_shader.raii(vs);
    gl.shader_source(vs, oglp::glsl_string_ref(vs_source));
    gl.compile_shader(vs);

    // geometry shader
    auto gs_source = embed(EAGINE_ID(GeomShader), "geometry.glsl");
    oglp::owned_shader_name gs;
    gl.create_shader(GL.geometry_shader) >> gs;
    auto cleanup_gs = gl.delete_shader.raii(gs);
    gl.shader_source(gs, oglp::glsl_string_ref(gs_source));
    gl.compile_shader(gs);

    // fragment shader
    auto fs_source = embed(EAGINE_ID(FragShader), "fragment.glsl");
    oglp::owned_shader_name fs;
    gl.create_shader(GL.fragment_shader) >> fs;
    auto cleanup_fs = gl.delete_shader.raii(fs);
    gl.shader_source(fs, oglp::glsl_string_ref(fs_source));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, gs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // geometry
    const std::array<oglp::vec2, 34> control_points{
      {{-0.33F, +0.50F}, {-0.45F, +0.70F}, {-0.66F, +0.70F}, {-0.66F, +0.30F},
       {-0.66F, -0.20F}, {-0.35F, -0.15F}, {-0.30F, +0.05F}, {-0.20F, +0.50F},
       {-0.30F, +0.50F}, {-0.33F, +0.50F}, {-0.50F, +0.45F}, {-0.10F, +0.40F},
       {+0.10F, +0.55F}, {-0.20F, +0.40F}, {-0.30F, -0.10F}, {+0.00F, -0.10F},
       {+0.10F, -0.10F}, {+0.20F, -0.10F}, {+0.10F, +0.55F}, {+0.20F, +0.00F},
       {+0.30F, -0.70F}, {+0.00F, -0.75F}, {-0.40F, -0.75F}, {+0.00F, +0.00F},
       {+0.40F, +0.10F}, {+0.60F, +0.10F}, {+0.70F, +0.90F}, {+0.55F, +0.90F},
       {+0.35F, +0.90F}, {+0.10F, -0.10F}, {+0.55F, +0.00F}, {+0.90F, +0.10F},
       {+0.70F, +0.10F}, {+0.90F, +0.20F}}};

    math::bezier_curves<oglp::vec2, float, 3> curve(view(control_points));
    std::vector<oglp::vec2> curve_points;
    curve.approximate(curve_points, 20);
    std::vector<float> position_data;
    memory::flatten(view(curve_points), position_data);
    point_count = limit_cast<decltype(point_count)>(curve_points.size());

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    gl.gen_buffers() >> positions;
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);

    oglp::vertex_attrib_location position_loc;
    gl.get_attrib_location(prog, "Position") >> position_loc;
    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    //
    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);
    gl.disable(GL.depth_test);
    gl.disable(GL.cull_face);

    ec.setup_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_writing::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_writing::update() noexcept {
    auto& state = _ctx.state();
    if(state.is_active()) {
        _is_done.reset();
    }

    auto& glapi = _video.gl_api();
    auto& [gl, GL] = glapi;

    gl.clear(GL.color_buffer_bit);
    gl.draw_arrays(GL.line_strip, 0, point_count);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_writing::clean_up() noexcept {
    auto& gl = _video.gl_api();

    gl.delete_program(std::move(prog));
    gl.delete_buffers(std::move(positions));
    gl.delete_vertex_arrays(std::move(vao));

    _video.end();
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
               GL.vertex_shader && GL.geometry_shader && GL.fragment_shader;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_writing>(ec, vc)};
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
