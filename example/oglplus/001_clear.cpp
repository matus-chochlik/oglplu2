/**
 *  example oglplus/001_clear.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl_fixed.hpp>
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
		int sec = int(state.exec_time());

		gl.clear_color(
			(sec%3==0)?1.f:0.f,
			(sec%3==1)?1.f:0.f,
			(sec%3==2)?1.f:0.f,
			0.0f
		);

		gl.clear(GL.color_buffer_bit);
	}
};

std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params&,
	const example_state_view&
)
{
	return std::unique_ptr<example>(new example_clear());
}

void adjust_params(example_params& params)
{
	params.depth_buffer(false);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
