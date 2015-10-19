/**
 *  @file eagine/string_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_VIEW_1509260923_HPP
#define EAGINE_STRING_VIEW_1509260923_HPP

#include "std_fixes.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#endif

#include <string_view.h>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

namespace eagine {

using gsl::string_view;
using gsl::cstring_view;

} // namespace eagine

#endif // include guard
