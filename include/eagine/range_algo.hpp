/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_RANGE_ALGO_HPP
#define EAGINE_RANGE_ALGO_HPP

#include "compare.hpp"
#include "count.hpp"
#include "extract.hpp"
#include "range_types.hpp"
#include "valid_if/le_size_ge0.hpp"
#include "valid_if/nonnegative.hpp"

namespace eagine {
namespace ranges {
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline Range1 find(const Range1& where, const Range2& what) {
    if(auto pos = find_pos(where, what)) {
        return slice(where, extract(pos));
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline Range1 slice_before(const Range1& rng, const Range2& what) {
    return slice(rng, 0, extract_or(find_pos(rng, what), rng.size()));
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline Range1 slice_before_last(const Range1& rng, const Range2& what) {
    return slice(rng, 0, extract_or(rfind_pos(rng, what), 0));
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline Range1 slice_after(const Range1& rng, const Range2& what) {
    if(auto pos = find_pos(rng, what)) {
        return slice(rng, extract(pos) + what.size());
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline Range1 slice_after_last(const Range1& rng, const Range2& what) {
    if(auto pos = rfind_pos(rng, what)) {
        return slice(rng, extract(pos) + what.size());
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2, typename Range3>
static inline Range1
slice_between(const Range1& rng, const Range2& bgn, const Range3& end) {
    if(auto bpos = find_pos(rng, bgn)) {
        if(auto epos = find_pos(slice(rng, extract(bpos) + bgn.size()), end)) {
            return slice(rng, extract(bpos) + bgn.size(), extract(epos));
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2, typename Range3>
static inline Range1
slice_inside(const Range1& rng, const Range2& bgn, const Range3& end) {
    if(auto bpos = find_pos(rng, bgn)) {
        if(auto epos = rfind_pos(rng, end)) {
            if(extract(bpos) + bgn.size() < extract(epos)) {
                return slice(
                  rng,
                  extract(bpos) + bgn.size(),
                  extract(epos) - bgn.size() - 1);
            }
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline span_size_t count(Range1 where, const Range2& what) {
    span_size_t result = 0;
    while(auto pos = find_pos(where, what)) {
        ++result;
        where = slice(where, extract(pos) + what.size());
    }
    return result;
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2, typename UnaryOperation>
static inline UnaryOperation for_each_delimited(
  const Range1& str,
  const Range2& delim,
  UnaryOperation unary_op) {
    Range1 tmp = str;
    while(auto pos = find_pos(tmp, delim)) {
        unary_op(head(tmp, extract(pos)));
        tmp = slice(tmp, extract(pos) + delim.size());
    }
    unary_op(tmp);
    return unary_op;
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2, typename BinaryOperation>
static inline BinaryOperation for_each_delimiter(
  const Range1& str,
  const Range2& delim,
  BinaryOperation binary_op) {
    Range1 tmp = str;
    if(auto p1 = find_pos(tmp, delim)) {
        Range1 prev = head(tmp, extract(p1));
        tmp = slice(tmp, extract(p1) + delim.size());

        while(auto pos = find_pos(tmp, delim)) {
            Range1 curr = head(tmp, extract(pos));
            binary_op(prev, curr);
            prev = curr;
            tmp = slice(tmp, extract(pos) + delim.size());
        }

        binary_op(prev, tmp);
    }
    return binary_op;
}
//------------------------------------------------------------------------------
template <typename Range1, typename Range2>
static inline span_size_t
count_delimited(const Range1& where, const Range2& delim) {
    return for_each_delimited(where, delim, count_t<span_size_t>());
}
//------------------------------------------------------------------------------
template <
  typename BackInsertionSequence,
  typename Range1,
  typename Range2,
  typename Transform>
static inline BackInsertionSequence& split_into(
  BackInsertionSequence& dest,
  const Range1& rng,
  const Range2& delim,
  Transform transform) {
    for_each_delimited(rng, delim, [&dest, &transform](const auto& x) {
        dest.push_back(transform(x));
    });
    return dest;
}
//------------------------------------------------------------------------------
template <typename BackInsertionSequence, typename Range1, typename Range2>
static inline BackInsertionSequence&
split_into(BackInsertionSequence& dest, const Range1& rng, const Range2& delim) {
    return split_into(dest, rng, delim, [](const auto& x) {
        return typename BackInsertionSequence::value_type(x);
    });
}
//------------------------------------------------------------------------------
template <
  typename BackInsertionSequence,
  typename Range1,
  typename Range2,
  typename Transform>
static inline BackInsertionSequence
split(const Range1& rng, const Range2& delim, Transform transform) {
    BackInsertionSequence result;
    return std::move(split_into(result, rng, delim, transform));
}
//------------------------------------------------------------------------------
template <typename BackInsertionSequence, typename Range1, typename Range2>
static inline BackInsertionSequence
split(const Range1& rng, const Range2& delim) {
    BackInsertionSequence result;
    return std::move(split_into(result, rng, delim));
}
//------------------------------------------------------------------------------
} // namespace ranges
} // namespace eagine

#endif // EAGINE_RANGE_ALGO_HPP
