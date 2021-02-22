/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_INVERSE_HPP
#define EAGINE_MATH_MATRIX_INVERSE_HPP

#include "../valid_if/decl.hpp"
#include "matrix_gauss.hpp"
#include "matrix_identity.hpp"

namespace eagine::math {
//------------------------------------------------------------------------------
/// @brief Returns the inverse matrix to the matrix passed as argument.
/// @ingroup math
template <typename T, int N, bool RM, bool V>
static inline auto inverse_matrix(matrix<T, N, N, RM, V> m) noexcept
  -> optionally_valid<matrix<T, N, N, RM, V>> {
    auto i = identity<matrix<T, N, N, RM, V>>()();
    if(gauss_jordan_elimination(m, i)) {
        return {i, true};
    }
    return {};
}
//------------------------------------------------------------------------------
/// @brief Returns the inverse matrix to the matrix constructed by the argument.
/// @ingroup math
template <typename Ctr, typename = std::enable_if_t<is_matrix_constructor_v<Ctr>>>
static inline auto inverse_matrix(const Ctr& ctr) noexcept {
    // TODO: reorder to row major?
    return inverse_matrix(ctr());
}
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_INVERSE_HPP
