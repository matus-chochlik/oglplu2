/**
 *  example oglplus/002_triangle.cpp
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

namespace eagine {
namespace oglp {

class example_triangle : public example {
    owned_buffer_name pos;
    owned_buffer_name clr;

    owned_vertex_array_name vao;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;

public:
    example_triangle(const example_context& ctx) {
        auto& [gl, GL] = ctx.gl();

        gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);

        gl.gen_buffers() >> pos;
        gl.gen_buffers() >> clr;

        gl.gen_vertex_arrays() >> vao;

        gl.create_shader(GL.vertex_shader) >> vs;
        gl.shader_source(
          vs,
          glsl_literal("#version 140\n"
                       "in vec2 Position;\n"
                       "in vec3 Color;\n"
                       "out vec3 vertColor;\n"
                       "void main()\n"
                       "{\n"
                       "	gl_Position = vec4(Position, 0.0, 1.0);\n"
                       "	vertColor = Color;\n"
                       "}\n"));
        gl.compile_shader(vs);

        gl.create_shader(GL.fragment_shader) >> fs;
        gl.shader_source(
          fs,
          glsl_literal("#version 140\n"
                       "in vec3 vertColor;\n"
                       "out vec3 fragColor;\n"
                       "void main()\n"
                       "{\n"
                       "	fragColor = vertColor;\n"
                       "}\n"));
        gl.compile_shader(fs);

        gl.create_program() >> prog;
        gl.attach_shader(prog, vs);
        gl.attach_shader(prog, fs);
        gl.link_program(prog);
        gl.use_program(prog);
    }

    void cleanup(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.delete_program(std::move(prog));

        gl.delete_shader(std::move(fs));
        gl.delete_shader(std::move(vs));

        gl.delete_vertex_arrays(std::move(vao));

        gl.delete_buffers(std::move(clr));
        gl.delete_buffers(std::move(pos));
    }

    void resize(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.viewport(ctx.state().width(), ctx.state().height());
    }

    void render(const example_context& ctx) final {
        auto& [gl, GL] = ctx.gl();

        gl.clear(GL.color_buffer_bit);
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    return {std::make_unique<example_triangle>(ctx)};
}

void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglp
} // namespace eagine

