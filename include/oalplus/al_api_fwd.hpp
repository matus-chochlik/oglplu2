/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_API_FWD_HPP
#define OALPLUS_AL_API_FWD_HPP

namespace eagine::oalp {
//------------------------------------------------------------------------------
class al_api_traits;

template <typename ApiTraits>
class basic_al_api;

/// @brief Alias for the default instantation of basic_al_api.
/// @ingroup al_api_wrap
using al_api = basic_al_api<al_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_FWD_HPP
