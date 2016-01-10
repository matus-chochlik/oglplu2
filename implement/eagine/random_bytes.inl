/**
 *  @file eagine/random_bytes.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <random>
#include <climits>
#include <algorithm>
#include <eagine/config/basic.hpp>

namespace eagine {
//------------------------------------------------------------------------------
// demangle_type_name
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void fill_with_random_bytes(const span<unsigned char>& buffer)
{
	const unsigned mask = ((1 << CHAR_BIT)-1);

	std::random_device rd;
	std::mt19937 re(rd());
	std::independent_bits_engine<std::mt19937, CHAR_BIT, unsigned> ibe(re);

	auto gen = [&ibe, mask]
	{
		return static_cast<unsigned char>(ibe() & mask);
	};

	std::generate(buffer.begin(), buffer.end(), gen);
}
//------------------------------------------------------------------------------
} // namespace eagine
