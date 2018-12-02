/**
 *  example oglplus/028_lighting.cpp
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

#include <oglplus/shapes/wrapper.hpp>
#include <oglplus/shapes/sphere.hpp>
#include <oglplus/shapes/torus.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/interpolate.hpp>

#include "example.hpp"
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
    erase_program erase_prog;
    lighting_program light_prog;

    shapes::generator_wrapper<shapes::unit_sphere_gen, 1> background;
    shapes::generator_wrapper<shapes::unit_torus_gen, 3> shape;

    float shp_turns;

    float cam_orbit;
    float cam_turns;
    float cam_pitch;

    short cam_dist_dir;
    short cam_turn_dir;
    short cam_elev_dir;

    void mod_bouncing(short& dir, float& val, float inc) {
        val += inc;
        if(val > 1.f) {
            val = 1.f;
            dir = -1;
        }
        if(val < 0.f) {
            val = 0.f;
            dir = +1;
        }
    }

    void mod_cam_orbit(float inc) {
        mod_bouncing(cam_dist_dir, cam_orbit, inc);
    }

    void mod_cam_turns(float inc) {
        cam_turns += inc;
        cam_turn_dir = (inc > 0) ? 1 : -1;
    }

    void mod_cam_pitch(float inc) {
        mod_bouncing(cam_elev_dir, cam_pitch, inc);
    }

    void set_projection(const example_state_view& state) {
        auto projection =
          matrix_perspective::y(right_angle_(), state.aspect(), 0.5f, 50.f) *
          matrix_orbiting_y_up(
            vec3(),
            smooth_lerp(1.5f, 5.0f, cam_orbit),
            turns_(cam_turns),
            smooth_oscillate(radians_(1.5f), cam_pitch));

        gl.use(light_prog);
        gl.uniform(light_prog.projection, projection);
        gl.use(erase_prog);
        gl.uniform(erase_prog.projection, projection);
    }

public:
    lighting_example(
      const example_params& params,
      const example_state_view& state,
      eagine::memory::buffer& temp_buffer)
      : erase_prog(params)
      , light_prog(params)
      , background(
          temp_buffer, (shapes::vertex_attrib_kind::position | 0), 36, 72)
      , shape(
          temp_buffer,
          (shapes::vertex_attrib_kind::position | 0) +
            (shapes::vertex_attrib_kind::normal | 1) +
            (shapes::vertex_attrib_kind::wrap_coord | 2),
          96,
          144)
      , shp_turns(0.0f)
      , cam_orbit(0.0f)
      , cam_turns(0.0f)
      , cam_pitch(0.5f)
      , cam_dist_dir(-1)
      , cam_turn_dir(1)
      , cam_elev_dir(1) {
        gl.clear_depth(1);
        gl.disable(GL.cull_face);

        set_projection(state);
    }

    void pointer_motion(const example_state_view& state) override {
        if(state.pointer_dragging()) {
            mod_cam_turns(-state.norm_pointer_x().delta() * 0.5f);
            mod_cam_pitch(-state.norm_pointer_y().delta() * 1.0f);
            set_projection(state);
        }
    }

    void pointer_scrolling(const example_state_view& state) override {
        mod_cam_orbit(-state.norm_pointer_z().delta());
        set_projection(state);
    }

    void resize(const example_state_view& state) override {
        gl.viewport(state.width(), state.height());
        set_projection(state);
    }

    void user_idle(const example_state_view& state) override {
        if(state.user_idle_time() > seconds_(1)) {
            const float s = state.frame_duration().value() / 5;

            mod_cam_orbit(s * cam_dist_dir);
            mod_cam_turns(s * cam_turn_dir);
            mod_cam_pitch(s * cam_elev_dir);

            set_projection(state);
        }
    }

    void render(const example_state_view& state) override {
        gl.use(erase_prog);
        gl.disable(GL.depth_test);
        background.use();
        background.draw();

        shp_turns += 0.1f * state.frame_duration().value();

        gl.use(light_prog);
        gl.uniform(
          light_prog.modelview,
          matrix_rotation_x(turns_(shp_turns) / 1) *
            matrix_rotation_y(turns_(shp_turns) / 2) *
            matrix_rotation_z(turns_(shp_turns) / 3));

        gl.clear(GL.depth_buffer_bit);
        gl.enable(GL.depth_test);
        shape.use();
        shape.draw();
    }

    seconds_t<float> default_timeout(void) override {
        return seconds_(20);
    }
};

std::unique_ptr<example> make_example(
  const example_args&,
  const example_params& params,
  const example_state_view& state) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(
      new lighting_example(params, state, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
