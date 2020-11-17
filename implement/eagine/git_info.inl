/**
 *  @file eagine/git_info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#if __has_include(<eagine/config/git_info.hpp>)
#include <eagine/config/git_info.hpp>
#endif

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_branch() noexcept -> valid_if_not_empty<string_view> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_BRANCH}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_hash_id() noexcept -> valid_if_not_empty<string_view> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_HASH_ID}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_date() noexcept -> valid_if_not_empty<string_view> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_DATE}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_describe() noexcept -> valid_if_not_empty<string_view> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_DESCRIBE}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_version() noexcept -> valid_if_not_empty<string_view> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_VERSION}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_version_major() noexcept -> valid_if_nonnegative<int> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {EAGINE_GIT_VERSION_MAJOR};
#else
    return -1;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_version_minor() noexcept -> valid_if_nonnegative<int> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {EAGINE_GIT_VERSION_MINOR};
#else
    return -1;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_version_patch() noexcept -> valid_if_nonnegative<int> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {EAGINE_GIT_VERSION_PATCH};
#else
    return -1;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto config_git_version_commit() noexcept -> valid_if_nonnegative<int> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {EAGINE_GIT_VERSION_COMMIT};
#else
    return -1;
#endif
}
//------------------------------------------------------------------------------
auto config_git_version_tuple() noexcept
  -> optionally_valid<std::tuple<int, int, int, int>> {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {
      {EAGINE_GIT_VERSION_MAJOR,
       EAGINE_GIT_VERSION_MINOR,
       EAGINE_GIT_VERSION_PATCH,
       EAGINE_GIT_VERSION_COMMIT},
      true};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
} // namespace eagine
