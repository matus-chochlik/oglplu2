/**
 *  example oglplus/000_cube.cpp
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
		"out vec3 vertColor;\n"

		"void main(void)\n"
		"{\n"
		"	gl_Position = Projection*Position;\n"
		"	vertColor = mix(BoxCoord,abs(Normal),0.5);\n"
		"}\n"
		));
		vs.compile();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 140\n"

		"in  vec3 vertColor;\n"
		"out vec3 fragColor;\n"

		"void main(void)\n"
		"{\n"
		"	fragColor = vertColor;\n"
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

class example_cube
 : public example
{
private:
	example_program prog;

	shapes::generator_wrapper<shapes::unit_cube_gen, 3> cube;

	float cam_radius;
	radians_t<float> cam_azimuth;
	radians_t<float> cam_elevation;

	short cam_radius_dir;
	short cam_azimuth_dir;
	short cam_elevation_dir;

	void mod_cam_radius(float inc)
	{
		const float max_cam_radius = 8.0f;
		const float min_cam_radius = 1.5f;

		cam_radius += inc;
		if(cam_radius > max_cam_radius)
		{
			cam_radius = max_cam_radius;
			cam_radius_dir = -1;
		}
		if(cam_radius < min_cam_radius)
		{
			cam_radius = min_cam_radius;
			cam_radius_dir = 1;
		}
	}

	void mod_cam_azimuth(radians_t<float> inc)
	{
		cam_azimuth += inc;
		cam_azimuth_dir = (inc > radians_(0))?1:-1;
	}

	void mod_cam_elevation(radians_t<float> inc)
	{

		const radians_t<float> max_cam_elevation = radians_(+1.57f);
		const radians_t<float> min_cam_elevation = radians_(-1.57f);

		cam_elevation += inc;
		if(cam_elevation > max_cam_elevation)
		{
			cam_elevation = max_cam_elevation;
			cam_elevation_dir = -1;
		}
		if(cam_elevation < min_cam_elevation)
		{
			cam_elevation = min_cam_elevation;
			cam_elevation_dir = 1;
		}
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
				cam_radius,
				cam_azimuth,
				cam_elevation
			)
		);
	}
public:
	example_cube(
		const example_state_view& state,
		eagine::memory::buffer& temp_buffer
	): prog()
	 , cube(
		temp_buffer,
		(shapes::vertex_attrib_kind::position|0),
		(shapes::vertex_attrib_kind::normal|1),
		(shapes::vertex_attrib_kind::box_coord|2)
	), cam_radius(2)
	 , cam_azimuth(1)
	 , cam_elevation(1)
	 , cam_radius_dir(-1)
	 , cam_azimuth_dir(1)
	 , cam_elevation_dir(1)
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
			mod_cam_azimuth(
				-state.norm_delta_pointer_x()*
				turns_(0.5f)
			);
			mod_cam_elevation(
				-state.norm_delta_pointer_y()*
				turns_(0.5f)
			);
			set_projection(state);
		}
	}

	void pointer_scrolling(const example_state_view& state)
	override
	{
		mod_cam_radius(-state.norm_delta_pointer_z()*1.5f);
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
			mod_cam_radius(0.05f*cam_radius_dir);
			mod_cam_azimuth(radians_(0.05f*cam_azimuth_dir));
			mod_cam_elevation(radians_(0.05f*cam_elevation_dir));

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
make_example(const example_params&, const example_state_view& state)
{
	eagine::memory::buffer temp_buffer;
	return std::unique_ptr<example>(new example_cube(state, temp_buffer));
}

void adjust_params(example_params& params)
{
	params.depth_buffer(true);
	params.stencil_buffer(false);
}

} // namespace oglplus
