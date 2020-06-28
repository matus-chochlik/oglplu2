/**
 *  @file oalplus/alc_api_fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_FWD_HPP
#define OALPLUS_ALC_API_FWD_HPP

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class alc_api_traits;

template <typename ApiTraits>
class basic_alc_api;

using alc_api = basic_alc_api<alc_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_FWD_HPP

