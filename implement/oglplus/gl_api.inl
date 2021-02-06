/**
 *  @file oglplus/gl_api.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl_api/api_traits.inl>
#include <oglplus/gl_api/constants.inl>
#include <oglplus/gl_api/c_api.inl>
#include <oglplus/gl_api/api.inl>
// clang-format on

namespace eagine::oglp {

template class basic_gl_api<gl_api_traits>;

} // namespace eagine::oglp

