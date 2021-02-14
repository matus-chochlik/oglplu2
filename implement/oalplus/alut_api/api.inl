/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_alut_operations<ApiTraits>::basic_alut_operations(api_traits& traits)
  : c_api{traits}
  , init("init", traits, *this)
  , create_buffer_hello_world("create_buffer_hello_world", traits, *this)
  , exit("exit", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp
