/**
 *  @file eagine/filesystem.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>
#include <eagine/range_algo.hpp>

namespace eagine {
namespace filesystem {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref path_separator(void)
noexcept
{
#if EAGINE_WINDOWS
	return cstr_ref("\\");
#else
	return cstr_ref("/");
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref basename(const cstr_ref& path)
noexcept
{
	return ranges::slice_after_last(
		ranges::strip_suffix(path, path_separator()),
		path_separator()
	);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
cstr_ref dirname(const cstr_ref& path)
noexcept
{
	return ranges::slice_before_last(
		ranges::strip_suffix(path, path_separator()),
		path_separator()
	);
}
//------------------------------------------------------------------------------
} // namespace filesystem
} // namespace eagine
