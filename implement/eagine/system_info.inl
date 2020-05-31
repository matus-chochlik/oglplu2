/**
 *  @file eagine/system_info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#if EAGINE_POSIX
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_positive<span_size_t> system_info::memory_page_size() const noexcept {
#if EAGINE_POSIX
#if defined(_SC_PAGESIZE)
    return {span_size(::sysconf(_SC_PAGESIZE))};
#endif
#endif
    return {0};
}
//------------------------------------------------------------------------------
} // namespace eagine
