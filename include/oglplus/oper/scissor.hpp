/**
 *  @file oglplus/oper/scissor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_SCISSOR_1509260923_HPP
#define OGLPLUS_OPER_SCISSOR_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/gl_func.hpp"

namespace oglplus {
namespace oper {

struct scissor_state {
    static outcome<void>
    scissor(GLint x, GLint y, GLsizei w, GLsizei h) noexcept {
        OGLPLUS_GLFUNC(Scissor)(x, y, w, h);
        OGLPLUS_VERIFY_SIMPLE(Scissor, debug);
        return {};
    }

#if defined(GL_VERSION_4_1)
    static outcome<void>
    scissor(GLuint index, GLint x, GLint y, GLsizei w, GLsizei h) noexcept {
        OGLPLUS_GLFUNC(ScissorIndexed)(index, x, y, w, h);
        OGLPLUS_VERIFY(ScissorIndexed, gl_index(index), debug);
        return {};
    }
#endif
};

} // namespace oper
} // namespace oglplus

#endif // include guard
