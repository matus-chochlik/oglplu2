/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_VECTOR_HPP
#define EAGINE_MATH_VECTOR_HPP

#include "../assert.hpp"
#include "../vec_mat_traits.hpp"
#include "../vect/axis.hpp"
#include "../vect/cast.hpp"
#include "../vect/compare.hpp"
#include "../vect/esum.hpp"
#include "../vect/from.hpp"
#include "../vect/hsum.hpp"
#include "../vect/sdiv.hpp"
#include "../vect/sqrt.hpp"
#include "../vect/view.hpp"
#include "scalar.hpp"
#include <utility>

namespace eagine {
namespace math {

/// @brief Basic N-dimensional vector implementation template.
/// @ingroup math
/// @see tvec
/// @note This is a base class, typically tvec should be used in client code.
template <typename T, int N, bool V>
struct vector {
    using type = vector;

    /// @brief Related scalar type.
    using scalar_type = scalar<T, N, V>;

    /// @brief Element value type.
    using value_type = T;

    /// @brief Indicates if the implementation used SIMD extensions.
    using is_vectorized = vect::has_vect_data_t<T, N, V>;

    using data_type = vect::data_t<T, N, V>;

    data_type _v;

    using _cpT = const vector&;
    using _cspT = const scalar_type&;

    /// @brief Creates a new zero vector instance.
    static auto zero() noexcept {
        return vector{vect::fill<T, N, V>::apply(T(0))};
    }

    /// @brief Creates a zero vector instance with all elements set to @p v.
    static auto fill(T v) noexcept {
        return vector{vect::fill<T, N, V>::apply(v)};
    }

    /// @brief Creates an unit axis vector for the I-th dimension.
    /// @pre I < N
    template <int I>
    static auto axis() noexcept {
        return vector{vect::axis<T, N, I, V>::apply(T(1))};
    }

    /// @brief Creates an axis vector for the I-th dimension with specified length.
    /// @pre I < N
    template <int I>
    static auto axis(T v) noexcept {
        return vector{vect::axis<T, N, I, V>::apply(v)};
    }

    /// @brief Creates an axis vector for the i-th dimension with specified length.
    /// @pre i < N
    static auto axis(int i, T v) noexcept {
        EAGINE_ASSERT(i < N);
        vector r = zero();
        r._v[i] = v;
        return r;
    }

    template <
      typename P,
      typename = std::enable_if_t<(N == 1) && (std::is_convertible_v<P, T>)>>
    static constexpr auto make(P&& p) noexcept {
        return vector{{T(std::forward<P>(p))}};
    }

    /// @brief Creates vector instance with the specified elements.
    template <
      typename... P,
      typename = std::enable_if_t<(N > 1) && (sizeof...(P) == N)>>
    static constexpr auto make(P&&... p) noexcept {
        return vector{{T(std::forward<P>(p))...}};
    }

    /// @brief Creates vector instance from vector of another dimension.
    /// @param d specifies the value for additional elements if M < N.
    template <
      typename P,
      int M,
      bool W,
      typename =
        std::enable_if_t<(!std::is_same_v<T, P> || (N != M) || (V != W))>>
    static constexpr auto from(const vector<P, M, W>& v, T d = T(0)) noexcept {
        return vector{vect::cast<P, M, W, T, N, V>::apply(v._v, d)};
    }

    /// @brief Creates vector instance from two other vectors.
    template <typename P, int M, bool W>
    static constexpr auto
    from(const vector<P, M, W>& v, const vector<T, N - M, W>& u) noexcept {
        return vector{vect::cast<P, M, W, T, N, V>::apply(v._v, u._v)};
    }

    /// @brief Creates vector instance from data pointer and length.
    static auto from(const T* dt, span_size_t sz) noexcept {
        return vector{vect::from_array<T, N, V>::apply(dt, sz)};
    }

    /// @brief Creates vector instance from data pointer, length and additional value.
    static auto from(const T* dt, span_size_t sz, T fv) noexcept {
        return vector{vect::from_saafv<T, N, V>::apply(dt, sz, fv)};
    }

    /// @brief Subscript operator.
    constexpr auto operator[](int pos) const noexcept {
        return _v[pos];
    }

    /// @brief Returns the x-coordinate value.
    /// @pre N >= 1
    template <int M = N>
    constexpr auto x() const noexcept -> std::enable_if_t<(M > 0), T> {
        static_assert(M == N);
        return _v[0];
    }

    /// @brief Returns the y-coordinate value.
    /// @pre N >= 2
    template <int M = N>
    constexpr auto y() const noexcept -> std::enable_if_t<(M > 1), T> {
        static_assert(M == N);
        return _v[1];
    }

    /// @brief Returns the z-coordinate value.
    /// @pre N >= 3
    template <int M = N>
    constexpr auto z() const noexcept -> std::enable_if_t<(M > 2), T> {
        static_assert(M == N);
        return _v[2];
    }

    /// @brief Returns the w-coordinate value.
    /// @pre N >= 4
    template <int M = N>
    constexpr auto w() const noexcept -> std::enable_if_t<(M > 3), T> {
        static_assert(M == N);
        return _v[3];
    }

    /// @brief Unary plus operator.
    friend constexpr auto operator+(_cpT a) noexcept {
        return a;
    }

    /// @brief Negation operator.
    friend constexpr auto operator-(_cpT a) noexcept {
        return vector{-a._v};
    }

    /// @brief Addition operator.
    friend constexpr auto operator+(_cpT a, _cpT b) noexcept {
        return vector{a._v + b._v};
    }

    /// @brief Addition operator.
    auto operator+=(_cpT a) noexcept -> auto& {
        _v = _v + a._v;
        return *this;
    }

    /// @brief Subtraction operator.
    friend constexpr auto operator-(_cpT a, _cpT b) noexcept {
        return vector{a._v - b._v};
    }

    /// @brief Subtraction operator.
    auto operator-=(_cpT a) noexcept -> auto& {
        _v = _v - a._v;
        return *this;
    }

    /// @brief Multiplication operator.
    friend constexpr auto operator*(_cpT a, _cpT b) noexcept {
        return vector{a._v * b._v};
    }

    /// @brief Multiplication operator.
    auto operator*=(_cpT a) noexcept -> auto& {
        _v = _v * a._v;
        return *this;
    }

    /// @brief Multiplication by scalar operator.
    friend constexpr auto operator*(_cspT c, _cpT a) noexcept {
        static_assert(scalar_type::is_vectorized::value);
        return vector{c._v * a._v};
    }

    /// @brief Multiplication by scalar operator.
    friend constexpr auto operator*(_cpT a, _cspT c) noexcept {
        static_assert(scalar_type::is_vectorized::value);
        return vector{a._v * c._v};
    }

    /// @brief Multiplication by scalar operator.
    auto operator*=(_cspT c) noexcept -> auto& {
        static_assert(scalar_type::is_vectorized::value);
        _v = _v * c._v;
        return *this;
    }

    /// @brief Multiplication by constant operator.
    friend constexpr auto operator*(T c, _cpT a) noexcept {
        return vector{a._v * vect::fill<T, N, V>::apply(c)};
    }

    /// @brief Multiplication by constant operator.
    friend constexpr auto operator*(_cpT a, T c) noexcept {
        return vector{a._v * vect::fill<T, N, V>::apply(c)};
    }

    /// @brief Multiplication by constant operator.
    auto operator*=(T c) noexcept -> auto& {
        _v = _v * vect::fill<T, N, V>::apply(c);
        return *this;
    }

    /// @brief Division operator.
    friend constexpr auto operator/(_cpT a, _cpT b) noexcept {
        return vector{vect::sdiv<T, N, V>::apply(a._v, b._v)};
    }

    /// @brief Scalar division operator.
    friend constexpr auto operator/(_cspT c, _cpT a) noexcept {
        static_assert(scalar_type::is_vectorized::value);
        return vector{vect::sdiv<T, N, V>::apply(c._v, a._v)};
    }

    /// @brief Division by scalar operator.
    friend constexpr auto operator/(_cpT a, _cspT c) noexcept {
        static_assert(scalar_type::is_vectorized::value);
        return vector{vect::sdiv<T, N, V>::apply(a._v, c._v)};
    }

    /// @brief Division by constant operator.
    friend constexpr auto operator/(_cpT a, T c) noexcept {
        return vector{
          vect::sdiv<T, N, V>::apply(a._v, vect::fill<T, N, V>::apply(c))};
    }

    /// @brief Constant division operator.
    friend constexpr auto operator/(T c, _cpT a) noexcept {
        return vector{
          vect::sdiv<T, N, V>::apply(vect::fill<T, N, V>::apply(c), a._v)};
    }
};

/// @brief Returns the dimension of a vector.
/// @ingroup math
template <typename T, int N, bool V>
static constexpr auto dimension(const vector<T, N, V>&) noexcept {
    return span_size_t(N);
}

/// @brief Tests if a vector has zero lenght.
/// @ingroup math
template <typename T, int N, bool V>
static inline auto is_zero(const vector<T, N, V>& v) noexcept -> bool {
    return vect::is_zero<T, N, V>::apply(v._v);
}

template <typename T, int N, bool V>
static constexpr auto _dot(
  const vector<T, N, V>& a,
  const vector<T, N, V>& b,
  std::true_type) noexcept {
    return scalar<T, N, V>{vect::hsum<T, N, V>::apply(a._v * b._v)};
}

template <typename T, int N, bool V>
static constexpr auto _dot(
  const vector<T, N, V>& a,
  const vector<T, N, V>& b,
  std::false_type) noexcept {
    return scalar<T, N, V>{vect::esum<T, N, V>::apply(a._v * b._v)};
}

/// @brief Vector dot product.
/// @ingroup math
template <typename T, int N, bool V>
static constexpr auto
dot(const vector<T, N, V>& a, const vector<T, N, V>& b) noexcept {
    return _dot(a, b, vect::has_vect_data<T, N, V>());
}

/// @brief Returns a vector perpendicular to argument.
/// @ingroup math
template <typename T, bool V>
static inline auto perpendicular(const vector<T, 2, V>& a) noexcept {
    return vector<T, 2, V>{{-a._v[1], a._v[0]}};
}

/// @brief 3D vector cross product.
/// @ingroup math
template <typename T, bool V>
static inline auto
cross(const vector<T, 3, V>& a, const vector<T, 3, V>& b) noexcept {
    using _sh = vect::shuffle<T, 3, V>;
    return vector<T, 3, V>{
      _sh::template apply<1, 2, 0>(a._v) * _sh::template apply<2, 0, 1>(b._v) -
      _sh::template apply<2, 0, 1>(a._v) * _sh::template apply<1, 2, 0>(b._v)};
}

template <typename T, int N, bool V>
static constexpr auto _mag(const vector<T, N, V>& a, std::true_type) noexcept {
    return scalar<T, N, V>{
      vect::sqrt<T, N, V>::apply(vect::hsum<T, N, V>::apply(a._v * a._v))};
}

template <typename T, int N, bool V>
static constexpr auto _mag(const vector<T, N, V> a, std::false_type) noexcept {
    using std::sqrt;
    return scalar<T, N, V>{T(sqrt(vect::esum<T, N, V>::apply(a._v * a._v)))};
}

/// @brief Returns the magnitude of a vector. Same as length.
/// @ingroup math
template <typename T, int N, bool V>
static constexpr auto magnitude(const vector<T, N, V>& a) noexcept {
    return _mag(a, vect::has_vect_data<T, N, V>());
}

/// @brief Returns the length of a vector.
/// @ingroup math
template <typename T, int N, bool V>
static constexpr auto length(const vector<T, N, V>& a) noexcept {
    return magnitude(a);
}

template <typename T, int N, bool V>
static inline auto _nmld(
  const vector<T, N, V>& a,
  const scalar<T, N, V>& l,
  std::true_type) noexcept {
    return vector<T, N, V>{vect::sdiv<T, N, V>::apply(a._v, l._v)};
}

template <typename T, int N, bool V>
static inline auto _nmld(
  const vector<T, N, V>& a,
  const scalar<T, N, V>& l,
  std::false_type) noexcept {
    return vector<T, N, V>{
      vect::sdiv<T, N, V>::apply(a._v, vect::fill<T, N, V>::apply(l._v))};
}

/// @brief Returns normalized argument.
/// @ingroup math
template <typename T, int N, bool V>
static inline auto normalized(const vector<T, N, V>& a) noexcept {
    scalar<T, N, V> l = length(a);
    return _nmld(a, l, vect::has_vect_data<T, N, V>());
}

/// @brief Returns the distance between two vectors.
/// @ingroup math
template <typename T, int N, bool V>
static constexpr auto
distance(const vector<T, N, V>& a, const vector<T, N, V>& b) noexcept {
    return magnitude(a - b);
}

} // namespace math

template <typename T, int N, bool V>
struct is_known_vector_type<math::vector<T, N, V>> : std::is_scalar<T> {};

template <typename T, int N, bool V>
struct canonical_compound_type<math::vector<T, N, V>>
  : type_identity<std::remove_cv_t<T[N]>> {};

template <typename T, int N, bool V>
struct compound_view_maker<math::vector<T, N, V>> {
    inline auto operator()(const math::vector<T, N, V>& v) const noexcept {
        return vect::view<T, N, V>::apply(v._v);
    }
};

} // namespace eagine

#endif // EAGINE_MATH_VECTOR_HPP
