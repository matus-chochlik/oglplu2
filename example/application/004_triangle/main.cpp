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

namespace eagine::application {
//------------------------------------------------------------------------------
class example_triangle : public application {
public:
    example_triangle(execution_context&, video_context&);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void update() noexcept final;

    void cleanup() noexcept final;

private:
    video_context& _video;
    timeout _is_done{std::chrono::seconds(10)};

    oglp::triangle tri{
      oglp::vec3{-0.2F, 0.5F, 0.0F},
      oglp::vec3{-0.7F, -0.6F, 0.0F},
      oglp::vec3{0.6F, 0.2F, 0.0F}};

    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name colors;

    oglp::owned_program_name prog;
};
//------------------------------------------------------------------------------
example_triangle::example_triangle(execution_context&, video_context& vc)
  : _video{vc} {
    auto& [gl, GL] = _video.gl_api();

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    // vertex shader
    auto vs_source = embed(EAGINE_ID(VertShader), "vertex.glsl");
    oglp::owned_shader_name vs;
    gl.create_shader(GL.vertex_shader) >> vs;
    auto cleanup_vs = gl.delete_shader.raii(vs);
    gl.shader_source(vs, oglp::glsl_string_ref(vs_source));
    gl.compile_shader(vs);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    oglp::owned_shader_name fs;
    gl.create_shader(GL.fragment_shader) >> fs;
    auto cleanup_fs = gl.delete_shader.raii(fs);
    gl.shader_source(fs, oglp::glsl_string_ref(fs_src));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    // vao
    gl.gen_vertex_arrays() >> vao;
    gl.bind_vertex_array(vao);

    // positions
    const auto position_data = GL.float_.array(
      tri.a().x(),
      tri.a().y(),
      tri.b().x(),
      tri.b().y(),
      tri.c().x(),
      tri.c().y());

    gl.gen_buffers() >> positions;
    gl.bind_buffer(GL.array_buffer, positions);
    gl.buffer_data(GL.array_buffer, view(position_data), GL.static_draw);
    oglp::vertex_attrib_location position_loc;
    gl.get_attrib_location(prog, "Position") >> position_loc;

    gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(position_loc);

    // colors
    const auto color_data =
      GL.float_.array(1.0F, 0.1F, 0.1F, 0.1F, 1.0F, 0.1F, 0.1F, 0.1F, 1.0F);

    gl.gen_buffers() >> colors;
    gl.bind_buffer(GL.array_buffer, colors);
    gl.buffer_data(GL.array_buffer, view(color_data), GL.static_draw);
    oglp::vertex_attrib_location color_loc;
    gl.get_attrib_location(prog, "Color") >> color_loc;

    gl.vertex_attrib_pointer(color_loc, 3, GL.float_, GL.false_);
    gl.enable_vertex_attrib_array(color_loc);

    gl.disable(GL.depth_test);
}
//------------------------------------------------------------------------------
void example_triangle::update() noexcept {
    auto& [gl, GL] = _video.gl_api();

    gl.clear(GL.color_buffer_bit);
    gl.draw_arrays(GL.triangles, 0, 3);

    _video.commit();
}
//------------------------------------------------------------------------------
void example_triangle::cleanup() noexcept {
    auto& gl = _video.gl_api();

    gl.delete_program(std::move(prog));
    gl.delete_buffers(std::move(positions));
    gl.delete_buffers(std::move(colors));
    gl.delete_vertex_arrays(std::move(vao));

    _video.end();
}
//------------------------------------------------------------------------------
class example_launchpad : public launchpad {
public:
    auto setup(main_ctx&, launch_options& opts) -> bool final {
        opts.no_audio().no_input().require_video();
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
                    return {std::make_unique<example_triangle>(ec, vc)};
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
