/**
 *  example oglplus/008_texgen.cpp
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

#include <oglplus/texgen/render_graph.hpp>
#include <oglplus/texgen/wrap_node.hpp>
#include <oglplus/texgen/mix_node.hpp>
#include <oglplus/texgen/functional_node.hpp>
#include <oglplus/texgen/newton_node.hpp>
#include <oglplus/texgen/uniform_node.hpp>
#include <oglplus/texgen/scale_node.hpp>
#include <oglplus/texgen/offset_node.hpp>

#include <eagine/math/interpolate.hpp>

#include "example.hpp"
// clang-format on

namespace oglplus {

class example_render_graph : public texgen::render_graph {
public:
    uniform<GLfloat> scale_loc;

    example_render_graph();
};

example_render_graph::example_render_graph() {
    using namespace texgen;

    uniform_node& uscale =
      add_new_anon<uniform_node>().set_value_type<float[2]>();

    connect_to_renderer(
      add_new_anon<offset_node>()
        .connect(
          "Input",
          add_new_anon<scale_node>()
            .connect("Scale", uscale)
            .connect(
              "Input",
              add_new_anon<mix_node>()
                .connect(
                  "Value",
                  add_new_anon<wrap_node>()
                    .connect(add_new_anon<binary_function_node>()
                               .connect(add_new_anon<newton_node>())
                               .set_function(binary_function::multiply)
                               .set_value_b(8.f, 8.f, 1.f, 1.f))
                    .set_mode(wrap_mode::mirror))
                .set_one(0.6f, 0.9f, 0.2f, 1.0f)
                .set_zero(0.2f, 0.3f, 0.8f, 1.0f)))
        .set_offset(-0.5, -0.5, 0.0f));

    finalize();

    scale_loc = uscale.get_uniform_location();
}

class example_texgen : public example {
private:
    constants GL;
    operations gl;

    example_render_graph erg;

    const GLfloat max_scale = 500.f;
    const GLfloat min_scale = 0.002f;

    GLfloat scale, aspect;

public:
    example_texgen()
      : scale(1.0f)
      , aspect(1.0f) {
        gl.uniform(erg.scale_loc, scale, scale);
        gl.disable(GL.depth_test);
    }

    void resize(const example_context& ctx) override {
        const auto& state = ctx.state();
        gl.viewport(0, 0, state.width(), state.height());
        erg.set_dimensions(state.width(), state.height());

        aspect = state.aspect();
    }

    void pointer_scrolling(const example_context& ctx) override {
        const auto& state = ctx.state();
        scale *= float(std::pow(2, -state.norm_pointer_z().delta()));
        if(scale < min_scale)
            scale = min_scale;
        if(scale > max_scale)
            scale = max_scale;

        gl.uniform(erg.scale_loc, scale * aspect, scale);
    }

    void user_idle(const example_context& ctx) override {
        const auto& state = ctx.state();
        if(state.user_idle_time() > seconds_(1)) {
            using namespace eagine::math;
            float new_sc = float(smooth_lerp(
              min_scale, max_scale, value(state.exec_time()) * 0.4f));

            scale = interpolate_linear(new_sc, scale, 0.9f);

            gl.uniform(erg.scale_loc, scale, scale);
        }
    }

    seconds_t<float> default_timeout() override {
        return seconds_(30);
    }

    void render(const example_context&) override {
        erg.render();
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context&) {
    return std::unique_ptr<example>(new example_texgen());
}

void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
