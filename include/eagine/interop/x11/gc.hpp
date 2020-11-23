/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_X11_GC_HPP
#define EAGINE_INTEROP_X11_GC_HPP

#include "display.hpp"
#include "pixmap.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine::x11 {

class GC : public DisplayObject<::GC> {
public:
    GC(const Display& display, const Pixmap& pixmap)
      : DisplayObject<::GC>(
          display,
          ::XCreateGC(display, pixmap, 0, nullptr),
          ::XFreeGC,
          "Error creating X GC (graphics context)") {}
};

} // namespace eagine::x11

#endif
