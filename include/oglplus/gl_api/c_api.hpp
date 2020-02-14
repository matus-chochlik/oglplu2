/**
 *  @file oglplus/gl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_C_API_HPP
#define OGLPLUS_GL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OGLPLUS_GL_STATIC_FUNC
#if OGLPLUS_HAS_EGL
#define OGLPLUS_GL_STATIC_FUNC(NAME) &EAGINE_JOIN(::egl, NAME)
#else
#define OGLPLUS_GL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_gl_c_api {

    using this_api = basic_gl_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = gl_types::has_api;
    using void_ptr_type = typename gl_types::void_ptr_type;
    using enum_type = typename gl_types::enum_type;
    using char_type = typename gl_types::char_type;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(),
      OGLPLUS_GL_STATIC_FUNC(GetError),
      has_api>
      GetError;

    static constexpr bool succeeded(enum_type ec) noexcept {
#ifdef GL_NO_ERROR
        return ec == GL_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }

    constexpr basic_gl_c_api(api_traits& traits)
      : GetError("GetError", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using gl_c_api = basic_gl_c_api<gl_api_traits>;
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_C_API_HPP

