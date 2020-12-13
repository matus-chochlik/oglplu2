/**
 *  @file eagine/application/state.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_STATE_HPP
#define EAGINE_APPLICATION_STATE_HPP

#include "state_view.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
class state : public state_view {
public:
    auto set_time(float new_time) noexcept -> auto& {
        EAGINE_ASSERT(new_time >= 0.0F);
        _frame_time.assign(new_time);
        return *this;
    }

    auto advance_time(float dt) noexcept -> auto& {
        _frame_time.advance(dt);
        return *this;
    }

    auto advance_frame() noexcept -> auto& {
        ++_frame_no;
        _old_user_idle = _new_user_idle;
        _new_user_idle = true;
        return *this;
    }

private:
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
