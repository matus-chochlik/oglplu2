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
	gl.program_delete_status(prog);
	gl.program_link_status(prog);
	gl.program_info_log_length(prog);
	gl.program_info_log(prog, span<char>());
	gl.program_active_attributes(prog);
	gl.program_active_attribute_max_length(prog);
	gl.get_active_attrib(prog, 0, span<char>(), size, type);
	gl.program_active_uniforms(prog);
	gl.program_active_uniform_max_length(prog);
	gl.get_active_uniform(prog, 0, span<char>(), size, type);

	prog.attach(shdr);
	prog.detach(shdr);
	prog.link();
	prog.delete_status();
	prog.link_status();
	prog.info_log_length();
	prog.info_log(span<char>());
	prog.active_attributes();
	prog.active_attribute_max_length();
	prog.get_active_attrib(0, span<char>(), size, type);
	prog.active_uniforms();
	prog.active_uniform_max_length();
	prog.get_active_uniform(0, span<char>(), size, type);
}

// TODO
