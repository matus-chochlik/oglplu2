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

#include <eagine/all_are_same.hpp>
#include "init.hpp"
#include "drawing.hpp"
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
	static constexpr inline
	vertex_attrib_bits _get_bits(const vertex_attrib_and_location& vaal)
	noexcept
	{
		return vaal.attrib;
	}

	template <typename ... P>
	static constexpr inline
	vertex_attrib_bits _get_bits(
		const vertex_attrib_and_location& vaal1,
		const vertex_attrib_and_location& vaal2,
		const P& ... vaaln
	)
	{
		return _get_bits(vaal2, vaaln...) | vaal1.attrib;
	}

	template <typename ... P>
	static inline
	std::array<vertex_attrib_and_location, sizeof ... (P)>
	_pack(const P& ... p)
	noexcept
	{
		return {{p...}};
	}
	

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
		Generator(_get_bits(p...)),
		_as_span(_pack(p...))
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
