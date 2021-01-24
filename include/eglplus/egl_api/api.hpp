/**
 *  @file eglplus/egl_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_API_HPP
#define EGLPLUS_EGL_API_API_HPP

#include "c_api.hpp"
#include "config_attribs.hpp"
#include "context_attribs.hpp"
#include "enum_types.hpp"
#include "extensions.hpp"
#include "image_attribs.hpp"
#include "objects.hpp"
#include "output_layer_attribs.hpp"
#include "output_port_attribs.hpp"
#include "platform_attribs.hpp"
#include "stream_attribs.hpp"
#include "surface_attribs.hpp"
#include "sync_attribs.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>
#include <chrono>

namespace eagine::eglp {
//------------------------------------------------------------------------------
#define EGLPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_egl_operations : public basic_egl_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_egl_c_api<ApiTraits>;

    using void_ptr_type = typename egl_types::void_ptr_type;
    using int_type = typename egl_types::int_type;
    using bool_type = typename egl_types::char_type;
    using char_type = typename egl_types::char_type;
    using enum_type = typename egl_types::enum_type;
    using attrib_type = typename egl_types::attrib_type;
    using device_type = typename egl_types::device_type;
    using native_display_type = typename egl_types::native_display_type;
    using native_window_type = typename egl_types::native_window_type;
    using native_pixmap_type = typename egl_types::native_pixmap_type;
    using client_buffer_type = typename egl_types::client_buffer_type;
    using config_type = typename egl_types::config_type;

    // extensions
    template <typename... Args>
    using extension = basic_egl_extension<ApiTraits, Args...>;

    extension<> EXT_device_base;
    extension<> EXT_device_enumeration;
    extension<> EXT_device_query;
    extension<> EXT_device_query_name;
    extension<device_handle> EXT_device_drm;
    extension<device_handle> MESA_device_software;

    extension<> EXT_platform_base;
    extension<> EXT_platform_device;
    extension<> EXT_platform_x11;
    extension<> EXT_platform_xcb;
    extension<> EXT_platform_wayland;
    extension<> KHR_platform_gbm;
    extension<> MESA_platform_surfaceless;

    extension<display_handle> EXT_create_context_robustness;
    extension<display_handle> EXT_swap_buffers_with_damage;

    extension<display_handle> EXT_output_base;
    extension<display_handle> EXT_output_drm;
    extension<display_handle> EXT_stream_consumer_egloutput;

    extension<display_handle> EXT_pixel_format_float;

    extension<display_handle> MESA_configless_context;
    extension<display_handle> MESA_query_driver;

    // functions
    template <typename W, W c_api::*F, typename Signature = typename W::signature>
    class func;

    template <typename W, W c_api::*F, typename RVC, typename... Params>
    class func<W, F, RVC(Params...)>
      : public wrapped_c_api_function<c_api, api_traits, nothing_t, W, F> {
        using base = wrapped_c_api_function<c_api, api_traits, nothing_t, W, F>;

    private:
        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }

    protected:
        template <typename... Args>
        constexpr auto _chkcall(Args&&... args) const noexcept {
            return this->_check(this->_call(std::forward<Args>(args)...));
        }

        using base::_conv;

        template <typename... Args>
        constexpr auto _cnvchkcall(Args&&... args) const noexcept {
            return this->_chkcall(_conv(args)...).cast_to(type_identity<RVC>{});
        }

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...)
              .cast_to(type_identity<RVC>{});
        }
    };

    // numeric query function
    template <
      typename PreTypeList,
      typename QueryClassList,
      typename PostTypeList,
      typename QueryResult,
      typename W,
      W c_api::*F>
    struct query_func;

    template <
      typename... PreParams,
      typename... QueryClasses,
      typename... PostParams,
      typename QueryResult,
      typename W,
      W c_api::*F>
    struct query_func<
      mp_list<PreParams...>,
      mp_list<QueryClasses...>,
      mp_list<PostParams...>,
      QueryResult,
      W,
      F> : func<W, F> {
        using func<W, F>::func;

        template <
          typename Query,
          typename = std::enable_if_t<
            (true || ... || is_enum_class_value_v<QueryClasses, Query>)>,
          typename = std::enable_if_t<!std::is_array_v<typename Query::tag_type>>>
        constexpr auto operator()(
          PreParams... pre_params,
          Query query,
          PostParams... post_params) const noexcept {
            using RV = typename Query::tag_type;
            QueryResult result{};
            return this
              ->_cnvchkcall(
                pre_params..., int_type(query), post_params..., &result)
              .replaced_with(result)
              .cast_to(type_identity<RV>{});
        }

        template <
          typename Query,
          typename = std::enable_if_t<
            (true || ... || is_enum_class_value_v<QueryClasses, Query>)>>
        auto operator()(
          PreParams... pre_params,
          Query query,
          PostParams... post_params,
          span<QueryResult> dest) const noexcept {
            EAGINE_ASSERT(dest.size());
            return this->_cnvchkcall(
              pre_params..., int_type(query), post_params..., dest.data());
        }
    };

    // query_devices
    struct : func<EGLPAFP(QueryDevices)> {
        using func<EGLPAFP(QueryDevices)>::func;

        auto count() const noexcept {
            int_type ret_count{0};
            return this->_cnvchkcall(0, nullptr, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        auto operator()(span<device_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_cnvchkcall(
                limit_cast<int_type>(dest.size()), dest.data(), &ret_count)
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }
    } query_devices;

    // query_device_string
    struct : func<EGLPAFP(QueryDeviceString)> {
        using func<EGLPAFP(QueryDeviceString)>::func;

        constexpr auto
        operator()(device_type dev, device_string_query query) const noexcept {
            return this->_cnvchkcall(dev, query)
              .cast_to(type_identity<string_view>{});
        }

        constexpr auto operator()(device_handle dev, device_string_query query)
          const noexcept {
            return (*this)(device_type(dev), query);
        }

        constexpr auto operator()() const noexcept {
            return this->_fake_empty_c_str().cast_to(
              type_identity<string_view>{});
        }
    } query_device_string;

    // get_device_extensions
    auto get_device_extensions(device_type dev) const noexcept {
#ifdef EGL_EXTENSIONS
        return query_device_string(dev, device_string_query(EGL_EXTENSIONS))
          .transformed(
            [](auto src) { return split_into_string_list(src, ' '); });
#else
        return this->_fake_empty_c_str();
#endif
    }

    auto get_device_extensions(device_handle dev) const noexcept {
        return get_device_extensions(device_type(dev));
    }

    // get_platform_display
    struct : func<EGLPAFP(GetPlatformDisplay)> {
        using func<EGLPAFP(GetPlatformDisplay)>::func;

        constexpr auto operator()(device_handle dev) const noexcept {
#ifdef EGL_PLATFORM_DEVICE_EXT
            return this->_cnvchkcall(EGL_PLATFORM_DEVICE_EXT, dev, nullptr)
              .cast_to(type_identity<display_handle>{});
#else
            EAGINE_MAYBE_UNUSED(dev);
            return this->_fake({}).cast_to(type_identity<display_handle>{});
#endif
        }

        constexpr auto
        operator()(platform pltf, void_ptr_type disp) const noexcept {
            return this->_cnvchkcall(pltf, disp, nullptr)
              .cast_to(type_identity<display_handle>{});
        }

        constexpr auto operator()(
          platform pltf,
          void_ptr_type disp,
          span<const attrib_type> attribs) const noexcept {
            return this->_cnvchkcall(pltf, disp, attribs.data())
              .cast_to(type_identity<display_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          platform pltf,
          void_ptr_type disp,
          const platform_attributes<N>& attribs) const noexcept {
            return (*this)(pltf, disp, attribs.get());
        }
    } get_platform_display;

    // get_display
    struct : func<EGLPAFP(GetDisplay)> {
        using func<EGLPAFP(GetDisplay)>::func;

        constexpr auto operator()(native_display_type disp) const noexcept {
            return this->_cnvchkcall(disp).cast_to(
              type_identity<display_handle>{});
        }

        constexpr auto operator()() const noexcept {
#ifdef EGL_DEFAULT_DISPLAY
            return this->_cnvchkcall(EGL_DEFAULT_DISPLAY)
              .cast_to(type_identity<display_handle>{});
#else
            return this->_fake({}).cast_to(type_identity<display_handle>{});
#endif
        }
    } get_display;

    // get_display_driver_name
    struct : func<EGLPAFP(GetDisplayDriverName)> {
        using func<EGLPAFP(GetDisplayDriverName)>::func;

        constexpr auto operator()(display_handle disp) const noexcept {
            return this->_cnvchkcall(disp).cast_to(
              type_identity<string_view>{});
        }
    } get_display_driver_name;

    // initialize
    struct : func<EGLPAFP(Initialize)> {
        using base = func<EGLPAFP(Initialize)>;
        using base::base;
        using base::operator();

        constexpr auto
        operator()(display_handle disp, int* maj, int* min) const noexcept {
            return this->_cnvchkcall(disp, maj, min)
              .transformed(
                [&maj, &min](auto) { return std::make_tuple(maj, min); });
        }

        constexpr auto operator()(display_handle disp) const noexcept {
            int_type maj{-1};
            int_type min{-1};
            return (*this)(disp, &maj, &min);
        }
    } initialize;

    // terminate
    struct : func<EGLPAFP(Terminate)> {
        using func<EGLPAFP(Terminate)>::func;

        constexpr auto operator()(display_handle disp) const noexcept {
            return this->_cnvchkcall(disp);
        }

        auto raii(display_handle disp) noexcept {
            return eagine::finally([=]() { (*this)(disp); });
        }
    } terminate;

    // get_configs
    struct : func<EGLPAFP(GetConfigs)> {
        using func<EGLPAFP(GetConfigs)>::func;

        auto count(display_handle disp) const noexcept {
            int_type ret_count{0};
            return this->_cnvchkcall(disp, nullptr, 0, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        auto
        operator()(display_handle disp, span<config_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_cnvchkcall(
                disp, dest.data(), limit_cast<int_type>(dest.size()), &ret_count)
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }
    } get_configs;

    // choose_config
    struct : func<EGLPAFP(ChooseConfig)> {
        using func<EGLPAFP(ChooseConfig)>::func;

        auto count(display_handle disp, span<const int_type> attribs)
          const noexcept {
            int_type ret_count{0};
            return this
              ->_cnvchkcall(disp, attribs.data(), nullptr, 0, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        template <std::size_t N>
        auto
        count(display_handle disp, const config_attributes<N>& attribs) const {
            return count(disp, attribs.get());
        }

        auto count(display_handle disp, const config_attribute_value& attribs)
          const {
            return count(disp, config_attributes<2>{attribs});
        }

        auto operator()(
          display_handle disp,
          span<const int_type> attribs,
          span<config_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_cnvchkcall(
                disp,
                attribs.data(),
                dest.data(),
                limit_cast<int_type>(dest.size()),
                &ret_count)
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }

        template <std::size_t N>
        auto operator()(
          display_handle disp,
          const config_attributes<N>& attribs,
          span<config_type> dest) const noexcept {
            return (*this)(disp, attribs.get(), dest);
        }

        template <std::size_t N>
        auto operator()(
          display_handle disp,
          const config_attributes<N>& attribs) const noexcept {
            config_type result;
            return (*this)(disp, attribs.get(), cover_one(&result))
              .replaced_with(result);
        }

        auto operator()(
          display_handle disp,
          const config_attribute_value& attribs,
          span<config_type> dest) const noexcept {
            return (*this)(disp, config_attributes<2>{attribs}, dest);
        }

        auto operator()(
          display_handle disp,
          const config_attribute_value& attribs) const noexcept {
            return (*this)(disp, config_attributes<2>{attribs});
        }
    } choose_config;

    // get_config_attrib
    query_func<
      mp_list<display_handle, config_type>,
      mp_list<config_attribute>,
      mp_list<>,
      int_type,
      EGLPAFP(GetConfigAttrib)>
      get_config_attrib;

    // create_window_surface
    struct : func<EGLPAFP(CreateWindowSurface)> {
        using func<EGLPAFP(CreateWindowSurface)>::func;

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          native_window_type win) const noexcept {
            return this->_cnvchkcall(disp, conf, win, nullptr)
              .cast_to(type_identity<surface_handle>{});
        }

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          native_window_type win,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, conf, win, attribs.data())
              .cast_to(type_identity<surface_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          native_window_type win,
          const surface_attributes<N> attribs) const noexcept {
            return (*this)(disp, conf, win, attribs.get());
        }
    } create_window_surface;

    // create_pbuffer_surface
    struct : func<EGLPAFP(CreatePbufferSurface)> {
        using func<EGLPAFP(CreatePbufferSurface)>::func;

        constexpr auto
        operator()(display_handle disp, config_type conf) const noexcept {
            return this->_cnvchkcall(disp, conf, nullptr)
              .cast_to(type_identity<surface_handle>{});
        }

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, conf, attribs.data())
              .cast_to(type_identity<surface_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          const surface_attributes<N> attribs) const noexcept {
            return (*this)(disp, conf, attribs.get());
        }
    } create_pbuffer_surface;

    // create_pixmap_surface
    struct : func<EGLPAFP(CreatePixmapSurface)> {
        using func<EGLPAFP(CreatePixmapSurface)>::func;

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          native_pixmap_type pmp) const noexcept {
            return this->_cnvchkcall(disp, conf, pmp, nullptr)
              .cast_to(type_identity<surface_handle>{});
        }

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          native_pixmap_type pmp,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, conf, pmp, attribs.data())
              .cast_to(type_identity<surface_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          native_pixmap_type pmp,
          const surface_attributes<N> attribs) const noexcept {
            return (*this)(disp, conf, pmp, attribs.get());
        }
    } create_pixmap_surface;

    // destroy_surface
    struct : func<EGLPAFP(DestroySurface)> {
        using func<EGLPAFP(DestroySurface)>::func;

        constexpr auto
        operator()(display_handle disp, surface_handle surf) const noexcept {
            return this->_cnvchkcall(disp, surf);
        }

        auto raii(display_handle disp, surface_handle surf) noexcept {
            return eagine::finally([=]() { (*this)(disp, surf); });
        }
    } destroy_surface;

    // get_current_surface
    struct : func<EGLPAFP(GetCurrentSurface)> {
        using func<EGLPAFP(GetCurrentSurface)>::func;

        constexpr auto operator()(read_draw which) const noexcept {
            return this->_cnvchkcall(which);
        }
    } get_current_surface;

    // surface_attrib
    struct : func<EGLPAFP(SurfaceAttrib)> {
        using func<EGLPAFP(SurfaceAttrib)>::func;

        constexpr auto operator()(
          display_handle disp,
          surface_handle surf,
          surface_attribute attr,
          int_type value) const noexcept {
            return this->_cnvchkcall(disp, surf, attr, value);
        }
    } surface_attrib;

    // query_surface
    query_func<
      mp_list<display_handle, surface_handle>,
      mp_list<surface_attribute>,
      mp_list<>,
      int_type,
      EGLPAFP(QuerySurface)>
      query_surface;

    // create_stream
    struct : func<EGLPAFP(CreateStream)> {
        using func<EGLPAFP(CreateStream)>::func;

        constexpr auto operator()(display_handle disp) const noexcept {
            return this->_cnvchkcall(disp, nullptr)
              .cast_to(type_identity<stream_handle>{});
        }

        constexpr auto operator()(
          display_handle disp,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, attribs.data())
              .cast_to(type_identity<stream_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          const stream_attributes<N> attribs) const noexcept {
            return (*this)(disp, attribs.get());
        }
    } create_stream;

    // destroy_stream
    struct : func<EGLPAFP(DestroyStream)> {
        using func<EGLPAFP(DestroyStream)>::func;

        constexpr auto
        operator()(display_handle disp, stream_handle surf) const noexcept {
            return this->_cnvchkcall(disp, surf);
        }

        auto raii(display_handle disp, stream_handle surf) noexcept {
            return eagine::finally([=]() { (*this)(disp, surf); });
        }
    } destroy_stream;

    // stream_attrib
    struct : func<EGLPAFP(StreamAttrib)> {
        using func<EGLPAFP(StreamAttrib)>::func;

        constexpr auto operator()(
          display_handle disp,
          stream_handle surf,
          stream_attribute attr,
          int_type value) const noexcept {
            return this->_cnvchkcall(disp, surf, attr, value);
        }
    } stream_attrib;

    // query_stream
    query_func<
      mp_list<display_handle, stream_handle>,
      mp_list<stream_attribute>,
      mp_list<>,
      int_type,
      EGLPAFP(QueryStream)>
      query_stream;

    // stream_consumer_gl_texture_external
    struct : func<EGLPAFP(StreamConsumerGLTextureExternal)> {
        using func<EGLPAFP(StreamConsumerGLTextureExternal)>::func;

        constexpr auto
        operator()(display_handle disp, stream_handle surf) const noexcept {
            return this->_cnvchkcall(disp, surf);
        }
    } stream_consumer_gl_texture_external;

    // stream_consumer_acquire
    struct : func<EGLPAFP(StreamConsumerAcquire)> {
        using func<EGLPAFP(StreamConsumerAcquire)>::func;

        constexpr auto
        operator()(display_handle disp, stream_handle surf) const noexcept {
            return this->_cnvchkcall(disp, surf);
        }
    } stream_consumer_acquire;

    // stream_consumer_release
    struct : func<EGLPAFP(StreamConsumerRelease)> {
        using func<EGLPAFP(StreamConsumerRelease)>::func;

        constexpr auto
        operator()(display_handle disp, stream_handle surf) const noexcept {
            return this->_cnvchkcall(disp, surf);
        }
    } stream_consumer_release;

    // get_output_layers
    struct : func<EGLPAFP(GetOutputLayers)> {
        using func<EGLPAFP(GetOutputLayers)>::func;

        auto count(display_handle disp) const noexcept {
            int_type ret_count{0};
            return this->_cnvchkcall(disp, nullptr, nullptr, 0, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        auto operator()(
          display_handle disp,
          span<attrib_type> attr,
          span<device_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_cnvchkcall(
                disp,
                attr.data(),
                dest.data(),
                limit_cast<int_type>(dest.size()),
                &ret_count)
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }

        template <std::size_t N>
        auto operator()(
          display_handle disp,
          output_layer_attributes<N> attr,
          span<device_type> dest) const noexcept {
            return (*this)(disp, attr.get(), dest);
        }
    } get_output_layers;

    // output_layer_attrib
    struct : func<EGLPAFP(OutputLayerAttrib)> {
        using func<EGLPAFP(OutputLayerAttrib)>::func;
        auto operator()(
          display_handle disp,
          output_layer_handle outl,
          output_layer_attribute_value attr) const noexcept {
            return this->_cnvchkcall(disp, outl, attr._key, attr._value);
        }
    } output_layer_attrib;

    // query_output_layer_attrib
    struct : func<EGLPAFP(QueryOutputLayerAttrib)> {
        using func<EGLPAFP(QueryOutputLayerAttrib)>::func;
        attrib_type result{0};
        auto operator()(
          display_handle disp,
          output_layer_handle outl,
          output_layer_attribute attr) const noexcept {
            using RV = attrib_type;
            return this->_cnvchkcall(disp, outl, attr, &result)
              .replaced_with(result)
              .cast_to(type_identity<RV>{});
        }
    } query_output_layer_attrib;

    // query_output_layer_string
    struct : func<EGLPAFP(QueryOutputLayerString)> {
        using func<EGLPAFP(QueryOutputLayerString)>::func;
        attrib_type result{0};
        auto operator()(
          display_handle disp,
          output_layer_handle outl,
          output_layer_string_query qury) const noexcept {
            return this->_cnvchkcall(disp, outl, qury)
              .cast_to(type_identity<string_view>{});
        }
    } query_output_layer_string;

    // get_output_ports
    struct : func<EGLPAFP(GetOutputPorts)> {
        using func<EGLPAFP(GetOutputPorts)>::func;

        auto count(display_handle disp) const noexcept {
            int_type ret_count{0};
            return this->_cnvchkcall(disp, nullptr, nullptr, 0, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        auto operator()(
          display_handle disp,
          span<attrib_type> attr,
          span<device_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_cnvchkcall(
                disp,
                attr.data(),
                dest.data(),
                limit_cast<int_type>(dest.size()),
                &ret_count)
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }

        template <std::size_t N>
        auto operator()(
          display_handle disp,
          output_port_attributes<N> attr,
          span<device_type> dest) const noexcept {
            return (*this)(disp, attr.get(), dest);
        }
    } get_output_ports;

    // output_port_attrib
    struct : func<EGLPAFP(OutputPortAttrib)> {
        using func<EGLPAFP(OutputPortAttrib)>::func;
        auto operator()(
          display_handle disp,
          output_port_handle outp,
          output_port_attribute_value attr) const noexcept {
            return this->_cnvchkcall(disp, outp, attr._key, attr._value);
        }
    } output_port_attrib;

    // query_output_port_attrib
    struct : func<EGLPAFP(QueryOutputPortAttrib)> {
        using func<EGLPAFP(QueryOutputPortAttrib)>::func;
        attrib_type result{0};
        auto operator()(
          display_handle disp,
          output_port_handle outp,
          output_port_attribute attr) const noexcept {
            using RV = attrib_type;
            return this->_cnvchkcall(disp, outp, attr, &result)
              .replaced_with(result)
              .cast_to(type_identity<RV>{});
        }
    } query_output_port_attrib;

    // query_output_port_string
    struct : func<EGLPAFP(QueryOutputPortString)> {
        using func<EGLPAFP(QueryOutputPortString)>::func;
        attrib_type result{0};
        auto operator()(
          display_handle disp,
          output_port_handle outl,
          output_port_string_query qury) const noexcept {
            return this->_cnvchkcall(disp, outl, qury)
              .cast_to(type_identity<string_view>{});
        }
    } query_output_port_string;

    // create_image
    struct : func<EGLPAFP(CreateImage)> {
        using func<EGLPAFP(CreateImage)>::func;

        constexpr auto operator()(
          display_handle disp,
          context_handle ctxt,
          image_target tgt,
          client_buffer_type buf,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, ctxt, tgt, buf, attribs.data())
              .cast_to(type_identity<image_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          context_handle ctxt,
          image_target tgt,
          client_buffer_type buf,
          const image_attributes<N> attribs) const noexcept {
            return (*this)(disp, ctxt, tgt, buf, attribs.get());
        }
    } create_image;

    // destroy_image
    struct : func<EGLPAFP(DestroyImage)> {
        using func<EGLPAFP(DestroyImage)>::func;

        constexpr auto
        operator()(display_handle disp, image_handle imge) const noexcept {
            return this->_cnvchkcall(disp, imge);
        }

        auto raii(display_handle disp, image_handle imge) noexcept {
            return eagine::finally([=]() { (*this)(disp, imge); });
        }
    } destroy_image;

    // bind_api
    struct : func<EGLPAFP(BindAPI)> {
        using func<EGLPAFP(BindAPI)>::func;

        constexpr auto operator()(client_api api) const noexcept {
            return this->_cnvchkcall(api);
        }
    } bind_api;

    // query_api
    struct : func<EGLPAFP(QueryAPI)> {
        using func<EGLPAFP(QueryAPI)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(type_identity<client_api>{});
        }
    } query_api;

    // create_context
    struct : func<EGLPAFP(CreateContext)> {
        using func<EGLPAFP(CreateContext)>::func;

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          context_handle share_ctxt,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, conf, share_ctxt, attribs.data())
              .cast_to(type_identity<context_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          const context_attributes<N> attribs) const noexcept {
            return (*this)(disp, conf, context_handle{}, attribs.get());
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          context_handle share_ctxt,
          const context_attributes<N> attribs) const noexcept {
            return (*this)(disp, conf, share_ctxt, attribs.get());
        }
    } create_context;

    // destroy_context
    struct : func<EGLPAFP(DestroyContext)> {
        using func<EGLPAFP(DestroyContext)>::func;

        constexpr auto
        operator()(display_handle disp, context_handle ctxt) const noexcept {
            return this->_cnvchkcall(disp, ctxt);
        }

        auto raii(display_handle disp, context_handle ctxt) noexcept {
            return eagine::finally([=]() { (*this)(disp, ctxt); });
        }
    } destroy_context;

    // make_current
    struct : func<EGLPAFP(MakeCurrent)> {
        using func<EGLPAFP(MakeCurrent)>::func;

        constexpr auto operator()(
          display_handle disp,
          surface_handle draw,
          surface_handle read,
          context_handle ctxt) const noexcept {
            return this->_cnvchkcall(disp, draw, read, ctxt);
        }

        constexpr auto operator()(
          display_handle disp,
          surface_handle surf,
          context_handle ctxt) const noexcept {
            return this->_cnvchkcall(disp, surf, surf, ctxt);
        }

        constexpr auto none(display_handle disp) const noexcept {
            return (*this)(disp, surface_handle{}, context_handle{});
        }
    } make_current;

    // get_current_context
    struct : func<EGLPAFP(GetCurrentContext)> {
        using func<EGLPAFP(GetCurrentContext)>::func;

        constexpr auto operator()() const noexcept {
            return this->_cnvchkcall().cast_to(type_identity<context_handle>{});
        }
    } get_current_context;

    // wait_client
    struct : func<EGLPAFP(WaitClient)> {
        using func<EGLPAFP(WaitClient)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall();
        }
    } wait_client;

    // wait_native
    struct : func<EGLPAFP(WaitNative)> {
        using func<EGLPAFP(WaitNative)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall();
        }
    } wait_native;

    // create_sync
    struct : func<EGLPAFP(CreateSync)> {
        using func<EGLPAFP(CreateSync)>::func;

        constexpr auto operator()(
          display_handle disp,
          sync_type type,
          span<const int_type> attribs) const noexcept {
            return this->_cnvchkcall(disp, type, attribs.data())
              .cast_to(type_identity<sync_handle>{});
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          sync_type type,
          const sync_attributes<N> attribs) const noexcept {
            return (*this)(disp, type, attribs.get());
        }
    } create_sync;

    // client_wait_sync
    struct : func<EGLPAFP(ClientWaitSync)> {
        using func<EGLPAFP(ClientWaitSync)>::func;

        template <typename R, typename P>
        constexpr auto operator()(
          display_handle disp,
          sync_handle sync,
          std::chrono::duration<R, P> timeout) const noexcept {
            return this->_cnvchkcall(
              disp, sync, 0, std::chrono::nanoseconds(timeout).count());
        }

        template <typename R, typename P>
        constexpr auto
        forever(display_handle disp, sync_handle sync) const noexcept {
#ifdef EGL_FOREVER
            return this->_cnvchkcall(disp, sync, 0, EGL_FOREVER);
#else
            return this->_fake({});
#endif
        }
    } client_wait_sync;

    // wait_sync
    struct : func<EGLPAFP(WaitSync)> {
        using func<EGLPAFP(WaitSync)>::func;

        constexpr auto
        operator()(display_handle disp, sync_handle sync) const noexcept {
            return this->_cnvchkcall(disp, sync, 0);
        }
    } wait_sync;

    // destroy_sync
    struct : func<EGLPAFP(DestroySync)> {
        using func<EGLPAFP(DestroySync)>::func;

        constexpr auto
        operator()(display_handle disp, sync_handle sync) const noexcept {
            return this->_cnvchkcall(disp, sync);
        }
    } destroy_sync;

    // query_string
    struct : func<EGLPAFP(QueryString)> {
        using func<EGLPAFP(QueryString)>::func;

        constexpr auto
        operator()(display_handle disp, string_query query) const noexcept {
            return this->_cnvchkcall(disp, query)
              .cast_to(type_identity<string_view>{});
        }

        constexpr auto operator()() const noexcept {
            return this->_fake_empty_c_str().cast_to(
              type_identity<string_view>{});
        }
    } query_string;

    // query_strings
    auto query_strings(
      display_handle disp,
      string_query query,
      char separator) noexcept {
        return query_string(disp, query).transformed([separator](auto src) {
            return split_into_string_list(src, separator);
        });
    }

    // get_client_apis
    auto get_client_apis(display_handle disp) const noexcept {
#ifdef EGL_CLIENT_APIS
        return query_string(disp, string_query(EGL_CLIENT_APIS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_into_string_list(src, ' '); });
    }

    auto get_client_api_bits(display_handle disp) const noexcept {
        enum_bitfield<client_api_bit> result{};

        if(ok apis{get_client_apis(disp)}) {
            for(auto api : apis) {
#ifdef EGL_OPENGL_BIT
                if(are_equal(api, string_view("OpenGL"))) {
                    result.add(client_api_bit(EGL_OPENGL_BIT));
                }
#endif
#ifdef EGL_OPENGL_ES_BIT
                if(are_equal(api, string_view("OpenGL_ES"))) {
                    result.add(client_api_bit(EGL_OPENGL_ES_BIT));
                }
#endif
#ifdef EGL_OPENVG_BIT
                if(are_equal(api, string_view("OpenVG"))) {
                    result.add(client_api_bit(EGL_OPENVG_BIT));
                }
#endif
            }
        }

        return result;
    }

    // get_extensions
    auto get_extensions() const noexcept {
#if defined(EGL_EXTENSIONS) && defined(EGL_NO_DISPLAY)
        return query_string(
                 display_handle(EGL_NO_DISPLAY), string_query(EGL_EXTENSIONS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_into_string_list(src, ' '); });
    }

    // get_extensions
    auto get_extensions(display_handle disp) const noexcept {
#ifdef EGL_EXTENSIONS
        return query_string(disp, string_query(EGL_EXTENSIONS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_into_string_list(src, ' '); });
    }

    // has_extension
    auto has_extension(string_view which) const noexcept {
        if(ok extensions{get_extensions()}) {
            for(auto ext_name : extensions) {
                if(ends_with(ext_name, which)) {
                    return true;
                }
            }
        }
        return false;
    }

    auto has_extension(device_handle dev, string_view which) const noexcept {
        if(ok extensions{get_device_extensions(dev)}) {
            for(auto ext_name : extensions) {
                if(ends_with(ext_name, which)) {
                    return true;
                }
            }
        }
        return false;
    }

    auto has_extension(display_handle disp, string_view which) const noexcept {
        if(ok extensions{get_extensions(disp)}) {
            for(auto ext_name : extensions) {
                if(ends_with(ext_name, which)) {
                    return true;
                }
            }
        }
        return false;
    }

    // swap_interval
    struct : func<EGLPAFP(SwapInterval)> {
        using func<EGLPAFP(SwapInterval)>::func;

        constexpr auto
        operator()(display_handle disp, int_type interval) const noexcept {
            return this->_cnvchkcall(disp, interval);
        }
    } swap_interval;

    // swap_buffers
    struct : func<EGLPAFP(SwapBuffers)> {
        using func<EGLPAFP(SwapBuffers)>::func;

        constexpr auto
        operator()(display_handle disp, surface_handle surf) const noexcept {
            return this->_cnvchkcall(disp, surf);
        }
    } swap_buffers;

    // swap_buffers_with_damage
    struct : func<EGLPAFP(SwapBuffersWithDamage)> {
        using func<EGLPAFP(SwapBuffersWithDamage)>::func;

        constexpr auto operator()(
          display_handle disp,
          surface_handle surf,
          span<const int_type> rects) const noexcept {
            EAGINE_ASSERT(rects.size() % 4 == 0);
            return this->_cnvchkcall(
              disp, surf, rects.data(), limit_cast<int_type>(rects.size()));
        }
    } swap_buffers_with_damage;

    // release_thread
    func<EGLPAFP(ReleaseThread)> release_thread;

    constexpr basic_egl_operations(api_traits& traits)
      : c_api{traits}
      , EXT_device_base("EXT_device_base", traits, *this)
      , EXT_device_enumeration("EXT_device_enumeration", traits, *this)
      , EXT_device_query("EXT_device_query", traits, *this)
      , EXT_device_query_name("EXT_device_query_name", traits, *this)
      , EXT_device_drm("EXT_device_drm", traits, *this)
      , MESA_device_software("MESA_device_software", traits, *this)
      , EXT_platform_base("EXT_platform_base", traits, *this)
      , EXT_platform_device("EXT_platform_device", traits, *this)
      , EXT_platform_x11("EXT_platform_x11", traits, *this)
      , EXT_platform_xcb("EXT_platform_xcb", traits, *this)
      , EXT_platform_wayland("EXT_platform_wayland", traits, *this)
      , KHR_platform_gbm("KHR_platform_gbm", traits, *this)
      , MESA_platform_surfaceless("MESA_platform_surfaceless", traits, *this)
      , EXT_create_context_robustness(
          "EXT_create_context_robustness",
          traits,
          *this)
      , EXT_swap_buffers_with_damage(
          "EXT_swap_buffers_with_damage",
          traits,
          *this)
      , EXT_output_base("EXT_output_base", traits, *this)
      , EXT_output_drm("EXT_output_drm", traits, *this)
      , EXT_stream_consumer_egloutput(
          "EXT_stream_consumer_egloutput",
          traits,
          *this)
      , EXT_pixel_format_float("EXT_pixel_format_float", traits, *this)
      , MESA_configless_context("MESA_configless_context", traits, *this)
      , MESA_query_driver("MESA_query_driver", traits, *this)
      , query_devices("query_devices", traits, *this)
      , query_device_string("query_device_string", traits, *this)
      , get_platform_display("get_platform_display", traits, *this)
      , get_display("get_display", traits, *this)
      , get_display_driver_name("get_display_driver_name", traits, *this)
      , initialize("initialize", traits, *this)
      , terminate("terminate", traits, *this)
      , get_configs("get_configs", traits, *this)
      , choose_config("choose_config", traits, *this)
      , get_config_attrib("get_config_attrib", traits, *this)
      , create_window_surface("create_window_surface", traits, *this)
      , create_pbuffer_surface("create_pbuffer_surface", traits, *this)
      , create_pixmap_surface("create_pixmap_surface", traits, *this)
      , destroy_surface("destroy_surface", traits, *this)
      , get_current_surface("get_current_surface", traits, *this)
      , surface_attrib("surface_attrib", traits, *this)
      , query_surface("query_surface", traits, *this)
      , create_stream("create_stream", traits, *this)
      , destroy_stream("destroy_stream", traits, *this)
      , stream_attrib("stream_attrib", traits, *this)
      , query_stream("query_stream", traits, *this)
      , stream_consumer_gl_texture_external(
          "consumer_gl_texture_external",
          traits,
          *this)
      , stream_consumer_acquire("stream_consumer_acquire", traits, *this)
      , stream_consumer_release("stream_consumer_release", traits, *this)
      , get_output_layers("get_output_layers", traits, *this)
      , output_layer_attrib("output_layer_attrib", traits, *this)
      , query_output_layer_attrib("query_output_layer_attrib", traits, *this)
      , query_output_layer_string("query_output_layer_string", traits, *this)
      , get_output_ports("get_output_ports", traits, *this)
      , output_port_attrib("output_port_attrib", traits, *this)
      , query_output_port_attrib("query_output_port_attrib", traits, *this)
      , query_output_port_string("query_output_port_string", traits, *this)
      , create_image("create_image", traits, *this)
      , destroy_image("destroy_image", traits, *this)
      , bind_api("bind_api", traits, *this)
      , query_api("query_api", traits, *this)
      , create_context("create_context", traits, *this)
      , destroy_context("destroy_context", traits, *this)
      , make_current("make_current", traits, *this)
      , get_current_context("get_current_context", traits, *this)
      , wait_client("wait_client", traits, *this)
      , wait_native("wait_native", traits, *this)
      , create_sync("create_sync", traits, *this)
      , client_wait_sync("client_wait_sync", traits, *this)
      , wait_sync("wait_sync", traits, *this)
      , destroy_sync("destroy_sync", traits, *this)
      , query_string("query_string", traits, *this)
      , swap_interval("swap_interval", traits, *this)
      , swap_buffers("swap_buffers", traits, *this)
      , swap_buffers_with_damage("swap_buffers_with_damage", traits, *this)
      , release_thread("release_thread", traits, *this) {}
};
//------------------------------------------------------------------------------
#undef OGLPAFP
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_API_HPP
