/**
 *  example oglplus/010_cube.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl_fixed.hpp>

#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>
#include <oglplus/glsl/string_ref.hpp>

#include <oglplus/shapes/wrapper.hpp>
#include <oglplus/shapes/cube.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/interpolate.hpp>

#include "example.hpp"

namespace oglplus {

static constants  GL;
static operations gl;

class example_program
 : public program
{
public:
	uniform_location projection;

	example_program(void)
	{
		shader vs(GL.vertex_shader);
		vs.source(glsl_literal(
		"#version 140\n"

		"uniform mat4 Projection;\n"

		"in vec4 Position;\n"
		"in vec3 Normal;\n"
		"in vec3 BoxCoord;\n"
		"in vec3 TexCoord;\n"
		"out vec2 vertCoord;\n"
		"out vec3 vertColor1;\n"
		"out vec3 vertColor2;\n"

		"void main(void)\n"
		"{\n"
		"	gl_Position = Projection*Position;\n"
		"	vertColor1 = mix(BoxCoord,abs(Normal),0.5);\n"
		"	vertColor2 = vertColor1 * 0.3;\n"
		"	vertCoord = TexCoord.xy*(2+TexCoord.z);\n"
		"}\n"
		));
		vs.compile();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 140\n"

		"in  vec2 vertCoord;\n"
		"in  vec3 vertColor1;\n"
		"in  vec3 vertColor2;\n"
		"out vec3 fragColor;\n"

		"float pattern(vec2 tc)\n"
		"{\n"
		"	return float((int(tc.x)%2+int(tc.y)%2)%2);\n"
		"}\n"

		"void main(void)\n"
		"{\n"
		"	float c = pattern(vertCoord);\n"
		"	fragColor = mix(vertColor1, vertColor2, c);\n"
		"}\n"
		));
		fs.compile();

		attach(vs);
		attach(fs);
		link();
		report_link_error();

		gl.use(*this);

		gl.query_location(projection, *this, "Projection");
	}
};

class cube_example
 : public example
{
private:
	example_program prog;

	shapes::generator_wrapper<shapes::unit_cube_gen, 4> cube;

	float cam_orbit;
	float cam_turns;
	float cam_pitch;

	short cam_dist_dir;
	short cam_turn_dir;
	short cam_elev_dir;

	void mod_bouncing(short& dir, float& val, float inc)
	{
		val += inc;
		if(val > 1.f)
		{
			val = 1.f;
			dir = -1;
		}
		if(val < 0.f)
		{
			val = 0.f;
			dir = +1;
		}
	}

	void mod_cam_orbit(float inc)
	{
		mod_bouncing(cam_dist_dir, cam_orbit, inc);
	}

	void mod_cam_turns(float inc)
	{
		cam_turns += inc;
		cam_turn_dir = (inc > 0)?1:-1;
	}

	void mod_cam_pitch(float inc)
	{
		mod_bouncing(cam_elev_dir, cam_pitch, inc);
	}

	void set_projection(const example_state_view& state)
	{
		gl.uniform(
			prog.projection,
			matrix_perspective::y(
				right_angle_(),
				state.aspect(),
				0.5f, 10.f
			)*matrix_orbiting_y_up(
				vec3(),
				smooth_lerp(1.5f, 5.0f, cam_orbit),
				turns_(cam_turns),
				smooth_oscillate(radians_(1.5f), cam_pitch)
			)
		);
	}
public:
	cube_example(
		const example_state_view& state,
		eagine::memory::buffer& temp_buffer
	): prog()
	 , cube(
		temp_buffer,
		shapes::vertex_attrib_kind::position+
		shapes::vertex_attrib_kind::normal+
		shapes::vertex_attrib_kind::box_coord+
		shapes::vertex_attrib_kind::face_coord
	), cam_orbit(0.5)
	 , cam_turns(0.12f)
	 , cam_pitch(0.72f)
	 , cam_dist_dir(-1)
	 , cam_turn_dir(1)
	 , cam_elev_dir(1)
	{
		gl.clear_color(0.6f, 0.6f, 0.5f, 0);
		gl.clear_depth(1);
		gl.enable(GL.depth_test);

		set_projection(state);
	}

	void pointer_motion(const example_state_view& state)
	override
	{
		if(state.pointer_dragging())
		{
			mod_cam_turns(-state.norm_delta_pointer_x()*0.5f);
			mod_cam_pitch(-state.norm_delta_pointer_y()*1.0f);
			set_projection(state);
		}
	}

	void pointer_scrolling(const example_state_view& state)
	override
	{
		mod_cam_orbit(-state.norm_delta_pointer_z());
		set_projection(state);
	}

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(state.width(), state.height());
		set_projection(state);
	}

	void user_idle(const example_state_view& state)
	override
	{
		if(state.user_idle_time() > seconds_(1))
		{
			const float s = state.frame_duration().value()/2;

			mod_cam_orbit(s*cam_dist_dir);
			mod_cam_turns(s*cam_turn_dir);
			mod_cam_pitch(s*cam_elev_dir);

			set_projection(state);
		}
	}

	void render(const example_state_view& /*state*/)
	override
	{
		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);
		cube.draw();
	}
};

std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params&,
	const example_state_view& state
)
{
	eagine::memory::buffer temp_buffer;
	return std::unique_ptr<example>(new cube_example(state, temp_buffer));
}

void adjust_params(example_params& params)
{
	params.depth_buffer(true);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
