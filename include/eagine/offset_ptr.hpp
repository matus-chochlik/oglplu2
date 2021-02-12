/// @file eagine/offset_ptr.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_OFFSET_PTR_HPP
#define EAGINE_OFFSET_PTR_HPP

#include "memory/offset_ptr.hpp"

namespace eagine {
//------------------------------------------------------------------------------
using memory::basic_offset_ptr;
//------------------------------------------------------------------------------
template <typename Pointee>
using offset_ptr = basic_offset_ptr<Pointee, std::ptrdiff_t>;
//------------------------------------------------------------------------------
template <typename Pointee>
using short_offset_ptr = basic_offset_ptr<Pointee, short>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_OFFSET_PTR_HPP
