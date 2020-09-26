/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_X11_COLOR_MAP_1107121519_HPP
#define UTILS_OGLPLUS_X11_COLOR_MAP_1107121519_HPP

#include "display.hpp"
#include "visual_info.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine {
namespace oglp {
namespace x11 {

class Colormap : public DisplayObject<::Colormap> {
public:
    Colormap(const Display& display, const VisualInfo& vi)
      : DisplayObject<::Colormap>(
          display,
          ::XCreateColormap(
            display,
            RootWindow(display.Get(), vi->screen),
            vi->visual,
            AllocNone),
          ::XFreeColormap,
          "Error creating X Colormap") {}
};

} // namespace x11
} // namespace oglp
} // namespace eagine

#endif // include guard
