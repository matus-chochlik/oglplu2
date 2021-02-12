/// @file eagine/application/framedump_raw.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_FRAMEDUMP_RAW_HPP
#define EAGINE_APPLICATION_FRAMEDUMP_RAW_HPP

#include "../main_ctx_fwd.hpp"
#include "interface.hpp"
#include <memory>

namespace eagine::application {

auto make_raw_framedump(main_ctx_parent) -> std::shared_ptr<framedump>;

} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/framedump_raw.inl>
#endif

#endif
