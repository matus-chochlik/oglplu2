/// @file
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
/// @brief Policy customizing the generic C-API wrappers for the AL API
/// @ingroup al_api_wrap
/// @see default_c_api_traits
class al_api_traits : public default_c_api_traits {
public:
    /// @brief Alias for result type of currently unavailable functions.
    template <typename R>
    using no_result = al_no_result<R>;

    /// @brief Alias for result type of functions.
    template <typename R>
    using result = al_result<R>;

    /// @brief Alias for result type of optionally available functions.
    template <typename R>
    using opt_result = al_opt_result<R>;

    /// @brief Loads an AL constant with the specified name and Type.
    template <typename Api, typename Type>
    auto load_constant(Api& api, string_view name, type_identity<Type>)
      -> std::tuple<Type, bool>;

    /// @brief Links an AL function with the specified name and Signature.
    template <typename Api, typename Tag, typename Signature>
    auto link_function(Api& api, Tag, string_view name, type_identity<Signature>)
      -> std::add_pointer_t<Signature>;

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_API_TRAITS_HPP
