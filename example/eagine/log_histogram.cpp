/**
 *  @example eagine/ssh/002_hash_self.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/file_contents.hpp>
#include <eagine/identifier_ctr.hpp>
#include <eagine/main.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/types.hpp>

#include <array>

namespace eagine {
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {

    file_contents content_of_self{ctx.exe_path()};
    memory::const_block data{content_of_self};

    std::array<span_size_t, 256> byte_counts{};
    zero(cover(byte_counts));

    span_size_t max_count{0};
    for(auto b : data) {
        max_count = math::maximum(max_count, ++byte_counts[std_size(b)]);
    }

    ctx.log()
      .info("byte histogram")
      .arg_func([max_count, &byte_counts](logger_backend& backend) {
          for(std::size_t i = 0; i < 256; ++i) {
              backend.add_float(
                byte_to_identifier(i),
                EAGINE_ID(Histogram),
                float(0),
                float(byte_counts[i]),
                float(max_count));
          }
      });

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

