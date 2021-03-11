/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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
/// @brief Class wrapping the C-functions from the AL API.
/// @ingroup al_api_wrap
/// @see basic_al_constants
/// @see basic_al_operations
template <typename ApiTraits>
class basic_al_c_api {
public:
    using this_api = basic_al_c_api;

    /// @brief Alias for the API traits policy type passed as template argument.
    using api_traits = ApiTraits;

    static constexpr bool has_api = al_types::has_api;

    /// @brief Alias for enumeration type.
    using enum_type = typename al_types::enum_type;

    /// @brief Alias for string characted type.
    using char_type = typename al_types::char_type;

    /// @brief Alias for boolean type.
    using bool_type = typename al_types::bool_type;

    /// @brief Alias for signed interger type.
    using int_type = typename al_types::int_type;

    /// @brief Alias for unsigned integer type.
    using uint_type = typename al_types::uint_type;

    /// @brief Alias for object handle type.
    using name_type = typename al_types::name_type;

    /// @brief Alias for integer type used to store sizes and counts.
    using size_type = typename al_types::size_type;

    /// @brief Alias for floating-point type.
    using float_type = typename al_types::float_type;

    /// @brief Alias for double-precision floating-point type.
    using double_type = typename al_types::double_type;

    /// @brief Untyped non-const pointer type.
    using void_ptr_type = typename al_types::void_ptr_type;

    /// @brief Untyped const pointer type.
    using const_void_ptr_type = typename al_types::const_void_ptr_type;

#ifdef __GNUC__
    EAGINE_DIAG_PUSH()
    EAGINE_DIAG_OFF(address)
#endif

    /// @brief Alias for AL C-API function wrapper template.
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
    EAGINE_DIAG_POP()
#endif

    /// @var GetError
    /// @alfuncwrap{GetError}
    al_api_function<enum_type(), OALPLUS_AL_STATIC_FUNC(GetError)> GetError;

    /// @var GetProcAddress
    /// @alfuncwrap{GetProcAddress}
    al_api_function<
      void_ptr_type(const char_type*),
      OALPLUS_AL_STATIC_FUNC(GetProcAddress)>
      GetProcAddress;

    /// @var GetEnumValue
    /// @alfuncwrap{GetEnumValue}
    al_api_function<
      enum_type(const char_type*),
      OALPLUS_AL_STATIC_FUNC(GetEnumValue)>
      GetEnumValue;

    /// @var Enable
    /// @alfuncwrap{Enable}
    al_api_function<void(enum_type), OALPLUS_AL_STATIC_FUNC(Enable)> Enable;

    /// @var Disable
    /// @alfuncwrap{Disable}
    al_api_function<void(enum_type), OALPLUS_AL_STATIC_FUNC(Disable)> Disable;

    /// @var IsEnabled
    /// @alfuncwrap{IsEnabled}
    al_api_function<bool_type(enum_type), OALPLUS_AL_STATIC_FUNC(IsEnabled)>
      IsEnabled;

    /// @var GetBooleanv
    /// @alfuncwrap{GetBooleanv}
    al_api_function<
      void(enum_type, bool_type*),
      OALPLUS_AL_STATIC_FUNC(GetBooleanv)>
      GetBooleanv;

    /// @var GetIntegerv
    /// @alfuncwrap{GetIntegerv}
    al_api_function<
      void(enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetIntegerv)>
      GetIntegerv;

    /// @var GetFloatv
    /// @alfuncwrap{GetFloatv}
    al_api_function<
      void(enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetFloatv)>
      GetFloatv;

    /// @var GetDoublev
    /// @alfuncwrap{GetDoublev}
    al_api_function<
      void(enum_type, double_type*),
      OALPLUS_AL_STATIC_FUNC(GetDoublev)>
      GetDoublev;

    /// @var GetBoolean
    /// @alfuncwrap{GetBoolean}
    al_api_function<bool_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetBoolean)>
      GetBoolean;

    /// @var GetInteger
    /// @alfuncwrap{GetInteger}
    al_api_function<int_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetInteger)>
      GetInteger;

    /// @var GetInteger
    /// @alfuncwrap{GetInteger}
    al_api_function<float_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetFloat)>
      GetFloat;

    /// @var GetFloat
    /// @alfuncwrap{GetFloat}
    al_api_function<double_type(enum_type), OALPLUS_AL_STATIC_FUNC(GetDouble)>
      GetDouble;

    /// @var GetString
    /// @alfuncwrap{GetString}
    al_api_function<
      const char_type*(enum_type),
      OALPLUS_AL_STATIC_FUNC(GetString)>
      GetString;

    /// @var DistanceModel
    /// @alfuncwrap{DistanceModel}
    al_api_function<void(enum_type), OALPLUS_AL_STATIC_FUNC(DistanceModel)>
      DistanceModel;

    /// @var DopplerFactor
    /// @alfuncwrap{DopplerFactor}
    al_api_function<void(float_type), OALPLUS_AL_STATIC_FUNC(DopplerFactor)>
      DopplerFactor;

    /// @var SpeedOfSound
    /// @alfuncwrap{SpeedOfSound}
    al_api_function<void(float_type), OALPLUS_AL_STATIC_FUNC(SpeedOfSound)>
      SpeedOfSound;

    /// @var Listeneri
    /// @alfuncwrap{Listeneri}
    al_api_function<void(enum_type, int_type), OALPLUS_AL_STATIC_FUNC(Listeneri)>
      Listeneri;

    /// @var Listener3i
    /// @alfuncwrap{Listener3i}
    al_api_function<
      void(enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Listener3i)>
      Listener3i;

    /// @var Listeneriv
    /// @alfuncwrap{Listeneriv}
    al_api_function<
      void(enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Listeneriv)>
      Listeneriv;

    /// @var GetListeneriv
    /// @alfuncwrap{GetListeneriv}
    al_api_function<
      void(enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetListeneriv)>
      GetListeneriv;

    /// @var Listenerf
    /// @alfuncwrap{Listenerf}
    al_api_function<
      void(enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Listenerf)>
      Listenerf;

    /// @var Listener3f
    /// @alfuncwrap{Listener3f}
    al_api_function<
      void(enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Listener3f)>
      Listener3f;

    /// @var Listenerfv
    /// @alfuncwrap{Listenerfv}
    al_api_function<
      void(enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Listenerfv)>
      Listenerfv;

    /// @var GetListenerfv
    /// @alfuncwrap{GetListenerfv}
    al_api_function<
      void(enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetListenerfv)>
      GetListenerfv;

    /// @var GenBuffers
    /// @alfuncwrap{GenBuffers}
    al_api_function<
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenBuffers)>
      GenBuffers;

    /// @var DeleteBuffers
    /// @alfuncwrap{DeleteBuffers}
    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(DeleteBuffers)>
      DeleteBuffers;

    /// @var IsBuffer
    /// @alfuncwrap{IsBuffer}
    al_api_function<bool_type(name_type), OALPLUS_AL_STATIC_FUNC(IsBuffer)>
      IsBuffer;

    /// @var BufferData
    /// @alfuncwrap{BufferData}
    al_api_function<
      void(name_type, enum_type, const_void_ptr_type, size_type, size_type),
      OALPLUS_AL_STATIC_FUNC(BufferData)>
      BufferData;

    /// @var Bufferi
    /// @alfuncwrap{Bufferi}
    al_api_function<
      void(name_type, enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Bufferi)>
      Bufferi;

    /// @var Buffer3i
    /// @alfuncwrap{Buffer3i}
    al_api_function<
      void(name_type, enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Buffer3i)>
      Buffer3i;

    /// @var Bufferiv
    /// @alfuncwrap{Bufferiv}
    al_api_function<
      void(name_type, enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Bufferiv)>
      Bufferiv;

    /// @var GetBufferiv
    /// @alfuncwrap{GetBufferiv}
    al_api_function<
      void(name_type, enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetBufferiv)>
      GetBufferiv;

    /// @var Bufferf
    /// @alfuncwrap{Bufferf}
    al_api_function<
      void(name_type, enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Bufferf)>
      Bufferf;

    /// @var Buffer3f
    /// @alfuncwrap{Buffer3f}
    al_api_function<
      void(name_type, enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Buffer3f)>
      Buffer3f;

    /// @var Bufferfv
    /// @alfuncwrap{Bufferfv}
    al_api_function<
      void(name_type, enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Bufferfv)>
      Bufferfv;

    /// @var GetBufferfv
    /// @alfuncwrap{GetBufferfv}
    al_api_function<
      void(name_type, enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetBufferfv)>
      GetBufferfv;

    /// @var GenSources
    /// @alfuncwrap{GenSources}
    al_api_function<
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenSources)>
      GenSources;

    /// @var DeleteSources
    /// @alfuncwrap{DeleteSources}
    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(DeleteSources)>
      DeleteSources;

    /// @var IsSource
    /// @alfuncwrap{IsSource}
    al_api_function<bool_type(name_type), OALPLUS_AL_STATIC_FUNC(IsSource)>
      IsSource;

    /// @var Sourcei
    /// @alfuncwrap{Sourcei}
    al_api_function<
      void(name_type, enum_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Sourcei)>
      Sourcei;

    /// @var Source3i
    /// @alfuncwrap{Source3i}
    al_api_function<
      void(name_type, enum_type, int_type, int_type, int_type),
      OALPLUS_AL_STATIC_FUNC(Source3i)>
      Source3i;

    /// @var Sourceiv
    /// @alfuncwrap{Sourceiv}
    al_api_function<
      void(name_type, enum_type, const int_type*),
      OALPLUS_AL_STATIC_FUNC(Sourceiv)>
      Sourceiv;

    /// @var GetSourceiv
    /// @alfuncwrap{GetSourceiv}
    al_api_function<
      void(name_type, enum_type, int_type*),
      OALPLUS_AL_STATIC_FUNC(GetSourceiv)>
      GetSourceiv;

    /// @var Sourcef
    /// @alfuncwrap{Sourcef}
    al_api_function<
      void(name_type, enum_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Sourcef)>
      Sourcef;

    /// @var Source3f
    /// @alfuncwrap{Source3f}
    al_api_function<
      void(name_type, enum_type, float_type, float_type, float_type),
      OALPLUS_AL_STATIC_FUNC(Source3f)>
      Source3f;

    /// @var Sourcefv
    /// @alfuncwrap{Sourcefv}
    al_api_function<
      void(name_type, enum_type, const float_type*),
      OALPLUS_AL_STATIC_FUNC(Sourcefv)>
      Sourcefv;

    /// @var GetSourcefv
    /// @alfuncwrap{GetSourcefv}
    al_api_function<
      void(name_type, enum_type, float_type*),
      OALPLUS_AL_STATIC_FUNC(GetSourcefv)>
      GetSourcefv;

    /// @var SourcePlay
    /// @alfuncwrap{SourcePlay}
    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourcePlay)>
      SourcePlay;

    /// @var SourceStop
    /// @alfuncwrap{SourceStop}
    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourceStop)>
      SourceStop;

    /// @var SourceRewind
    /// @alfuncwrap{SourceRewind}
    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourceRewind)>
      SourceRewind;

    /// @var SourcePause
    /// @alfuncwrap{SourcePause}
    al_api_function<void(name_type), OALPLUS_AL_STATIC_FUNC(SourcePause)>
      SourcePause;

    /// @var SourcePlayv
    /// @alfuncwrap{SourcePlayv}
    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourcePlayv)>
      SourcePlayv;

    /// @var SourceStopv
    /// @alfuncwrap{SourceStopv}
    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceStopv)>
      SourceStopv;

    /// @var SourceRewindv
    /// @alfuncwrap{SourceRewindv}
    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceRewindv)>
      SourceRewindv;

    /// @var SourcePausev
    /// @alfuncwrap{SourcePausev}
    al_api_function<
      void(size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourcePausev)>
      SourcePausev;

    /// @var SourceQueueBuffers
    /// @alfuncwrap{SourceQueueBuffers}
    al_api_function<
      void(name_type, size_type, const name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceQueueBuffers)>
      SourceQueueBuffers;

    /// @var SourceUnqueueBuffers
    /// @alfuncwrap{SourceUnqueueBuffers}
    al_api_function<
      void(name_type, size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(SourceUnqueueBuffers)>
      SourceUnqueueBuffers;

    /// @var GenEffects
    /// @alfuncwrap{GenEffects}
    al_api_function<void(size_type, name_type*), nullptr> GenEffects;

    /// @var DeleteEffects
    /// @alfuncwrap{DeleteEffects}
    al_api_function<void(size_type, const name_type*), nullptr> DeleteEffects;

    /// @var IsEffect
    /// @alfuncwrap{IsEffect}
    al_api_function<bool_type(name_type), nullptr> IsEffect;

    /// @var Effecti
    /// @alfuncwrap{Effecti}
    al_api_function<void(name_type, enum_type, int_type), nullptr> Effecti;

    /// @var Effectiv
    /// @alfuncwrap{Effectiv}
    al_api_function<void(name_type, enum_type, const int_type*), nullptr>
      Effectiv;

    /// @var Effectf
    /// @alfuncwrap{Effectf}
    al_api_function<void(name_type, enum_type, float_type), nullptr> Effectf;

    /// @var Effectfv
    /// @alfuncwrap{Effectfv}
    al_api_function<void(name_type, enum_type, const float_type*), nullptr>
      Effectfv;

    /// @var GetEffecti
    /// @alfuncwrap{GetEffecti}
    al_api_function<void(name_type, enum_type, int_type*), nullptr> GetEffecti;

    /// @var GetEffectiv
    /// @alfuncwrap{GetEffectiv}
    al_api_function<void(name_type, enum_type, int_type*), nullptr> GetEffectiv;

    /// @var GetEffectf
    /// @alfuncwrap{GetEffectf}
    al_api_function<void(name_type, enum_type, float_type*), nullptr> GetEffectf;

    /// @var GetEffectfv
    /// @alfuncwrap{GetEffectfv}
    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetEffectfv;

    /// @var GenFilters
    /// @alfuncwrap{GenFilters}
    al_api_function<void(size_type, name_type*), nullptr> GenFilters;

    /// @var DeleteFilters
    /// @alfuncwrap{DeleteFilters}
    al_api_function<void(size_type, const name_type*), nullptr> DeleteFilters;

    /// @var IsFilter
    /// @alfuncwrap{IsFilter}
    al_api_function<bool_type(name_type), nullptr> IsFilter;

    /// @var Filteri
    /// @alfuncwrap{Filteri}
    al_api_function<void(name_type, enum_type, int_type), nullptr> Filteri;

    /// @var Filteriv
    /// @alfuncwrap{Filteriv}
    al_api_function<void(name_type, enum_type, const int_type*), nullptr>
      Filteriv;

    /// @var Filterf
    /// @alfuncwrap{Filterf}
    al_api_function<void(name_type, enum_type, float_type), nullptr> Filterf;

    /// @var Filterfv
    /// @alfuncwrap{Filterfv}
    al_api_function<void(name_type, enum_type, const float_type*), nullptr>
      Filterfv;

    /// @var GetFilteri
    /// @alfuncwrap{GetFilteri}
    al_api_function<void(name_type, enum_type, int_type*), nullptr> GetFilteri;

    /// @var GetFilteriv
    /// @alfuncwrap{GetFilteriv}
    al_api_function<void(name_type, enum_type, int_type*), nullptr> GetFilteriv;

    /// @var GetFilterf
    /// @alfuncwrap{GetFilterf}
    al_api_function<void(name_type, enum_type, float_type*), nullptr> GetFilterf;

    /// @var GetFilterfv
    /// @alfuncwrap{GetFilterfv}
    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetFilterfv;

    /// @var GenAuxiliaryEffectSlots
    /// @alfuncwrap{GenAuxiliaryEffectSlots}
    al_api_function<void(size_type, name_type*), nullptr>
      GenAuxiliaryEffectSlots;

    /// @var DeleteAuxiliaryEffectSlots
    /// @alfuncwrap{DeleteAuxiliaryEffectSlots}
    al_api_function<void(size_type, const name_type*), nullptr>
      DeleteAuxiliaryEffectSlots;

    /// @var IsAuxiliaryEffectSlot
    /// @alfuncwrap{IsAuxiliaryEffectSlot}
    al_api_function<bool_type(name_type), nullptr> IsAuxiliaryEffectSlot;

    /// @var AuxiliaryEffectSloti
    /// @alfuncwrap{AuxiliaryEffectSloti}
    al_api_function<void(name_type, enum_type, int_type), nullptr>
      AuxiliaryEffectSloti;

    /// @var AuxiliaryEffectSlotiv
    /// @alfuncwrap{AuxiliaryEffectSlotiv}
    al_api_function<void(name_type, enum_type, const int_type*), nullptr>
      AuxiliaryEffectSlotiv;

    /// @var AuxiliaryEffectSlotf
    /// @alfuncwrap{AuxiliaryEffectSlotf}
    al_api_function<void(name_type, enum_type, float_type), nullptr>
      AuxiliaryEffectSlotf;

    /// @var AuxiliaryEffectSlotfv
    /// @alfuncwrap{AuxiliaryEffectSlotfv}
    al_api_function<void(name_type, enum_type, const float_type*), nullptr>
      AuxiliaryEffectSlotfv;

    /// @var GetAuxiliaryEffectSloti
    /// @alfuncwrap{GetAuxiliaryEffectSloti}
    al_api_function<void(name_type, enum_type, int_type*), nullptr>
      GetAuxiliaryEffectSloti;

    /// @var GetAuxiliaryEffectSlotiv
    /// @alfuncwrap{GetError}
    al_api_function<void(name_type, enum_type, int_type*), nullptr>
      GetAuxiliaryEffectSlotiv;

    /// @var GetAuxiliaryEffectSlotf
    /// @alfuncwrap{GetAuxiliaryEffectSlotf}
    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetAuxiliaryEffectSlotf;

    /// @var GetAuxiliaryEffectSlotfv
    /// @alfuncwrap{GetAuxiliaryEffectSlotfv}
    al_api_function<void(name_type, enum_type, float_type*), nullptr>
      GetAuxiliaryEffectSlotfv;

    basic_al_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
/// @brief Alias for the default AL operations wrapper instantiation.
/// @ingroup al_api_wrap
using al_c_api = basic_al_c_api<al_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_C_API_HPP
