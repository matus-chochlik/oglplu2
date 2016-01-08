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
#include <oglplus/gl_fixed.hpp>
#include <oglplus/utils/span.hpp>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

namespace oglplus {

std::vector<char>&
example_wrapper::
pixels(void)
{
	std::size_t size = std::size_t(_state.height()* _state.width()*4);

	if(_pixel_data.size() < size)
	{
		_pixel_data.resize(size);
	}

	return _pixel_data;
}

std::vector<char>&
example_wrapper::
textbuf(std::size_t size)
{
	if(_textbuf.size() < size)
	{
		_textbuf.resize(size);
	}

	return _textbuf;
}

example_wrapper::
example_wrapper(example_params& params, example_state& state)
 : _params(params)
 , _state(state)
 , _example(make_example(_params, _state))
 , _screenshot_done(false)
 , _start(clock_type::now())
 , _now(_start)
{
	assert(_example);

	_state.sync_size();
	_example->resize(_state);

	_state.center_mouse();
	_example->pointer_motion(_state);

	if(_params.doing_framedump())
	{
		textbuf(1024);
		std::cin.getline(
			_textbuf.data(),
			std::streamsize(_textbuf.size())
		);

		if(std::strncmp(
			_params.framedump_prefix().c_str(),
			_textbuf.data(),
			_textbuf.size()
		) != 0)
		{
			throw std::runtime_error(
				"Expected frame-dump prefix on stdin"
			);
		}
	}

	if(_state.multiple_tiles() && _params.auto_tiles())
	{
		glEnable(GL_SCISSOR_TEST);
	}
}


void example_wrapper::destroy(void)
{
	_example.reset();
}

bool example_wrapper::next_frame(void)
{
	assert(_example);

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
	
	if(_params.doing_screenshot())
	{
		return !_screenshot_done;
	}
	else
	{
		return _example->continue_running(_state);
	}
}

void example_wrapper::update(void)
{
	assert(_example);

	if(_state.user_idle())
	{
		_example->user_idle(_state);
	}
}

void example_wrapper::render(void)
{
	assert(_example);

	bool save_frame = _params.doing_framedump();
	save_frame |= _params.doing_screenshot() &&
		(_state.exec_time() >= _params.screenshot_time());

	if(_state.multiple_tiles())
	{
		assert(_state.first_tile());
		do {
			if(_params.auto_tiles())
			{
				glScissor(
					_state.tile_x(),
					_state.tile_y(),
					_state.tile_w(),
					_state.tile_h()
				);
			}

			_example->render(_state);
			glFlush();
			
		} while(!_state.next_tile());
	}
	else _example->render(_state);

	if(save_frame)
	{
		glReadPixels(
			0, 0,
			GLsizei(_state.width()),
			GLsizei(_state.height()),
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			pixels().data()
		);

		std::stringstream filename;

		if(_params.doing_framedump())
		{
			filename <<
				_params.framedump_prefix() <<
				std::setfill('0') << std::setw(6) <<
				_state.frame_number() << ".rgba";
		}
		else if(_params.doing_screenshot())
		{
			filename << _params.screenshot_path();
		}

		std::ofstream file(filename.str());
		file.write(pixels().data(), std::streamsize(pixels().size()));
		file.flush();

		if(_params.doing_framedump())
		{
			std::cout << filename.str() << std::endl;
			textbuf(filename.str().size()+1);

			std::cin.getline(
				_textbuf.data(),
				std::streamsize(_textbuf.size())
			);

			if(std::strncmp(
				filename.str().c_str(),
				_textbuf.data(),
				_textbuf.size()
			) != 0)
			{
				throw std::runtime_error(
					"Expected frame-dump filepath on stdin."
				);
			}
		}
		else if(_params.doing_screenshot())
		{
			_screenshot_done = true;
		}
	}
}

void example_wrapper::set_size(int width, int height)
{
	assert(_example);

	if(_state.set_size(width, height))
	{
		_example->resize(_state);
	}
}

void example_wrapper::set_mouse_btn(int i, bool pressed)
{
	assert(_example);

	if(_state.set_mouse_btn(i, pressed))
	{
		// TODO
		//_example->mouse_button(_state);
	}
}

void example_wrapper::set_mouse_pos(int x, int y)
{
	assert(_example);

	if(_state.set_mouse_pos(x, y))
	{
		_example->pointer_motion(_state);
	}
}

void example_wrapper::set_mouse_wheel(int w)
{
	assert(_example);

	if(_state.set_mouse_wheel(w))
	{
		_example->pointer_scrolling(_state);
	}
}

} // namespace oglplus
