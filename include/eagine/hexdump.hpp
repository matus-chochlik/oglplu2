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

#include "callable_ref.hpp"
#include "config/basic.hpp"
#include "memory/block.hpp"
#include "types.hpp"
#include "valid_if/decl.hpp"
#include <iosfwd>

namespace eagine {

class hexdump {
private:
    memory::const_block _mb;

public:
    hexdump(memory::const_block mb) noexcept
      : _mb(mb) {
    }

    using byte_getter = callable_ref<optionally_valid<byte>()>;
    using char_putter = callable_ref<bool(char)>;

    static void apply(byte_getter get_byte, char_putter put_char);

    friend std::ostream& operator<<(std::ostream&, const hexdump&);
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/hexdump.inl>
#endif

#endif // EAGINE_HEXDUMP_HPP
