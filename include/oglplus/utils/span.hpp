/**
 *  @file oglplus/utils/span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_SPAN_HPP
#define OGLPLUS_UTILS_SPAN_HPP

#include "types.hpp"
#include <eagine/span.hpp>

namespace oglplus {

using eagine::cover;
using eagine::span;
using eagine::view;
using eagine::memory::accomodate;
using eagine::memory::can_accomodate;

} // namespace oglplus

#endif // OGLPLUS_UTILS_SPAN_HPP
