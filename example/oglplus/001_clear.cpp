/**
 *  example oglplus/001_clear.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>

// TODO fixed gl version/extension
#undef GL_ARB_compatibility

#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>

#include "example.hpp"

namespace oglplus {

class example_clear
 : public example
{
private:
	constants  GL;
	operations gl;
public:
	void resize(const example_state_view& state)
	override
	{
		gl.viewport(0, 0, state.width(), state.height());
	}

	void render(const example_state_view& state)
	override
	{
		int sec = int(state.time());

		gl.clear_color(
			(sec%3==0)?1:0,
			(sec%3==1)?1:0,
			(sec%3==2)?1:0,
			0.0f
		);

		gl.clear(GL.color_buffer_bit);
	}
};

std::unique_ptr<example>
make_example(const example_params&, const example_state&)
{
	return std::unique_ptr<example>(new example_clear());
}

void adjust_params(example_params& params)
{
	params.depth_bits(0);
	params.stencil_bits(0);
}

} // namespace oglplus
