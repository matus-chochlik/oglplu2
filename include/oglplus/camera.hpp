/// @file oglplus/camera.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_CAMERA_HPP
#define OGLPLUS_CAMERA_HPP

#include "math/interpolate.hpp"
#include "math/matrix_ctrs.hpp"
#include "math/primitives.hpp"
#include "math/sign.hpp"
#include "math/vector.hpp"
#include <eagine/units/trivial.hpp>
#include <eagine/valid_if/positive.hpp>

namespace eagine::oglp {

class orbiting_camera {
public:
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

    auto fov() const noexcept {
        return _fov;
    }

    auto orbit() const noexcept {
        return smooth_lerp(_orbit_min, _orbit_max, _orbit_factor);
    }

    auto azimuth() const noexcept {
        return _turns;
    }

    auto elevation() const noexcept {
        return _pitch;
    }

    auto target() const noexcept -> vec3 {
        return _target;
    }

    auto target_to_camera_direction() const noexcept -> vec3;
    auto camera_to_target_direction() const noexcept -> vec3 {
        return -target_to_camera_direction();
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

    auto target_plane_point(float ndcx, float ndcy, float aspect) const noexcept
      -> optionally_valid<vec3>;

    auto pointer_ray(float ndcx, float ndcy, float aspect) const noexcept
      -> optionally_valid<line>;

    auto grab_sphere_radius() const noexcept -> float;
    auto grab_sphere() const noexcept -> sphere;

private:
    vec3 _target{};
    radians_t<float> _fov{right_angle_()};

    float _near{0.5F};
    float _far{10.F};

protected:
    radians_t<float> _turns{};
    radians_t<float> _pitch{};

    float _orbit_min{1.5F};
    float _orbit_max{5.5F};
    float _orbit_factor = 0.50F;
};

} // namespace eagine::oglp

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/camera.inl>
#endif

#endif

