/**
 *  @file oalplus/alc_api/c_api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_C_API_TRAITS_HPP
#define OALPLUS_ALC_API_C_API_TRAITS_HPP

#include <eagine/nothing.hpp>
#include <eagine/string_span.hpp>
#include <type_traits>
#include <utility>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alc_c_api_traits {

    template <typename Tag, typename Signature>
    using function_pointer = std::add_pointer<Signature>;

    template <typename Tag, typename Signature>
    std::add_pointer_t<Signature> load_function(
      Tag, string_view, identity<Signature>) {
        return nullptr;
    }

    template <typename RV>
    static constexpr RV fallback(nothing_t, identity<RV>) {
        return {};
    }

    static constexpr void fallback(nothing_t, identity<void>) {
    }

    template <typename RV, typename... Params, typename... Args>
    static constexpr RV call(
      nothing_t tag, RV (*function)(Params...), Args&&... args) {
        if(function) {
            return function(std::forward<Args>(args)...);
        }
        return fallback(tag, identity<RV>());
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_C_API_TRAITS_HPP

