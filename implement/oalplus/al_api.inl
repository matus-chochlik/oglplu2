/// @file oalplus/al_api.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

// clang-format off
#include <oalplus/al_api/api_traits.inl>
#include <oalplus/al_api/constants.inl>
#include <oalplus/al_api/c_api.inl>
#include <oalplus/al_api/api.inl>
// clang-format on

namespace eagine::oalp {

template class basic_al_constants<al_api_traits>;
template class basic_al_operations<al_api_traits>;
template class basic_al_c_api<al_api_traits>;
template class basic_al_api<al_api_traits>;

} // namespace eagine::oalp

