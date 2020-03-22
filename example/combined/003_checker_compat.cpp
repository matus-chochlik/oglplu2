/**
 *  example oglplus/003_checker_compat.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>
#include <oglplus/glsl/string_ref.hpp>

#include "example.hpp"
// clang-format on
#include <iostream>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class example_checked : public example {

    owned_shader_name fs;

    owned_program_name prog;

public:
    bool check_requirements(const example_context& ctx) final;
    void init(example_context& ctx) final;
    void resize(const example_context& ctx) final;
    void render(const example_context& ctx) final;
};
//------------------------------------------------------------------------------
bool example_checked::check_requirements(const example_context& ctx) {
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
void example_checked::init(example_context& ctx) {
    auto& cleanup = ctx.cleanup();
    const auto& [gl, GL] = ctx.gl();

    gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);

    // fragment shader
    gl.create_shader(GL.fragment_shader) >> fs;
    gl.delete_shader.later_by(cleanup, fs);
    gl.shader_source(
      fs,
      glsl_literal(
        "#version 140\n"
        "out vec3 fragColor;\n"
        "void main()\n"
        "{\n"
        "	vec2 co = gl_TexCoord[0].xy * vec2(8.0);\n"
        "	float ck = mod(mod(int(co.x), 2) + mod(int(co.y), 2), 2);\n"
        "	fragColor = mix(vec3(0.0), gl_Color.rgb, ck);\n"
        "}\n"));
    gl.compile_shader(fs);

    std::array<char, 1024> x;
    std::cout << extract(gl.get_shader_info_log(fs, cover(x))) << std::endl;

    // program
    gl.create_program() >> prog;
    gl.delete_program.later_by(cleanup, prog);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);
}
//------------------------------------------------------------------------------
void example_checked::resize(const example_context& ctx) {
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
void example_checked::render(const example_context& ctx) {
    const auto& [gl, GL] = ctx.gl();
    gl.clear(GL.color_buffer_bit);

    gl.matrix_mode(GL.modelview);
    gl.load_identity();
    gl.rotate_f(degrees_(ctx.state().exec_time().value() * 90), 0, 0, -1);

    gl.begin(GL.quads);

    gl.tex_coord2i(0, 0);
    gl.color3f(1.0f, 1.0f, 1.0f);
    gl.vertex2i(-1, -1);

    gl.tex_coord2i(1, 0);
    gl.color3f(1.0f, 0.2f, 0.2f);
    gl.vertex2i(+1, -1);

    gl.tex_coord2i(1, 1);
    gl.color3f(0.2f, 1.0f, 0.2f);
    gl.vertex2i(+1, +1);

    gl.tex_coord2i(0, 1);
    gl.color3f(0.2f, 0.2f, 1.0f);
    gl.vertex2i(-1, +1);

    gl.end();
}
//------------------------------------------------------------------------------
std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return std::make_unique<example_checked>();
}
//------------------------------------------------------------------------------
void adjust_params(example_params& params) {
    params.compatibility_context(true);
    params.depth_buffer(false);
    params.stencil_buffer(false);
}
//------------------------------------------------------------------------------
bool is_example_param(const example_arg&) {
    return false;
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
