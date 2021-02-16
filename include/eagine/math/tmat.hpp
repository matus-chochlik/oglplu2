/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_TMAT_HPP
#define EAGINE_MATH_TMAT_HPP

#include "../all_are_same.hpp"
#include "matrix.hpp"
#include "matrix_identity.hpp"

namespace eagine {
namespace math {

/// @brief Generic template for RxC dimensional matrices.
/// @ingroup math
template <typename T, int C, int R, bool RM, bool V>
struct tmat : matrix<T, C, R, RM, V> {
    /// @brief The base matrix type.
    using base = matrix<T, C, R, RM, V>;

    /// @brief Default constructor. Constructs identity matrix.
    constexpr tmat() noexcept
      : base{identity<base>{}()} {}

    /// @brief Construction from a base matrix.
    constexpr tmat(const base& m) noexcept
      : base{m} {}

    /// @brief Construction from element data pointer and count.
    tmat(const T* d, int n) noexcept
      : base{base::from(d, n)} {}

    /// @brief Construction from element data array.
    tmat(const T (&d)[C * R]) noexcept
      : base{base::from(d, C * R)} {}

private:
    template <
      typename... P,
      typename = std::enable_if_t<
        ((sizeof...(P)) == (C * R)) && all_are_convertible_to<T, P...>::value>>
    static auto _make(P&&... p) {
        T d[C * R] = {T(p)...};
        return base::from(d, C * R);
    }

public:
    template <
      typename... P,
      typename = std::enable_if_t<
        ((sizeof...(P)) == (R * C)) && all_are_convertible_to<T, P...>::value>>
    tmat(P&&... p)
      : base(_make(std::forward<P>(p)...)) {}

    template <
      typename... P,
      typename = std::enable_if_t<((sizeof...(P)) == (RM ? R : C))>>
    constexpr tmat(const vector<P, RM ? C : R, V>&... v) noexcept
      : base{{v._v...}} {}

    template <
      typename P,
      int M,
      int N,
      typename =
        std::enable_if_t<std::is_convertible_v<P, T> && (C <= M) && (R <= N)>>
    constexpr tmat(const matrix<P, M, N, RM, V>& m) noexcept
      : base{base::from(m)} {}
};

template <typename T, int C, int R, bool RM, bool V>
struct is_row_major<math::tmat<T, C, R, RM, V>> : bool_constant<RM> {};

} // namespace math

template <typename T, int C, int R, bool RM, bool V>
struct is_known_matrix_type<math::tmat<T, C, R, RM, V>> : std::is_scalar<T> {};

template <typename T, int C, int R, bool RM, bool V>
struct canonical_compound_type<math::tmat<T, C, R, RM, V>>
  : type_identity<std::remove_cv_t<T[C][R]>> {};

template <typename T, int C, int R, bool RM, bool V>
struct compound_view_maker<math::tmat<T, C, R, RM, V>> {
    auto operator()(const math::tmat<T, C, R, RM, V>& m) const noexcept {
        return vect::view < T, RM ? C : R, V > ::apply(m._v);
    }
};

template <typename T, int C, int R, bool RM, bool V>
struct is_row_major<math::tmat<T, C, R, RM, V>> : bool_constant<RM> {};

} // namespace eagine

#endif // EAGINE_MATH_TMAT_HPP
