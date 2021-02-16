/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/application/main.hpp>
#include <eagine/application_config.hpp>
#include <eagine/embed.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/timeout.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class example_atomics : public application {
public:
    example_atomics(execution_context& ctx, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void clean_up() noexcept final;

private:
    execution_context& _ctx;
    video_context& _video;
    timeout _is_done{std::chrono::seconds(20)};

    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name counters;

    oglp::owned_program_name prog;
};
//------------------------------------------------------------------------------
example_atomics::example_atomics(execution_context& ec, video_context& vc)
  : _ctx{ec}
  , _video{vc} {
    auto& [gl, GL] = _video.gl_api();

    // vertex shader
    oglp::owned_shader_name vs;
    auto vs_cleanup = gl.delete_shader.raii(vs);
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    gl.create_shader(GL.vertex_shader) >> vs;
    gl.shader_source(vs, oglp::glsl_string_ref(vs_source.unpack(ec)));
    gl.compile_shader(vs);

    // geometry shader
    oglp::owned_shader_name gs;
    auto gs_cleanup = gl.delete_shader.raii(gs);
    auto gs_source = embed(EAGINE_ID(GeomShader), "geometry.glsl");
    gl.create_shader(GL.geometry_shader) >> gs;
    gl.shader_source(gs, oglp::glsl_string_ref(gs_source.unpack(ec)));
    gl.compile_shader(gs);

    // fragment shader
    oglp::owned_shader_name fs;
    auto fs_cleanup = gl.delete_shader.raii(fs);
    auto fs_source = embed(EAGINE_ID(FragShader), "fragment.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.shader_source(fs, oglp::glsl_string_ref(fs_source.unpack(ec)));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, gs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    const auto position_data =
      GL.float_.array(-1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, 1.0F);

    gl.gen_buffers() >> positions;
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    oglp::vertex_attrib_location position_loc;
    gl.get_attrib_location(prog, "Position") >> position_loc;

    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    // counters
    const auto counter_values = GL.unsigned_int_.array(0U, 0U, 0U);

    gl.gen_buffers() >> counters;
    gl.bind_buffer(GL.atomic_counter_buffer, counters);
    gl.bind_buffer_base(GL.atomic_counter_buffer, 0, counters);
    gl.buffer_data(
      GL.atomic_counter_buffer, view(counter_values), GL.dynamic_draw);

    gl.disable(GL.depth_test);

    ec.connect_inputs().map_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_atomics::on_video_resize() noexcept {
    auto& gl = _video.gl_api();
    gl.viewport(_video.surface_size());
}
//------------------------------------------------------------------------------
void example_atomics::update() noexcept {
    auto& state = _ctx.state();
    auto& [gl, GL] = _video.gl_api();

    if(state.is_active()) {
        _is_done.reset();
    }

    gl.clear(GL.color_buffer_bit);
    gl.draw_arrays(GL.triangle_strip, 0, 4);

    const auto counter_values = GL.unsigned_int_.array(0U, 0U, 0U);
    gl.buffer_data(
      GL.atomic_counter_buffer, view(counter_values), GL.dynamic_draw);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_atomics::clean_up() noexcept {
    auto& gl = _video.gl_api();

    gl.delete_program(std::move(prog));
    gl.delete_buffers(std::move(counters));
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
                    return {std::make_unique<example_atomics>(ec, vc)};
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
