/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_CAMERA_HPP
#define EAGINE_APPLICATION_CAMERA_HPP

#include "context.hpp"
#include <oglplus/camera.hpp>
#include <oglplus/math/sign.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class orbiting_camera : public oglp::orbiting_camera {
    using base = oglp::orbiting_camera;

public:
    using base::matrix;
    auto matrix(video_context& vc) const noexcept {
        return base::matrix(vc.surface_aspect());
    }

    auto has_changed() noexcept {
        return std::exchange(_changed, false);
    }

    auto update_orbit(float inc) noexcept -> orbiting_camera&;
    auto update_turns(float inc) noexcept -> orbiting_camera&;
    auto update_pitch(float inc) noexcept -> orbiting_camera&;

    auto idle_update(
      const context_state_view&,
      const valid_if_positive<float>& divisor = 2.F) noexcept
      -> orbiting_camera&;

    auto idle_update(
      const execution_context&,
      const valid_if_positive<float>& divisor = 2.F) noexcept
      -> orbiting_camera&;

    constexpr auto pressure_input_id() const noexcept -> message_id {
        return EAGINE_MSG_ID(Camera, Pressure);
    }
    auto pressure_input() noexcept -> input_slot {
        return {
          pressure_input_id(),
          {this, EAGINE_THIS_MEM_FUNC_C(_handle_pressure)}};
    }

    constexpr auto dampening_input_id() const noexcept -> message_id {
        return EAGINE_MSG_ID(Camera, Dampening);
    }
    auto dampening_input() noexcept -> input_slot {
        return {
          dampening_input_id(),
          {this, EAGINE_THIS_MEM_FUNC_C(_handle_dampening)}};
    }

    constexpr auto altitude_change_input_id() const noexcept -> message_id {
        return EAGINE_MSG_ID(Camera, Altitude);
    }
    auto altitude_change_input() noexcept -> input_slot {
        return {
          altitude_change_input_id(),
          {this, EAGINE_THIS_MEM_FUNC_C(_change_altitude)}};
    }

    constexpr auto longitude_change_input_id() const noexcept -> message_id {
        return EAGINE_MSG_ID(Camera, Longitude);
    }
    auto longitude_change_input() noexcept -> input_slot {
        return {
          longitude_change_input_id(),
          input_handler{this, EAGINE_THIS_MEM_FUNC_C(_change_longitude)}};
    }

    constexpr auto latitude_change_input_id() const noexcept -> message_id {
        return EAGINE_MSG_ID(Camera, Latitude);
    }
    auto latitude_change_input() noexcept -> input_slot {
        return {
          latitude_change_input_id(),
          {this, EAGINE_THIS_MEM_FUNC_C(_change_latitude)}};
    }

    auto connect_inputs(execution_context& ec) -> orbiting_camera&;

    auto basic_input_mapping(execution_context& ec, identifier mapping_id)
      -> orbiting_camera&;

    auto basic_input_mapping(execution_context& ec) -> auto& {
        return basic_input_mapping(ec, {});
    }

private:
    oglp::sign _orbit_dir;
    oglp::sign _turn_dir;
    oglp::sign _pitch_dir;

    bool _changed{true};
    bool _is_dragging{false};
    bool _dampen_motion{false};

    auto _motion_adjust() const noexcept {
        return _dampen_motion ? 0.2 : 1.0;
    }

    void _handle_pressure(const input& i);
    void _handle_dampening(const input& i);
    void _change_altitude(const input& i);
    void _change_longitude(const input& i);
    void _change_latitude(const input& i);
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/camera.inl>
#endif

#endif
