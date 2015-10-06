/**
 *  @file oglplus/utils/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_ENUM_CLASS_1509260923_HPP
#define OGLPLUS_UTILS_ENUM_CLASS_1509260923_HPP

#include <eagine/enum_class.hpp>
#include <eagine/enum_bitfield.hpp>

namespace oglplus {

using eagine::enum_value;

template <typename Self, typename T, unsigned Id>
using enum_class = eagine::enum_class<Self, T, 0, Id>;

using eagine::enum_bitfield;

using any_enum_class = eagine::any_enum_class<0>;
using any_enum_value = eagine::any_enum_value<0>;

} // namespace oglplus

#endif // include guard
