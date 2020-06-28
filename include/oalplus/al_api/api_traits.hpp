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
class al_api_traits : public default_c_api_traits {
public:
    template <typename R>
    using no_result = al_no_result<R>;
    template <typename R>
    using result = al_result<R>;
    template <typename R>
    using opt_result = al_opt_result<R>;

    template <typename Api, typename Type>
    std::tuple<Type, bool> load_constant(
      Api& api, string_view name, identity<Type>) {
        if(api.GetEnumValue && api.GetError) {
            _full_name.clear();
            _full_name.reserve(3 + name.size() + 1);
            _full_name.append("AL_");
            _full_name.append(name.data(), std::size_t(name.size()));
            const auto val = api.GetEnumValue(_full_name.c_str());
            if(al_types::error_code_no_error(api.GetError())) {
                return {static_cast<Type>(val), true};
            }
        }
        return {{}, false};
    }

    template <typename Api, typename Tag, typename Signature>
    std::add_pointer_t<Signature> link_function(
      Api& api, Tag, string_view name, identity<Signature>) {
        if(api.GetProcAddress && api.GetError) {
            _full_name.clear();
            _full_name.reserve(2 + name.size() + 1);
            _full_name.append("al");
            _full_name.append(name.data(), std::size_t(name.size()));
            auto func = api.GetProcAddress(_full_name.c_str());
            if(al_types::error_code_no_error(api.GetError())) {
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

#endif // OALPLUS_AL_API_API_TRAITS_HPP

