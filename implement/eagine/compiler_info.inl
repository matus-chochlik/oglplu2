/**
 *  @file eagine/compiler_info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_name() noexcept -> valid_if_not_empty<string_view> {
#if defined(__clang__)
    return {{"Clang"}};
#elif defined(__GNUC__)
    return {{"GCC"}};
#endif
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_version_major() noexcept -> valid_if_nonnegative<int> {
#if defined(__clang_major__)
    return {__clang_major__};
#elif defined(__GNUC__)
    return {__GNUC__};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_version_minor() noexcept -> valid_if_nonnegative<int> {
#if defined(__clang_minor__)
    return {__clang_minor__};
#elif defined(__GNUC_MINOR__)
    return {__GNUC_MINOR__};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_version_patch() noexcept -> valid_if_nonnegative<int> {
#if defined(__clang_patchlevel__)
    return {__clang_patchlevel__};
#elif defined(__GNUC_PATCHLEVEL__)
    return {__GNUC_PATCHLEVEL__};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
} // namespace eagine
