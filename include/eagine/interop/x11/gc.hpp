/// @file eagine/interop/x11/gc.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEROP_X11_GC_HPP
#define EAGINE_INTEROP_X11_GC_HPP

#include "display.hpp"
#include "pixmap.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine::x11 {

class gc : public display_object<::GC> {
public:
    gc(const display& dpy, const pixmap& pmp)
      : display_object<::GC>(
          dpy,
          ::XCreateGC(dpy, pmp, 0, nullptr),
          ::XFreeGC,
          "Error creating X GC (graphics context)") {}
};

} // namespace eagine::x11

#endif
