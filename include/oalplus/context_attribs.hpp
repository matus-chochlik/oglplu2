/**
 *  @file oalplus/context_attribs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_CONTEXT_ATTRIBS_1509260923_HPP
#define OALPLUS_CONTEXT_ATTRIBS_1509260923_HPP

#include <eagine/key_val_list.hpp>
#include "enum/values_alc.hpp"

namespace oalplus {

struct context_attrib_traits
{
	typedef context_attrib key_type;
	typedef ALCenum conv_type;
	typedef ALCint value_type;

	static constexpr inline
	ALCint terminator(void)
	noexcept
	{
		return 0;
	}
};

template <std::size_t N>
using context_attribs =
	eagine::key_value_list<context_attrib_traits, N>;

using context_attrib_value =
	eagine::key_value_list_element<context_attrib_traits>;

static constexpr inline
context_attrib_value
operator | (context_attrib key, ALint value)
noexcept
{
	return {key, value};
}

static constexpr inline
context_attrib_value
operator | (context_attrib key, bool value)
noexcept
{
	return {key, value?ALC_TRUE:ALC_FALSE};
}


} // namespace oalplus

#endif // include guard
