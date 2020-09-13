/**
 *  @example eagine/ssh/003_verify_cert.cpp
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

    string_view cert_path{"example.crt"};
    file_contents cert_pem{cert_path};

    sslp::ssl_api ssl{};

    if(ok cert{ssl.parse_x509(cert_pem, {})}) {
        auto del_cert{ssl.delete_x509.raii(cert)};

        if(ssl.ca_verify_certificate("example-ca.crt", cert)) {
            ctx.log()
              .info("successfully verified certificate ${certPath}")
              .arg(EAGINE_ID(certPath), EAGINE_ID(FsPath), cert_path);
        } else {
            ctx.log()
              .error("failed to verify certificate ${certPath}")
              .arg(EAGINE_ID(certPath), EAGINE_ID(FsPath), cert_path);
        }
    } else {
        ctx.log()
          .error("failed to load certificate ${certPath}")
          .arg(EAGINE_ID(certPath), EAGINE_ID(FsPath), cert_path);
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
