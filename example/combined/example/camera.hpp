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
#include <oglplus/math/primitives.hpp>
#include <oglplus/math/sign.hpp>
#include <oglplus/math/vector.hpp>

namespace eagine {
namespace oglp {

class example_orbiting_camera {
public:
    example_orbiting_camera() noexcept = default;

    auto set_target(vec3 target) noexcept -> auto& {
        _target = target;
        return *this;
    }

    auto set_fov(radians_t<float> angle) noexcept -> auto& {
        _fov = angle;
        return *this;
    }

    auto set_near(valid_if_positive<float> dist) noexcept -> auto& {
        _near = dist.value();
        return *this;
    }

    auto set_far(valid_if_positive<float> dist) noexcept -> auto& {
        _far = dist.value();
        return *this;
    }

    auto set_orbit_min(valid_if_positive<float> orbit) noexcept -> auto& {
        _orbit_min = orbit.value();
        return *this;
    }

    auto set_orbit_max(valid_if_positive<float> orbit) noexcept -> auto& {
        _orbit_max = orbit.value();
        return *this;
    }

    auto apply_pointer_motion(const example_state_view&) noexcept -> bool;

    auto apply_pointer_scrolling(const example_state_view&) noexcept -> bool;

    auto update_orbit(float inc) noexcept -> example_orbiting_camera&;
    auto update_turns(float inc) noexcept -> example_orbiting_camera&;
    auto update_pitch(float inc) noexcept -> example_orbiting_camera&;

    auto idle_update(
      const example_state_view& state,
      const valid_if_positive<float>& divisor) noexcept
      -> example_orbiting_camera&;

    auto orbit() const noexcept {
        return smooth_lerp(_orbit_min, _orbit_max, _orbit_factor);
    }

    auto azimuth() const noexcept {
        return _turns;
    }

    auto elevation() const noexcept {
        return _pitch;
    }

    auto target_to_camera_direction() const noexcept -> vec3;
    auto camera_to_target_direction() const noexcept -> vec3;

    auto target() const noexcept -> vec3 {
        return _target;
    }

    auto position() const noexcept -> vec3 {
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

    auto target_plane_point(float ndcx, float ndcy, float aspect) const noexcept
      -> optionally_valid<vec3>;

    auto target_plane_pointer(const example_state_view& state, int pointer = 0)
      const noexcept -> optionally_valid<vec3>;

    auto
    pointer_ray(const example_state_view& state, int pointer = 0) const noexcept
      -> optionally_valid<line>;

    auto grab_sphere_radius() const noexcept -> float;

    auto grab_sphere() const noexcept -> sphere;

private:
    vec3 _target{};
    radians_t<float> _fov{right_angle_()};

    float _near{0.5f};
    float _far{10.f};

    float _orbit_min{1.5F};
    float _orbit_max{5.5F};
    float _orbit_factor = 0.50F;

    radians_t<float> _turns{};
    radians_t<float> _pitch{};

    radians_t<float> _grab_azimuth{};
    radians_t<float> _grab_elevation{};

    sign _orbit_dir;
    sign _turn_dir;
    sign _pitch_dir;
    bool _is_grabbing{false};
};

} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_CAMERA_HPP
