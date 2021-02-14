/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_FLATTEN_HPP
#define EAGINE_MEMORY_FLATTEN_HPP

#include "../all_are_same.hpp"
#include "flatten_fwd.hpp"
#include "span_algo.hpp"
#include <array>
#include <tuple>
#include <utility>
#include <vector>

namespace eagine {

template <typename Src, typename Dst>
struct flatten_traits;

namespace memory {
//------------------------------------------------------------------------------
template <
  typename Ts,
  typename Ps,
  typename Ss,
  typename Td,
  typename Pd,
  typename Sd>
auto flatten(basic_span<Ts, Ps, Ss> src, basic_span<Td, Pd, Sd> dst) noexcept
  -> basic_span<Td, Pd, Sd> {
    flatten_traits<std::remove_cv_t<Ts>, Td> traits{};
    EAGINE_ASSERT(traits.required_size(src) <= dst.size());

    auto tmp = dst;
    for(auto& elem : src) {
        tmp = traits.apply(elem, tmp);
    }
    return head(dst, dst.size() - tmp.size());
}
//------------------------------------------------------------------------------
template <typename Ts, typename Ps, typename Ss, typename Td, typename A>
auto flatten(basic_span<Ts, Ps, Ss> src, std::vector<Td, A>& dst) -> auto& {
    flatten_traits<std::remove_cv_t<Ts>, Td> traits{};
    dst.resize(std_size(traits.required_size(src)));
    flatten(src, cover(dst));
    return dst;
}
//------------------------------------------------------------------------------
} // namespace memory

template <typename Ts, std::size_t N, typename Td>
struct flatten_traits<std::array<Ts, N>, Td> {
    static_assert(std::is_convertible_v<Ts, Td>);

    template <typename Ps, typename Ss>
    static constexpr auto required_size(
      memory::basic_span<const std::array<Ts, N>, Ps, Ss> src) noexcept
      -> span_size_t {
        return src.size() * span_size(N);
    }

    template <typename Pd, typename Sd>
    static auto apply(
      const std::array<Ts, N>& src,
      memory::basic_span<Td, Pd, Sd> dst) noexcept {
        EAGINE_ASSERT(span_size(N) <= dst.size());
        copy(view(src), dst);
        return skip(dst, span_size(N));
    }
};
//------------------------------------------------------------------------------
template <typename T, typename... P>
struct flatten_traits<std::tuple<P...>, T> {
    static_assert(all_are_convertible_to_v<T, P...>);

    template <typename Ps, typename Ss>
    static constexpr auto required_size(
      memory::basic_span<const std::tuple<P...>, Ps, Ss> src) noexcept
      -> span_size_t {
        return src.size() * span_size(sizeof...(P));
    }

    template <typename Pd, typename Sd>
    static auto apply(
      const std::tuple<P...>& src,
      memory::basic_span<T, Pd, Sd> dst) noexcept {
        EAGINE_ASSERT(span_size(sizeof...(P)) <= dst.size());
        _do_apply(src, dst, std::make_index_sequence<sizeof...(P)>{});
        return skip(dst, span_size(sizeof...(P)));
    }

private:
    template <typename Pd, typename Sd, std::size_t... I>
    static void _do_apply(
      const std::tuple<P...>& src,
      memory::basic_span<T, Pd, Sd> dst,
      std::index_sequence<I...>) noexcept {
        ((dst[I] = T(std::get<I>(src))), ...);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MEMORY_FLATTEN_HPP
