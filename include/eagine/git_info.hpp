/**
 *  @file eagine/git_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_GIT_INFO_HPP
#define EAGINE_GIT_INFO_HPP

#include "string_span.hpp"
#include "valid_if/nonnegative.hpp"
#include "valid_if/not_empty.hpp"
#include <tuple>

namespace eagine {

auto config_git_branch() noexcept -> valid_if_not_empty<string_view>;
auto config_git_hash_id() noexcept -> valid_if_not_empty<string_view>;
auto config_git_date() noexcept -> valid_if_not_empty<string_view>;
auto config_git_describe() noexcept -> valid_if_not_empty<string_view>;
auto config_git_version() noexcept -> valid_if_not_empty<string_view>;
auto config_git_version_major() noexcept -> valid_if_nonnegative<int>;
auto config_git_version_minor() noexcept -> valid_if_nonnegative<int>;
auto config_git_version_patch() noexcept -> valid_if_nonnegative<int>;
auto config_git_version_commit() noexcept -> valid_if_nonnegative<int>;
auto config_git_version_tuple() noexcept
  -> optionally_valid<std::tuple<int, int, int, int>>;

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/git_info.inl>
#endif

#endif // EAGINE_GIT_INFO_HPP
