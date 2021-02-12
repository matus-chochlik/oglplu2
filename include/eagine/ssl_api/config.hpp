/// @file eagine/ssl_api/config.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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

namespace eagine::sslp {
//------------------------------------------------------------------------------
struct ssl_types {
#if EAGINE_HAS_SSL
    static constexpr bool has_api = true;
    using ui_method_type = ::UI_METHOD;
    using engine_type = ::ENGINE;
    using bio_method_type = ::BIO_METHOD;
    using bio_type = ::BIO;
    using evp_pkey_ctx_type = ::EVP_PKEY_CTX;
    using evp_pkey_type = ::EVP_PKEY;
    using evp_cipher_ctx_type = ::EVP_CIPHER_CTX;
    using evp_cipher_type = ::EVP_CIPHER;
    using evp_md_ctx_type = ::EVP_MD_CTX;
    using evp_md_type = ::EVP_MD;
    using x509_lookup_method_type = ::X509_LOOKUP_METHOD;
    using x509_lookup_type = ::X509_LOOKUP;
    using x509_store_ctx_type = ::X509_STORE_CTX;
    using x509_store_type = ::X509_STORE;
    using x509_crl_type = ::X509_CRL;
    using x509_type = ::X509;
    using x509_stack_type = STACK_OF(X509);
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
    using x509_lookup_method_type = nothing_t;
    using x509_lookup_type = nothing_t;
    using x509_store_ctx_type = nothing_t;
    using x509_store_type = nothing_t;
    using x509_crl_type = nothing_t;
    using x509_type = nothing_t;
    using x509_stack_type = nothing_t;
#endif
};
//------------------------------------------------------------------------------
} // namespace eagine::sslp

#endif // EAGINE_SSL_API_CONFIG_HPP
