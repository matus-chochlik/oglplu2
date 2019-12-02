/**
 *  @file eagine/random_bytes.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/basic.hpp>
#include <algorithm>
#include <climits>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
// demangle_type_name
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void fill_with_random_bytes(span<byte> buffer) {

    const unsigned mask = ((1U << unsigned(CHAR_BIT)) - 1U);

    std::random_device rd;
    std::mt19937 re(rd());
    std::independent_bits_engine<std::mt19937, CHAR_BIT, unsigned> ibe(re);

    auto gen = [&ibe] { return static_cast<byte>(ibe() & mask); };

    std::generate(buffer.begin(), buffer.end(), gen);
}
//------------------------------------------------------------------------------
} // namespace eagine
