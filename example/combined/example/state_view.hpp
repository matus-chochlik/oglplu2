/**
 *  .file oglplus/example/state_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_VIEW_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_STATE_VIEW_HPP

#include <eagine/assert.hpp>
#include <eagine/quantities.hpp>
#include <eagine/valid_if/positive.hpp>
#include <eagine/value_with_history.hpp>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
using example_state_value = value_with_history<T, 3>;

template <typename T>
using example_state_variable = variable_with_history<T, 3>;
//------------------------------------------------------------------------------
class example_state_view {

protected:
    example_state_variable<valid_if_positive<int>> _width{1};
    example_state_variable<valid_if_positive<int>> _height{1};
    example_state_variable<valid_if_positive<int>> _depth{1};

    example_state_variable<int> _mouse_x{0};
    example_state_variable<int> _mouse_y{0};
    example_state_variable<int> _mouse_z{0};

    static constexpr const int _mouse_btn_count{4};
    example_state_variable<bool> _mouse_btn[_mouse_btn_count]{
      false,
      false,
      false,
      false};

    example_state_variable<float> _exe_time{0.0F};
    float _usr_act_time{0.0F};

    auto _notice_user_activity(bool something_changed = true) noexcept -> bool;

    int _frame_no{0};

    int _x_tiles{1}, _tile_i{0};
    int _y_tiles{1}, _tile_j{0};

    bool _old_user_idle{false};
    bool _new_user_idle{false};

    example_state_view() noexcept = default;

public:
    auto width() const noexcept -> const auto& {
        return _width;
    }

    auto height() const noexcept -> const auto& {
        return _height;
    }

    auto depth() const noexcept -> const auto& {
        return _depth;
    }

    auto mouse_x() const noexcept -> const auto& {
        return _mouse_x;
    }

    auto mouse_y() const noexcept -> const auto& {
        return _mouse_y;
    }

    auto mouse_z() const noexcept -> const auto& {
        return _mouse_z;
    }

    auto aspect() const noexcept {
        return width().as<float>() / height().as<float>();
    }

    auto exec_time() const noexcept -> seconds_t<float> {
        return seconds_(_exe_time.value());
    }

    auto user_activity_time() const noexcept -> seconds_t<float> {
        return seconds_(_usr_act_time);
    }

    auto user_idle_time() const noexcept -> seconds_t<float> {
        return exec_time() - user_activity_time();
    }

    auto user_idle() const noexcept -> example_state_value<bool> {
        return {_new_user_idle, _old_user_idle};
    }

    auto user_became_idle() const noexcept -> bool {
        return user_idle().delta() > 0;
    }

    auto user_became_active() const noexcept -> bool {
        return user_idle().delta() < 0;
    }

    auto frame_duration() const noexcept -> seconds_t<float> {
        return seconds_(_exe_time.delta());
    }

    auto frame_number() const noexcept -> int {
        return _frame_no;
    }

    auto x_tiles() const noexcept -> int {
        return _x_tiles;
    }

    auto tile_i() const noexcept -> int {
        EAGINE_ASSERT(_tile_i < _x_tiles);
        return _tile_i;
    }

    auto tile_w() const noexcept -> int {
        return (width() / x_tiles()) + ((tile_i() + 1 == x_tiles()) ? 1 : 0);
    }

    auto tile_x() const noexcept -> int {
        return tile_i() * (width() / x_tiles());
    }

    auto y_tiles() const noexcept -> int {
        return _y_tiles;
    }

    auto tile_j() const noexcept -> int {
        EAGINE_ASSERT(_tile_j < _y_tiles);
        return _tile_j;
    }

    auto tile_h() const noexcept -> int {
        return (height() / y_tiles()) + ((tile_j() + 1 == y_tiles()) ? 1 : 0);
    }

    auto tile_y() const noexcept -> int {
        return tile_j() * (height() / y_tiles());
    }

    auto multiple_tiles() const noexcept -> bool {
        return x_tiles() > 1 || y_tiles() > 1;
    }

    auto mouse_button_pressed(int button) const noexcept
      -> example_state_value<bool>;

    auto pointer_dragging(int index = 0) const noexcept -> bool;

    auto norm_pointer_x(int index = 0) const noexcept
      -> example_state_value<float>;

    auto norm_pointer_y(int index = 0) const noexcept
      -> example_state_value<float>;

    auto norm_pointer_z(int index = 0) const noexcept
      -> example_state_value<float>;

    auto ndc_pointer_x(int index = 0) const noexcept
      -> example_state_value<float>;

    auto ndc_pointer_y(int index = 0) const noexcept
      -> example_state_value<float>;

    auto pointer_radius(int index = 0) const noexcept
      -> example_state_value<float>;

    auto pointer_angle(int index = 0) const noexcept
      -> example_state_value<radians_t<float>>;
};

class example_state;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_STATE_VIEW_HPP
