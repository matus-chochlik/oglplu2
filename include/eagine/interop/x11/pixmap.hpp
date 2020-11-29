/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_X11_PIXMAP_HPP
#define EAGINE_INTEROP_X11_PIXMAP_HPP

#include "display.hpp"
#include "visual_info.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine::x11 {

class pixmap : public display_object<::Pixmap> {
public:
    pixmap(
      const display& dpy,
      const visual_info& vi,
      unsigned width,
      unsigned height)
      : display_object<::Pixmap>(
          dpy,
          ::XCreatePixmap(
            dpy,
            RootWindow(dpy.get(), vi->screen),
            width,
            height,
            unsigned(vi->depth)),
          ::XFreePixmap,
          "Error creating X Pixmap") {}
};

} // namespace eagine::x11

#endif
