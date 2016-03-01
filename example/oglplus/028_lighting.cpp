/**
 *  example oglplus/028_lighting.cpp
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
#include <oglplus/shapes/sphere.hpp>
#include <oglplus/shapes/torus.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/interpolate.hpp>

#include "example.hpp"

namespace oglplus {

static constants  GL;
static operations gl;

class erase_program
 : public program
{
public:
	uniform_location projection;

	erase_program(void)
	{
		shader vs(GL.vertex_shader);
		vs.source(glsl_literal(
		"#version 330\n"

		"uniform mat4 Projection;\n"

		"layout (location = 0) in vec3 Position;\n"

		"out vec3 vertCoord;\n"

		"void main(void)\n"
		"{\n"
		"	gl_Position = Projection*vec4(Position*50, 1);\n"
		"	vertCoord = Position*10;\n"
		"}\n"
		));
		vs.compile();
		vs.report_compile_error();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 140\n"

		"in vec3 vertCoord;\n"
		"out vec3 fragColor;\n"

		"float lines(float c)\n"
		"{\n"
		"	return pow(2*abs(c-floor(c+0.5)), 64);\n"
		"}\n"

		"float grid(vec3 c)\n"
		"{\n"
		"	return lines(c.x)+lines(c.y)+lines(c.z);\n"
		"}\n"

		"void main(void)\n"
		"{\n"
		"	fragColor = mix(\n"
		"		vec3(0.25, 0.25, 0.2),\n"
		"		vec3(0),\n"
		"		grid(vertCoord)\n"
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
	}

};

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
		auto projection = 
			matrix_perspective::y(
				right_angle_(),
				state.aspect(),
				0.5f, 50.f
			)*matrix_orbiting_y_up(
				vec3(),
				smooth_lerp(1.5f, 5.0f, cam_orbit),
				turns_(cam_turns),
				smooth_oscillate(radians_(1.5f), cam_pitch)
			);

		gl.use(light_prog);
		gl.uniform(light_prog.projection, projection);
		gl.use(erase_prog);
		gl.uniform(erase_prog.projection, projection);
	}
public:
	lighting_example(
		const example_state_view& state,
		eagine::memory::buffer& temp_buffer
	): erase_prog()
	 , light_prog()
	 , background(
		temp_buffer,
		(shapes::vertex_attrib_kind::position  |0),
		36, 72
	), shape(
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
		gl.clear_depth(1);
		gl.disable(GL.cull_face);

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
		gl.use(erase_prog);
		gl.disable(GL.depth_test);
		background.use();
		background.draw();

		shp_turns += 0.1f*state.frame_duration().value();

		gl.use(light_prog);
		gl.uniform(
			light_prog.modelview,
			matrix_rotation_x(turns_(shp_turns)/1)*
			matrix_rotation_y(turns_(shp_turns)/2)*
			matrix_rotation_z(turns_(shp_turns)/3)
		);

		gl.clear(GL.depth_buffer_bit);
		gl.enable(GL.depth_test);
		shape.use();
		shape.draw();
	}

	bool continue_running(const example_state_view& state)
	override
	{
		return state.user_idle_time() < seconds_(20);
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

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
