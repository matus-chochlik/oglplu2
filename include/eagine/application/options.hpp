/// @file
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
/// @brief Class holding and managing video-related application options.
/// @ingroup application
/// @see audio_options
/// @see launch_options
/// @see application_config
///
/// Instances of this class read the application configuration and provide
/// access to video/graphics rendering-related options.
class video_options {
public:
    video_options(
      application_config&,
      video_context_kind kind,
      string_view instance);

    video_options(
      main_ctx_object& obj,
      video_context_kind kind,
      identifier instance);

    /// @brief Returns the requested video rendering context kind.
    auto video_kind() const noexcept -> video_context_kind {
        return _video_kind;
    }

    /// @brief Sets the video provider identifier name.
    /// @see has_provider
    auto set_provider(std::string name) -> auto& {
        _provider_name = std::move(name);
        return *this;
    }

    /// @brief Indicates if video provider name is set (not empty).
    /// @see set_provider
    auto has_provider() const noexcept -> bool {
        return !extract(_provider_name).empty();
    }

    /// @brief Indicates if video provider name is the same as the argument.
    /// @see set_provider
    auto has_provider(string_view name) const noexcept -> bool {
        return are_equal(string_view(_provider_name), name);
    }

    /// @brief Returns the assigned provider name.
    auto provider() const noexcept -> valid_if_not_empty<string_view> {
        return {_provider_name};
    }

    /// @brief Returns the display name string (this may be provider-specific).
    /// @see driver_name
    /// @see device_path
    /// @see device_kind
    auto display_name() const noexcept -> valid_if_not_empty<string_view> {
        return {_display_name};
    }

    /// @brief Returns the driver name string (this may be provider-specific).
    /// @see display_name
    /// @see device_path
    /// @see device_kind
    auto driver_name() const noexcept -> valid_if_not_empty<string_view> {
        return {_driver_name};
    }

    /// @brief Returns the driver name string (this may be provider-specific).
    /// @see display_name
    /// @see driver_name
    /// @see device_kind
    auto device_path() const noexcept -> valid_if_not_empty<string_view> {
        return {_device_path};
    }

    /// @brief Returns the rendering device kind (this may be provider-specific).
    /// @see display_name
    /// @see driver_name
    /// @see device_path
    /// @see device_index
    auto device_kind() const noexcept
      -> valid_if_not<video_device_kind, video_device_kind::dont_care> {
        return {_device_kind};
    }

    /// @brief Returns the rendering device index (this may be provider-specific).
    /// @see display_name
    /// @see driver_name
    /// @see device_path
    /// @see device_kind
    auto device_index() const noexcept -> valid_if_nonnegative<span_size_t> {
        return _device_idx;
    }

    /// @brief Indicates that if both GL and GL|ES is available, ES should be used.
    /// @see gl_version_major
    /// @see gl_version_minor
    auto prefer_gles() const noexcept -> bool {
        return _prefer_gles;
    }

    /// @brief Alias for GL major version value type.
    using valid_gl_major_version = valid_if_positive<int>;

    /// @brief Alias for GL minor version value type.
    using valid_gl_minor_version = valid_if_nonnegative<int>;

    /// @brief Returns the preferred GL major version number.
    auto gl_version_major() const noexcept -> valid_gl_major_version {
        return {_gl_version_major};
    }

    /// @brief Returns the preferred GL major version number.
    /// @see gl_version_minor
    /// @see prefer_gles
    auto gl_version_minor() const noexcept -> valid_gl_minor_version {
        return {_gl_version_minor};
    }

    /// @brief Returns the preferred GL minor version number.
    /// @see gl_version_major
    /// @see prefer_gles
    auto gl_compatibility_context() const noexcept -> bool {
        return _gl_compat_context;
    }

    /// @brief Indicates if a debug GL context should be created.
    /// @see gl_robust_access
    auto gl_debug_context() const noexcept -> bool {
        return _gl_debug_context;
    }

    /// @brief Indicates if a GL context with robust access checks should be created.
    /// @see gl_debug_context
    auto gl_robust_access() const noexcept -> bool {
        return _gl_robust_access;
    }

    /// @brief Alias for the video surface width or height dimension value type.
    using valid_surface_size = valid_if_positive<int>;

    /// @brief Sets the rendering surface size.
    auto surface_size(valid_surface_size width, valid_surface_size height)
      -> auto& {
        _surface_width = extract(width);
        _surface_height = extract(height);
        return *this;
    }

    /// @brief Returns the rendering surface width (in pixels).
    /// @see surface_height
    auto surface_width() const noexcept -> valid_surface_size {
        return {_surface_width};
    }

    /// @brief Returns the rendering surface height (in pixels).
    /// @see surface_width
    auto surface_height() const noexcept -> valid_surface_size {
        return {_surface_height};
    }

    /// @brief Alias for the number of pixel samples value type.
    using valid_samples = valid_if_nonnegative<int>;

    /// @brief Sets the number of per-pixel samples.
    /// @see samples_dont_care
    auto samples(const valid_samples& value) noexcept -> auto& {
        _samples = extract(value);
        return *this;
    }

    /// @brief Sets the number of per-pixel samples to a "don't care" value.
    /// @see samples
    auto samples_dont_care() noexcept -> auto& {
        _samples = 0;
        return *this;
    }

    /// @brief Returns the number of per-pixel samples.
    auto samples() const noexcept -> valid_if_positive<int> {
        return {_samples};
    }

    /// @brief Alias for color channel bit count value type.
    using valid_color_bits = valid_if_between<int, 0, 16>;

    /// @brief Sets the number of red, green and blue channel bits.
    /// @see alpha_bits
    /// @see depth_bits
    /// @see stencil_bits
    auto color_bits(const valid_color_bits& value) noexcept -> auto& {
        _color_bits = extract(value);
        return *this;
    }

    /// @brief Returns the number of red, green and blue channel bits.
    auto color_bits() const noexcept -> valid_if_positive<int> {
        return {_color_bits};
    }

    /// @brief Alias for alpha channel bit count value type.
    using valid_alpha_bits = valid_if_between<int, 0, 16>;

    /// @brief Sets the number of alpha channel bits.
    /// @see color_bits
    /// @see depth_bits
    /// @see stencil_bits
    auto alpha_bits(const valid_alpha_bits& value) noexcept -> auto& {
        _alpha_bits = extract(value);
        return *this;
    }

    /// @brief Sets the number of alpha channel bits to a default non-zero value.
    /// @see alpha_bits
    /// @see with_depth
    /// @see with_stencil
    auto with_alpha() noexcept -> auto& {
        _alpha_bits = 8;
        return *this;
    }

    /// @brief Returns the number of alpha channel bits.
    auto alpha_bits() const noexcept -> valid_if_positive<int> {
        return {_alpha_bits};
    }

    /// @brief Alias for depth buffer bit count value type.
    using valid_depth_bits = valid_if_between<int, 0, 32>;

    /// @brief Sets the number of depth buffer bits.
    /// @see color_bits
    /// @see alpha_bits
    /// @see stencil_bits
    auto depth_bits(const valid_depth_bits& value) noexcept -> auto& {
        _depth_bits = extract(value);
        return *this;
    }

    /// @brief Sets the number of depth buffer bits to a default non-zero value.
    /// @see with_alpha
    /// @see with_stencil
    auto with_depth() noexcept -> auto& {
        _depth_bits = 24;
        return *this;
    }

    /// @brief Returns the number of depth buffer bits.
    auto depth_bits() const noexcept -> valid_if_positive<int> {
        return {_depth_bits};
    }

    /// @brief Alias for stencil buffer bit count value type.
    using valid_stencil_bits = valid_if_one_of<int, 0, 8>;

    /// @brief Sets the number of stencil buffer bits.
    /// @see color_bits
    /// @see alpha_bits
    /// @see depth_bits
    auto stencil_bits(const valid_stencil_bits& value) noexcept -> auto& {
        _stencil_bits = extract(value);
        return *this;
    }

    /// @brief Sets the number of stencil buffer bits to a default non-zero value.
    /// @see with_alpha
    /// @see with_depth
    auto with_stencil() noexcept -> auto& {
        _stencil_bits = 8;
        return *this;
    }

    /// @brief Returns the number of stencil buffer bits.
    auto stencil_bits() const noexcept -> valid_if_positive<int> {
        return {_stencil_bits};
    }

    /// @brief Requests an off-screen rendering surface.
    /// @see fullscreen
    auto offscreen(bool value) noexcept -> auto& {
        if((_offscreen = value)) {
            _surface_width = 0;
            _surface_height = 0;
        }
        return *this;
    }

    /// @brief Indicates if an off-screen rendering surface was requested.
    auto offscreen() const noexcept -> bool {
        return _offscreen;
    }

    auto needs_offscreen_framebuffer() const noexcept -> bool {
        return _offscreen_framebuffer;
    }

    /// @brief Requests an full-screen rendering surface.
    /// @see offscreen
    auto fullscreen(bool value) noexcept -> auto& {
        if((_fullscreen = value)) {
            _surface_width = 0;
            _surface_height = 0;
        }
        return *this;
    }

    /// @brief Indicates if an full-screen rendering surface was requested.
    auto fullscreen() const noexcept -> bool {
        return _fullscreen;
    }

    /// @brief Returns a filesystem prefix for framedump image files.
    auto framedump_prefix() const noexcept -> string_view {
        return {_framedump_prefix};
    }

    /// @brief Returns the pixel data type for color/alpha buffer frame dumps.
    auto framedump_color() const noexcept -> framedump_data_type {
        return _framedump_color;
    }

    /// @brief Returns the pixel data type for depth buffer frame dumps.
    auto framedump_depth() const noexcept -> framedump_data_type {
        return _framedump_depth;
    }

    /// @brief Returns the pixel data type for stencil buffer frame dumps.
    auto framedump_stencil() const noexcept -> framedump_data_type {
        return _framedump_stencil;
    }

    /// @brief Indicates if a frame dump render run is requested.
    auto doing_framedump() const noexcept -> bool {
        return (_framedump_color != framedump_data_type::none) ||
               (_framedump_depth != framedump_data_type::none) ||
               (_framedump_stencil != framedump_data_type::none);
    }

private:
    video_context_kind _video_kind;

    application_config_value<std::string, string_view> _provider_name;
    application_config_value<std::string, string_view> _display_name;
    application_config_value<std::string, string_view> _driver_name;
    application_config_value<std::string, string_view> _device_path;
    application_config_value<std::string, string_view> _framedump_prefix;

    application_config_value<valid_if_nonnegative<span_size_t>> _device_idx;

    application_config_value<int> _gl_version_major;
    application_config_value<int> _gl_version_minor;

    application_config_value<int> _surface_width;
    application_config_value<int> _surface_height;

    application_config_value<int> _samples;
    application_config_value<int> _color_bits;
    application_config_value<int> _alpha_bits;
    application_config_value<int> _depth_bits;
    application_config_value<int> _stencil_bits;

    application_config_value<bool> _prefer_gles;
    application_config_value<bool> _gl_debug_context;
    application_config_value<bool> _gl_robust_access;
    application_config_value<bool> _gl_compat_context;
    application_config_value<bool> _fullscreen;
    application_config_value<bool> _offscreen;
    application_config_value<bool> _offscreen_framebuffer;
    application_config_value<video_device_kind> _device_kind;
    application_config_value<framedump_data_type> _framedump_color;
    application_config_value<framedump_data_type> _framedump_depth;
    application_config_value<framedump_data_type> _framedump_stencil;
};
//------------------------------------------------------------------------------
/// @brief Class holding and managing audio-related application options.
/// @ingroup application
/// @see video_options
/// @see launch_options
/// @see application_config
///
/// Instances of this class read the application configuration and provide
/// access to audio/sound playback and recording-related options.
class audio_options {
public:
    audio_options(
      main_ctx_object&,
      audio_context_kind kind,
      identifier instance);

    /// @brief Returns the requested audio rendering context kind.
    auto audio_kind() const noexcept {
        return _audio_kind;
    }

private:
    friend class execution_context;

    audio_context_kind _audio_kind;
};
//------------------------------------------------------------------------------
/// @brief Class managing options for an application with video / audio rendering.
/// @ingroup application
/// @see video_options
/// @see audio_options
/// @see application_config
///
/// Instances of this class read the application configuration and provide
/// access to general application options.
class launch_options : public main_ctx_object {
public:
    /// @brief Constructor with parent main context object.
    launch_options(main_ctx_parent parent) noexcept;

    /// @brief Returns the title of the application.
    auto application_title() const noexcept -> string_view;

    /// @brief Specifies that no video rendering should be used.
    /// @see require_video
    /// @see no_audio
    /// @see no_input
    auto no_video() noexcept -> auto& {
        _video_opts.clear();
        return *this;
    }

    /// @brief Requests a new video rendering context and surface.
    /// @param kind the kind of the requested context.
    /// @see instance identifier for the requested context.
    /// @see no_video
    /// @see require_audio
    /// @see video_requirements
    auto require_video(
      video_context_kind kind = video_context_kind::opengl,
      identifier instance = {}) -> video_options&;

    /// @brief Returns all current video rendering context options.
    /// @see require_video
    /// @see audio_requirements
    auto video_requirements() const noexcept
      -> const std::map<identifier, video_options>& {
        return _video_opts;
    }

    /// @brief Specifies that no audio playback or recording should be used.
    /// @see require_audio
    /// @see no_video
    /// @see no_input
    auto no_audio() noexcept -> auto& {
        _audio_opts.clear();
        return *this;
    }

    /// @brief Requests a new audio playback and recording context.
    /// @param kind the kind of the requested context.
    /// @see instance identifier for the requested context.
    /// @see no_audio
    /// @see require_video
    /// @see audio_requirements
    auto require_audio(
      audio_context_kind kind = audio_context_kind::openal,
      identifier instance = {}) -> audio_options&;

    /// @brief Returns all current audio rendering context options.
    /// @see require_audio
    /// @see video_requirements
    auto audio_requirements() const noexcept
      -> const std::map<identifier, audio_options>& {
        return _audio_opts;
    }

    /// @brief Specifies that no user input should be used.
    /// @see require_input
    /// @see no_video
    /// @see no_audio
    auto no_input() noexcept -> auto& {
        _requires_input = false;
        return *this;
    }

    /// @brief Specifies that user input handling is required.
    /// @see no_input
    /// @see require_input
    auto require_input() noexcept -> auto& {
        _requires_input = true;
        return *this;
    }

    /// @brief Indicates if user input handling is required.
    auto required_input() const noexcept -> bool {
        return _requires_input;
    }

    /// @brief Says if the application ran long enough according to the configuration.
    template <typename R, typename P>
    auto enough_run_time(std::chrono::duration<R, P> run_time) const noexcept
      -> bool {
        return _max_run_time && extract(_max_run_time) <= run_time;
    }

    /// @brief Says if the application rendered enough frames according to the configuration.
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
