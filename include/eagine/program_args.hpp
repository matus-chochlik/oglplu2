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
#include "type_name.hpp"
#include "span.hpp"
#include <cassert>
#include <sstream>
#include <vector>
#include <memory>

namespace eagine {

class program_args;

template <typename T>
class program_parameter
{
private:
	cstr_ref _short_tag;
	cstr_ref _long_tag;
	cstr_ref _description;
	T _value;

	template <typename X>
	static inline
	bool _is_valid(const X&)
	noexcept
	{
		return true;
	}

	template <typename X, typename P>
	static inline
	bool _is_valid(const valid_if<X, P>& vi)
	noexcept
	{
		return vi.is_valid();
	}

	template <typename X>
	static inline
	void _log_invalid(const X&, const std::ostream&)
	noexcept
	{ }

	template <typename X, typename P>
	static inline
	void _log_invalid(const valid_if<X, P>& vi, std::ostream& log)
	noexcept
	{
		vi.log_invalid(log);
	}

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

	const cstr_ref& description(void) const
	noexcept
	{
		return _description;
	}

	program_parameter& description(cstr_ref help_str)
	noexcept
	{
		_description = help_str;
		return *this;
	}

	T& ref(void)
	noexcept
	{
		return _value;
	}

	bool has_valid_value(void) const
	noexcept
	{
		return _is_valid(_value);
	}

	std::ostream& log_invalid_value(std::ostream& log) const
	{
		log << "Invalid value of parameter " << long_tag() << ": ";
		_log_invalid(_value, log);
		return log << ". ";
	}

	bool validate(std::ostream& log) const
	{
		if(!has_valid_value())
		{
			log_invalid_value(log) << std::endl;
			return false;
		}
		return true;
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

template <>
class program_parameter<void>
{
private:
	cstr_ref _short_tag;
	cstr_ref _long_tag;
	cstr_ref _description;
	std::size_t _count;
public:
	program_parameter(
		const cstr_ref& short_tag,
		const cstr_ref& long_tag
	) noexcept
	 : _short_tag(short_tag)
	 , _long_tag(long_tag)
	 , _count(0)
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

	const cstr_ref& description(void) const
	noexcept
	{
		return _description;
	}

	program_parameter& description(cstr_ref help_str)
	noexcept
	{
		_description = help_str;
		return *this;
	}

	void increment(void)
	noexcept
	{
		++_count;
	}

	bool has_valid_value(void) const
	noexcept
	{
		return true;
	}

	std::ostream& log_invalid_value(std::ostream& log) const
	noexcept
	{
		return log;
	}

	bool validate(std::ostream&) const
	noexcept
	{
		return true;
	}

	std::size_t value(void) const
	noexcept
	{
		return _count;
	}
};

typedef program_parameter<void> program_option;

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
	bool _do_parse(T& dest, const std::ostream&)
	{
		std::stringstream ss(get_string());
		return !((ss >> dest).fail() || !ss.eof());
	}

	bool _do_parse(cstr_ref& dest, const std::ostream&)
	{
		dest = get();
		return true;
	}

	bool _do_parse(std::string& dest, const std::ostream&)
	{
		dest = get_string();
		return true;
	}

	template <typename T, typename P>
	bool _do_parse(valid_if<T, P>& dest, std::ostream& parse_log)
	{
		T value;
		if(parse(value, parse_log))
		{
			if(dest.is_valid(value))
			{
				dest = std::move(value);
				return true;
			}
			else
			{
				dest.log_invalid(parse_log, value);
			}
		}
		else
		{
			parse_log	<< "'" << get() << "' "
					<< "is not a valid `"
					<< type_name<T>()
					<< "` value";
		}
		return false;
	}

	template <typename T, typename A>
	bool _do_parse(std::vector<T, A>& dest, std::ostream& parse_log)
	{
		T value;
		if(parse(value, parse_log))
		{
			dest.push_back(std::move(value));
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

	bool is_help_arg(void) const
	noexcept
	{
		return (get() == cstr_ref("-h"))||(get() == cstr_ref("--help"));
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
	bool parse(T& dest, std::ostream& parse_log)
	{
		if(is_valid())
		{
			T temp = dest;
			if(_do_parse(temp, parse_log))
			{
				dest = std::move(temp);
				return true;
			}
		}
		return false;
	}

	template <typename T>
	bool parse_next(T& dest, std::ostream& parse_log)
	{
		return next().parse(dest, parse_log);
	}

	auto missing_handler(std::ostream& errorlog)
	{
		return
		[&errorlog](const cstr_ref& arg_tag)
		{
			errorlog<< "Missing value after '"
				<< arg_tag
				<< "'."
				<< std::endl;
		};
	}

	auto invalid_handler(std::ostream& errorlog)
	{
		return 
		[&errorlog](
			const cstr_ref& arg_tag,
			const cstr_ref& arg_val,
			const cstr_ref& log_str
		)
		{
			errorlog<< "Invalid value '"
				<< arg_val
				<< "' after '"
				<< arg_tag
				<< "'. "
				<< log_str
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
			std::stringstream parse_log;
			if(parse_next(dest, parse_log))
			{
				*this = next();
				return true;
			}
			else
			{
				handle_invalid(
					get(),
					next().get(),
					cstr_ref(parse_log.str())
				);
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

	template <typename MissingFunc, typename InvalidFunc>
	bool do_parse_param(
		program_parameter<void>& param,
		const MissingFunc&,
		const InvalidFunc&
	)
	{
		if((get() == param.short_tag()) || (get() == param.long_tag()))
		{
			param.increment();
			return true;
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
		valid_if_in_list<T, span<const T>> temp(T(), choices);
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
		program_parameter<T>& param,
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
		program_parameter<T>& param,
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

class program_parameters
{
private:
	struct _intf
	{
		virtual ~_intf(void) = default;

		virtual bool parse(program_arg&, std::ostream&) = 0;

		virtual bool has_valid_value(void) const = 0;
		virtual bool validate(std::ostream&) const = 0;

		virtual const cstr_ref& short_tag(void) const = 0;
		virtual const cstr_ref& long_tag(void) const = 0;
		virtual const cstr_ref& description(void) const = 0;
		virtual const cstr_ref& placeholder(void) const = 0;
	};

	template <typename T>
	struct _impl : _intf
	{
		program_parameter<T>* _pparam;
		cstr_ref _plchldr;

		program_parameter<T>& _param(void)
		noexcept
		{
			assert(_pparam != nullptr);
			return *_pparam;
		}

		const program_parameter<T>& _param(void) const
		noexcept
		{
			assert(_pparam != nullptr);
			return *_pparam;
		}

		_impl(program_parameter<T>& param)
		noexcept
		 : _pparam(&param)
		 , _plchldr("VALUE") // TODO: be more precise depending on T
		{ }

		bool parse(program_arg& arg, std::ostream& log)
		override
		{
			return arg.parse_param(_param(), log);
		}

		bool has_valid_value(void) const
		override
		{
			return _param().has_valid_value();
		}

		bool validate(std::ostream& log) const
		override
		{
			return _param().validate(log);
		}

		const cstr_ref& short_tag(void) const
		override
		{
			return _param().short_tag();
		}

		const cstr_ref& long_tag(void) const
		override
		{
			return _param().long_tag();
		}

		const cstr_ref& description(void) const
		override
		{
			return _param().description();
		}

		const cstr_ref& placeholder(void) const
		override
		{
			return _plchldr;
		}
	};

	std::vector<std::unique_ptr<_intf>> _params;

	static inline
	std::vector<std::unique_ptr<_intf>>&
	_insert(std::vector<std::unique_ptr<_intf>>& dest)
	noexcept
	{
		return dest;
	}

	template <typename ... Intf>
	static inline
	std::vector<std::unique_ptr<_intf>>&
	_insert(
		std::vector<std::unique_ptr<_intf>>& dest,
		std::unique_ptr<_intf>&& param,
		std::unique_ptr<Intf>&& ... params
	) noexcept
	{
		assert(param != nullptr);
		dest.push_back(std::move(param));
		return _insert(dest, std::move(params)...);
	}

	template <typename ... Intf>
	static
	std::vector<std::unique_ptr<_intf>>
	_make(std::unique_ptr<Intf>&& ... params)
	{
		std::vector<std::unique_ptr<_intf>> result;
		result.reserve(sizeof ... (params));
		return std::move(_insert(result, std::move(params)...));
	}
public:
	template <typename ... T>
	program_parameters(program_parameter<T>& ... params)
	 : _params(_make(std::unique_ptr<_intf>(new _impl<T>(params))...))
	{ }

	std::size_t size(void) const
	noexcept
	{
		return _params.size();
	}

	bool parse(program_arg& arg, std::ostream& log)
	{
		for(std::unique_ptr<_intf>& param : _params)
		{
			assert(param != nullptr);
			if(param->parse(arg, log))
			{
				return true;
			}
		}
		return false;
	}

	bool validate(std::ostream& log) const
	{
		bool all_ok = true;
		for(const std::unique_ptr<_intf>& param : _params)
		{
			assert(param != nullptr);
			all_ok &= param->validate(log);
		}
		return all_ok;
	}

	std::ostream& print_usage(std::ostream& out, const cstr_ref& command)
	{
		out << "Usage: " << command;

		span_size_type stag_maxl = 0;
		span_size_type ltag_maxl = 0;

		for(const std::unique_ptr<_intf>& param : _params)
		{
			assert(param != nullptr);

			out << " ";

			bool mandatory = !param->has_valid_value();

			out << (mandatory?'<':'[');

			out << param->short_tag() << "|" << param->long_tag();
			out << " " << param->placeholder();

			out << (mandatory?'>':']');

			if(stag_maxl < param->short_tag().size())
			{
				stag_maxl = param->short_tag().size();
			}

			if(ltag_maxl < param->long_tag().size())
			{
				ltag_maxl = param->long_tag().size();
			}
		}
		out << std::endl;
		out << "  Options:" << std::endl;

		span_size_type padl;

		for(const std::unique_ptr<_intf>& param : _params)
		{
			padl = 4+stag_maxl-param->short_tag().size();
			while(padl-- > 0) out << " ";
			out << param->short_tag() << "|";

			out << param->long_tag();
			padl = ltag_maxl-param->long_tag().size();
			while(padl-- > 0) out << " ";
			out << ": " << param->description() << std::endl;
		}

		return out;
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

	typedef cstr_ref value_type;
	typedef int size_type;
	typedef valid_if_ge_0_lt_size<program_args, size_type> valid_index;

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

	bool is_valid(valid_index pos) const
	noexcept
	{
		return	pos.is_valid(*this) &&
			(_argv != nullptr) &&
			(_argv[pos.value(*this)] != nullptr);
	}

	value_type get(valid_index pos) const
	noexcept
	{
		assert(is_valid(pos));
		return value_type(_argv[pos.value(*this)]);
	}

	value_type operator [] (valid_index pos) const
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

