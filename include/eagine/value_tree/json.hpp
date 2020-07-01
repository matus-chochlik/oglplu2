/**
 *  @file eagine/value_tree/json.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_TREE_JSON_HPP
#define EAGINE_VALUE_TREE_JSON_HPP

#include "../config/basic.hpp"
#include "../logging/fwd.hpp"
#include "wrappers.hpp"

namespace eagine::valtree {
//------------------------------------------------------------------------------
compound from_json_text(string_view, logger&);
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/json.inl>
#endif

#endif // EAGINE_VALUE_TREE_JSON_HPP

