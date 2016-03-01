/**
 *  .file oglplus/example/args.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_ARGS_1512120710_HPP
#define OGLPLUS_EXAMPLE_ARGS_1512120710_HPP

#include <oglplus/utils/valid_if.hpp>
#include <oglplus/utils/cstr_ref.hpp>
#include <iosfwd>

namespace eagine {

class program_arg;
class program_args;

} // namespace eagine

namespace oglplus {

class example_arg;
class example_args;

class example_param_tags
{
protected:
	cstr_ref _stag;
	cstr_ref _ltag;

	friend class example_arg;
	friend class example_args;
public:
	example_param_tags(cstr_ref stag, cstr_ref ltag)
	noexcept
	 : _stag(stag)
	 , _ltag(ltag)
	{ }
};

template <typename T>
class example_param;

template <typename T, typename P>
class example_param<valid_if<T, P>>
 : public example_param_tags
{
private:
	valid_if<T, P> _value;

	friend class example_args;
public:
	example_param(cstr_ref stag, cstr_ref ltag, T initial)
	 : example_param_tags(stag, ltag)
	 , _value(initial)
	{ }

	operator const T& (void) const
	noexcept
	{
		return _value.value();
	}
};

typedef example_param<valid_if_not_empty<cstr_ref>> example_string_param;

class example_arg
{
private:
	const eagine::program_arg& _arg;
public:
	example_arg(const eagine::program_arg& arg)
	noexcept
	 : _arg(arg)
	{ }

	bool operator == (const example_param_tags& tags) const
	noexcept;
};

class example_args
{
private:
	const eagine::program_args& _args;
	std::ostream& _errlog;

	template <typename T>
	bool _parse_param(example_param<T>& param) const;
public:
	example_args(const eagine::program_args& args, std::ostream& log)
	noexcept
	 : _args(args)
	 , _errlog(log)
	{ }

	int argc(void) const
	noexcept;

	const char** argv(void) const
	noexcept;

	cstr_ref command(void) const
	noexcept;

	bool parse_param(example_string_param& param) const;
};

} // namespace oglplus

#endif
