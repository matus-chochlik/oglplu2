/**
 *  @file eagine/random_identifier.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/identity.hpp>
#include <eagine/int_constant.hpp>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
template <std::size_t S, std::size_t... I, typename Engine>
void fill_random_charset_string(
  span<char> dst,
  const char (&charset)[S],
  std::index_sequence<I...>,
  Engine& engine) {
    std::uniform_int_distribution<std::size_t> dist(0, S - 1);
    dst[sizeof...(I)] = '\0';
    ((dst[I] = charset[dist(engine)]), ...);
}
//------------------------------------------------------------------------------
template <
  std::size_t M,
  std::size_t B,
  typename CharSet,
  typename UIntT,
  typename Engine>
auto make_random_basic_identifier(
  identity<basic_identifier<M, B, CharSet, UIntT>>, Engine& engine) {
    char temp[M + 1];
    fill_random_charset_string(
      cover(temp), CharSet::values, std::make_index_sequence<M>(), engine);
    return basic_identifier<M, B, CharSet, UIntT>{temp};
}
//------------------------------------------------------------------------------
template <typename Engine>
identifier get_random_identifier(Engine& engine) {
    return make_random_basic_identifier(identity<identifier>(), engine);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
identifier random_identifier(any_random_engine<std::uint32_t> engine) {
    return get_random_identifier(engine);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
identifier random_identifier(any_random_engine<std::uint64_t> engine) {
    return get_random_identifier(engine);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
identifier random_identifier() {
    std::random_device engine;
    return random_identifier(
      any_random_engine<std::random_device::result_type>{engine});
}
//------------------------------------------------------------------------------
} // namespace eagine
