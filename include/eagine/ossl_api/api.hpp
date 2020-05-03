/**
 *  @file eagine/ossl_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_API_HPP
#define EAGINE_OSSL_API_API_HPP

#include "c_api.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
#define OSSLPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_ossl_operations : public basic_ossl_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_ossl_c_api<ApiTraits>;

    using evp_md_ctx_type = ossl_types::evp_md_ctx_type;
    using evp_md_type = ossl_types::evp_md_type;

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

    // message_digest_null
    func<OSSLPAFP(evp_md_null)> message_digest_noop;
    func<OSSLPAFP(evp_md5)> message_digest_md5;
    func<OSSLPAFP(evp_sha1)> message_digest_sha1;
    func<OSSLPAFP(evp_sha224)> message_digest_sha224;
    func<OSSLPAFP(evp_sha256)> message_digest_sha256;
    func<OSSLPAFP(evp_sha384)> message_digest_sha384;
    func<OSSLPAFP(evp_sha512)> message_digest_sha512;

    func<OSSLPAFP(evp_md_size)> message_digest_size;

    // message_digest_new
    func<OSSLPAFP(evp_md_ctx_new)> message_digest_new;

    // message_digest_init
    func<OSSLPAFP(evp_digest_init)> message_digest_init;

    // message_digest_init_ex
    func<OSSLPAFP(evp_digest_init_ex)> message_digest_init_ex;

    // message_digest_update
    struct : func<OSSLPAFP(evp_digest_update)> {
        using func<OSSLPAFP(evp_digest_update)>::func;

        constexpr auto operator()(
          evp_md_ctx_type* ctx, memory::const_block blk) const noexcept {
            return this->_chkcall(ctx, blk.data(), std_size(blk.size()));
        }

    } message_digest_update;

    // message_digest_final
    struct : func<OSSLPAFP(evp_digest_final)> {
        using func<OSSLPAFP(evp_digest_final)>::func;

        constexpr auto operator()(evp_md_ctx_type* ctx, memory::block blk) const
          noexcept {
            unsigned int size{0U};
            return this->_chkcall(ctx, blk.data(), &size)
              .replaced_with(head(blk, span_size(size)));
        }
    } message_digest_final;

    constexpr basic_ossl_operations(api_traits& traits)
      : c_api{traits}
      , message_digest_noop("message_digest_noop", traits, *this)
      , message_digest_md5("message_digest_md5", traits, *this)
      , message_digest_sha1("message_digest_sha1", traits, *this)
      , message_digest_sha224("message_digest_sha224", traits, *this)
      , message_digest_sha256("message_digest_sha256", traits, *this)
      , message_digest_sha384("message_digest_sha384", traits, *this)
      , message_digest_sha512("message_digest_sha512", traits, *this)
      , message_digest_size("message_digest_size", traits, *this)
      , message_digest_new("message_digest_new", traits, *this)
      , message_digest_init("message_digest_init", traits, *this)
      , message_digest_init_ex("message_digest_init_ex", traits, *this)
      , message_digest_update("message_digest_update", traits, *this)
      , message_digest_final("message_digest_final", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef OSSLPAFP
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

#endif // EAGINE_OSSL_API_API_HPP

