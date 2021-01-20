/**
 *  @file eagine/application/opengl_eglplus.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/application/context.hpp>
#include <eagine/extract.hpp>
#include <eagine/integer_range.hpp>
#include <eagine/logging/type/yes_no_maybe.hpp>
#include <eagine/maybe_unused.hpp>
#include <eagine/valid_if/decl.hpp>
#include <oglplus/config/basic.hpp>

#include <eglplus/egl.hpp>
#include <eglplus/egl_api.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// surface
//------------------------------------------------------------------------------
class eglplus_opengl_surface
  : public main_ctx_object
  , public video_provider {
public:
    eglplus_opengl_surface(main_ctx_parent parent, eglp::egl_api& egl)
      : main_ctx_object{EAGINE_ID(EGLPbuffer), parent}
      , _egl_api{egl} {}

    auto get_context_attribs(
      execution_context&,
      bool gl_or_gles,
      const launch_options&,
      const video_options&) const -> std::vector<eglp::egl_types::int_type>;

    auto initialize(
      execution_context&,
      eglp::display_handle,
      eglp::egl_types::config_type,
      const launch_options&,
      const video_options&) -> bool;

    auto initialize(
      execution_context&,
      eglp::display_handle,
      valid_if_nonnegative<span_size_t> device_idx,
      const launch_options&,
      const video_options&) -> bool;

    auto initialize(
      execution_context&,
      string_view name,
      const launch_options&,
      const video_options&) -> bool;

    void cleanup();

    auto video_kind() const noexcept -> video_context_kind final;
    auto instance_name() const noexcept -> string_view final;

    auto is_offscreen() noexcept -> tribool final;
    auto has_framebuffer() noexcept -> tribool final;
    auto surface_size() noexcept -> std::tuple<int, int> final;
    auto surface_aspect() noexcept -> float final;

    void video_begin(execution_context&) final;
    void video_end(execution_context&) final;
    void video_commit(execution_context&) final;

private:
    eglp::egl_api& _egl_api;
    string_view _instance_name;
    eglp::display_handle _display{};
    eglp::surface_handle _surface{};
    eglp::context_handle _context{};

    int _width{1};
    int _height{1};
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::get_context_attribs(
  execution_context&,
  bool gl_or_gles,
  const launch_options&,
  const video_options& video_opts) const
  -> std::vector<eglp::egl_types::int_type> {
    const auto& [egl, EGL] = _egl_api;

    if(gl_or_gles) {
        if(video_opts.gl_compatibility_context()) {
            return ((EGL.context_major_version |
                     (video_opts.gl_version_major() / 3)) +
                    (EGL.context_minor_version |
                     (video_opts.gl_version_minor() / 0)) +
                    (EGL.context_opengl_profile_mask |
                     EGL.context_opengl_compatibility_profile_bit))
              .copy();
        } else {
            return ((EGL.context_major_version |
                     (video_opts.gl_version_major() / 3)) +
                    (EGL.context_minor_version |
                     (video_opts.gl_version_minor() / 3)) +
                    (EGL.context_opengl_profile_mask |
                     EGL.context_opengl_core_profile_bit))
              .copy();
        }
    } else {
        return ((EGL.context_major_version |
                 (video_opts.gl_version_major() / 3)) +
                (EGL.context_minor_version |
                 (video_opts.gl_version_minor() / 0)))
          .copy();
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::initialize(
  execution_context& exec_ctx,
  eglp::display_handle display,
  eglp::egl_types::config_type config,
  const launch_options& opts,
  const video_options& video_opts) -> bool {
    const auto& [egl, EGL] = _egl_api;

    const auto apis{egl.get_client_api_bits(display)};
    const bool has_gl = apis.has(EGL.opengl_bit);
    const bool has_gles = apis.has(EGL.opengl_es_bit);

    if(!has_gl && !has_gles) {
        log_info("display does not support any OpenAPI APIs;skipping");
        return false;
    }

    log_info("display device supports GL APIs")
      .arg(EAGINE_ID(OpenGL), yes_no_maybe(has_gl))
      .arg(EAGINE_ID(OpenGL_ES), yes_no_maybe(has_gles))
      .arg(EAGINE_ID(PreferES), yes_no_maybe(video_opts.prefer_gles()));

    const bool gl_or_gles = has_gl && !video_opts.prefer_gles();

    _width = video_opts.surface_width() / 1;
    _height = video_opts.surface_height() / 1;

    const auto surface_attribs = (EGL.width | _width) + (EGL.height | _height);
    if(ok surface{
         egl.create_pbuffer_surface(display, config, surface_attribs)}) {
        _surface = surface;

        const auto gl_api = gl_or_gles ? eglp::client_api(EGL.opengl_api)
                                       : eglp::client_api(EGL.opengl_es_api);

        if(ok bound{egl.bind_api(gl_api)}) {
            const auto context_attribs =
              get_context_attribs(exec_ctx, gl_or_gles, opts, video_opts);

            if(ok ctxt{egl.create_context(
                 display,
                 config,
                 eglp::context_handle{},
                 view(context_attribs))}) {
                _context = ctxt;
                return true;
            } else {
                log_error("failed to create context")
                  .arg(EAGINE_ID(message), (!ctxt).message());
            }
        } else {
            log_error("failed to bind OpenGL API")
              .arg(EAGINE_ID(message), (!bound).message());
        }
    } else {
        log_error("failed to create pbuffer ${width}x${height}")
          .arg(EAGINE_ID(width), _width)
          .arg(EAGINE_ID(height), _height)
          .arg(EAGINE_ID(message), (!surface).message());
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::initialize(
  execution_context& exec_ctx,
  eglp::display_handle display,
  valid_if_nonnegative<span_size_t> device_idx,
  const launch_options& opts,
  const video_options& video_opts) -> bool {
    const auto& [egl, EGL] = _egl_api;

    if(device_idx) {
        log_info("trying EGL device ${index}")
          .arg(EAGINE_ID(index), extract(device_idx));
    } else {
        exec_ctx.log_info("trying default EGL display device");
    }

    if(ok initialized{egl.initialize(display)}) {
        if(auto conf_driver_name{video_opts.driver_name()}) {
            if(egl.MESA_query_driver(display)) {
                if(ok driver_name{egl.get_display_driver_name(display)}) {
                    if(are_equal(
                         extract(video_opts.driver_name()),
                         extract(driver_name))) {
                        log_info("using the ${driver} MESA display driver")
                          .arg(
                            EAGINE_ID(driver),
                            EAGINE_ID(Identifier),
                            extract(driver_name));
                    } else {
                        log_info(
                          "${current} does not match the configured "
                          "${config} display driver; skipping")
                          .arg(
                            EAGINE_ID(current),
                            EAGINE_ID(Identifier),
                            extract(driver_name))
                          .arg(
                            EAGINE_ID(config),
                            EAGINE_ID(Identifier),
                            extract(conf_driver_name));
                        return false;
                    }
                } else {
                    log_error("failed to get EGL display driver name");
                    return false;
                }
            } else {
                log_info(
                  "cannot determine current display driver to match "
                  "with configured ${config} driver; skipping")
                  .arg(
                    EAGINE_ID(config),
                    EAGINE_ID(Identifier),
                    extract(conf_driver_name));
                return false;
            }
        } else {
            if(egl.MESA_query_driver(display)) {
                if(ok driver_name{egl.get_display_driver_name(display)}) {
                    log_info("using the ${driver} MESA display driver")
                      .arg(
                        EAGINE_ID(driver),
                        EAGINE_ID(Identifier),
                        extract(driver_name));
                }
            }
        }

        _display = display;

        const auto config_attribs =
          (EGL.red_size | (video_opts.color_bits() / EGL.dont_care)) +
          (EGL.green_size | (video_opts.color_bits() / EGL.dont_care)) +
          (EGL.blue_size | (video_opts.color_bits() / EGL.dont_care)) +
          (EGL.alpha_size | (video_opts.alpha_bits() / EGL.dont_care)) +
          (EGL.depth_size | (video_opts.depth_bits() / EGL.dont_care)) +
          (EGL.stencil_size | (video_opts.stencil_bits() / EGL.dont_care)) +
          (EGL.color_buffer_type | EGL.rgb_buffer) +
          (EGL.surface_type | EGL.pbuffer_bit) +
          (EGL.renderable_type | (EGL.opengl_bit | EGL.opengl_es3_bit));

        if(ok count{egl.choose_config.count(_display, config_attribs)}) {
            log_info("found ${count} suitable framebuffer configurations")
              .arg(EAGINE_ID(count), extract(count));

            if(ok config{egl.choose_config(_display, config_attribs)}) {
                return initialize(exec_ctx, _display, config, opts, video_opts);
            } else {
                const string_view dont_care{"-"};
                log_error("no matching framebuffer configuration found")
                  .arg(
                    EAGINE_ID(color),
                    EAGINE_ID(integer),
                    video_opts.color_bits(),
                    dont_care)
                  .arg(
                    EAGINE_ID(alpha),
                    EAGINE_ID(integer),
                    video_opts.alpha_bits(),
                    dont_care)
                  .arg(
                    EAGINE_ID(depth),
                    EAGINE_ID(integer),
                    video_opts.depth_bits(),
                    dont_care)
                  .arg(
                    EAGINE_ID(stencil),
                    EAGINE_ID(integer),
                    video_opts.stencil_bits(),
                    dont_care)
                  .arg(EAGINE_ID(message), (!config).message());
            }
        } else {
            log_error("failed to query framebuffer configurations")
              .arg(EAGINE_ID(message), (!count).message());
        }
    } else {
        exec_ctx.log_error("failed to initialize EGL display")
          .arg(EAGINE_ID(message), (!initialized).message());
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::initialize(
  execution_context& exec_ctx,
  string_view name,
  const launch_options& opts,
  const video_options& video_opts) -> bool {
    _instance_name = name;
    const auto& [egl, EGL] = _egl_api;

    const auto device_kind = video_opts.device_kind();
    const auto device_path = video_opts.device_path();
    const auto device_idx = video_opts.device_index();
    const bool select_device =
      device_kind.is_valid() || device_path.is_valid() ||
      device_idx.is_valid() || video_opts.driver_name().is_valid();

    if(select_device && egl.EXT_device_enumeration) {
        if(ok dev_count{egl.query_devices.count()}) {
            const auto n = std_size(extract(dev_count));
            std::vector<eglp::egl_types::device_type> devices;
            devices.resize(n);
            if(egl.query_devices(cover(devices))) {
                for(auto cur_dev_idx : integer_range(n)) {
                    bool matching_device = true;
                    auto device = eglp::device_handle(devices[cur_dev_idx]);

                    if(device_idx) {
                        if(std_size(extract(device_idx)) == cur_dev_idx) {
                            log_info("explicitly selected device ${index}")
                              .arg(EAGINE_ID(index), extract(device_idx));
                        } else {
                            matching_device = false;
                            log_info(
                              "current device index is ${current} but, "
                              "device ${config} requested; skipping")
                              .arg(EAGINE_ID(current), cur_dev_idx)
                              .arg(EAGINE_ID(config), extract(device_idx));
                        }
                    }

                    if(device_kind) {
                        if(extract(device_kind) == video_device_kind::hardware) {
                            if(!egl.MESA_device_software(device)) {
                                log_info(
                                  "device ${index} seems to be hardware as "
                                  "explicitly specified by configuration")
                                  .arg(EAGINE_ID(index), cur_dev_idx);
                            } else {
                                matching_device = false;
                                log_info(
                                  "device ${index} is software but, "
                                  "hardware device requested; skipping")
                                  .arg(EAGINE_ID(index), cur_dev_idx);
                            }
                        } else if(
                          extract(device_kind) == video_device_kind::software) {
                            if(!egl.EXT_device_drm(device)) {
                                log_info(
                                  "device ${index} seems to be software as "
                                  "explicitly specified by configuration")
                                  .arg(EAGINE_ID(index), cur_dev_idx);
                            } else {
                                matching_device = false;
                                log_info(
                                  "device ${index} is hardware but, "
                                  "software device requested; skipping")
                                  .arg(EAGINE_ID(index), cur_dev_idx);
                            }
                        }
                    }

                    if(device_path) {
                        if(egl.EXT_device_drm(device)) {
                            if(ok path{egl.query_device_string(
                                 device, EGL.drm_device_file)}) {
                                if(are_equal(
                                     extract(device_path), extract(path))) {
                                    log_info(
                                      "using DRM device ${path} as "
                                      "explicitly specified by configuration")
                                      .arg(
                                        EAGINE_ID(path),
                                        EAGINE_ID(FsPath),
                                        extract(path));
                                } else {
                                    matching_device = false;
                                    log_info(
                                      "device file is ${current}, but "
                                      "${config} was requested; skipping")
                                      .arg(
                                        EAGINE_ID(current),
                                        EAGINE_ID(FsPath),
                                        extract(path))
                                      .arg(
                                        EAGINE_ID(config),
                                        EAGINE_ID(FsPath),
                                        extract(device_path));
                                }
                            }
                        } else {
                            log_warning(
                              "${config} requested by config, but cannot "
                              "determine current device file path")
                              .arg(
                                EAGINE_ID(config),
                                EAGINE_ID(FsPath),
                                extract(device_path));
                        }
                    }

                    if(matching_device) {
                        if(ok display{egl.get_platform_display(device)}) {

                            if(initialize(
                                 exec_ctx,
                                 display,
                                 cur_dev_idx,
                                 opts,
                                 video_opts)) {
                                return true;
                            } else {
                                _egl_api.terminate(display);
                            }
                        }
                    }
                }
            }
        }
    } else {
        if(ok display{egl.get_display()}) {
            return initialize(exec_ctx, display, -1, opts, video_opts);
        } else {
            exec_ctx.log_error("failed to get EGL display")
              .arg(EAGINE_ID(message), (!display).message());
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::cleanup() {
    if(_display) {
        if(_context) {
            _egl_api.destroy_context(_display, _context);
        }
        if(_surface) {
            _egl_api.destroy_surface(_display, _surface);
        }
        _egl_api.terminate(_display);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::video_kind() const noexcept -> video_context_kind {
    return video_context_kind::opengl;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::instance_name() const noexcept -> string_view {
    return _instance_name;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::is_offscreen() noexcept -> tribool {
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::has_framebuffer() noexcept -> tribool {
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::surface_size() noexcept -> std::tuple<int, int> {
    return {_width, _height};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::surface_aspect() noexcept -> float {
    return float(_width) / float(_height);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::video_begin(execution_context&) {
    _egl_api.make_current(_display, _surface, _context);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::video_end(execution_context&) {
    _egl_api.make_current.none(_display);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::video_commit(execution_context&) {
    _egl_api.swap_buffers(_display, _surface);
}
//------------------------------------------------------------------------------
// provider
//------------------------------------------------------------------------------
class eglplus_opengl_provider
  : public main_ctx_object
  , public hmi_provider {
public:
    eglplus_opengl_provider(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(EGLPPrvdr), parent} {}

    auto is_implemented() const noexcept -> bool final;
    auto implementation_name() const noexcept -> string_view final;

    auto is_initialized() -> bool final;
    auto should_initialize(execution_context&) -> bool final;
    auto initialize(execution_context&) -> bool final;
    void update(execution_context&) final;
    void cleanup(execution_context&) final;

    auto input() -> std::shared_ptr<input_provider> final;
    auto video(string_view) -> std::shared_ptr<video_provider> final;
    auto audio(string_view) -> std::shared_ptr<audio_provider> final;

private:
    eglp::egl_api _egl_api;

    std::map<
      std::string,
      std::shared_ptr<eglplus_opengl_surface>,
      basic_str_view_less<std::string, string_view>>
      _surfaces;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::is_implemented() const noexcept -> bool {
    return _egl_api.get_display && _egl_api.initialize && _egl_api.terminate &&
           _egl_api.get_configs && _egl_api.choose_config &&
           _egl_api.get_config_attrib && _egl_api.query_string &&
           _egl_api.swap_buffers;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::implementation_name() const noexcept
  -> string_view {
    return {"eglplus"};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::is_initialized() -> bool {
    return !_surfaces.empty();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::should_initialize(execution_context& exec_ctx)
  -> bool {
    for(auto& [name, video_opts] : exec_ctx.options().video_requirements()) {
        EAGINE_MAYBE_UNUSED(name);
        if(video_opts.has_provider(implementation_name())) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::initialize(execution_context& exec_ctx) -> bool {
    if(_egl_api.get_display) {
        auto& options = exec_ctx.options();
        for(auto& [name, video_opts] : options.video_requirements()) {
            const bool should_create_surface =
              video_opts.has_provider(implementation_name()) &&
              (video_opts.video_kind() == video_context_kind::opengl);

            if(should_create_surface) {
                if(auto surface{std::make_shared<eglplus_opengl_surface>(
                     *this, _egl_api)}) {
                    if(extract(surface).initialize(
                         exec_ctx, name, options, video_opts)) {
                        _surfaces[name] = std::move(surface);
                    } else {
                        extract(surface).cleanup();
                    }
                }
            }
        }
        return true;
    }
    exec_ctx.log_error("EGL is context is not supported");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_provider::update(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_provider::cleanup(execution_context&) {
    for(auto& entry : _surfaces) {
        entry.second->cleanup();
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::input() -> std::shared_ptr<input_provider> {
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::video(string_view name)
  -> std::shared_ptr<video_provider> {
    auto pos = _surfaces.find(name);
    if(pos != _surfaces.end()) {
        return {pos->second};
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::audio(string_view)
  -> std::shared_ptr<audio_provider> {
    return {};
}
//------------------------------------------------------------------------------
auto make_eglplus_opengl_provider(main_ctx_parent parent)
  -> std::shared_ptr<hmi_provider> {
    return {std::make_shared<eglplus_opengl_provider>(parent)};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
