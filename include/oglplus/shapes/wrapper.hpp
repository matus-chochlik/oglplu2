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

namespace oglplus {
namespace shapes {

// base_wrapper
template <std::size_t N>
class base_wrapper
{
private:
	vertex_array _vao;
	buffer_array<N+1> _bufs;
	std::vector<draw_operation> _ops;
public:
	base_wrapper(
		eagine::memory::buffer& data,
		const adapted_generator& gen,
		const span<const vertex_attrib_and_location>& vaals
	): _bufs()
	 , _ops(gen.operation_count())
	{
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
	template <std::size_t M>
	static inline
	span<const vertex_attrib_and_location>
	_as_span(const std::array<vertex_attrib_and_location, M>& a)
	noexcept
	{
		return a;
	}
public:
	template <
		typename Generator,
		typename ... P,
		typename = std::enable_if<
			(sizeof ... (P) == N) &&
			eagine::all_are_same<
				vertex_attrib_and_location,
				P...
			>::value
		>
	>
	wrapper(
		eagine::identity<Generator>,
		eagine::memory::buffer& tmp_buf,
		const P& ... p
	): base_wrapper<N>(
		tmp_buf,
		Generator(eagine::shapes::get_attrib_bits(p...)),
		_as_span(eagine::make_array(p...))
	)
	{ }
};

// generator_wrapper
template <typename Generator, std::size_t N>
class generator_wrapper
 : public wrapper<N>
{
public:
	template <
		typename ... P,
		typename = std::enable_if<
			(sizeof ... (P) == N) &&
			eagine::all_are_same<
				vertex_attrib_and_location,
				P...
			>::value
		>
	>
	generator_wrapper(eagine::memory::buffer& tmp_buf, const P& ... p)
	 : wrapper<N>(eagine::identity<Generator>(), tmp_buf, p...)
	{ }
};

} // namespace shapes
} // namespace oglplus

#endif // include guard
