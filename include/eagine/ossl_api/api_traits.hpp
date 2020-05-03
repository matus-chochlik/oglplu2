/**
 *  @file eagine/ossl_api/api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_API_TRAITS_HPP
#define EAGINE_OSSL_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
class ossl_api_traits : public default_c_api_traits {
public:
    template <typename R>
    using no_result = ossl_no_result<R>;
    template <typename R>
    using result = ossl_result<R>;
    template <typename R>
    using opt_result = ossl_opt_result<R>;

private:
};
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

#endif // EAGINE_OSSL_API_API_TRAITS_HPP

