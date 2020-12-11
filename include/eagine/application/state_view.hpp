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

namespace eagine::application {
//------------------------------------------------------------------------------
template <typename T>
using state_value = value_with_history<T, 3>;

template <typename T>
using state_variable = variable_with_history<T, 3>;
//------------------------------------------------------------------------------
class state_view {
public:
    auto frame_number() const noexcept -> int {
        return _frame_no;
    }

    auto frame_time() const noexcept -> seconds_t<float> {
        return seconds_(_frame_time.value());
    }

    auto frame_duration() const noexcept -> seconds_t<float> {
        return seconds_(_frame_time.delta());
    }

    auto user_idle() const noexcept -> state_value<bool> {
        return {_new_user_idle, _old_user_idle};
    }

    auto user_became_idle() const noexcept -> bool {
        return user_idle().delta() > 0;
    }

    auto user_became_active() const noexcept -> bool {
        return user_idle().delta() < 0;
    }

protected:
    state_variable<float> _frame_time{0.0F};
    int _frame_no{0};

    bool _old_user_idle{false};
    bool _new_user_idle{false};
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
