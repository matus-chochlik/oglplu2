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

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class alc_api : public alc_c_api {

    template <
      typename ApiTraits,
      typename Tag,
      typename RV,
      typename... Params,
      typename... Args>
    static constexpr alc_no_result<RV> _call(
      const unimplemented_c_api_function<ApiTraits, Tag, RV(Params...)>&,
      Args&&...) noexcept {
        return {};
    }

    template <
      typename ApiTraits,
      typename Tag,
      typename RV,
      typename... Params,
      typename... Args,
      RV (*Func)(Params...)>
    static constexpr alc_result<RV> _call(
      static_c_api_function<ApiTraits, Tag, RV(Params...), Func>& function,
      Args&&... args) noexcept {
        return {std::move(function(std::forward<Args>(args)...))};
    }

    template <
      typename ApiTraits,
      typename Tag,
      typename... Params,
      typename... Args,
      void (*Func)(Params...)>
    static constexpr alc_result<void> _call(
      static_c_api_function<ApiTraits, Tag, void(Params...), Func>& function,
      Args&&... args) noexcept {
        function(std::forward<Args>(args)...);
        return {};
    }

    template <typename RV>
    constexpr auto _check(
      alc_result<RV>&& res, alc_c_api::device_type* dev = nullptr) const
      noexcept {
        return std::move(res).error_code(GetError(dev));
    }

public:
    using device_handle = alc_c_api::device_type*;
    using context_handle = alc_c_api::context_type*;

    template <typename Tag = nothing_t>
    struct derived_func
      : derived_c_api_function<alc_c_api, alc_c_api_traits, Tag> {
        using base = derived_c_api_function<alc_c_api, alc_c_api_traits, Tag>;
        using base::api;
        using base::base;

        template <typename Res>
        constexpr auto _check(
          Res&& res, alc_c_api::device_type* dev = nullptr) const noexcept {
            return std::move(res).error_code(api().GetError(dev));
        }
    };

    struct : derived_func<> {
        using base = derived_func<>;
        using base::_check;
        using base::api;
        using base::base;

        explicit constexpr operator bool() const noexcept {
            return bool(api().OpenDevice);
        }

        constexpr auto operator()() const noexcept {
            return _check(_call(api().OpenDevice, nullptr));
        }

        auto operator()(string_view name) const noexcept {
            return _check(_call(api().OpenDevice, c_str(name)));
        }
    } open_device;

    struct : derived_func<> {
        using base = derived_func<>;
        using base::_check;
        using base::api;
        using base::base;

        explicit constexpr operator bool() const noexcept {
            return bool(api().CloseDevice);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return _check(_call(api().CloseDevice, dev), dev);
        }
    } close_device;

    auto close_device_raii(device_handle dev) noexcept {
        return eagine::finally([=]() { this->close_device(dev); });
    }

    struct : derived_func<> {
        using base = derived_func<>;
        using base::_check;
        using base::api;
        using base::base;

        explicit constexpr operator bool() const noexcept {
            return bool(api().CreateContext);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            // TODO: attributes
            return _check(_call(api().CreateContext, dev, nullptr), dev);
        }
    } create_context;

    struct : derived_func<> {
        using base = derived_func<>;
        using base::_check;
        using base::api;
        using base::base;

        explicit constexpr operator bool() const noexcept {
            return bool(api().DestroyContext);
        }

        constexpr auto operator()(device_handle dev, context_handle ctx) const
          noexcept {
            return _check(_call(api().DestroyContext, ctx), dev);
        }
    } destroy_context;

    auto destroy_context_raii(device_handle dev, context_handle ctx) noexcept {
        return eagine::finally([=]() { this->destroy_context(dev, ctx); });
    }

    constexpr alc_api(alc_c_api_traits& traits)
      : alc_c_api{traits}
      , open_device("open_device", traits, *this)
      , close_device("close_device", traits, *this)
      , create_context("create_context", traits, *this)
      , destroy_context("destroy_context", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_API_HPP

