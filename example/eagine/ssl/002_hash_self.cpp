/**
 *  @example eagine/ssh/002_hash_self.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/file_contents.hpp>
#include <eagine/main.hpp>

#include <eagine/ssl.hpp>
#include <eagine/ssl_api.hpp>

#include <array>

namespace eagine {
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {
    file_contents data(ctx.args().command());
    std::array<byte, 32> temp{};

    sslp::ssl_api ssl{};

    memory::const_block hash = ssl.sha256_digest(data, cover(temp));

    ctx.log()
      .info("hash of self")
      .arg(EAGINE_ID(data), data)
      .arg(EAGINE_ID(hash), hash);

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

