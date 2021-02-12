/// @file eagine/signal_switch.hpp
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

class signal_switch {

    static auto _state() noexcept -> auto& {
        static volatile std::sig_atomic_t state{0};
        return state;
    }

    static void _flip(int sig_num) {
        _state() = sig_num;
    }

public:
    signal_switch() noexcept
      : _intr_handler{std::signal(SIGINT, &_flip)}
      , _term_handler{std::signal(SIGTERM, &_flip)} {}

    ~signal_switch() noexcept {
        std::signal(SIGINT, _intr_handler);
        std::signal(SIGTERM, _term_handler);
    }

    signal_switch(signal_switch&&) = delete;
    signal_switch(const signal_switch&) = delete;
    auto operator=(signal_switch&&) = delete;
    auto operator=(const signal_switch&) = delete;

    auto reset() noexcept -> signal_switch& {
        _state() = 0;
        return *this;
    }

    auto interrupted() const noexcept -> bool {
        return _state() == SIGINT;
    }

    auto terminated() const noexcept -> bool {
        return _state() == SIGTERM;
    }

    explicit inline operator bool() const noexcept {
        return bool(_state());
    }

private:
    using _sighandler_t = void(int);
    _sighandler_t* _intr_handler{nullptr};
    _sighandler_t* _term_handler{nullptr};
};

} // namespace eagine

#endif // EAGINE_SIGNAL_SWITCH_HPP
