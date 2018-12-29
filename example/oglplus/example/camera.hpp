/**
 *  .file oglplus/example/camera.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_CAMERA_HPP
#define OGLPLUS_EXAMPLE_CAMERA_HPP

#include "state_view.hpp"
#include <oglplus/math/interpolate.hpp>
#include <oglplus/math/matrix_ctrs.hpp>
#include <oglplus/math/sign.hpp>
#include <oglplus/math/vector.hpp>

namespace oglplus {

class example_orbiting_camera {
public:
    example_orbiting_camera() noexcept = default;

    example_orbiting_camera& set_target(vec3 target) noexcept {
        _target = target;
        return *this;
    }

    example_orbiting_camera& set_fov(radians_t<float> angle) noexcept {
        _fov = angle;
        return *this;
    }

    example_orbiting_camera& set_near(
      eagine::valid_if_positive<float> dist) noexcept {
        _near = dist.value();
        return *this;
    }

    example_orbiting_camera& set_far(
      eagine::valid_if_positive<float> dist) noexcept {
        _far = dist.value();
        return *this;
    }

    example_orbiting_camera& set_orbit_min(
      eagine::valid_if_positive<float> orbit) noexcept {
        _orbit_min = orbit.value();
        return *this;
    }

    example_orbiting_camera& set_orbit_max(
      eagine::valid_if_positive<float> orbit) noexcept {
        _orbit_max = orbit.value();
        return *this;
    }

    example_orbiting_camera& change_orbit(float inc) noexcept {
        _change_bouncing(_dist_dir, _orbit, inc);
        return *this;
    }

    example_orbiting_camera& change_pitch(float inc) noexcept {
        _change_bouncing(_elev_dir, _pitch, inc);
        return *this;
    }

    example_orbiting_camera& change_turns(float inc) noexcept {
        _turns += inc;
        _turn_dir = (inc > 0) ? sign::plus() : sign::minus();
        return *this;
    }

    example_orbiting_camera& pointer_dragging(
      const example_state_view& state) noexcept {
        change_turns(-state.norm_pointer_x().delta() * 0.5f);
        change_pitch(-state.norm_pointer_y().delta() * 1.0f);
        return *this;
    }

    example_orbiting_camera& pointer_scrolling(
      const example_state_view& state) noexcept {
        change_orbit(-state.norm_pointer_z().delta());
        return *this;
    }

    example_orbiting_camera& update_orbit(float inc) noexcept {
        return change_orbit(inc * _dist_dir);
    }

    example_orbiting_camera& update_turns(float inc) noexcept {
        return change_turns(inc * _turn_dir);
    }

    example_orbiting_camera& update_pitch(float inc) noexcept {
        return change_pitch(inc * _elev_dir);
    }

    example_orbiting_camera& idle_update(
      const example_state_view& state,
      eagine::valid_if_positive<float> divisor) noexcept {
        const auto s = state.frame_duration().value() / divisor.value();
        return update_orbit(s).update_turns(s).update_pitch(s);
    }

    auto orbit() const noexcept {
        return smooth_lerp(_orbit_min, _orbit_max, _orbit);
    }

    auto azimuth() const noexcept {
        return turns_(_turns);
    }

    auto elevation() const noexcept {
        return smooth_oscillate(radians_(1.5f), _pitch);
    }

    vec3 target_to_camera_direction() const noexcept;
    vec3 camera_to_target_direction() const noexcept;

    vec3 target() const noexcept {
        return _target;
    }

    vec3 position() const noexcept {
        return target() + target_to_camera_direction() * orbit();
    }

    auto perspective_matrix(float aspect) const noexcept {
        return matrix_perspective::y(_fov, aspect, _near, _far);
    }

    auto projection_matrix() const noexcept {
        return matrix_orbiting_y_up(_target, orbit(), azimuth(), elevation());
    }

    auto matrix(float aspect) const noexcept {
        return perspective_matrix(aspect) * projection_matrix();
    }

    auto matrix(const example_state_view& state) const noexcept {
        return matrix(state.aspect());
    }

    vec3 target_plane_point(float ndcx, float ndcy, float aspect) const
      noexcept;

    vec3 target_plane_pointer(
      const example_state_view& state, int pointer = 0) const noexcept;

private:
    void _change_bouncing(sign& dir, float& val, float inc) noexcept;

    vec3 _target;
    radians_t<float> _fov = right_angle_();

    float _near = 0.5f;
    float _far = 10.f;

    float _orbit_min = 1.5f;
    float _orbit_max = 5.5f;

    float _orbit = 0.50f;
    // float _turns = 0.12f;
    // float _pitch = 0.72f;
    float _turns = 0.0f;
    float _pitch = 0.5f;

    sign _dist_dir;
    sign _turn_dir;
    sign _elev_dir;
};

} // namespace oglplus

#endif // OGLPLUS_EXAMPLE_CAMERA_HPP
