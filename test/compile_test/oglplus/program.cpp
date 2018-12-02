/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl.hpp>
#include <oglplus/program.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_program_test_1(void) {
    oglplus_object_name_test<program_name>();
    oglplus_object_test<program>();
}

void
oglplus_program_test_ops1(void) {
    oper::program_ops gl;
    program prog;
    program_array<4> progs;
    shader shdr(shader_type(GL_VERTEX_SHADER));
    sl_data_type type;
    memory_block blk;
    GLint size;
    GLenum format;

    EAGINE_MAYBE_UNUSED(format);

    gl.attach_shader(prog, shdr);
    gl.detach_shader(prog, shdr);
    gl.attach_shader(progs[0], shdr);
    gl.link_program(prog);
    gl.validate_program(prog);
    gl.use_program(prog);
    gl.current_program();

#if defined(GL_VERSION_4_1)
    gl.program_binary_retrievable_hint(prog, true);
    gl.program_separable(prog, true);
    gl.get_program_binary_length(prog);
    gl.get_program_binary(prog, format, blk);
    gl.program_binary(prog, format, blk);
#endif

    gl.get_program_delete_status(prog);
    gl.get_program_link_status(prog);
    gl.get_program_validate_status(prog);

    gl.report_program_link_error(prog);
    gl.report_program_validate_error(prog);

    gl.get_program_info_log_length(prog);
    gl.get_program_info_log(prog, span<char>());
    gl.get_program_active_attributes(prog);
    gl.get_program_active_attribute_max_length(prog);
    gl.get_active_attrib(prog, 0, span<char>(), size, type);
    gl.get_program_active_uniforms(prog);
    gl.get_program_active_uniform_max_length(prog);
    gl.get_active_uniform(prog, 0, span<char>(), size, type);

#if defined(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS)
    gl.get_program_active_atomic_counter_buffers(prog);
#endif

    gl.get_program_transform_feedback_buffer_mode(prog);

#if defined(GL_VERSION_3_2)
    gl.get_program_geometry_vertices_out(prog);
#endif

#if defined(GL_VERSION_3_2)
    gl.get_program_geometry_input_type(prog);
#endif

#if defined(GL_VERSION_3_2)
    gl.get_program_geometry_output_type(prog);
#endif

#if defined(GL_VERSION_4_3)
    gl.get_program_compute_work_group_size(prog);
#endif

    prog.attach(shdr);
    prog.detach(shdr);
    prog.link();

#if defined(GL_VERSION_4_1)
    prog.binary_retrievable_hint(true);
    prog.separable(true);
    prog.get_binary_length();
    prog.get_binary(format, blk);
    prog.binary(format, blk);
#endif

    prog.get_delete_status();
    prog.get_link_status();
    prog.get_validate_status();

    prog.report_link_error();
    prog.report_validate_error();

    prog.get_info_log_length();
    prog.get_info_log(span<char>());
    prog.get_active_attributes();
    prog.get_active_attribute_max_length();
    prog.get_active_attrib(0, span<char>(), size, type);
    prog.get_active_uniforms();
    prog.get_active_uniform_max_length();
    prog.get_active_uniform(0, span<char>(), size, type);

#if defined(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS)
    prog.get_active_atomic_counter_buffers();
#endif

    prog.get_transform_feedback_buffer_mode();

#if defined(GL_VERSION_3_2)
    prog.get_geometry_vertices_out();
#endif

#if defined(GL_VERSION_3_2)
    prog.get_geometry_input_type();
#endif

#if defined(GL_VERSION_3_2)
    prog.get_geometry_output_type();
#endif

#if defined(GL_VERSION_4_3)
    prog.get_compute_work_group_size();
#endif
}

// TODO
