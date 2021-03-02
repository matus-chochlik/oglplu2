/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_EXTENSIONS_HPP
#define OGLPLUS_GL_API_EXTENSIONS_HPP

#include <eagine/string_span.hpp>

namespace eagine::oglp {

template <typename ApiTraits>
class basic_gl_operations;

/// @brief Wrapper for GL extension information getter.
/// @ingroup gl_api_wrap
template <typename ApiTraits>
class basic_gl_extension {
public:
    constexpr basic_gl_extension(
      string_view name,
      ApiTraits&,
      const basic_gl_operations<ApiTraits>& api) noexcept
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
    const basic_gl_operations<ApiTraits>& _api;
    string_view _name;
};

} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_EXTENSIONS_HPP
