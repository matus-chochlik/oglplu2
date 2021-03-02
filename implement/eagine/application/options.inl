/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main_ctx.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// video_options
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
video_options::video_options(
  main_ctx_object& obj,
  video_context_kind kind,
  identifier instance)
  : video_options{obj.main_context().config(), kind, instance.name()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
video_options::video_options(
  application_config& c,
  video_context_kind kind,
  string_view instance)
  : _video_kind{kind}
  , _provider_name{c, "application.video.provider", instance}
  , _display_name{c, "application.video.display", instance}
  , _driver_name{c, "application.video.driver", instance}
  , _device_path{c, "application.video.device.path", instance}
  , _framedump_prefix{c, "application.video.framedump.prefix", instance}
  , _device_idx{c, "application.video.device.index", instance, -1}
  , _gl_version_major{c, "application.opengl.version.major", instance, -1}
  , _gl_version_minor{c, "application.opengl.version.minor", instance, -1}
  , _surface_width{c, "application.video.surface.width", instance, 1280}
  , _surface_height{c, "application.video.surface.height", instance, 800}
  , _samples{c, "application.video.samples", instance, 0}
  , _color_bits{c, "application.video.color_bits", instance, 8}
  , _alpha_bits{c, "application.video.alpha_bits", instance, 0}
  , _depth_bits{c, "application.video.depth_bits", instance, 24}
  , _stencil_bits{c, "application.video.stencil_bits", instance, 0}
  , _prefer_gles{c, "application.opengl.prefer_es", instance, false}
  , _gl_debug_context{c, "application.opengl.debug_context", instance, false}
  , _gl_robust_access{c, "application.opengl.robust_access", instance, false}
  , _gl_compat_context{c, "application.opengl.compatibility", instance, false}
  , _fullscreen{c, "application.video.fullscreen", instance, false}
  , _offscreen{c, "application.video.offscreen", instance, false}
  , _offscreen_framebuffer{c, "application.video.frambuffer", instance, false}
  , _device_kind{c, "application.video.device.kind", instance, video_device_kind::dont_care}
  , _framedump_color{c, "application.video.framedump.color", instance, framedump_data_type::none}
  , _framedump_depth{c, "application.video.framedump.depth", instance, framedump_data_type::none}
  , _framedump_stencil{
      c,
      "application.video.framedump.stencil",
      instance,
      framedump_data_type::none} {}
//------------------------------------------------------------------------------
// audio_options
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
audio_options::audio_options(
  main_ctx_object&,
  audio_context_kind kind,
  identifier)
  : _audio_kind{kind} {}
//------------------------------------------------------------------------------
// launch_options
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
launch_options::launch_options(main_ctx_parent parent) noexcept
  : main_ctx_object(EAGINE_ID(LaunchOpts), parent) {
    _max_run_time = cfg_init("application.max_run_time", _max_run_time);
    _max_frames = cfg_init("application.max_frames", _max_frames);
    _requires_input = cfg_init("application.input.required", _requires_input);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto launch_options::application_title() const noexcept -> string_view {
    if(_app_title.empty()) {
        return main_context().app_name();
    }
    return {_app_title};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto launch_options::require_video(video_context_kind kind, identifier instance)
  -> video_options& {
    auto pos = _video_opts.find(instance);
    if(pos == _video_opts.end()) {
        pos = _video_opts
                .try_emplace(instance, video_options(*this, kind, instance))
                .first;
    }
    return pos->second;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto launch_options::require_audio(audio_context_kind kind, identifier instance)
  -> audio_options& {
    auto pos = _audio_opts.find(instance);
    if(pos == _audio_opts.end()) {
        pos = _audio_opts
                .try_emplace(instance, audio_options(*this, kind, instance))
                .first;
    }
    return pos->second;
}
//------------------------------------------------------------------------------
} // namespace eagine::application
