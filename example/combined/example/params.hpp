/**
 *  .file oglplus/example/params.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_PARAMS_HPP
#define OGLPLUS_EXAMPLE_PARAMS_HPP

#include <eagine/assert.hpp>
#include <eagine/quantities.hpp>
#include <eagine/string_span.hpp>
#include <eagine/valid_if/not_empty.hpp>
#include <eagine/valid_if/positive.hpp>

namespace eagine {

enum class example_resource_type {
    texture_image,
    shader_source,
    program_source
};

class example_params {
private:
    unsigned _rand_seed{0};

    string_view _exec_cmd{};
    string_view _framedump_prefix{};
    string_view _screenshot_path{};
    float _screenshot_time{3.F};
    float _fixed_fps{30.F};

    int _x_pos{64};
    int _y_pos{64};

    int _x_tiles{1};
    int _y_tiles{1};

    int _samples{4};

    int _color_bits{8};
    int _alpha_bits{0};
    int _depth_bits{24};
    int _stencil_bits{0};

    bool _compat_ctxt{false};
    bool _debug_ctxt{true};
    bool _auto_tiles{true};
    bool _demo_mode{false};
    bool _high_quality{false};

public:
    example_params() noexcept = default;

    auto exec_command(valid_if_not_empty<string_view> cmd) -> auto& {
        _exec_cmd = cmd.value();
        return *this;
    }

    auto exec_command() const noexcept -> string_view {
        return _exec_cmd;
    }

    auto is_readable_file(string_view path) const noexcept -> bool;

    auto
    find_resource_file_path(string_view res_group, string_view res_name) const
      -> valid_if_not_empty<std::string>;

    auto find_resource_file_path(string_view res_name) const
      -> valid_if_not_empty<std::string> {
        return find_resource_file_path(string_view(), res_name);
    }

    auto
    find_resource_file_path(example_resource_type, string_view res_name) const
      -> valid_if_not_empty<std::string>;

    auto
    get_resource_file_path(example_resource_type, string_view res_name) const
      -> std::string;

    auto screenshot_path(valid_if_not_empty<string_view> path) -> auto& {
        _screenshot_path = path.value();
        return *this;
    }

    auto screenshot_path() const noexcept -> string_view {
        return _screenshot_path;
    }

    auto doing_screenshot() const noexcept -> bool {
        return !_screenshot_path.empty();
    }

    auto screenshot_time(seconds_t<float> ss_time) -> auto& {
        _screenshot_time = value(ss_time);
        return *this;
    }

    auto screenshot_time() const noexcept -> seconds_t<float> {
        return seconds_(_screenshot_time);
    }

    auto framedump_prefix(valid_if_not_empty<string_view> prefix) -> auto& {
        _framedump_prefix = prefix.value();
        return *this;
    }

    auto framedump_prefix() const noexcept -> string_view {
        return _framedump_prefix;
    }

    auto doing_framedump() const noexcept -> bool {
        return !_framedump_prefix.empty();
    }

    auto fixed_framerate() const noexcept -> bool {
        return doing_screenshot() || doing_framedump();
    }

    auto fixed_fps(valid_if_positive<float> fps) noexcept -> auto& {
        _fixed_fps = fps.value();
        return *this;
    }

    auto frame_time() const noexcept -> float {
        return 1.0F / _fixed_fps;
    }

    auto window_x_pos(int pos) noexcept -> auto& {
        _x_pos = pos;
        return *this;
    }

    auto window_x_pos() const noexcept -> int {
        return _x_pos;
    }

    auto window_y_pos(int pos) noexcept -> auto& {
        _y_pos = pos;
        return *this;
    }

    auto window_y_pos() const noexcept -> int {
        return _y_pos;
    }

    auto rand_seed(unsigned seed) noexcept -> auto& {
        _rand_seed = seed;
        return *this;
    }

    auto rand_seed() const noexcept -> valid_if_positive<unsigned> {
        return {_rand_seed};
    }

    auto compatibility_context(bool v) noexcept -> auto& {
        _compat_ctxt = v;
        return *this;
    }

    auto compatibility_context() const noexcept -> bool {
        return _compat_ctxt;
    }

    auto debugging_context(bool v) noexcept -> auto& {
        _debug_ctxt = v;
        return *this;
    }

    auto debugging_context() const noexcept -> bool {
        return _debug_ctxt;
    }

    auto auto_tiles(bool v) noexcept -> auto& {
        _auto_tiles = v;
        return *this;
    }

    auto auto_tiles() const noexcept -> bool {
        return _auto_tiles;
    }

    auto x_tiles(valid_if_positive<int> n) noexcept -> auto& {
        _x_tiles = n.value();
        return *this;
    }

    auto x_tiles() const noexcept -> int {
        return _x_tiles;
    }

    auto y_tiles(valid_if_positive<int> n) noexcept -> auto& {
        _y_tiles = n.value();
        return *this;
    }

    auto y_tiles() const noexcept -> int {
        return _y_tiles;
    }

    auto demo_mode(bool v) noexcept -> auto& {
        _demo_mode = v;
        return *this;
    }

    auto demo_mode() const noexcept -> bool {
        return _demo_mode;
    }

    auto high_quality(bool v) noexcept -> auto& {
        _high_quality = v;
        return *this;
    }

    auto high_quality() const noexcept -> bool {
        return _high_quality;
    }

    auto samples(valid_if_positive<int> n) noexcept -> auto& {
        _samples = n.value();
        return *this;
    }

    auto samples_dont_care() noexcept -> auto& {
        _samples = 0;
        return *this;
    }

    auto samples() const noexcept -> valid_if_positive<int> {
        return _samples;
    }

    auto color_bits(int n) noexcept -> auto& {
        EAGINE_ASSERT(n >= 0);
        _color_bits = n;
        return *this;
    }

    auto color_bits() const noexcept -> int {
        return _color_bits;
    }

    auto with_alpha(bool v) noexcept -> auto& {
        _alpha_bits = v ? 8 : 0;
        return *this;
    }

    auto alpha_bits() const noexcept -> int {
        return _alpha_bits;
    }

    auto depth_buffer(bool v) noexcept -> auto& {
        _depth_bits = v ? 24 : 0;
        return *this;
    }

    auto depth_bits() const noexcept -> int {
        return _depth_bits;
    }

    auto depth_buffer() const noexcept -> bool {
        return _depth_bits > 0;
    }

    auto stencil_buffer(bool v) noexcept -> auto& {
        _stencil_bits = v ? 8 : 0;
        return *this;
    }

    auto stencil_bits() const noexcept -> int {
        return _stencil_bits;
    }

    auto stencil_buffer() const noexcept -> bool {
        return _stencil_bits > 0;
    }
};

extern void adjust_params(example_params&);

} // namespace eagine

#endif // OGLPLUS_EXAMPLE_PARAMS_HPP
