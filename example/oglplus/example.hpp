/**
 *  .file oglplus/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_1512120710_HPP
#define OGLPLUS_EXAMPLE_1512120710_HPP

#include "example/state_view.hpp"
#include "example/params.hpp"
#include "example/args.hpp"
#include <memory>

namespace oglplus {

struct example
{
	virtual
	~example(void) = default;

	virtual
	bool continue_running(const example_state_view& state)
	{
		return state.user_idle_time() < seconds_(10);
	}

	virtual
	void user_idle(const example_state_view&) { }

	virtual
	void pointer_motion(const example_state_view&) { }

	virtual
	void pointer_scrolling(const example_state_view&) { }

	virtual
	void resize(const example_state_view&) = 0;

	virtual
	void render(const example_state_view&) = 0;
};

extern
std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params&,
	const example_state_view&
);

extern
bool is_example_param(const example_arg&);

} // namespace oglplus

#endif
