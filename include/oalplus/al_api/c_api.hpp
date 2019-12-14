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

#include "api_traits.hpp"
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
    using const_void_ptr_type = const void*;

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
      void(enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Listeneri),
      has_api>
      Listeneri;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Listener3i),
      has_api>
      Listener3i;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Listeneriv),
      has_api>
      Listeneriv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetListeneriv),
      has_api>
      GetListeneriv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Listenerf),
      has_api>
      Listenerf;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Listener3f),
      has_api>
      Listener3f;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Listenerfv),
      has_api>
      Listenerfv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetListenerfv),
      has_api>
      GetListenerfv;

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
      void(name_type, enum_type, const_void_ptr_type, size_type, size_type),
      OALPLUS_AL_STATIC_FUNC(BufferData),
      has_api>
      BufferData;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Bufferi),
      has_api>
      Bufferi;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Buffer3i),
      has_api>
      Buffer3i;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Bufferiv),
      has_api>
      Bufferiv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetBufferiv),
      has_api>
      GetBufferiv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Bufferf),
      has_api>
      Bufferf;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Buffer3f),
      has_api>
      Buffer3f;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Bufferfv),
      has_api>
      Bufferfv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetBufferfv),
      has_api>
      GetBufferfv;

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

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Sourcei),
      has_api>
      Sourcei;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Source3i),
      has_api>
      Source3i;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Sourceiv),
      has_api>
      Sourceiv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetSourceiv),
      has_api>
      GetSourceiv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Sourcef),
      has_api>
      Sourcef;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Source3f),
      has_api>
      Source3f;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Sourcefv),
      has_api>
      Sourcefv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetSourcefv),
      has_api>
      GetSourcefv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type),
      OALPLUS_AL_STATIC_FUNC(SourcePlay),
      has_api>
      SourcePlay;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type),
      OALPLUS_AL_STATIC_FUNC(SourceStop),
      has_api>
      SourceStop;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type),
      OALPLUS_AL_STATIC_FUNC(SourceRewind),
      has_api>
      SourceRewind;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type),
      OALPLUS_AL_STATIC_FUNC(SourcePause),
      has_api>
      SourcePause;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourcePlayv),
      has_api>
      SourcePlayv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceStopv),
      has_api>
      SourceStopv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceRewindv),
      has_api>
      SourceRewindv;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourcePausev),
      has_api>
      SourcePausev;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceQueueBuffers),
      has_api>
      SourceQueueBuffers;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(name_type, size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceUnqueueBuffers),
      has_api>
      SourceUnqueueBuffers;

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
      , Listeneri("Listeneri", traits, *this)
      , Listener3i("Listener3i", traits, *this)
      , Listeneriv("Listeneriv", traits, *this)
      , GetListeneriv("GetListeneriv", traits, *this)
      , Listenerf("Listenerf", traits, *this)
      , Listener3f("Listener3f", traits, *this)
      , Listenerfv("Listenerfv", traits, *this)
      , GetListenerfv("GetListenerfv", traits, *this)
      , GenBuffers("GenBuffers", traits, *this)
      , DeleteBuffers("DeleteBuffers", traits, *this)
      , IsBuffer("IsBuffer", traits, *this)
      , BufferData("BufferData", traits, *this)
      , Bufferi("Bufferi", traits, *this)
      , Buffer3i("Buffer3i", traits, *this)
      , Bufferiv("Bufferiv", traits, *this)
      , GetBufferiv("GetBufferiv", traits, *this)
      , Bufferf("Bufferf", traits, *this)
      , Buffer3f("Buffer3f", traits, *this)
      , Bufferfv("Bufferfv", traits, *this)
      , GetBufferfv("GetBufferfv", traits, *this)
      , GenSources("GenSources", traits, *this)
      , DeleteSources("DeleteSources", traits, *this)
      , IsSource("IsSource", traits, *this)
      , Sourcei("Sourcei", traits, *this)
      , Source3i("Source3i", traits, *this)
      , Sourceiv("Sourceiv", traits, *this)
      , GetSourceiv("GetSourceiv", traits, *this)
      , Sourcef("Sourcef", traits, *this)
      , Source3f("Source3f", traits, *this)
      , Sourcefv("Sourcefv", traits, *this)
      , GetSourcefv("GetSourcefv", traits, *this)
      , SourcePlay("SourcePlay", traits, *this)
      , SourceStop("SourceStop", traits, *this)
      , SourceRewind("SourceRewind", traits, *this)
      , SourcePause("SourcePause", traits, *this)
      , SourcePlayv("SourcePlayv", traits, *this)
      , SourceStopv("SourceStopv", traits, *this)
      , SourceRewindv("SourceRewindv", traits, *this)
      , SourcePausev("SourcePausev", traits, *this)
      , SourceQueueBuffers("SourceQueueBuffers", traits, *this)
      , SourceUnqueueBuffers("SourceUnqueueBuffers", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using al_c_api = basic_al_c_api<al_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_C_API_HPP
