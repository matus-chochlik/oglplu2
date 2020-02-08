/**
 *  @file eglplus/egl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_C_API_HPP
#define EGLPLUS_EGL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef EGLPLUS_EGL_STATIC_FUNC
#if EGLPLUS_HAS_AL
#define EGLPLUS_EGL_STATIC_FUNC(NAME) &EAGINE_JOIN(::al, NAME)
#else
#define EGLPLUS_EGL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_egl_c_api {

    using this_api = basic_egl_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = egl_types::has_api;
    using enum_type = typename egl_types::enum_type;
    using bool_type = typename egl_types::bool_type;
    using int_type = typename egl_types::int_type;
    using display_type = typename egl_types::display_type;
    using surface_type = typename egl_types::surface_type;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(),
      EGLPLUS_EGL_STATIC_FUNC(GetError),
      has_api>
      GetError;

    static constexpr bool success(enum_type ec) noexcept {
#ifdef EGL_SUCCESS
        return ec == EGL_SUCCESS;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(display_type, surface_type),
      EGLPLUS_EGL_STATIC_FUNC(SwapBuffers),
      has_api>
      SwapBuffers;

    constexpr basic_egl_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , SwapBuffers("SwapBuffers", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using egl_c_api = basic_egl_c_api<egl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_C_API_HPP

