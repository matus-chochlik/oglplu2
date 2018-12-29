/**
 *  .file oglplus/example/camera.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include <oglplus/gl.hpp>
// clang-format on
#include "camera.hpp"
#include <eagine/math/matrix_inverse.hpp>
#include <oglplus/math/coordinates.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
void example_orbiting_camera::_change_bouncing(
  sign& dir, float& val, float inc) noexcept {
    val += inc;
    if(val > 1.f) {
        val = 1.f;
        dir.flip();
    }
    if(val < 0.f) {
        val = 0.f;
        dir.flip();
    }
}
//------------------------------------------------------------------------------
vec3 example_orbiting_camera::target_to_camera_direction() const noexcept {
    return to_cartesian(unit_spherical_coordinates(azimuth(), elevation()));
}
//------------------------------------------------------------------------------
vec3 example_orbiting_camera::camera_to_target_direction() const noexcept {
    return -target_to_camera_direction();
}
//------------------------------------------------------------------------------
vec3 example_orbiting_camera::target_plane_point(
  float ndcx, float ndcy, float aspect) const noexcept {
    using eagine::math::inverse_matrix;
    using eagine::math::multiply;

    const auto mat = matrix(aspect);

    if(auto inv = inverse_matrix(mat)) {
        auto ndct = multiply(mat, vec4(_target, 1.f));
        auto ndc = vec4{ndcx * ndct.w(), ndcy * ndct.w(), ndct.z(), ndct.w()};
        return vec3(eagine::math::multiply(inv.value(), ndc));
    }
    return {};
}
//------------------------------------------------------------------------------
vec3 example_orbiting_camera::target_plane_pointer(
  const example_state_view& state, int pointer) const noexcept {
    return target_plane_point(
      state.ndc_pointer_x(pointer).get(),
      state.ndc_pointer_y(pointer).get(),
      state.aspect());
}
//------------------------------------------------------------------------------
} // namespace oglplus
