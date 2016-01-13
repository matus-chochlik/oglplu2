/**
 *  @file eagine/hexdump.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_HEXDUMP_1509260923_HPP
#define EAGINE_HEXDUMP_1509260923_HPP

#include "config/basic.hpp"
#include "memory_block.hpp"
#include "types.hpp"
#include <iosfwd>

namespace eagine {

class hexdump
{
private:
	const_memory_block _mb;

	static void _to_hex_b(std::ostream& out, byte b);
public:
	hexdump(const const_memory_block& mb)
	noexcept
	 : _mb(mb)
	{ }

	friend
	std::ostream& operator << (std::ostream&, const hexdump&);
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/hexdump.inl>
#endif

#endif // include guard
