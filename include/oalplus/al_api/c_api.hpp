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
      void(size_type, name_type*),
      OALPLUS_AL_STATIC_FUNC(GenBuffers),
      has_api>
      GenBuffers;

    eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      void(size_type, name_type*),
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
      void(size_type, name_type*),
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
      , GenBuffers("GenBuffers", traits, *this)
      , DeleteBuffers("DeleteBuffers", traits, *this)
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

