/**
 *  .file oglplus/example/args.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "args.hpp"
#include <eagine/program_args.hpp>

namespace oglplus {

bool
example_arg::operator == (const example_param_tags& tags) const
noexcept
{
	return _arg == tags._stag || _arg == tags._ltag;
}

int
example_args::argc(void) const
noexcept
{
	return _args.argc();
}

const char**
example_args::argv(void) const
noexcept
{
	return _args.argv();
}

cstr_ref
example_args::command(void) const
noexcept
{
	return _args.command();
}

template <typename T>
bool
example_args::_parse_param(example_param<T>& param) const
{
	eagine::program_parameter<T> temp(param._stag,param._ltag,param._value);
	if(_args.parse_param(temp, _errlog))
	{
		param._value = temp.value();
	}
	return false;
}

bool
example_args::
parse_param(example_string_param& param) const
{
	return _parse_param(param);
}

} // namespace oglplus

