/**
 *  @file eagine/valid_if/io.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_IO_HPP
#define EAGINE_VALID_IF_IO_HPP

#include "base.hpp"
#include <iosfwd>

namespace eagine {

template <typename T, typename P, typename L>
std::ostream& operator<<(std::ostream& out, const basic_valid_if<T, P, L>& v) {
    if(v.is_valid()) {
        return out << v.value_anyway();
    }
    return out << "∅";
}

} // namespace eagine

#endif // EAGINE_VALID_IF_IO_HPP
