/**
 *  @file oglplus/texgen/render_params.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_RENDER_PARAMS_HPP
#define OGLPLUS_TEXGEN_RENDER_PARAMS_HPP

#include <eagine/bitfield.hpp>

namespace eagine {
namespace oglp {
namespace texgen {

struct output_intf;

enum class render_param_bit : unsigned {
    normalized_coord = 1U << 0U,
    voxel_size = 1U << 1U,
    voxel_offset = 1U << 2U,
    element_offset = 1U << 3U
};

using render_param_bits = bitfield<render_param_bit>;

static constexpr inline render_param_bits operator|(
  render_param_bit a, render_param_bit b) noexcept {
    return {a, b};
}

static constexpr inline render_param_bits all_render_params() noexcept {
    return render_param_bit::normalized_coord | render_param_bit::voxel_size |
           render_param_bit::voxel_offset | render_param_bit::element_offset;
}

struct render_params {
    unsigned version;
    int width;
    int height;
};

} // namespace texgen
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_TEXGEN_RENDER_PARAMS_HPP
