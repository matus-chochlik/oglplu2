/**
 *  @file eagine/program_args.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_PROGRAM_ARGS_1509260923_HPP
#define EAGINE_PROGRAM_ARGS_1509260923_HPP

#include "cstr_ref.hpp"
#include <cassert>

namespace eagine {

class program_args;

class program_arg
{
private:
	int _argi;
	int _argc;
	const char** _argv;

	program_arg(int argi, int argc, const char** argv)
	noexcept
	 : _argi(argi)
	 , _argc(argc)
	 , _argv(argv)
	{ }

	friend class program_args;
public:
	program_arg(void)
	noexcept
	 : _argi(0)
	 , _argc(0)
	 , _argv(nullptr)
	{ }

	typedef cstr_ref value_type;

	bool is_valid(void) const
	noexcept
	{
		return	(0 < _argi) && (_argi < _argc) &&
			(_argv != nullptr) && (_argv[_argi] != nullptr);
	}

	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
	}

	value_type get(void) const
	noexcept
	{
		if(is_valid())
		{
			return value_type(_argv[_argi]);
		}
		return value_type();
	}

	operator value_type (void) const
	noexcept
	{
		return get();
	}

	program_arg next(void) const
	noexcept
	{
		return program_arg(_argi+1, _argc, _argv);
	}

	program_arg prev(void) const
	noexcept
	{
		return program_arg(_argi-1, _argc, _argv);
	}

	bool operator == (const value_type& v) const
	noexcept
	{
		return get() == v;
	}

	bool operator != (const value_type& v) const
	noexcept
	{
		return get() != v;
	}
};

class program_args
{
private:
	int _argc;
	const char** _argv;
public:
	program_args(void)
	noexcept
	 : _argc(0)
	 , _argv(nullptr)
	{ }

	program_args(int argn, char** args)
	noexcept
	 : _argc(argn)
	 , _argv(const_cast<const char**>(args))
	{ }

	program_args(int argn, const char** args)
	noexcept
	 : _argc(argn)
	 , _argv(args)
	{ }

	typedef int size_type;
	typedef cstr_ref value_type;

	int argc(void) const
	noexcept
	{
		return _argc;
	}

	const char** argv(void) const
	noexcept
	{
		return _argv;
	}

	bool empty(void) const
	noexcept
	{
		return _argc <= 0;
	}

	bool none(void) const
	noexcept
	{
		return _argc <= 1;
	}

	int size(void) const
	noexcept
	{
		return _argc;
	}

	bool is_valid(int pos) const
	noexcept
	{
		return	(0 <= pos) && (pos < _argc) &&
			(_argv != nullptr) && (_argv[pos] != nullptr);
	}

	value_type get(int pos) const
	noexcept
	{
		assert(is_valid(pos));
		return value_type(_argv[pos]);
	}

	value_type operator [] (int pos) const
	noexcept
	{
		return get(pos);
	}

	value_type command(void) const
	noexcept
	{
		return get(0);
	}

	program_arg first(void) const
	noexcept
	{
		return program_arg(1, _argc, _argv);
	}
};

} // namespace eagine

#endif //include guard

