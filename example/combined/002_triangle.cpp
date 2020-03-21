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
#include <oglplus/math/vector.hpp>
#include <oglplus/math/primitives.hpp>
#include "example.hpp"
// clang-format on

namespace eagine {
namespace oglp {

class example_triangle : public example {
    triangle tri;

    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name colors;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;

public:
    example_triangle(const example_context& ctx)
      : tri(
          vec3(-0.2f, 0.5f, 0.0f),
          vec3(-0.7f, -0.6f, 0.0f),
          vec3(0.6f, 0.2f, 0.0f)) {

        auto& [gl, GL] = ctx.gl();

        gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);

        // vertex shader
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

        // fragment shader
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
        gl_types::float_type position_data[6]{tri.a().x(),
                                              tri.a().y(),
                                              tri.b().x(),
                                              tri.b().y(),
                                              tri.c().x(),
                                              tri.c().y()};

        gl.gen_buffers() >> positions;
        gl.bind_buffer(GL.array_buffer, positions);
        gl.buffer_data(GL.array_buffer, position_data, GL.static_draw);
        vertex_attrib_location position_loc;
        gl.get_attrib_location(prog, "Position") >> position_loc;

        gl.vertex_attrib_pointer(position_loc, 2, GL.float_, GL.false_);
        gl.enable_vertex_attrib_array(position_loc);

        // color colors
        gl_types::float_type color_data[9]{
          1.0f, 0.1f, 0.1f, 0.1f, 1.0f, 0.1f, 0.1f, 0.1f, 1.0f};

        gl.gen_buffers() >> colors;
        gl.bind_buffer(GL.array_buffer, colors);
        gl.buffer_data(GL.array_buffer, color_data, GL.static_draw);
        vertex_attrib_location color_loc;
        gl.get_attrib_location(prog, "Color") >> color_loc;

        gl.vertex_attrib_pointer(color_loc, 3, GL.float_, GL.false_);
        gl.enable_vertex_attrib_array(color_loc);

        gl.disable(GL.depth_test);
    }

    void cleanup(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.delete_program(std::move(prog));

        gl.delete_shader(std::move(fs));
        gl.delete_shader(std::move(vs));

        gl.delete_vertex_arrays(std::move(vao));

        gl.delete_buffers(std::move(colors));
        gl.delete_buffers(std::move(positions));
    }

    void resize(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.viewport(ctx.state().width(), ctx.state().height());
    }

    void render(const example_context& ctx) final {
        auto& [gl, GL] = ctx.gl();

        gl.clear(GL.color_buffer_bit);
        gl.draw_arrays(GL.triangles, 0, 3);
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

