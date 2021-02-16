/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SELECTOR_HPP
#define EAGINE_SELECTOR_HPP

#include "identifier_t.hpp"

namespace eagine {

/// @brief Template used to construct tag-types used mostly in tag-dispatching.
/// @ingroup metaprogramming
/// @see default_selector
/// @see construct_from
template <identifier_t V>
struct selector {
    static constexpr const identifier_t value = V;
    using type = selector;
};

/// @brief Type alias for the default overload selector type.
/// @ingroup metaprogramming
/// @see default_selector
using default_selector_t = selector<0U>;

/// @brief The default overload selector constant.
/// @ingroup metaprogramming
/// @see default_selector_t
constexpr const default_selector_t default_selector = {};

/// @brief Type alias for the construct-from tag-dispatch selector.
/// @ingroup metaprogramming
/// @see construct_from
///
/// This type is typically used as an additional parameter in templated
/// constructors to avoid conflicts with copy/move constructors.
using construct_from_t = selector<0xFU>;

/// @brief The construct-from tag-dispatch constant.
/// @ingroup metaprogramming
/// @see construct_from_t
constexpr const construct_from_t construct_from = {};

} // namespace eagine

#endif // EAGINE_SELECTOR_HPP
