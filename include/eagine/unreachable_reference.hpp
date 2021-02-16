/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNREACHABLE_REFERENCE_HPP
#define EAGINE_UNREACHABLE_REFERENCE_HPP

#include "assert.hpp"
#include "type_identity.hpp"
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <std::size_t N>
static inline auto unreachable_storage() noexcept {
    static std::aligned_storage_t<N> _storage{};
    return static_cast<void*>(&_storage);
}
//------------------------------------------------------------------------------
template <typename T>
static inline auto unreachable_reference(type_identity<T>) noexcept -> T& {
    EAGINE_UNREACHABLE();
    return *static_cast<T*>(unreachable_storage<sizeof(T)>());
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_UNREACHABLE_REFERENCE_HPP
