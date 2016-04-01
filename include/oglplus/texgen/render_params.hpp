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

enum class render_param : int
{
	normalized_coords = 1 <<  0,
	pixel_size        = 1 <<  1,
	pixel_offset      = 1 <<  2,
	sample_offset     = 1 <<  3
};

typedef eagine::bitfield<render_param> render_params;

static constexpr inline
render_params
operator | (render_param a, render_param b)
noexcept
{
	return {a, b};
}

static constexpr inline
render_params
all_render_params(void)
noexcept
{
	return	render_param::normalized_coords|
		render_param::pixel_size|
		render_param::pixel_offset|
		render_param::sample_offset;
}

} // namespace texgen
} // namespace oglplus

#endif // include guard
