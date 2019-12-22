/**
 *  @file oalplus/alut_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_CONSTANTS_HPP
#define OALPLUS_ALUT_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_alut_constants {
public:
    using enum_type = typename alut_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    opt_c_api_constant<
      mp_list<alut_error_code>,
#ifdef ALUT_NO_ERROR
      enum_type_c<ALUT_ERROR_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    basic_alut_constants(ApiTraits& traits, basic_alut_c_api<ApiTraits>& api)
      : no_error("ERROR_NO_ERROR", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_CONSTANTS_HPP

