/**
 *  @file oglplus/utils/array_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_ARRAY_VIEW_1509260923_HPP
#define OGLPLUS_UTILS_ARRAY_VIEW_1509260923_HPP

#include "std_fixes.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#endif

#include <array_view.h>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

namespace oglplus {

using Guide::array_view;

} // namespace oglplus

#endif // include guard
