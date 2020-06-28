/**
 *  @file eagine/value_tree/yaml.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_TREE_YAML_HPP
#define EAGINE_VALUE_TREE_YAML_HPP

#include "../config/basic.hpp"
#include "../logging/fwd.hpp"
#include "wrappers.hpp"

namespace eagine {
namespace valtree {
//------------------------------------------------------------------------------
compound from_yaml_text(string_view, logger&);
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/yaml.inl>
#endif

#endif // EAGINE_VALUE_TREE_YAML_HPP

