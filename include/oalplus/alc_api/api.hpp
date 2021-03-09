/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_API_HPP
#define OALPLUS_ALC_API_API_HPP

#include "c_api.hpp"
#include "enum_types.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/span.hpp>
#include <eagine/string_list.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
#define OALPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
/// @brief Class wrapping the functions from the ALC API.
/// @ingroup al_api_wrap
/// @see basic_alc_constants
/// @see basic_alc_c_api
template <typename ApiTraits>
class basic_alc_operations : public basic_alc_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_alc_c_api<ApiTraits>;

    using device_handle = typename alc_types::device_type*;
    using context_handle = typename alc_types::context_type*;
    using enum_type = typename alc_types::enum_type;
    using size_type = typename alc_types::size_type;
    using char_type = typename alc_types::char_type;
    using int_type = typename alc_types::int_type;

    template <typename W, W c_api::*F, typename Signature = typename W::signature>
    class func;

    template <typename W, W c_api::*F, typename RVC, typename... Params>
    class func<W, F, RVC(Params...)>
      : public wrapped_c_api_function<c_api, api_traits, nothing_t, W, F> {
        using base = wrapped_c_api_function<c_api, api_traits, nothing_t, W, F>;

    private:
        template <typename Res>
        constexpr auto _check(device_handle dev, Res&& res) const noexcept {
            res.error_code(this->api().GetError(dev));
            return std::forward<Res>(res);
        }

    protected:
        template <typename... Args>
        constexpr auto
        _chkcall(device_handle dev, Args&&... args) const noexcept {
            return this->_check(dev, this->_call(std::forward<Args>(args)...));
        }

        using base::_conv;

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...)
              .cast_to(type_identity<RVC>{});
        }
    };

    // open_device
    struct : func<OALPAFP(OpenDevice)> {
        using func<OALPAFP(OpenDevice)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall(nullptr, nullptr);
        }

        auto operator()(string_view name) const noexcept {
            return this->_chkcall(nullptr, c_str(name));
        }
    } open_device;

    // close_device
    struct : func<OALPAFP(CloseDevice)> {
        using func<OALPAFP(CloseDevice)>::func;

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_chkcall(dev, dev);
        }

        auto raii(device_handle dev) noexcept {
            return eagine::finally([=]() { (*this)(dev); });
        }
    } close_device;

    // create_context
    struct : func<OALPAFP(CreateContext)> {
        using func<OALPAFP(CreateContext)>::func;

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_chkcall(dev, dev, nullptr);
        }

        constexpr auto operator()(
          device_handle dev,
          span<const int_type> attributes) const noexcept {
            return this->_chkcall(dev, dev, attributes.data());
        }
    } create_context;

    // destroy_context
    struct : func<OALPAFP(DestroyContext)> {
        using func<OALPAFP(DestroyContext)>::func;

        constexpr auto
        operator()(device_handle dev, context_handle ctx) const noexcept {
            return this->_chkcall(dev, ctx);
        }

        auto raii(device_handle dev, context_handle ctx) noexcept {
            return eagine::finally([=]() { (*this)(dev, ctx); });
        }
    } destroy_context;

    // make_context_current
    struct : func<OALPAFP(MakeContextCurrent)> {
        using func<OALPAFP(MakeContextCurrent)>::func;

        constexpr auto
        operator()(device_handle dev, context_handle ctx) const noexcept {
            return this->_chkcall(dev, ctx);
        }

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_chkcall(dev, nullptr);
        }

        constexpr auto operator()(context_handle ctx) const noexcept {
            return this->_chkcall(nullptr, ctx);
        }

        constexpr auto operator()() const noexcept {
            return this->_chkcall(nullptr, nullptr);
        }

        auto raii(device_handle dev) noexcept {
            return eagine::finally([=]() { (*this)(dev); });
        }

        auto raii() noexcept {
            return eagine::finally([=]() { (*this)(); });
        }
    } make_context_current;

    // get_current_context
    struct : func<OALPAFP(GetCurrentContext)> {
        using func<OALPAFP(GetCurrentContext)>::func;

        constexpr auto operator()(device_handle dev) const noexcept {
            return this->_chkcall(dev);
        }

        constexpr auto operator()() const noexcept {
            return this->_chkcall(nullptr);
        }
    } get_current_context;

    // get_integer
    struct : func<OALPAFP(GetIntegerv)> {
        using func<OALPAFP(GetIntegerv)>::func;

        constexpr auto
        operator()(device_handle dev, alc_integer_query query) const noexcept {
            int_type result{};
            return this
              ->_chkcall(dev, dev, enum_type(query), size_type(1), &result)
              .replaced_with(result);
        }

        constexpr auto operator()(alc_integer_query query) const noexcept {
            return (*this)(nullptr, query);
        }

        constexpr auto operator()(
          device_handle dev,
          alc_integer_query query,
          span<int_type> dst) const noexcept {
            return this->_chkcall(
              dev, dev, enum_type(query), size_type(dst.size()), dst.data());
        }
    } get_integer;

    // get_string
    struct : func<OALPAFP(GetString)> {
        using func<OALPAFP(GetString)>::func;

        constexpr auto
        operator()(device_handle dev, alc_string_query query) const noexcept {
            return this->_chkcall(dev, dev, enum_type(query))
              .cast_to(type_identity<string_view>{});
        }

        constexpr auto operator()(alc_string_query query) const noexcept {
            return (*this)(nullptr, query);
        }

        constexpr auto operator()(device_handle) const noexcept {
            return this->_fake_empty_c_str().cast_to(
              type_identity<string_view>{});
        }
    } get_string;

    // get_strings
    auto get_strings(
      device_handle dev,
      alc_string_query query,
      char separator) noexcept {
        return get_string(dev, query).transformed([separator](auto src) {
            return split_into_string_list(src, separator);
        });
    }

    // get_extensions
    auto get_extensions(device_handle dev) noexcept {
#ifdef ALC_EXTENSIONS
        return get_string(dev, alc_string_query(ALC_EXTENSIONS))
#else
        return get_string(dev)
#endif
          .transformed(
            [](auto src) { return split_into_string_list(src, ' '); });
    }

    // get_default_device_specifier
    auto get_default_device_specifier() noexcept {
#ifdef ALC_DEFAULT_DEVICE_SPECIFIER
        return get_string(
          nullptr, alc_string_query(ALC_DEFAULT_DEVICE_SPECIFIER));
#else
        return get_string(nullptr);
#endif
    }

    // get_device_specifiers
    auto get_device_specifiers() noexcept {
#ifdef ALC_DEVICE_SPECIFIER
        return get_string(nullptr, alc_string_query(ALC_DEVICE_SPECIFIER))
#else
        return get_string(nullptr)
#endif
          .transformed(
            [](auto src) { return split_into_string_list(src, '\0'); });
    }

    // get_capture_default_device_specifier
    auto get_capture_default_device_specifier() noexcept {
#ifdef ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER
        return get_string(
          nullptr, alc_string_query(ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER));
#else
        return get_string(nullptr);
#endif
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
            [](auto src) { return split_into_string_list(src, '\0'); });
    }

    basic_alc_operations(api_traits& traits);
};
//------------------------------------------------------------------------------
#undef OALPAFP
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_API_HPP
