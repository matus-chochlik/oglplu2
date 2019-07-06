/**
 *  @file oglplus/oper/compat_drawing.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifdef GL_ARB_compatibility
#include <eagine/assert.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::vertex(
  span<const GLshort> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 2);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 2) {
        OGLPLUS_GLFUNC(Vertex2sv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(Vertex3sv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Vertex4sv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::vertex(
  span<const GLint> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 2);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 2) {
        OGLPLUS_GLFUNC(Vertex2iv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(Vertex3iv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Vertex4iv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::vertex(
  span<const GLfloat> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 2);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 2) {
        OGLPLUS_GLFUNC(Vertex2fv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(Vertex3fv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Vertex4fv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::vertex(
  span<const GLdouble> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 2);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 2) {
        OGLPLUS_GLFUNC(Vertex2dv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(Vertex3dv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Vertex4dv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::color(
  span<const GLubyte> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 3);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 3) {
        OGLPLUS_GLFUNC(Color3ubv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Color4ubv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::color(
  span<const GLint> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 3);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 3) {
        OGLPLUS_GLFUNC(Color3iv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Color4iv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::color(
  span<const GLfloat> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 3);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 3)
        OGLPLUS_GLFUNC(Color3fv)(v.data());
    if(n == 4)
        OGLPLUS_GLFUNC(Color4fv)(v.data());
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::color(
  span<const GLdouble> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 3);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 3) {
        OGLPLUS_GLFUNC(Color3dv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(Color4dv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::tex_coord(
  span<const GLshort> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 1);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 1) {
        OGLPLUS_GLFUNC(TexCoord1sv)(v.data());
    }
    if(n == 2) {
        OGLPLUS_GLFUNC(TexCoord2sv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(TexCoord3sv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(TexCoord4sv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::tex_coord(
  span<const GLint> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 1);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 1) {
        OGLPLUS_GLFUNC(TexCoord1iv)(v.data());
    }
    if(n == 2) {
        OGLPLUS_GLFUNC(TexCoord2iv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(TexCoord3iv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(TexCoord4iv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::tex_coord(
  span<const GLfloat> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 1);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 1) {
        OGLPLUS_GLFUNC(TexCoord1fv)(v.data());
    }
    if(n == 2) {
        OGLPLUS_GLFUNC(TexCoord2fv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(TexCoord3fv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(TexCoord4fv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> compatibility_drawing::tex_coord(
  span<const GLdouble> v, span_size_t n) noexcept {
    EAGINE_ASSERT(n >= 1);
    EAGINE_ASSERT(n <= 4);
    EAGINE_ASSERT(n <= v.size());

    if(n == 1) {
        OGLPLUS_GLFUNC(TexCoord1dv)(v.data());
    }
    if(n == 2) {
        OGLPLUS_GLFUNC(TexCoord2dv)(v.data());
    }
    if(n == 3) {
        OGLPLUS_GLFUNC(TexCoord3dv)(v.data());
    }
    if(n == 4) {
        OGLPLUS_GLFUNC(TexCoord4dv)(v.data());
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
#endif
