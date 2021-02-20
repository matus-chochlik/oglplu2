/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_BINDUMP_HPP
#define EAGINE_BINDUMP_HPP

#include "callable_ref.hpp"
#include "config/basic.hpp"
#include "memory/block.hpp"
#include "types.hpp"
#include "valid_if/decl.hpp"
#include <iosfwd>

namespace eagine {

/// @brief Class for encoding byte blocks into binary format.
/// @ingroup logging
/// @see hexdump
///
/// This class stores a memory block and can be used to write the content of the
/// block into an standard output stream in binary format.
class bindump {

public:
    /// @brief Construction initializing the dumped memory block.
    bindump(memory::const_block mb) noexcept
      : _mb{mb} {}

    /// @brief Alias for source byte getter callable.
    using byte_getter = callable_ref<optionally_valid<byte>()>;

    /// @brief Alias for destination encoded char putter callable.
    using char_putter = callable_ref<bool(char)>;

    /// @brief Uses get_byte to read input bytes, encodes them and calls put_char.
    static void apply(byte_getter get_byte, char_putter put_char);

    /// @brief Operator for writing instances of bindump to standard output streams.
    friend auto operator<<(std::ostream&, const bindump&) -> std::ostream&;

private:
    memory::const_block _mb;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/bindump.inl>
#endif

#endif // EAGINE_BINDUMP_HPP
