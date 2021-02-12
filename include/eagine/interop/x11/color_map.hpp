/// @file eagine/interop/x11/colormap.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEROP_X11_COLOR_MAP_HPP
#define EAGINE_INTEROP_X11_COLOR_MAP_HPP

#include "display.hpp"
#include "visual_info.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine::x11 {

class colormap : public display_object<::Colormap> {
public:
    colormap(const display& dpy, const visual_info& vi)
      : display_object<::Colormap>(
          dpy,
          ::XCreateColormap(
            dpy,
            RootWindow(dpy.get(), vi->screen),
            vi->visual,
            AllocNone),
          ::XFreeColormap,
          "Error creating X Colormap") {}
};

} // namespace eagine::x11

#endif
