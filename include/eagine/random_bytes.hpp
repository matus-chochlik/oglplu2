/**
 *  @file eagine/random_bytes.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_RANDOM_BYTES_HPP
#define EAGINE_RANDOM_BYTES_HPP

#include "span.hpp"

namespace eagine {

void fill_with_random_bytes(span<unsigned char> buffer);

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/random_bytes.inl>
#endif

#endif // EAGINE_RANDOM_BYTES_HPP
