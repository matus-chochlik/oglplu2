/**
 *  .file oglplus/example/wrapper.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "wrapper.hpp"
#include "state.hpp"

namespace oglplus {

example_wrapper::
example_wrapper(example_params& params, example_state& state)
 : _start(clock_type::now())
 , _now(_start)
 , _params(params)
 , _state(state)
 , _example(make_example(_params, _state))
{
	assert(_example);

	_state.sync_size();
	_example->resize(_state);

	_state.center_mouse();
	_example->pointer_motion(_state);
}

bool example_wrapper::next_frame(void)
{
	_state.advance_frame();
	if(_params.fixed_framerate())
	{
		_state.advance_time(_params.frame_time());
	}
	else
	{
		static const float period =
			float(clock_type::period::num)/
			float(clock_type::period::den);
		_now = clock_type::now();
		_state.set_time((_now-_start).count() * period);
	}
	
	return _example->continue_running(_state);
}

void example_wrapper::update(void)
{
	if(_state.user_idle())
	{
		_example->user_idle(_state);
	}
}

bool example_wrapper::render(void)
{
	_example->render(_state);
	return true; // TODO tiles
}

void example_wrapper::set_size(int width, int height)
{
	if(_state.set_size(width, height))
	{
		_example->resize(_state);
	}
}

void example_wrapper::set_mouse_btn(int i, bool pressed)
{
	if(_state.set_mouse_btn(i, pressed))
	{
		// TODO
		//_example->mouse_button(_state);
	}
}

void example_wrapper::set_mouse_pos(int x, int y)
{
	if(_state.set_mouse_pos(x, y))
	{
		_example->pointer_motion(_state);
	}
}

void example_wrapper::set_mouse_wheel(int w)
{
	if(_state.set_mouse_wheel(w))
	{
		_example->pointer_scrolling(_state);
	}
}

} // namespace oglplus
