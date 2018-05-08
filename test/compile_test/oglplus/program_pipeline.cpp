/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl_fixed.hpp>
#include <oglplus/program_pipeline.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_program_pipeline_test_1(void) {
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
    oglplus_object_name_test<program_pipeline_name>();
    oglplus_object_test<program_pipeline>();
#endif
}

void
oglplus_program_pipeline_test_ops1(void) {
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
    oper::program_pipeline_ops gl;
    program_name prog(0);
    program_pipeline ppl;
    program_pipeline_array<4> ppls;
    enum_bitfield<program_pipeline_stage> stages(GL_ALL_SHADER_BITS);

    gl.use_program_stages(ppl, stages, prog);
    gl.active_shader_program(ppl, prog);
    gl.validate_program_pipeline(ppl);
    gl.get_program_pipeline_validate_status(ppls[0]);
    gl.get_program_pipeline_active_program(ppl);
    gl.get_program_pipeline_info_log_length(ppl);
    gl.get_program_pipeline_info_log(ppl, span<char>());
    gl.report_program_pipeline_validate_error(ppls[1]);

    ppl.use_program_stages(stages, prog);
    ppl.active_program(prog);
    ppl.validate();
    ppl.get_validate_status();
    ppl.get_active_program();
    ppl.get_info_log_length();
    ppl.get_info_log(span<char>());
    ppl.report_validate_error();
#endif
}

// TODO
