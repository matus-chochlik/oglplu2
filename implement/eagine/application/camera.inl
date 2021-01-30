/**
 *  @file eagine/application/camera.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::application {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto orbiting_camera::update_orbit(float inc) noexcept -> orbiting_camera& {
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
EAGINE_LIB_FUNC
auto orbiting_camera::update_turns(float inc) noexcept -> orbiting_camera& {
    _turns += turns_(inc * _turn_dir);
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto orbiting_camera::update_pitch(float inc) noexcept -> orbiting_camera& {
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
EAGINE_LIB_FUNC
void orbiting_camera::_handle_pressure(const input& i) {
    _is_dragging = bool(i);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void orbiting_camera::_change_altitude(const input& i) {
    _orbit_factor -= (float(i.get()));
    if(_orbit_factor > 1.F) {
        _orbit_factor = 1.F;
    }
    if(_orbit_factor < 0.F) {
        _orbit_factor = 0.F;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void orbiting_camera::_change_longitude(const input& i) {
    _turns -= turns_(float(i.get() * 0.25));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void orbiting_camera::_change_latitude(const input& i) {
    const auto max = right_angles_(1.F);
    _pitch -= right_angles_(float(i.get()));
    if(_pitch > max) {
        _pitch = max;
    }
    if(_pitch < -max) {
        _pitch = -max;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto orbiting_camera::connect_inputs(execution_context& ec)
  -> orbiting_camera& {
    ec.connect_input(pressure_input())
      .connect_input(altitude_change_input())
      .connect_input(longitude_change_input())
      .connect_input(latitude_change_input());
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto orbiting_camera::basic_input_mapping(
  execution_context& ec,
  identifier mapping_id) -> orbiting_camera& {
    ec.map_input(
        pressure_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Cursor, Pressed),
        input_setup().trigger())
      .map_input(
        altitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Keyboard, KpPlus),
        input_setup().trigger().multiply(0.05))
      .map_input(
        altitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Keyboard, KpMinus),
        input_setup().trigger().multiply(0.05).invert())
      .map_input(
        altitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Wheel, ScrollY),
        input_setup().relative().multiply(0.2))
      .map_input(
        longitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Keyboard, Left),
        input_setup().trigger().multiply(0.05))
      .map_input(
        longitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Keyboard, Right),
        input_setup().trigger().multiply(0.05).invert())
      .map_input(
        longitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Cursor, MotionX),
        input_setup().relative().multiply(2).only_if(_is_dragging))
      .map_input(
        latitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Keyboard, Down),
        input_setup().trigger().multiply(0.05))
      .map_input(
        latitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Keyboard, Up),
        input_setup().trigger().multiply(0.05).invert())
      .map_input(
        latitude_change_input_id(),
        mapping_id,
        EAGINE_MSG_ID(Cursor, MotionY),
        input_setup().relative().multiply(2).only_if(_is_dragging));
    return *this;
}
//------------------------------------------------------------------------------
} // namespace eagine::application
