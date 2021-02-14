/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEROP_GLX_VERSION_HPP
#define EAGINE_INTEROP_GLX_VERSION_HPP

#include "../x11/display.hpp"

#include <GL/glx.h>
#include <stdexcept>

namespace eagine::glx {

class version {
private:
    int _major{0};
    int _minor{0};

public:
    version(const x11::display& dpy) {
        if(!::glXQueryVersion(dpy, &_major, &_minor)) {
            throw std::runtime_error("Error querying GLX version");
        }
    }

    void assert_at_least(int major, int minor) const {
        if((_major < major) || ((_major == major) && (_minor < minor))) {
            throw std::runtime_error("Invalid GLX version");
        }
    }

    auto major() const noexcept {
        return _major;
    }

    auto minor() const noexcept {
        return _minor;
    }
};

} // namespace eagine::glx

#endif
