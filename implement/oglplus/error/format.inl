/**
 *  @file oglplus/error/format.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cassert>
#endif

namespace oglplus {
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
format_info(
	const error_info& info,
	const cstring_view<>& fmt_str,
	std::ostream& out
)
{
	auto i=fmt_str.begin();
	const auto e=fmt_str.end();

	while(i != e)
	{
		auto p = std::find(i, e, '%');
		std::copy(i, p, std::ostream_iterator<char>(out));

		if(p == e)
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
			if(p == i)
			{
				throw std::runtime_error(
					"Empty placeholder specified "
					"in format string."
				);
			}

			if(*p == '|')
			{
				if(!placeholder.empty())
				{
					throw std::runtime_error(
						"Multiple fallbacks in "
						"placeholder of format string."
					);
				}
				placeholder = std::string(i, p);
				i = p+1;
			}
		}
		while(*p == '|');

		if(placeholder.empty())
		{
			placeholder = std::string(i, p);
		}
		else
		{
			fallback = std::string(i, p);
		}

		auto print = [&out,&fallback](auto value)
		{
			if(value)
			{
				out << value;
			}
			else if(!fallback.empty())
			{
				out << fallback;
			}
			else
			{
				out << "[N/A]";
			}
		};

		if(placeholder == "gl_library_name")
		{
			print(info.gl_library_name());
		}
		else if(placeholder == "gl_function_name")
		{
			print(info.gl_function_name());
		}
		else if(placeholder == "source_function")
		{
			print(info.source_function());
		}
		else if(placeholder == "source_file")
		{
			print(info.source_file());
		}
		else if(placeholder == "source_line")
		{
			print(info.source_line());
		}
		else if(placeholder == "gl_object_name")
		{
			print(info.gl_object_name());
		}
		else if(placeholder == "gl_subbject_name")
		{
			print(info.gl_subject_name());
		}

		i = p+1;
	}
	return out;
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
} // namespace oglplus
