/**
 *  @file oalplus/alc_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_C_API_HPP
#define OALPLUS_ALC_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OALPLUS_ALC_STATIC_FUNC
#if OALPLUS_HAS_ALC
#define OALPLUS_ALC_STATIC_FUNC(NAME) &EAGINE_JOIN(::alc, NAME)
#else
#define OALPLUS_ALC_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_alc_c_api {

    using this_api = basic_alc_c_api;
    using api_traits = ApiTraits;

    static constexpr bool has_api = alc_types::has_api;
    using device_type = typename alc_types::device_type;
    using context_type = typename alc_types::context_type;
    using enum_type = typename alc_types::enum_type;
    using char_type = typename alc_types::char_type;
    using bool_type = typename alc_types::bool_type;
    using int_type = typename alc_types::int_type;
    using uint_type = typename alc_types::uint_type;
    using size_type = typename alc_types::size_type;
    using void_ptr_type = typename alc_types::void_ptr_type;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using alc_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    alc_api_function<enum_type(device_type*), OALPLUS_ALC_STATIC_FUNC(GetError)>
      GetError;

    alc_api_function<
      void_ptr_type(device_type*, const char_type*),
      OALPLUS_ALC_STATIC_FUNC(GetProcAddress)>
      GetProcAddress;

    alc_api_function<
      enum_type(device_type*, const char_type*),
      OALPLUS_ALC_STATIC_FUNC(GetEnumValue)>
      GetEnumValue;

    alc_api_function<
      device_type*(const char_type*),
      OALPLUS_ALC_STATIC_FUNC(OpenDevice)>
      OpenDevice;

    alc_api_function<
      device_type*(
        const char_type*,
        uint_type freq,
        enum_type format,
        size_type bufsize),
      OALPLUS_ALC_STATIC_FUNC(CaptureOpenDevice)>
      CaptureOpenDevice;

    alc_api_function<
      bool_type(device_type*),
      OALPLUS_ALC_STATIC_FUNC(CloseDevice)>
      CloseDevice;

    alc_api_function<
      bool_type(device_type*),
      OALPLUS_ALC_STATIC_FUNC(CaptureCloseDevice)>
      CaptureCloseDevice;

    alc_api_function<
      const char_type*(device_type*, enum_type),
      OALPLUS_ALC_STATIC_FUNC(GetString)>
      GetString;

    alc_api_function<
      void(device_type*, enum_type, size_type, int_type*),
      OALPLUS_ALC_STATIC_FUNC(GetIntegerv)>
      GetIntegerv;

    alc_api_function<
      bool_type(device_type*, const char_type*),
      OALPLUS_ALC_STATIC_FUNC(IsExtensionPresent)>
      IsExtensionPresent;

    alc_api_function<
      context_type*(device_type*, const int_type*),
      OALPLUS_ALC_STATIC_FUNC(CreateContext)>
      CreateContext;

    alc_api_function<void(context_type*), OALPLUS_ALC_STATIC_FUNC(ProcessContext)>
      ProcessContext;

    alc_api_function<void(context_type*), OALPLUS_ALC_STATIC_FUNC(SuspendContext)>
      SuspendContext;

    alc_api_function<void(context_type*), OALPLUS_ALC_STATIC_FUNC(DestroyContext)>
      DestroyContext;

    alc_api_function<
      bool_type(context_type*),
      OALPLUS_ALC_STATIC_FUNC(MakeContextCurrent)>
      MakeContextCurrent;

    alc_api_function<context_type*(), OALPLUS_ALC_STATIC_FUNC(GetCurrentContext)>
      GetCurrentContext;

    alc_api_function<
      device_type*(context_type*),
      OALPLUS_ALC_STATIC_FUNC(GetContextsDevice)>
      GetContextsDevice;

    alc_api_function<void(device_type*), OALPLUS_ALC_STATIC_FUNC(CaptureStart)>
      CaptureStart;

    alc_api_function<void(device_type*), OALPLUS_ALC_STATIC_FUNC(CaptureStop)>
      CaptureStop;

    alc_api_function<
      void(device_type*, void_ptr_type, size_type),
      OALPLUS_ALC_STATIC_FUNC(CaptureSamples)>
      CaptureSamples;

    basic_alc_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
using alc_c_api = basic_alc_c_api<alc_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_C_API_HPP
