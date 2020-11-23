/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_GLX_PIXMAP_HPP
#define EAGINE_INTEROP_GLX_PIXMAP_HPP

#include "../x11/display.hpp"
#include "../x11/pixmap.hpp"
#include "../x11/visual_info.hpp"

#include <GL/glx.h>
#include <stdexcept>

namespace eagine::glx {

class pixmap
  : public x11::display_object<::GLXPixmap, void(::Display*, ::GLXPixmap)> {
public:
    pixmap(
      const x11::display& dpy,
      const x11::visual_info& vi,
      const x11::pixmap& pmp)
      : x11::display_object<::GLXPixmap, void(::Display*, ::GLXPixmap)>(
          dpy,
          ::glXCreateGLXPixmap(dpy, vi, pmp),
          ::glXDestroyGLXPixmap,
          "Error creating glX Pixmap") {}
};

} // namespace eagine::glx

#endif
