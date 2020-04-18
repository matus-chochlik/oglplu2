/**
 *  @file eagine/timeout.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TIMEOUT_HPP
#define EAGINE_TIMEOUT_HPP

#include <chrono>

namespace eagine {

class timeout {
    using _clock = std::chrono::steady_clock;

public:
    timeout() noexcept
      : _timeout{_clock::now()} {
    }

    timeout(_clock::duration duration) noexcept
      : _duration{duration}
      , _timeout{_clock::now() + _duration} {
    }

    timeout& reset() noexcept {
        _timeout = std::chrono::steady_clock::now() + _duration;
        return *this;
    }

    timeout& reset(_clock::duration duration) noexcept {
        _duration = duration;
        _timeout = std::chrono::steady_clock::now() + _duration;
        return *this;
    }

    bool elapsed() const noexcept {
        return _clock::now() >= _timeout;
    }

    explicit operator bool() const noexcept {
        return elapsed();
    }

    bool operator!() const noexcept {
        return !elapsed();
    }

private:
    _clock::duration _duration{};
    _clock::time_point _timeout;
};

} // namespace eagine

#endif // EAGINE_TIMEOUT_HPP
