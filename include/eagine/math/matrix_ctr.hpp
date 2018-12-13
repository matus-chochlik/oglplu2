/**
 *  @file eagine/math/matrix_ctr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_CTR_1509260923_HPP
#define EAGINE_MATH_MATRIX_CTR_1509260923_HPP

#include "../nothing.hpp"
#include "matrix.hpp"

namespace eagine {
namespace math {

template <template <class> class MC, typename T, int C, int R, bool RM, bool V>
struct constructed_matrix<MC<matrix<T, C, R, RM, V>>>
  : std::conditional_t<
      is_matrix_constructor<MC<matrix<T, C, R, RM, V>>>::value,
      matrix<T, C, R, RM, V>,
      nothing_t> {};

template <
  template <class, int>
  class MC,
  typename T,
  int C,
  int R,
  bool RM,
  bool V,
  int I>
struct constructed_matrix<MC<matrix<T, C, R, RM, V>, I>>
  : std::conditional_t<
      is_matrix_constructor<MC<matrix<T, C, R, RM, V>, I>>::value,
      matrix<T, C, R, RM, V>,
      nothing_t> {};

// construct_matrix (noop)
template <bool RM, typename MC>
static constexpr inline std::enable_if_t<
  is_matrix_constructor<MC>::value &&
    is_row_major<constructed_matrix_t<MC>>::value == RM,
  constructed_matrix_t<MC>>
construct_matrix(const MC& c) noexcept {
    return c();
}

// construct_matrix (reorder)
template <bool RM, typename MC>
static constexpr inline std::enable_if_t<
  is_matrix_constructor<MC>::value &&
    is_row_major<constructed_matrix_t<MC>>::value != RM,
  reordered_matrix_t<constructed_matrix_t<MC>>>
construct_matrix(const MC& c) noexcept {
    return reorder_mat_ctr(c)();
}

template <
  typename MC1,
  typename MC2,
  typename = std::enable_if_t<
    is_matrix_constructor<MC1>::value && is_matrix_constructor<MC2>::value &&
    are_multiplicable<constructed_matrix_t<MC1>, constructed_matrix_t<MC2>>::
      value>>
static inline auto multiply(const MC1& mc1, const MC2& mc2) noexcept {
    return multiply(construct_matrix<true>(mc1), construct_matrix<false>(mc2));
}

template <typename MC>
struct convertible_matrix_constructor : MC {
    static_assert(is_matrix_constructor<MC>::value, "");

    template <typename... P>
    convertible_matrix_constructor(P&&... p)
      : MC(std::forward<P>(p)...) {
    }

    operator constructed_matrix_t<MC>() const noexcept {
        return MC::operator()();
    }
};

template <typename MC>
struct is_matrix_constructor<convertible_matrix_constructor<MC>>
  : is_matrix_constructor<MC> {};

template <typename MC>
struct constructed_matrix<convertible_matrix_constructor<MC>>
  : constructed_matrix<MC> {};

} // namespace math

template <typename MC>
struct is_known_matrix_type<math::convertible_matrix_constructor<MC>>
  : is_known_matrix_type<math::constructed_matrix_t<MC>> {};

template <typename MC>
struct canonical_compound_type<math::convertible_matrix_constructor<MC>>
  : canonical_compound_type<math::constructed_matrix_t<MC>> {};

template <typename MC>
struct compound_view_maker<math::convertible_matrix_constructor<MC>> {
    struct _result_type {
        using M = math::constructed_matrix_t<MC>;
        using T = typename M::element_type;
        M _m;

        operator span<const T>() const noexcept {
            compound_view_maker<M> cvm;
            return cvm(_m);
        }
    };

    inline _result_type operator()(
      const math::convertible_matrix_constructor<MC>& mc) const noexcept {
        return _result_type{mc()};
    }
};

template <typename MC>
struct is_row_major<math::convertible_matrix_constructor<MC>>
  : math::is_row_major<math::constructed_matrix_t<MC>> {};

} // namespace eagine

#endif // include guard
