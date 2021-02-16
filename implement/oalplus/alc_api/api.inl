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
basic_alc_operations<ApiTraits>::basic_alc_operations(api_traits& traits)
  : c_api{traits}
  , open_device("open_device", traits, *this)
  , close_device("close_device", traits, *this)
  , create_context("create_context", traits, *this)
  , destroy_context("destroy_context", traits, *this)
  , make_context_current("make_context_current", traits, *this)
  , get_current_context("get_current_context", traits, *this)
  , get_integer("get_integer", traits, *this)
  , get_string("get_string", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

