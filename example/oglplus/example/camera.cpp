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
vec3 example_orbiting_camera::target_to_camera_direction() const noexcept {
    return to_cartesian(unit_spherical_coordinates(azimuth(), elevation()));
}
//------------------------------------------------------------------------------
vec3 example_orbiting_camera::camera_to_target_direction() const noexcept {
    return -target_to_camera_direction();
}
//------------------------------------------------------------------------------
eagine::optionally_valid<vec3> example_orbiting_camera::target_plane_point(
  float ndcx, float ndcy, float aspect) const noexcept {
    using eagine::math::inverse_matrix;
    using eagine::math::multiply;

    const auto mat = matrix(aspect);

    if(auto inv = inverse_matrix(mat)) {
        auto ndct = multiply(mat, vec4(_target, 1.f));
        auto ndc = vec4{ndcx * ndct.w(), ndcy * ndct.w(), ndct.z(), ndct.w()};
        return {vec3(eagine::math::multiply(inv.value(), ndc)), true};
    }
    return {};
}
//------------------------------------------------------------------------------
eagine::optionally_valid<vec3> example_orbiting_camera::target_plane_pointer(
  const example_state_view& state, int pointer) const noexcept {
    return target_plane_point(
      state.ndc_pointer_x(pointer).get(),
      state.ndc_pointer_y(pointer).get(),
      state.aspect());
}
//------------------------------------------------------------------------------
eagine::optionally_valid<line> example_orbiting_camera::pointer_ray(
  const example_state_view& state, int pointer) const noexcept {
    if(const auto ptr = target_plane_pointer(state, pointer)) {
        return {line(position(), ptr.value_anyway() - position()), true};
    }
    return {};
}
//------------------------------------------------------------------------------
float example_orbiting_camera::grab_sphere_radius() const noexcept {
    const auto orb = orbit();
    return eagine::math::minimum(orb * tan(_fov * 0.5f), orb * 0.75f);
}
//------------------------------------------------------------------------------
sphere example_orbiting_camera::grab_sphere() const noexcept {
    return sphere(target(), grab_sphere_radius());
}
//------------------------------------------------------------------------------
bool example_orbiting_camera::apply_pointer_motion(
  const example_state_view& state) noexcept {
    if(state.pointer_dragging()) {

        if(const auto ray = pointer_ray(state)) {

            if(
              const auto intersection =
                eagine::math::nearest_line_sphere_intersection(
                  ray.value_anyway(), grab_sphere())) {
                const auto grab_point =
                  normalized(intersection.value_anyway() - target());
                const auto grab_coords = to_unit_spherical(grab_point);

                if(!_is_grabbing) {
                    _grab_azimuth = grab_coords.azimuth();
                    _grab_elevation = grab_coords.elevation();
                    _is_grabbing = true;
                } else {
                    const auto turn_inc = _grab_azimuth - grab_coords.azimuth();

                    _turns += turn_inc;
                    _turn_dir = turn_inc;

                    const auto elev_max = radians_(1.5f);
                    const auto elev_inc =
                      _grab_elevation - grab_coords.elevation();

                    _pitch += elev_inc;
                    _pitch_dir = -elev_inc;

                    if(_pitch >= elev_max) {
                        _pitch = elev_max;
                    } else if(_pitch <= -elev_max) {
                        _pitch -= elev_max;
                    }
                }
                return true;
            }
        }
    }
    _is_grabbing = false;
    return false;
}
//------------------------------------------------------------------------------
bool example_orbiting_camera::apply_pointer_scrolling(
  const example_state_view& state) noexcept {
    update_orbit(-state.norm_pointer_z().delta());
    return true;
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
