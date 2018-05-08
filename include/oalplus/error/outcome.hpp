/**
 *  @file oalplus/error/outcome.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OALPLUS_ERROR_OUTCOME_1509260923_HPP
#define OALPLUS_ERROR_OUTCOME_1509260923_HPP

#include "../utils/outcome.hpp"
#include "handling.hpp"

namespace oalplus {

template <typename T>
using outcome = basic_outcome<T, error_info, al_error_handling_policy>;

} // namespace oalplus

#endif // include guard
