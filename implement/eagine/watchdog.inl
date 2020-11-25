/**
 *  @file eagine/watchdog.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#if EAGINE_USE_SYSTEMD
#include <systemd/sd-daemon.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void process_watchdog::declare_initialized() noexcept {
#if EAGINE_USE_SYSTEMD
    ::sd_notify(0, "READY=1");
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void process_watchdog::notify_alive() noexcept {
#if EAGINE_USE_SYSTEMD
    ::sd_notify(0, "WATCHDOG=1");
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void process_watchdog::announce_shutdown() noexcept {
#if EAGINE_USE_SYSTEMD
    ::sd_notify(0, "STOPPING=1");
#endif
}
//------------------------------------------------------------------------------
} // namespace eagine
