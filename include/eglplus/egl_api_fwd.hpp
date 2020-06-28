/**
 *  @file eglplus/egl_api_fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_FWD_HPP
#define EGLPLUS_EGL_API_FWD_HPP

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
class egl_api_traits;

template <typename ApiTraits>
class basic_egl_api;

using egl_api = basic_egl_api<egl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_FWD_HPP

