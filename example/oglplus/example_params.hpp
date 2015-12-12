/**
 *  .file oglplus/example_params.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_PARAMS_1512120710_HPP
#define OGLPLUS_EXAMPLE_PARAMS_1512120710_HPP

#include <oglplus/utils/cstr_ref.hpp>
#include <cassert>

namespace oglplus {

class example_params
{
private:
	cstr_ref _screenshot_path;

	int _color_bits;
	int _alpha_bits;
	int _depth_bits;
	int _stencil_bits;
public:
	example_params(void)
	noexcept
	 : _color_bits(8)
	 , _alpha_bits(0)
	 , _depth_bits(24)
	 , _stencil_bits(0)
	{ }

	void screenshot_path(cstr_ref screenshot_path)
	{
		_screenshot_path = screenshot_path;
	}

	bool screenshot_only(void) const
	noexcept
	{
		return !_screenshot_path.empty();
	}

	bool fixed_framerate(void) const
	noexcept
	{
		return screenshot_only();
	}

	double frame_time(void) const
	noexcept
	{
		// TODO
		return 1.0/25.0;
	}

	cstr_ref screenshot_path(void) const
	noexcept
	{
		return _screenshot_path;
	}

	void color_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_color_bits = n;
	}

	int color_bits(void) const
	noexcept
	{
		return _color_bits;
	}

	void alpha_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_alpha_bits = n;
	}

	int alpha_bits(void) const
	noexcept
	{
		return _alpha_bits;
	}

	void depth_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_depth_bits = n;
	}

	int depth_bits(void) const
	noexcept
	{
		return _depth_bits;
	}

	void stencil_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_stencil_bits = n;
	}

	int stencil_bits(void) const
	noexcept
	{
		return _stencil_bits;
	}
};

extern
void adjust_params(example_params&);

} // namespace oglplus

#endif
