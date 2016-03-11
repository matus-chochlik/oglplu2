/**
 *  @file oglplus/error/format.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/error/error.hpp>
#include <oglplus/object/ios.hpp>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <cstring>

namespace oglplus {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
format_error_info(
	const error_info& info,
	const cstr_ref& msg_str,
	const cstr_ref& fmt_str,
	const cstr_ref& n_a_str,
	std::ostream& out
)
{
	auto i=fmt_str.begin();
	const auto e=fmt_str.end();

	while(i != e)
	{
		auto p = std::find(i, e, '%');
		if(p == e)
		{
			p = std::find(i, e, '\0');
		}
		std::copy(i, p, std::ostream_iterator<char>(out));

		if(p == e || *p == '\0')
		{
			break;
		}

		assert(*p == '%');
		i = p+1;

		if(i == e)
		{
			throw std::runtime_error(
				"Missing placeholder at "
				"the end of format string."
			);
		}

		if(*i == '%')
		{
			out << '%';
			++i;
			continue;
		}

		if(*i != '(')
		{
			throw std::runtime_error(
				"Missing placeholder after "
				"single '%' in format string."
			);
		}
		++i;

		std::string placeholder;
		std::string fallback;
		bool parsed_fallback = false;

		do
		{
			p = std::find_if(
				i, e,
				[](char c){ return c=='|' || c==')'; }
			);
			if(p == e)
			{
				throw std::runtime_error(
					"Placeholder not terminated "
					"by ')' in format string."
				);
			}

			if(*p == '|')
			{
				if(p == i)
				{
					throw std::runtime_error(
						"Empty placeholder specified "
						"in format string."
					);
				}
				if(!placeholder.empty())
				{
					throw std::runtime_error(
						"Multiple fallbacks in "
						"placeholder of format string."
					);
				}
			}

			if(placeholder.empty())
			{
				placeholder = std::string(i, p);
			}
			else
			{
				fallback = std::string(i, p);
				parsed_fallback = true;
			}
			i = p+1;
		}
		while(*p == '|');

		auto print =
			[&out,&n_a_str,&fallback,parsed_fallback]
			(auto value, auto nil)
			{
				if(value != nil)
				{
					out << value;
				}
				else if(parsed_fallback)
				{
					out << fallback;
				}
				else
				{
					out << n_a_str;
				}
			};

		if(placeholder == "message")
		{
			out << msg_str;
		}
		else if(placeholder == "info_log")
		{
			auto il = info.info_log();
			out.write(il.data(), il.size());
		}
		else if(placeholder == "gl_library_name")
		{
			print(info.gl_library_name(), nullptr);
		}
		else if(placeholder == "gl_function_name")
		{
			print(info.gl_function_name(), nullptr);
		}
		else if(placeholder == "source_function")
		{
			print(info.source_function(), nullptr);
		}
		else if(placeholder == "source_file")
		{
			print(info.source_file(), nullptr);
		}
		else if(placeholder == "source_line")
		{
			print(info.source_line(), 0u);
		}
		else if(placeholder == "gl_object")
		{
			print(info.gl_object(), any_object_name());
		}
		else if(placeholder == "gl_subject")
		{
			print(info.gl_subject(), any_object_name());
		}
		else if(placeholder == "gl_enum_value")
		{
			auto ev_name = get_enum_value_name(info.gl_enum_value());
			if(ev_name)
			{
				out << ev_name;
			}
			else if(parsed_fallback)
			{
				out << fallback;
			}
			else
			{
				out << n_a_str;
			}
		}
		else if(placeholder == "gl_index")
		{
			print(info.gl_index(), info.invalid_index());
		}
		else
		{
			throw std::runtime_error(
				"Invalid placeholder specified "
				"in format string."
			);
		}

		i = p+1;
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
format_error_info(
	const error_info& info,
	const cstr_ref& msg_str,
	const cstr_ref& fmt_str,
	std::ostream& out
)
{
	return format_error_info(info, msg_str, fmt_str, "[N/A]", out);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
format_error_info(
	const error_info& info,
	const cstr_ref& fmt_str,
	std::ostream& out
)
{
	return format_error_info(info, "", fmt_str, "[N/A]", out);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
format_error(
	error& err,
	const cstr_ref& fmt_str,
	const cstr_ref& n_a_str,
 	std::ostream& out
)
{
	return format_error_info(
		err.info(),
		cstr_ref(err.what()),
		fmt_str,
		n_a_str,
		out
	);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
format_error(
	error& err,
	const cstr_ref& fmt_str,
 	std::ostream& out
)
{
	return format_error(err, fmt_str, "[N/A]", out);
}
//------------------------------------------------------------------------------
} // namespace oglplus
