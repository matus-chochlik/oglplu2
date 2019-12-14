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
#include <eagine/preprocessor.hpp>

#ifndef OALPLUS_ALC_STATIC_FUNC
#define OALPLUS_ALC_STATIC_FUNC(NAME) &EAGINE_JOIN(::alc, NAME)
#endif

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_alc_c_api {

    using this_api = basic_alc_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = true;
    using device_type = ALCdevice;
    using context_type = ALCcontext;
    using enum_type = ALCenum;
    using char_type = ALCchar;
    using bool_type = ALCboolean;
    using int_type = ALCint;
    using uint_type = ALCuint;
    using size_type = ALCsizei;
    using void_ptr_type = void*;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(device_type*),
      OALPLUS_ALC_STATIC_FUNC(GetError),
      has_api>
      GetError;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void_ptr_type(device_type*, const char_type*),
      OALPLUS_ALC_STATIC_FUNC(GetProcAddress),
      has_api>
      GetProcAddress;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(device_type*, const char_type*),
      OALPLUS_ALC_STATIC_FUNC(GetEnumValue),
      has_api>
      GetEnumValue;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      device_type*(const char_type*),
      OALPLUS_ALC_STATIC_FUNC(OpenDevice),
      has_api>
      OpenDevice;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      device_type*(
        const char_type*, uint_type freq, enum_type format, size_type bufsize),
      OALPLUS_ALC_STATIC_FUNC(CaptureOpenDevice),
      has_api>
      CaptureOpenDevice;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(device_type*),
      OALPLUS_ALC_STATIC_FUNC(CloseDevice),
      has_api>
      CloseDevice;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(device_type*),
      OALPLUS_ALC_STATIC_FUNC(CaptureCloseDevice),
      has_api>
      CaptureCloseDevice;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      const char_type*(device_type*, enum_type),
      OALPLUS_ALC_STATIC_FUNC(GetString),
      has_api>
      GetString;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(device_type*, enum_type, size_type, int_type*),
      OALPLUS_ALC_STATIC_FUNC(GetIntegerv),
      has_api>
      GetIntegerv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(device_type*, const char_type*),
      OALPLUS_ALC_STATIC_FUNC(IsExtensionPresent),
      has_api>
      IsExtensionPresent;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      context_type*(device_type*, const int_type*),
      OALPLUS_ALC_STATIC_FUNC(CreateContext),
      has_api>
      CreateContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(context_type*),
      OALPLUS_ALC_STATIC_FUNC(ProcessContext),
      has_api>
      ProcessContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(context_type*),
      OALPLUS_ALC_STATIC_FUNC(SuspendContext),
      has_api>
      SuspendContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(context_type*),
      OALPLUS_ALC_STATIC_FUNC(DestroyContext),
      has_api>
      DestroyContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(context_type*),
      OALPLUS_ALC_STATIC_FUNC(MakeContextCurrent),
      has_api>
      MakeContextCurrent;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      context_type*(),
      OALPLUS_ALC_STATIC_FUNC(GetCurrentContext),
      has_api>
      GetCurrentContext;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      device_type*(context_type*),
      OALPLUS_ALC_STATIC_FUNC(GetContextsDevice),
      has_api>
      GetContextsDevice;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(device_type*),
      OALPLUS_ALC_STATIC_FUNC(CaptureStart),
      has_api>
      CaptureStart;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(device_type*),
      OALPLUS_ALC_STATIC_FUNC(CaptureStop),
      has_api>
      CaptureStop;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(device_type*, void_ptr_type, size_type),
      OALPLUS_ALC_STATIC_FUNC(CaptureSamples),
      has_api>
      CaptureSamples;

    constexpr basic_alc_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , GetProcAddress("GetProcAddress", traits, *this)
      , GetEnumValue("GetEnumValue", traits, *this)
      , OpenDevice("OpenDevice", traits, *this)
      , CaptureOpenDevice("CaptureOpenDevice", traits, *this)
      , CloseDevice("CloseDevice", traits, *this)
      , CaptureCloseDevice("CaptureCloseDevice", traits, *this)
      , GetString("GetString", traits, *this)
      , GetIntegerv("GetIntegerv", traits, *this)
      , IsExtensionPresent("IsExtensionPresent", traits, *this)
      , CreateContext("CreateContext", traits, *this)
      , ProcessContext("ProcessContext", traits, *this)
      , SuspendContext("SuspendContext", traits, *this)
      , DestroyContext("DestroyContext", traits, *this)
      , MakeContextCurrent("MakeContextCurrent", traits, *this)
      , GetCurrentContext("GetCurrentContext", traits, *this)
      , GetContextsDevice("GetContextsDevice", traits, *this)
      , CaptureStart("CaptureStart", traits, *this)
      , CaptureStop("CaptureStop", traits, *this)
      , CaptureSamples("CaptureSamples", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using alc_c_api = basic_alc_c_api<alc_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_C_API_HPP
