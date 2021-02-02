/**
 *  @file eagine/application/options.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main_ctx.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// video_options
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
video_options::video_options(
  main_ctx_object& o,
  video_context_kind kind,
  identifier instance)
  : _video_kind{kind} {
    const auto instname = instance.name();
    _provider_name =
      o.cfg_init("application.video.provider", std::string(), instname);
    _display_name =
      o.cfg_init("application.video.display", std::string(), instname);
    _device_idx =
      o.cfg_init("application.video.device.index", _device_idx, instname);
    _device_kind =
      o.cfg_init("application.video.device.kind", _device_kind, instname);
    _device_path =
      o.cfg_init("application.video.device.path", _device_path, instname);
    _driver_name =
      o.cfg_init("application.video.driver", std::string(), instname);

    _gl_version_major = o.cfg_extr<valid_gl_major_version>(
      "application.opengl.version.major", _gl_version_major, instname);
    _gl_version_minor = o.cfg_extr<valid_gl_minor_version>(
      "application.opengl.version.minor", _gl_version_minor, instname);

    _surface_width = o.cfg_extr<valid_surface_size>(
      "application.video.surface.width", _surface_width, instname);
    _surface_height = o.cfg_extr<valid_surface_size>(
      "application.video.surface.height", _surface_height, instname);

    _samples = o.cfg_extr<valid_samples>(
      "application.video.samples", _samples, instname);
    _color_bits = o.cfg_extr<valid_color_bits>(
      "application.video.color_bits", _color_bits, instname);
    _alpha_bits = o.cfg_extr<valid_alpha_bits>(
      "application.video.alpha_bits", _alpha_bits, instname);
    _depth_bits = o.cfg_extr<valid_depth_bits>(
      "application.video.depth_bits", _depth_bits, instname);
    _stencil_bits = o.cfg_extr<valid_stencil_bits>(
      "application.video.0.stencil_bits", _stencil_bits, instname);

    _prefer_gles =
      o.cfg_init("application.opengl.prefer_es", _prefer_gles, instname);
    _gl_debug_context = o.cfg_init(
      "application.opengl.debug_context", _gl_debug_context, instname);
    _gl_compat_context = o.cfg_init(
      "application.opengl.compatibility", _gl_compat_context, instname);

    _fullscreen = o.cfg_init("application.video.fullscreen", false, instname);
    _offscreen = o.cfg_init("application.video.offscreen", false, instname);

    _offscreen_framebuffer =
      o.cfg_init("application.video.offscreen_frambuffer", false, instname);

    _framedump_prefix =
      o.cfg_init("application.video.framedump.prefix", std::string(), instname);
    _framedump_color = o.cfg_init(
      "application.video.framedump.color", _framedump_color, instname);
    _framedump_depth = o.cfg_init(
      "application.video.framedump.depth", _framedump_depth, instname);
    _framedump_stencil = o.cfg_init(
      "application.video.framedump.stencil", _framedump_stencil, instname);
}
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
