/**
 *  .file oglplus/example/state.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_STATE_HPP

#include "state_view.hpp"
#include <eagine/assert.hpp>
#include <eagine/math/functions.hpp>

namespace eagine {
//------------------------------------------------------------------------------
class example_state : public example_state_view {
public:
    void set_time(float new_time) noexcept {
        EAGINE_ASSERT(new_time >= 0.0F);
        _exe_time.assign(new_time);
    }

    void advance_time(float dt) noexcept {
        _exe_time.advance(dt);
    }

    void advance_frame() noexcept {
        ++_frame_no;
        _old_user_idle = _new_user_idle;
        _new_user_idle = true;
    }

    auto set_width(const valid_if_positive<int>& new_width) noexcept -> bool {
        return _notice_user_activity(_width.assign(new_width));
    }

    auto set_height(const valid_if_positive<int>& new_height) noexcept -> bool {
        return _notice_user_activity(_height.assign(new_height));
    }

    auto set_depth(const valid_if_positive<int>& new_depth) noexcept -> bool {
        return _notice_user_activity(_depth.assign(new_depth));
    }

    void set_tiles(int x, int y) noexcept {
        if(x < 1) {
            x = 1;
        }
        if(y < 1) {
            y = 1;
        }

        _x_tiles = x;
        _y_tiles = y;
        _tile_i = 0;
        _tile_j = 0;
    }

    auto first_tile() noexcept -> bool {
        return (_tile_i == 0) && (_tile_j == 0);
    }

    auto next_tile() noexcept -> bool {
        if(multiple_tiles()) {
            if(++_tile_i >= _x_tiles) {
                _tile_i = 0;
                if(++_tile_j >= _y_tiles) {
                    _tile_j = 0;
                }
            }
        }
        return first_tile();
    }

    auto set_size(
      const valid_if_positive<int>& new_width,
      const valid_if_positive<int>& new_height) noexcept -> bool {
        // intentional to bypass short circuiting
        bool ws = set_width(new_width);
        bool hs = set_height(new_height);

        return ws || hs;
    }

    void sync_size() noexcept {
        _width.sync();
        _height.sync();
        _depth.sync();
    }

    auto set_mouse_btn(int button, bool pressed) noexcept -> bool {
        button -= 1;
        if((button >= 0) && (button < this->_mouse_btn_count)) {
            auto& mouse_btn = _mouse_btn[button];
            return _notice_user_activity(mouse_btn.assign(pressed));
        }
        return false;
    }

    auto set_mouse_pos(int new_mouse_x, int new_mouse_y) noexcept -> bool {
        using math::clamp;
        const bool x_chng =
          _mouse_x.assign(clamp(new_mouse_x, 0, _width.value()));
        const bool y_chng =
          _mouse_y.assign(clamp(new_mouse_y, 0, _height.value()));
        // the xy_chng variables are required for the assign functions
        // to be called properly (or short circuit!)
        return _notice_user_activity(x_chng || y_chng);
    }

    auto set_mouse_wheel(int new_mouse_z) noexcept -> bool {
        return _notice_user_activity(_mouse_z.assign(new_mouse_z));
    }

    void center_mouse() noexcept {
        _mouse_x.assign(width() / 2);
        _mouse_x.sync();
        _mouse_y.assign(height() / 2);
        _mouse_y.sync();
        _mouse_z.assign(0);
        _mouse_z.sync();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_STATE_HPP
