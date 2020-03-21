/**
 *  example oglplus/004_pick_triangle.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/math/primitives.hpp>
#include <eagine/math/intersection.hpp>

#include "example.hpp"
// clang-format on

namespace eagine {
namespace oglp {

class example_triangle : public example {
private:
    triangle tri;
    GLfloat hl_value{0.f};
    bool is_inside{false};

    owned_vertex_array_name vao;

    owned_buffer_name positions;

    owned_shader_name vs;
    owned_shader_name fs;

    owned_program_name prog;

    program prog;

    uniform_location highlight_loc;

public:
    example_triangle()
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
                       "uniform float Highlight;\n"
                       "in vec2 Position;\n"
                       "out vec3 vertColor;\n"
                       "const vec3 Red = vec3(1.0, 0.2, 0.2);\n"
                       "const vec3 Grn = vec3(0.2, 1.0, 0.2);\n"
                       "void main()\n"
                       "{\n"
                       "	gl_Position = vec4(Position, 0.0, 1.0);\n"
                       "	vertColor = mix(Red, Grn, Highlight);\n"
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
                       "} \n"));
        gl.compile_shader(fs);
        //
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

        // uniform
        gl.query_location(highlight, prog, "Highlight");
        gl.uniform(highlight, hl_value);

        gl.disable(GL.depth_test);
    }

    void cleanup(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.delete_program(std::move(prog));

        gl.delete_shader(std::move(fs));
        gl.delete_shader(std::move(vs));

        gl.delete_buffers(std::move(positions));

        gl.delete_vertex_arrays(std::move(vao));
    }

    void update_highlight(float dt) {
        auto& [gl, GL] = ctx.gl();
        EAGINE_MAYBE_UNUSED(GL);

        if(is_inside) {
            hl_value = eagine::math::minimum(hl_value + dt * 3.0f, 1.f);
        } else {
            hl_value = eagine::math::maximum(hl_value - dt * 1.0f, 0.f);
        }
        gl.uniform(highlight, hl_value);
    }

    void pointer_motion(const example_context& ctx) final {
        const auto& state = ctx.state();
        const auto x = state.ndc_pointer_x();
        const auto y = state.ndc_pointer_y();
        line ray(vec3(x, y, 1.f), vec3(0.f, 0.f, -1.f));

        is_inside = bool(eagine::math::line_triangle_intersection(ray, tri));
        update_highlight(state.frame_duration().value());
    }

    void user_idle(const example_context& ctx) final {
        update_highlight(ctx.state().frame_duration().value());
    }

    void resize(const example_context& ctx) final {
        auto& [gl, GL] = ctx.gl();
        EAGINE_MAYBE_UNUSED(GL);
        const auto& state = ctx.state();
        gl.viewport(state.width(), state.height());
    }

    seconds_t<float> default_timeout() final {
        return seconds_(20);
    }

    void render(const example_context&) final {
        auto& [gl, GL] = ctx.gl();
        gl.draw_arrays(GL.triangles, 0, 3);
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return std::unique_ptr<example>(new example_triangle());
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
