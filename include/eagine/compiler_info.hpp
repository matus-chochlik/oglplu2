/// @file eagine/compiler_info.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_COMPILER_INFO_HPP
#define EAGINE_COMPILER_INFO_HPP

#include "string_span.hpp"
#include "valid_if/nonnegative.hpp"
#include "valid_if/not_empty.hpp"
#include <tuple>

namespace eagine {

auto compiler_name() noexcept -> valid_if_not_empty<string_view>;
auto compiler_version_major() noexcept -> valid_if_nonnegative<int>;
auto compiler_version_minor() noexcept -> valid_if_nonnegative<int>;
auto compiler_version_patch() noexcept -> valid_if_nonnegative<int>;
auto architecture_name() noexcept -> valid_if_not_empty<string_view>;

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/compiler_info.inl>
#endif

#endif // EAGINE_COMPILER_INFO_HPP
