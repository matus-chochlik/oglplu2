/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_X11_WINDOW_HPP
#define EAGINE_INTEROP_X11_WINDOW_HPP

#include "color_map.hpp"
#include "display.hpp"
#include "visual_info.hpp"

#include <X11/Xlib.h>
#include <cassert>
#include <stdexcept>

namespace eagine::x11 {

class window : public display_object<::Window> {
private:
    static auto make_window(
      const display& dpy,
      const visual_info& vi,
      const colormap& cmap,
      int pos_x,
      int pos_y,
      unsigned width,
      unsigned height) -> ::Window {
        ::XSetWindowAttributes swa;
        swa.colormap = cmap.handle();
        swa.background_pixmap = None;
        swa.border_pixel = 0;
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        swa.event_mask = StructureNotifyMask;

        return ::XCreateWindow(
          dpy,
          RootWindow(dpy.get(), vi->screen),
          pos_x,
          pos_y,
          width,
          height,
          0,
          vi->depth,
          InputOutput,
          vi->visual,
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          CWBorderPixel | CWColormap | CWEventMask,
          &swa);
    }

public:
    window(
      const display& dpy,
      const visual_info& vi,
      const colormap& cmap,
      const char* title,
      int pos_x,
      int pos_y,
      unsigned width,
      unsigned height)
      : display_object<::Window>(
          dpy,
          make_window(dpy, vi, cmap, pos_x, pos_y, width, height),
          ::XDestroyWindow,
          "Error creating X Window") {
        ::XSizeHints size_hints;
        size_hints.width = int(width);
        size_hints.height = int(height);
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        size_hints.flags = USSize;
        ::XSetNormalHints(dpy, this->handle(), &size_hints);

        ::Atom wmDelete = ::XInternAtom(dpy, "WM_DELETE_WINDOW", True);
        ::XSetWMProtocols(dpy, this->handle(), &wmDelete, 1);

        ::XStoreName(dpy, this->handle(), title);
        ::XMapWindow(dpy, this->handle());
    }

    void select_input(long event_mask) const {
        ::XSelectInput(this->display_ref(), this->handle(), event_mask);
    }
};

} // namespace eagine::x11

#endif
