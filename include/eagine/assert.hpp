/**
 *  @file eagine/assert.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ASSERT_1408161720_HPP
#define EAGINE_ASSERT_1408161720_HPP

#include <cassert>

#define EAGINE_ABORT(MSG) assert(!bool(MSG))
#define EAGINE_UNREACHABLE(MSG) EAGINE_ABORT(MSG)

#endif //include guard

