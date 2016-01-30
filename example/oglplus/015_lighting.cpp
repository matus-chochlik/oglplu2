/**
 *  example oglplus/015_lighting.cpp
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
#include <oglplus/shapes/torus.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/interpolate.hpp>

#include "example.hpp"

namespace oglplus {

static constants  GL;
static operations gl;

class lighting_program
 : public program
{
public:
	uniform_location projection, modelview;

	lighting_program(void)
	{
		shader vs(GL.vertex_shader);
		vs.source(glsl_literal(
		"#version 330\n"

		"const vec3 LightPos[5] = vec3[5](\n"
		"	vec3( 0, -100, 0),\n"
		"	vec3( 10, 10, 20),\n"
		"	vec3( 10, 20,-10),\n"
		"	vec3(-20, 10,-20),\n"
		"	vec3(-10, 20, 10) \n"
		");\n"

		"uniform mat4 Projection, Modelview;\n"

		"layout (location = 0) in vec4 Position;\n"
		"layout (location = 1) in vec3 Normal;\n"
		"layout (location = 2) in vec2 TCoord;\n"

		"out vec3 vertNormal;\n"
		"out vec2 vertTCoord;\n"
		"out float vertOccl;\n"
		"out vec3 vertLightDir[5];\n"

		"void main(void)\n"
		"{\n"
		"	gl_Position = Modelview*Position;\n"
		"	vertNormal = mat3(Modelview)*Normal;\n"
		"	vertTCoord = TCoord*vec2(32,8);\n"
		"	vertOccl = 0.5*(1+sqrt(2*abs(0.5-TCoord.y)));\n"
		"	for(int i=0; i<5; ++i)\n"
		"	{\n"
		"		vertLightDir[i]=LightPos[i]-gl_Position.xyz;\n"
		"	}\n"
		"	gl_Position = Projection*gl_Position;\n"
		"}\n"
		));
		vs.compile();
		vs.report_compile_error();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 140\n"

		"const vec3 Color1 = vec3(0.1, 0.1, 0.1);\n"
		"const vec3 Color2 = vec3(0.8, 0.6, 0.1);\n"

		"in vec3 vertNormal;\n"
		"in vec2 vertTCoord;\n"
		"in float vertOccl;\n"
		"in vec3 vertLightDir[5];\n"
		"out vec3 fragColor;\n"

		"float Pattern(vec2 tc)\n"
		"{\n"
		"	return float(int(tc.x+tc.y)%2);\n"
		"}\n"

		"void main(void)\n"
		"{\n"
		"	float O = min(pow(vertOccl+0.2,6),1);\n"
		"	float A1 = pow(O,2)*0.1;\n"
		"	float A2 = sqrt(O)*0.1;\n"
		"	float D1 = 0;\n"
		"	float D2 = 0;\n"
		"	float S1 = 0;\n"
		"	float S2 = 0;\n"
		"	for(int i=0; i<5; ++i)\n"
		"	{\n"
		"		vec3 LD = vertLightDir[i];\n"
		"		float L = length(LD);\n"
		"		float DL = dot(vertNormal, LD/L);\n"
		"		D1 += max(DL/L, 0)*2;\n"
		"		D2 += sqrt(max(DL/L, 0))*1.2;\n"
		"		S1 += pow(clamp(DL+1.0/L, 0, 1),256)*0.7;\n"
		"		S2 += pow(clamp(DL+1.5/L, 0, 1), 16)*0.2;\n"
		"	}\n"
		"	fragColor = mix(\n"
		"		O*((A1+D1+S1*0.5)*Color1+vec3(S1)),\n"
		"		O*((A2+D2+S2*0.5)*Color2+vec3(S2)),\n"
		"		Pattern(vertTCoord)\n"
		"	);\n"
		"}\n"
		));
		fs.compile();
		fs.report_compile_error();

		attach(vs);
		attach(fs);
		link();
		report_link_error();

		gl.use(*this);

		gl.query_location(projection, *this, "Projection");
		gl.query_location(modelview, *this, "Modelview");
	}
};

class lighting_example
 : public example
{
private:
	lighting_program prog;

	shapes::generator_wrapper<shapes::unit_torus_gen, 3> shape;

	float shp_turns;

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
	lighting_example(
		const example_state_view& state,
		eagine::memory::buffer& temp_buffer
	): prog()
	 , shape(
		temp_buffer,
		(shapes::vertex_attrib_kind::position  |0)+
		(shapes::vertex_attrib_kind::normal    |1)+
		(shapes::vertex_attrib_kind::wrap_coord|2),
		96, 144
	), shp_turns(0.0f)
	 , cam_orbit(0.0f)
	 , cam_turns(0.0f)
	 , cam_pitch(0.5f)
	 , cam_dist_dir(-1)
	 , cam_turn_dir(1)
	 , cam_elev_dir(1)
	{
		gl.clear_color(0.25f, 0.25f, 0.2f, 0);
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
			const float s = state.frame_duration().value()/5;

			mod_cam_orbit(s*cam_dist_dir);
			mod_cam_turns(s*cam_turn_dir);
			mod_cam_pitch(s*cam_elev_dir);

			set_projection(state);
		}
	}

	void render(const example_state_view& state)
	override
	{
		shp_turns += 0.1f*state.frame_duration().value();

		gl.uniform(
			prog.modelview,
			matrix_rotation_x(turns_(shp_turns)/1)*
			matrix_rotation_y(turns_(shp_turns)/2)*
			matrix_rotation_z(turns_(shp_turns)/3)
		);

		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);
		shape.draw();
	}

	bool continue_running(const example_state_view& state)
	override
	{
		return state.user_idle_time() < seconds_(20);
	}
};

std::unique_ptr<example>
make_example(const example_params&, const example_state_view& state)
{
	eagine::memory::buffer temp_buffer;
	return std::unique_ptr<example>(new lighting_example(
		state,
		temp_buffer
	));
}

void adjust_params(example_params& params)
{
	params.depth_buffer(true);
	params.stencil_buffer(false);
}

} // namespace oglplus
