/**
 *  @file oglplus/oper/viewport.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/oper/numeric_queries.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void>
viewport_state::viewport(GLint x, GLint y, GLsizei w, GLsizei h) noexcept {
    OGLPLUS_GLFUNC(Viewport)(x, y, w, h);
    OGLPLUS_VERIFY_SIMPLE(Viewport, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
viewport_state::viewport(GLsizei w, GLsizei h) noexcept {
    OGLPLUS_GLFUNC(Viewport)(0, 0, w, h);
    OGLPLUS_VERIFY_SIMPLE(Viewport, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<viewport_extents>
viewport_state::get_viewport(void) noexcept {
    viewport_extents result;
    return numeric_queries::get_float_v(numeric_query(GL_VIEWPORT), {result._v})
      .add(result);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1)
inline outcome<void>
viewport_state::viewport(
  viewport_index index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) noexcept {
#if !OGLPLUS_NO_LIMIT_CHECKS
    if(auto invalid_index = failure(check_below_limit(index))) {
        return std::move(invalid_index);
    }
#endif
    OGLPLUS_GLFUNC(ViewportIndexedf)(GLuint(index), x, y, w, h);
    OGLPLUS_VERIFY(ViewportIndexedf, gl_index(GLuint(index)), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
viewport_state::viewport(
  viewport_index index, const viewport_extents& vpe) noexcept {
#if !OGLPLUS_NO_LIMIT_CHECKS
    if(auto invalid_index = failure(check_below_limit(index))) {
        return std::move(invalid_index);
    }
#endif
    OGLPLUS_GLFUNC(ViewportIndexedfv)(GLuint(index), vpe._v);
    OGLPLUS_VERIFY(ViewportIndexedfv, gl_index(GLuint(index)), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
viewport_state::viewport_array(
  viewport_index first, span<const GLfloat> vpe) noexcept {
    assert(vpe.size() % 4 == 0);
#if !OGLPLUS_NO_LIMIT_CHECKS
    if(auto invalid_index = failure(check_below_limit(first))) {
        return std::move(invalid_index);
    }
#endif
    OGLPLUS_GLFUNC(ViewportArrayv)
    (GLuint(first), GLsizei(vpe.size()), vpe.data());
    OGLPLUS_VERIFY(ViewportArrayv, gl_index(GLuint(first)), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<viewport_extents>
viewport_state::get_viewport(viewport_index index) noexcept {
    viewport_extents result;
#if !OGLPLUS_NO_LIMIT_CHECKS
    if(auto invalid_index = failure(check_below_limit(index))) {
        return std::move(invalid_index).add(result);
    }
#endif
    return numeric_queries::get_float_v(
             numeric_query(GL_VIEWPORT), GLuint(index), {result._v})
      .add(result);
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
