/**
 *  @file eagine/application/opengl_glfw3.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_OPENGL_GLFW3_HPP
#define EAGINE_APPLICATION_OPENGL_GLFW3_HPP

#include "../main_ctx_fwd.hpp"
#include "interface.hpp"
#include <memory>

namespace eagine::application {

auto make_glfw3_opengl_provider(main_ctx_parent)
  -> std::shared_ptr<hmi_provider>;

} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/opengl_glfw3.inl>
#endif

#endif
