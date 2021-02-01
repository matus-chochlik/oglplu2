/**
 *  .file oglplus/example/state_view.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "state_view.hpp"
#include <cmath>

namespace eagine {
//------------------------------------------------------------------------------
auto example_state_view::_notice_user_activity(bool something_changed) noexcept
  -> bool {
    if(something_changed) {
        _usr_act_time = _exe_time;
        _new_user_idle = false;
    }
    return something_changed;
}
//------------------------------------------------------------------------------
auto example_state_view::mouse_button_pressed(int button) const noexcept
  -> example_state_value<bool> {
    if((button >= 0) && (button < _mouse_btn_count)) {
        return _mouse_btn[button];
    }
    return {false, false};
}
//------------------------------------------------------------------------------
auto example_state_view::pointer_dragging(int index) const noexcept -> bool {
    if(index == 0) {
        return _mouse_btn[0];
    }
    // TODO
    return false;
}
//------------------------------------------------------------------------------
auto example_state_view::norm_pointer_x(int index) const noexcept
  -> example_state_value<float> {
    if(index == 0) {
        return mouse_x().as<float>() / width();
    }
    return {0.5F, 0.5F};
}
//------------------------------------------------------------------------------
auto example_state_view::norm_pointer_y(int index) const noexcept
  -> example_state_value<float> {
    if(index == 0) {
        return mouse_y().as<float>() / height();
    }
    return {0.5F, 0.5F};
}
//------------------------------------------------------------------------------
auto example_state_view::norm_pointer_z(int index) const noexcept
  -> example_state_value<float> {
    if(index == 0) {
        return mouse_z().as<float>() / depth();
    }
    return {0.0F, 0.0F};
}
//------------------------------------------------------------------------------
auto example_state_view::ndc_pointer_x(int index) const noexcept
  -> example_state_value<float> {
    return transform(
      [](float v) { return -1.F + 2.F * v; }, norm_pointer_x(index));
}
//------------------------------------------------------------------------------
auto example_state_view::ndc_pointer_y(int index) const noexcept
  -> example_state_value<float> {
    return transform(
      [](float v) { return -1.F + 2.F * v; }, norm_pointer_y(index));
}
//------------------------------------------------------------------------------
auto example_state_view::pointer_radius(int index) const noexcept
  -> example_state_value<float> {
    using std::pow;
    using std::sqrt;
    return transform(
      [](float x, float y) { return float(sqrt(pow(x, 2.F) + pow(y, 2.F))); },
      ndc_pointer_x(index),
      ndc_pointer_y(index));
}
//------------------------------------------------------------------------------
auto example_state_view::pointer_angle(int index) const noexcept
  -> example_state_value<radians_t<float>> {
    return transform(
      [](float x, float y) { return arctan(y, x); },
      ndc_pointer_x(index),
      ndc_pointer_y(index));
}
//------------------------------------------------------------------------------
} // namespace eagine
