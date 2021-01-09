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
#include "objects.hpp"
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
    using native_display_type = typename egl_types::native_display_type;
    using native_window_type = typename egl_types::native_window_type;
    using native_pixmap_type = typename egl_types::native_pixmap_type;
    using config_type = typename egl_types::config_type;

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

    // get_platform_display
    struct : func<EGLPAFP(GetPlatformDisplay)> {
        using func<EGLPAFP(GetPlatformDisplay)>::func;

        constexpr auto operator()(
          platform_type platform,
          void_ptr_type disp,
          span<const attrib_type> attribs) const noexcept {
            return this->_cnvchkcall(platform, disp, attribs.data())
              .cast_to(type_identity<display_handle>{});
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

        auto operator()(
          display_handle disp,
          const config_attribute_value& attribs,
          span<config_type> dest) const noexcept {
            return (*this)(disp, config_attributes<2>{attribs}, dest);
        }
    } choose_config;

    // get_config_attrib
    struct : func<EGLPAFP(GetConfigAttrib)> {
        using func<EGLPAFP(GetConfigAttrib)>::func;

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          config_attribute attrib,
          int_type* dest) const noexcept {
            return this->_cnvchkcall(disp, conf, attrib, dest);
        }

        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          config_attribute attrib) const noexcept {
            int_type value{0};
            return (*this)(disp, conf, attrib, &value)
              .transformed([&value](auto ok) {
                  return egl_types::bool_true(ok) ? value : 0;
              });
        }
    } get_config_attrib;

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
          const surface_attributes<N> attribs) const noexcept {
            return (*this)(disp, conf, context_handle{}, attribs.get());
        }

        template <std::size_t N>
        constexpr auto operator()(
          display_handle disp,
          config_type conf,
          context_handle share_ctxt,
          const surface_attributes<N> attribs) const noexcept {
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
            return this->_cnvchkcall(disp, query);
        }

        constexpr auto operator()() const noexcept {
            return this->_fake("");
        }
    } query_string;

    // query_strings
    auto query_strings(
      display_handle disp,
      string_query query,
      char separator) noexcept {
        return query_string(disp, query).transformed([separator](auto src) {
            return split_c_str_into_string_list(src, separator);
        });
    }

    // get_client_apis
    auto get_client_apis(display_handle disp) noexcept {
#ifdef EGL_CLIENT_APIS
        return query_string(disp, string_query(EGL_CLIENT_APIS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // get_extensions
    auto get_extensions() noexcept {
#if defined(EGL_EXTENSIONS) && defined(EGL_NO_DISPLAY)
        return query_string(
                 display_handle(EGL_NO_DISPLAY), string_query(EGL_EXTENSIONS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // get_extensions
    auto get_extensions(display_handle disp) noexcept {
#ifdef EGL_EXTENSIONS
        return query_string(disp, string_query(EGL_EXTENSIONS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // swap_interval
    func<EGLPAFP(SwapInterval)> swap_interval;

    // swap_buffers
    func<EGLPAFP(SwapBuffers)> swap_buffers;

    // release_thread
    func<EGLPAFP(ReleaseThread)> release_thread;

    constexpr basic_egl_operations(api_traits& traits)
      : c_api{traits}
      , get_platform_display("get_platform_display", traits, *this)
      , get_display("get_display", traits, *this)
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
      , release_thread("release_thread", traits, *this) {}
};
//------------------------------------------------------------------------------
#undef OGLPAFP
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_API_HPP
