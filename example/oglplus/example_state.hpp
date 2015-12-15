/**
 *  .file oglplus/example_state.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_1512120710_HPP
#define OGLPLUS_EXAMPLE_STATE_1512120710_HPP

#include <oglplus/utils/quantities.hpp>
#include <cassert>

namespace oglplus {

class example_state_view
{
protected:
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

	seconds_t<float> frame_time(void) const
	noexcept
	{
		return seconds(_new_time - _old_time);
	}

	int frame_number(void) const
	noexcept
	{
		return _frame_no;
	}

	int width(void) const
	noexcept
	{
		return _new_width;
	}

	int delta_width(void) const
	noexcept
	{
		return _new_width - _old_width;
	}

	int height(void) const
	noexcept
	{
		return _new_height;
	}

	int delta_height(void) const
	noexcept
	{
		return _new_height- _old_height;
	}

	float aspect(void) const
	noexcept
	{
		return float(width())/float(height());
	}

	int mouse_x(void) const
	noexcept
	{
		return _new_mouse_x;
	}

	int mouse_y(void) const
	noexcept
	{
		return _new_mouse_y;
	}

	int delta_mouse_x(void) const
	noexcept
	{
		return _new_mouse_x - _old_mouse_x;
	}

	int delta_mouse_y(void) const
	noexcept
	{
		return _new_mouse_y - _old_mouse_y;
	}

	float norm_mouse_x(void) const
	noexcept
	{
		assert(width() > 0);
		return float(mouse_x()) / width();
	}

	float norm_mouse_y(void) const
	noexcept
	{
		assert(height() > 0);
		return float(mouse_y()) / height();
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

	float ndc_mouse_x(void) const
	noexcept
	{
		return -1.f + 2*norm_mouse_x();
	}

	float ndc_mouse_y(void) const
	noexcept
	{
		return -1.f + 2*norm_mouse_y();
	}
};

class example_state
 : public example_state_view
{
public:
	void set_time(float new_time)
	noexcept
	{
		assert(new_time >= 0.0);
		_old_time = _new_time;
		_new_time = new_time;
	}

	void advance_time(float dt)
	noexcept
	{
		_old_time = _new_time;
		_new_time += dt;
	}

	void advance_frame(void)
	noexcept
	{
		++_frame_no;
	}

	bool set_width(int new_width)
	noexcept
	{
		if(new_width < 1) new_width = 1;

		if(_new_width != new_width)
		{
			_old_width = _new_width;
			_new_width =  new_width;
			return true;
		}
		return false;
	}

	bool set_height(int new_height)
	noexcept
	{
		if(new_height < 1) new_height = 1;

		if(_new_height != new_height)
		{
			_old_height = _new_height;
			_new_height =  new_height;
			return true;
		}
		return false;
	}

	bool set_size(int new_width, int new_height)
	noexcept
	{
		bool ws = set_width(new_width);
		bool hs = set_height(new_height);

		return ws || hs;
	}

	void sync_size(void)
	noexcept
	{
		_old_width = _new_width;
		_old_height = _new_height;
	}

	bool set_mouse_pos(int new_mouse_x, int new_mouse_y)
	noexcept
	{
		bool result = false;

		if(new_mouse_x < 0) new_mouse_x = 0;
		if(new_mouse_x > _new_width) new_mouse_x = _new_width;
		if(new_mouse_y < 0) new_mouse_y = 0;
		if(new_mouse_y > _new_height) new_mouse_y = _new_height;

		if(_new_mouse_x != new_mouse_x)
		{
			_old_mouse_x = _new_mouse_x;
			_new_mouse_x =  new_mouse_x;
			result = true;
		}

		if(_new_mouse_y != new_mouse_y)
		{
			_old_mouse_y = _new_mouse_y;
			_new_mouse_y =  new_mouse_y;
			result = true;
		}

		return result;
	}

	void center_mouse(void)
	noexcept
	{
		_old_mouse_x = _new_mouse_x = width()/2;
		_old_mouse_y = _new_mouse_y = height()/2;
	}
};

} // namespace oglplus

#endif
