/// @file oalplus/al_api/api_traits.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_API_API_TRAITS_HPP
#define OALPLUS_AL_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine::oalp {
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
    auto load_constant(Api& api, string_view name, type_identity<Type>)
      -> std::tuple<Type, bool>;

    template <typename Api, typename Tag, typename Signature>
    auto link_function(Api& api, Tag, string_view name, type_identity<Signature>)
      -> std::add_pointer_t<Signature>;

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_API_TRAITS_HPP
