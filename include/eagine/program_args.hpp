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
#include "valid_if.hpp"
#include "span.hpp"
#include <cassert>
#include <sstream>

namespace eagine {

class program_args;

template <typename T>
class program_parameter
{
private:
	cstr_ref _short_tag;
	cstr_ref _long_tag;
	T _value;

	template <typename X>
	static
	T& _get_value(X& val)
	noexcept
	{
		return val;
	}

	template <typename X>
	static
	const T& _get_value(const X& val)
	noexcept
	{
		return val;
	}

	template <typename X, typename P>
	static
	X& _get_value(valid_if<X, P>& vi)
	noexcept
	{
		return vi.value();
	}

	template <typename X, typename P>
	static
	const X& _get_value(const valid_if<X, P>& vi)
	noexcept
	{
		return vi.value();
	}
public:
	program_parameter(
		const cstr_ref& short_tag,
		const cstr_ref& long_tag,
		const T& initial
	) noexcept
	 : _short_tag(short_tag)
	 , _long_tag(long_tag)
	 , _value(initial)
	{ }

	const cstr_ref& short_tag(void) const
	noexcept
	{
		return _short_tag;
	}

	const cstr_ref& long_tag(void) const
	noexcept
	{
		return _long_tag;
	}

	T& ref(void)
	noexcept
	{
		return _value;
	}

	const auto& value(void) const
	noexcept
	{
		return _get_value(_value);
	}

	operator const T& (void) const
	noexcept
	{
		return _value;
	}
};

template <typename T>
class program_parameter_alias
{
private:
	cstr_ref _short_tag;
	cstr_ref _long_tag;
	program_parameter<T>& _aliased;
public:
	program_parameter_alias(const program_parameter_alias&) = delete;

	program_parameter_alias(
		const cstr_ref& short_tag,
		const cstr_ref& long_tag,
		program_parameter<T>& that
	) noexcept
	 : _short_tag(short_tag)
	 , _long_tag(long_tag)
	 , _aliased(that)
	{ }

	const cstr_ref& short_tag(void) const
	noexcept
	{
		return _short_tag;
	}

	const cstr_ref& long_tag(void) const
	noexcept
	{
		return _long_tag;
	}

	T& ref(void)
	noexcept
	{
		return _aliased.ref();
	}

	const auto& value(void) const
	noexcept
	{
		return _aliased.value();
	}

	operator const T& (void) const
	noexcept
	{
		return static_cast<const T&>(_aliased);
	}
};

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

	template <typename T>
	bool _do_parse(T& dest)
	{
		std::stringstream ss(get_string());
		return !((ss >> dest).fail() || !ss.eof());
	}

	bool _do_parse(cstr_ref& dest)
	{
		dest = get();
		return true;
	}

	bool _do_parse(std::string& dest)
	{
		dest = get_string();
		return true;
	}

	template <typename T, typename P>
	bool _do_parse(valid_if<T, P>& dest)
	{
		T value;
		if(parse(value) && dest.is_valid(value))
		{
			dest = std::move(value);
			return true;
		}
		return false;
	}
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

	std::string get_string(void) const
	{
		value_type tmp = get();
		return std::string(tmp.data(), std::size_t(tmp.size()));
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

	template <typename T>
	bool parse(T& dest)
	{
		if(is_valid())
		{
			T temp = dest;
			if(_do_parse(temp))
			{
				dest = std::move(temp);
				return true;
			}
		}
		return false;
	}

	template <typename T>
	bool parse_next(T& dest)
	{
		return next().parse(dest);
	}

	auto missing_handler(std::ostream& errorlog)
	{
		return
		[&errorlog](const cstr_ref& arg_tag)
		{
			errorlog
				<< "Missing value after '"
				<< arg_tag
				<< "'."
				<< std::endl;
		};
	}

	auto invalid_handler(std::ostream& errorlog)
	{
		return 
		[&errorlog](const cstr_ref& arg_tag, const cstr_ref& arg_val)
		{
			errorlog
				<< "Invalid value '"
				<< arg_val
				<< "' after '"
				<< arg_tag
				<< "'."
				<< std::endl;
		};
	}

	template <typename T, typename MissingFunc, typename InvalidFunc>
	bool do_consume_next(
		T& dest,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		if(next())
		{
			if(parse_next(dest))
			{
				*this = next();
				return true;
			}
			else
			{
				handle_invalid(get(), next().get());
			}
		}
		else
		{
			handle_missing(get());
		}
		return false;
	}

	template <typename T>
	bool consume_next(
		T& dest,
		std::ostream& errorlog
	)
	{
		auto if_missing = missing_handler(errorlog);
		auto if_invalid = invalid_handler(errorlog);
		return do_consume_next(dest, if_missing, if_invalid);
	}

	template <typename T, typename MissingFunc, typename InvalidFunc>
	bool do_parse_param(
		program_parameter<T>& param,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		if((get() == param.short_tag()) || (get() == param.long_tag()))
		{
			return do_consume_next(
				param.ref(),
				handle_missing,
				handle_invalid
			);
		}
		return false;
	}

	template <typename T>
	bool parse_param(program_parameter<T>& param, std::ostream& errorlog)
	{
		auto if_missing = missing_handler(errorlog);
		auto if_invalid = invalid_handler(errorlog);
		return do_parse_param(param, if_missing, if_invalid);
	}

	template <typename T, typename MissingFunc, typename InvalidFunc>
	bool do_consume_next(
		T& dest,
		const span<const T>& choices,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		valid_if_in_range<T, span<const T>> temp(T(), choices);
		if(do_consume_next(temp, handle_missing, handle_invalid))
		{
			dest = temp.value();
			return true;
		}
		return false;
	}

	template <typename T, typename P, class MissingFunc, class InvalidFunc>
	bool do_consume_next(
		valid_if<T, P>& dest,
		const span<const T>& choices,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		T temp;
		if(do_consume_next(
			temp,
			choices,
			handle_missing,
			handle_invalid
		))
		{
			if(dest.is_valid(temp))
			{
				dest = std::move(temp);
				return true;
			}
		}
		return false;
	}

	template <typename T, typename C>
	bool consume_next(
		T& dest,
		const span<const C>& choices,
		std::ostream& errorlog
	)
	{
		auto if_missing = missing_handler(errorlog);
		auto if_invalid = invalid_handler(errorlog);
		return do_consume_next(dest, choices, if_missing, if_invalid);
	}

	template <typename T, typename C, class MissingFunc, class InvalidFunc>
	bool do_parse_param(
		program_parameter<T>& param,
		const span<const C>& choices,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		if((get() == param.short_tag()) || (get() == param.long_tag()))
		{
			return do_consume_next(
				param.ref(),
				choices,
				handle_missing, handle_invalid
			);
		}
		return false;
	}

	template <typename T, typename C>
	bool parse_param(
		program_parameter<T>& param,
		const span<const C>& choices,
		std::ostream& errorlog
	)
	{
		auto if_missing = missing_handler(errorlog);
		auto if_invalid = invalid_handler(errorlog);
		return do_parse_param(param, choices, if_missing, if_invalid);
	}

	template <typename T, typename MissingFunc, typename InvalidFunc>
	bool do_consume_next(
		T& dest,
		const span<const cstr_ref>& symbols,
		const span<const T>& translations,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		assert(symbols.size() <= translations.size());

		cstr_ref parsed;
		if(do_consume_next(
			parsed,
			symbols,
			handle_missing, handle_invalid
		))
		{
			for(span_size_type i=0,n=symbols.size(); i<n; ++i)
			{
				if(parsed == symbols[i])
				{
					dest = translations[i];
					return true;
				}
			}
		}
		return false;
	}

	template <typename T, typename P, class MissingFunc, class InvalidFunc>
	bool do_consume_next(
		valid_if<T, P>& dest,
		const span<const cstr_ref>& symbols,
		const span<const T>& translations,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		T temp;
		if(do_consume_next(
			temp,
			symbols, translations, 
			handle_missing,
			handle_invalid
		))
		{
			if(dest.is_valid(temp))
			{
				dest = std::move(temp);
				return true;
			}
		}
		return false;
	}

	template <typename T, typename R>
	bool consume_next(
		T& dest,
		const span<const cstr_ref>& symbols,
		const span<const R>& translations,
		std::ostream& errorlog
	)
	{
		auto if_missing = missing_handler(errorlog);
		auto if_invalid = invalid_handler(errorlog);
		return do_consume_next(
			dest,
			symbols, translations,
			if_missing, if_invalid
		);
	}

	template <typename T, typename R, class MissingFunc, class InvalidFunc>
	bool do_parse_param(
		program_parameter_alias<T>& param,
		const span<const cstr_ref>& symbols,
		const span<const R>& translations,
		MissingFunc handle_missing,
		InvalidFunc handle_invalid
	)
	{
		if((get() == param.short_tag()) || (get() == param.long_tag()))
		{
			return do_consume_next(
				param.ref(),
				symbols, translations,
				handle_missing, handle_invalid
			);
		}
		return false;
	}

	template <typename T, typename R>
	bool parse_param(
		program_parameter_alias<T>& param,
		const span<const cstr_ref>& symbols,
		const span<const R>& translations,
		std::ostream& errorlog
	)
	{
		auto if_missing = missing_handler(errorlog);
		auto if_invalid = invalid_handler(errorlog);
		return do_parse_param(
			param,
			symbols, translations,
			if_missing, if_invalid
		);
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

	template <typename T>
	bool parse_param(
		program_parameter<T>& param,
		std::ostream& errlog
	) const
	{
		for(program_arg a = first(); a; a = a.next())
		{
			if(a.parse_param(param, errlog)) return true;
		}
		return false;
	}
};

} // namespace eagine

#endif //include guard

