/**
 *  .file oglplus/example/camera.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_CAMERA_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_CAMERA_HPP

#include "state_view.hpp"
#include <oglplus/camera.hpp>

namespace eagine {
namespace oglp {

class example_orbiting_camera : public orbiting_camera {
public:
    example_orbiting_camera() noexcept = default;

    using orbiting_camera::matrix;
    auto matrix(const example_state_view& state) const noexcept {
        return matrix(state.aspect());
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

    auto target_plane_pointer(const example_state_view& state, int pointer = 0)
      const noexcept -> optionally_valid<vec3>;

    using orbiting_camera::pointer_ray;
    auto
    pointer_ray(const example_state_view& state, int pointer = 0) const noexcept
      -> optionally_valid<line>;

private:
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
