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
    using int_type = typename gl_types::int_type;
    using bool_type = typename gl_types::char_type;
    using char_type = typename gl_types::char_type;
    using enum_type = typename gl_types::enum_type;
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

    // clear
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Clear);
        }

        constexpr auto operator()(enum_bitfield<buffer_clear_bit> mask) const
          noexcept {
            return this->_check(
              this->call(this->api().clear, bitfield_type(mask)));
        }
    } clear;

    constexpr basic_gl_api(api_traits& traits)
      : c_api{traits}
      , clear("clear", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_API_HPP

