/**
 *  @file oglplus/utils/nothing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_NOTHING_1509260923_HPP
#define OGLPLUS_UTILS_NOTHING_1509260923_HPP

namespace oglplus {

struct nothing_t
{
	typedef nothing_t type;
};

static constexpr nothing_t nothing = {};

} // namespace oglplus

#endif // include guard
