/**
 *  @file eagine/ossl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_C_API_HPP
#define EAGINE_OSSL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef EAGINE_OSSL_STATIC_FUNC
#if EAGINE_HAS_OSSL
#define EAGINE_OSSL_STATIC_FUNC(NAME) &::NAME
#else
#define EAGINE_OSSL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_ossl_c_api {

    using this_api = basic_ossl_c_api;
    using api_traits = Traits;

    static constexpr bool has_api = ossl_types::has_api;
    using engine_type = ossl_types::engine_type;
    using evp_md_ctx_type = ossl_types::evp_md_ctx_type;
    using evp_md_type = ossl_types::evp_md_type;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using ossl_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

    ossl_api_function<unsigned long(), EAGINE_OSSL_STATIC_FUNC(ERR_get_error)>
      err_get_error;

    ossl_api_function<unsigned long(), EAGINE_OSSL_STATIC_FUNC(ERR_peek_error)>
      err_peek_error;

    ossl_api_function<
      void(unsigned long, char*, size_t),
      EAGINE_OSSL_STATIC_FUNC(ERR_error_string_n)>
      err_error_string_n;

    ossl_api_function<
      const evp_md_type*(),
      EAGINE_OSSL_STATIC_FUNC(EVP_md_null)>
      evp_md_null;

    ossl_api_function<const evp_md_type*(), EAGINE_OSSL_STATIC_FUNC(EVP_md5)>
      evp_md5;

    ossl_api_function<const evp_md_type*(), EAGINE_OSSL_STATIC_FUNC(EVP_sha1)>
      evp_sha1;

    ossl_api_function<const evp_md_type*(), EAGINE_OSSL_STATIC_FUNC(EVP_sha224)>
      evp_sha224;

    ossl_api_function<const evp_md_type*(), EAGINE_OSSL_STATIC_FUNC(EVP_sha256)>
      evp_sha256;

    ossl_api_function<const evp_md_type*(), EAGINE_OSSL_STATIC_FUNC(EVP_sha384)>
      evp_sha384;

    ossl_api_function<const evp_md_type*(), EAGINE_OSSL_STATIC_FUNC(EVP_sha512)>
      evp_sha512;

    ossl_api_function<
      const evp_md_type*(const char*),
      EAGINE_OSSL_STATIC_FUNC(EVP_get_digestbyname)>
      evp_get_digest_by_name;

    ossl_api_function<
      int(const evp_md_type*),
      EAGINE_OSSL_STATIC_FUNC(EVP_MD_size)>
      evp_md_size;

    ossl_api_function<
      int(const evp_md_type*),
      EAGINE_OSSL_STATIC_FUNC(EVP_MD_block_size)>
      evp_md_block_size;

    ossl_api_function<
      evp_md_ctx_type*(),
      EAGINE_OSSL_STATIC_FUNC(EVP_MD_CTX_new)>
      evp_md_ctx_new;

    ossl_api_function<
      int(evp_md_ctx_type*),
      EAGINE_OSSL_STATIC_FUNC(EVP_MD_CTX_reset)>
      evp_md_ctx_reset;

    ossl_api_function<
      void(evp_md_ctx_type*),
      EAGINE_OSSL_STATIC_FUNC(EVP_MD_CTX_free)>
      evp_md_ctx_free;

    ossl_api_function<
      int(evp_md_ctx_type*, const evp_md_type*),
      EAGINE_OSSL_STATIC_FUNC(EVP_DigestInit)>
      evp_digest_init;

    ossl_api_function<
      int(evp_md_ctx_type*, const evp_md_type*, engine_type*),
      EAGINE_OSSL_STATIC_FUNC(EVP_DigestInit_ex)>
      evp_digest_init_ex;

    ossl_api_function<
      int(evp_md_ctx_type*, const void*, size_t),
      EAGINE_OSSL_STATIC_FUNC(EVP_DigestUpdate)>
      evp_digest_update;

    ossl_api_function<
      int(evp_md_ctx_type*, unsigned char*, unsigned int*),
      EAGINE_OSSL_STATIC_FUNC(EVP_DigestFinal_ex)>
      evp_digest_final;

    ossl_api_function<
      int(evp_md_ctx_type*, unsigned char*, unsigned int*),
      EAGINE_OSSL_STATIC_FUNC(EVP_DigestFinal_ex)>
      evp_digest_final_ex;

    constexpr basic_ossl_c_api(api_traits& traits)
      : err_get_error("ERR_get_error", traits, *this)
      , err_peek_error("ERR_peek_error", traits, *this)
      , err_error_string_n("ERR_error_string_n", traits, *this)
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
      , evp_digest_final_ex("EVP_DigestFinal_ex", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using ossl_c_api = basic_ossl_c_api<ossl_api_traits>;
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

#endif
