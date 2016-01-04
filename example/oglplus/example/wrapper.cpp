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
	bool finished_frame = true; // TODO tiles
	_example->render(_state);

	bool save_frame = _params.doing_framedump();

	if(finished_frame && save_frame)
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
	}

	return finished_frame; 
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
