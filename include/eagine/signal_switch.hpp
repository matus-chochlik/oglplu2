/**
 *  @file eagine/signal_switch.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SIGNAL_SWITCH_HPP
#define EAGINE_SIGNAL_SWITCH_HPP

#include <csignal>

namespace eagine {

class signal_switch {

    static inline auto& _state() noexcept {
        static volatile std::sig_atomic_t state{0};
        return state;
    }

    static inline void _flip(int sig_num) {
        _state() = sig_num;
    }

public:
    signal_switch() noexcept
      : _intr_handler{std::signal(SIGINT, &_flip)}
      , _term_handler{std::signal(SIGTERM, &_flip)} {
    }

    bool interrupted() const noexcept {
        return _state() == SIGINT;
    }

    bool terminated() const noexcept {
        return _state() == SIGTERM;
    }

    explicit inline operator bool() const noexcept {
        return bool(_state());
    }

    inline bool operator!() const noexcept {
        return !bool(*this);
    }

private:
    using _sighandler_t = void(int);
    const _sighandler_t* _intr_handler{nullptr};
    const _sighandler_t* _term_handler{nullptr};
};

} // namespace eagine

#endif // EAGINE_SIGNAL_SWITCH_HPP
