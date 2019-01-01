/**
 * Copyright Matus Chochlik.
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt
 */
#define OGLPLUS_CONFIG_QUERY_GL_VER_MAJOR 3
#define OGLPLUS_CONFIG_QUERY_GL_VER_MINOR 0

// clang-format off
#include "decl_GL_test.ipp"
#include "has_GL_ARB_geometry_shader4.ipp"
// clang-format on

bool do_query_gl() {
#if !defined(GL_VERSION_4_1)
    if(!does_have_ARB_geometry_shader4()) {
        return false;
    }
#endif

#if !defined(GL_GEOMETRY_SHADER)
    return false;
#endif

    unsigned missing_gl_symbols = 0;

    OGLPLUS_CONFIG_ASSERT_GL_FUNC(glProgramParameteri);
    // TODO?

    return missing_gl_symbols == 0;
}

#include "impl_GL_test.ipp"
