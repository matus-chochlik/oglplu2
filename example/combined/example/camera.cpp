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

namespace eagine::oglp {
//------------------------------------------------------------------------------
auto example_orbiting_camera::target_to_camera_direction() const noexcept
  -> vec3 {
    return to_cartesian(unit_spherical_coordinates(azimuth(), elevation()));
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::camera_to_target_direction() const noexcept
  -> vec3 {
    return -target_to_camera_direction();
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::target_plane_point(
  float ndcx,
  float ndcy,
  float aspect) const noexcept -> optionally_valid<vec3> {
    using math::inverse_matrix;
    using math::multiply;

    const auto mat = matrix(aspect);

    if(auto inv = inverse_matrix(mat)) {
        auto ndct = multiply(mat, vec4(_target, 1.F));
        auto ndc = vec4{ndcx * ndct.w(), ndcy * ndct.w(), ndct.z(), ndct.w()};
        return {vec3(math::multiply(inv.value(), ndc)), true};
    }
    return {};
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::target_plane_pointer(
  const example_state_view& state,
  int pointer) const noexcept -> optionally_valid<vec3> {
    return target_plane_point(
      state.ndc_pointer_x(pointer).get(),
      state.ndc_pointer_y(pointer).get(),
      state.aspect());
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::pointer_ray(
  const example_state_view& state,
  int pointer) const noexcept -> optionally_valid<line> {
    if(const auto ptr = target_plane_pointer(state, pointer)) {
        return {line(position(), ptr.value_anyway() - position()), true};
    }
    return {};
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::grab_sphere_radius() const noexcept -> float {
    const auto orb = orbit();
    return math::minimum(orb * tan(_fov * 0.5F), orb * 0.75F);
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::grab_sphere() const noexcept -> sphere {
    return sphere(target(), grab_sphere_radius());
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::apply_pointer_motion(
  const example_state_view& state) noexcept -> bool {
    if(state.pointer_dragging()) {

        if(const auto ray = pointer_ray(state)) {

            if(
              const auto intersection = math::nearest_line_sphere_intersection(
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

                    const auto elev_max = radians_(1.5F);
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
auto example_orbiting_camera::apply_pointer_scrolling(
  const example_state_view& state) noexcept -> bool {
    _orbit_factor -= state.norm_pointer_z().delta();
    if(_orbit_factor > 1.F) {
        _orbit_factor = 1.F;
    }
    if(_orbit_factor < 0.F) {
        _orbit_factor = 0.F;
    }
    return true;
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::update_orbit(float inc) noexcept
  -> example_orbiting_camera& {
    _orbit_factor += (inc * _orbit_dir);
    if(_orbit_factor > 1.F) {
        _orbit_factor = 1.F;
        _orbit_dir.flip();
    }
    if(_orbit_factor < 0.F) {
        _orbit_factor = 0.F;
        _orbit_dir.flip();
    }
    return *this;
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::update_turns(float inc) noexcept
  -> example_orbiting_camera& {
    _turns += turns_(inc * _turn_dir);
    return *this;
}
//------------------------------------------------------------------------------
auto example_orbiting_camera::update_pitch(float inc) noexcept
  -> example_orbiting_camera& {
    const auto max = right_angles_(1.F);
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
auto example_orbiting_camera::idle_update(
  const example_state_view& state,
  const valid_if_positive<float>& divisor) noexcept
  -> example_orbiting_camera& {
    const auto s = state.frame_duration().value() / divisor.value_or(1);
    return update_orbit(s).update_turns(s).update_pitch(s);
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
