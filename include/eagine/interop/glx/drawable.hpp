/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_GLX_DRAWABLE_HPP
#define EAGINE_INTEROP_GLX_DRAWABLE_HPP

#include "../x11/display.hpp"

#include <GL/glx.h>
#include <stdexcept>

namespace eagine::glx {

using Drawable = x11::BaseDisplayObject<::GLXDrawable>;

} // namespace eagine::glx

#endif
