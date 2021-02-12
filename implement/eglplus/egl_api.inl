/// @file eglplus/egl_api.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

// clang-format off
#include <eglplus/egl_api/api_traits.inl>
#include <eglplus/egl_api/constants.inl>
#include <eglplus/egl_api/c_api.inl>
#include <eglplus/egl_api/api.inl>
// clang-format on

namespace eagine::eglp {

template class basic_egl_constants<egl_api_traits>;
template class basic_egl_operations<egl_api_traits>;
template class basic_egl_c_api<egl_api_traits>;
template class basic_egl_api<egl_api_traits>;

} // namespace eagine::eglp

