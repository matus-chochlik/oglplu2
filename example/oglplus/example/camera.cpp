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
#include <eagine/math/intersection.hpp>
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
example_orbiting_camera& example_orbiting_camera::pointer_dragging(
  const example_state_view& state) noexcept {
    change_turns(-state.norm_pointer_x().delta() * 0.5f);
    change_pitch(-state.norm_pointer_y().delta() * 1.0f);
    return *this;
}
//------------------------------------------------------------------------------
example_orbiting_camera& example_orbiting_camera::pointer_scrolling(
  const example_state_view& state) noexcept {
    change_orbit(-state.norm_pointer_z().delta());
    return *this;
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
line example_orbiting_camera::pointer_ray(
  const example_state_view& state, int pointer) const noexcept {
    return line(position(), target_plane_pointer(state, pointer));
}
//------------------------------------------------------------------------------
example_orbiting_camera& example_orbiting_camera::idle_update(
  const example_state_view& state,
  const eagine::valid_if_positive<float>& divisor) noexcept {
    const auto s = state.frame_duration().value() / divisor.value_or(1);
    return update_orbit(s).update_turns(s).update_pitch(s);
}
//------------------------------------------------------------------------------
} // namespace oglplus
