/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_API_HPP
#define OALPLUS_ALUT_API_API_HPP

#include "../al_api/object_name.hpp"
#include "c_api.hpp"
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
#define OALPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
/// @brief Class wrapping the functions from the ALUT API.
/// @ingroup al_api_wrap
/// @see basic_alut_constants
/// @see basic_alut_c_api
template <typename ApiTraits>
class basic_alut_operations : public basic_alut_c_api<ApiTraits> {

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

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...)
              .cast_to(type_identity<RVC>{});
        }
    };

    // init
    func<OALPAFP(Init)> init;

    // create_buffer_hello_world
    func<OALPAFP(CreateBufferHelloWorld), owned_buffer_name()>
      create_buffer_hello_world;

    // exit
    struct : func<OALPAFP(Exit)> {
        using base = func<OALPAFP(Exit)>;
        using base::base;
        using base::operator();

        auto raii() noexcept {
            return eagine::finally([=]() { (*this)(); });
        }
    } exit;

    basic_alut_operations(api_traits& traits);
};
//------------------------------------------------------------------------------
#undef OALPAFP
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_API_HPP
