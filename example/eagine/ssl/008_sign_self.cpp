/// @example eagine/ssh/008_sign_self.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/logging/logger.hpp>
#include <eagine/main.hpp>

#include <eagine/embed.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/ssl.hpp>
#include <eagine/ssl_api.hpp>

#include <array>

namespace eagine {
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    auto& log = ctx.log();
    file_contents data(ctx.exe_path());
    std::array<byte, 1024> temp{};

    string_view engine_id("pkcs11");
    if(auto arg{ctx.args().find("--engine").next()}) {
        engine_id = arg;
    }

    string_view key_id("pkcs11:token=user;object=user;");
    if(auto arg{ctx.args().find("--key").next()}) {
        key_id = arg;
    }

    sslp::ssl_api ssl{};

    ssl.load_builtin_engines();

    if(ok engine{ssl.open_engine(engine_id)}) {
        auto del_eng{ssl.delete_engine.raii(engine)};

        if(auto init_result{ssl.init_engine(engine)}) {
            auto fin_eng{ssl.finish_engine.raii(engine)};

            if(ok pkey{ssl.load_engine_private_key(
                 engine, key_id, ok{ssl.openssl_ui()})}) {
                auto del_pkey{ssl.delete_pkey.raii(pkey)};

                if(ok md{ssl.message_digest_sha256()}) {

                    if(auto sig{
                         ssl.sign_data_digest(data, cover(temp), md, pkey)}) {

                        ctx.log()
                          .info("signature of self")
                          .arg(EAGINE_ID(size), sig.size())
                          .arg(EAGINE_ID(sig), memory::const_block{sig});

                        if(ssl.verify_data_digest(data, sig, md, pkey)) {
                            ctx.log().info("signature verified");
                        } else {
                            log.error("failed to verify data signature")
                              .arg(EAGINE_ID(keyId), key_id)
                              .arg(EAGINE_ID(engineId), engine_id);
                        }
                    } else {
                        log.error("failed to sign data")
                          .arg(EAGINE_ID(keyId), key_id)
                          .arg(EAGINE_ID(engineId), engine_id);
                    }
                } else {
                    log.error("failed to get message digest: ${reason}")
                      .arg(EAGINE_ID(engineId), engine_id)
                      .arg(EAGINE_ID(reason), (!md).message());
                }
            } else {
                log.error("failed to load key ${keyID} from engine: ${reason}")
                  .arg(EAGINE_ID(keyId), key_id)
                  .arg(EAGINE_ID(engineId), engine_id)
                  .arg(EAGINE_ID(reason), (!pkey).message());
            }

        } else {
            log.error("failed to init ssl engine ${engineId}: ${reason}")
              .arg(EAGINE_ID(engineId), engine_id)
              .arg(EAGINE_ID(reason), init_result.message());
        }
    } else {
        log.error("failed to open ssl engine ${engineId}")
          .arg(EAGINE_ID(engineId), engine_id);
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
