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

	example_state_view(void)
	noexcept
	 : _old_time(0.0)
	 , _new_time(0.0)
	 , _frame_no(0)
	 , _old_width(1)
	 , _old_height(1)
	 , _new_width(1)
	 , _new_height(1)
	{ }
public:

	float time(void) const
	noexcept
	{
		return _new_time;
	}

	float delta_time(void) const
	noexcept
	{
		return _new_time - _old_time;
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
			_new_width = new_width;
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
			_new_height = new_height;
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
};

} // namespace oglplus

#endif
