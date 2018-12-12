/**
 *  @file eagine/bindump.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BINDUMP_1509260923_HPP
#define EAGINE_BINDUMP_1509260923_HPP

#include "config/basic.hpp"
#include "memory/block.hpp"
#include "types.hpp"
#include <iosfwd>

namespace eagine {

class bindump {
private:
    memory::const_block _mb;
    bool _offs;

    static void _to_bin_b(std::ostream& out, byte b);

public:
    bindump(memory::const_block mb, bool offs = true) noexcept
      : _mb(mb)
      , _offs(offs) {
    }

    friend std::ostream& operator<<(std::ostream&, const bindump&);
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/bindump.inl>
#endif

#endif // include guard
