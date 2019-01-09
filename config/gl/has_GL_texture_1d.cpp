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
// clang-format on

bool do_query_gl() {

#if !defined(GL_TEXTURE_1D)
    return false;
#endif

    unsigned missing_gl_symbols = 0;

    OGLPLUS_CONFIG_ASSERT_GL_FUNC(glTexImage1D);
    OGLPLUS_CONFIG_ASSERT_GL_FUNC(glTexSubImage1D);
    OGLPLUS_CONFIG_ASSERT_GL_FUNC(glCopyTexImage1D);
    OGLPLUS_CONFIG_ASSERT_GL_FUNC(glCopyTexSubImage1D);
    // TODO?

    return missing_gl_symbols == 0;
}

#include "impl_GL_test.ipp"
