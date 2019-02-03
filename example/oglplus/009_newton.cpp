/**
 *  example oglplus/009_newton.cpp
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

#include <oglplus/shapes/wrapper.hpp>
#include <eagine/shapes/screen.hpp>

#include <oglplus/utils/program.hpp>

#include "example.hpp"
// clang-format on

namespace oglplus {

class example_newton : public example {
private:
    constants GL;
    operations gl;

    program prog;

    uniform<GLfloat> offset_loc;
    uniform<GLfloat> scale_loc;

    shapes::vertex_attribs_and_locations<1> attrs;
    shapes::adapted_generator_wrapper<1> screen;

    texture gradient;

    GLfloat offset_x, offset_y;
    GLfloat scale, aspect;

    static constexpr const float min_scale = 0.00001f;
    static constexpr const float max_scale = 10.0f;

public:
    example_newton(
      const example_context& ctx, eagine::memory::buffer& temp_buffer)
      : prog()
      , attrs(+(shapes::vertex_attrib_kind::position | 0))
      , screen(
          temp_buffer,
          eagine::shapes::unit_screen(get_attrib_bits(attrs)),
          attrs)
      , offset_x(0.0f)
      , offset_y(0.0f)
      , scale(1.0f)
      , aspect(1.0f) {
        std::string prog_path = ctx.params().get_resource_file_path(
          example_resource_type::program_source, "009_newton.oglpprog");
        build_program(prog, program_source_file(prog_path));

        gl.use(prog);

        gl.query_location(offset_loc, prog, "Offset");
        gl.query_location(scale_loc, prog, "Scale");
        gl.uniform(offset_loc, offset_x, offset_y);

        GLfloat gradient_data[8 * 3];

        for(int i = 0; i < 8 * 3; ++i) {
            gradient_data[i] = (std::rand() % 10000) / 10000.f;
        }

        gl.bind(GL.texture_1d, gradient);
        gl.texture_min_filter(GL.texture_1d, GL.linear);
        gl.texture_mag_filter(GL.texture_1d, GL.linear);
        gl.texture_wrap(GL.texture_1d, GL.texture_wrap_s, GL.repeat);
        gl.texture_image_1d(
          GL.texture_1d,
          0,
          GL.rgb,
          8,
          0,
          GL.rgb,
          GL.float_,
          as_bytes(view(gradient_data)));

        gl.disable(GL.depth_test);
    }

    void pointer_motion(const example_context& ctx) final {
        const auto& state = ctx.state();
        if(state.pointer_dragging()) {
            offset_x -= 2 * state.norm_pointer_x().delta() * scale;
            offset_y -= 2 * state.norm_pointer_y().delta() * scale;

            gl.uniform(offset_loc, offset_x, offset_y);
        }
    }

    void pointer_scrolling(const example_context& ctx) final {
        const auto& state = ctx.state();

        scale *= float(std::pow(2, -state.norm_pointer_z().delta()));
        if(scale < min_scale)
            scale = min_scale;
        if(scale > max_scale)
            scale = max_scale;

        gl.uniform(scale_loc, scale * aspect, scale);
    }

    void resize(const example_context& ctx) final {
        const auto& state = ctx.state();
        gl.viewport(0, 0, state.width(), state.height());

        aspect = state.aspect();
        gl.uniform(scale_loc, scale * aspect, scale);
    }

    void user_idle(const example_context& ctx) final {
        const auto& state = ctx.state();
        if(state.user_idle_time() > seconds_(1)) {
            const float s = value(state.frame_duration()) * 60;
            const float dest_offset_x = -0.568407f;
            const float dest_offset_y = 0.125629f;
            const float c = 0.02f * s;

            offset_x = c * dest_offset_x + (1 - c) * offset_x;
            offset_y = c * dest_offset_y + (1 - c) * offset_y;

            scale *= (1 - 0.01f * s);
            if(scale < min_scale)
                scale = min_scale;

            gl.uniform(offset_loc, offset_x, offset_y);
            gl.uniform(scale_loc, scale * aspect, scale);
        }
    }

    seconds_t<float> default_timeout() final {
        return seconds_(20);
    }

    void render(const example_context&) final {
        screen.draw();
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(new example_newton(ctx, temp_buffer));
}

void adjust_params(example_params& params) {
    params.rand_seed(1234);
    params.depth_buffer(false);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
