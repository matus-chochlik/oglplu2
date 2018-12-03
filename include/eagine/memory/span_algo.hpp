/**
 *  @file eagine/memory/span_algo.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MEMORY_SPAN_ALGO_HPP
#define EAGINE_MEMORY_SPAN_ALGO_HPP

#include "../std/type_traits.hpp"
#include "span.hpp"
#include <algorithm>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr inline P
clamp_span_iterator(basic_span<T, P, S> s, P p) noexcept {
    return (p < s.begin()) ? s.begin() : (p > s.end()) ? s.end() : p;
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename I>
static constexpr inline std::enable_if_t<std::is_integral_v<I>, P>
clamp_span_position(basic_span<T, P, S> s, I p) noexcept {
    return clamp_span_iterator(s, s.begin() + p);
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename B, typename E>
static constexpr inline std::enable_if_t<
  std::is_integral_v<B> && std::is_integral_v<E>,
  basic_span<T, P, S>>
subspan(basic_span<T, P, S> s, B b, E e) noexcept {
    return {clamp_span_position(s, b), clamp_span_position(s, e)};
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename I, typename L>
static constexpr inline basic_span<T, P, S>
slice(basic_span<T, P, S> s, I i, L l) noexcept {
    return {clamp_span_position(s, i), clamp_span_position(s, i + l)};
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename L>
static constexpr inline basic_span<T, P, S>
skip(basic_span<T, P, S> s, L l) noexcept {
    return slice(s, l, s.size() - l);
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename L>
static constexpr inline basic_span<T, P, S>
snip(basic_span<T, P, S> s, L l) noexcept {
    return head(s, s.size() - l);
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename L>
static constexpr inline basic_span<T, P, S>
head(basic_span<T, P, S> s, L l) noexcept {
    return slice(s, S(0), l);
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename L>
static constexpr inline basic_span<T, P, S>
tail(basic_span<T, P, S> s, L l) noexcept {
    return skip(s, s.size() - l);
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline bool
starts_with(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> with) {
    return are_equal(head(spn, with.size()), with);
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline bool
ends_with(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> with) {
    return are_equal(tail(spn, with.size()), with);
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline basic_span<T1, P1, S1>
strip_prefix(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> prefix) {
    return starts_with(spn, prefix) ? skip(spn, prefix.size()) : spn;
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline basic_span<T1, P1, S1>
strip_suffix(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> suffix) {
    return ends_with(spn, suffix) ? snip(spn, suffix.size()) : spn;
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline S1
contains(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) noexcept {
    for(S1 i = 0; i < spn.size(); ++i) {
        if(starts_with(skip(spn, i), what)) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline optionally_valid<S1> find_position(
  basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) noexcept {
    auto pos = S1(0);
    while(pos < spn.size()) {
        if(starts_with(skip(spn, pos), what)) {
            return {pos, true};
        }
        ++pos;
    }
    return {};
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static constexpr inline optionally_valid<S1> reverse_find_position(
  basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) noexcept {
    auto pos = spn.size();
    while(pos > S1(0)) {
        --pos;
        if(starts_with(skip(spn, pos), what)) {
            return {pos, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static inline basic_span<T1, P1, S1>
slice_before(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) {
    return head(spn, find_position(spn, what).value_or(spn.size()));
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static inline basic_span<T1, P1, S1>
slice_after(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) {
    return skip(
      spn, find_position(spn, what).value_or(spn.size()) + what.size());
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static inline basic_span<T1, P1, S1>
slice_before_last(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) {
    return head(spn, reverse_find_position(spn, what).value_or(spn.size()));
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2>
static inline basic_span<T1, P1, S1>
slice_after_last(basic_span<T1, P1, S1> spn, basic_span<T2, P2, S2> what) {
    return skip(
      spn, reverse_find_position(spn, what).value_or(spn.size()) + what.size());
}
//------------------------------------------------------------------------------
template <
  typename T1,
  typename P1,
  typename S1,
  typename T2,
  typename P2,
  typename S2,
  typename UnaryOperation>
static inline void for_each_delimited(
  basic_span<T1, P1, S1> spn,
  basic_span<T2, P2, S2> delim,
  UnaryOperation unary_op) {
    basic_span<T1, P1, S1> tmp = spn;
    while(auto pos = find_position(tmp, delim)) {
        unary_op(head(tmp, pos.value()));
        tmp = skip(tmp, pos.value() + delim.size());
    }
    unary_op(tmp);
}
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine
#endif // EAGINE_MEMORY_SPAN_ALGO_HPP
