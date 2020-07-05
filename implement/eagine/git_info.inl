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
valid_if_not_empty<string_view> config_git_branch() noexcept {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_BRANCH}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_not_empty<string_view> config_git_hash_id() noexcept {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_HASH_ID}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_not_empty<string_view> config_git_date() noexcept {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_DATE}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_not_empty<string_view> config_git_describe() noexcept {
#if defined(EAGINE_CONFIG_GIT_INFO_HPP)
    return {string_view{EAGINE_GIT_DESCRIBE}};
#else
    return {};
#endif
}
//------------------------------------------------------------------------------
} // namespace eagine
