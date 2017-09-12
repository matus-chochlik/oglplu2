/**
 *  @file oglplus/texgen/render_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <sstream>
#include <iostream>
#include <cassert>
#include <eagine/maybe_unused.hpp>
#include <oglplus/shader.hpp>
#include <oglplus/program.hpp>
#include <oglplus/buffer.hpp>
#include <oglplus/vertex_array.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>

#include <oglplus/operations.hpp>
#include <oglplus/constants.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::_init_screen(void)
{
	operations gl;
	constants GL;

	if(_data) buffer::delete_(_data);
	if(_vao) vertex_array::delete_(_vao);

	vertex_array::gen_(_vao);
	gl.bind(_vao);

	GLfloat data[2*2*4] = {
		-1.0f, -1.0f,
		-1.0f,  1.0f,
		 1.0f, -1.0f,
		 1.0f,  1.0f,
		 0.0f,  0.0f,
		 0.0f,  1.0f,
		 1.0f,  0.0f,
		 1.0f,  1.0f,
	};

	buffer::gen_(_data);
	gl.bind(GL.array_buffer, _data);
	gl.buffer_data(GL.array_buffer, data, GL.static_draw);

	vertex_attrib_location va_p(0);
	gl.vertex_array_attrib_pointer(
		va_p,
		2, GL.float_,
		false, 0, static_cast<GLfloat*>(nullptr)+0
	);
	gl.enable_vertex_array_attrib(va_p);

	vertex_attrib_location va_c(1);
	gl.vertex_array_attrib_pointer(
		va_c,
		2, GL.float_,
		false, 0, static_cast<GLfloat*>(nullptr)+8
	);
	gl.enable_vertex_array_attrib(va_c);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::_update_program(void)
{
	operations gl;
	constants GL;

	if(_prog) program::delete_(_prog);
	program::gen_(_prog);

	shader vs(GL.vertex_shader);
	vs.source(glsl_literal(
		"#version 150\n"
		"in vec2 Position;\n"
		"in vec2 Coordinate;\n"
		"out vec3 oglptg_nc;\n"
		"void main(void)\n"
		"{\n"
		"	gl_Position = vec4(Position, 0.0, 1.0);\n"
		"	oglptg_nc = vec3(Coordinate, 0.0);\n"
		"}\n"
	));
	vs.compile();
	vs.report_compile_error();
	gl.attach_shader(_prog, vs);

	std::stringstream fs_src;
	compile_context ctxt;
	make_fragment_shader_source(fs_src, ctxt);

	shader fs(GL.fragment_shader);
	fs.source(glsl_string_ref(fs_src.str()));
	fs.compile();
	fs.report_compile_error();
	gl.attach_shader(_prog, fs);


	gl.link_program(_prog);
	gl.use_program(_prog);
	gl.query_location(_voxel_size, _prog, "oglptg_vs");

	_input.prepare_connected();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_node::render_node(void)
 : _input(*this, cstr_ref("Input"), 0.5f, 0.5f, 0.5f, 1.0f)
 , _xdiv(1)
 , _ydiv(1)
 , _tile(0)
 , _render_version(0)
{
	_render_params.version = 0;
	_render_params.width = 1;
	_render_params.height = 1;
	_init_screen();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_node::~render_node(void)
{
	if(_prog) program::delete_(_prog);
	if(_data) buffer::delete_(_data);
	if(_vao) vertex_array::delete_(_vao);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::draw_screen(void)
{
	operations gl;
	constants GL;

	gl.draw_arrays(GL.triangle_strip, 0, 4);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
render_node::
make_fragment_shader_source(std::ostream& out, compile_context& ctxt)
{
	out << "#version " << ctxt.glsl_version() << std::endl;

	_input.definitions(out, ctxt);

	out << "out vec4 oglptg_out;" << std::endl;
	out << "in vec3 oglptg_nc;" << std::endl;
	out << "uniform vec3 oglptg_vs;" << std::endl;
	out << "const vec3 oglptg_vo = vec3(0);" << std::endl;
	out << std::endl;

	out << "void main(void)" << std::endl;
	out << "{" << std::endl;
	out << "	oglptg_out = ";

	const slot_data_type v4 = slot_data_type::float_4;
	out << expr::conversion_prefix{_input.output().value_type(), v4};
	out << expr::output_id{_input.output(), ctxt};
	out << expr::render_param_pass{_input.output()};
	out << expr::conversion_suffix{_input.output().value_type(), v4};
	out << ";" << std::endl;

	out << "}" << std::endl;
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
render_node::type_name(void) 
{
	return cstr_ref("Render");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
render_node::input_count(void)
{
	return 1;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
render_node::input(span_size_t index)
{
	EAGINE_MAYBE_UNUSED(index);
	assert(index < input_count());
	return _input;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::update_needed(void)
{
	_needs_update = true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::update_if_needed(void)
{
	if(_needs_update)
	{
		_update_program();
		_needs_update = false;
	}
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_node::render(const render_params& params)
{
	if(_render_version < params.version)
	{
		update_if_needed();

		operations gl;
		constants GL;

		if(_tile == 0)
		{
			if(!_input.render_connected(params))
			{
				return false;
			}
			if(_voxel_size)
			{
				gl.uniform(
					_voxel_size,
					vec3(
						1.f/params.width,
						1.f/params.height,
						1.f
					)
				);
			}
		}
		int x_tile = _tile%_xdiv;
		int y_tile = _tile/_ydiv;

		int w = params.width/_xdiv;
		int h = params.width/_ydiv;

		gl.enable(GL.scissor_test);
		gl.scissor(
			GLint(x_tile*w),
			GLint(y_tile*h),
			GLint(w+1),
			GLint(h+1)
		);
		draw_screen();
		gl.disable(GL.scissor_test);

		if(++_tile < _xdiv*_ydiv)
		{
			return false;
		}

		_tile = 0;
		_render_version = params.version;
	}
	return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_node::render(void)
{
	if(render(_render_params))
	{
		++_render_params.version;
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::
set_divisions(
	eagine::valid_if_positive<int> xdiv,
	eagine::valid_if_positive<int> ydiv
)
{
	_xdiv = xdiv.value_or(1);
	_ydiv = ydiv.value_or(1);
	_tile = 0;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_node::
set_dimensions(
	eagine::valid_if_positive<int> width,
	eagine::valid_if_positive<int> height
)
{
	_render_params.width = width.value_or(1);
	_render_params.height = height.value_or(1);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

