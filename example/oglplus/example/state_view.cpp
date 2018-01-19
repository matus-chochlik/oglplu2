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
 , _exe_time(0.0f)
 , _usr_act_time(0)
 , _frame_no(0)
 , _x_tiles(1)
 , _tile_i(0)
 , _y_tiles(1)
 , _tile_j(0)
 , _old_mouse_btn_1(false)
 , _new_mouse_btn_1(false)
 , _old_mouse_btn_2(false)
 , _new_mouse_btn_2(false)
 , _old_mouse_btn_3(false)
 , _new_mouse_btn_3(false)
 , _old_mouse_btn_4(false)
 , _new_mouse_btn_4(false)
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
bool
example_state_view::
_mouse_btn(int i, bool old) const
noexcept {
	switch(i) {
		case 1: return old?_old_mouse_btn_1:_new_mouse_btn_1;
		case 2: return old?_old_mouse_btn_2:_new_mouse_btn_2;
		case 3: return old?_old_mouse_btn_3:_new_mouse_btn_3;
		case 4: return old?_old_mouse_btn_4:_new_mouse_btn_4;
		default:;
	}
	return false;
}
//------------------------------------------------------------------------------
void
example_state_view::
_set_mouse_btn(int i, bool pressed)
noexcept {
	switch(i) {
		case 1:
			_old_mouse_btn_1 = _new_mouse_btn_1;
			_new_mouse_btn_1 = pressed;
			break;
		case 2:
			_old_mouse_btn_2 = _new_mouse_btn_2;
			_new_mouse_btn_2 = pressed;
			break;
		case 3:
			_old_mouse_btn_3 = _new_mouse_btn_3;
			_new_mouse_btn_3 = pressed;
			break;
		case 4:
			_old_mouse_btn_4 = _new_mouse_btn_4;
			_new_mouse_btn_4 = pressed;
			break;
		default:;
	}
}
//------------------------------------------------------------------------------
bool
example_state_view::
pointer_dragging(int index) const
noexcept {
	if(index == 0) {
		return _mouse_btn(1);
	}
	// TODO
	return false;
}
//------------------------------------------------------------------------------
example_state_variable_base<float>
example_state_view::
norm_pointer_x(int index) const
noexcept {
	if(index == 0) {
		return mouse_x().as<float>() / width();
	}
	return {0.5f, 0.5f};
}
//------------------------------------------------------------------------------
example_state_variable_base<float>
example_state_view::
norm_pointer_y(int index) const
noexcept {
	if(index == 0) {
		return mouse_y().as<float>() / height();
	}
	return {0.5f, 0.5f};
}
//------------------------------------------------------------------------------
example_state_variable_base<float>
example_state_view::
norm_pointer_z(int index) const
noexcept {
	if(index == 0) {
		return mouse_z().as<float>() / depth();
	}
	return {0.0f, 0.0f};
}
//------------------------------------------------------------------------------
} // namespace oglplus
