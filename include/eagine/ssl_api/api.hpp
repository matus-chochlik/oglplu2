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
    using passwd_callback_type = int(char*, int, int, void*);

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

        template <typename Tag, typename Handle>
        static constexpr inline auto _conv(
          basic_handle<Tag, Handle> obj) noexcept {
            return static_cast<Handle>(obj);
        }

        template <typename... Args>
        constexpr auto _cnvchkcall(Args&&... args) const noexcept {
            return this->_chkcall(_conv(args)...).cast_to(identity<RVC>{});
        }

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...).cast_to(identity<RVC>{});
        }
    };

    // basic_io_new
    struct : func<SSLPAFP(bio_new)> {
        using func<SSLPAFP(bio_new)>::func;

        constexpr auto operator()(basic_io_method method) const noexcept {
            return this->_chkcall(method).cast_to(identity<owned_basic_io>{});
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

    // read_bio_private_key
    struct : func<SSLPAFP(pem_read_bio_private_key)> {
        using func<SSLPAFP(pem_read_bio_private_key)>::func;

        constexpr auto operator()(
          basic_io bio, passwd_callback_type get_passwd, void* param) const
          noexcept {
            return this->_cnvchkcall(bio, nullptr, get_passwd, param)
              .cast_to(identity<owned_pkey>{});
        }

    } read_bio_private_key;

    // read_bio_public_key
    struct : func<SSLPAFP(pem_read_bio_pubkey)> {
        using func<SSLPAFP(pem_read_bio_pubkey)>::func;

        constexpr auto operator()(
          basic_io bio, passwd_callback_type get_passwd, void* param) const
          noexcept {
            return this->_cnvchkcall(bio, nullptr, get_passwd, param)
              .cast_to(identity<owned_pkey>{});
        }

    } read_bio_public_key;

    // pkey_free
    struct : func<SSLPAFP(evp_pkey_free)> {
        using func<SSLPAFP(evp_pkey_free)>::func;

        constexpr auto operator()(owned_pkey& pky) const noexcept {
            return this->_chkcall(pky.release());
        }

        auto raii(owned_pkey& pky) noexcept {
            return eagine::finally([=]() { (*this)(pky); });
        }

    } pkey_free;

    // message_digest_null
    struct : func<SSLPAFP(evp_md_null)> {
        using func<SSLPAFP(evp_md_null)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_noop;

    struct : func<SSLPAFP(evp_md5)> {
        using func<SSLPAFP(evp_md5)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_md5;

    struct : func<SSLPAFP(evp_sha1)> {
        using func<SSLPAFP(evp_sha1)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_sha1;

    struct : func<SSLPAFP(evp_sha224)> {
        using func<SSLPAFP(evp_sha224)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_sha224;

    struct : func<SSLPAFP(evp_sha256)> {
        using func<SSLPAFP(evp_sha256)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_sha256;

    struct : func<SSLPAFP(evp_sha384)> {
        using func<SSLPAFP(evp_sha384)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_sha384;

    struct : func<SSLPAFP(evp_sha512)> {
        using func<SSLPAFP(evp_sha512)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<message_digest_type>{});
        }
    } message_digest_sha512;

    struct : func<SSLPAFP(evp_md_size)> {
        using func<SSLPAFP(evp_md_size)>::func;

        constexpr auto operator()(message_digest_type mdt) const noexcept {
            return this->_cnvchkcall(mdt);
        }
    } message_digest_size;

    // message_digest_new
    struct : func<SSLPAFP(evp_md_ctx_new)> {
        using func<SSLPAFP(evp_md_ctx_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_message_digest>{});
        }
    } message_digest_new;

    // message_digest_free
    struct : func<SSLPAFP(evp_md_ctx_free)> {
        using func<SSLPAFP(evp_md_ctx_free)>::func;

        constexpr auto operator()(owned_message_digest& mdc) const noexcept {
            return eagine::finally(
              [this, &mdc]() { this->_chkcall(mdc.release()); });
        }

        auto raii(owned_message_digest& mdc) noexcept {
            return eagine::finally([this, &mdc]() { (*this)(mdc); });
        }

    } message_digest_free;

    // message_digest_init
    struct : func<SSLPAFP(evp_digest_init)> {
        using func<SSLPAFP(evp_digest_init)>::func;

        constexpr auto operator()(
          message_digest mdc, message_digest_type mdt) const noexcept {
            return this->_cnvchkcall(mdc, mdt);
        }
    } message_digest_init;

    // message_digest_init_ex
    struct : func<SSLPAFP(evp_digest_init_ex)> {
        using func<SSLPAFP(evp_digest_init_ex)>::func;

        constexpr auto operator()(
          message_digest mdc, message_digest_type mdt, engine eng) const
          noexcept {
            return this->_cnvchkcall(mdc, mdt, eng);
        }
    } message_digest_init_ex;

    // message_digest_update
    struct : func<SSLPAFP(evp_digest_update)> {
        using func<SSLPAFP(evp_digest_update)>::func;

        constexpr auto operator()(
          message_digest mdc, memory::const_block blk) const noexcept {
            return this->_cnvchkcall(mdc, blk.data(), std_size(blk.size()));
        }

    } message_digest_update;

    // message_digest_final
    struct : func<SSLPAFP(evp_digest_final)> {
        using func<SSLPAFP(evp_digest_final)>::func;

        constexpr auto operator()(message_digest mdc, memory::block blk) const
          noexcept {
            unsigned int size{0U};
            return this->_cnvchkcall(mdc, blk.data(), &size)
              .replaced_with(head(blk, span_size(size)));
        }
    } message_digest_final;

    // message_digest_final
    struct : func<SSLPAFP(evp_digest_final_ex)> {
        using func<SSLPAFP(evp_digest_final_ex)>::func;

        constexpr auto operator()(message_digest mdc, memory::block blk) const
          noexcept {
            unsigned int size{0U};
            return this->_cnvchkcall(mdc, blk.data(), &size)
              .replaced_with(head(blk, span_size(size)));
        }
    } message_digest_final_ex;

    constexpr basic_ssl_operations(api_traits& traits)
      : c_api{traits}
      , basic_io_new("basic_io_new", traits, *this)
      , basic_io_block_new("basic_io_block_new", traits, *this)
      , basic_io_free("basic_io_free", traits, *this)
      , basic_io_free_all("basic_io_free_all", traits, *this)
      , read_bio_private_key("read_bio_private_key", traits, *this)
      , read_bio_public_key("read_bio_public_key", traits, *this)
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
      , message_digest_final("message_digest_final", traits, *this)
      , message_digest_final_ex("message_digest_final", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef SSLPAFP
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_API_HPP

