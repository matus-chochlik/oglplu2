/**
 *  @file oglplus/shapes/init.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_INIT_HPP
#define OGLPLUS_SHAPES_INIT_HPP

#include "../buffer_name.hpp"
#include "../vertex_array_name.hpp"
#include "adapted_gen.hpp"
#include <eagine/any_iterator.hpp>
#include <eagine/memory/buffer.hpp>

namespace eagine {
namespace oglp {
namespace shapes {

outcome<void> initialize_vao_and_buffers(
  vertex_array_name vao,
  const any_copying_forward_range<buffer_name>& bufs,
  span<const vertex_attrib_and_location> vaals,
  span<draw_operation> ops,
  const adapted_generator& gen,
  memory::buffer& data);

} // namespace shapes
} // namespace oglp
} // namespace eagine

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/init.inl>
#endif

#endif // OGLPLUS_SHAPES_INIT_HPP
