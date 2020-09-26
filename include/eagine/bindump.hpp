/**
 *  @file eagine/bindump.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BINDUMP_HPP
#define EAGINE_BINDUMP_HPP

#include "callable_ref.hpp"
#include "config/basic.hpp"
#include "memory/block.hpp"
#include "types.hpp"
#include "valid_if/decl.hpp"
#include <iosfwd>

namespace eagine {

class bindump {
private:
    memory::const_block _mb;

public:
    bindump(memory::const_block mb) noexcept
      : _mb(mb) {}

    using byte_getter = callable_ref<optionally_valid<byte>()>;
    using char_putter = callable_ref<bool(char)>;

    static void apply(byte_getter get_byte, char_putter put_char);

    friend auto operator<<(std::ostream&, const bindump&) -> std::ostream&;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/bindump.inl>
#endif

#endif // EAGINE_BINDUMP_HPP
