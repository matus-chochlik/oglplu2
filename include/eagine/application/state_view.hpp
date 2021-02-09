/**
 *  @file eagine/application/state_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_STATE_VIEW_HPP
#define EAGINE_APPLICATION_STATE_VIEW_HPP

#include "../quantities.hpp"
#include "../value_with_history.hpp"
#include <chrono>

namespace eagine::application {
//------------------------------------------------------------------------------
template <typename T>
using state_value = value_with_history<T, 3>;

template <typename T>
using state_variable = variable_with_history<T, 3>;
//------------------------------------------------------------------------------
class context_state_view {
public:
    using clock_type = std::chrono::steady_clock;

    auto run_time() const noexcept {
        return clock_type::now() - _start_time;
    }

    auto user_idle_time() const noexcept {
        return clock_type::now() - _user_active_time;
    }

    auto frame_time() const noexcept -> seconds_t<float> {
        return seconds_(_frame_time.value());
    }

    auto frame_duration() const noexcept -> seconds_t<float> {
        return seconds_(_frame_time.delta());
    }

    auto is_active() const noexcept -> bool {
        return !_new_user_idle || _has_activity;
    }

    auto user_is_idle() const noexcept -> state_value<bool> {
        return {_new_user_idle, _old_user_idle};
    }

    auto user_became_idle() const noexcept -> bool {
        return user_is_idle().delta() > 0;
    }

    auto user_became_active() const noexcept -> bool {
        return user_is_idle().delta() < 0;
    }

    auto user_idle_too_long() const noexcept -> bool {
        // TODO: configurable interval?
        return user_idle_time() > std::chrono::seconds{1};
    }

protected:
    const clock_type::time_point _start_time{clock_type::now()};
    clock_type::time_point _user_active_time{clock_type::now()};
    state_variable<float> _frame_time{0.0F};

    bool _has_activity{false};
    bool _old_user_idle{false};
    bool _new_user_idle{false};
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
