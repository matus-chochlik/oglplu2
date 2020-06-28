/**
 *  @example eagine/ssh/005_random_engine.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>

#include <eagine/ssl.hpp>
#include <eagine/ssl_api.hpp>

#include <array>

namespace eagine {
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {

    auto& log = ctx.log();
    sslp::ssl_api ssl{};

    string_view engine_id("rdrand");

    ssl.load_builtin_engines();

    if(ok engine = ssl.open_engine(engine_id)) {
        auto del_eng = ssl.delete_engine.raii(engine);

        if(auto init_result = ssl.init_engine(engine)) {
            auto fin_eng = ssl.finish_engine.raii(engine);

            if(auto set_result = ssl.set_default_rand(engine)) {
                std::array<byte, 256> temp{};
                if(auto rand_result = ssl.random_bytes(cover(temp))) {
                    log.info("got ${size} random bytes from ${id}")
                      .arg(EAGINE_ID(size), temp.size())
                      .arg(EAGINE_ID(id), engine_id)
                      .arg(EAGINE_ID(bytes), view(temp));
                } else {
                    log
                      .error("failed to get random bytes from ${id}: ${reason}")
                      .arg(EAGINE_ID(id), engine_id)
                      .arg(EAGINE_ID(reason), rand_result.message());
                }
            } else {
                log.error("failed to set ${id} as random engine: ${reason}")
                  .arg(EAGINE_ID(id), engine_id)
                  .arg(EAGINE_ID(reason), set_result.message());
            }
        } else {
            log.error("failed to init ssl engine ${id}: ${reason}")
              .arg(EAGINE_ID(id), engine_id)
              .arg(EAGINE_ID(reason), init_result.message());
        }
    } else {
        log.error("failed to open ssl engine ${id}")
          .arg(EAGINE_ID(id), engine_id);
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

