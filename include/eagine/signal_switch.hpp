/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SIGNAL_SWITCH_HPP
#define EAGINE_SIGNAL_SWITCH_HPP

#include <csignal>

namespace eagine {

/// @brief Installs handlers for interrupt signals and flips switch on receipt.
///
/// This class installs handlers for the interrupt and terminate OS IPC signals
/// and if one of the signals is received it flips a boolean indicator from
/// false to true.
///
/// @note Only a single instance per process should be created.
class signal_switch {

    static auto _state() noexcept -> auto& {
        static volatile std::sig_atomic_t state{0};
        return state;
    }

    static void _flip(int sig_num) {
        _state() = sig_num;
    }

public:
    /// @brief Default constructor. Stores the original handlers if any.
    /// @post !bool(*this)
    signal_switch() noexcept
      : _intr_handler{std::signal(SIGINT, &_flip)}
      , _term_handler{std::signal(SIGTERM, &_flip)} {}

    /// @brief Destructor. Restores the original signal handlers.
    ~signal_switch() noexcept {
        std::signal(SIGINT, _intr_handler);
        std::signal(SIGTERM, _term_handler);
    }

    /// @brief Not moveable.
    signal_switch(signal_switch&&) = delete;
    /// @brief Not copyable.
    signal_switch(const signal_switch&) = delete;
    /// @brief Not move-assignable.
    auto operator=(signal_switch&&) = delete;
    /// @brief Not copy-assignable.
    auto operator=(const signal_switch&) = delete;

    /// @brief Resets the signal state as if no signal was received.
    /// @post !bool(*this)
    auto reset() noexcept -> signal_switch& {
        _state() = 0;
        return *this;
    }

    /// @brief Indicates if the interrupt signal was received.
    auto interrupted() const noexcept -> bool {
        return _state() == SIGINT;
    }

    /// @brief Indicates if the terminate signal was received.
    auto terminated() const noexcept -> bool {
        return _state() == SIGTERM;
    }

    /// @brief Indicates if one of the tracked signals was received.
    explicit operator bool() const noexcept {
        return bool(_state());
    }

private:
    using _sighandler_t = void(int);
    _sighandler_t* _intr_handler{nullptr};
    _sighandler_t* _term_handler{nullptr};
};

} // namespace eagine

#endif // EAGINE_SIGNAL_SWITCH_HPP
