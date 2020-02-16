/**
 *  @file oglplus/gl_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_API_HPP
#define OGLPLUS_GL_API_API_HPP

#include "c_api.hpp"
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_gl_api : public basic_gl_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_gl_c_api<ApiTraits>;

    using void_ptr_type = typename gl_types::void_ptr_type;
    using sizei_type = typename gl_types::sizei_type;
    using int_type = typename gl_types::int_type;
    using bool_type = typename gl_types::char_type;
    using char_type = typename gl_types::char_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }
    };

    // viewport
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Viewport);
        }

        constexpr auto operator()(
          int_type x, int_type y, sizei_type w, sizei_type h) const noexcept {
            return this->_check(this->call(this->api().Viewport, x, y, w, h));
        }

        constexpr auto operator()(sizei_type w, sizei_type h) const noexcept {
            return this->_check(this->call(this->api().Viewport, 0, 0, w, h));
        }
    } viewport;

    // clear_color
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ClearColor);
        }

        constexpr auto operator()(
          float_type r, float_type g, float_type b, float_type a) const
          noexcept {
            return this->_check(this->call(this->api().ClearColor, r, g, b, a));
        }
    } clear_color;

    // clear_depth
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ClearDepthf) ||
                   bool(this->api().ClearDepth);
        }

        constexpr auto operator()(float_type d) const noexcept {
            if(EAGINE_LIKELY(this->api().ClearDepthf)) {
                return this->_check(this->call(this->api().ClearDepthf, d));
            }
            return this->_check(
              this->call(this->api().ClearDepth, double_type(d)));
        }

        constexpr auto operator()(double_type d) const noexcept {
            return this->_check(this->call(this->api().ClearDepth, d));
        }
    } clear_depth;

    // clear_stencil
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ClearStencil);
        }

        constexpr auto operator()(int_type s) const noexcept {
            return this->_check(this->call(this->api().ClearStencil, s));
        }
    } clear_stencil;

    // clear
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Clear);
        }

        constexpr auto operator()(enum_bitfield<buffer_clear_bit> mask) const
          noexcept {
            return this->_check(
              this->call(this->api().Clear, bitfield_type(mask)));
        }
    } clear;

    // get_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetString);
        }

        constexpr auto operator()(string_query query) const noexcept {
            return this
              ->_check(this->call(this->api().GetString, enum_type(query)))
              .transformed(
                [](auto src) { return reinterpret_cast<const char*>(src); });
        }

        constexpr auto operator()() const noexcept {
            return this->fake(this->api().GetString, "");
        }
    } get_string;

    // get_strings
    auto get_strings(string_query query, char separator) noexcept {
        return get_string(query).transformed([separator](auto src) {
            return split_c_str_into_string_list(src, separator);
        });
    }

    // get_extensions
    auto get_extensions() noexcept {
#ifdef GL_EXTENSIONS
        return get_string(string_query(GL_EXTENSIONS))
#else
        return get_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    constexpr basic_gl_api(api_traits& traits)
      : c_api{traits}
      , viewport("viewport", traits, *this)
      , clear_color("clear_color", traits, *this)
      , clear_depth("clear_depth", traits, *this)
      , clear_stencil("clear_stencil", traits, *this)
      , clear("clear", traits, *this)
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_API_HPP

