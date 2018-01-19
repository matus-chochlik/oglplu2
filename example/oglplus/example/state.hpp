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
private:
	template <typename T>
	T _clamp(T value, T min, T max)
	noexcept {
		if(value < min) value = min;
		if(value > max) value = max;
		return value;
	}
public:
	void set_time(float new_time)
	noexcept {
		assert(new_time >= 0.0f);
		_exe_time.assign(new_time);
	}

	void advance_time(float dt)
	noexcept {
		_exe_time.advance(dt);
	}

	void advance_frame(void)
	noexcept {
		++_frame_no;
		_old_user_idle = _new_user_idle;
		_new_user_idle = true;
	}

	bool set_width(eagine::valid_if_positive<int> new_width)
	noexcept {
		return _notice_user_activity(_width.assign(new_width));
	}

	bool set_height(eagine::valid_if_positive<int> new_height)
	noexcept {
		return _notice_user_activity(_height.assign(new_height));
	}

	bool set_depth(eagine::valid_if_positive<int> new_depth)
	noexcept {
		return _notice_user_activity(_depth.assign(new_depth));
	}

	void set_tiles(int x, int y)
	noexcept {
		if(x < 1) x = 1;
		if(y < 1) y = 1;

		_x_tiles = x;
		_y_tiles = y;
		_tile_i = 0;
		_tile_j = 0;
	}

	bool first_tile(void)
	noexcept {
		return (_tile_i == 0) && (_tile_j == 0);
	}

	bool next_tile(void)
	noexcept {
		if(multiple_tiles()) {
			if(++_tile_i >= _x_tiles) {
				_tile_i = 0;
				if(++_tile_j >= _y_tiles) {
					_tile_j = 0;
				}
			}
		}
		return first_tile();
	}

	bool set_size(
		eagine::valid_if_positive<int> new_width,
		eagine::valid_if_positive<int> new_height
	) noexcept {
		// intentional to bypass short circuiting
		bool ws = set_width(new_width);
		bool hs = set_height(new_height);

		return ws || hs;
	}

	void sync_size(void)
	noexcept {
		_width.sync();
		_height.sync();
		_depth.sync();
	}

	bool set_mouse_btn(int button, bool pressed)
	noexcept {
		if(_mouse_btn(button) != pressed) {
			_set_mouse_btn(button, pressed);
			_notice_user_activity();
			return true;
		}
		return false;
	}

	bool set_mouse_pos(int new_mouse_x, int new_mouse_y)
	noexcept {
		return _notice_user_activity(
			_mouse_x.assign(_clamp(new_mouse_x, 0, _width.value())) ||
			_mouse_y.assign(_clamp(new_mouse_y, 0, _height.value()))
		);
	}

	bool set_mouse_wheel(int new_mouse_z)
	noexcept {
		return _notice_user_activity(_mouse_z.assign(new_mouse_z));
	}

	void center_mouse(void)
	noexcept {
		_mouse_x.assign(width()/2);
		_mouse_x.sync();
		_mouse_y.assign(height()/2);
		_mouse_y.sync();
		_mouse_z.assign(0);
		_mouse_z.sync();
	}
};

} // namespace oglplus

#endif
