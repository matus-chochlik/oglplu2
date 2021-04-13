/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_GIT_INFO_HPP
#define EAGINE_GIT_INFO_HPP

#include "string_span.hpp"
#include "valid_if/nonnegative.hpp"
#include "valid_if/not_empty.hpp"
#include <tuple>

namespace eagine {

/// @brief Returns the name of the git branch from which the executable is built.
/// @ingroup main_ctx
/// @see config_git_date
/// @see config_git_hash_id
/// @see config_git_describe
auto config_git_branch() noexcept -> valid_if_not_empty<string_view>;

/// @brief Returns the hash of the commit from which the executable is built.
/// @ingroup main_ctx
/// @see config_git_date
/// @see config_git_branch
auto config_git_hash_id() noexcept -> valid_if_not_empty<string_view>;

/// @brief Returns the date of the commit from which the executable is built.
/// @ingroup main_ctx
/// @see config_git_hash_id
auto config_git_date() noexcept -> valid_if_not_empty<string_view>;

/// @brief Returns the description of the commit from which the executable is built.
/// @ingroup main_ctx
/// @see config_git_date
/// @see config_git_hash_id
/// @see config_git_branch
auto config_git_describe() noexcept -> valid_if_not_empty<string_view>;

/// @brief Returns the version number as string.
/// @ingroup main_ctx
/// @see config_git_version_major
/// @see config_git_version_minor
/// @see config_git_version_patch
/// @see config_git_version_commit
/// @see config_git_version_tuple
auto config_git_version() noexcept -> valid_if_not_empty<string_view>;

/// @brief Returns major version number.
/// @ingroup main_ctx
/// @see config_git_version_minor
/// @see config_git_version_patch
/// @see config_git_version_commit
/// @see config_git_version_tuple
auto config_git_version_major() noexcept -> valid_if_nonnegative<int>;

/// @brief Returns minor version number.
/// @ingroup main_ctx
/// @see config_git_version_major
/// @see config_git_version_patch
/// @see config_git_version_commit
/// @see config_git_version_tuple
auto config_git_version_minor() noexcept -> valid_if_nonnegative<int>;

/// @brief Returns patch version number.
/// @ingroup main_ctx
/// @see config_git_version_major
/// @see config_git_version_minor
/// @see config_git_version_commit
/// @see config_git_version_tuple
auto config_git_version_patch() noexcept -> valid_if_nonnegative<int>;

/// @brief Returns commit version number.
/// @ingroup main_ctx
/// @see config_git_version_major
/// @see config_git_version_minor
/// @see config_git_version_patch
/// @see config_git_version_tuple
auto config_git_version_commit() noexcept -> valid_if_nonnegative<int>;

/// @brief Returns the complete version number as a tuple (major, minor, patch, commit).
/// @ingroup main_ctx
/// @see config_git_version_major
/// @see config_git_version_minor
/// @see config_git_version_patch
/// @see config_git_version_commit
auto config_git_version_tuple() noexcept -> std::tuple<int, int, int, int>;

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/git_info.inl>
#endif

#endif // EAGINE_GIT_INFO_HPP
