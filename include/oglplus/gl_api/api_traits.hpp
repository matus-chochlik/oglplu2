/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_API_TRAITS_HPP
#define OGLPLUS_GL_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Policy customizing the generic C-API wrappers for the GL API
/// @ingroup gl_api_wrap
class gl_api_traits : public default_c_api_traits {
public:
    /// @brief Alias for result type of currently unavailable functions.
    template <typename R>
    using no_result = gl_no_result<R>;

    /// @brief Alias for result type of functions.
    template <typename R>
    using result = gl_result<R>;

    /// @brief Alias for result type of optionally available functions.
    template <typename R>
    using opt_result = gl_opt_result<R>;

    /// @brief Combined result.
    /// @see result
    /// @see opt_result
    /// @see no_result
    template <typename R>
    using combined_result = gl_combined_result<R>;

    /// @brief Links a GL function with the specified name and Signature.
    template <typename Api, typename Tag, typename Signature>
    auto link_function(Api&, Tag, string_view name, type_identity<Signature>)
      -> std::add_pointer_t<Signature>;

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_API_TRAITS_HPP
