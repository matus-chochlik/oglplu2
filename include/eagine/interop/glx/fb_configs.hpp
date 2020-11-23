/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_GLX_FB_CONFIGS_HPP
#define EAGINE_INTEROP_GLX_FB_CONFIGS_HPP

#include "../x11/display.hpp"
#include "../x11/visual_info.hpp"
#include "fb_config.hpp"
#include <eagine/assert.hpp>

#include <GL/glx.h>
#include <stdexcept>
#include <utility>

namespace eagine::glx {

class FBConfigs {
private:
    int _count{0};
    GLXFBConfig* _handle{nullptr};

public:
    FBConfigs(const x11::Display& display, const int* visual_attribs)
      : _handle(::glXChooseFBConfig(
          display,
          DefaultScreen(display.Get()),
          visual_attribs,
          &_count)) {
        if(!_handle || (_count <= 0)) {
            throw std::runtime_error(
              "Failed to get matching framebuffer configs");
        }
    }

    FBConfigs(FBConfigs&& temp) noexcept
      : _count(std::exchange(temp._count, 0))
      , _handle(std::exchange(temp._handle, nullptr)) {}

    FBConfigs(const FBConfigs&) = delete;
    auto operator=(FBConfigs&&) = delete;
    auto operator=(const FBConfigs&) = delete;

    ~FBConfigs() {
        if(_handle) {
            ::XFree(_handle);
        }
    }

    auto FindBest(const x11::Display& display) const -> FBConfig {
        int best = -1, best_num = -1;
        EAGINE_ASSERT(_count > 0);
        for(int i = 0; i != _count; ++i) {
            int sample_buf, samples;

            ::glXGetFBConfigAttrib(
              display, _handle[i], GLX_SAMPLE_BUFFERS, &sample_buf);
            ::glXGetFBConfigAttrib(display, _handle[i], GLX_SAMPLES, &samples);
            if((best < 0) || (sample_buf && (samples > best_num))) {
                best = i;
                best_num = samples;
            }
        }
        EAGINE_ASSERT(best >= 0);
        EAGINE_ASSERT(best < _count);
        return FBConfig(_handle[best]);
    }
};

} // namespace eagine::glx

#endif
