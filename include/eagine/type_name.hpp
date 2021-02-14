/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_TYPE_NAME_HPP
#define EAGINE_TYPE_NAME_HPP

#include "config/basic.hpp"

#include <string>
#include <typeinfo>

namespace eagine {

auto demangle_type_name(const char*) noexcept -> std::string;

template <typename T>
static inline auto type_name(const T&) noexcept -> std::string {
    return demangle_type_name(typeid(T).name());
}

template <typename T>
static inline auto type_name() noexcept -> std::string {
    return demangle_type_name(typeid(T).name());
}

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/type_name.inl>
#endif

#endif // EAGINE_TYPE_NAME_HPP
