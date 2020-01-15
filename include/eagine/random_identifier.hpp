/**
 *  @file eagine/random_identifier.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_RANDOM_IDENTIFIER_HPP
#define EAGINE_RANDOM_IDENTIFIER_HPP

#include "identifier.hpp"
#include "identity.hpp"
#include "random_bites.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <
  std::size_t M,
  std::size_t B,
  typename CharSet,
  typename UIntT,
  typename Engine>
auto make_random_basic_identifier(
  identity<basic_identifier<M, B, CharSet, UIntT>>, Engine& engine) {
    return basic_identifier<M, B, CharSet, UIntT>{
      random_biteset<M, B, std::uint8_t>(0, (1U << B) - 1, engine)};
}
//------------------------------------------------------------------------------
template <typename Engine>
identifier random_identifier(Engine& engine) {
    return make_random_basic_identifier(identity<identifier>(), engine);
}
//------------------------------------------------------------------------------
static inline identifier random_identifier() {
    std::random_device engine;
    return random_identifier(engine);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_RANDOM_IDENTIFIER_HPP
