/**
 *  @file oalplus/alc_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_API_HPP
#define OALPLUS_ALC_API_API_HPP

#include "c_api.hpp"
#include "result.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alc_api : public basic_alc_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_alc_c_api<ApiTraits>;

    using device_handle = typename c_api::device_type*;
    using context_handle = typename c_api::context_type*;
    using enum_type = typename c_api::enum_type;
    using char_type = typename c_api::char_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res, device_handle dev = nullptr) const
          noexcept {
            res.error_code(this->api().GetError(dev));
            return std::move(res);
        }
    };

    // open_device
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().OpenDevice);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(this->call(this->api().OpenDevice, nullptr));
        }

        auto operator()(string_view name) const noexcept {
            return this->_check(
              this->call(this->api().OpenDevice, c_str(name)));
        }
    } open_device;

    // close_device
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CloseDevice);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_check(this->call(this->api().CloseDevice, dev), dev);
        }
    } close_device;

    // close_device_raii
    auto close_device_raii(device_handle dev) noexcept {
        return eagine::finally([=]() { this->close_device(dev); });
    }

    // create_context
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CreateContext);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            // TODO: attributes
            return this->_check(
              this->call(this->api().CreateContext, dev, nullptr), dev);
        }
    } create_context;

    // destroy_context
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().DestroyContext);
        }

        constexpr auto operator()(device_handle dev, context_handle ctx) const
          noexcept {
            return this->_check(
              this->call(this->api().DestroyContext, ctx), dev);
        }
    } destroy_context;

    // destroy_context_raii
    auto destroy_context_raii(device_handle dev, context_handle ctx) noexcept {
        return eagine::finally([=]() { this->destroy_context(dev, ctx); });
    }

    // get_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetString);
        }

        constexpr auto operator()(device_handle dev, enum_type query) const
          noexcept {
            return this->_check(
              this->call(this->api().GetString, dev, query), dev);
        }
    } get_string;

    // get_extensions
    auto get_extensions(device_handle dev) noexcept {
        return get_string(dev, ALC_EXTENSIONS)
          .transformed([](const char_type* src) {
              return split_c_str_into_string_list(src, ' ');
          });
    }

    constexpr basic_alc_api(api_traits& traits)
      : c_api{traits}
      , open_device("open_device", traits, *this)
      , close_device("close_device", traits, *this)
      , create_context("create_context", traits, *this)
      , destroy_context("destroy_context", traits, *this)
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using alc_api = basic_alc_api<alc_api_traits>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_API_HPP

