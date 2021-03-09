/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_EXTENSIONS_HPP
#define EGLPLUS_EGL_API_EXTENSIONS_HPP

#include "objects.hpp"

namespace eagine::eglp {

template <typename ApiTraits>
class basic_egl_operations;

/// @brief Wrapper for EGL extension information getter.
/// @ingroup egl_api_wrap
template <typename ApiTraits, typename...>
class basic_egl_extension {
public:
    constexpr basic_egl_extension(
      string_view name,
      ApiTraits&,
      const basic_egl_operations<ApiTraits>& api) noexcept
      : _api{api}
      , _name{name} {}

    /// @brief Tests if this extension is available.
    explicit operator bool() const noexcept {
        return _api.has_extension(_name);
    }

    /// @brief Tests if this extension is available.
    auto operator()() const noexcept -> bool {
        return _api.has_extension(_name);
    }

private:
    const basic_egl_operations<ApiTraits>& _api;
    string_view _name;
};

/// @brief Wrapper for display-specific EGL extension information getter.
/// @ingroup egl_api_wrap
template <typename ApiTraits>
class basic_egl_extension<ApiTraits, display_handle> {
public:
    constexpr basic_egl_extension(
      string_view name,
      ApiTraits&,
      const basic_egl_operations<ApiTraits>& api) noexcept
      : _api{api}
      , _name{name} {}

    /// @brief Tests if this extension is available on the specified display.
    auto operator()(display_handle disp) const noexcept -> bool {
        return _api.has_extension(disp, _name);
    }

private:
    const basic_egl_operations<ApiTraits>& _api;
    string_view _name;
};

/// @brief Wrapper for device-specific EGL extension information getter.
/// @ingroup egl_api_wrap
template <typename ApiTraits>
class basic_egl_extension<ApiTraits, device_handle> {
public:
    constexpr basic_egl_extension(
      string_view name,
      ApiTraits&,
      const basic_egl_operations<ApiTraits>& api) noexcept
      : _api{api}
      , _name{name} {}

    /// @brief Tests if this extension is available on the specified device.
    auto operator()(device_handle dev) const noexcept -> bool {
        return _api.has_extension(dev, _name);
    }

private:
    const basic_egl_operations<ApiTraits>& _api;
    string_view _name;
};

} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_EXTENSIONS_HPP
