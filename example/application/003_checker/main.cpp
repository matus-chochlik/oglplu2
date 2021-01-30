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

namespace eagine::application {
//------------------------------------------------------------------------------
class example_checker : public application {
public:
    example_checker(execution_context& ec, video_context& vc);

    auto is_done() noexcept -> bool final {
        return _is_done.is_expired();
    }

    void on_video_resize() noexcept final;
    void update() noexcept final;
    void cleanup() noexcept final;

private:
    execution_context& _ec;
    video_context& _video;
    timeout _is_done{std::chrono::seconds(8)};

    oglp::owned_program_name prog;
};
//------------------------------------------------------------------------------
example_checker::example_checker(execution_context& ec, video_context& vc)
  : _ec{ec}
  , _video{vc} {
    auto& [gl, GL] = _video.gl_api();
    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    oglp::owned_shader_name fs;
    gl.create_shader(GL.fragment_shader) >> fs;
    const auto cleanup_fs = gl.delete_shader.raii(fs);
    gl.shader_source(fs, oglp::glsl_string_ref(fs_src));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    ec.connect_inputs().map_inputs().switch_input_mapping();
}
//------------------------------------------------------------------------------
void example_checker::on_video_resize() noexcept {
    auto& [gl, GL] = _video.gl_api();

    gl.viewport(_video.surface_size());

    const auto h = GL.double_(2);
    const auto w = h * GL.double_(_video.surface_aspect());

    gl.matrix_mode(GL.projection);
    gl.load_identity();
    gl.ortho(-w, +w, -h, +h, 0, 1);
}
//------------------------------------------------------------------------------
void example_checker::update() noexcept {
    auto& [gl, GL] = _video.gl_api();

    gl.clear(GL.color_buffer_bit);

    gl.matrix_mode(GL.modelview);
    gl.load_identity();
    gl.rotate_f(degrees_(_ec.state().frame_time().value() * 90), 0, 0, 1);

    gl.begin(GL.quads);

    gl.tex_coord2i(0, 0);
    gl.color3f(1.0F, 1.0F, 1.0F);
    gl.vertex2i(-1, -1);

    gl.tex_coord2i(1, 0);
    gl.color3f(1.0F, 0.2F, 0.2F);
    gl.vertex2i(+1, -1);

    gl.tex_coord2i(1, 1);
    gl.color3f(0.2F, 1.0F, 0.2F);
    gl.vertex2i(+1, +1);

    gl.tex_coord2i(0, 1);
    gl.color3f(0.2F, 0.2F, 1.0F);
    gl.vertex2i(-1, +1);

    gl.end();

    _video.commit();
}
//------------------------------------------------------------------------------
void example_checker::cleanup() noexcept {
    auto& gl = _video.gl_api();

    gl.delete_program(std::move(prog));
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

        return gl.viewport && gl.clear_color && gl.clear &&
               GL.color_buffer_bit && gl.load_identity && gl.ortho &&
               gl.rotate_f && gl.begin && gl.end && gl.vertex2i && gl.color3f &&
               gl.tex_coord2i && GL.modelview && GL.projection &&
               GL.triangle_fan && GL.line_loop && gl.create_shader &&
               gl.shader_source && gl.compile_shader && GL.fragment_shader &&
               gl.create_program && gl.attach_shader && gl.link_program;
    }

    auto launch(execution_context& ec, const launch_options&)
      -> std::unique_ptr<application> final {
        if(auto opt_vc{ec.video_ctx()}) {
            auto& vc = extract(opt_vc);
            vc.begin();
            if(vc.init_gl_api()) {
                if(check_requirements(vc)) {
                    return {std::make_unique<example_checker>(ec, vc)};
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
