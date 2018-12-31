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
bool example_orbiting_camera::apply_pointer_motion(
  const example_state_view& state) noexcept {
    if(state.pointer_dragging()) {

        const float radius = orbit() * 0.85f;

        if(
          const auto intersection =
            eagine::math::nearest_line_sphere_intersection(
              pointer_ray(state), eagine::math::sphere(target(), radius))) {

            const auto grab_coords = to_unit_spherical(
              normalized(intersection.value_anyway() - target()));

            if(!_was_dragging) {
                _grab_azimuth = grab_coords.azimuth();
                _grab_elevation = grab_coords.elevation();
                _was_dragging = true;
            } else {
                const auto turn_inc = _grab_azimuth - grab_coords.azimuth();

                _turns += turn_inc * 2.f;
                _turn_dir = sign(turn_inc);

                const auto elev_max = radians_(1.5f);
                const auto elev_inc = _grab_elevation - grab_coords.elevation();

                if(!std::isnan(elev_inc.value())) {
                    _pitch += elev_inc;
                    _pitch_dir = -sign(elev_inc);

                    if(_pitch >= elev_max) {
                        _pitch = elev_max;
                    } else if(_pitch <= -elev_max) {
                        _pitch -= elev_max;
                    }
                }
            }
            return true;
        }
    }
    _was_dragging = false;
    return false;
}
//------------------------------------------------------------------------------
bool example_orbiting_camera::apply_pointer_scrolling(
  const example_state_view& state) noexcept {
    update_orbit(-state.norm_pointer_z().delta());
    return true;
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
    return line(position(), target_plane_pointer(state, pointer) - position());
}
//------------------------------------------------------------------------------
example_orbiting_camera& example_orbiting_camera::update_orbit(
  float inc) noexcept {
    _orbit_factor += inc;
    if(_orbit_factor > 1.f) {
        _orbit_factor = 1.f;
        _orbit_dir.flip();
    }
    if(_orbit_factor < 0.f) {
        _orbit_factor = 0.f;
        _orbit_dir.flip();
    }
    return *this;
}
//------------------------------------------------------------------------------
example_orbiting_camera& example_orbiting_camera::update_turns(
  float inc) noexcept {
    _turns += turns_(inc * _turn_dir);
    return *this;
}
//------------------------------------------------------------------------------
example_orbiting_camera& example_orbiting_camera::update_pitch(
  float inc) noexcept {
    const auto max = right_angles_(1.f);
    _pitch += right_angles_(inc * _pitch_dir);
    if(_pitch > max) {
        _pitch = max;
        _pitch_dir.flip();
    }
    if(_pitch < -max) {
        _pitch = -max;
        _pitch_dir.flip();
    }
    return *this;
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
