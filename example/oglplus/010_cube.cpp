/**
 *  example oglplus/010_cube.cpp
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
#include <eagine/shapes/scaled.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>

#include "example.hpp"
#include "example/camera.hpp"
// clang-format on

namespace oglplus {

static constants GL;
static operations gl;

class example_program : public program {
public:
    uniform_location projection;

    example_program() {
        shader vs(GL.vertex_shader);
        vs.source(
          glsl_literal("#version 140\n"

                       "uniform mat4 Projection;\n"

                       "in vec4 Position;\n"
                       "in vec3 Normal;\n"
                       "in vec3 BoxCoord;\n"
                       "in vec3 TexCoord;\n"
                       "out vec2 vertCoord;\n"
                       "out vec3 vertColor1;\n"
                       "out vec3 vertColor2;\n"

                       "void main()\n"
                       "{\n"
                       "	gl_Position = Projection*Position;\n"
                       "	vertColor1 = mix(BoxCoord,abs(Normal),0.5);\n"
                       "	vertColor2 = vertColor1 * 0.3;\n"
                       "	vertCoord = TexCoord.xy*(2+TexCoord.z);\n"
                       "}\n"));
        vs.compile();

        shader fs(GL.fragment_shader);
        fs.source(
          glsl_literal("#version 140\n"

                       "in  vec2 vertCoord;\n"
                       "in  vec3 vertColor1;\n"
                       "in  vec3 vertColor2;\n"
                       "out vec3 fragColor;\n"

                       "float pattern(vec2 tc)\n"
                       "{\n"
                       "	return float((int(tc.x)%2+int(tc.y)%2)%2);\n"
                       "}\n"

                       "void main()\n"
                       "{\n"
                       "	float c = pattern(vertCoord);\n"
                       "	fragColor = mix(vertColor1, vertColor2, c);\n"
                       "}\n"));
        fs.compile();

        attach(vs);
        attach(fs);
        link();
        report_link_error();

        gl.use(*this);

        gl.query_location(projection, *this, "Projection");
    }
};

class cube_example : public example {
private:
    example_orbiting_camera camera;

    example_program prog;

    shapes::vertex_attribs_and_locations<4> attrs;
    shapes::adapted_generator_wrapper<4> cubes;

    void set_projection(const example_state_view& state) {
        gl.uniform(prog.projection, camera.matrix(state));
    }

public:
    cube_example(
      const example_state_view& state, eagine::memory::buffer& temp_buffer)
      : prog()
      , attrs(
          shapes::vertex_attrib_kind::position +
          shapes::vertex_attrib_kind::normal +
          shapes::vertex_attrib_kind::box_coord +
          shapes::vertex_attrib_kind::face_coord)
      , cubes(
          temp_buffer,
          eagine::shapes::center(eagine::shapes::ortho_array_xyz(
            eagine::shapes::scale(
              eagine::shapes::unit_cube(get_attrib_bits(attrs)),
              {0.85f, 0.85f, 0.85f}),
            {1.f, 1.f, 1.f},
            {3, 3, 3})),
          attrs) {

        camera.set_fov(right_angle_())
          .set_orbit_min(3.0f)
          .set_orbit_max(8.0f)
          .set_near(0.5f)
          .set_far(20.f);

        gl.clear_color(0.6f, 0.6f, 0.5f, 0);
        gl.clear_depth(1);
        gl.enable(GL.depth_test);

        set_projection(state);
    }

    void pointer_motion(const example_state_view& state) final {
        if(camera.apply_pointer_motion(state)) {
            set_projection(state);
        }
    }

    void pointer_scrolling(const example_state_view& state) final {
        if(camera.apply_pointer_scrolling(state)) {
            set_projection(state);
        }
    }

    void resize(const example_state_view& state) final {
        gl.viewport(state.width(), state.height());
        set_projection(state);
    }

    void user_idle(const example_state_view& state) final {
        if(state.user_idle_time() > seconds_(1)) {
            camera.idle_update(state, 2);
            set_projection(state);
        }
    }

    void render(const example_state_view& /*state*/) final {
        gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);
        cubes.draw();
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_params&, const example_state_view& state) {
    eagine::memory::buffer temp_buffer;
    return std::unique_ptr<example>(new cube_example(state, temp_buffer));
}

void adjust_params(example_params& params) {
    params.depth_buffer(true);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
