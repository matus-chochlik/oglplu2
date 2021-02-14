/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEROP_GLX_PBUFFER_HPP
#define EAGINE_INTEROP_GLX_PBUFFER_HPP

#include "../x11/display.hpp"
#include "fb_config.hpp"

#include <GL/glx.h>
#include <stdexcept>

namespace eagine::glx {

class pbuffer
  : public x11::display_object<::GLXPbuffer, void(::Display*, ::GLXPbuffer)> {
public:
    pbuffer(
      const x11::display& dpy,
      const glx::fb_config& fbc,
      const int* attrib_list)
      : x11::display_object<::GLXPbuffer, void(::Display*, ::GLXPbuffer)>(
          dpy,
          ::glXCreatePbuffer(dpy, fbc, attrib_list),
          ::glXDestroyPbuffer,
          "Error creating glX Pbuffer") {}
};

} // namespace eagine::glx

#endif
