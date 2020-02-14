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
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_egl_api : public basic_egl_c_api<ApiTraits> {

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
    using display_type = typename egl_types::display_type;
    using config_type = typename egl_types::config_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }
    };

    // get_platform_display
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetPlatformDisplay);
        }

        constexpr auto operator()(
          platform_type platform,
          void_ptr_type disp,
          span<const attrib_type> attribs) const noexcept {
            return this->_check(this->call(
              this->api().GetPlatformDisplay, platform, disp, attribs.data()));
        }
    } get_platform_display;

    // get_display
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetDisplay);
        }

        constexpr auto operator()(native_display_type disp) const noexcept {
            return this->_check(this->call(this->api().GetDisplay, disp));
        }

        constexpr auto operator()() const noexcept {
#ifdef EGL_DEFAULT_DISPLAY
            return this->_check(
              this->call(this->api().GetDisplay, EGL_DEFAULT_DISPLAY));
#else
            return this->fake(this->api().GetDisplay, {});
#endif
        }
    } get_display;

    // initialize
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Initialize);
        }

        constexpr auto operator()(
          display_type disp, int_type* maj, int_type* min) const noexcept {
            return this->_check(
              this->call(this->api().Initialize, disp, maj, min));
        }

        constexpr auto operator()(display_type disp) const noexcept {
            int_type maj{-1};
            int_type min{-1};
            return (*this)(disp, &maj, &min).transformed([&maj, &min](auto) {
                return std::make_tuple(maj, min);
            });
        }
    } initialize;

    // terminate
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Terminate);
        }

        constexpr auto operator()(display_type disp) const noexcept {
            return this->_check(this->call(this->api().Terminate, disp));
        }

        auto raii(display_type disp) noexcept {
            return eagine::finally([=]() { (*this)(disp); });
        }
    } terminate;

    // get_configs
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetConfigs);
        }

        auto operator()(display_type disp, span<config_type> dest) const
          noexcept {
            int_type ret_count{0};
            return this
              ->_check(this->call(
                this->api().GetConfigs,
                disp,
                dest.data(),
                limit_cast<int_type>(dest.size()),
                &ret_count))
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }
    } get_configs;

    // choose_config
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ChooseConfig);
        }

        auto operator()(
          display_type disp,
          span<attrib_type> attribs,
          span<config_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_check(this->call(
                this->api().ChooseConfig,
                disp,
                attribs.data(),
                dest.data(),
                limit_cast<int_type>(dest.size()),
                &ret_count))
              .transformed([dest, &ret_count](auto ok) {
                  return head(
                    dest,
                    limit_cast<span_size_t>(
                      egl_types::bool_true(ok) ? ret_count : 0));
              });
        }

        auto operator()(
          display_type disp,
          const config_attributes<2>& attribs,
          span<config_type> dest) const noexcept {
            return (*this)(disp, attribs.get(), dest);
        }
    } choose_config;

    // query_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().QueryString);
        }

        constexpr auto operator()(display_type disp, string_query query) const
          noexcept {
            return this->_check(
              this->call(this->api().QueryString, disp, int_type(query)));
        }

        constexpr auto operator()() const noexcept {
            return this->fake(this->api().QueryString, "");
        }
    } query_string;

    // query_strings
    auto query_strings(
      display_type disp, string_query query, char separator) noexcept {
        return query_string(disp, query).transformed([separator](auto src) {
            return split_c_str_into_string_list(src, separator);
        });
    }

    // get_client_apis
    auto get_client_apis(display_type disp) noexcept {
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
        return query_string(EGL_NO_DISPLAY, string_query(EGL_EXTENSIONS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // get_extensions
    auto get_extensions(display_type disp) noexcept {
#ifdef EGL_EXTENSIONS
        return query_string(disp, string_query(EGL_EXTENSIONS))
#else
        return query_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // swap_buffers
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SwapBuffers);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(this->call(this->api().SwapBuffers));
        }
    } swap_buffers;

    constexpr basic_egl_api(api_traits& traits)
      : c_api{traits}
      , get_platform_display("get_platform_display", traits, *this)
      , get_display("get_display", traits, *this)
      , initialize("initialize", traits, *this)
      , terminate("terminate", traits, *this)
      , get_configs("get_configs", traits, *this)
      , choose_config("choose_config", traits, *this)
      , query_string("query_string", traits, *this)
      , swap_buffers("swap_buffers", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_API_HPP

