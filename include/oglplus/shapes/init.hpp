/**
 *  @file oglplus/shapes/init.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_INIT_1509260923_HPP
#define OGLPLUS_SHAPES_INIT_1509260923_HPP

#include <eagine/memory/buffer.hpp>
#include <eagine/any_iterator.hpp>
#include "adapted_gen.hpp"
#include "../buffer_name.hpp"
#include "../vertex_array_name.hpp"

namespace oglplus {
namespace shapes {

outcome<void>
initialize_vao_and_buffers(
	vertex_array_name vao,
	const eagine::any_copying_forward_range<buffer_name>& bufs,
	const span<const vertex_attrib_and_location>& vaals,
	const span<draw_operation>& ops,
	const adapted_generator& gen,
	eagine::memory::buffer& data
);

} // namespace shapes
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/init.inl>
#endif

#endif // include guard
