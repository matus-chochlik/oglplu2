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

#include "../callable_ref.hpp"
#include "../memory/split_block.hpp"
#include "c_api.hpp"
#include "object_handle.hpp"
#include "object_stack.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
#define SSLPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
class password_callback {
public:
    constexpr password_callback() noexcept = default;

    constexpr password_callback(
      callable_ref<bool(string_span, bool)> callback) noexcept
      : _callback{callback} {
    }

    constexpr auto* native_func() noexcept {
        return _callback ? &_impl : nullptr;
    }

    constexpr auto* native_data() noexcept {
        return _callback ? static_cast<void*>(this) : nullptr;
    }

private:
    static int _impl(char* dst, int len, int writing, void* ptr) {
        if(auto* self = static_cast<password_callback*>(ptr)) {
            return self->_callback(
                     string_span(dst, span_size_t(len)), writing != 0)
                     ? 1
                     : 0;
        }
        return 0;
    }

    callable_ref<bool(string_span, bool)> _callback{};
};
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_ssl_operations : public basic_ssl_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_ssl_c_api<ApiTraits>;

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

        template <typename Object>
        static constexpr inline auto _conv(
          const object_stack<Object>& stk) noexcept {
            return stk.native();
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

        constexpr auto fake() const noexcept {
            auto result{this->_fake(0)};
            result.set_unknown_error();
            return result;
        }
    };

    // null_ui
    struct : func<SSLPAFP(ui_null)> {
        using func<SSLPAFP(ui_null)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<ui_method>{});
        }
    } null_ui;

    // openssl_ui
    struct : func<SSLPAFP(ui_openssl)> {
        using func<SSLPAFP(ui_openssl)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<ui_method>{});
        }
    } openssl_ui;

    // load_builtin_engines
    struct : func<SSLPAFP(engine_load_builtin_engines)> {
        using func<SSLPAFP(engine_load_builtin_engines)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall();
        }
    } load_builtin_engines;

    // get_first_engine
    struct : func<SSLPAFP(engine_get_first)> {
        using func<SSLPAFP(engine_get_first)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_engine>{});
        }
    } get_first_engine;

    // get_last_engine
    struct : func<SSLPAFP(engine_get_last)> {
        using func<SSLPAFP(engine_get_last)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_engine>{});
        }
    } get_last_engine;

    // get_next_engine
    struct : func<SSLPAFP(engine_get_next)> {
        using func<SSLPAFP(engine_get_next)>::func;

        constexpr auto operator()(owned_engine& eng) const noexcept {
            return this->_cnvchkcall(eng.release())
              .cast_to(identity<owned_engine>{});
        }
    } get_next_engine;

    // get_prev_engine
    struct : func<SSLPAFP(engine_get_prev)> {
        using func<SSLPAFP(engine_get_prev)>::func;

        constexpr auto operator()(owned_engine& eng) const noexcept {
            return this->_cnvchkcall(eng.release())
              .cast_to(identity<owned_engine>{});
        }
    } get_prev_engine;

    // new_engine
    struct : func<SSLPAFP(engine_new)> {
        using func<SSLPAFP(engine_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_engine>{});
        }
    } new_engine;

    // open_engine
    struct : func<SSLPAFP(engine_by_id)> {
        using func<SSLPAFP(engine_by_id)>::func;

        constexpr auto operator()(string_view id) const noexcept {
            return this->_cnvchkcall(id).cast_to(identity<owned_engine>{});
        }
    } open_engine;

    // copy_engine
    struct : func<SSLPAFP(engine_up_ref)> {
        using func<SSLPAFP(engine_up_ref)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng).replaced_with(owned_engine(eng));
        }
    } copy_engine;

    // delete_engine
    struct : func<SSLPAFP(engine_free)> {
        using func<SSLPAFP(engine_free)>::func;

        constexpr auto operator()(owned_engine& eng) const noexcept {
            return this->_chkcall(eng.release());
        }

        auto raii(owned_engine& eng) const noexcept {
            return eagine::finally([this, &eng]() { (*this)(eng); });
        }

    } delete_engine;

    // init_engine
    struct : func<SSLPAFP(engine_init)> {
        using func<SSLPAFP(engine_init)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return collapse_bool(this->_cnvchkcall(eng));
        }
    } init_engine;

    // finish_engine
    struct : func<SSLPAFP(engine_finish)> {
        using func<SSLPAFP(engine_finish)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return collapse_bool(this->_cnvchkcall(eng));
        }

        auto raii(owned_engine& eng) const noexcept {
            return eagine::finally([this, &eng]() { (*this)(eng); });
        }
    } finish_engine;

    // get_engine_id
    struct : func<SSLPAFP(engine_get_id)> {
        using func<SSLPAFP(engine_get_id)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng).cast_to(identity<string_view>{});
        }
    } get_engine_id;

    // get_engine_name
    struct : func<SSLPAFP(engine_get_name)> {
        using func<SSLPAFP(engine_get_name)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng).cast_to(identity<string_view>{});
        }
    } get_engine_name;

    // set_default_rsa
    struct : func<SSLPAFP(engine_set_default_rsa)> {
        using func<SSLPAFP(engine_set_default_rsa)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng);
        }
    } set_default_rsa;

    // set_default_dsa
    struct : func<SSLPAFP(engine_set_default_dsa)> {
        using func<SSLPAFP(engine_set_default_dsa)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng);
        }
    } set_default_dsa;

    // set_default_dh
    struct : func<SSLPAFP(engine_set_default_dh)> {
        using func<SSLPAFP(engine_set_default_dh)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng);
        }
    } set_default_dh;

    // set_default_rand
    struct : func<SSLPAFP(engine_set_default_rand)> {
        using func<SSLPAFP(engine_set_default_rand)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng);
        }
    } set_default_rand;

    // set_default_ciphers
    struct : func<SSLPAFP(engine_set_default_ciphers)> {
        using func<SSLPAFP(engine_set_default_ciphers)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng);
        }
    } set_default_ciphers;

    // set_default_digests
    struct : func<SSLPAFP(engine_set_default_digests)> {
        using func<SSLPAFP(engine_set_default_digests)>::func;

        constexpr auto operator()(engine eng) const noexcept {
            return this->_cnvchkcall(eng);
        }
    } set_default_digests;

    // load_engine_private_key
    struct : func<SSLPAFP(engine_load_private_key)> {
        using func<SSLPAFP(engine_load_private_key)>::func;

        constexpr auto operator()(
          engine eng, string_view key_id, ui_method uim) const noexcept {
            return this->_cnvchkcall(eng, key_id, uim, nullptr)
              .cast_to(identity<owned_pkey>{});
        }
    } load_engine_private_key;

    // load_engine_public_key
    struct : func<SSLPAFP(engine_load_public_key)> {
        using func<SSLPAFP(engine_load_public_key)>::func;

        constexpr auto operator()(engine eng, string_view key_id) const
          noexcept {
            return this->_cnvchkcall(eng, key_id, this->ui_openssl())
              .cast_to(identity<owned_pkey>{});
        }
    } load_engine_public_key;

    // new_basic_io
    struct : func<SSLPAFP(bio_new)> {
        using func<SSLPAFP(bio_new)>::func;

        constexpr auto operator()(basic_io_method method) const noexcept {
            return this->_chkcall(method).cast_to(identity<owned_basic_io>{});
        }
    } new_basic_io;

    // new_block_basic_io
    struct : func<SSLPAFP(bio_new_mem_buf)> {
        using func<SSLPAFP(bio_new_mem_buf)>::func;

        constexpr auto operator()(memory::const_block blk) const noexcept {
            return this->_chkcall(blk.data(), limit_cast<int>(blk.size()))
              .cast_to(identity<owned_basic_io>{});
        }

    } new_block_basic_io;

    // delete_basic_io
    struct : func<SSLPAFP(bio_free)> {
        using func<SSLPAFP(bio_free)>::func;

        constexpr auto operator()(owned_basic_io& bio) const noexcept {
            return this->_chkcall(bio.release());
        }

        auto raii(owned_basic_io& bio) const noexcept {
            return eagine::finally([this, &bio]() { (*this)(bio); });
        }

    } delete_basic_io;

    // delete_all_basic_ios
    struct : func<SSLPAFP(bio_free_all)> {
        using func<SSLPAFP(bio_free_all)>::func;

        constexpr auto operator()(owned_basic_io& bio) const noexcept {
            return this->_chkcall(bio.release());
        }

        auto raii(owned_basic_io& bio) const noexcept {
            return eagine::finally([this, &bio]() { (*this)(bio); });
        }

    } delete_all_basic_ios;

    // random_bytes
    struct : func<SSLPAFP(rand_bytes)> {
        using func<SSLPAFP(rand_bytes)>::func;

        constexpr auto operator()(memory::block blk) const noexcept {
            return this->_cnvchkcall(blk.data(), limit_cast<int>(blk.size()));
        }

    } random_bytes;

    // copy_pkey
    struct : func<SSLPAFP(evp_pkey_up_ref)> {
        using func<SSLPAFP(evp_pkey_up_ref)>::func;

        constexpr auto operator()(pkey pky) const noexcept {
            return this->_cnvchkcall(pky).replaced_with(owned_pkey(pky));
        }
    } copy_pkey;

    // delete_pkey
    struct : func<SSLPAFP(evp_pkey_free)> {
        using func<SSLPAFP(evp_pkey_free)>::func;

        constexpr auto operator()(owned_pkey& pky) const noexcept {
            return this->_chkcall(pky.release());
        }

        auto raii(owned_pkey& pky) const noexcept {
            return eagine::finally([this, &pky]() { (*this)(pky); });
        }

    } delete_pkey;

    // cipher
    struct : func<SSLPAFP(evp_aes_128_ctr)> {
        using func<SSLPAFP(evp_aes_128_ctr)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<cipher_type>{});
        }
    } cipher_aes_128_ctr;

    struct : func<SSLPAFP(evp_aes_128_ccm)> {
        using func<SSLPAFP(evp_aes_128_ccm)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<cipher_type>{});
        }
    } cipher_aes_128_ccm;

    struct : func<SSLPAFP(evp_aes_128_gcm)> {
        using func<SSLPAFP(evp_aes_128_gcm)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<cipher_type>{});
        }
    } cipher_aes_128_gcm;

    struct : func<SSLPAFP(evp_aes_128_xts)> {
        using func<SSLPAFP(evp_aes_128_xts)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<cipher_type>{});
        }
    } cipher_aes_128_xts;

    struct : func<SSLPAFP(evp_aes_192_ecb)> {
        using func<SSLPAFP(evp_aes_192_ecb)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<cipher_type>{});
        }
    } cipher_aes_192_ecb;

    struct : func<SSLPAFP(evp_aes_192_cbc)> {
        using func<SSLPAFP(evp_aes_192_cbc)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<cipher_type>{});
        }
    } cipher_aes_192_cbc;

    // new_cipher
    struct : func<SSLPAFP(evp_cipher_ctx_new)> {
        using func<SSLPAFP(evp_cipher_ctx_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_cipher>{});
        }
    } new_cipher;

    // delete_cipher
    struct : func<SSLPAFP(evp_cipher_ctx_free)> {
        using func<SSLPAFP(evp_cipher_ctx_free)>::func;

        constexpr auto operator()(owned_cipher& cyc) const noexcept {
            return this->_chkcall(cyc.release());
        }

        auto raii(owned_cipher& cyc) const noexcept {
            return eagine::finally([this, &cyc]() { (*this)(cyc); });
        }

    } delete_cipher;

    // cipher_reset
    struct : func<SSLPAFP(evp_cipher_ctx_reset)> {
        using func<SSLPAFP(evp_cipher_ctx_reset)>::func;

        constexpr auto operator()(cipher cyc) const noexcept {
            return this->_cnvchkcall(cyc);
        }

    } cipher_reset;

    // cipher_init
    struct : func<SSLPAFP(evp_cipher_init)> {
        using func<SSLPAFP(evp_cipher_init)>::func;

        constexpr auto operator()(
          cipher cyc,
          cipher_type cyt,
          memory::const_block key,
          memory::const_block iv,
          bool enc) const noexcept {
            return this->_cnvchkcall(
              cyc, cyt, key.data(), iv.data(), enc ? 1 : 0);
        }
    } cipher_init;

    // cipher_init_ex
    struct : func<SSLPAFP(evp_cipher_init_ex)> {
        using func<SSLPAFP(evp_cipher_init_ex)>::func;

        constexpr auto operator()(
          cipher cyc,
          cipher_type cyt,
          engine eng,
          memory::const_block key,
          memory::const_block iv,
          bool enc) const noexcept {
            return this->_cnvchkcall(
              cyc, cyt, eng, key.data(), iv.data(), enc ? 1 : 0);
        }
    } cipher_init_ex;

    // cipher_update
    struct : func<SSLPAFP(evp_cipher_update)> {
        using func<SSLPAFP(evp_cipher_update)>::func;

        constexpr auto operator()(
          cipher cyc, memory::split_block out, memory::const_block in) const
          noexcept {
            int outl{0};
            return this
              ->_cnvchkcall(
                cyc,
                out.tail().data(),
                &outl,
                in.data(),
                limit_cast<int>(in.size()))
              .replaced_with(out.advance(span_size(outl)));
        }

    } cipher_update;

    // cipher_final
    struct : func<SSLPAFP(evp_cipher_final)> {
        using func<SSLPAFP(evp_cipher_final)>::func;

        constexpr auto operator()(cipher cyc, memory::split_block out) const
          noexcept {
            int outl{0U};
            return this->_cnvchkcall(cyc, out.tail().data(), &outl)
              .replaced_with(out.advance(span_size(outl)));
        }
    } cipher_final;

    // cipher_final_ex
    struct : func<SSLPAFP(evp_cipher_final_ex)> {
        using func<SSLPAFP(evp_cipher_final_ex)>::func;

        constexpr auto operator()(cipher cyc, memory::split_block out) const
          noexcept {
            int outl{0U};
            return this->_cnvchkcall(cyc, out.tail().data(), &outl)
              .replaced_with(out.advance(span_size(outl)));
        }
    } cipher_final_ex;

    // encrypt_init
    struct : func<SSLPAFP(evp_encrypt_init)> {
        using func<SSLPAFP(evp_encrypt_init)>::func;

        constexpr auto operator()(
          cipher cyc,
          cipher_type cyt,
          memory::const_block key,
          memory::const_block iv,
          bool enc) const noexcept {
            return this->_cnvchkcall(
              cyc, cyt, key.data(), iv.data(), enc ? 1 : 0);
        }
    } encrypt_init;

    // encrypt_init_ex
    struct : func<SSLPAFP(evp_encrypt_init_ex)> {
        using func<SSLPAFP(evp_encrypt_init_ex)>::func;

        constexpr auto operator()(
          cipher cyc,
          cipher_type cyt,
          engine eng,
          memory::const_block key,
          memory::const_block iv,
          bool enc) const noexcept {
            return this->_cnvchkcall(
              cyc, cyt, eng, key.data(), iv.data(), enc ? 1 : 0);
        }
    } encrypt_init_ex;

    // encrypt_update
    struct : func<SSLPAFP(evp_encrypt_update)> {
        using func<SSLPAFP(evp_encrypt_update)>::func;

        constexpr auto operator()(
          cipher cyc, memory::split_block out, memory::const_block in) const
          noexcept {
            int outl{0};
            return this
              ->_cnvchkcall(
                cyc,
                out.tail().data(),
                &outl,
                in.data(),
                limit_cast<int>(in.size()))
              .replaced_with(out.advance(span_size(outl)));
        }

    } encrypt_update;

    // encrypt_final
    struct : func<SSLPAFP(evp_encrypt_final)> {
        using func<SSLPAFP(evp_encrypt_final)>::func;

        constexpr auto operator()(cipher cyc, memory::split_block out) const
          noexcept {
            int outl{0U};
            return this->_cnvchkcall(cyc, out.tail().data(), &outl)
              .replaced_with(out.advance(span_size(outl)));
        }
    } encrypt_final;

    // encrypt_final_ex
    struct : func<SSLPAFP(evp_encrypt_final_ex)> {
        using func<SSLPAFP(evp_encrypt_final_ex)>::func;

        constexpr auto operator()(cipher cyc, memory::split_block out) const
          noexcept {
            int outl{0U};
            return this->_cnvchkcall(cyc, out.tail().data(), &outl)
              .replaced_with(out.advance(span_size(outl)));
        }
    } encrypt_final_ex;

    // decrypt_init
    struct : func<SSLPAFP(evp_decrypt_init)> {
        using func<SSLPAFP(evp_decrypt_init)>::func;

        constexpr auto operator()(
          cipher cyc,
          cipher_type cyt,
          memory::const_block key,
          memory::const_block iv,
          bool enc) const noexcept {
            return this->_cnvchkcall(
              cyc, cyt, key.data(), iv.data(), enc ? 1 : 0);
        }
    } decrypt_init;

    // decrypt_init_ex
    struct : func<SSLPAFP(evp_decrypt_init_ex)> {
        using func<SSLPAFP(evp_decrypt_init_ex)>::func;

        constexpr auto operator()(
          cipher cyc,
          cipher_type cyt,
          engine eng,
          memory::const_block key,
          memory::const_block iv,
          bool enc) const noexcept {
            return this->_cnvchkcall(
              cyc, cyt, eng, key.data(), iv.data(), enc ? 1 : 0);
        }
    } decrypt_init_ex;

    // decrypt_update
    struct : func<SSLPAFP(evp_decrypt_update)> {
        using func<SSLPAFP(evp_decrypt_update)>::func;

        constexpr auto operator()(
          cipher cyc, memory::split_block out, memory::const_block in) const
          noexcept {
            int outl{0};
            return this
              ->_cnvchkcall(
                cyc,
                out.tail().data(),
                &outl,
                in.data(),
                limit_cast<int>(in.size()))
              .replaced_with(out.advance(span_size(outl)));
        }

    } decrypt_update;

    // decrypt_final
    struct : func<SSLPAFP(evp_decrypt_final)> {
        using func<SSLPAFP(evp_decrypt_final)>::func;

        constexpr auto operator()(cipher cyc, memory::split_block out) const
          noexcept {
            int outl{0U};
            return this->_cnvchkcall(cyc, out.tail().data(), &outl)
              .replaced_with(out.advance(span_size(outl)));
        }
    } decrypt_final;

    // decrypt_final_ex
    struct : func<SSLPAFP(evp_decrypt_final_ex)> {
        using func<SSLPAFP(evp_decrypt_final_ex)>::func;

        constexpr auto operator()(cipher cyc, memory::split_block out) const
          noexcept {
            int outl{0U};
            return this->_cnvchkcall(cyc, out.tail().data(), &outl)
              .replaced_with(out.advance(span_size(outl)));
        }
    } decrypt_final_ex;

    // message_digest
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

    // new_message_digest
    struct : func<SSLPAFP(evp_md_ctx_new)> {
        using func<SSLPAFP(evp_md_ctx_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_message_digest>{});
        }
    } new_message_digest;

    // delete_message_digest
    struct : func<SSLPAFP(evp_md_ctx_free)> {
        using func<SSLPAFP(evp_md_ctx_free)>::func;

        constexpr auto operator()(owned_message_digest& mdc) const noexcept {
            return this->_chkcall(mdc.release());
        }

        auto raii(owned_message_digest& mdc) const noexcept {
            return eagine::finally([this, &mdc]() { (*this)(mdc); });
        }

    } delete_message_digest;

    // message_digest_reset
    struct : func<SSLPAFP(evp_md_ctx_reset)> {
        using func<SSLPAFP(evp_md_ctx_reset)>::func;

        constexpr auto operator()(message_digest mdc) const noexcept {
            return this->_cnvchkcall(mdc);
        }

    } message_digest_reset;

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

    // message_digest_final_ex
    struct : func<SSLPAFP(evp_digest_final_ex)> {
        using func<SSLPAFP(evp_digest_final_ex)>::func;

        constexpr auto operator()(message_digest mdc, memory::block blk) const
          noexcept {
            unsigned int size{0U};
            return this->_cnvchkcall(mdc, blk.data(), &size)
              .replaced_with(head(blk, span_size(size)));
        }
    } message_digest_final_ex;

    // message_digest_sign_init
    struct : func<SSLPAFP(evp_digest_sign_init)> {
        using func<SSLPAFP(evp_digest_sign_init)>::func;

        constexpr auto operator()(
          message_digest mdc, message_digest_type mdt, pkey pky) const
          noexcept {
            return this->_cnvchkcall(mdc, nullptr, mdt, nullptr, pky);
        }

        constexpr auto operator()(
          message_digest mdc,
          message_digest_type mdt,
          engine eng,
          pkey pky) const noexcept {
            return this->_cnvchkcall(mdc, nullptr, mdt, eng, pky);
        }
    } message_digest_sign_init;

    // message_digest_sign_update
    struct : func<SSLPAFP(evp_digest_sign_update)> {
        using func<SSLPAFP(evp_digest_sign_update)>::func;

        constexpr auto operator()(
          message_digest mdc, memory::const_block blk) const noexcept {
            return this->_cnvchkcall(mdc, blk.data(), std_size(blk.size()));
        }

    } message_digest_sign_update;

    // message_digest_sign_final
    struct : func<SSLPAFP(evp_digest_sign_final)> {
        using func<SSLPAFP(evp_digest_sign_final)>::func;

        constexpr auto required_size(message_digest mdc) const noexcept {
            size_t size{0U};
            return this->_cnvchkcall(mdc, nullptr, &size)
              .replaced_with(span_size(size));
        }

        constexpr auto operator()(message_digest mdc, memory::block blk) const
          noexcept {
            auto size = limit_cast<size_t>(blk.size());
            return this->_cnvchkcall(mdc, blk.data(), &size)
              .replaced_with(head(blk, span_size(size)));
        }
    } message_digest_sign_final;

    // message_digest_verify_init
    struct : func<SSLPAFP(evp_digest_verify_init)> {
        using func<SSLPAFP(evp_digest_verify_init)>::func;

        constexpr auto operator()(
          message_digest mdc, message_digest_type mdt, pkey pky) const
          noexcept {
            return this->_cnvchkcall(mdc, nullptr, mdt, nullptr, pky);
        }

        constexpr auto operator()(
          message_digest mdc,
          message_digest_type mdt,
          engine eng,
          pkey pky) const noexcept {
            return this->_cnvchkcall(mdc, nullptr, mdt, eng, pky);
        }
    } message_digest_verify_init;

    // message_digest_verify_update
    struct : func<SSLPAFP(evp_digest_verify_update)> {
        using func<SSLPAFP(evp_digest_verify_update)>::func;

        constexpr auto operator()(
          message_digest mdc, memory::const_block blk) const noexcept {
            return this->_cnvchkcall(mdc, blk.data(), std_size(blk.size()));
        }

    } message_digest_verify_update;

    // message_digest_verify_final
    struct : func<SSLPAFP(evp_digest_verify_final)> {
        using func<SSLPAFP(evp_digest_verify_final)>::func;

        constexpr auto operator()(
          message_digest mdc, memory::const_block blk) const noexcept {
            return this->_cnvchkcall(mdc, blk.data(), std_size(blk.size()))
              .transformed([](int result) { return result == 1; });
        }
    } message_digest_verify_final;

    // new_x509_store_ctx
    struct : func<SSLPAFP(x509_store_ctx_new)> {
        using func<SSLPAFP(x509_store_ctx_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_x509_store_ctx>{});
        }
    } new_x509_store_ctx;

    // init_x509_store_ctx
    struct : func<SSLPAFP(x509_store_ctx_init)> {
        using func<SSLPAFP(x509_store_ctx_init)>::func;

        constexpr auto operator()(
          x509_store_ctx xsc, x509_store xst, x509 crt) const noexcept {
            return this->_cnvchkcall(xsc, xst, crt, nullptr);
        }

        constexpr auto operator()(
          x509_store_ctx xsc,
          x509_store xst,
          x509 crt,
          const object_stack<x509>& chain) const noexcept {
            return this->_cnvchkcall(xsc, xst, crt, chain);
        }

    } init_x509_store_ctx;

    // set_x509_store_trusted_stack
    struct : func<SSLPAFP(x509_store_ctx_set0_trusted_stack)> {
        using func<SSLPAFP(x509_store_ctx_set0_trusted_stack)>::func;

        constexpr auto operator()(
          x509_store_ctx xsc, const object_stack<x509>& stk) const noexcept {
            return this->_cnvchkcall(xsc, stk);
        }

    } set_x509_store_trusted_stack;

    // set_x509_store_verified_chain
    struct : func<SSLPAFP(x509_store_ctx_set0_verified_chain)> {
        using func<SSLPAFP(x509_store_ctx_set0_verified_chain)>::func;

        constexpr auto operator()(
          x509_store_ctx xsc, const object_stack<x509>& stk) const noexcept {
            return this->_cnvchkcall(xsc, stk);
        }

    } set_x509_store_verified_chain;

    // set_x509_store_untrusted
    struct : func<SSLPAFP(x509_store_ctx_set0_untrusted)> {
        using func<SSLPAFP(x509_store_ctx_set0_untrusted)>::func;

        constexpr auto operator()(
          x509_store_ctx xsc, const object_stack<x509>& stk) const noexcept {
            return this->_cnvchkcall(xsc, stk);
        }

    } set_x509_store_untrusted;

    // cleanup_x509_store_ctx
    struct : func<SSLPAFP(x509_store_ctx_cleanup)> {
        using func<SSLPAFP(x509_store_ctx_cleanup)>::func;

        constexpr auto operator()(x509_store_ctx xsc) const noexcept {
            return this->_chkcall(xsc);
        }

        auto raii(x509_store_ctx xsc) const noexcept {
            return eagine::finally([this, xsc]() { (*this)(xsc); });
        }

    } cleanup_x509_store_ctx;

    // delete_x509_store_ctx
    struct : func<SSLPAFP(x509_store_ctx_free)> {
        using func<SSLPAFP(x509_store_ctx_free)>::func;

        constexpr auto operator()(owned_x509_store_ctx& xsc) const noexcept {
            return this->_chkcall(xsc.release());
        }

        auto raii(owned_x509_store_ctx& xsc) const noexcept {
            return eagine::finally([this, &xsc]() { (*this)(xsc); });
        }

    } delete_x509_store_ctx;

    // x509_verify_certificate
    struct : func<SSLPAFP(x509_verify_cert)> {
        using func<SSLPAFP(x509_verify_cert)>::func;

        constexpr auto operator()(x509_store_ctx xsc) const noexcept {
            return this->_cnvchkcall(xsc);
        }

    } x509_verify_certificate;

    // new_x509_store
    struct : func<SSLPAFP(x509_store_new)> {
        using func<SSLPAFP(x509_store_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_x509_store>{});
        }
    } new_x509_store;

    // copy_x509_store
    struct : func<SSLPAFP(x509_store_up_ref)> {
        using func<SSLPAFP(x509_store_up_ref)>::func;

        constexpr auto operator()(x509_store xst) const noexcept {
            return this->_chkcall().replaced_with(owned_x509_store{xst});
        }
    } copy_x509_store;

    // delete_x509_store
    struct : func<SSLPAFP(x509_store_free)> {
        using func<SSLPAFP(x509_store_free)>::func;

        constexpr auto operator()(owned_x509_store& xst) const noexcept {
            return this->_chkcall(xst.release());
        }

        auto raii(owned_x509_store& xst) const noexcept {
            return eagine::finally([this, &xst]() { (*this)(xst); });
        }

    } delete_x509_store;

    // add_cert_into_x509_store
    struct : func<SSLPAFP(x509_store_add_cert)> {
        using func<SSLPAFP(x509_store_add_cert)>::func;

        constexpr auto operator()(x509_store xst, x509 crt) const noexcept {
            return this->_cnvchkcall(xst, crt);
        }

    } add_cert_into_x509_store;

    // add_crl_into_x509_store
    struct : func<SSLPAFP(x509_store_add_crl)> {
        using func<SSLPAFP(x509_store_add_crl)>::func;

        constexpr auto operator()(x509_store xst, x509_crl crl) const noexcept {
            return this->_cnvchkcall(xst, crl);
        }

    } add_crl_into_x509_store;

    // load_into_x509_store
    struct : func<SSLPAFP(x509_store_load_locations)> {
        using func<SSLPAFP(x509_store_load_locations)>::func;

        constexpr auto operator()(x509_store xst, string_view file_path) const
          noexcept {
            return this->_cnvchkcall(xst, file_path, nullptr);
        }

    } load_into_x509_store;

    // new_x509_crl
    struct : func<SSLPAFP(x509_crl_new)> {
        using func<SSLPAFP(x509_crl_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_x509_crl>{});
        }
    } new_x509_crl;

    // delete_x509_crl
    struct : func<SSLPAFP(x509_crl_free)> {
        using func<SSLPAFP(x509_crl_free)>::func;

        constexpr auto operator()(owned_x509_crl& crl) const noexcept {
            return this->_chkcall(crl.release());
        }

        auto raii(owned_x509_crl& crl) const noexcept {
            return eagine::finally([this, &crl]() { (*this)(crl); });
        }

    } delete_x509_crl;

    // new_x509
    struct : func<SSLPAFP(x509_new)> {
        using func<SSLPAFP(x509_new)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_x509>{});
        }
    } new_x509;

    // get_x509_pubkey
    struct : func<SSLPAFP(x509_get_pubkey)> {
        using func<SSLPAFP(x509_get_pubkey)>::func;

        constexpr auto operator()(x509 crt) const noexcept {
            return this->_cnvchkcall(crt).cast_to(identity<owned_pkey>{});
        }
    } get_x509_pubkey;

    // delete_x509
    struct : func<SSLPAFP(x509_free)> {
        using func<SSLPAFP(x509_free)>::func;

        constexpr auto operator()(owned_x509& crt) const noexcept {
            return this->_chkcall(crt.release());
        }

        auto raii(owned_x509& crt) const noexcept {
            return eagine::finally([this, &crt]() { (*this)(crt); });
        }

    } delete_x509;

    // read_bio_private_key
    struct : func<SSLPAFP(pem_read_bio_private_key)> {
        using func<SSLPAFP(pem_read_bio_private_key)>::func;

        constexpr auto operator()(basic_io bio) const noexcept {
            return this->_cnvchkcall(bio, nullptr, nullptr, nullptr)
              .cast_to(identity<owned_pkey>{});
        }

        constexpr auto operator()(
          basic_io bio, password_callback get_passwd) const noexcept {
            return this
              ->_cnvchkcall(
                bio,
                nullptr,
                get_passwd.native_func(),
                get_passwd.native_data())
              .cast_to(identity<owned_pkey>{});
        }

    } read_bio_private_key;

    // read_bio_public_key
    struct : func<SSLPAFP(pem_read_bio_pubkey)> {
        using func<SSLPAFP(pem_read_bio_pubkey)>::func;

        constexpr auto operator()(basic_io bio) const noexcept {
            return this->_cnvchkcall(bio, nullptr, nullptr, nullptr)
              .cast_to(identity<owned_pkey>{});
        }

        constexpr auto operator()(
          basic_io bio, password_callback get_passwd) const noexcept {
            return this
              ->_cnvchkcall(
                bio,
                nullptr,
                get_passwd.native_func(),
                get_passwd.native_data())
              .cast_to(identity<owned_pkey>{});
        }

    } read_bio_public_key;

    // read_bio_x509_crl
    struct : func<SSLPAFP(pem_read_bio_x509_crl)> {
        using func<SSLPAFP(pem_read_bio_x509_crl)>::func;

        constexpr auto operator()(basic_io bio) const noexcept {
            return this->_cnvchkcall(bio, nullptr, nullptr, nullptr)
              .cast_to(identity<owned_x509_crl>{});
        }

        constexpr auto operator()(
          basic_io bio, password_callback get_passwd) const noexcept {
            return this
              ->_cnvchkcall(
                bio,
                nullptr,
                get_passwd.native_func(),
                get_passwd.native_data())
              .cast_to(identity<owned_x509_crl>{});
        }

    } read_bio_x509_crl;

    // read_bio_x509
    struct : func<SSLPAFP(pem_read_bio_x509)> {
        using func<SSLPAFP(pem_read_bio_x509)>::func;

        constexpr auto operator()(basic_io bio) const noexcept {
            return this->_cnvchkcall(bio, nullptr, nullptr, nullptr)
              .cast_to(identity<owned_x509>{});
        }

        constexpr auto operator()(
          basic_io bio, password_callback get_passwd) const noexcept {
            return this
              ->_cnvchkcall(
                bio,
                nullptr,
                get_passwd.native_func(),
                get_passwd.native_data())
              .cast_to(identity<owned_x509>{});
        }

    } read_bio_x509;

    constexpr basic_ssl_operations(api_traits& traits)
      : c_api{traits}
      , null_ui("null_ui", traits, *this)
      , openssl_ui("openssl_ui", traits, *this)
      , load_builtin_engines("load_builtin_engines", traits, *this)
      , get_first_engine("get_first_engine", traits, *this)
      , get_last_engine("get_last_engine", traits, *this)
      , get_next_engine("get_next_engine", traits, *this)
      , get_prev_engine("get_prev_engine", traits, *this)
      , new_engine("new_engine", traits, *this)
      , open_engine("open_engine", traits, *this)
      , copy_engine("copy_engine", traits, *this)
      , delete_engine("delete_engine", traits, *this)
      , init_engine("init_engine", traits, *this)
      , finish_engine("finish_engine", traits, *this)
      , get_engine_id("get_engine_id", traits, *this)
      , get_engine_name("get_engine_name", traits, *this)
      , set_default_rsa("set_default_rsa", traits, *this)
      , set_default_dsa("set_default_dsa", traits, *this)
      , set_default_dh("set_default_dh", traits, *this)
      , set_default_rand("set_default_rand", traits, *this)
      , set_default_ciphers("set_default_ciphers", traits, *this)
      , set_default_digests("set_default_digests", traits, *this)
      , load_engine_private_key("load_engine_private_key", traits, *this)
      , load_engine_public_key("load_engine_public_key", traits, *this)
      , new_basic_io("new_basic_io", traits, *this)
      , new_block_basic_io("new_block_basic_io", traits, *this)
      , delete_basic_io("delete_basic_io", traits, *this)
      , delete_all_basic_ios("delete_all_basic_ios", traits, *this)
      , random_bytes("random_bytes", traits, *this)
      , copy_pkey("copy_pkey", traits, *this)
      , delete_pkey("delete_pkey", traits, *this)
      , cipher_aes_128_ctr("cipher_aes_128_ctr", traits, *this)
      , cipher_aes_128_ccm("cipher_aes_128_ccm", traits, *this)
      , cipher_aes_128_gcm("cipher_aes_128_gcm", traits, *this)
      , cipher_aes_128_xts("cipher_aes_128_xts", traits, *this)
      , cipher_aes_192_ecb("cipher_aes_192_ecb", traits, *this)
      , cipher_aes_192_cbc("cipher_aes_192_cbc", traits, *this)
      , new_cipher("new_cipher", traits, *this)
      , delete_cipher("delete_cipher", traits, *this)
      , cipher_reset("cipher_reset", traits, *this)
      , cipher_init("cipher_init", traits, *this)
      , cipher_init_ex("cipher_init_ex", traits, *this)
      , cipher_update("cipher_update", traits, *this)
      , cipher_final("cipher_final", traits, *this)
      , cipher_final_ex("cipher_final", traits, *this)
      , encrypt_init("encrypt_init", traits, *this)
      , encrypt_init_ex("encrypt_init_ex", traits, *this)
      , encrypt_update("encrypt_update", traits, *this)
      , encrypt_final("encrypt_final", traits, *this)
      , encrypt_final_ex("encrypt_final", traits, *this)
      , decrypt_init("decrypt_init", traits, *this)
      , decrypt_init_ex("decrypt_init_ex", traits, *this)
      , decrypt_update("decrypt_update", traits, *this)
      , decrypt_final("decrypt_final", traits, *this)
      , decrypt_final_ex("decrypt_final", traits, *this)
      , message_digest_noop("message_digest_noop", traits, *this)
      , message_digest_md5("message_digest_md5", traits, *this)
      , message_digest_sha1("message_digest_sha1", traits, *this)
      , message_digest_sha224("message_digest_sha224", traits, *this)
      , message_digest_sha256("message_digest_sha256", traits, *this)
      , message_digest_sha384("message_digest_sha384", traits, *this)
      , message_digest_sha512("message_digest_sha512", traits, *this)
      , message_digest_size("message_digest_size", traits, *this)
      , new_message_digest("new_message_digest", traits, *this)
      , delete_message_digest("delete_message_digest", traits, *this)
      , message_digest_reset("message_digest_reset", traits, *this)
      , message_digest_init("message_digest_init", traits, *this)
      , message_digest_init_ex("message_digest_init_ex", traits, *this)
      , message_digest_update("message_digest_update", traits, *this)
      , message_digest_final("message_digest_final", traits, *this)
      , message_digest_final_ex("message_digest_final", traits, *this)
      , message_digest_sign_init("message_digest_sign_init", traits, *this)
      , message_digest_sign_update("message_digest_sign_update", traits, *this)
      , message_digest_sign_final("message_digest_sign_final", traits, *this)
      , message_digest_verify_init("message_digest_verify_init", traits, *this)
      , message_digest_verify_update(
          "message_digest_verify_update", traits, *this)
      , message_digest_verify_final(
          "message_digest_verify_final", traits, *this)
      , new_x509_store_ctx("new_x509_store_ctx", traits, *this)
      , init_x509_store_ctx("init_x509_store_ctx", traits, *this)
      , set_x509_store_trusted_stack(
          "set_x509_store_trusted_stack", traits, *this)
      , set_x509_store_verified_chain(
          "set_x509_store_verified_chain", traits, *this)
      , set_x509_store_untrusted("set_x509_store_untrusted", traits, *this)
      , cleanup_x509_store_ctx("cleanup_x509_store_ctx", traits, *this)
      , delete_x509_store_ctx("delete_x509_store_ctx", traits, *this)
      , x509_verify_certificate("x509_verify_certificate", traits, *this)
      , new_x509_store("new_x509_store", traits, *this)
      , copy_x509_store("copy_x509_store", traits, *this)
      , delete_x509_store("delete_x509_store", traits, *this)
      , add_cert_into_x509_store("add_cert_into_x509_store", traits, *this)
      , add_crl_into_x509_store("add_crl_into_x509_store", traits, *this)
      , load_into_x509_store("load_into_x509_store", traits, *this)
      , new_x509_crl("new_x509_crl", traits, *this)
      , delete_x509_crl("delete_x509_crl", traits, *this)
      , new_x509("new_x509", traits, *this)
      , get_x509_pubkey("get_x509_pubkey", traits, *this)
      , delete_x509("delete_x509", traits, *this)
      , read_bio_private_key("read_bio_private_key", traits, *this)
      , read_bio_public_key("read_bio_public_key", traits, *this)
      , read_bio_x509_crl("read_bio_x509_crl", traits, *this)
      , read_bio_x509("read_bio_x509", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef SSLPAFP
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_API_HPP

