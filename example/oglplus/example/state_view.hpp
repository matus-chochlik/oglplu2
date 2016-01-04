/**
 *  .file oglplus/example/state_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_VIEW_1512120710_HPP
#define OGLPLUS_EXAMPLE_STATE_VIEW_1512120710_HPP

#include <oglplus/utils/quantities.hpp>
#include <cassert>

namespace oglplus {

class example_state_view
{
protected:
	static constexpr const bool _old = true;

	float _old_time;
	float _new_time;
	float _usr_act_time;

	int _frame_no;

	int _old_width;
	int _old_height;
	int _old_depth;
	int _new_width;
	int _new_height;
	int _new_depth;

	int _old_mouse_x;
	int _old_mouse_y;
	int _old_mouse_z;
	int _new_mouse_x;
	int _new_mouse_y;
	int _new_mouse_z;

	bool _old_mouse_btn_1 : 1;
	bool _new_mouse_btn_1 : 1;
	bool _old_mouse_btn_2 : 1;
	bool _new_mouse_btn_2 : 1;
	bool _old_mouse_btn_3 : 1;
	bool _new_mouse_btn_3 : 1;
	bool _old_mouse_btn_4 : 1;
	bool _new_mouse_btn_4 : 1;

	bool _mouse_btn(int i, bool old = false) const
	noexcept;

	void _set_mouse_btn(int i, bool state)
	noexcept;

	bool _old_user_idle : 1;
	bool _new_user_idle : 1;

	example_state_view(void)
	noexcept;
public:

	seconds_t<float> exec_time(void) const
	noexcept
	{
		return seconds_(_new_time);
	}

	seconds_t<float> user_activity_time(void) const
	noexcept
	{	
		return seconds_(_usr_act_time);
	}

	seconds_t<float> user_idle_time(void) const
	noexcept
	{	
		return exec_time() - user_activity_time();
	}

	bool user_idle(bool old = false) const
	noexcept
	{
		return old?_old_user_idle:_new_user_idle;
	}

	bool user_became_idle(void) const
	noexcept
	{
		return !user_idle(_old) && user_idle();
	}

	bool user_became_active(void) const
	noexcept
	{
		return user_idle(_old) && !user_idle();
	}

	seconds_t<float> frame_duration(void) const
	noexcept
	{
		return seconds_(_new_time - _old_time);
	}

	int frame_number(void) const
	noexcept
	{
		return _frame_no;
	}

	int width(bool old = false) const
	noexcept
	{
		return old?_old_width:_new_width;
	}

	int height(bool old = false) const
	noexcept
	{
		return old?_old_height:_new_height;
	}

	int depth(bool old = false) const
	noexcept
	{
		return old?_old_depth:_new_depth;
	}

	int delta_width(void) const
	noexcept
	{
		return width() - width(_old);
	}

	int delta_height(void) const
	noexcept
	{
		return height()- height(_old);
	}

	float aspect(bool old = false) const
	noexcept
	{
		return float(width(old))/float(height(old));
	}

	int mouse_x(bool old = false) const
	noexcept
	{
		return old?_old_mouse_x:_new_mouse_x;
	}

	int mouse_y(bool old = false) const
	noexcept
	{
		return old?_old_mouse_y:_new_mouse_y;
	}

	int mouse_z(bool old = false) const
	noexcept
	{
		return old?_old_mouse_z:_new_mouse_z;
	}

	int delta_mouse_x(void) const
	noexcept
	{
		return mouse_x() - mouse_x(_old);
	}

	int delta_mouse_y(void) const
	noexcept
	{
		return mouse_y() - mouse_y(_old);
	}

	int delta_mouse_z(void) const
	noexcept
	{
		return mouse_z() - mouse_z(_old);
	}

	bool pointer_dragging(int index = 0) const
	noexcept;

	float norm_pointer_x(int index = 0, bool old = false) const
	noexcept;

	float norm_pointer_y(int index = 0, bool old = false) const
	noexcept;

	float norm_pointer_z(int index = 0, bool old = false) const
	noexcept;

	float norm_delta_pointer_x(int index = 0) const
	noexcept;

	float norm_delta_pointer_y(int index = 0) const
	noexcept;

	float norm_delta_pointer_z(int index = 0) const
	noexcept;

	float ndc_pointer_x(int index = 0, bool old = false) const
	noexcept;

	float ndc_pointer_y(int index = 0, bool old = false) const
	noexcept;

	float pointer_radius(int index = 0, bool old = false) const
	noexcept;

	float delta_pointer_radius(int index = 0) const
	noexcept;

	radians_t<float> pointer_angle(int index = 0, bool old = false) const
	noexcept;

	radians_t<float> delta_pointer_angle(int index = 0) const
	noexcept;
};

class example_state;

} // namespace oglplus

#endif
