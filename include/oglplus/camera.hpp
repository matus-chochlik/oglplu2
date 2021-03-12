/// @file
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
#include <eagine/units/common.hpp>
#include <eagine/valid_if/positive.hpp>

namespace eagine::oglp {

/// @brief Class representing a camera orbiting around its target.
/// @ingroup gl_utils
class orbiting_camera {
public:
    /// @brief Sets the target position.
    auto set_target(vec3 target) noexcept -> auto& {
        _target = target;
        return *this;
    }

    /// @brief Sets the y-axis FOV angle.
    auto set_fov(radians_t<float> angle) noexcept -> auto& {
        _fov = angle;
        return *this;
    }

    /// @brief Sets the distance of the near plane.
    auto set_near(valid_if_positive<float> dist) noexcept -> auto& {
        _near = dist.value();
        return *this;
    }

    /// @brief Sets the distance of the far plane.
    auto set_far(valid_if_positive<float> dist) noexcept -> auto& {
        _far = dist.value();
        return *this;
    }

    /// @brief Set minimal orbit value.
    auto set_orbit_min(valid_if_positive<float> orbit) noexcept -> auto& {
        _orbit_min = orbit.value();
        return *this;
    }

    /// @brief Set maximal orbit value.
    auto set_orbit_max(valid_if_positive<float> orbit) noexcept -> auto& {
        _orbit_max = orbit.value();
        return *this;
    }

    /// @brief Returns the y-axis FOV angle
    auto fov() const noexcept -> radians_t<float> {
        return _fov;
    }

    /// @brief Returns the orbit altitude value.
    /// @see azimuth
    /// @see elevation
    auto orbit() const noexcept -> float {
        return smooth_lerp(_orbit_min, _orbit_max, _orbit_factor);
    }

    /// @brief Returns the azimuth angle (longitude).
    /// @see orbit
    /// @see elevation
    auto azimuth() const noexcept -> radians_t<float> {
        return _turns;
    }

    /// @brief Returns the elevation angle (latitude).
    /// @see orbit
    /// @see azimuth
    auto elevation() const noexcept -> radians_t<float> {
        return _pitch;
    }

    /// @brief Returns the target position.
    /// @see position
    auto target() const noexcept -> vec3 {
        return _target;
    }

    /// @brief Returns the target-to-camera direction vector.
    /// @see camera_to_target_direction
    auto target_to_camera_direction() const noexcept -> vec3;

    /// @brief Returns the camera-to-target direction vector.
    /// @see target_to_camera_direction
    auto camera_to_target_direction() const noexcept -> vec3 {
        return -target_to_camera_direction();
    }

    /// @brief Returns the position of the camera.
    /// @see target
    auto position() const noexcept -> vec3 {
        return target() + target_to_camera_direction() * orbit();
    }

    auto perspective_matrix_ctr(float aspect) const noexcept {
        return matrix_perspective::y(_fov, aspect, _near, _far);
    }

    /// @brief Returns the perspective matrix for the given aspect ratio.
    auto perspective_matrix(float aspect) const noexcept {
        return perspective_matrix_ctr(aspect)();
    }

    auto transform_matrix_ctr() const noexcept {
        return matrix_orbiting_y_up(_target, orbit(), azimuth(), elevation());
    }

    /// @brief Returns the camera transformation matrix.
    auto transform_matrix() const noexcept {
        return transform_matrix_ctr()();
    }

    /// @brief Returns the camera matrix (perspective * projection).
    auto matrix(float aspect) const noexcept {
        return perspective_matrix_ctr(aspect) * transform_matrix_ctr();
    }

    /// @brief Returns the 3D position of a point (in NDC) on the target plane.
    auto target_plane_point(float ndcx, float ndcy, float aspect) const noexcept
      -> optionally_valid<vec3>;

    /// @brief Returns a ray from the camera through a point on the target plane.
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

