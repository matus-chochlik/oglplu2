/**
 *  @file oalplus/alut_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_C_API_HPP
#define OALPLUS_ALUT_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OALPLUS_ALUT_STATIC_FUNC
#if OALPLUS_HAS_AL
#define OALPLUS_ALUT_STATIC_FUNC(NAME) &EAGINE_JOIN(::alut, NAME)
#else
#define OALPLUS_ALUT_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_alut_c_api {

    using this_api = basic_alut_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = alut_types::has_api;
    using enum_type = typename alut_types::enum_type;
    using char_type = typename alut_types::char_type;
    using bool_type = typename alut_types::bool_type;
    using int_type = typename alut_types::int_type;
    using uint_type = typename alut_types::uint_type;
    using name_type = typename alut_types::name_type;
    using size_type = typename alut_types::size_type;
    using float_type = typename alut_types::float_type;
    using void_ptr_type = typename alut_types::void_ptr_type;
    using const_void_ptr_type = typename alut_types::const_void_ptr_type;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using alut_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    alut_api_function<enum_type(), OALPLUS_ALUT_STATIC_FUNC(GetError)> GetError;

    alut_api_function<
      const char_type*(enum_type),
      OALPLUS_ALUT_STATIC_FUNC(GetErrorString)>
      GetErrorString;

    alut_api_function<bool_type(int*, char**), OALPLUS_ALUT_STATIC_FUNC(Init)>
      Init;

    alut_api_function<bool_type(int*, char**), OALPLUS_ALUT_STATIC_FUNC(Init)>
      InitWithoutContext;

    alut_api_function<
      name_type(const char*),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferFromFile)>
      CreateBufferFromFile;

    alut_api_function<
      name_type(const_void_ptr_type, size_type),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferFromFileImage)>
      CreateBufferFromFileImage;

    alut_api_function<
      name_type(),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferHelloWorld)>
      CreateBufferHelloWorld;

    alut_api_function<
      name_type(enum_type, float_type, float_type, float_type),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferWaveform)>
      CreateBufferWaveform;

    alut_api_function<bool_type(), OALPLUS_ALUT_STATIC_FUNC(Exit)> Exit;

    constexpr basic_alut_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , GetErrorString("GetErrorString", traits, *this)
      , Init("Init", traits, *this)
      , InitWithoutContext("InitWithoutContext", traits, *this)
      , CreateBufferFromFile("CreateBufferFromFile", traits, *this)
      , CreateBufferFromFileImage("CreateBufferFromFileImage", traits, *this)
      , CreateBufferHelloWorld("CreateBufferHelloWorld", traits, *this)
      , CreateBufferWaveform("CreateBufferWaveform", traits, *this)
      , Exit("Exit", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using alut_c_api = basic_alut_c_api<alut_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_C_API_HPP

