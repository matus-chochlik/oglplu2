/**
 *  example oglplus/014_voronoi.cpp
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
#include <oglplus/utils/image_file.hpp>
#include <oglplus/utils/program_file.hpp>

#include "example.hpp"
#include <vector>

namespace oglplus {

static constants  GL;
static operations gl;

class voronoi_program
 : public program
{
private:
	void _init(const program_source_file& prog_src)
	{
		for(std::size_t i=0, n=prog_src.shader_source_count(); i<n; ++i)
		{
			shader shdr(prog_src.shader_type(i));
			shdr.source(prog_src.shader_source(i));
			shdr.compile();
			shdr.report_compile_error();
			attach(shdr);
		}
		link();
		report_link_error();
	}
public:
	uniform<GLfloat> offset_loc;
	uniform<GLfloat> scale_loc;

	voronoi_program(const example_params& params)
	{
		std::string path = params.get_resource_file_path(
			example_resource_type::program_source,
			cstr_ref("014_voronoi.oglpprog")
		);
		_init(program_source_file(cstr_ref(path)));

		gl.use(*this);

		gl.query_location(offset_loc, *this, "Offset");
		gl.query_location(scale_loc, *this, "Scale");
	}
};

class random_texture
 : public texture
{
private:
	void init(const texture_image_file& image_data)
	{
		gl.bind(GL.texture_2d, *this);
		gl.texture_min_filter(GL.texture_2d, GL.nearest);
		gl.texture_mag_filter(GL.texture_2d, GL.nearest);
		gl.texture_wrap(
			GL.texture_2d,
			GL.texture_wrap_s,
			GL.repeat
		);
		gl.texture_image_2d(GL.texture_2d, image_data.spec());
	}
public:
	random_texture(const example_params& params)
	{
		std::string path = params.get_resource_file_path(
			example_resource_type::texture,
			cstr_ref("noise.256x256x3.oglptex")
		);
		init(texture_image_file(cstr_ref(path)));
	}
};

class screen_shape
{
private:
	buffer positions;
	buffer coords;
public:
	vertex_array vao;

	screen_shape(const program& prog)
	{
		gl.bind(vao);

		GLfloat position_data[4*2] = {
			-1.0f, -1.0f,
			-1.0f,  1.0f,
			 1.0f, -1.0f,
			 1.0f,  1.0f
		};

		gl.bind(GL.array_buffer, positions);
		gl.buffer_data(GL.array_buffer, position_data, GL.static_draw);

		vertex_attrib_location va_p;
		gl.query_location(va_p, prog, "Position");
		gl.vertex_array_attrib_pointer(
			va_p,
			2, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_p);

		GLfloat coord_data[4*2] = {
			-1.0f, -1.0f,
			-1.0f,  1.0f,
			 1.0f, -1.0f,
			 1.0f,  1.0f
		};

		gl.bind(GL.array_buffer, coords);
		gl.buffer_data(GL.array_buffer, coord_data, GL.static_draw);

		vertex_attrib_location va_c;
		gl.query_location(va_c, prog, "TexCoord");
		gl.vertex_array_attrib_pointer(
			va_c,
			2, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_c);
	}
};

class example_voronoi
 : public example
{
private:
	random_texture tex;
	voronoi_program prog;
	screen_shape screen;


	GLfloat ofs_x_dir, ofs_y_dir, offset_x, offset_y;
	GLfloat scale_dir, scale, aspect;

	static constexpr const float min_scale = 1.0f;
	static constexpr const float max_scale = 100.0f;
public:
	example_voronoi(const example_params& params)
	 : tex(params)
	 , prog(params)
	 , screen(prog)
	 , ofs_x_dir(1.f)
	 , ofs_y_dir(1.f)
	 , offset_x(-0.5f)
	 , offset_y(0.0f)
	 , scale_dir(1.f)
	 , scale(10.0f)
	 , aspect(1.0f)
	{

		gl.disable(GL.depth_test);
	}

	void pointer_motion(const example_state_view& state)
	override
	{
		if(state.pointer_dragging())
		{
			offset_x -= 2*state.norm_delta_pointer_x()*scale;
			offset_y -= 2*state.norm_delta_pointer_y()*scale;

			gl.uniform(prog.offset_loc, offset_x, offset_y);
		}
	}

	void pointer_scrolling(const example_state_view& state)
	override
	{

		scale *= float(std::pow(2,-state.norm_delta_pointer_z()));
		if(scale < min_scale) scale = min_scale;
		if(scale > max_scale) scale = max_scale;

		gl.uniform(prog.scale_loc, scale*aspect, scale);
	}

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(state.width(), state.height());

		aspect = state.aspect();
		gl.uniform(prog.scale_loc, scale*aspect, scale);
	}

	void user_idle(const example_state_view& state)
	override
	{
		if(state.user_idle_time() > seconds_(1))
		{
			const float t = value(state.frame_duration())*60;

			scale *= std::pow(1.f+0.05f*t, scale_dir);
			if(scale < min_scale)
			{
				scale_dir *= -1.f;
				ofs_x_dir *= -1.f;
				ofs_y_dir *= ofs_x_dir;
				scale = min_scale;
			}
			if(scale > max_scale)
			{
				scale_dir *= -1.f;
				ofs_y_dir *= -1.f;
				ofs_x_dir *= ofs_y_dir;
				scale = max_scale;
			}

			offset_x += ofs_x_dir*t*scale/30;
			offset_y += ofs_y_dir*t*scale/30;

			gl.uniform(prog.offset_loc, offset_x, offset_y);
			gl.uniform(prog.scale_loc, scale*aspect, scale);
		}
	}

	bool continue_running(const example_state_view& state)
	override
	{
		return state.user_idle_time() < seconds_(20);
	}

	void render(const example_state_view& /*state*/)
	override
	{
		gl.draw_arrays(GL.triangle_strip, 0, 4);
	}
};

std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params& params,
	const example_state_view&
)
{
	return std::unique_ptr<example>(new example_voronoi(params));
}

void adjust_params(example_params& params)
{
	params.rand_seed(1234);
	params.depth_buffer(false);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
