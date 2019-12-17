/**
 *  @file oalplus/al_api/api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_API_TRAITS_HPP
#define OALPLUS_AL_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_api_traits : default_c_api_traits {
    template <typename R>
    using no_result = al_no_result<R>;
    template <typename R>
    using result = al_result<R>;
    template <typename R>
    using opt_result = al_opt_result<R>;

    template <typename Api, typename Type>
    static std::tuple<Type, bool> load_constant(
      Api& api, string_view name, identity<Type>) {
        if(api.GetEnumValue) {
            std::string full_name;
            full_name.reserve(3 + name.size() + 1);
            full_name.append("AL_");
            full_name.append(name.data(), std::size_t(name.size()));
            return {
              static_cast<Type>(api.GetEnumValue(nullptr, full_name.c_str())),
              true};
        }
        return {{}, false};
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_API_TRAITS_HPP

