/**
 *  @file oglplus/shapes/wrapper.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_WRAPPER_1509260923_HPP
#define OGLPLUS_SHAPES_WRAPPER_1509260923_HPP

#include "init.hpp"
#include "drawing.hpp"
#include <eagine/make_array.hpp>
#include <vector>
#include <cassert>

namespace oglplus {
namespace shapes {

// base_wrapper
template <std::size_t N, bool InclElemBuf = true>
class base_wrapper
{
private:
	vertex_array _vao;
	buffer_array<N+(InclElemBuf?1:0)> _bufs;
	std::vector<draw_operation> _ops;
public:
	base_wrapper(
		eagine::memory::buffer& data,
		const adapted_generator& gen,
		const span<const vertex_attrib_and_location>& vaals
	): _bufs()
	 , _ops(gen.operation_count())
	{
		assert(vaals.size() >= span_size_type(N));
		initialize_vao_and_buffers(_vao, _bufs, vaals, _ops, gen, data);
	}

	outcome<void> use(void)
	noexcept
	{
		oper::vertex_array_ops gl;
		return gl.bind_vertex_array(_vao);
	}

	outcome<void> draw(void) const
	noexcept
	{
		return draw_using_instructions(as_span(_ops));
	}
};

// wrapper
template <std::size_t N>
class wrapper
 : public base_wrapper<N>
{
private:
	static inline
	span<const vertex_attrib_and_location>
	_as_span(const std::array<const vertex_attrib_and_location, N>& a)
	noexcept
	{
		return {a.data(), span_size_type(a.size())};
	}
public:
	template <typename Generator, typename ... P>
	wrapper(
		eagine::identity<Generator>,
		eagine::memory::buffer& tmp_buf,
		const std::array<const vertex_attrib_and_location, N>& vaals,
		P&& ... p
	): base_wrapper<N>(
		tmp_buf,
		Generator(
			eagine::shapes::get_attrib_bits(vaals),
			std::forward<P>(p)...
		),
		_as_span(vaals)
	)
	{ }
};

// generator_wrapper
template <typename Generator, std::size_t N>
class generator_wrapper
 : public wrapper<N>
{
public:
	template <typename ... P>
	generator_wrapper(
		eagine::memory::buffer& tmp_buf,
		const std::array<const vertex_attrib_and_location, N>& vaals,
		P&& ... p
	): wrapper<N>(
		eagine::identity<Generator>(),
		tmp_buf,
		vaals,
		std::forward<P>(p)...
	)
	{ }
};

} // namespace shapes
} // namespace oglplus

#endif // include guard
