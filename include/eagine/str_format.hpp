/**
 *  @file eagine/str_format.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STR_FORMAT_1509260923_HPP
#define EAGINE_STR_FORMAT_1509260923_HPP

#include "config/basic.hpp"
#include "span.hpp"
#include <string>

namespace eagine {

class format_string_and_list_base
{
private:
	std::string _fmt_str;
	typedef span<const std::string> _span_t;
protected:
	format_string_and_list_base(std::string&& fmt_str)
	noexcept
	 : _fmt_str(std::move(fmt_str))
	{ }

	format_string_and_list_base(format_string_and_list_base& that)
	noexcept
	 : _fmt_str(std::move(that._fmt_str))
	{ }

	std::string _fmt(const _span_t& values) const;
};

template <std::size_t N>
class format_string_and_list;

template <>
class format_string_and_list<0>
 : public format_string_and_list_base
{
public:
	format_string_and_list(std::string& fmt_str)
	noexcept
	 : format_string_and_list_base(std::move(fmt_str))
	{ }

	operator std::string (void) const
	{ return _fmt({}); }
};

template <std::size_t N>
class format_string_and_list
 : public format_string_and_list_base
{
public:
	std::array<std::string, N> _list;
public:
	format_string_and_list(
		format_string_and_list<N-1>&& prev,
		std::string&& val
	) noexcept
	 : format_string_and_list_base(prev)
	{
		for(std::size_t i=0; i<N-1; ++i)
		{
			_list[i] = std::move(prev._list[i]);
		}
		_list[N-1] = std::move(val);
	}

	operator std::string (void) const
	{ return _fmt({_list}); }
};

template <>
class format_string_and_list<1>
 : public format_string_and_list_base
{
public:
	std::array<std::string, 1> _list;
public:
	format_string_and_list(
		format_string_and_list<0>&& prev,
		std::string&& val
	) noexcept
	 : format_string_and_list_base(prev)
	{
		_list[0] = std::move(val);
	}

	operator std::string (void) const
	{ return _fmt({_list}); }
};

template <std::size_t N>
static inline
format_string_and_list<N+1>
operator % (format_string_and_list<N>&& fsal, std::string&& val)
noexcept
{
	return {std::move(fsal), std::move(val)};
}

static inline
format_string_and_list<0>
format(std::string&& fmt_str)
noexcept
{
	return {fmt_str};
}

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/str_format.inl>
#endif

#endif // include guard
