/// @file eagine/application/options.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_OPTIONS_HPP
#define EAGINE_APPLICATION_OPTIONS_HPP

#include "../main_ctx_object.hpp"
#include "../string_span.hpp"
#include "../valid_if/between.hpp"
#include "../valid_if/nonnegative.hpp"
#include "../valid_if/not_empty.hpp"
#include "../valid_if/not_equal.hpp"
#include "../valid_if/one_of.hpp"
#include "../valid_if/positive.hpp"
#include "fwd.hpp"
#include "types.hpp"
#include <map>

namespace eagine::application {
//------------------------------------------------------------------------------
class video_options {
public:
    video_options(
      main_ctx_object&,
      video_context_kind kind,
      identifier instance);

    auto video_kind() const noexcept {
        return _video_kind;
    }

    auto has_provider(string_view name) const noexcept -> bool {
        return are_equal(string_view(_provider_name), name);
    }

    auto display_name() const noexcept -> valid_if_not_empty<string_view> {
        return {_display_name};
    }

    auto driver_name() const noexcept -> valid_if_not_empty<string_view> {
        return {_driver_name};
    }

    auto device_path() const noexcept -> valid_if_not_empty<string_view> {
        return {_device_path};
    }

    auto device_kind() const noexcept
      -> valid_if_not<video_device_kind, video_device_kind::dont_care> {
        return _device_kind;
    }

    auto device_index() const noexcept -> valid_if_nonnegative<span_size_t> {
        return _device_idx;
    }

    auto prefer_gles() const noexcept -> bool {
        return _prefer_gles;
    }

    using valid_gl_major_version = valid_if_positive<int>;
    using valid_gl_minor_version = valid_if_nonnegative<int>;

    auto gl_version_major() const noexcept -> valid_gl_major_version {
        return {_gl_version_major};
    }

    auto gl_version_minor() const noexcept -> valid_gl_minor_version {
        return {_gl_version_minor};
    }

    auto gl_compatibility_context() const noexcept -> bool {
        return _gl_compat_context;
    }

    auto gl_debug_context() const noexcept -> bool {
        return _gl_debug_context;
    }

    auto gl_robust_access() const noexcept -> bool {
        return _gl_robust_access;
    }

    using valid_surface_size = valid_if_positive<int>;
    auto surface_size(valid_surface_size width, valid_surface_size height)
      -> auto& {
        _surface_width = extract(width);
        _surface_height = extract(height);
        return *this;
    }

    auto surface_width() const noexcept -> valid_surface_size {
        return {_surface_width};
    }

    auto surface_height() const noexcept -> valid_surface_size {
        return {_surface_height};
    }

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

    auto color_bits() const noexcept -> valid_if_positive<int> {
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

    auto alpha_bits() const noexcept -> valid_if_positive<int> {
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

    auto depth_bits() const noexcept -> valid_if_positive<int> {
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

    auto stencil_bits() const noexcept -> valid_if_positive<int> {
        return _stencil_bits;
    }

    auto offscreen(bool value) noexcept -> auto& {
        if((_offscreen = value)) {
            _surface_width = 0;
            _surface_height = 0;
        }
        return *this;
    }

    auto offscreen() const noexcept -> bool {
        return _offscreen;
    }

    auto needs_offscreen_framebuffer() const noexcept -> bool {
        return _offscreen_framebuffer;
    }

    auto fullscreen(bool value) noexcept -> auto& {
        if((_fullscreen = value)) {
            _surface_width = 0;
            _surface_height = 0;
        }
        return *this;
    }

    auto fullscreen() const noexcept -> bool {
        return _fullscreen;
    }

    auto framedump_prefix() const noexcept -> string_view {
        return {_framedump_prefix};
    }

    auto framedump_color() const noexcept -> framedump_data_type {
        return _framedump_color;
    }

    auto framedump_depth() const noexcept -> framedump_data_type {
        return _framedump_depth;
    }

    auto framedump_stencil() const noexcept -> framedump_data_type {
        return _framedump_stencil;
    }

    auto doing_framedump() const noexcept -> bool {
        return (_framedump_color != framedump_data_type::none) ||
               (_framedump_depth != framedump_data_type::none) ||
               (_framedump_stencil != framedump_data_type::none);
    }

private:
    friend class execution_context;

    video_context_kind _video_kind;
    std::string _provider_name;
    std::string _display_name;
    std::string _driver_name;
    std::string _device_path;
    std::string _framedump_prefix;

    valid_if_nonnegative<span_size_t> _device_idx{-1};

    int _gl_version_major{-1};
    int _gl_version_minor{-1};

    int _surface_width{1280};
    int _surface_height{800};

    int _samples{0};
    int _color_bits{8};
    int _alpha_bits{0};
    int _depth_bits{24};
    int _stencil_bits{0};

    video_device_kind _device_kind{video_device_kind::dont_care};
    bool _prefer_gles{false};
    bool _gl_debug_context{false};
    bool _gl_robust_access{false};
    bool _gl_compat_context{false};
    bool _fullscreen{false};
    bool _offscreen{false};
    bool _offscreen_framebuffer{false};
    framedump_data_type _framedump_color{framedump_data_type::none};
    framedump_data_type _framedump_depth{framedump_data_type::none};
    framedump_data_type _framedump_stencil{framedump_data_type::none};
};
//------------------------------------------------------------------------------
class audio_options {
public:
    audio_options(
      main_ctx_object&,
      audio_context_kind kind,
      identifier instance);

    auto audio_kind() const noexcept {
        return _audio_kind;
    }

private:
    friend class execution_context;

    audio_context_kind _audio_kind;
};
//------------------------------------------------------------------------------
class launch_options : public main_ctx_object {
public:
    launch_options(main_ctx_parent parent) noexcept;

    auto application_title() const noexcept -> string_view;

    auto no_video() noexcept -> auto& {
        _video_opts.clear();
        return *this;
    }

    auto require_video(
      video_context_kind kind = video_context_kind::opengl,
      identifier instance = {}) -> video_options&;

    auto video_requirements() const noexcept -> auto& {
        return _video_opts;
    }

    auto no_audio() noexcept -> auto& {
        _audio_opts.clear();
        return *this;
    }

    auto require_audio(
      audio_context_kind kind = audio_context_kind::openal,
      identifier instance = {}) -> audio_options&;

    auto audio_requirements() const noexcept -> auto& {
        return _audio_opts;
    }

    auto no_input() noexcept -> auto& {
        _requires_input = false;
        return *this;
    }

    auto require_input() noexcept -> auto& {
        _requires_input = true;
        return *this;
    }

    auto required_input() const noexcept {
        return _requires_input;
    }

    template <typename R, typename P>
    auto enough_run_time(std::chrono::duration<R, P> run_time) const noexcept
      -> bool {
        return _max_run_time && extract(_max_run_time) <= run_time;
    }

    auto enough_frames(span_size_t frame_no) const noexcept -> bool {
        return _max_frames && extract(_max_frames) <= frame_no;
    }

private:
    friend class execution_context;

    std::string _app_title;

    std::map<identifier, video_options> _video_opts;
    std::map<identifier, audio_options> _audio_opts;

    valid_if_positive<std::chrono::seconds> _max_run_time{};
    valid_if_positive<span_size_t> _max_frames{-1};
    bool _requires_input{false};
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/options.inl>
#endif

#endif
