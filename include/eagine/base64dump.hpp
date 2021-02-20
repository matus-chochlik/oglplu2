/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_BASE64DUMP_HPP
#define EAGINE_BASE64DUMP_HPP

#include "base64.hpp"
#include "callable_ref.hpp"
#include "memory/block.hpp"

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Class for encoding byte blocks into base64 format.
/// @ingroup logging
/// @see bindump
/// @see hexdump
///
/// This class stores a memory block and can be used to write the content of the
/// block into an standard output stream in base64-encoding.
class base64dump {
public:
    /// @brief Construction initializing the dumped memory block.
    base64dump(memory::const_block mb) noexcept
      : _mb{mb} {}

    /// @brief Operator for writing instances of base64dump to standard output streams.
    friend auto operator<<(std::ostream& out, const base64dump& src)
      -> std::ostream& {
        span_size_t i = 0;
        do_dissolve_bits(
          make_span_getter(i, src._mb),
          [&out](byte b) {
              if(auto opt_c = make_base64_encode_transform()(b)) {
                  out << extract(opt_c);
                  return true;
              }
              return false;
          },
          6);
        return out;
    }

private:
    memory::const_block _mb;
};
//------------------------------------------------------------------------------
} // namespace eagine
#endif // EAGINE_BASE64DUMP_HPP
