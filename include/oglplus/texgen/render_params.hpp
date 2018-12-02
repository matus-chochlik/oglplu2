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

enum class render_param_bit : int {
    normalized_coord = 1 << 0,
    voxel_size = 1 << 1,
    voxel_offset = 1 << 2,
    element_offset = 1 << 3
};

typedef eagine::bitfield<render_param_bit> render_param_bits;

static constexpr inline render_param_bits
operator|(render_param_bit a, render_param_bit b) noexcept {
    return {a, b};
}

static constexpr inline render_param_bits
all_render_params() noexcept {
    return render_param_bit::normalized_coord | render_param_bit::voxel_size |
           render_param_bit::voxel_offset | render_param_bit::element_offset;
}

struct render_params {
    unsigned version;
    int width;
    int height;
};

} // namespace texgen
} // namespace oglplus

#endif // include guard
