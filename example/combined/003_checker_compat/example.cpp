/**
 *  example combined/003_checker_compat/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <oglplus/glsl/string_ref.hpp>

#include "../example.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_checker : public example {

    owned_shader_name fs;

    owned_program_name prog;

public:
    auto check_requirements(const example_context& ctx) -> bool final;
    void init(example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
// example_checker
//------------------------------------------------------------------------------
auto example_checker::check_requirements(const example_context& ctx) -> bool {
    const auto& [gl, GL] = ctx.gl();
    auto r = ctx.req_mark();

    return r(gl.viewport) && r(gl.clear_color) && r(gl.clear) &&
           r(GL.color_buffer_bit) && r(gl.load_identity) && r(gl.ortho) &&
           r(gl.rotate_f) && r(gl.begin) && r(gl.end) && r(gl.vertex2i) &&
           r(gl.color3f) && r(gl.tex_coord2i) && r(GL.modelview) &&
           r(GL.projection) && r(GL.triangle_fan) && r(GL.line_loop) &&
           r(gl.create_shader) && r(gl.shader_source) && r(gl.compile_shader) &&
           r(GL.fragment_shader) && r(gl.create_program) &&
           r(gl.attach_shader) && r(gl.link_program);
}
//------------------------------------------------------------------------------
void example_checker::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    gl.clear_color(0.4F, 0.4F, 0.4F, 0.0F);

    // fragment shader
    auto fs_src = embed(EAGINE_ID(FragShader), "fragment.glsl");
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.delete_shader.later_by(cleanup, fs);
    gl.shader_source(fs, glsl_string_ref(fs_src));
    gl.compile_shader(fs);

    // program
    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);
}
//------------------------------------------------------------------------------
void example_checker::resize(const example_context& ctx) {
    const auto& state = ctx.state();
    const auto& [gl, GL] = ctx.gl();

    gl.viewport(state.width(), state.height());

    const auto h = GL.double_(2);
    const auto w = h * GL.double_(state.aspect());

    gl.matrix_mode(GL.projection);
    gl.load_identity();
    gl.ortho(-w, +w, -h, +h, 0, 1);
}
//------------------------------------------------------------------------------
void example_checker::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    gl.clear(GL.color_buffer_bit);

    gl.matrix_mode(GL.modelview);
    gl.load_identity();
    gl.rotate_f(degrees_(ctx.state().exec_time().value() * 90), 0, 0, -1);

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
}
//------------------------------------------------------------------------------
} // namespace oglp
//------------------------------------------------------------------------------
auto make_example(const example_args&, const example_context&)
  -> std::unique_ptr<example> {
    return std::make_unique<oglp::example_checker>();
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.compatibility_context(true);
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
auto is_example_param(const example_arg&) -> bool {
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine
