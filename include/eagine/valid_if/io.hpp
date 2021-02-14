/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_IO_HPP
#define EAGINE_VALID_IF_IO_HPP

#include "base.hpp"
#include <iosfwd>

namespace eagine {

/// @brief Operator for writing values of basic_valid_if to output streams.
/// @ingroup valid_if
template <typename T, typename P, typename L>
auto operator<<(std::ostream& out, const basic_valid_if<T, P, L>& v) -> auto& {
    if(v.is_valid()) {
        return out << v.value_anyway();
    }
    return out << "∅";
}

} // namespace eagine

#endif // EAGINE_VALID_IF_IO_HPP
