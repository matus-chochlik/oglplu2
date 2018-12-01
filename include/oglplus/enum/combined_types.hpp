/**
 *  @file oglplus/enum/indexed_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_COMBINED_TYPES_1509260923_HPP
#define OGLPLUS_ENUM_COMBINED_TYPES_1509260923_HPP

#include "../utils/combined_enum.hpp"
#include "indexed_types.hpp"
#include "types.hpp"

namespace oglplus {

typedef combined_enum_value<
  framebuffer_other_attachment,
  framebuffer_color_attachment>
  framebuffer_attachment;

} // namespace oglplus

#endif // include guard
