/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_RANDOM_IDENTIFIER_HPP
#define EAGINE_RANDOM_IDENTIFIER_HPP

#include "any_random_engine.hpp"
#include "identifier.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Creates an random identifier using the specified random engine.
/// @ingroup identifiers
/// @see identifier
/// @see byte_to_identifier
/// @see dec_to_identifier
auto random_identifier(any_random_engine<std::uint32_t> engine) -> identifier;

/// @brief Creates an random identifier using the specified random engine.
/// @ingroup identifiers
/// @see identifier
/// @see byte_to_identifier
/// @see dec_to_identifier
auto random_identifier(any_random_engine<std::uint64_t> engine) -> identifier;

/// @brief Creates an random identifier using a default random engine.
/// @ingroup identifiers
/// @see identifier
/// @see byte_to_identifier
/// @see dec_to_identifier
auto random_identifier() -> identifier;
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/random_identifier.inl>
#endif

#endif // EAGINE_RANDOM_IDENTIFIER_HPP
