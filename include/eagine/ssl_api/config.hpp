/**
 *  @file eagine/ssl_api/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_CONFIG_HPP
#define EAGINE_SSL_API_CONFIG_HPP

#include "../config/basic.hpp"
#include <eagine/maybe_unused.hpp>

#ifndef EAGINE_HAS_SSL
#if defined(OPENSSL_VERSION_NUMBER)
#define EAGINE_HAS_SSL 1
#else
#define EAGINE_HAS_SSL 0
#endif
#endif // EAGINE_HAS_SSL

#if !EAGINE_HAS_SSL
#include <eagine/nothing.hpp>
#endif

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
struct ssl_types {
#if EAGINE_HAS_SSL
    static constexpr bool has_api = true;
    using engine_type = ::ENGINE;
    using bio_method_type = ::BIO_METHOD;
    using bio_type = ::BIO;
    using evp_pkey_ctx_type = ::EVP_PKEY_CTX;
    using evp_pkey_type = ::EVP_PKEY;
    using evp_cipher_ctx_type = ::EVP_CIPHER_CTX;
    using evp_cipher_type = ::EVP_CIPHER;
    using evp_md_ctx_type = ::EVP_MD_CTX;
    using evp_md_type = ::EVP_MD;
#else
    static constexpr bool has_api = false;
    using engine_type = nothing_t;
    using bio_method_type = nothing_t;
    using bio_type = nothing_t;
    using evp_pkey_ctx_type = nothing_t;
    using evp_pkey_type = nothing_t;
    using evp_cipher_ctx_type = nothing_t;
    using evp_cipher_type = nothing_t;
    using evp_md_ctx_type = nothing_t;
    using evp_md_type = nothing_t;
#endif
};
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_CONFIG_HPP

