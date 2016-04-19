/**
 *  @file eagine/str_var_subst.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STR_VAR_SUBST_1509260923_HPP
#define EAGINE_STR_VAR_SUBST_1509260923_HPP

#include "config/basic.hpp"
#include <cassert>
#include <string>
#include <map>

namespace eagine {

std::string
substitute_variables(
	const std::string& str,
	const std::map<std::string, std::string>& dictionary
);

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/str_var_subst.inl>
#endif

#endif // include guard
