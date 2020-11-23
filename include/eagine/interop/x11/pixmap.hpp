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

class Pixmap : public DisplayObject<::Pixmap> {
public:
    Pixmap(
      const Display& display,
      const VisualInfo& vi,
      unsigned width,
      unsigned height)
      : DisplayObject<::Pixmap>(
          display,
          ::XCreatePixmap(
            display,
            RootWindow(display.Get(), vi->screen),
            width,
            height,
            unsigned(vi->depth)),
          ::XFreePixmap,
          "Error creating X Pixmap") {}
};

} // namespace eagine::x11

#endif
