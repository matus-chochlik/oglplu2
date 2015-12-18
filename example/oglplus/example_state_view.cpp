/**
 *  .file oglplus/example_state_view.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "example_state_view.hpp"
#include <cmath>

namespace oglplus {

example_state_view::
example_state_view(void)
noexcept
 : _old_time(0.0)
 , _new_time(0.0)
 , _frame_no(0)
 , _old_width(1)
 , _old_height(1)
 , _new_width(1)
 , _new_height(1)
 , _old_mouse_x(0)
 , _old_mouse_y(0)
 , _new_mouse_x(0)
 , _new_mouse_y(0)
 , _old_mouse_btn_1(false)
 , _new_mouse_btn_1(false)
 , _old_mouse_btn_2(false)
 , _new_mouse_btn_2(false)
 , _old_mouse_btn_3(false)
 , _new_mouse_btn_3(false)
 , _old_mouse_btn_4(false)
 , _new_mouse_btn_4(false)
{ }

bool example_state_view::_mouse_btn(int i, bool old)
noexcept
{
	switch(i)
	{
		case 1: return old?_old_mouse_btn_1:_new_mouse_btn_1;
		case 2: return old?_old_mouse_btn_2:_new_mouse_btn_2;
		case 3: return old?_old_mouse_btn_3:_new_mouse_btn_3;
		case 4: return old?_old_mouse_btn_4:_new_mouse_btn_4;
		default:;
	}
	return false;
}

bool example_state_view::_set_mouse_btn(int i, bool state, bool old)
noexcept
{
	if(_mouse_btn(i, old) == state)
	{
		return false;
	}
	if(old)
	{
		switch(i)
		{
			case 1: _old_mouse_btn_1 = state; break;
			case 2: _old_mouse_btn_2 = state; break;
			case 3: _old_mouse_btn_3 = state; break;
			case 4: _old_mouse_btn_4 = state; break;
			default: return false;
		}
	}
	else
	{
		switch(i)
		{
			case 1: _new_mouse_btn_1 = state; break;
			case 2: _new_mouse_btn_2 = state; break;
			case 3: _new_mouse_btn_3 = state; break;
			case 4: _new_mouse_btn_4 = state; break;
			default: return false;
		}
	}
	return true;
}

float example_state_view::mouse_radius(bool old) const
noexcept
{
	using std::sqrt;
	using std::pow;
	return float(sqrt(
		pow(ndc_mouse_x(old), 2)+
		pow(ndc_mouse_y(old), 2)
	));
}

radians_t<float> example_state_view::mouse_angle(bool old) const
noexcept
{
	using std::atan2;
	return radians(atan2(ndc_mouse_y(old), ndc_mouse_x(old)));
}

} // namespace oglplus
