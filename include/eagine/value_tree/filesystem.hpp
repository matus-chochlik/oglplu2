/**
 *  @file eagine/value_tree/filesystem.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_TREE_FILESYSTEM_HPP
#define EAGINE_VALUE_TREE_FILESYSTEM_HPP

#include "../config/basic.hpp"
#include "../logging/fwd.hpp"
#include "wrappers.hpp"

namespace eagine::valtree {
//------------------------------------------------------------------------------
auto from_filesystem_path(string_view, logger&) -> compound;
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/filesystem.inl>
#endif

#endif // EAGINE_VALUE_TREE_FILESYSTEM_HPP
