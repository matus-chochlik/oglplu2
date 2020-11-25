/**
 *  @file eagine/watchdog.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_WATCHDOG_HPP
#define EAGINE_WATCHDOG_HPP

#include "config/basic.hpp"

namespace eagine {

class process_watchdog {
public:
    void declare_initialized() noexcept;
    void notify_alive() noexcept;
    void announce_shutdown() noexcept;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/watchdog.inl>
#endif

#endif // EAGINE_WATCHDOG_HPP
