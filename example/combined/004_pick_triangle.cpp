/**
 *  example oglplus/003_pick_triangle.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/math/primitives.hpp>

#include <eagine/math/intersection.hpp>

#include "example.hpp"
// clang-format on

namespace oglplus {

class example_triangle : public example {
private:
    triangle tri;
    GLfloat hl_value{0.f};
    bool is_inside{false};

    constants GL;
    operations gl;

    program prog;

    uniform<GLfloat> highlight;

    vertex_array vao;

    buffer positions;

public:
    example_triangle()
      : tri(
          vec3(-0.2f, 0.5f, 0.0f),
          vec3(-0.7f, -0.6f, 0.0f),
          vec3(0.6f, 0.2f, 0.0f)) {
        shader vs(GL.vertex_shader);
        vs.source(
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
        vs.compile();

        shader fs(GL.fragment_shader);
        fs.source(
          glsl_literal("#version 140\n"
                       "in vec3 vertColor;\n"
                       "out vec3 fragColor;\n"
                       "void main()\n"
                       "{\n"
                       "	fragColor = vertColor;\n"
                       "} \n"));
        fs.compile();

        prog.attach(vs);
        prog.attach(fs);
        prog.link();
        prog.report_link_error();

        gl.use(prog);

        gl.query_location(highlight, prog, "Highlight");
        gl.uniform(highlight, hl_value);

        gl.bind(vao);

        GLfloat position_data[3 * 2] = {tri.a().x(),
                                        tri.a().y(),
                                        tri.b().x(),
                                        tri.b().y(),
                                        tri.c().x(),
                                        tri.c().y()};

        gl.bind(GL.array_buffer, positions);
        gl.buffer_data(GL.array_buffer, position_data, GL.static_draw);

        vertex_attrib_location va_p;
        gl.query_location(va_p, prog, "Position");
        gl.vertex_array_attrib_pointer(va_p, 2, GL.float_, false, 0, nullptr);
        gl.enable_vertex_array_attrib(va_p);

        gl.disable(GL.depth_test);
    }

    void update_highlight(float dt) {
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
        const auto& state = ctx.state();
        gl.viewport(0, 0, state.width(), state.height());
    }

    seconds_t<float> default_timeout() final {
        return seconds_(20);
    }

    void render(const example_context&) final {
        gl.draw_arrays(GL.triangle_strip, 0, 4);
    }
}; // namespace oglplus

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

} // namespace oglplus
