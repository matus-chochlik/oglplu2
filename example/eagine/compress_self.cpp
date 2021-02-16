/// @example eagine/compress_self.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/file_contents.hpp>
#include <eagine/main.hpp>

#include <eagine/compression.hpp>

namespace eagine {
//------------------------------------------------------------------------------
static inline void
pack_unpack(main_ctx& ctx, data_compressor& comp, memory::const_block original) {
    ctx.log()
      .info("original size ${original}")
      .arg(EAGINE_ID(original), EAGINE_ID(ByteSize), original.size());

    memory::buffer buf1{};
    const auto level = data_compression_level::highest;

    if(auto packed{comp.compress(original, buf1, level)}) {

        ctx.log()
          .info("packed size ${packed}")
          .arg(EAGINE_ID(packed), EAGINE_ID(ByteSize), packed.size());

        memory::buffer buf2{};

        if(auto unpacked{comp.decompress(packed, buf2)}) {

            ctx.log()
              .info("unpacked size ${unpacked}")
              .arg(EAGINE_ID(unpacked), EAGINE_ID(ByteSize), unpacked.size());

            if(are_equal(original, unpacked)) {
                const auto compr_ratio =
                  float(packed.size()) / float(unpacked.size());
                ctx.log()
                  .info("original and unpacked block are equal")
                  .arg(EAGINE_ID(comprRatio), EAGINE_ID(Ratio), compr_ratio);
            } else {
                ctx.log().error("original and unpacked block are different");
            }
        } else {
            ctx.log().error("failed to unpack memory block");
        }
    } else {
        ctx.log().error("failed to pack memory block");
    }
}
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {

    data_compressor comp{};
    if(file_contents self{ctx.exe_path()}) {
        pack_unpack(ctx, comp, self);
    }
    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
