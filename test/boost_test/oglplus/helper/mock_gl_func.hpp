/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_OGLPLUS_HELPER_FAKE_GL_FUNC_HPP
#define TEST_OGLPLUS_HELPER_FAKE_GL_FUNC_HPP

#include "../../eagine/helper/mock_func.hpp"

namespace oglplus {

template <typename Sig>
using mock_gl_function = eagine::mock_function<Sig>;

using eagine::mock_ptr;

static inline GLenum
mock_glGetError(void) noexcept {
    return GL_NO_ERROR;
}

#define OGLPLUS_MOCK_GLFUNC(NAME, SIG) \
    static oglplus::mock_gl_function<SIG> mock_gl##NAME(#NAME);

#define OGLPLUS_GLFUNC(FUNC) mock_gl##FUNC.called_function(#FUNC)

#define OGLPLUS_GL_GET_ERROR() oglplus::mock_glGetError()

} // namespace oglplus

#endif // include guard
