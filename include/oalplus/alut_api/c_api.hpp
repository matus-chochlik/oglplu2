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

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(),
      OALPLUS_ALUT_STATIC_FUNC(GetError),
      has_api>
      GetError;

    static constexpr bool success(enum_type ec) noexcept {
#ifdef ALUT_ERROR_NO_ERROR
        return ec == ALUT_ERROR_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      const char_type*(enum_type),
      OALPLUS_ALUT_STATIC_FUNC(GetErrorString),
      has_api>
      GetErrorString;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(int*, char**),
      OALPLUS_ALUT_STATIC_FUNC(Init),
      has_api>
      Init;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(int*, char**),
      OALPLUS_ALUT_STATIC_FUNC(Init),
      has_api>
      InitWithoutContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      name_type(const char*),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferFromFile),
      has_api>
      CreateBufferFromFile;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      name_type(const_void_ptr_type, size_type),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferFromFileImage),
      has_api>
      CreateBufferFromFileImage;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      name_type(),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferHelloWorld),
      has_api>
      CreateBufferHelloWorld;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      name_type(enum_type, float_type, float_type, float_type),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferWaveform),
      has_api>
      CreateBufferWaveform;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(),
      OALPLUS_ALUT_STATIC_FUNC(Exit),
      has_api>
      Exit;

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

