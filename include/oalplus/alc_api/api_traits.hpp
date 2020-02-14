/**
 *  @file oalplus/alc_api/api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_API_TRAITS_HPP
#define OALPLUS_ALC_API_API_TRAITS_HPP

#include "result.hpp"
#include <string>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class alc_api_traits : public default_c_api_traits {
public:
    template <typename R>
    using no_result = alc_no_result<R>;
    template <typename R>
    using result = alc_result<R>;
    template <typename R>
    using opt_result = alc_opt_result<R>;

    template <typename Api, typename Type>
    std::tuple<Type, bool> load_constant(
      Api& api, string_view name, identity<Type>) {
        if(api.GetEnumValue) {
            _full_name.clear();
            _full_name.reserve(4 + name.size() + 1);
            _full_name.append("ALC_");
            _full_name.append(name.data(), std::size_t(name.size()));
            return {
              static_cast<Type>(api.GetEnumValue(nullptr, _full_name.c_str())),
              true};
        }
        return {{}, false};
    }

    template <typename Api, typename Tag, typename Signature>
    std::add_pointer_t<Signature> link_function(
      Api& api, Tag, string_view name, identity<Signature>) {
        if(api.GetProcAddress && api.GetError) {
            _full_name.clear();
            _full_name.reserve(3 + name.size() + 1);
            _full_name.append("alc");
            _full_name.append(name.data(), std::size_t(name.size()));
            auto func = api.GetProcAddress(nullptr, _full_name.c_str());
            if(alc_types::error_code_no_error(api.GetError())) {
                return reinterpret_cast<std::remove_pointer_t<Signature>*>(
                  func);
            }
        }
        return nullptr;
    }

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_API_TRAITS_HPP

