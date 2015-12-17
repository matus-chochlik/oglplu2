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
#include <cmath>
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
	{ }
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
	noexcept
	{
		using std::sqrt;
		using std::pow;
		return float(sqrt(
			pow(ndc_mouse_x(old), 2)+
			pow(ndc_mouse_y(old), 2)
		));
	}

	float delta_mouse_radius(void) const
	noexcept
	{
		return mouse_radius() - mouse_radius(_old);
	}

	radians_t<float> mouse_angle(bool old = false) const
	noexcept
	{
		using std::atan2;
		return radians(atan2(ndc_mouse_y(old), ndc_mouse_x(old)));
	}

	radians_t<float> delta_mouse_angle(void) const
	noexcept
	{
		return mouse_angle() - mouse_angle(_old);
	}
};

class example_state;

} // namespace oglplus

#endif
