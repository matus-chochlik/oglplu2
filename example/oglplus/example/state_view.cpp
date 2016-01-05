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

example_state_view::
example_state_view(void)
noexcept
 : _old_time(0)
 , _new_time(0)
 , _usr_act_time(0)
 , _frame_no(0)
 , _x_tiles(1)
 , _tile_i(0)
 , _y_tiles(1)
 , _tile_j(0)
 , _old_width(1)
 , _old_height(1)
 , _old_depth(1)
 , _new_width(1)
 , _new_height(1)
 , _new_depth(1)
 , _old_mouse_x(0)
 , _old_mouse_y(0)
 , _old_mouse_z(0)
 , _new_mouse_x(0)
 , _new_mouse_y(0)
 , _new_mouse_z(0)
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

bool
example_state_view::
_mouse_btn(int i, bool old) const
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

void
example_state_view::
_set_mouse_btn(int i, bool pressed)
noexcept
{
	switch(i)
	{
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

bool
example_state_view::
pointer_dragging(int index) const
noexcept
{
	if(index == 0)
	{
		return _mouse_btn(1);
	}
	// TODO
	return false;
}

float
example_state_view::
norm_pointer_x(int index, bool old) const
noexcept
{
	assert(width() > 0);
	if(index == 0)
	{
		return float(mouse_x(old)) / width();
	}
	// TODO
	return 0.5f;
}

float
example_state_view::
norm_pointer_y(int index, bool old) const
noexcept
{
	assert(height() > 0);
	if(index == 0)
	{
		return float(mouse_y(old)) / height();
	}
	// TODO
	return 0.5f;
}

float
example_state_view::
norm_pointer_z(int index, bool old) const
noexcept
{
	assert(depth() > 0);
	if(index == 0)
	{
		return float(mouse_z(old)) / depth();
	}
	// TODO
	return 0.5f;
}

float
example_state_view::
norm_delta_pointer_x(int index) const
noexcept
{
	assert(width() > 0);
	if(index == 0)
	{
		return float(delta_mouse_x()) / width();
	}
	// TODO
	return 0;
}

float
example_state_view::
norm_delta_pointer_y(int index) const
noexcept
{
	assert(height() > 0);
	if(index == 0)
	{
		return float(delta_mouse_y()) / height();
	}
	// TODO
	return 0;
}

float
example_state_view::
norm_delta_pointer_z(int index) const
noexcept
{
	assert(depth() > 0);
	if(index == 0)
	{
		return float(delta_mouse_z()) / depth();
	}
	// TODO
	return 0;
}

float
example_state_view::
ndc_pointer_x(int index, bool old) const
noexcept
{
	return -1.f + 2*norm_pointer_x(index, old);
}

float
example_state_view::
ndc_pointer_y(int index, bool old) const
noexcept
{
	return -1.f + 2*norm_pointer_y(index, old);
}

float
example_state_view::
pointer_radius(int index, bool old) const
noexcept
{
	using std::sqrt;
	using std::pow;
	return float(sqrt(
		pow(ndc_pointer_x(index, old), 2)+
		pow(ndc_pointer_y(index, old), 2)
	));
}

float
example_state_view::
delta_pointer_radius(int index) const
noexcept
{
	return pointer_radius(index) - pointer_radius(index, _old);
}

radians_t<float>
example_state_view::
pointer_angle(int index, bool old) const
noexcept
{
	return arctan(
		ndc_pointer_y(index, old),
		ndc_pointer_x(index, old)
	);
}

radians_t<float>
example_state_view::
delta_pointer_angle(int index) const
noexcept
{
	return pointer_angle(index) - pointer_angle(index, _old);
}

} // namespace oglplus
