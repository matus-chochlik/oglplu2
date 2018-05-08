/**
 *  @file oglplus/oper/pixel_transfer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline outcome<void>
pixel_transfer_state::clamp_color(
  clamp_color_target target, boolean clamp) noexcept {
    OGLPLUS_GLFUNC(ClampColor)(GLenum(target), GLboolean(clamp));
    OGLPLUS_VERIFY(ClampColor, gl_enum_value(target), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
template <typename T>
static outcome<void>
read_pixels(GLint x,
  GLint y,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  pixel_data_type type,
  span<T> data) noexcept {
#if defined(GL_VERSION_4_5)
    OGLPLUS_GLFUNC(ReadnPixels)
    (x,
      y,
      width,
      height,
      GLenum(format),
      GLenum(type),
      GLsizei(data.size()),
      data.data());
    OGLPLUS_VERIFY(ReadnPixels, gl_enum_value(format), debug);
    return {};
#else
    OGLPLUS_GLFUNC(ReadPixels)
    (x, y, width, height, GLenum(format), GLenum(type), data.data());
    OGLPLUS_VERIFY(ReadPixels, gl_enum_value(format), debug);
    return {};
#endif
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
