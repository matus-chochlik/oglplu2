/**
 *  @file oglplus/shapes/init.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>

namespace oglplus {
namespace shapes {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
outcome<void>
initialize_vao_and_buffers(
	vertex_array_name vao,
	const eagine::any_copying_forward_range<buffer_name>& bufs,
	const span<const vertex_attrib_and_location>& vaals,
	const span<draw_operation>& ops,
	const adapted_generator& gen,
	eagine::memory::buffer& data
)
{
	constants  GL;
	operations gl;

	auto vaali = vaals.begin();
	auto vaale = vaals.end();
	auto bufsi = bufs.begin();
	auto bufse = bufs.end();
	(void)bufse;

	if(auto res = failure(gl.bind(vao)))
	{
		return std::move(res);
	}

	while(vaali != vaale)
	{
		assert(bufsi != bufse);

		vertex_attrib_kind attrib(vaali->attrib);
		vertex_attrib_location location(vaali->location);

		data.resize(gen.attrib_data_block_size(attrib));
		gen.attrib_data(attrib, data);

		if(auto res = failure(gl.bind(GL.array_buffer, *bufsi)))
		{
			return std::move(res);
		}

		if(auto res = failure(gl.buffer_data(
			GL.array_buffer,
			buffer_data_spec(data),
			GL.static_draw
		))) { return std::move(res); }

		if(auto res = failure(gl.vertex_array_attrib_pointer(
			location,
			GLint(gen.values_per_vertex(attrib)),
			GL.float_,
			false, 0, nullptr
		))) { return std::move(res); }

		if(auto res = failure(gl.enable_vertex_array_attrib(location)))
		{
			return std::move(res);
		}

		++bufsi;
		++vaali;
	}

	if(gen.indexed())
	{
		assert(bufsi != bufse);

		data.resize(gen.index_data_block_size());
		gen.index_data(data);

		if(auto res = failure(gl.bind(GL.element_array_buffer, *bufsi)))
		{
			return std::move(res);
		}

		if(auto res = failure(gl.buffer_data(
			GL.element_array_buffer,
			buffer_data_spec(data),
			GL.static_draw
		))) { return std::move(res); }
	}

	gen.instructions(ops);

	return {};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglplus
//------------------------------------------------------------------------------

