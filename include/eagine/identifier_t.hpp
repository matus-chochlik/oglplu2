/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_IDENTIFIER_T_HPP
#define EAGINE_IDENTIFIER_T_HPP

#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief The underlying integer type for eagine::identifier.
/// @ingroup identifiers
/// @see identifier
using identifier_t = std::uint64_t;

/// @brief Unique process identifier type (does not necessarily match to OS PID).
using process_instance_id_t = std::uint32_t;

/// @brief Unique host identifier type.
using host_id_t = std::uint32_t;
//------------------------------------------------------------------------------
#if __SIZEOF_INT128__
/// @brief The underlying integer type for eagine::long_identifier.
/// @ingroup identifiers
/// @see long_identifier
using long_identifier_t = __uint128_t;
//------------------------------------------------------------------------------
#define EAGINE_HAS_LONG_ID 1
#else
#define EAGINE_HAS_LONG_ID 0
#endif
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_IDENTIFIER_T_HPP
