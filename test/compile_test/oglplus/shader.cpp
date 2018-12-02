/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl.hpp>
#include <oglplus/shader.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_shader_test_1(void) {
    oglplus_object_name_test<shader_name>();
    oglplus_object_test<shader>(shader_type(GL_VERTEX_SHADER));
}

void
oglplus_shader_test_ops1(void) {
    oper::shader_ops gl;
    shader shdr(shader_type(GL_VERTEX_SHADER));
    shader_array<4> shdrs(shader_type(GL_FRAGMENT_SHADER));
    glsl_source_ref src(0, nullptr, nullptr);

#if defined(GL_VERSION_4_1)
    gl.release_shader_compiler();
#endif
    gl.shader_source(shdr, src);
    gl.get_shader_source_length(shdr);
    gl.get_shader_source(shdr, span<char>());
    gl.compile_shader(shdr);
    gl.shader_source(shdrs[0], src);

    gl.get_shader_type(shdr);
    gl.get_shader_delete_status(shdr);
    gl.get_shader_compile_status(shdr);
    gl.get_shader_info_log_length(shdr);
    gl.get_shader_info_log(shdr, span<char>());

    shdr.get_type();
    shdr.source(src);
    shdr.get_source_length();
    shdr.get_source(span<char>());
    shdr.compile();
    shdr.get_compile_status();
    shdr.get_delete_status();
    shdr.get_info_log_length();
    shdr.get_info_log(span<char>());
}

// TODO
