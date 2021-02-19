/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_IDENTIFIER_CTR_HPP
#define EAGINE_IDENTIFIER_CTR_HPP

#include "identifier.hpp"
#include "types.hpp"

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Creates an identifier representing a byte value as a hex string.
/// @ingroup identifiers
/// @see identifier
/// @see dec_to_identifier
auto byte_to_identifier(byte b) noexcept -> identifier;

/// @brief Creates an identifier representing an integer value as a decimal string.
/// @ingroup identifiers
/// @see identifier
/// @see byte_to_identifier
auto dec_to_identifier(int i) noexcept -> identifier;
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/identifier_ctr.inl>
#endif

#endif // EAGINE_IDENTIFIER_CTR_HPP
