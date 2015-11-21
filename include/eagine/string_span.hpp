/**
 *  @file eagine/string_span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_SPAN_1509260923_HPP
#define EAGINE_STRING_SPAN_1509260923_HPP

#include "type_traits.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshadow"
#endif

#include <string_span.h>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

namespace eagine {

using gsl::string_span;
using gsl::cstring_span;

} // namespace eagine

#endif // include guard
