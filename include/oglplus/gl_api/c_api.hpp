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
#if OGLPLUS_HAS_GL
#if defined(__GLEW_H__)
#define OGLPLUS_GL_STATIC_FUNC(NAME) nullptr
#else
#define OGLPLUS_GL_STATIC_FUNC(NAME) &EAGINE_JOIN(::gl, NAME)
#endif
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

    using void_ptr_type = typename gl_types::void_ptr_type;
    using sizei_type = typename gl_types::sizei_type;
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using byte_type = typename gl_types::byte_type;
    using ubyte_type = typename gl_types::ubyte_type;
    using int_type = typename gl_types::int_type;
    using uint_type = typename gl_types::uint_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;

    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using gl_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      gl_types::has_api,
      gl_types::has_static_api>;

    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetError)> GetError;

    gl_api_function<
      void(double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRange)>
      DepthRange;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangef)>
      DepthRangef;

    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Viewport)>
      Viewport;

    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ClearColor)>
      ClearColor;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(ClearDepthf)>
      ClearDepthf;

    gl_api_function<void(double_type), OGLPLUS_GL_STATIC_FUNC(ClearDepth)>
      ClearDepth;

    gl_api_function<void(int_type), OGLPLUS_GL_STATIC_FUNC(ClearStencil)>
      ClearStencil;

    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(Clear)> Clear;

    gl_api_function<
      const ubyte_type*(enum_type),
      OGLPLUS_GL_STATIC_FUNC(GetString)>
      GetString;

    gl_api_function<
      const ubyte_type*(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(GetStringi)>
      GetStringi;

    constexpr basic_gl_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , DepthRange("DepthRange", traits, *this)
      , DepthRangef("DepthRangef", traits, *this)
      , Viewport("Viewport", traits, *this)
      , ClearColor("ClearColor", traits, *this)
      , ClearDepthf("ClearDepthf", traits, *this)
      , ClearDepth("ClearDepth", traits, *this)
      , ClearStencil("ClearStencil", traits, *this)
      , Clear("Clear", traits, *this)
      , GetString("GetString", traits, *this)
      , GetStringi("GetStringi", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using gl_c_api = basic_gl_c_api<gl_api_traits>;
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_C_API_HPP

