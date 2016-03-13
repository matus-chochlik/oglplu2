/**
 *  @file eagine/filesystem.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FILESYSTEM_1509260923_HPP
#define EAGINE_FILESYSTEM_1509260923_HPP

#include "config/basic.hpp"
#include "cstr_ref.hpp"

namespace eagine {
namespace filesystem {

cstr_ref path_separator(void)
noexcept;

cstr_ref basename(const cstr_ref& path)
noexcept;

cstr_ref dirname(const cstr_ref& path)
noexcept;

} // namespace filesystem
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/filesystem.inl>
#endif

#endif // include guard
