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
#define EGLPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
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

    template <typename W, W c_api::*F>
    class func
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
            return this->_check(this->call(std::forward<Args>(args)...));
        }

    public:
        using base::base;
    };

    // get_platform_display
    struct : func<EGLPAFP(GetPlatformDisplay)> {
        using func<EGLPAFP(GetPlatformDisplay)>::func;

        constexpr auto operator()(
          platform_type platform,
          void_ptr_type disp,
          span<const attrib_type> attribs) const noexcept {
            return this->_chkcall(platform, disp, attribs.data());
        }
    } get_platform_display;

    // get_display
    struct : func<EGLPAFP(GetDisplay)> {
        using func<EGLPAFP(GetDisplay)>::func;

        constexpr auto operator()(native_display_type disp) const noexcept {
            return this->_chkcall(disp);
        }

        constexpr auto operator()() const noexcept {
#ifdef EGL_DEFAULT_DISPLAY
            return this->_chkcall(EGL_DEFAULT_DISPLAY);
#else
            return this->fake({});
#endif
        }
    } get_display;

    // initialize
    struct : func<EGLPAFP(Initialize)> {
        using func<EGLPAFP(Initialize)>::func;

        constexpr auto operator()(
          display_type disp, int_type* maj, int_type* min) const noexcept {
            return this->_chkcall(disp, maj, min);
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
    struct : func<EGLPAFP(Terminate)> {
        using func<EGLPAFP(Terminate)>::func;

        constexpr auto operator()(display_type disp) const noexcept {
            return this->_chkcall(disp);
        }

        auto raii(display_type disp) noexcept {
            return eagine::finally([=]() { (*this)(disp); });
        }
    } terminate;

    // get_configs
    struct : func<EGLPAFP(GetConfigs)> {
        using func<EGLPAFP(GetConfigs)>::func;

        auto count(display_type disp) const noexcept {
            int_type ret_count{0};
            return this->_chkcall(disp, nullptr, 0, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        auto operator()(display_type disp, span<config_type> dest) const
          noexcept {
            int_type ret_count{0};
            return this
              ->_chkcall(
                disp,
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
    } get_configs;

    // choose_config
    struct : func<EGLPAFP(ChooseConfig)> {
        using func<EGLPAFP(ChooseConfig)>::func;

        auto count(display_type disp, span<const int_type> attribs) const
          noexcept {
            int_type ret_count{0};
            return this->_chkcall(disp, attribs.data(), nullptr, 0, &ret_count)
              .transformed([&ret_count](auto ok) {
                  return limit_cast<span_size_t>(
                    egl_types::bool_true(ok) ? ret_count : 0);
              });
        }

        template <std::size_t N>
        auto count(
          display_type disp, const config_attributes<N>& attribs) const {
            return count(disp, attribs.get());
        }

        auto count(
          display_type disp, const config_attribute_value& attribs) const {
            return count(disp, config_attributes<2>{attribs});
        }

        auto operator()(
          display_type disp,
          span<const int_type> attribs,
          span<config_type> dest) const noexcept {
            int_type ret_count{0};
            return this
              ->_chkcall(
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
          display_type disp,
          const config_attributes<N>& attribs,
          span<config_type> dest) const noexcept {
            return (*this)(disp, attribs.get(), dest);
        }

        auto operator()(
          display_type disp,
          const config_attribute_value& attribs,
          span<config_type> dest) const noexcept {
            return (*this)(disp, config_attributes<2>{attribs}, dest);
        }
    } choose_config;

    // get_config_attrib
    struct : func<EGLPAFP(GetConfigAttrib)> {
        using func<EGLPAFP(GetConfigAttrib)>::func;

        constexpr auto operator()(
          display_type disp,
          config_type conf,
          config_attribute attrib,
          int_type* dest) const noexcept {
            return this->_chkcall(disp, conf, int_type(attrib), dest);
        }

        constexpr auto operator()(
          display_type disp, config_type conf, config_attribute attrib) const
          noexcept {
            int_type value{0};
            return (*this)(disp, conf, attrib, &value)
              .transformed([&value](auto ok) {
                  return egl_types::bool_true(ok) ? value : 0;
              });
        }
    } get_config_attrib;

    // query_string
    struct : func<EGLPAFP(QueryString)> {
        using func<EGLPAFP(QueryString)>::func;

        constexpr auto operator()(display_type disp, string_query query) const
          noexcept {
            return this->_chkcall(disp, int_type(query));
        }

        constexpr auto operator()() const noexcept {
            return this->fake("");
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
    struct : func<EGLPAFP(SwapBuffers)> {
        using func<EGLPAFP(SwapBuffers)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall();
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
      , get_config_attrib("get_config_attrib", traits, *this)
      , query_string("query_string", traits, *this)
      , swap_buffers("swap_buffers", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef OGLPAFP
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_API_HPP

