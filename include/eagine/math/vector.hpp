/**
 *  @file eagine/math/vector.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
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

template <typename T, int N, bool V>
struct vector {
    using type = vector;
    using scalar_type = scalar<T, N, V>;

    using value_type = T;

    using is_vectorized = vect::has_vect_data_t<T, N, V>;

    using data_type = vect::data_t<T, N, V>;

    data_type _v;

    using _cpT = const vector&;
    using _cspT = const scalar_type&;

    static inline vector zero() noexcept {
        return vector{vect::fill<T, N, V>::apply(T(0))};
    }

    static inline vector fill(T v) noexcept {
        return vector{vect::fill<T, N, V>::apply(v)};
    }

    template <int I>
    static inline vector axis() noexcept {
        return vector{vect::axis<T, N, I, V>::apply(T(1))};
    }

    template <int I>
    static inline vector axis(T v) noexcept {
        return vector{vect::axis<T, N, I, V>::apply(v)};
    }

    static inline vector axis(int i, T v) noexcept {
        EAGINE_ASSERT(i < N);
        vector r = zero();
        r._v[i] = v;
        return r;
    }

    template <
      typename P,
      typename = std::enable_if_t<(N == 1) && (std::is_convertible_v<P, T>)>>
    static constexpr inline vector make(P&& p) noexcept {
        return vector{{T(std::forward<P>(p))}};
    }

    template <
      typename... P,
      typename = std::enable_if_t<(N > 1) && (sizeof...(P) == N)>>
    static constexpr inline vector make(P&&... p) noexcept {
        return vector{{T(std::forward<P>(p))...}};
    }

    template <
      typename P,
      int M,
      bool W,
      typename =
        std::enable_if_t<(!std::is_same_v<T, P> || (N != M) || (V != W))>>
    static constexpr inline vector
    from(const vector<P, M, W>& v, T d = T(0)) noexcept {
        return vector{vect::cast<P, M, W, T, N, V>::apply(v._v, d)};
    }

    template <typename P, int M, bool W>
    static constexpr inline vector
    from(const vector<P, M, W>& v, const vector<T, N - M, W>& u) noexcept {
        return vector{vect::cast<P, M, W, T, N, V>::apply(v._v, u._v)};
    }

    static inline vector from(const T* dt, span_size_t sz) noexcept {
        return vector{vect::from_array<T, N, V>::apply(dt, sz)};
    }

    static inline vector from(const T* dt, span_size_t sz, T fv) noexcept {
        return vector{vect::from_saafv<T, N, V>::apply(dt, sz, fv)};
    }

    constexpr inline T operator[](int pos) const noexcept {
        return _v[pos];
    }

    template <int M = N>
    constexpr inline std::enable_if_t<(M > 0), T> x() const noexcept {
        static_assert(M == N);
        return _v[0];
    }

    template <int M = N>
    constexpr inline std::enable_if_t<(M > 1), T> y() const noexcept {
        static_assert(M == N);
        return _v[1];
    }

    template <int M = N>
    constexpr inline std::enable_if_t<(M > 2), T> z() const noexcept {
        static_assert(M == N);
        return _v[2];
    }

    template <int M = N>
    constexpr inline std::enable_if_t<(M > 3), T> w() const noexcept {
        static_assert(M == N);
        return _v[3];
    }

    friend constexpr vector operator+(_cpT a) noexcept {
        return a;
    }

    friend constexpr vector operator-(_cpT a) noexcept {
        return vector{-a._v};
    }

    friend constexpr vector operator+(_cpT a, _cpT b) noexcept {
        return vector{a._v + b._v};
    }

    vector& operator+=(_cpT a) noexcept {
        _v = _v + a._v;
        return *this;
    }

    friend constexpr vector operator-(_cpT a, _cpT b) noexcept {
        return vector{a._v - b._v};
    }

    vector& operator-=(_cpT a) noexcept {
        _v = _v - a._v;
        return *this;
    }

    friend constexpr vector operator*(_cpT a, _cpT b) noexcept {
        return vector{a._v * b._v};
    }

    vector& operator*=(_cpT a) noexcept {
        _v = _v * a._v;
        return *this;
    }

    template <typename Vec = vector>
    friend constexpr std::enable_if_t<scalar_type::is_vectorized::value, Vec>
    operator*(_cspT c, _cpT a) noexcept {
        return vector{c._v * a._v};
    }

    template <typename Vec = vector>
    friend constexpr std::enable_if_t<scalar_type::is_vectorized::value, Vec>
    operator*(_cpT a, _cspT c) noexcept {
        return vector{a._v * c._v};
    }

    template <typename Vec = vector>
    std::enable_if_t<scalar_type::is_vectorized::value, Vec>&
    operator*=(_cspT c) noexcept {
        _v = _v * c._v;
        return *this;
    }

    friend constexpr vector operator*(T c, _cpT a) noexcept {
        return vector{a._v * vect::fill<T, N, V>::apply(c)};
    }

    friend constexpr vector operator*(_cpT a, T c) noexcept {
        return vector{a._v * vect::fill<T, N, V>::apply(c)};
    }

    vector& operator*=(T c) noexcept {
        _v = _v * vect::fill<T, N, V>::apply(c);
        return *this;
    }

    friend constexpr vector operator/(_cpT a, _cpT b) noexcept {
        return vector{vect::sdiv<T, N, V>::apply(a._v, b._v)};
    }

    template <typename Vec = vector>
    friend constexpr std::enable_if_t<scalar_type::is_vectorized::value, Vec>
    operator/(_cspT c, _cpT a) noexcept {
        return vector{vect::sdiv<T, N, V>::apply(c._v, a._v)};
    }

    template <typename Vec = vector>
    friend constexpr std::enable_if_t<scalar_type::is_vectorized::value, Vec>
    operator/(_cpT a, _cspT c) noexcept {
        return vector{vect::sdiv<T, N, V>::apply(a._v, c._v)};
    }

    friend constexpr vector operator/(_cpT a, T c) noexcept {
        return vector{
          vect::sdiv<T, N, V>::apply(a._v, vect::fill<T, N, V>::apply(c))};
    }

    friend constexpr vector operator/(T c, _cpT a) noexcept {
        return vector{
          vect::sdiv<T, N, V>::apply(vect::fill<T, N, V>::apply(c), a._v)};
    }
};

template <typename T, int N, bool V>
static constexpr inline span_size_t dimension(const vector<T, N, V>&) noexcept {
    return span_size_t(N);
}

template <typename T, int N, bool V>
static inline bool is_zero(const vector<T, N, V>& v) noexcept {
    return vect::is_zero<T, N, V>::apply(v._v);
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V> _dot(
  const vector<T, N, V>& a,
  const vector<T, N, V>& b,
  std::true_type) noexcept {
    return scalar<T, N, V>{vect::hsum<T, N, V>::apply(a._v * b._v)};
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V> _dot(
  const vector<T, N, V>& a,
  const vector<T, N, V>& b,
  std::false_type) noexcept {
    return scalar<T, N, V>{vect::esum<T, N, V>::apply(a._v * b._v)};
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V>
dot(const vector<T, N, V>& a, const vector<T, N, V>& b) noexcept {
    return _dot(a, b, vect::has_vect_data<T, N, V>());
}

// perpendicular
template <typename T, bool V>
static inline vector<T, 2, V> perpendicular(const vector<T, 2, V>& a) noexcept {
    return vector<T, 2, V>{{-a._v[1], a._v[0]}};
}

// cross
template <typename T, bool V>
static inline vector<T, 3, V>
cross(const vector<T, 3, V>& a, const vector<T, 3, V>& b) noexcept {
    using _sh = vect::shuffle<T, 3, V>;
    return vector<T, 3, V>{
      _sh::template apply<1, 2, 0>(a._v) * _sh::template apply<2, 0, 1>(b._v) -
      _sh::template apply<2, 0, 1>(a._v) * _sh::template apply<1, 2, 0>(b._v)};
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V>
_mag(const vector<T, N, V> a, std::true_type) noexcept {
    return scalar<T, N, V>{
      vect::sqrt<T, N, V>::apply(vect::hsum<T, N, V>::apply(a._v * a._v))};
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V>
_mag(const vector<T, N, V> a, std::false_type) noexcept {
    using std::sqrt;
    return scalar<T, N, V>{T(sqrt(vect::esum<T, N, V>::apply(a._v * a._v)))};
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V>
magnitude(const vector<T, N, V>& a) noexcept {
    return _mag(a, vect::has_vect_data<T, N, V>());
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V>
length(const vector<T, N, V>& a) noexcept {
    return magnitude(a);
}

template <typename T, int N, bool V>
static inline vector<T, N, V> _nmld(
  const vector<T, N, V>& a,
  const scalar<T, N, V>& l,
  std::true_type) noexcept {
    return {vect::sdiv<T, N, V>::apply(a._v, l._v)};
}

template <typename T, int N, bool V>
static inline vector<T, N, V> _nmld(
  const vector<T, N, V>& a,
  const scalar<T, N, V>& l,
  std::false_type) noexcept {
    return {vect::sdiv<T, N, V>::apply(a._v, vect::fill<T, N, V>::apply(l._v))};
}

template <typename T, int N, bool V>
static inline vector<T, N, V> normalized(const vector<T, N, V>& a) noexcept {
    scalar<T, N, V> l = length(a);
    return _nmld(a, l, vect::has_vect_data<T, N, V>());
}

template <typename T, int N, bool V>
static constexpr inline scalar<T, N, V>
distance(const vector<T, N, V>& a, const vector<T, N, V>& b) noexcept {
    return magnitude(a - b);
}

} // namespace math

template <typename T, int N, bool V>
struct is_known_vector_type<math::vector<T, N, V>> : std::is_scalar<T> {};

template <typename T, int N, bool V>
struct canonical_compound_type<math::vector<T, N, V>>
  : identity<std::remove_cv_t<T[N]>> {};

template <typename T, int N, bool V>
struct compound_view_maker<math::vector<T, N, V>> {
    inline auto operator()(const math::vector<T, N, V>& v) const noexcept {
        return vect::view<T, N, V>::apply(v._v);
    }
};

} // namespace eagine

#endif // EAGINE_MATH_VECTOR_HPP
