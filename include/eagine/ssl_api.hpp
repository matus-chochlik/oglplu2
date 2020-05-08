/**
 *  @file eagine/ssl_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_HPP
#define EAGINE_SSL_API_HPP

#include "memory/block.hpp"
#include "ssl_api/api.hpp"
#include "ssl_api/api_traits.hpp"
#include "ssl_api/constants.hpp"
#include "ssl_api_fwd.hpp"

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_ssl_api
  : protected ApiTraits
  , public basic_ssl_operations<ApiTraits>
  , public basic_ssl_constants<ApiTraits> {
public:
    template <typename R>
    using combined_result = typename ApiTraits::template combined_result<R>;

    using evp_md_type = ssl_types::evp_md_type;

    basic_ssl_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_ssl_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_ssl_constants<ApiTraits>{
          *static_cast<ApiTraits*>(this),
          *static_cast<basic_ssl_operations<ApiTraits>*>(this)} {
    }

    basic_ssl_api()
      : basic_ssl_api{ApiTraits{}} {
    }

    template <typename Function>
    void for_each_engine(Function function) {
        if(auto opt_eng = this->get_first_engine()) {
            owned_engine eng = std::move(extract(opt_eng));
            while(eng) {
                function(engine(eng));
                opt_eng = this->get_next_engine(eng);
                if(opt_eng) {
                    eng = std::move(extract(opt_eng));
                }
            }
        }
    }

    memory::block data_digest(
      memory::const_block data, memory::block dst, message_digest_type mdtype) {
        if(mdtype) {
            const auto req_size =
              extract_or(this->message_digest_size(mdtype), 0);

            if(dst.size() >= span_size(req_size)) {
                if(ok mdctx{this->new_message_digest()}) {
                    auto cleanup{this->delete_message_digest.raii(mdctx)};

                    this->message_digest_init(mdctx, mdtype);
                    this->message_digest_update(mdctx, data);
                    return extract_or(
                      this->message_digest_final(mdctx, dst), memory::block{});
                }
            }
        }
        return {};
    }

    template <typename OptMdt>
    memory::block do_data_digest(
      memory::const_block data, memory::block dst, OptMdt opt_mdtype) {
        if(opt_mdtype) {
            return data_digest(data, dst, extract(opt_mdtype));
        }
        return {};
    }

    auto md5_digest(memory::const_block data, memory::block dst) {
        return do_data_digest(data, dst, this->message_digest_md5());
    }

    auto sha1_digest(memory::const_block data, memory::block dst) {
        return do_data_digest(data, dst, this->message_digest_sha1());
    }

    auto sha224_digest(memory::const_block data, memory::block dst) {
        return do_data_digest(data, dst, this->message_digest_sha224());
    }

    auto sha256_digest(memory::const_block data, memory::block dst) {
        return do_data_digest(data, dst, this->message_digest_sha256());
    }

    auto sha384_digest(memory::const_block data, memory::block dst) {
        return do_data_digest(data, dst, this->message_digest_sha384());
    }

    auto sha512_digest(memory::const_block data, memory::block dst) {
        return do_data_digest(data, dst, this->message_digest_sha512());
    }

    memory::block sign_data_digest(
      memory::const_block data,
      memory::block dst,
      message_digest_type mdtype,
      pkey pky) {
        if(mdtype && pky) {
            if(ok mdctx{this->new_message_digest()}) {
                auto cleanup{this->delete_message_digest.raii(mdctx)};

                if(this->message_digest_sign_init(mdctx, mdtype, pky)) {
                    if(this->message_digest_sign_update(mdctx, data)) {
                        return extract_or(
                          this->message_digest_sign_final(mdctx, dst),
                          memory::block{});
                    }
                }
            }
        }
        return {};
    }

    bool verify_data_digest(
      memory::const_block data,
      memory::const_block sig,
      message_digest_type mdtype,
      pkey pky) {
        if(mdtype && pky) {
            if(ok mdctx{this->new_message_digest()}) {
                auto cleanup{this->delete_message_digest.raii(mdctx)};

                if(this->message_digest_verify_init(mdctx, mdtype, pky)) {
                    if(this->message_digest_verify_update(mdctx, data)) {
                        return extract_or(
                          this->message_digest_verify_final(mdctx, sig), false);
                    }
                }
            }
        }
        return false;
    }

    combined_result<owned_x509> parse_x509(
      memory::const_block blk, password_callback get_passwd) const noexcept {
        if(ok mbio{this->new_block_basic_io(blk)}) {
            auto del_bio{this->delete_basic_io.raii(mbio)};

            return this->read_bio_x509(mbio, get_passwd);
        }

        return {owned_x509{}};
    }

    bool ca_verify_certificate(string_view ca_file_path, x509 cert) {
        if(ok store{this->new_x509_store()}) {
            auto del_store{this->delete_x509_store.raii(store)};

            if(this->load_into_x509_store(store, ca_file_path)) {
                if(ok vrfy_ctx{this->new_x509_store_ctx()}) {
                    auto del_vrfy{this->delete_x509_store_ctx.raii(vrfy_ctx)};

                    if(this->init_x509_store_ctx(vrfy_ctx, store, cert)) {
                        if(ok verify_res{
                             this->x509_verify_certificate(vrfy_ctx)}) {
                            return verify_res.get();
                        }
                    }
                }
            }
        }
        return false;
    }
};
//------------------------------------------------------------------------------
template <std::size_t I, typename ApiTraits>
typename std::tuple_element<I, basic_ssl_api<ApiTraits>>::type& get(
  basic_ssl_api<ApiTraits>& x) noexcept {
    return x;
}

template <std::size_t I, typename ApiTraits>
const typename std::tuple_element<I, basic_ssl_api<ApiTraits>>::type& get(
  const basic_ssl_api<ApiTraits>& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct tuple_size<eagine::sslp::basic_ssl_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

template <typename ApiTraits>
struct tuple_element<0, eagine::sslp::basic_ssl_api<ApiTraits>> {
    using type = eagine::sslp::basic_ssl_operations<ApiTraits>;
};

template <typename ApiTraits>
struct tuple_element<1, eagine::sslp::basic_ssl_api<ApiTraits>> {
    using type = eagine::sslp::basic_ssl_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

#endif // EAGINE_SSL_API_HPP

