/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEROP_GLX_CONTEXT_HPP
#define EAGINE_INTEROP_GLX_CONTEXT_HPP

#include "../x11/display.hpp"
#include "../x11/window.hpp"
#include "drawable.hpp"
#include "fb_config.hpp"

#include <GL/glx.h>
#include <X11/Xlib.h>
#include <stdexcept>

namespace eagine::glx {

class context
  : public x11::display_object<::GLXContext, void(::Display*, ::GLXContext)> {
private:
    static auto make_context(
      const x11::display& dpy,
      const fb_config& fbc,
      int version_major,
      int version_minor,
      bool debugging,
      bool compatibility,
      ::GLXContext share_context = ::GLXContext(nullptr)) -> ::GLXContext {
        using glXCreateContextAttribsARBProc = GLXContext (*)(
          ::Display*, ::GLXFBConfig, ::GLXContext, Bool, const int*);

        glXCreateContextAttribsARBProc glXCreateContextAttribsARB = nullptr;
        glXCreateContextAttribsARB =
          reinterpret_cast<glXCreateContextAttribsARBProc>(glXGetProcAddressARB(
            reinterpret_cast<const GLubyte*>("glXCreateContextAttribsARB")));

        const int CONTEXT_MAJOR_VERSION_ARB = 0x2091;
        const int CONTEXT_MINOR_VERSION_ARB = 0x2092;
        const int CONTEXT_FLAGS_ARB = 0x2094;
        const int CONTEXT_PROFILE_MASK_ARB = 0x9126;
        const int CONTEXT_DEBUG_BIT_ARB = 0x0001;
        const int CONTEXT_CORE_PROFILE_BIT_ARB = 0x00000001;
        const int CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;

        ::GLXContext res{};

        if(compatibility) {
            int context_attribs[] = {
              CONTEXT_MAJOR_VERSION_ARB,
              version_major,
              CONTEXT_MINOR_VERSION_ARB,
              version_minor,
              CONTEXT_FLAGS_ARB,
              (debugging ? CONTEXT_DEBUG_BIT_ARB : 0),
              CONTEXT_PROFILE_MASK_ARB,
              (compatibility ? CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
                             : CONTEXT_CORE_PROFILE_BIT_ARB),
              None};
            res = glXCreateContextAttribsARB(
              dpy,
              fbc.handle(),
              share_context,
              True,
              static_cast<const int*>(context_attribs));
        } else {
            int context_attribs[] = {
              CONTEXT_MAJOR_VERSION_ARB,
              version_major,
              CONTEXT_MINOR_VERSION_ARB,
              version_minor,
              CONTEXT_FLAGS_ARB,
              (debugging ? CONTEXT_DEBUG_BIT_ARB : 0),
              None};
            res = glXCreateContextAttribsARB(
              dpy,
              fbc.handle(),
              share_context,
              True,
              static_cast<const int*>(context_attribs));
        }
        ::XSync(dpy, False);
        return res;
    }

public:
    context(
      const x11::display& dpy,
      const fb_config& fbc,
      int version_major,
      int version_minor,
      bool debugging = true,
      bool compatibility = false)
      : x11::display_object<::GLXContext, void(::Display*, ::GLXContext)>(
          dpy,
          make_context(
            dpy,
            fbc,
            version_major,
            version_minor,
            debugging,
            compatibility),
          ::glXDestroyContext,
          "Error creating glX context") {}

    context(
      const x11::display& dpy,
      const fb_config& fbc,
      const context& share_context,
      int version_major,
      int version_minor,
      bool debugging = true,
      bool compatibility = false)
      : x11::display_object<::GLXContext, void(::Display*, ::GLXContext)>(
          dpy,
          make_context(
            dpy,
            fbc,
            version_major,
            version_minor,
            debugging,
            compatibility,
            share_context.handle()),
          ::glXDestroyContext,
          "Error creating sharing glX context") {}

    void make_current(const drawable& surface) const {
        ::glXMakeCurrent(this->display_ref(), surface, this->handle());
    }

    static void release(const x11::display& dpy) {
        ::glXMakeCurrent(dpy, 0, nullptr);
    }

    void swap_buffers(const drawable& surface) const {
        ::glXSwapBuffers(this->display_ref(), surface);
    }
};

} // namespace eagine::glx

#endif
