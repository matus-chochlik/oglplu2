/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_COMMON_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_COMMON_1107121519_HPP

#include <oglplus/config/site.hpp>

namespace eagine {
namespace oglp {

struct offscreen_context_params {
    int argc;
    char** argv;
    const char* title{""};
    int version_major{OGLPLUS_GL_VERSION_MAJOR};
    int version_minor{OGLPLUS_GL_VERSION_MINOR};
    int width{64};
    int height{64};
    bool debugging{false};
    bool compatibility{false};

    static char** fake_argv() noexcept {
        static char name[64] = {'<', 'N', '/', 'A', '>', '\0'};
        static char* av[2] = {name, nullptr};
        return av;
    }

    offscreen_context_params()
      : argc(1)
      , argv(fake_argv()) {
    }
};

} // namespace oglp
} // namespace eagine

#endif
