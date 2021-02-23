/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_TVEC_HPP
#define EAGINE_MATH_TVEC_HPP

#include "../all_are_same.hpp"
#include "../memory/flatten_fwd.hpp"
#include "vector.hpp"

namespace eagine {
namespace math {

/// @brief Generic template for N-dimensional vectors.
/// @ingroup math
template <typename T, int N, bool V>
struct tvec : vector<T, N, V> {
    /// @brief The base vector type.
    using base = vector<T, N, V>;

    /// @brief Default constructor. Constructs a zero vector.
    constexpr tvec() noexcept
      : base{base::zero()} {}

    /// @brief Constructor initializing all coordinates to @p v.
    constexpr tvec(T v) noexcept
      : base{base::fill(v)} {}

    /// @brief Construction from base vector.
    constexpr tvec(const base& v) noexcept
      : base{v} {}

    /// @brief Construction from native array.
    tvec(const T (&d)[N]) noexcept
      : base{base::from(static_cast<const T*>(d), N)} {}

    /// @brief Construction from coordinates.
    template <
      typename... P,
      typename = std::enable_if_t<
        (sizeof...(P) == N) && all_are_convertible_to<T, P...>::value>>
    constexpr tvec(P&&... p) noexcept
      : base{base::make(std::forward<P>(p)...)} {}

    /// @brief Construction from vector of different dimensionality.
    template <
      typename P,
      int M,
      bool W,
      typename = std::enable_if_t<!std::is_same_v<P, T> || !(M == N)>>
    constexpr tvec(const vector<P, M, W>& v) noexcept
      : base{base::from(v)} {}

    /// @brief Construction from vector of different dimensionality.
    template <typename P, int M, bool W>
    constexpr tvec(const vector<P, M, W>& v, T d) noexcept
      : base{base::from(v, d)} {}

    /// @brief Construction from vector of different dimensionality.
    template <
      typename P,
      int M,
      bool W,
      typename... R,
      typename = std::enable_if_t<
        (sizeof...(R) > 1) && (M + sizeof...(R) == N) &&
        all_are_convertible_to<T, R...>::value>>
    constexpr tvec(const vector<P, M, W>& v, R&&... r) noexcept
      : base{base::from(v, vector<T, N - M, W>::make(std::forward<R>(r)...))} {}

    /// @brief Construction from a pair of vectors of different dimensionality.
    template <typename P, int M, bool W>
    constexpr tvec(
      const vector<P, M, W>& v,
      const vector<T, N - M, W>& w) noexcept
      : base{base::from(v, w)} {}
};

} // namespace math

template <typename T, int N, bool V>
struct is_known_vector_type<math::tvec<T, N, V>> : std::is_scalar<T> {};

template <typename T, int N, bool V>
struct canonical_compound_type<math::tvec<T, N, V>>
  : type_identity<std::remove_cv_t<T[N]>> {};

template <typename T, int N, bool V>
struct compound_view_maker<math::tvec<T, N, V>> {
    auto operator()(const math::vector<T, N, V>& v) const noexcept {
        return vect::view<T, N, V>::apply(v._v);
    }
};

template <typename T, int N, bool V>
struct flatten_traits<math::tvec<T, N, V>, T> {

    template <typename Ps, typename Ss>
    static constexpr auto required_size(
      memory::basic_span<const math::tvec<T, N, V>, Ps, Ss> src) noexcept
      -> span_size_t {
        return src.size() * N;
    }

    template <typename Pd, typename Sd>
    static auto apply(
      const math::tvec<T, N, V>& src,
      memory::basic_span<T, Pd, Sd> dst) noexcept {
        EAGINE_ASSERT(N <= dst.size());
        _do_apply(src._v, dst, std::make_index_sequence<std::size_t(N)>{});
        return skip(dst, N);
    }

private:
    template <typename Pd, typename Sd, std::size_t... I>
    static void _do_apply(
      vect::data_t<T, N, V> src,
      memory::basic_span<T, Pd, Sd> dst,
      std::index_sequence<I...>) noexcept {
        ((dst[I] = src[I]), ...);
    }
};

} // namespace eagine

#endif // EAGINE_MATH_TVEC_HPP
