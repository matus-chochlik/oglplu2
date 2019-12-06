/**
 *  @file eagine/hexdump.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_HEXDUMP_HPP
#define EAGINE_HEXDUMP_HPP

#include "config/basic.hpp"
#include "memory/block.hpp"
#include "types.hpp"
#include <iosfwd>

namespace eagine {

class hexdump {
private:
    memory::const_block _mb;

public:
    hexdump(memory::const_block mb) noexcept
      : _mb(mb) {
    }

    friend std::ostream& operator<<(std::ostream&, const hexdump&);
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/hexdump.inl>
#endif

#endif // EAGINE_HEXDUMP_HPP
