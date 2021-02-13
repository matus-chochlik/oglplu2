/// @file eagine/memory/flatten_fwd.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_FLATTEN_FWD_HPP
#define EAGINE_MEMORY_FLATTEN_FWD_HPP

namespace eagine {
namespace memory {

template <typename ValueType, typename Pointer, typename SizeType>
class basic_span;

} // namespace memory

template <typename Src, typename Dst>
struct flatten_traits;

} // namespace eagine

#endif // EAGINE_MEMORY_FLATTEN_FWD_HPP
