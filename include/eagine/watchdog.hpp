/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_WATCHDOG_HPP
#define EAGINE_WATCHDOG_HPP

#include "config/basic.hpp"
#include "main_ctx_object.hpp"
#include <memory>

namespace eagine {

class process_watchdog_impl;

/// @brief Class implementing process watchdog functionality.
/// @ingroup main_context
class process_watchdog : public main_ctx_object {
public:
    process_watchdog(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(Watchdog), parent} {}

    /// @brief Tells the system that this process finished initialization.
    void declare_initialized() noexcept;

    /// @brief Tells the system that this process is alive. Should be called repeatedly.
    void notify_alive() noexcept;

    /// @brief Announce to the system that this process is shutting down.
    void announce_shutdown() noexcept;

private:
    std::shared_ptr<process_watchdog_impl> _pimpl;
    auto _impl() noexcept -> process_watchdog_impl*;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/watchdog.inl>
#endif

#endif // EAGINE_WATCHDOG_HPP
