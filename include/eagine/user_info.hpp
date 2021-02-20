/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_USER_INFO_HPP
#define EAGINE_USER_INFO_HPP

#include "config/platform.hpp"
#include "main_ctx_object.hpp"
#include "string_span.hpp"
#include "valid_if/not_empty.hpp"

namespace eagine {

class user_info_impl;

/// @brief Class providing user-related information.
/// @ingroup main_context
class user_info : public main_ctx_object {
public:
    user_info(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(UserInfo), parent} {}

    /// @brief The user's login name.
    auto login_name() -> valid_if_not_empty<string_view>;

    /// @brief Paths to the user's home directory.
    auto home_dir_path() -> valid_if_not_empty<string_view>;

private:
    std::shared_ptr<user_info_impl> _pimpl;
    auto _impl() noexcept -> user_info_impl*;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/user_info.inl>
#endif

#endif
