/**
 *  @file eagine/reflect/map_enumerators_fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_REFLECT_MAP_ENUMERATORS_FWD_HPP
#define EAGINE_REFLECT_MAP_ENUMERATORS_FWD_HPP

#include "../string_span.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct enumerator_info {
    constexpr enumerator_info(string_view n, T e) noexcept
      : name{n}
      , enumerator{e} {
    }

    const string_view name;
    const T enumerator;
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
using enumerator_map_type = std::array<enumerator_info<T>, N>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MAP_ENUMERATORS_FWD_HPP
