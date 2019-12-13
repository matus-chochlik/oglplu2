/**
 *  @file oalplus/al_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_C_API_HPP
#define OALPLUS_AL_API_C_API_HPP

#include "c_api_traits.hpp"
#include <eagine/preprocessor.hpp>

#ifndef OALPLUS_AL_STATIC_FUNC
#define OALPLUS_AL_STATIC_FUNC(NAME) &EAGINE_JOIN(::al, NAME)
#endif

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_al_c_api {

    using this_api = basic_al_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = true;
    using enum_type = ALenum;
    using char_type = ALchar;
    using bool_type = ALboolean;
    using int_type = ALint;
    using uint_type = ALuint;
    using name_type = ALuint;
    using size_type = ALsizei;
    using float_type = ALfloat;
    using double_type = ALdouble;
    using void_ptr_type = void*;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      enum_type(),
      OALPLUS_AL_STATIC_FUNC(GetError),
      has_api>
      GetError;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type),
      OALPLUS_AL_STATIC_FUNC(Enable),
      has_api>
      Enable;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type),
      OALPLUS_AL_STATIC_FUNC(Disable),
      has_api>
      Disable;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(enum_type),
      OALPLUS_AL_STATIC_FUNC(IsEnabled),
      has_api>
      IsEnabled;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, bool_type*),
      OALPLUS_AL_STATIC_FUNC(GetBooleanv),
      has_api>
      GetBooleanv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetIntegerv),
      has_api>
      GetIntegerv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetFloatv),
      has_api>
      GetFloatv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, double_type*),
      OALPLUS_AL_STATIC_FUNC(GetDoublev),
      has_api>
      GetDoublev;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetBoolean),
      has_api>
      GetBoolean;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      int_type(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetInteger),
      has_api>
      GetInteger;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      float_type(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetFloat),
      has_api>
      GetFloat;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      double_type(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetDouble),
      has_api>
      GetDouble;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      const char_type*(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetString),
      has_api>
      GetString;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type),
      OALPLUS_AL_STATIC_FUNC(DistanceModel),
      has_api>
      DistanceModel;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(float_type),
      OALPLUS_AL_STATIC_FUNC(DopplerFactor),
      has_api>
      DopplerFactor;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(float_type),
      OALPLUS_AL_STATIC_FUNC(SpeedOfSound),
      has_api>
      SpeedOfSound;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenBuffers),
      has_api>
      GenBuffers;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(DeleteBuffers),
      has_api>
      DeleteBuffers;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(name_type),
      OALPLUS_AL_STATIC_FUNC(IsBuffer),
      has_api>
      IsBuffer;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenSources),
      has_api>
      GenSources;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(DeleteSources),
      has_api>
      DeleteSources;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      bool_type(name_type),
      OALPLUS_AL_STATIC_FUNC(IsSource),
      has_api>
      IsSource;

    constexpr basic_al_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , Enable("Enable", traits, *this)
      , Disable("Disable", traits, *this)
      , IsEnabled("IsEnabled", traits, *this)
      , GetBooleanv("GetBooleanv", traits, *this)
      , GetIntegerv("GetIntegerv", traits, *this)
      , GetFloatv("GetFloatv", traits, *this)
      , GetDoublev("GetDoublev", traits, *this)
      , GetBoolean("GetBoolean", traits, *this)
      , GetInteger("GetInteger", traits, *this)
      , GetFloat("GetFloat", traits, *this)
      , GetDouble("GetDouble", traits, *this)
      , GetString("GetString", traits, *this)
      , DistanceModel("DistanceModel", traits, *this)
      , DopplerFactor("DopplerFactor", traits, *this)
      , SpeedOfSound("SpeedOfSound", traits, *this)
      , GenBuffers("GenBuffers", traits, *this)
      , DeleteBuffers("DeleteBuffers", traits, *this)
      , IsBuffer("IsBuffer", traits, *this)
      , GenSources("GenSources", traits, *this)
      , DeleteSources("DeleteSources", traits, *this)
      , IsSource("IsSource", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using al_c_api = basic_al_c_api<al_c_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_C_API_HPP

