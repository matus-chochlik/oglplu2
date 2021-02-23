/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INT_CONSTANT_HPP
#define EAGINE_INT_CONSTANT_HPP

#include "identifier_t.hpp"
#include <type_traits>

namespace eagine {

/// @brief Alias for boolean constant type.
/// @ingroup type_utils
template <bool B>
using bool_constant = std::integral_constant<bool, B>;

/// @brief Alias for signed int constant type.
/// @ingroup type_utils
template <int I>
using int_constant = std::integral_constant<int, I>;

/// @brief Alias for unsigned int constant type.
/// @ingroup type_utils
template <unsigned U>
using unsigned_constant = std::integral_constant<unsigned, U>;

/// @brief Alias for size_t constant type.
/// @ingroup type_utils
template <std::size_t S>
using size_constant = std::integral_constant<std::size_t, S>;

/// @brief Alias for identifier_t constant type.
/// @ingroup type_utils
/// @see identifier_t
template <identifier_t Id>
using id_constant = std::integral_constant<identifier_t, Id>;

} // namespace eagine

#endif // EAGINE_INT_CONSTANT_HPP
