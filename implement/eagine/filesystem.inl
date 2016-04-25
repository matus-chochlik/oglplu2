/**
 *  @file eagine/filesystem.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>
#include <eagine/range_algo.hpp>

#include <eagine/posix/fd_path.hpp> // TODO Windows

namespace eagine {
namespace filesystem {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref path_separator(void)
noexcept
{
#if EAGINE_WINDOWS
	return cstr_ref("\\");
#else
	return cstr_ref("/");
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref alt_path_separator(void)
noexcept
{
	return cstr_ref("/");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool has_alt_path_separator(void)
noexcept
{
#if EAGINE_WINDOWS
	return true;
#else
	return false;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref path_curdir(void)
noexcept
{
	return cstr_ref(".");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref path_pardir(void)
noexcept
{
	return cstr_ref("..");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref basename(const cstr_ref& path)
noexcept
{
	return ranges::slice_after_last(
		ranges::strip_suffix(path, path_separator()),
		path_separator()
	);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref dirname(const cstr_ref& path)
noexcept
{
	return ranges::slice_before_last(
		ranges::strip_suffix(path, path_separator()),
		path_separator()
	);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path::string_path(
	const str_span& path_str,
	const str_span& sep,
	const str_span& alt_sep
)
{
	std::size_t s = 0;

	auto count =
	[&s](const str_span& name)
	{
		s += basic_string_path::required_bytes(name);
	};

	auto count_alt =
	[&count,&alt_sep](const str_span& name)
	{
		ranges::for_each_delimited(name, alt_sep, count);
	};

	ranges::for_each_delimited(path_str, sep, count_alt);
	_p.reserve_bytes(s);

	auto push_back =
	[this](const str_span& name)
	{
		_p.push_back(name);
	};

	auto push_back_alt =
	[&push_back,&alt_sep](const str_span& name)
	{
		ranges::for_each_delimited(name, alt_sep, push_back);
	};

	ranges::for_each_delimited(path_str, sep, push_back_alt);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path::string_path(const str_span& path_str, const str_span& sep)
{
	std::size_t s = 0;

	auto count =
	[&s](const str_span& name)
	{
		s += basic_string_path::required_bytes(name);
	};

	ranges::for_each_delimited(path_str, sep, count);
	_p.reserve_bytes(s);

	auto push_back =
	[this](const str_span& name)
	{
		_p.push_back(name);
	};

	ranges::for_each_delimited(path_str, sep, push_back);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path::string_path(str_span path_str)
#if EAGINE_WINDOWS
 : string_path(path_str, path_separator(), alt_path_separator())
#else
 : string_path(path_str, path_separator())
#endif
{ }
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path
string_path::normalized(void) const
{
	string_path result;

	auto do_norm =
	[&result](const string_list::element& elem, bool first)
	{
		auto val = elem.value();
		if(val == path_curdir() && !first) return;
		if((val.size() == 0) && !first) return;

		if(result.empty() || (result.back() == path_pardir()))
		{
			result._p.push_back_elem(elem);
		}
		else if(val == path_pardir())
		{
			if(result.back() == path_curdir())
			{
				result._p.pop_back();
				result._p.push_back_elem(elem);

			}
			else if((result.size()!=1) || (result.back().size()!=0))
			{
				result._p.pop_back();
			}
		}
		else
		{
			result._p.push_back_elem(elem);
		}
	};
	_p.for_each_elem(do_norm);

	return std::move(result);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path
string_path::parent_path(void) const
{
	string_path result(normalized());
	if(result.empty() || result.back() == path_pardir())
	{
		result.push_back(path_pardir());
	}
	else if(result.size() == 1)
	{
		if((result.back() == path_curdir()))
		{
			result.pop_back();
			result.push_back(path_pardir());
		}
		else
		{
			result.pop_back();
			result.push_back(path_curdir());
		}
	}
	else if((result.size() > 1) || (!is_root_name(front())))
	{
		result.pop_back();
	}
	return std::move(result);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
string_path::is_root_name(const str_span& name)
noexcept
{
#if EAGINE_WINDOWS
	return ranges::ends_with(name, cstr_ref(":"));
#else
	return name.size() == 0;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
string_path::is_root_path(void) const
noexcept
{
	return (size() == 1) && is_root_name(front());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
string_path::is_absolute(void) const
noexcept
{
	return !empty() && is_root_name(front());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
string_path::is_relative(void) const
noexcept
{
	return !is_absolute();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path current_working_directory(void)
{
	return string_path(posix::safe_getcwd().value());
}
//------------------------------------------------------------------------------
} // namespace filesystem
} // namespace eagine
