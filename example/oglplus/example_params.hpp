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
#include <oglplus/utils/valid_if.hpp>
#include <cassert>

namespace oglplus {

class example_params
{
private:
	cstr_ref _screenshot_path;

	unsigned _rand_seed;

	int _samples;

	int _color_bits;
	int _alpha_bits;
	int _depth_bits;
	int _stencil_bits;
	bool _compat_ctxt;
public:
	example_params(void)
	noexcept
	 : _rand_seed(0)
	 , _samples(4)
	 , _color_bits(8)
	 , _alpha_bits(0)
	 , _depth_bits(24)
	 , _stencil_bits(0)
	 , _compat_ctxt(false)
	{ }

	example_params& screenshot_path(cstr_ref screenshot_path)
	{
		_screenshot_path = screenshot_path;
		return *this;
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

	float frame_time(void) const
	noexcept
	{
		// TODO
		return 1.0f/25.0f;
	}

	cstr_ref screenshot_path(void) const
	noexcept
	{
		return _screenshot_path;
	}

	example_params& rand_seed(unsigned seed)
	noexcept
	{
		_rand_seed = seed;
		return *this;
	}

	unsigned rand_seed(void) const
	noexcept
	{
		return _rand_seed;
	}

	example_params& compatibility_context(bool v)
	noexcept
	{
		_compat_ctxt = v;
		return *this;
	}

	bool compatibility_context(void) const
	noexcept
	{
		return _compat_ctxt;
	}

	example_params& samples(int n)
	noexcept
	{
		assert(n > 0);
		_samples = n;
		return *this;
	}

	example_params& samples_dont_care(void)
	noexcept
	{
		_samples = 0;
		return *this;
	}

	valid_if_greater_than<int, 0> samples(void) const
	noexcept
	{
		return _samples;
	}

	example_params& color_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_color_bits = n;
		return *this;
	}

	int color_bits(void) const
	noexcept
	{
		return _color_bits;
	}

	example_params& alpha_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_alpha_bits = n;
		return *this;
	}

	int alpha_bits(void) const
	noexcept
	{
		return _alpha_bits;
	}

	example_params& depth_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_depth_bits = n;
		return *this;
	}

	int depth_bits(void) const
	noexcept
	{
		return _depth_bits;
	}

	example_params& stencil_bits(int n)
	noexcept
	{
		assert(n >= 0);
		_stencil_bits = n;
		return *this;
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
