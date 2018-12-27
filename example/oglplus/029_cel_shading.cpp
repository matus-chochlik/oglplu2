/**
 *  example oglplus/029_single_pass_edges.cpp
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
#include <oglplus/shapes/icosahedron.hpp>

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
    uniform_location modelview;

    example_program(const example_params& params) {
        attach(make_shader(params, "029_cel_shading.vert.oglpshdr"));
        attach(make_shader(params, "029_cel_shading.geom.oglpshdr"));
        attach(make_shader(params, "029_cel_shading.frag.oglpshdr"));
        link();
        report_link_error();

        gl.use(*this);
        gl.query_location(projection, *this, "Projection");
        gl.query_location(modelview, *this, "Modelview");
    }
};

class icosahedron_example : public example {
private:
    example_orbiting_camera camera;
    example_program prog;

    shapes::generator_wrapper<shapes::unit_icosahedron_gen, 1> icosahedron;

    float shp_turns;

    void set_projection(const example_state_view& state) {
        gl.uniform(prog.projection, camera.matrix(state));
    }

public:
    icosahedron_example(
      const example_state_view& state,
      const example_params& params,
      eagine::memory::buffer& temp_buffer)
      : prog(params)
      , icosahedron(temp_buffer, shapes::vertex_attrib_kind::position | 0) {

        camera.set_fov(right_angle_())
          .set_near(0.5f)
          .set_far(10.f)
          .set_orbit_min(1.5f)
          .set_orbit_max(4.0f);

        gl.clear_color(0.6f, 0.6f, 0.5f, 0);
        gl.clear_depth(1);
        gl.enable(GL.depth_test);
        gl.enable(GL.cull_face);
        gl.cull_face(GL.back);

        set_projection(state);
    }

    void pointer_motion(const example_state_view& state) override {
        if(state.pointer_dragging()) {
            camera.pointer_dragging(state);
            set_projection(state);
        }
    }

    void pointer_scrolling(const example_state_view& state) override {
        camera.pointer_scrolling(state);
        set_projection(state);
    }

    void resize(const example_state_view& state) override {
        gl.viewport(state.width(), state.height());
        set_projection(state);
    }

    void user_idle(const example_state_view& state) override {
        if(state.user_idle_time() > seconds_(1)) {
            camera.idle_update(state, 11);

            set_projection(state);
        }
    }

    void render(const example_state_view& state) override {
        shp_turns += 0.1f * state.frame_duration().value();

        gl.uniform(
          prog.modelview,
          matrix_rotation_x(turns_(shp_turns) / 1) *
            matrix_rotation_y(turns_(shp_turns) / 2) *
            matrix_rotation_z(turns_(shp_turns) / 3));

        gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
        icosahedron.draw();
    }

    seconds_t<float> default_timeout() override {
        return seconds_(20);
    }
};

std::unique_ptr<example> make_example(
  const example_args&,
  const example_params& params,
  const example_state_view& state) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(
      new icosahedron_example(state, params, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
