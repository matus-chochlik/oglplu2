/**
 *  @file oalplus/al_api_fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_FWD_HPP
#define OALPLUS_AL_API_FWD_HPP

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class al_api_traits;

template <typename ApiTraits>
class basic_al_api;

using al_api = basic_al_api<al_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_FWD_HPP

