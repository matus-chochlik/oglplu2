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

namespace oglplus {
//------------------------------------------------------------------------------
example_state_view::
example_state_view(void)
noexcept
 : _width(1)
 , _height(1)
 , _depth(1)
 , _mouse_x(0)
 , _mouse_y(0)
 , _mouse_z(0)
 , _mouse_btn{{false},{false},{false},{false}}
 , _exe_time(0.0f)
 , _usr_act_time(0)
 , _frame_no(0)
 , _x_tiles(1)
 , _tile_i(0)
 , _y_tiles(1)
 , _tile_j(0)
 , _old_user_idle(false)
 , _new_user_idle(false)
{ }
//------------------------------------------------------------------------------
bool
example_state_view::
_notice_user_activity(bool something_changed)
noexcept {
	if(something_changed) {
		_usr_act_time = _exe_time;
		_new_user_idle = false;
	}
	return something_changed;
}
//------------------------------------------------------------------------------
example_state_value<bool>
example_state_view::
mouse_button_pressed(int button) const
noexcept {
	if((button >= 0) && (button < _mouse_btn_count)) {
		return _mouse_btn[button];
	}
	return {false, false};
}
//------------------------------------------------------------------------------
bool
example_state_view::
pointer_dragging(int index) const
noexcept {
	if(index == 0) {
		return _mouse_btn[0];
	}
	// TODO
	return false;
}
//------------------------------------------------------------------------------
example_state_value<float>
example_state_view::
norm_pointer_x(int index) const
noexcept {
	if(index == 0) {
		return mouse_x().as<float>() / width();
	}
	return {0.5f, 0.5f};
}
//------------------------------------------------------------------------------
example_state_value<float>
example_state_view::
norm_pointer_y(int index) const
noexcept {
	if(index == 0) {
		return mouse_y().as<float>() / height();
	}
	return {0.5f, 0.5f};
}
//------------------------------------------------------------------------------
example_state_value<float>
example_state_view::
norm_pointer_z(int index) const
noexcept {
	if(index == 0) {
		return mouse_z().as<float>() / depth();
	}
	return {0.0f, 0.0f};
}
//------------------------------------------------------------------------------
example_state_value<float>
example_state_view::
ndc_pointer_x(int index) const
noexcept {
	auto norm = norm_pointer_x(index);
	return {-1.f + 2.f*norm.old_value(), -1.f + 2.f*norm.value()};
}
//------------------------------------------------------------------------------
example_state_value<float>
example_state_view::
ndc_pointer_y(int index) const
noexcept {
	auto norm = norm_pointer_y(index);
	return {-1.f + 2.f*norm.old_value(), -1.f + 2.f*norm.value()};
}
//------------------------------------------------------------------------------
} // namespace oglplus
