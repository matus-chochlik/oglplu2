/**
 *  @file eagine/base64dump.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BASE64DUMP_HPP
#define EAGINE_BASE64DUMP_HPP

#include "base64.hpp"
#include "callable_ref.hpp"
#include "memory/block.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class base64dump {
private:
    memory::const_block _mb;

public:
    base64dump(memory::const_block mb) noexcept
      : _mb(mb) {
    }

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
};
//------------------------------------------------------------------------------
} // namespace eagine
#endif // EAGINE_BASE64DUMP_HPP

