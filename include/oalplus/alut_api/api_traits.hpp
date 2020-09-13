/**
 *  @file oalplus/alut_api/api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_API_TRAITS_HPP
#define OALPLUS_ALUT_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
class alut_api_traits : public default_c_api_traits {
public:
    template <typename R>
    using no_result = alut_no_result<R>;
    template <typename R>
    using result = alut_result<R>;
    template <typename R>
    using opt_result = alut_opt_result<R>;

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_API_TRAITS_HPP
