/**
 *  @file eagine/application/options.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_OPTIONS_HPP
#define EAGINE_APPLICATION_OPTIONS_HPP

#include "../main_ctx_object.hpp"
#include "../valid_if/between.hpp"
#include "../valid_if/nonnegative.hpp"
#include "../valid_if/one_of.hpp"
#include "../valid_if/positive.hpp"

namespace eagine::application {

class launch_options : public main_ctx_object {
public:
    launch_options(main_ctx_parent parent) noexcept
      : main_ctx_object(EAGINE_ID(LaunchOpts), parent) {}

    using valid_samples = valid_if_nonnegative<int>;
    auto samples(const valid_samples& value) noexcept -> auto& {
        _samples = extract(value);
        return *this;
    }

    auto samples_dont_care() noexcept -> auto& {
        _samples = 0;
        return *this;
    }

    auto samples() const noexcept -> valid_if_positive<int> {
        return _samples;
    }

    using valid_color_bits = valid_if_between<int, 0, 16>;
    auto color_bits(const valid_color_bits& value) noexcept -> auto& {
        _color_bits = extract(value);
        return *this;
    }

    auto color_bits() const noexcept -> int {
        return _color_bits;
    }

    using valid_alpha_bits = valid_if_between<int, 0, 16>;
    auto alpha_bits(const valid_alpha_bits& value) noexcept -> auto& {
        _alpha_bits = extract(value);
        return *this;
    }

    auto with_alpha() noexcept -> auto& {
        _alpha_bits = 8;
        return *this;
    }

    auto alpha_bits() const noexcept -> int {
        return _alpha_bits;
    }

    using valid_depth_bits = valid_if_between<int, 0, 32>;
    auto depth_bits(const valid_depth_bits& value) noexcept -> auto& {
        _depth_bits = extract(value);
        return *this;
    }

    auto with_depth() noexcept -> auto& {
        _depth_bits = 24;
        return *this;
    }

    auto depth_bits() const noexcept -> int {
        return _depth_bits;
    }

    using valid_stencil_bits = valid_if_one_of<int, 0, 8>;
    auto stencil_bits(const valid_stencil_bits& value) noexcept -> auto& {
        _stencil_bits = extract(value);
        return *this;
    }

    auto with_stencil() noexcept -> auto& {
        _stencil_bits = 8;
        return *this;
    }

    auto stencil_bits() const noexcept -> int {
        return _stencil_bits;
    }

private:
    int _samples{cfg_extr<valid_samples>("application.visual.samples", 0)};

    int _color_bits{
      cfg_extr<valid_color_bits>("application.visual.color_bits", 8)};

    int _alpha_bits{
      cfg_extr<valid_alpha_bits>("application.visual.alpha_bits", 0)};

    int _depth_bits{
      cfg_extr<valid_depth_bits>("application.visual.depth_bits", 24)};

    int _stencil_bits{
      cfg_extr<valid_stencil_bits>("application.visual.stencil_bits", 0)};
};

} // namespace eagine::application

#endif
