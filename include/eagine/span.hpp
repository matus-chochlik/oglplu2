/**
 *  @file eagine/span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SPAN_1509260923_HPP
#define EAGINE_SPAN_1509260923_HPP

#include "span_fwd.hpp"
#include "types.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wdeprecated"
#pragma clang diagnostic ignored "-Wshadow"
#endif

#include <gsl/span>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <initializer_list>

namespace eagine {

using gsl::make_span;
using gsl::span;

template <typename T>
static inline span<const T> make_span(std::initializer_list<T> il) noexcept {
    return {il.begin(), span_size_t(il.size())};
}

} // namespace eagine

#endif // include guard
