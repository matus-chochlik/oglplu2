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

#include "c_api_traits.hpp"
#include <eagine/c_api_wrap.hpp>
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
      device_type*(const char_type*),
      OALPLUS_ALC_STATIC_FUNC(OpenDevice),
      has_api>
      OpenDevice;

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
      const char_type*(device_type*, enum_type),
      OALPLUS_ALC_STATIC_FUNC(GetString),
      has_api>
      GetString;

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
      OALPLUS_ALC_STATIC_FUNC(DestroyContext),
      has_api>
      DestroyContext;

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

    constexpr basic_alc_c_api(api_traits& traits)
      : GetError("GetError", traits)
      , OpenDevice("OpenDevice", traits)
      , CloseDevice("CloseDevice", traits)
      , GetString("GetString", traits)
      , CreateContext("CreateContext", traits)
      , DestroyContext("DestroyContext", traits)
      , GetCurrentContext("GetCurrentContext", traits)
      , GetContextsDevice("GetContextsDevice", traits) {
    }
};
//------------------------------------------------------------------------------
using alc_c_api = basic_alc_c_api<alc_c_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_C_API_HPP

