/**
 *  @file eagine/input_data.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_INPUT_DATA_1408161720_HPP
#define EAGINE_INPUT_DATA_1408161720_HPP

#include "config/basic.hpp"
#include "memory/buffer.hpp"
#include "cstr_ref.hpp"
#include <iosfwd>
#include <vector>

namespace eagine {

void read_stream_data(std::istream&, memory::buffer& dest);
void read_file_data(const cstr_ref& path, memory::buffer& dest);

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/input_data.inl>
#endif

#endif //include guard

