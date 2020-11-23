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

class FBConfigs;

class FBConfig {
private:
    ::GLXFBConfig _handle;

    FBConfig(::GLXFBConfig handle)
      : _handle(handle) {}

    friend class FBConfigs;

public:
    auto Handle() const -> ::GLXFBConfig {
        return _handle;
    }

    operator ::GLXFBConfig() const {
        return Handle();
    }
};

} // namespace eagine::glx

#endif
