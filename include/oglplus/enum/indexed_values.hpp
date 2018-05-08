/**
 *  @file oglplus/enum/indexed_values.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_INDEXED_VALUES_1509260923_HPP
#define OGLPLUS_ENUM_INDEXED_VALUES_1509260923_HPP

#include "indexed_types.hpp"

namespace oglplus {

struct indexed_enum_values {
#ifdef GL_TEXTURE0
    static constexpr const indexed_enum_base<GL_TEXTURE0> texture0 = {};
#endif

#ifdef GL_DRAW_BUFFER0
    static constexpr const indexed_enum_base<GL_DRAW_BUFFER0> draw_buffer0 = {};
#endif

#ifdef GL_CLIP_DISTANCE0
    static constexpr const indexed_enum_base<GL_CLIP_DISTANCE0> clip_distance0 =
      {};
#endif

#ifdef GL_COLOR_ATTACHMENT0
    static constexpr const indexed_enum_base<GL_COLOR_ATTACHMENT0>
      color_attachment0 = {};
#endif
};

} // namespace oglplus

#endif // include guard
