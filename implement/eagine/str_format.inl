/**
 *  @file eagine/str_format.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/str_var_subst.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::string
format_string_and_list_base::_fmt(const span<const std::string>& values) const {
    return substitute_variables(_fmt_str, values);
}
//------------------------------------------------------------------------------
} // namespace eagine
