/**
 *  @file oalplus/alc_api/api_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_API_TYPES_HPP
#define OALPLUS_ALC_API_API_TYPES_HPP

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct api_types {
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
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_API_TYPES_HPP

