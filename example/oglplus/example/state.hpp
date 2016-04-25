/**
 *  .file oglplus/example/state.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_1512120710_HPP
#define OGLPLUS_EXAMPLE_STATE_1512120710_HPP

#include "state_view.hpp"
#include <cmath>
#include <cassert>

namespace oglplus {

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
		_old_user_idle = _new_user_idle;
		_new_user_idle = true;
	}

	bool set_width(valid_if_positive<int> new_width)
	noexcept
	{
		_old_width = _new_width;
		if(_new_width != new_width.value())
		{
			_new_width =  new_width.value();
			_usr_act_time = _new_time;
			_new_user_idle = false;
			return true;
		}
		return false;
	}

	bool set_height(valid_if_positive<int> new_height)
	noexcept
	{
		_old_height = _new_height;
		if(_new_height != new_height.value())
		{
			_new_height =  new_height.value();
			_usr_act_time = _new_time;
			_new_user_idle = false;
			return true;
		}
		return false;
	}

	bool set_depth(valid_if_positive<int> new_depth)
	noexcept
	{
		_old_depth = _new_depth;
		if(_new_depth != new_depth.value())
		{
			_new_depth =  new_depth.value();
			_usr_act_time = _new_time;
			_new_user_idle = false;
			return true;
		}
		return false;
	}

	void set_tiles(int x, int y)
	noexcept
	{
		if(x < 1) x = 1;
		if(y < 1) y = 1;

		_x_tiles = x;
		_y_tiles = y;
		_tile_i = 0;
		_tile_j = 0;
	}

	bool first_tile(void)
	noexcept
	{
		return (_tile_i == 0) && (_tile_j == 0);
	}

	bool next_tile(void)
	noexcept
	{
		if(multiple_tiles())
		{
			if(++_tile_i >= _x_tiles)
			{
				_tile_i = 0;
				if(++_tile_j >= _y_tiles)
				{
					_tile_j = 0;
				}
			}
		}
		return first_tile();
	}

	bool set_size(
		valid_if_positive<int> new_width,
		valid_if_positive<int> new_height
	) noexcept
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
		_old_depth = _new_depth;
	}

	bool set_mouse_btn(int button, bool pressed)
	noexcept
	{
		if(_mouse_btn(button) != pressed)
		{
			_set_mouse_btn(button, pressed);
			_usr_act_time = _new_time;
			_new_user_idle = false;
			return true;
		}
		return false;
	}

	bool set_mouse_pos(int new_mouse_x, int new_mouse_y)
	noexcept
	{
		bool result = false;

		if(new_mouse_x < 0) new_mouse_x = 0;
		if(new_mouse_x > _new_width) new_mouse_x = _new_width;
		if(new_mouse_y < 0) new_mouse_y = 0;
		if(new_mouse_y > _new_height) new_mouse_y = _new_height;

		_old_mouse_x = _new_mouse_x;
		if(_new_mouse_x != new_mouse_x)
		{
			_new_mouse_x =  new_mouse_x;
			_usr_act_time = _new_time;
			_new_user_idle = false;
			result = true;
		}

		_old_mouse_y = _new_mouse_y;
		if(_new_mouse_y != new_mouse_y)
		{
			_new_mouse_y =  new_mouse_y;
			_usr_act_time = _new_time;
			_new_user_idle = false;
			result = true;
		}

		return result;
	}

	bool set_mouse_wheel(int new_mouse_z)
	noexcept
	{
		_old_mouse_z = _new_mouse_z;
		if(_new_mouse_z != new_mouse_z)
		{
			_new_mouse_z =  new_mouse_z;
			_usr_act_time = _new_time;
			_new_user_idle = false;
			return true;
		}
		return false;
	}

	void center_mouse(void)
	noexcept
	{
		_old_mouse_x = _new_mouse_x = width()/2;
		_old_mouse_y = _new_mouse_y = height()/2;
		_old_mouse_z = _new_mouse_z = 0;
	}
};

} // namespace oglplus

#endif
