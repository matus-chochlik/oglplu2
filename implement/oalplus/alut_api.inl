/**
 *  @file oalplus/alut_api.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oalplus/alut_api/api_traits.inl>
#include <oalplus/alut_api/constants.inl>
#include <oalplus/alut_api/c_api.inl>
#include <oalplus/alut_api/api.inl>
// clang-format on

namespace eagine::oalp {

template class basic_alut_api<alut_api_traits>;

} // namespace eagine::oalp

