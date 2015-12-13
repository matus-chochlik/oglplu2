/**
 *  .file oglplus/example_wrapper.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_WRAPPER_1512120710_HPP
#define OGLPLUS_EXAMPLE_WRAPPER_1512120710_HPP

#include "example.hpp"
#include <cassert>
#include <chrono>

namespace oglplus {

class example_wrapper
{
private:
	typedef std::chrono::system_clock clock_type;
	const std::chrono::time_point<clock_type> _start;
	std::chrono::time_point<clock_type> _now;

	example_params& _params;
	example_state& _state;

	std::unique_ptr<example> _example;
public:
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
	}

	bool next_frame(void)
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

	void render(void)
	{
		_example->render(_state);
	}

	void set_size(int width, int height)
	{
		if(_state.set_size(width, height))
		{
			_example->resize(_state);
		}
	}
};

} // namespace oglplus

#endif
