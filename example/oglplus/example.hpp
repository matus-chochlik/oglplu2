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

#include "example_state.hpp"
#include "example_params.hpp"
#include <memory>

namespace oglplus {

struct example
{
	virtual
	~example(void) = default;

	virtual
	bool continue_running(const example_state_view& state)
	{
		return state.time() < 10; //[sec]
	}

	virtual
	void resize(const example_state_view&) = 0;

	virtual
	void render(const example_state_view&) = 0;
};

extern
std::unique_ptr<example>
make_example(const example_params&, const example_state&);

} // namespace oglplus

#endif
