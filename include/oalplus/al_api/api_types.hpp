/**
 *  @file oalplus/al_api/api_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_API_TYPES_HPP
#define OALPLUS_AL_API_API_TYPES_HPP

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_types {
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
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_API_TYPES_HPP

