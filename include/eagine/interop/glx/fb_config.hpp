/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_GLX_FB_CONFIG_HPP
#define EAGINE_INTEROP_GLX_FB_CONFIG_HPP

#include <GL/glx.h>
#include <stdexcept>

namespace eagine::glx {

class fb_configs;

class fb_config {
private:
    ::GLXFBConfig _handle;

    fb_config(::GLXFBConfig handle)
      : _handle(handle) {}

    friend class fb_configs;

public:
    auto handle() const -> ::GLXFBConfig {
        return _handle;
    }

    operator ::GLXFBConfig() const {
        return handle();
    }
};

} // namespace eagine::glx

#endif
