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
#include "enum_types.hpp"
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

    using device_handle = typename api_types::device_type*;
    using context_handle = typename api_types::context_type*;
    using enum_type = typename api_types::enum_type;
    using char_type = typename api_types::char_type;

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

        constexpr auto operator()(
          device_handle dev, alc_string_query query) const noexcept {
            return this->_check(
              this->call(this->api().GetString, dev, enum_type(query)), dev);
        }

        constexpr auto operator()(alc_string_query query) const noexcept {
            return (*this)(nullptr, query);
        }

        constexpr auto operator()(device_handle) const noexcept {
            return this->fake(this->api().GetString, "");
        }
    } get_string;

    // get_extensions
    auto get_extensions(device_handle dev) noexcept {
#ifdef ALC_EXTENSIONS
        return get_string(dev, alc_string_query(ALC_EXTENSIONS))
#else
        return get_string(dev)
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // get_default_device_specifier
    auto get_default_device_specifier() noexcept {
#ifdef ALC_DEFAULT_DEVICE_SPECIFIER
        return get_string(
                 nullptr, alc_string_query(ALC_DEFAULT_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed([](auto src) { return string_view(src); });
    }

    // get_device_specifiers
    auto get_device_specifiers() noexcept {
#ifdef ALC_DEVICE_SPECIFIER
        return get_string(nullptr, alc_string_query(ALC_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, '\0'); });
    }

    // get_capture_default_device_specifier
    auto get_capture_default_device_specifier() noexcept {
#ifdef ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER
        return get_string(
                 nullptr,
                 alc_string_query(ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed([](auto src) { return string_view(src); });
    }

    // get_capture_device_specifiers
    auto get_capture_device_specifiers() noexcept {
#ifdef ALC_CAPTURE_DEVICE_SPECIFIER
        return get_string(
                 nullptr, alc_string_query(ALC_CAPTURE_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, '\0'); });
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

