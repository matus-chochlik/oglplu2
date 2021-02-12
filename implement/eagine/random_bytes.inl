/// @file eagine/random_bytes.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/config/basic.hpp>
#include <algorithm>
#include <climits>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Engine>
void do_fill_with_random_bytes(span<byte> buffer, Engine& engine) {

    using ui_t = typename Engine::result_type;

    const ui_t mask = ((1U << unsigned(CHAR_BIT)) - 1U);
    std::independent_bits_engine<Engine, CHAR_BIT, ui_t> ibe(engine);

    auto gen = [&] {
        return static_cast<byte>(ibe() & mask);
    };

    std::generate(buffer.begin(), buffer.end(), gen);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void fill_with_random_bytes(
  span<byte> buffer,
  any_random_engine<std::uint32_t> engine) {
    return do_fill_with_random_bytes(buffer, engine);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void fill_with_random_bytes(
  span<byte> buffer,
  any_random_engine<std::uint64_t> engine) {
    return do_fill_with_random_bytes(buffer, engine);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void fill_with_random_bytes(span<byte> buffer) {
    std::random_device rd;
    std::mt19937 re(rd());
    return do_fill_with_random_bytes(buffer, re);
}
//------------------------------------------------------------------------------
} // namespace eagine
