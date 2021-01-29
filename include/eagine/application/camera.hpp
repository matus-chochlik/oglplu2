/**
 *  @file eagine/application/camera.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

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

    auto update_orbit(float inc) noexcept -> orbiting_camera& {
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

    auto update_turns(float inc) noexcept -> orbiting_camera& {
        _turns += turns_(inc * _turn_dir);
        return *this;
    }

    auto update_pitch(float inc) noexcept -> orbiting_camera& {
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

    auto altitude_change_handler() noexcept -> input_handler {
        return {this, EAGINE_THIS_MEM_FUNC_C(_change_altitude)};
    }

    auto longitude_change_handler() noexcept -> input_handler {
        return {this, EAGINE_THIS_MEM_FUNC_C(_change_longitude)};
    }

    auto latitude_change_handler() noexcept -> input_handler {
        return {this, EAGINE_THIS_MEM_FUNC_C(_change_latitude)};
    }

private:
    oglp::sign _orbit_dir;
    oglp::sign _turn_dir;
    oglp::sign _pitch_dir;

    void _change_altitude(const input& i) {
        _orbit_factor -= (float(i.get()));
        if(_orbit_factor > 1.F) {
            _orbit_factor = 1.F;
        }
        if(_orbit_factor < 0.F) {
            _orbit_factor = 0.F;
        }
    }

    void _change_longitude(const input& i) {
        _turns -= turns_(float(i.get() * 0.25));
    }

    void _change_latitude(const input& i) {
        const auto max = right_angles_(1.F);
        _pitch -= right_angles_(float(i.get()));
        if(_pitch > max) {
            _pitch = max;
        }
        if(_pitch < -max) {
            _pitch = -max;
        }
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
