/**
 *  example oglplus/013_occlusion.cpp
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
#include <eagine/shapes/torus.hpp>
#include <eagine/shapes/sphere.hpp>
#include <eagine/shapes/translated.hpp>
#include <eagine/shapes/combined.hpp>
#include <eagine/shapes/occluded.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/coordinates.hpp>

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
    uniform_location light_direction;

    example_program(const example_params& params)
      : example_program_base(params, "013_occlusion.oglpprog") {
        gl.use(*this);
        gl.query_location(projection, *this, "Projection");
        gl.query_location(light_direction, *this, "LightDirection");
    }
};

class occlusion_example : public example {
private:
    example_orbiting_camera camera;
    example_program prog;

    shapes::vertex_attribs_and_locations<4> attrs;
    shapes::adapted_generator_wrapper<4> shape;

    void set_projection(const example_state_view& state) {
        gl.uniform(prog.projection, camera.matrix(state));
    }

public:
    occlusion_example(
      const example_context& ctx, eagine::memory::buffer& temp_buffer)
      : prog(ctx.params())
      , attrs(
          shapes::vertex_attrib_kind::position +
          shapes::vertex_attrib_kind::occlusion +
          shapes::vertex_attrib_kind::normal +
          shapes::vertex_attrib_kind::wrap_coord_0)
      , shape(
          temp_buffer,
          eagine::shapes::occlude(
            eagine::shapes::combine(
              eagine::shapes::translate(
                eagine::shapes::unit_torus(
                  get_attrib_bits(attrs), 18, 36, 0.7f),
                {0.f, -0.5f, 0.f}) +
              eagine::shapes::translate(
                eagine::shapes::unit_sphere(get_attrib_bits(attrs), 24, 36),
                {-0.55f, +0.2f, 0.f}) +
              eagine::shapes::translate(
                eagine::shapes::unit_sphere(get_attrib_bits(attrs), 24, 36),
                {+0.55f, +0.3f, 0.1f})),
            ctx.params().high_quality() ? 64 : 8),
          attrs) {
        camera.set_fov(radians_(1.0f))
          .set_near(0.1f)
          .set_far(10.f)
          .set_orbit_min(1.8f)
          .set_orbit_max(3.0f);

        gl.clear_color(0.6f, 0.6f, 0.5f, 0);
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
        const auto t = ctx.state().exec_time().value();

        gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);

        gl.uniform(
          prog.light_direction,
          to_cartesian(unit_spherical_coordinates(
            turns_(t / 5.f),
            smooth_lerp(radians_(1.4f), radians_(-1.4f), t / 7.f))));

        shape.draw();
    }

    seconds_t<float> default_timeout() final {
        return seconds_(60);
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(new occlusion_example(ctx, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
