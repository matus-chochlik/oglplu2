/// example oglplus/028_lighting.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

// clang-format off
#include <oglplus/gl.hpp>

#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>

#include <oglplus/shapes/wrapper.hpp>
#include <eagine/shapes/sphere.hpp>
#include <eagine/shapes/torus.hpp>
#include <eagine/shapes/translated.hpp>
#include <eagine/shapes/combined.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>

#include "example.hpp"
#include "example/camera.hpp"
#include "example/program.hpp"
// clang-format on

namespace oglplus {

static constants GL;
static operations gl;

class erase_program : public example_program_base {
public:
    uniform_location projection;

    erase_program(const example_params& params)
      : example_program_base(params, "028_lighting-bg.oglpprog") {
        gl.use(*this);
        gl.query_location(projection, *this, "Projection");
    }
};

class lighting_program : public example_program_base {
public:
    uniform_location projection, modelview;

    lighting_program(const example_params& params)
      : example_program_base(params, "028_lighting-lt.oglpprog") {
        gl.use(*this);
        gl.query_location(projection, *this, "Projection");
        gl.query_location(modelview, *this, "Modelview");
    }
};

class lighting_example : public example {
private:
    example_orbiting_camera camera;
    erase_program erase_prog;
    lighting_program light_prog;

    shapes::vertex_attribs_and_locations<1> background_attrs;
    shapes::adapted_generator_wrapper<1> background;

    shapes::vertex_attribs_and_locations<3> shape_attrs;
    shapes::adapted_generator_wrapper<3> shape;

    float shp_turns;

    void set_projection(const example_state_view& state) {
        auto projection = camera.matrix(state);

        gl.use(light_prog);
        gl.uniform(light_prog.projection, projection);
        gl.use(erase_prog);
        gl.uniform(erase_prog.projection, projection);
    }

public:
    lighting_example(
      const example_context& ctx,
      eagine::memory::buffer& temp_buffer)
      : erase_prog(ctx.params())
      , light_prog(ctx.params())
      , background_attrs(+(shapes::vertex_attrib_kind::position | 0))
      , background(
          temp_buffer,
          eagine::shapes::unit_sphere(
            get_attrib_bits(background_attrs),
            72,
            144),
          background_attrs)
      , shape_attrs(
          (shapes::vertex_attrib_kind::position | 0) +
          (shapes::vertex_attrib_kind::normal | 1) +
          (shapes::vertex_attrib_kind::wrap_coord_0 | 2))
      , shape(
          temp_buffer,
          eagine::shapes::combine(
            eagine::shapes::translate(
              eagine::shapes::unit_torus(
                get_attrib_bits(shape_attrs),
                96,
                144,
                0.5f),
              {0.f, +0.4f, 0.f}) +
            eagine::shapes::translate(
              eagine::shapes::unit_torus(
                get_attrib_bits(shape_attrs),
                96,
                144,
                0.5f),
              {0.f, -0.4f, 0.f})),
          shape_attrs)
      , shp_turns(0.0f) {
        camera.set_near(0.5f)
          .set_far(50.f)
          .set_orbit_min(1.5f)
          .set_orbit_max(5.0f)
          .set_fov(right_angle_());

        gl.clear_depth(1);
        gl.disable(GL.cull_face);

        gl.enable(GL.cull_face);

        set_projection(ctx.state());
    }

    void pointer_motion(const example_context& ctx) final {
        const auto& state = ctx.state();
        if(camera.apply_pointer_motion(state)) {
            set_projection(state);
        }
    }

    void pointer_scrolling(const example_context& ctx) final {
        const auto& state = ctx.state();
        if(camera.apply_pointer_scrolling(state)) {
            set_projection(state);
        }
    }

    void resize(const example_context& ctx) final {
        const auto& state = ctx.state();
        gl.viewport(state.width(), state.height());
        set_projection(state);
    }

    void user_idle(const example_context& ctx) final {
        const auto& state = ctx.state();
        if(state.user_idle_time() > seconds_(1)) {
            camera.idle_update(state, 5);
            set_projection(state);
        }
    }

    void render(const example_context& ctx) final {
        gl.use(erase_prog);
        gl.disable(GL.depth_test);
        gl.cull_face(GL.front);
        background.use();
        background.draw();

        shp_turns += 0.1f * ctx.state().frame_duration().value();

        gl.use(light_prog);
        gl.uniform(
          light_prog.modelview,
          matrix_rotation_x(turns_(shp_turns) / 1) *
            matrix_rotation_y(turns_(shp_turns) / 2) *
            matrix_rotation_z(turns_(shp_turns) / 3));

        gl.clear(GL.depth_buffer_bit);
        gl.enable(GL.depth_test);
        gl.cull_face(GL.back);
        shape.use();
        shape.draw();
    }

    seconds_t<float> default_timeout() final {
        return seconds_(20);
    }
};

std::unique_ptr<example>
make_example(const example_args&, const example_context& ctx) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(new lighting_example(ctx, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
