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
#include <eagine/c_api_wrap.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alc_api_traits : default_c_api_traits {
    template <typename R>
    using no_result = alc_no_result<R>;
    template <typename R>
    using opt_result = alc_opt_result<R>;
    template <typename R>
    using result = alc_result<R>;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_API_TRAITS_HPP

