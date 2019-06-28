/**
 *  @file eagine/type_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPE_TRAITS_HPP
#define EAGINE_TYPE_TRAITS_HPP

#include <type_traits>

namespace eagine {

template <typename X, typename Match>
using disable_if_same_t = std::enable_if_t<
  !std::is_same_v<std::remove_cv_t<std::remove_reference_t<X>>, Match>>;

} // namespace eagine

#endif // EAGINE_TYPE_TRAITS_HPP
