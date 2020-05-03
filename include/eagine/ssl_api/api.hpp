/**
 *  @file eagine/ssl_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_API_HPP
#define EAGINE_SSL_API_API_HPP

#include "c_api.hpp"
#include "object_handle.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
#define SSLPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_ssl_operations : public basic_ssl_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_ssl_c_api<ApiTraits>;

    using bio_method_type = ssl_types::bio_method_type;
    using bio_type = ssl_types::bio_type;
    using evp_pkey_type = ssl_types::evp_pkey_type;
    using evp_md_ctx_type = ssl_types::evp_md_ctx_type;
    using evp_md_type = ssl_types::evp_md_type;

    template <
      typename W,
      W c_api::*F,
      typename Signature = typename W::signature>
    class func;

    template <typename W, W c_api::*F, typename RVC, typename... Params>
    class func<W, F, RVC(Params...)>
      : public wrapped_c_api_function<c_api, api_traits, nothing_t, W, F> {
        using base = wrapped_c_api_function<c_api, api_traits, nothing_t, W, F>;

    private:
        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().err_get_error());
            return std::forward<Res>(res);
        }

    protected:
        template <typename... Args>
        constexpr auto _chkcall(Args&&... args) const noexcept {
            return this->_check(this->_call(std::forward<Args>(args)...));
        }

        using base::_conv;

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...).cast_to(identity<RVC>{});
        }
    };

    // basic_io_new
    struct : func<SSLPAFP(bio_new)> {
        using func<SSLPAFP(bio_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_basic_io>{});
        }
    } basic_io_new;

    // basic_io_block_new
    struct : func<SSLPAFP(bio_new_mem_buf)> {
        using func<SSLPAFP(bio_new_mem_buf)>::func;

        constexpr auto operator()(memory::const_block blk) const noexcept {
            return this->_chkcall(blk.data(), limit_cast<int>(blk.size()))
              .cast_to(identity<owned_basic_io>{});
        }

    } basic_io_block_new;

    // basic_io_free
    struct : func<SSLPAFP(bio_free)> {
        using func<SSLPAFP(bio_free)>::func;

        constexpr auto operator()(owned_basic_io& bio) const noexcept {
            return this->_chkcall(bio.release());
        }

        auto raii(owned_basic_io& bio) const noexcept {
            return eagine::finally([this, &bio]() { (*this)(bio); });
        }

    } basic_io_free;

    // basic_io_free_all
    struct : func<SSLPAFP(bio_free_all)> {
        using func<SSLPAFP(bio_free_all)>::func;

        constexpr auto operator()(owned_basic_io& bio) const noexcept {
            return this->_chkcall(bio.release());
        }

        auto raii(owned_basic_io& bio) const noexcept {
            return eagine::finally([this, &bio]() { (*this)(bio); });
        }

    } basic_io_free_all;

    // pkey_free
    struct : func<SSLPAFP(evp_pkey_free)> {
        using func<SSLPAFP(evp_pkey_free)>::func;

        auto raii(evp_pkey_type* pky) noexcept {
            return eagine::finally([=]() { (*this)(pky); });
        }

    } pkey_free;

    // message_digest_null
    func<SSLPAFP(evp_md_null)> message_digest_noop;
    func<SSLPAFP(evp_md5)> message_digest_md5;
    func<SSLPAFP(evp_sha1)> message_digest_sha1;
    func<SSLPAFP(evp_sha224)> message_digest_sha224;
    func<SSLPAFP(evp_sha256)> message_digest_sha256;
    func<SSLPAFP(evp_sha384)> message_digest_sha384;
    func<SSLPAFP(evp_sha512)> message_digest_sha512;

    func<SSLPAFP(evp_md_size)> message_digest_size;

    // message_digest_new
    func<SSLPAFP(evp_md_ctx_new)> message_digest_new;

    // message_digest_free
    struct : func<SSLPAFP(evp_md_ctx_free)> {
        using func<SSLPAFP(evp_md_ctx_free)>::func;

        auto raii(evp_md_ctx_type* ctx) noexcept {
            return eagine::finally([=]() { (*this)(ctx); });
        }

    } message_digest_free;

    // message_digest_init
    func<SSLPAFP(evp_digest_init)> message_digest_init;

    // message_digest_init_ex
    func<SSLPAFP(evp_digest_init_ex)> message_digest_init_ex;

    // message_digest_update
    struct : func<SSLPAFP(evp_digest_update)> {
        using func<SSLPAFP(evp_digest_update)>::func;

        constexpr auto operator()(
          evp_md_ctx_type* ctx, memory::const_block blk) const noexcept {
            return this->_chkcall(ctx, blk.data(), std_size(blk.size()));
        }

    } message_digest_update;

    // message_digest_final
    struct : func<SSLPAFP(evp_digest_final)> {
        using func<SSLPAFP(evp_digest_final)>::func;

        constexpr auto operator()(evp_md_ctx_type* ctx, memory::block blk) const
          noexcept {
            unsigned int size{0U};
            return this->_chkcall(ctx, blk.data(), &size)
              .replaced_with(head(blk, span_size(size)));
        }
    } message_digest_final;

    constexpr basic_ssl_operations(api_traits& traits)
      : c_api{traits}
      , basic_io_new("basic_io_new", traits, *this)
      , basic_io_block_new("basic_io_block_new", traits, *this)
      , basic_io_free("basic_io_free", traits, *this)
      , basic_io_free_all("basic_io_free_all", traits, *this)
      , pkey_free("pkey_free", traits, *this)
      , message_digest_noop("message_digest_noop", traits, *this)
      , message_digest_md5("message_digest_md5", traits, *this)
      , message_digest_sha1("message_digest_sha1", traits, *this)
      , message_digest_sha224("message_digest_sha224", traits, *this)
      , message_digest_sha256("message_digest_sha256", traits, *this)
      , message_digest_sha384("message_digest_sha384", traits, *this)
      , message_digest_sha512("message_digest_sha512", traits, *this)
      , message_digest_size("message_digest_size", traits, *this)
      , message_digest_new("message_digest_new", traits, *this)
      , message_digest_free("message_digest_free", traits, *this)
      , message_digest_init("message_digest_init", traits, *this)
      , message_digest_init_ex("message_digest_init_ex", traits, *this)
      , message_digest_update("message_digest_update", traits, *this)
      , message_digest_final("message_digest_final", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef SSLPAFP
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_API_HPP

