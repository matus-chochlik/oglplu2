/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEROP_X11_VISUAL_INFO_HPP
#define EAGINE_INTEROP_X11_VISUAL_INFO_HPP

#include "../glx/fb_config.hpp"
#include "display.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine::x11 {

class visual_info : public object<::XVisualInfo, int(void*)> {
private:
    static auto _from_id(const display& dpy, int id) -> ::XVisualInfo* {
        ::XVisualInfo tpl;
        tpl.visualid = VisualID(id);
        int num_vis = 0;

        return ::XGetVisualInfo(dpy, VisualIDMask, &tpl, &num_vis);
    }

public:
    visual_info(const display& dpy, const glx::fb_config& fbc)
      : object<::XVisualInfo, int(void*)>(
          ::glXGetVisualFromFBConfig(dpy, fbc),
          ::XFree,
          "Error Getting X VisualInfo from GLX FB config") {}

    visual_info(const display& dpy, int visual_id)
      : object<::XVisualInfo, int(void*)>(
          _from_id(dpy, visual_id),
          ::XFree,
          "Error Getting X VisualInfo from visual ID") {}
};

} // namespace eagine::x11

#endif
