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
          const attrib_type* attribs) const noexcept {
            return this->_check(this->call(
              this->api().GetPlatformDisplay, platform, disp, attribs));
        }
    } get_platform_display;

    // get_display
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetPlatformDisplay);
        }

        constexpr auto operator()(native_display_type disp) const noexcept {
            return this->_check(
              this->call(this->api().GetPlatformDisplay, disp));
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

    // query_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().QueryString);
        }

        constexpr auto operator()(display_type disp, string_query query) const
          noexcept {
            return this->_check(
              this->call(this->api().QueryString, disp, enum_type(query)));
        }

        constexpr auto operator()() const noexcept {
            return this->fake(this->api().QueryString, "");
        }
    } query_string;

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
      , query_string("query_string", traits, *this)
      , swap_buffers("swap_buffers", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_API_HPP

