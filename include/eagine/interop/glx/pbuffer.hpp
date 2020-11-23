/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_GLX_PBUFFER_HPP
#define EAGINE_INTEROP_GLX_PBUFFER_HPP

#include "../x11/display.hpp"
#include "fb_config.hpp"

#include <GL/glx.h>
#include <stdexcept>

namespace eagine::glx {

class Pbuffer
  : public x11::DisplayObject<::GLXPbuffer, void(::Display*, ::GLXPbuffer)> {
public:
    Pbuffer(
      const x11::Display& display,
      const glx::FBConfig& fbc,
      const int* attrib_list)
      : x11::DisplayObject<::GLXPbuffer, void(::Display*, ::GLXPbuffer)>(
          display,
          ::glXCreatePbuffer(display, fbc, attrib_list),
          ::glXDestroyPbuffer,
          "Error creating glX Pbuffer") {}
};

} // namespace eagine::glx

#endif
