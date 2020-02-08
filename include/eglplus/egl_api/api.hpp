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

    using int_type = typename egl_types::int_type;
    using bool_type = typename egl_types::char_type;
    using char_type = typename egl_types::char_type;
    using enum_type = typename egl_types::enum_type;
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

    constexpr basic_egl_api(api_traits& traits)
      : c_api{traits}
      , query_string("query_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_API_HPP

