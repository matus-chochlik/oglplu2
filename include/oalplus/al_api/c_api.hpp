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
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OALPLUS_AL_STATIC_FUNC
#if OALPLUS_HAS_AL
#define OALPLUS_AL_STATIC_FUNC(NAME) &EAGINE_JOIN(::al, NAME)
#else
#define OALPLUS_AL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_al_c_api {
public:
    using this_api = basic_al_c_api;
    using api_traits = ApiTraits;

    static constexpr bool has_api = al_types::has_api;
    using enum_type = typename al_types::enum_type;
    using char_type = typename al_types::char_type;
    using bool_type = typename al_types::bool_type;
    using int_type = typename al_types::int_type;
    using uint_type = typename al_types::uint_type;
    using name_type = typename al_types::name_type;
    using size_type = typename al_types::size_type;
    using float_type = typename al_types::float_type;
    using double_type = typename al_types::double_type;
    using void_ptr_type = typename al_types::void_ptr_type;
    using const_void_ptr_type = typename al_types::const_void_ptr_type;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using al_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    al_api_function<enum_type(), OALPLUS_AL_STATIC_FUNC(GetError)> GetError;

    al_api_function<
      void_ptr_type(const char_type*),
      OALPLUS_AL_STATIC_FUNC(GetProcAddress)>
      GetProcAddress;

    al_api_function<
      enum_type(const char_type*),
      OALPLUS_AL_STATIC_FUNC(GetEnumValue)>
      GetEnumValue;

    al_api_function<void(enum_type), OALPLUS_AL_STATIC_FUNC(Enable)> Enable;

    al_api_function<void(enum_type), OALPLUS_AL_STATIC_FUNC(Disable)> Disable;

    al_api_function<bool_type(enum_type), OALPLUS_AL_STATIC_FUNC(IsEnabled)>
      IsEnabled;

    al_api_function<
      void(enum_type, bool_type*),
      OALPLUS_AL_STATIC_FUNC(GetBooleanv)>
      GetBooleanv;

    al_api_function<
      void(enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetIntegerv)>
      GetIntegerv;

    al_api_function<
      void(enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetFloatv)>
      GetFloatv;

    al_api_function<
      void(enum_type, double_type*),
      OALPLUS_AL_STATIC_FUNC(GetDoublev)>
      GetDoublev;

    al_api_function<bool_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetBoolean)>
      GetBoolean;

    al_api_function<int_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetInteger)>
      GetInteger;

    al_api_function<float_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetFloat)>
      GetFloat;

    al_api_function<double_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetDouble)>
      GetDouble;

    al_api_function<
      const char_type*(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetString)>
      GetString;

    al_api_function<void(enum_type), OALPLUS_AL_STATIC_FUNC(DistanceModel)>
      DistanceModel;

    al_api_function<void(float_type), OALPLUS_AL_STATIC_FUNC(DopplerFactor)>
      DopplerFactor;

    al_api_function<void(float_type), OALPLUS_AL_STATIC_FUNC(SpeedOfSound)>
      SpeedOfSound;

    // Listener
    al_api_function<void(enum_type, int_type), OALPLUS_AL_STATIC_FUNC(Listeneri)>
      Listeneri;

    al_api_function<
      void(enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Listener3i)>
      Listener3i;

    al_api_function<
      void(enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Listeneriv)>
      Listeneriv;

    al_api_function<
      void(enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetListeneriv)>
      GetListeneriv;

    al_api_function<
      void(enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Listenerf)>
      Listenerf;

    al_api_function<
      void(enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Listener3f)>
      Listener3f;

    al_api_function<
      void(enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Listenerfv)>
      Listenerfv;

    al_api_function<
      void(enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetListenerfv)>
      GetListenerfv;

    // Buffers
    al_api_function<
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenBuffers)>
      GenBuffers;

    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(DeleteBuffers)>
      DeleteBuffers;

    al_api_function<bool_type(name_type), OALPLUS_AL_STATIC_FUNC(IsBuffer)>
      IsBuffer;

    al_api_function<
      void(name_type, enum_type, const_void_ptr_type, size_type, size_type),
      OALPLUS_AL_STATIC_FUNC(BufferData)>
      BufferData;

    al_api_function<
      void(name_type, enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Bufferi)>
      Bufferi;

    al_api_function<
      void(name_type, enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Buffer3i)>
      Buffer3i;

    al_api_function<
      void(name_type, enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Bufferiv)>
      Bufferiv;

    al_api_function<
      void(name_type, enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetBufferiv)>
      GetBufferiv;

    al_api_function<
      void(name_type, enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Bufferf)>
      Bufferf;

    al_api_function<
      void(name_type, enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Buffer3f)>
      Buffer3f;

    al_api_function<
      void(name_type, enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Bufferfv)>
      Bufferfv;

    al_api_function<
      void(name_type, enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetBufferfv)>
      GetBufferfv;

    // Sources
    al_api_function<
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenSources)>
      GenSources;

    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(DeleteSources)>
      DeleteSources;

    al_api_function<bool_type(name_type), OALPLUS_AL_STATIC_FUNC(IsSource)>
      IsSource;

    al_api_function<
      void(name_type, enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Sourcei)>
      Sourcei;

    al_api_function<
      void(name_type, enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Source3i)>
      Source3i;

    al_api_function<
      void(name_type, enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Sourceiv)>
      Sourceiv;

    al_api_function<
      void(name_type, enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetSourceiv)>
      GetSourceiv;

    al_api_function<
      void(name_type, enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Sourcef)>
      Sourcef;

    al_api_function<
      void(name_type, enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Source3f)>
      Source3f;

    al_api_function<
      void(name_type, enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Sourcefv)>
      Sourcefv;

    al_api_function<
      void(name_type, enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetSourcefv)>
      GetSourcefv;

    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourcePlay)>
      SourcePlay;

    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourceStop)>
      SourceStop;

    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourceRewind)>
      SourceRewind;

    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourcePause)>
      SourcePause;

    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourcePlayv)>
      SourcePlayv;

    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceStopv)>
      SourceStopv;

    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceRewindv)>
      SourceRewindv;

    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourcePausev)>
      SourcePausev;

    al_api_function<
      void(name_type, size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceQueueBuffers)>
      SourceQueueBuffers;

    al_api_function<
      void(name_type, size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceUnqueueBuffers)>
      SourceUnqueueBuffers;

    // Effects
    al_api_function<void(size_type, name_type*), nullptr> GenEffects;

    al_api_function<void(size_type, const name_type*), nullptr> DeleteEffects;

    al_api_function<bool_type(name_type), nullptr> IsEffect;

    al_api_function<void(name_type, enum_type, int_type), nullptr> Effecti;

    al_api_function<void(name_type, enum_type, const int_type*), nullptr>
      Effectiv;

    al_api_function<void(name_type, enum_type, float_type), nullptr> Effectf;

    al_api_function<void(name_type, enum_type, const float_type*), nullptr>
      Effectfv;

    al_api_function<void(name_type, enum_type, int_type), nullptr> GetEffecti;

    al_api_function<void(name_type, enum_type, int_type*), nullptr> GetEffectiv;

    al_api_function<void(name_type, enum_type, float_type), nullptr> GetEffectf;

    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetEffectfv;

    // Filters
    al_api_function<void(size_type, name_type*), nullptr> GenFilters;

    al_api_function<void(size_type, const name_type*), nullptr> DeleteFilters;

    al_api_function<bool_type(name_type), nullptr> IsFilter;

    al_api_function<void(name_type, enum_type, int_type), nullptr> Filteri;

    al_api_function<void(name_type, enum_type, const int_type*), nullptr>
      Filteriv;

    al_api_function<void(name_type, enum_type, float_type), nullptr> Filterf;

    al_api_function<void(name_type, enum_type, const float_type*), nullptr>
      Filterfv;

    al_api_function<void(name_type, enum_type, int_type), nullptr> GetFilteri;

    al_api_function<void(name_type, enum_type, int_type*), nullptr> GetFilteriv;

    al_api_function<void(name_type, enum_type, float_type), nullptr> GetFilterf;

    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetFilterfv;

    // AuxiliaryEffectSlots
    al_api_function<void(size_type, name_type*), nullptr>
      GenAuxiliaryEffectSlots;

    al_api_function<void(size_type, const name_type*), nullptr>
      DeleteAuxiliaryEffectSlots;

    al_api_function<bool_type(name_type), nullptr> IsAuxiliaryEffectSlot;

    al_api_function<void(name_type, enum_type, int_type), nullptr>
      AuxiliaryEffectSloti;

    al_api_function<void(name_type, enum_type, const int_type*), nullptr>
      AuxiliaryEffectSlotiv;

    al_api_function<void(name_type, enum_type, float_type), nullptr>
      AuxiliaryEffectSlotf;

    al_api_function<void(name_type, enum_type, const float_type*), nullptr>
      AuxiliaryEffectSlotfv;

    al_api_function<void(name_type, enum_type, int_type), nullptr>
      GetAuxiliaryEffectSloti;

    al_api_function<void(name_type, enum_type, int_type*), nullptr>
      GetAuxiliaryEffectSlotiv;

    al_api_function<void(name_type, enum_type, float_type), nullptr>
      GetAuxiliaryEffectSlotf;

    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetAuxiliaryEffectSlotfv;

    basic_al_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
using al_c_api = basic_al_c_api<al_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_C_API_HPP
