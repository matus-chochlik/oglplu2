/**
 *  @file eagine/application/options.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::application {
//------------------------------------------------------------------------------
// video_options
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
video_options::video_options(
  main_ctx_object& o,
  string_view instance,
  video_context_kind kind)
  : _video_kind{kind} {

    _surface_width = o.cfg_extr<valid_surface_size>(
      "application.video.surface.width", _surface_width, instance);
    _surface_height = o.cfg_extr<valid_surface_size>(
      "application.video.surface.height", _surface_height, instance);
    _samples = o.cfg_extr<valid_samples>(
      "application.video.samples", _samples, instance);
    _color_bits = o.cfg_extr<valid_color_bits>(
      "application.video.color_bits", _color_bits, instance);
    _alpha_bits = o.cfg_extr<valid_alpha_bits>(
      "application.video.alpha_bits", _alpha_bits, instance);
    _depth_bits = o.cfg_extr<valid_depth_bits>(
      "application.video.depth_bits", _depth_bits, instance);
    _stencil_bits = o.cfg_extr<valid_stencil_bits>(
      "application.video.0.stencil_bits", _stencil_bits, instance);
    _offscreen = o.cfg_init("application.video.offscreen", false, instance);
    _fullscreen = o.cfg_init("application.video.fullscreen", false, instance);
    _gl_debug_context = o.cfg_init(
      "application.video.opengl.debug_context", _gl_debug_context, instance);
    _gl_compat_context = o.cfg_init(
      "application.video.opengl.compatibility", _gl_compat_context, instance);
}
//------------------------------------------------------------------------------
// launch_options
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
launch_options::launch_options(main_ctx_parent parent) noexcept
  : main_ctx_object(EAGINE_ID(LaunchOpts), parent) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto launch_options::require_video(video_context_kind kind, string_view instance)
  -> video_options& {
    auto pos = _video_opts.find(instance);
    if(pos == _video_opts.end()) {
        pos = _video_opts
                .try_emplace(
                  to_string(instance), video_options(*this, instance, kind))
                .first;
    }
    return pos->second;
}
//------------------------------------------------------------------------------
} // namespace eagine::application
