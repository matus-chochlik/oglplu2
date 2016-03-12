/**
 *  @file eagine/valid_if.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_1509260923_HPP
#define EAGINE_VALID_IF_1509260923_HPP

#include "type_traits.hpp"
#include <utility>
#include "assert.hpp"

namespace eagine {

struct valid_flag_policy
{
	bool _is_valid;

	constexpr
	valid_flag_policy(void)
	noexcept
	 : _is_valid(false)
	{ }

	constexpr
	valid_flag_policy(bool is_valid)
	noexcept
	 : _is_valid(is_valid)
	{ }

	template <typename T>
	bool operator ()(const T&) const
	noexcept
	{
		return _is_valid;
	}

	struct do_log
	{
		inline
		do_log(const valid_flag_policy&)
		noexcept
		{ }

		template <typename Log, typename T>
		void operator ()(Log& log, const T&) const
		{
			log << "Getting the value of an empty optional";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Getting the value of an empty optional");
		}
	};
};

template <
	typename T,
	typename Policy,
	typename Abort,
	typename DoLog,
	typename ... P
>
class basic_valid_if
{
private:
	T _value;
	Policy _policy;
	Abort _do_abort;
	DoLog _do_log;

protected:
	explicit
	basic_valid_if(Policy policy)
	noexcept
	 : _value()
	 , _policy(policy)
	 , _do_log(_policy)
	{ }
public:
	basic_valid_if(void)
	noexcept
	 : _value()
	 , _policy()
	 , _do_log(_policy)
	{ }

	basic_valid_if(basic_valid_if&&) = default;
	basic_valid_if(const basic_valid_if&) = default;

	basic_valid_if& operator = (basic_valid_if&&) = default;
	basic_valid_if& operator = (const basic_valid_if&) = default;

	~basic_valid_if(void) = default;

	constexpr inline
	basic_valid_if(T val)
	noexcept
	 : _value(val)
	 , _policy()
	 , _do_log(_policy)
	{ }

	constexpr
	basic_valid_if(T val, Policy policy)
	noexcept
	 : _value(val)
	 , _policy(policy)
	 , _do_log(_policy)
	{ }

	basic_valid_if& operator = (const T& v)
	{
		_value = v;
		return *this;
	}

	basic_valid_if& operator = (T&& v)
	{
		_value = std::move(v);
		return *this;
	}

	bool is_valid(const T& val, P ... p) const
	noexcept
	{
		return _policy(val, p...);
	}

	bool is_valid(P ... p) const
	noexcept
	{
		return is_valid(_value, p...);
	}

	template <typename Log>
	void log_invalid(Log& log, const T& v, P ... p) const
	{
		assert(!is_valid(v));
		_do_log(log, v, p...);
	}

	template <typename Log>
	void log_invalid(Log& log, P ... p) const
	{
		log_invalid(log, _value, p...);
	}

	template <typename Func>
	basic_valid_if& call_if_invalid(Func func, P ... p)
	{
		if(!is_valid(p...)) func(_do_log, _value, p...);
		return *this;
	}

	void abort_if_invalid(P ... p) const
	noexcept
	{
		if(!is_valid(p...)) _do_abort();
	}

	T& value(P ... p)
	noexcept
	{
		abort_if_invalid(p...);
		return _value;
	}

	const T& value(P ... p) const
	noexcept
	{
		abort_if_invalid(p...);
		return _value;
	}

	T& value_or(T& fallback, P ... p)
	noexcept
	{
		return is_valid(p...)?value(p...):fallback;
	}

	const T& value_or(const T& fallback, P ... p) const
	noexcept
	{
		return is_valid(p...)?value(p...):fallback;
	}

	template <typename Func>
	std::enable_if_t<std::is_same<std::result_of_t<Func(T)>, void>::value>
	then(const Func& func, P ... p) const
	{
		if(is_valid(p...))
		{
			func(value(p...));
		}
	}
};

template <
	typename T,
	typename Policy,
	typename Abort = typename Policy::abort,
	typename DoLog = typename Policy::do_log
>
class valid_if
 : public basic_valid_if<T, Policy, Abort, DoLog>
{
private:
	typedef basic_valid_if<T, Policy, Abort, DoLog> _base_t;

	_base_t& _base(void)
	noexcept
	{
		return *this;
	}
public:
	using _base_t::_base_t;
	using _base_t::is_valid;
	using _base_t::value;
	using _base_t::value_or;

	valid_if& operator = (const T& v)
	{
		_base() = v;
		return *this;
	}

	valid_if& operator = (T&& v)
	{
		_base() = std::move(v);
		return *this;
	}

	explicit
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

	template <typename Func>
	std::enable_if_t<
		!std::is_same<std::result_of_t<Func(T)>, void>::value,
		valid_if<
			std::result_of_t<Func(T)>,
			valid_flag_policy
		>
	> then(const Func& func) const
	{
		if(is_valid())
		{
			return {func(value()), true};
		}
		return {};
	}

	template <typename Func>
	valid_if transformed(Func func) const
	{
		return {func(value())};
	}

	template <typename Func>
	auto operator | (const Func& func) const
	{
		return then(func);
	}

	const T& operator / (const T& fallback) const
	noexcept
	{
		return value_or(fallback);
	}

	const T& operator * (void) const
	noexcept
	{
		return value();
	}

	const T* operator -> (void) const
	noexcept
	{
		return &value();
	}
};

// always
struct always_valid_policy
{
	template <typename T>
	constexpr inline
	bool operator ()(T) const
	noexcept
	{
		return true;
	}

	struct do_log
	{
		inline
		do_log(const always_valid_policy&)
		noexcept
		{ }

		template <typename Log, typename T>
		void operator ()(Log&, const T&) const { }
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Never should get here!");
		}
	};
};

template <typename T, T Cmp>
using always_valid = valid_if<T, always_valid_policy>;

// greater-than
template <typename T, T Cmp>
struct valid_if_gt_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value > Cmp;
	}

	struct do_log
	{
		inline
		do_log(const valid_if_gt_policy<T, Cmp>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "less then or equal to " << Cmp << " "
				<< "is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value less than or equal to the limit is invalid"
			);
		}
	};
};

template <typename T, T Cmp>
using valid_if_greater_than = valid_if<T, valid_if_gt_policy<T, Cmp>>;

// positive
template <typename T>
struct valid_if_positive_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value > T(0);
	}

	struct do_log
	{
		inline
		do_log(const valid_if_positive_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "less then or equal to zero "
				<< "is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value less than or equal to zero is invalid"
			);
		}
	};
};

template <typename T>
using valid_if_positive = valid_if<T, valid_if_positive_policy<T>>;

// nonnegative
template <typename T>
struct valid_if_nonnegative_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value >= T(0);
	}

	struct do_log
	{
		inline
		do_log(const valid_if_nonnegative_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "less then zero "
				<< "is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Value less than zero is invalid");
		}
	};
};

template <typename T>
using valid_if_nonnegative = valid_if<T, valid_if_nonnegative_policy<T>>;

// not-equal
template <typename T, T Cmp>
struct valid_if_ne_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value != Cmp;
	}

	struct do_log
	{
		inline
		do_log(const valid_if_ne_policy<T, Cmp>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T&) const
		{
			log << "Value equal to " << Cmp << " is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value equal to the specified constant is invalid"
			);
		}
	};
};

template <typename T, T Cmp>
using valid_if_not = valid_if<T, valid_if_ne_policy<T, Cmp>>;

// not-zero
template <typename T>
struct valid_if_nz_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (value > T(0)) || (value < T(0));
	}

	struct do_log
	{
		inline
		do_log(const valid_if_nz_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T&) const
		{
			log << "Value zero is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Value zero is invalid");
		}
	};
};

template <typename T>
using valid_if_not_zero = valid_if<T, valid_if_nz_policy<T>>;

// nonzero
template <typename T>
using nonzero_t = valid_if_not_zero<T>;

template <typename T>
static inline
nonzero_t<T> nonzero(T v)
noexcept
{
	return {v};
}

// between [min, max]
template <typename T, T Min, T Max>
struct valid_if_btwn_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (Min <= value) && (value <= Max);
	}

	struct do_log
	{
		inline
		do_log(const valid_if_btwn_policy<T, Min, Max>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", not between "
				<< Min << " and " << Max << " is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value outside of the specified limits is invalid"
			);
		}
	};
};

template <typename T, T Min, T Max>
using valid_if_between = valid_if<T, valid_if_btwn_policy<T, Min, Max>>;

// in [0, 1]
template <typename T>
struct valid_if_ge0_le1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (T(0) <= value) && (value <= T(1));
	}

	struct do_log
	{
		inline
		do_log(const valid_if_ge0_le1_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "outside of interval [0,1] is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value outside of interval [0,1] is invalid"
			);
		}
	};
};

template <typename T>
using valid_if_between_0_1 = valid_if<T, valid_if_ge0_le1_policy<T>>;

// in [0, 1)
template <typename T>
struct valid_if_ge0_lt1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (T(0) <= value) && (value < T(1));
	}

	struct do_log
	{
		inline
		do_log(const valid_if_ge0_lt1_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "outside of interval [0,1) is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value outside of interval [0,1) is invalid"
			);
		}
	};
};

template <typename T>
using valid_if_ge0_lt1 = valid_if<T, valid_if_ge0_lt1_policy<T>>;

// in (0, 1)
template <typename T>
struct valid_if_gt0_lt1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (T(0) < value) && (value < T(1));
	}

	struct do_log
	{
		inline
		do_log(const valid_if_gt0_lt1_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "outside of interval (0,1) is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value outside of interval (0,1) is invalid"
			);
		}
	};
};

template <typename T>
using valid_if_gt0_lt1 = valid_if<T, valid_if_gt0_lt1_policy<T>>;

// not empty
template <typename T>
struct valid_if_not_empty_policy
{
	constexpr
	bool operator ()(const T& range) const
	noexcept
	{
		return !range.empty();
	}

	struct do_log
	{
		inline
		do_log(const valid_if_not_empty_policy<T>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T&) const
		{
			log << "Empty range, string or container is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Empty range or container is invalid");
		}
	};
};

template <typename T>
using valid_if_not_empty = valid_if<T, valid_if_not_empty_policy<T>>;

// one of
template <typename T, T ... C>
struct valid_if_one_of_policy
{
	constexpr
	bool operator ()(const T& value) const
	noexcept
	{
		const T choices[] = {C...};
		for(const T& choice : choices)
		{
			if(value == choice)
			{
				return true;
			}
		}
		return false;
	}

	struct do_log
	{
		inline
		do_log(const valid_if_one_of_policy<T, C...>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value " << v << ", "
				<< "other than one of the values [";

			const T choices[] = {C...};
			bool first = true;
			for(const T& choice : choices)
			{
				log << (first?"":", ") << choice;
				first = false;
			}
			log	<< "] is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value other than enumerated is invalid"
			);
		}
	};
};

template <typename T, T ... C>
using valid_if_one_of = valid_if<T, valid_if_one_of_policy<T, C...>>;

// in range
template <typename T, typename Range>
struct valid_if_in_list_policy
{
	Range _choices;

	valid_if_in_list_policy(const Range& choices)
	 : _choices(choices)
	{ }

	constexpr
	bool operator ()(const T& value) const
	noexcept
	{
		for(const T& choice : _choices)
		{
			if(value == choice)
			{
				return true;
			}
		}
		return false;
	}

	struct do_log
	{
		const Range* _choices;

		inline
		do_log(const valid_if_in_list_policy<T, Range>& p)
		noexcept
		 : _choices(&p._choices)
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v) const
		{
			log	<< "Value '" << v << "', "
				<< "other than one of the values [";

			bool first = true;
			for(const T& choice : *_choices)
			{
				log << (first?"":", ") << "'" << choice << "'";
				first = false;
			}
			log	<< "] is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value other than one of specified choices is invalid"
			);
		}
	};
};

template <typename T, typename Range>
using valid_if_in_list = valid_if<T, valid_if_in_list_policy<T, Range>>;


// in_class_valid_if
template <
	typename T,
	typename C,
	typename Policy,
	typename Abort = typename Policy::abort,
	typename DoLog = typename Policy::do_log
> using in_class_valid_if = basic_valid_if<T, Policy, Abort, DoLog, const C&>;


// valid if less than container.size()
template <typename T, typename C>
struct valid_if_lt_size_policy
{
	bool operator()(T x, const C& c) const
	{
		return x < c.size();
	}

	struct do_log
	{
		inline
		do_log(const valid_if_lt_size_policy<T, C>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v, const C& c) const
		{
			log	<< "Value " << v << ", "
				<< "not less than c.size() = "
				<< c.size() << " is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value not less than c.size() is invalid"
			);
		}
	};
};

template <typename C, typename T>
using valid_if_lt_size =
	in_class_valid_if<T, C, valid_if_lt_size_policy<T, C>>;

// valid if greater than or equal to 0 and less than container.size()
template <typename T, typename C>
struct valid_if_ge_0_lt_size_policy
{
	bool operator()(T x, const C& c) const
	{
		return (T(0) <= x) && (x < c.size());
	}

	struct do_log
	{
		inline
		do_log(const valid_if_ge_0_lt_size_policy<T, C>&)
		noexcept
		{ }

		template <typename Log>
		void operator ()(Log& log, const T& v, const C& c) const
		{
			log	<< "Value " << v << ", less than zero or "
				<< "not less than c.size() = "
				<< c.size() << " is invalid";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT(
			"Value less than 0 or not less than c.size() is invalid"
			);
		}
	};
};

template <typename C, typename T>
using valid_if_ge_0_lt_size =
	in_class_valid_if<T, C, valid_if_ge_0_lt_size_policy<T, C>>;

} // namespace eagine

#endif // include guard
