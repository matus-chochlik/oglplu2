/**
 *  @file eagine/valid_if/size_gt.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_SIZE_GT_1509260923_HPP
#define EAGINE_VALID_IF_SIZE_GT_1509260923_HPP

#include "in_class.hpp"

namespace eagine {

// valid if less than container.size()
template <typename C, typename T>
struct valid_if_size_gt_policy {
    bool operator()(const C& c, T s) const {
	return c.size() > s;
    }

    struct do_log {
	template <typename X>
	constexpr inline do_log(X&&) noexcept {
	}

	template <typename Log>
	void operator()(Log& log, const C& c, const T& s) const {
	    log << "Size " << c.size() << ", "
		<< "not greater than value " << s << " is invalid";
	}
    };
};

template <typename C, typename T>
using valid_if_size_gt = in_class_valid_if<C, T, valid_if_size_gt_policy<C, T>>;

} // namespace eagine

#endif // include guard
