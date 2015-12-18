/**
 *  .file oglplus/example_state_view.hpp
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

	int _frame_no;

	int _old_width;
	int _old_height;
	int _new_width;
	int _new_height;

	int _old_mouse_x;
	int _old_mouse_y;
	int _new_mouse_x;
	int _new_mouse_y;

	bool _old_mouse_btn_1 : 1;
	bool _new_mouse_btn_1 : 1;
	bool _old_mouse_btn_2 : 1;
	bool _new_mouse_btn_2 : 1;
	bool _old_mouse_btn_3 : 1;
	bool _new_mouse_btn_3 : 1;
	bool _old_mouse_btn_4 : 1;
	bool _new_mouse_btn_4 : 1;

	bool _mouse_btn(int i, bool old)
	noexcept;

	bool _set_mouse_btn(int i, bool state, bool old)
	noexcept;

	example_state_view(void)
	noexcept;
public:

	seconds_t<float> exec_time(void) const
	noexcept
	{
		return seconds(_new_time);
	}

	seconds_t<float> frame_duration(void) const
	noexcept
	{
		return seconds(_new_time - _old_time);
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

	float norm_mouse_x(bool old = false) const
	noexcept
	{
		assert(width() > 0);
		return float(mouse_x(old)) / width();
	}

	float norm_mouse_y(bool old = false) const
	noexcept
	{
		assert(height() > 0);
		return float(mouse_y(old)) / height();
	}

	float norm_delta_mouse_x(void) const
	noexcept
	{
		assert(width() > 0);
		return float(delta_mouse_x()) / width();
	}

	float norm_delta_mouse_y(void) const
	noexcept
	{
		assert(height() > 0);
		return float(delta_mouse_y()) / height();
	}

	float ndc_mouse_x(bool old = false) const
	noexcept
	{
		return -1.f + 2*norm_mouse_x(old);
	}

	float ndc_mouse_y(bool old = false) const
	noexcept
	{
		return -1.f + 2*norm_mouse_y(old);
	}

	float mouse_radius(bool old = false) const
	noexcept;

	float delta_mouse_radius(void) const
	noexcept
	{
		return mouse_radius() - mouse_radius(_old);
	}

	radians_t<float> mouse_angle(bool old = false) const
	noexcept;

	radians_t<float> delta_mouse_angle(void) const
	noexcept
	{
		return mouse_angle() - mouse_angle(_old);
	}
};

class example_state;

} // namespace oglplus

#endif
