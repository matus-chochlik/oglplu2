/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_API_TRAITS_HPP
#define OALPLUS_ALUT_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Policy customizing the generic C-API wrappers for the ALUT API
/// @ingroup al_api_wrap
/// @see default_c_api_traits
class alut_api_traits : public default_c_api_traits {
public:
    /// @brief Alias for result type of currently unavailable functions.
    template <typename R>
    using no_result = alut_no_result<R>;

    /// @brief Alias for result type of functions.
    template <typename R>
    using result = alut_result<R>;

    /// @brief Alias for result type of optionally available functions.
    template <typename R>
    using opt_result = alut_opt_result<R>;

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_API_TRAITS_HPP
