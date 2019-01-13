/**
 *  example oglplus/032_extruded.cpp
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
#include <eagine/shapes/torus.hpp>
#include <eagine/shapes/to_quads.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>

#include "example.hpp"
#include "example/camera.hpp"
#include "example/program.hpp"
// clang-format on

namespace oglplus {

static constants GL;
static operations gl;

class example_program : public example_program_base {
public:
    uniform_location projection;
    uniform_location time;

    example_program(const example_params& params)
      : example_program_base(params, "032_extruded.oglpprog") {

        gl.use(*this);
        gl.query_location(projection, *this, "Projection");
        gl.query_location(time, *this, "Time");
    }
};

class extruded_example : public example {
private:
    example_orbiting_camera camera;

    example_program prog;

    shapes::vertex_attribs_and_locations<3> attrs;
    shapes::adapted_generator_wrapper<3> shape;

    void set_projection(const example_state_view& state) {
        gl.uniform(prog.projection, camera.matrix(state));
    }

public:
    extruded_example(
      const example_context& ctx, eagine::memory::buffer& temp_buffer)
      : prog(ctx.params())
      , attrs(
          shapes::vertex_attrib_kind::position +
          shapes::vertex_attrib_kind::normal +
          shapes::vertex_attrib_kind::wrap_coord_0)
      , shape(
          temp_buffer,
          eagine::shapes::to_quads(
            eagine::shapes::unit_torus(get_attrib_bits(attrs), 18, 36, 0.5f)),
          attrs) {

        camera.set_fov(right_angle_())
          .set_orbit_min(1.5f)
          .set_orbit_max(5.0f)
          .set_near(0.5f)
          .set_far(10.f);

        gl.clear_color(0.5f, 0.5f, 0.4f, 0);
        gl.clear_depth(1);
        gl.enable(GL.depth_test);

        set_projection(ctx.state());
    }

    void pointer_motion(const example_context& ctx) override {
        const auto& state = ctx.state();
        if(camera.apply_pointer_motion(state)) {
            set_projection(state);
        }
    }

    void pointer_scrolling(const example_context& ctx) override {
        const auto& state = ctx.state();
        if(camera.apply_pointer_scrolling(state)) {
            set_projection(state);
        }
    }

    void resize(const example_context& ctx) override {
        const auto& state = ctx.state();
        gl.viewport(state.width(), state.height());
        set_projection(state);
    }

    void user_idle(const example_context& ctx) final {
        const auto& state = ctx.state();
        if(state.user_idle_time() > seconds_(1)) {
            camera.idle_update(state, 2);
            set_projection(state);
        }
    }

    void render(const example_context& ctx) final {
        gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
        gl.uniform(prog.time, ctx.state().exec_time().value());
        shape.draw();
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(new extruded_example(ctx, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
