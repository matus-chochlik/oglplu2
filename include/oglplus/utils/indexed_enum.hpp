/**
 *  @file oglplus/utils/indexed_enum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_INDEXED_ENUM_HPP
#define OGLPLUS_UTILS_INDEXED_ENUM_HPP

#include <eagine/indexed_enum.hpp>

namespace oglplus {

template <GLenum Base>
using indexed_enum_base = eagine::indexed_enum_base<GLenum, Base, 0>;

template <GLenum Base>
using indexed_enum_value = eagine::indexed_enum_value<GLenum, Base, 0>;

using any_indexed_enum_value = eagine::any_indexed_enum_value<GLenum, 0>;

} // namespace oglplus

#endif // OGLPLUS_UTILS_INDEXED_ENUM_HPP
