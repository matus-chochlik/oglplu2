/**
 *  @file oalplus/alut_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_API_HPP
#define OALPLUS_ALUT_API_API_HPP

#include "c_api.hpp"
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alut_api : public basic_alut_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_alut_c_api<ApiTraits>;

    using enum_type = typename alut_types::enum_type;
    using char_type = typename alut_types::char_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }
    };

    // init
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Init);
        }

        constexpr auto operator()(int* argcp, char** argvp) const noexcept {
            return this->_check(this->call(this->api().Init, argcp, argvp));
        }
    } init;

    // create_buffer_hello_world
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CreateBufferHelloWorld);
        }

        constexpr auto operator()() const noexcept {
            // TODO: transform to buffer name wrapper.
            return this->_check(this->call(this->api().CreateBufferHelloWorld));
        }
    } create_buffer_hello_world;

    // exit
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Exit);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(this->call(this->api().Exit));
        }
    } exit;

    // exit_raii
    auto exit_raii() noexcept {
        return eagine::finally([=]() { this->exit(); });
    }

    constexpr basic_alut_api(api_traits& traits)
      : c_api{traits}
      , init("init", traits, *this)
      , create_buffer_hello_world("create_buffer_hello_world", traits, *this)
      , exit("exit", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_API_HPP

