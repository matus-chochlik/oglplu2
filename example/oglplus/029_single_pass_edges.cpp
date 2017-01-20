/**
 *  example oglplus/029_single_pass_edges.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl_fixed.hpp>

#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>

#include <oglplus/shapes/wrapper.hpp>
#include <oglplus/shapes/icosahedron.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/interpolate.hpp>

#include "example.hpp"
#include "example/program.hpp"

namespace oglplus {

static constants  GL;
static operations gl;

class example_program
 : public example_program_base
{
public:
	uniform_location projection;
	uniform<GLfloat> vp_dimensions;

	example_program(const example_params& params)
	 : example_program_base(
		params,
		cstr_ref("029_single_pass_edges.oglpprog")
	) {
		gl.use(*this);
		gl.query_location(projection, *this, "Projection");
		gl.query_location(vp_dimensions, *this, "ViewportDimensions");
	}
};

class icosahedron_example
 : public example
{
private:
	example_program prog;

	shapes::generator_wrapper<shapes::unit_icosahedron_gen, 1> icosahedron;

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
				smooth_lerp(1.5f, 9.0f, cam_orbit),
				turns_(cam_turns),
				smooth_oscillate(radians_(1.5f), cam_pitch)
			)
		);
		gl.uniform(
			prog.vp_dimensions,
			state.width(),
			state.height()
		);
	}
public:
	icosahedron_example(
		const example_state_view& state,
		const example_params& params,
		eagine::memory::buffer& temp_buffer
	): prog(params)
	 , icosahedron(temp_buffer, shapes::vertex_attrib_kind::position|0)
	 , cam_orbit(0.5)
	 , cam_turns(0.12f)
	 , cam_pitch(0.72f)
	 , cam_dist_dir(-1)
	 , cam_turn_dir(1)
	 , cam_elev_dir(1)
	{
		gl.clear_color(0.6f, 0.6f, 0.5f, 0);
		gl.clear_depth(1);
		gl.enable(GL.depth_test);
		gl.enable(GL.cull_face);
		gl.cull_face(GL.back);

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
		icosahedron.draw();
	}
};

std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params& params,
	const example_state_view& state
)
{
	eagine::memory::buffer temp_buffer;
	return std::unique_ptr<example>(new icosahedron_example(
		state,
		params,
		temp_buffer
	));
}

void adjust_params(example_params& params)
{
	params.depth_buffer(true);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
