/**
 *  @file oglplus/utils/indexed_enum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_INDEXED_ENUM_1509260923_HPP
#define OGLPLUS_UTILS_INDEXED_ENUM_1509260923_HPP

#include <eagine/indexed_enum.hpp>

namespace oglplus {

template <typename T, T Base>
using indexed_enum_base = eagine::indexed_enum_base<T, Base, 0>;

template <typename T, T Base>
using indexed_enum_class = eagine::indexed_enum_class<T, Base, 0>;

} // namespace oglplus

#endif // include guard
