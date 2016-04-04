/**
 *  @file oglplus/texgen/render_params.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_RENDER_PARAMS_1509260923_HPP
#define OGLPLUS_TEXGEN_RENDER_PARAMS_1509260923_HPP

#include <eagine/bitfield.hpp>

namespace oglplus {
namespace texgen {

struct output_intf;

enum class render_param_bit : int
{
	normalized_coords = 1 <<  0,
	pixel_size        = 1 <<  1,
	pixel_offset      = 1 <<  2,
	sample_offset     = 1 <<  3
};

typedef eagine::bitfield<render_param_bit> render_param_bits;

static constexpr inline
render_param_bits
operator | (render_param_bit a, render_param_bit b)
noexcept
{
	return {a, b};
}

static constexpr inline
render_param_bits
all_render_params(void)
noexcept
{
	return	render_param_bit::normalized_coords|
		render_param_bit::pixel_size|
		render_param_bit::pixel_offset|
		render_param_bit::sample_offset;
}

struct render_params
{
	std::size_t version;
	unsigned width;
	unsigned height;
};

} // namespace texgen
} // namespace oglplus

#endif // include guard
