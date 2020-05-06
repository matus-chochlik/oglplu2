/**
 *  @file eagine/ssl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_C_API_HPP
#define EAGINE_SSL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef EAGINE_SSL_STATIC_FUNC
#if EAGINE_HAS_SSL
#define EAGINE_SSL_STATIC_FUNC(NAME) &::NAME
#else
#define EAGINE_SSL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_ssl_c_api {

    using this_api = basic_ssl_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = ssl_types::has_api;
    using engine_type = ssl_types::engine_type;
    using bio_method_type = ssl_types::bio_method_type;
    using bio_type = ssl_types::bio_type;
    using evp_pkey_ctx_type = ssl_types::evp_pkey_ctx_type;
    using evp_pkey_type = ssl_types::evp_pkey_type;
    using evp_cipher_ctx_type = ssl_types::evp_cipher_ctx_type;
    using evp_cipher_type = ssl_types::evp_cipher_type;
    using evp_md_ctx_type = ssl_types::evp_md_ctx_type;
    using evp_md_type = ssl_types::evp_md_type;

    using passwd_callback_type = int(char*, int, int, void*);

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using ssl_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    ssl_api_function<unsigned long(), EAGINE_SSL_STATIC_FUNC(ERR_get_error)>
      err_get_error;

    ssl_api_function<unsigned long(), EAGINE_SSL_STATIC_FUNC(ERR_peek_error)>
      err_peek_error;

    ssl_api_function<
      void(unsigned long, char*, size_t),
      EAGINE_SSL_STATIC_FUNC(ERR_error_string_n)>
      err_error_string_n;

    ssl_api_function<
      bio_type*(const bio_method_type*),
      EAGINE_SSL_STATIC_FUNC(BIO_new)>
      bio_new;

    ssl_api_function<
      bio_type*(const void*, int),
      EAGINE_SSL_STATIC_FUNC(BIO_new_mem_buf)>
      bio_new_mem_buf;

    ssl_api_function<int(bio_type*), EAGINE_SSL_STATIC_FUNC(BIO_up_ref)>
      bio_up_ref;

    ssl_api_function<int(bio_type*), EAGINE_SSL_STATIC_FUNC(BIO_free)> bio_free;

    ssl_api_function<void(bio_type*), EAGINE_SSL_STATIC_FUNC(BIO_free_all)>
      bio_free_all;

    ssl_api_function<
      evp_pkey_type*(bio_type*, evp_pkey_type**, passwd_callback_type*, void*),
      EAGINE_SSL_STATIC_FUNC(PEM_read_bio_PrivateKey)>
      pem_read_bio_private_key;

    ssl_api_function<
      evp_pkey_type*(bio_type*, evp_pkey_type**, passwd_callback_type*, void*),
      EAGINE_SSL_STATIC_FUNC(PEM_read_bio_PUBKEY)>
      pem_read_bio_pubkey;

    ssl_api_function<evp_pkey_type*(), EAGINE_SSL_STATIC_FUNC(EVP_PKEY_new)>
      evp_pkey_new;

    ssl_api_function<
      int(evp_pkey_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_PKEY_up_ref)>
      evp_pkey_up_ref;

    ssl_api_function<
      void(evp_pkey_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_PKEY_free)>
      evp_pkey_free;

    ssl_api_function<
      const evp_cipher_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_aes_128_ctr)>
      evp_aes_128_ctr;

    ssl_api_function<
      const evp_cipher_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_aes_128_ccm)>
      evp_aes_128_ccm;

    ssl_api_function<
      const evp_cipher_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_aes_128_gcm)>
      evp_aes_128_gcm;

    ssl_api_function<
      const evp_cipher_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_aes_128_xts)>
      evp_aes_128_xts;

    ssl_api_function<
      const evp_cipher_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_aes_192_ecb)>
      evp_aes_192_ecb;

    ssl_api_function<
      const evp_cipher_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_aes_192_cbc)>
      evp_aes_192_cbc;

    ssl_api_function<
      evp_cipher_ctx_type*(),
      EAGINE_SSL_STATIC_FUNC(EVP_CIPHER_CTX_new)>
      evp_cipher_ctx_new;

    ssl_api_function<
      int(evp_cipher_ctx_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_CIPHER_CTX_reset)>
      evp_cipher_ctx_reset;

    ssl_api_function<
      void(evp_cipher_ctx_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_CIPHER_CTX_free)>
      evp_cipher_ctx_free;

    ssl_api_function<
      int(
        evp_cipher_ctx_type*,
        const evp_cipher_type*,
        const unsigned char*,
        const unsigned char*,
        int),
      EAGINE_SSL_STATIC_FUNC(EVP_CipherInit)>
      evp_cipher_init;

    ssl_api_function<
      int(
        evp_cipher_ctx_type*,
        const evp_cipher_type*,
        engine_type*,
        const unsigned char*,
        const unsigned char*,
        int),
      EAGINE_SSL_STATIC_FUNC(EVP_CipherInit_ex)>
      evp_cipher_init_ex;

    ssl_api_function<
      int(
        evp_cipher_ctx_type*, unsigned char*, int*, const unsigned char*, int),
      EAGINE_SSL_STATIC_FUNC(EVP_CipherUpdate)>
      evp_cipher_update;

    ssl_api_function<
      int(evp_cipher_ctx_type*, unsigned char*, int*),
      EAGINE_SSL_STATIC_FUNC(EVP_CipherFinal_ex)>
      evp_cipher_final;

    ssl_api_function<
      int(evp_cipher_ctx_type*, unsigned char*, int*),
      EAGINE_SSL_STATIC_FUNC(EVP_CipherFinal_ex)>
      evp_cipher_final_ex;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_md_null)>
      evp_md_null;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_md5)>
      evp_md5;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_sha1)>
      evp_sha1;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_sha224)>
      evp_sha224;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_sha256)>
      evp_sha256;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_sha384)>
      evp_sha384;

    ssl_api_function<const evp_md_type*(), EAGINE_SSL_STATIC_FUNC(EVP_sha512)>
      evp_sha512;

    ssl_api_function<
      const evp_md_type*(const char*),
      EAGINE_SSL_STATIC_FUNC(EVP_get_digestbyname)>
      evp_get_digest_by_name;

    ssl_api_function<
      int(const evp_md_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_MD_size)>
      evp_md_size;

    ssl_api_function<
      int(const evp_md_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_MD_block_size)>
      evp_md_block_size;

    ssl_api_function<evp_md_ctx_type*(), EAGINE_SSL_STATIC_FUNC(EVP_MD_CTX_new)>
      evp_md_ctx_new;

    ssl_api_function<
      int(evp_md_ctx_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_MD_CTX_reset)>
      evp_md_ctx_reset;

    ssl_api_function<
      void(evp_md_ctx_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_MD_CTX_free)>
      evp_md_ctx_free;

    ssl_api_function<
      int(evp_md_ctx_type*, const evp_md_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestInit)>
      evp_digest_init;

    ssl_api_function<
      int(evp_md_ctx_type*, const evp_md_type*, engine_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestInit_ex)>
      evp_digest_init_ex;

    ssl_api_function<
      int(evp_md_ctx_type*, const void*, size_t),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestUpdate)>
      evp_digest_update;

    ssl_api_function<
      int(evp_md_ctx_type*, unsigned char*, unsigned int*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestFinal_ex)>
      evp_digest_final;

    ssl_api_function<
      int(evp_md_ctx_type*, unsigned char*, unsigned int*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestFinal_ex)>
      evp_digest_final_ex;

    ssl_api_function<
      int(
        evp_md_ctx_type*,
        evp_pkey_ctx_type**,
        const evp_md_type*,
        engine_type*,
        evp_pkey_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestSignInit)>
      evp_digest_sign_init;

    ssl_api_function<
      int(evp_md_ctx_type*, const void*, size_t),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestUpdate)>
      evp_digest_sign_update;

    ssl_api_function<
      int(evp_md_ctx_type*, unsigned char*, size_t*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestSignFinal)>
      evp_digest_sign_final;

    ssl_api_function<
      int(
        evp_md_ctx_type*,
        evp_pkey_ctx_type**,
        const evp_md_type*,
        engine_type*,
        evp_pkey_type*),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestVerifyInit)>
      evp_digest_verify_init;

    ssl_api_function<
      int(evp_md_ctx_type*, const void*, size_t),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestUpdate)>
      evp_digest_verify_update;

    ssl_api_function<
      int(evp_md_ctx_type*, const unsigned char*, size_t),
      EAGINE_SSL_STATIC_FUNC(EVP_DigestVerifyFinal)>
      evp_digest_verify_final;

    constexpr basic_ssl_c_api(api_traits& traits)
      : err_get_error("ERR_get_error", traits, *this)
      , err_peek_error("ERR_peek_error", traits, *this)
      , err_error_string_n("ERR_error_string_n", traits, *this)
      , bio_new("BIO_new", traits, *this)
      , bio_new_mem_buf("BIO_new_mem_buf", traits, *this)
      , bio_up_ref("BIO_up_ref", traits, *this)
      , bio_free("BIO_free", traits, *this)
      , bio_free_all("BIO_free_all", traits, *this)
      , pem_read_bio_private_key("pem_read_bio_private_key", traits, *this)
      , pem_read_bio_pubkey("pem_read_bio_pubkey", traits, *this)
      , evp_pkey_new("EVP_PKEY_new", traits, *this)
      , evp_pkey_up_ref("EVP_PKEY_up_ref", traits, *this)
      , evp_pkey_free("EVP_PKEY_free", traits, *this)
      , evp_aes_128_ctr("evp_aes_128_ctr", traits, *this)
      , evp_aes_128_ccm("evp_aes_128_ccm", traits, *this)
      , evp_aes_128_gcm("evp_aes_128_gcm", traits, *this)
      , evp_aes_128_xts("evp_aes_128_xts", traits, *this)
      , evp_aes_192_ecb("evp_aes_192_ecb", traits, *this)
      , evp_aes_192_cbc("evp_aes_192_cbc", traits, *this)
      , evp_cipher_ctx_new("EVP_CIPHER_CTX_new", traits, *this)
      , evp_cipher_ctx_reset("EVP_CIPHER_CTX_reset", traits, *this)
      , evp_cipher_ctx_free("EVP_CIPHER_CTX_free", traits, *this)
      , evp_cipher_init("EVP_CipherInit", traits, *this)
      , evp_cipher_init_ex("EVP_CipherInit_ex", traits, *this)
      , evp_cipher_update("EVP_CipherUpdate", traits, *this)
      , evp_cipher_final("EVP_CipherFinal", traits, *this)
      , evp_cipher_final_ex("EVP_CipherFinal_ex", traits, *this)
      , evp_md_null("EVP_md_null", traits, *this)
      , evp_md5("EVP_md5", traits, *this)
      , evp_sha1("EVP_sha1", traits, *this)
      , evp_sha224("EVP_sha224", traits, *this)
      , evp_sha256("EVP_sha256", traits, *this)
      , evp_sha384("EVP_sha384", traits, *this)
      , evp_sha512("EVP_sha512", traits, *this)
      , evp_get_digest_by_name("EVP_get_digestbyname", traits, *this)
      , evp_md_size("EVP_MD_size", traits, *this)
      , evp_md_block_size("EVP_MD_block_size", traits, *this)
      , evp_md_ctx_new("EVP_MD_CTX_new", traits, *this)
      , evp_md_ctx_reset("EVP_MD_CTX_reset", traits, *this)
      , evp_md_ctx_free("EVP_MD_CTX_free", traits, *this)
      , evp_digest_init("EVP_DigestInit", traits, *this)
      , evp_digest_init_ex("EVP_DigestInit_ex", traits, *this)
      , evp_digest_update("EVP_DigestUpdate", traits, *this)
      , evp_digest_final("EVP_DigestFinal", traits, *this)
      , evp_digest_final_ex("EVP_DigestFinal_ex", traits, *this)
      , evp_digest_sign_init("EVP_DigestSignInit", traits, *this)
      , evp_digest_sign_update("EVP_DigestSignUpdate", traits, *this)
      , evp_digest_sign_final("EVP_DigestSignFinal", traits, *this)
      , evp_digest_verify_init("EVP_DigestVerifyInit", traits, *this)
      , evp_digest_verify_update("EVP_DigestVerifyUpdate", traits, *this)
      , evp_digest_verify_final("EVP_DigestVerifyFinal", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using ssl_c_api = basic_ssl_c_api<ssl_api_traits>;
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif
