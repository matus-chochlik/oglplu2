/**
 *  example oglplus/010_cubes_ssao.cpp
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
#include <eagine/shapes/cube.hpp>
#include <eagine/shapes/array.hpp>
#include <eagine/shapes/centered.hpp>
#include <eagine/shapes/reboxed.hpp>

#include <oglplus/math/interpolate.hpp>
#include <oglplus/math/coordinates.hpp>
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
    uniform_location center;
    uniform_location time;

    example_program(const example_params& params)
      : example_program_base(params, "011_scaled_cubes.oglpprog") {

        gl.use(*this);
        gl.query_location(projection, *this, "Projection");
        gl.query_location(center, *this, "Center");
        gl.query_location(time, *this, "Time");
    }
};

class cube_example : public example {
private:
    example_orbiting_camera camera;

    example_program prog;

    shapes::vertex_attribs_and_locations<3> attrs;
    shapes::adapted_generator_wrapper<3> cubes;

    void set_projection(const example_state_view& state) {
        gl.uniform(prog.projection, camera.matrix(state));
    }

public:
    cube_example(
      const example_context& ctx, eagine::memory::buffer& temp_buffer)
      : prog(ctx.params())
      , attrs(
          shapes::vertex_attrib_kind::position +
          shapes::vertex_attrib_kind::pivot +
          shapes::vertex_attrib_kind::box_coord)
      , cubes(
          temp_buffer,
          eagine::shapes::rebox(
            eagine::shapes::center(eagine::shapes::ortho_array_xyz(
              eagine::shapes::unit_cube(get_attrib_bits(attrs)),
              {1.f, 1.f, 1.f},
              {10, 10, 10}))),
          attrs) {

        camera.set_fov(right_angle_())
          .set_orbit_min(12.0f)
          .set_orbit_max(15.0f)
          .set_near(0.5f)
          .set_far(40.f);

        gl.clear_color(0.7f, 0.7f, 0.6f, 0);
        gl.clear_depth(1);
        gl.enable(GL.depth_test);
        gl.enable(GL.cull_face);
        gl.cull_face(GL.back);

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
            camera.idle_update(state, 2);
            set_projection(state);
        }
    }

    void render(const example_context& ctx) final {
        gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);

        const auto t = ctx.state().exec_time().value();

        gl.uniform(
          prog.center,
          to_cartesian(unit_spherical_coordinates(
            turns_(t / 3.f),
            smooth_lerp(right_angles_(1.f), right_angles_(-1.f), t / 5.f))) *
            smooth_lerp(0.f, 10.f, t / 7.f));
        gl.uniform(prog.time, t);

        cubes.draw();
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(new cube_example(ctx, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
