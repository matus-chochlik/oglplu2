/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_TIMEOUT_HPP
#define EAGINE_TIMEOUT_HPP

#include "nothing.hpp"
#include "slow_exec.hpp"
#include <chrono>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Class that measures elapsed time since instance construction.
/// @ingroup time_utils
/// @see timeout
class time_measure {
    using _clock = std::chrono::steady_clock;

public:
    /// @brief Default constructor. Saves the current time.
    time_measure() noexcept
      : _start{_clock::now()} {}

    /// @brief Returns the time since construction using clock's representation.
    auto elapsed_time() const noexcept {
        return _clock::now() - _start;
    }

    /// @brief Returns the time since construction in seconds.
    auto seconds() const noexcept {
        return std::chrono::duration_cast<std::chrono::duration<float>>(
          elapsed_time());
    }

private:
    _clock::time_point _start{};
};
//------------------------------------------------------------------------------
/// @brief Adjusts time duration in cases program execution is slowed down.
/// @ingroup time_utils
template <typename R, typename P>
constexpr auto adjusted_duration(
  std::chrono::duration<R, P> d,
  memory_access_rate mem_access = memory_access_rate::medium) noexcept {
    return d * R(temporal_slowdown_factor(mem_access));
}
//------------------------------------------------------------------------------
/// @brief Class representing a timeout since construction or reset.
/// @ingroup time_utils
/// @see time_measure
/// @see resetting_timeout
class timeout {
    using _clock = std::chrono::steady_clock;

public:
    /// @brief Default construction. Saves current time. Immediately expires.
    /// @post is_expired()
    timeout() noexcept
      : _timeout{_clock::now()} {}

    /// @brief Construction from the default and initial timeout duration.
    /// @see reset
    /// @see period
    timeout(_clock::duration duration, _clock::duration initial) noexcept
      : _duration{duration}
      , _timeout{_clock::now() + initial} {}

    /// @brief Construction from the default and zero initial timeout duration.
    /// @see reset
    /// @see period
    timeout(_clock::duration duration, nothing_t) noexcept
      : timeout{duration, _clock::duration::zero()} {}

    /// @brief Construction from the default duration.
    /// @see reset
    /// @see period
    timeout(_clock::duration duration) noexcept
      : timeout{duration, duration} {}

    /// @brief Construction from the default duration.
    /// @see reset
    /// @see period
    template <typename R, typename P>
    timeout(std::chrono::duration<R, P> duration) noexcept
      : timeout{std::chrono::duration_cast<_clock::duration>(duration)} {}

    /// @brief Resets the timeout using the previously specified duration.
    auto reset() noexcept -> auto& {
        _timeout = std::chrono::steady_clock::now() + _duration;
        return *this;
    }

    /// @brief Resets the timeout using the specified duration values.
    auto reset(_clock::duration duration, _clock::duration initial) noexcept
      -> auto& {
        _duration = duration;
        _timeout = std::chrono::steady_clock::now() + initial;
        return *this;
    }

    /// @brief Resets the timeout using the specified duration values.
    /// @post is_expired()
    auto reset(_clock::duration duration, nothing_t) noexcept -> auto& {
        return reset(duration, _clock::duration::zero());
    }

    /// @brief Resets the timeout using the specified duration value.
    /// @see is_expired
    auto reset(_clock::duration duration) noexcept -> auto& {
        return reset(duration, duration);
    }

    /// @brief Returns the time since reset as clocks duration type.
    auto elapsed_time() const noexcept {
        return _clock::now() - _timeout + _duration;
    }

    /// @brief Indicates if the timeout is expired.
    /// @see reset
    /// @see period
    auto is_expired() const noexcept -> bool {
        return _clock::now() >= _timeout;
    }

    /// @brief Indicates if the timeout is expired.
    /// @see is_expired
    explicit operator bool() const noexcept {
        return is_expired();
    }

    /// @brief Returns the timeout period.
    /// @see reset
    /// @see is_expired
    auto period() const noexcept -> auto& {
        return _duration;
    }

private:
    _clock::duration _duration{};
    _clock::time_point _timeout{};
};
//------------------------------------------------------------------------------
/// @brief Specialization of timeout that resets when tested for expiration.
/// @ingroup time_utils
/// @see timeout
/// @see time_measure
class resetting_timeout : public timeout {
public:
    using timeout::timeout;

    /// @brief Indicates if expired and if it is resets the timeout.
    explicit operator bool() noexcept {
        const auto result = is_expired();
        if(result) {
            reset();
        }
        return result;
    }
};

} // namespace eagine

#endif // EAGINE_TIMEOUT_HPP
