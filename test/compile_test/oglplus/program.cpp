/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/program.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_program_test_1(void)
{
	oglplus_object_name_test<program_name>();
	oglplus_object_test<program>();
}

void oglplus_program_test_ops1(void)
{
	oper::program_ops gl;
	program prog;
	program_array<4> progs;
	shader shdr(shader_type(GL_VERTEX_SHADER));
	sl_data_type type;
	GLint size;

	gl.attach_shader(prog, shdr);
	gl.detach_shader(prog, shdr);
	gl.attach_shader(progs[0], shdr);
	gl.link_program(prog);
	gl.use_program(prog);
	gl.current_program();
	gl.get_program_delete_status(prog);
	gl.get_program_link_status(prog);
	gl.get_program_info_log_length(prog);
	gl.get_program_info_log(prog, span<char>());
	gl.get_program_active_attributes(prog);
	gl.get_program_active_attribute_max_length(prog);
	gl.get_active_attrib(prog, 0, span<char>(), size, type);
	gl.get_program_active_uniforms(prog);
	gl.get_program_active_uniform_max_length(prog);
	gl.get_active_uniform(prog, 0, span<char>(), size, type);

	prog.attach(shdr);
	prog.detach(shdr);
	prog.link();
	prog.get_delete_status();
	prog.get_link_status();
	prog.get_info_log_length();
	prog.get_info_log(span<char>());
	prog.get_active_attributes();
	prog.get_active_attribute_max_length();
	prog.get_active_attrib(0, span<char>(), size, type);
	prog.get_active_uniforms();
	prog.get_active_uniform_max_length();
	prog.get_active_uniform(0, span<char>(), size, type);
}

// TODO
