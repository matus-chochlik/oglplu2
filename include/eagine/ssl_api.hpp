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

namespace eagine::sslp {
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
    void for_each_engine(Function function) const {
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
      memory::const_block data,
      memory::block dst,
      message_digest_type mdtype) const noexcept;

    template <typename OptMdt>
    memory::block do_data_digest(
      memory::const_block data,
      memory::block dst,
      OptMdt opt_mdtype) const noexcept {
        if(opt_mdtype) {
            return data_digest(data, dst, extract(opt_mdtype));
        }
        return {};
    }

    auto md5_digest(
      memory::const_block data, memory::block dst) const noexcept {
        return do_data_digest(data, dst, this->message_digest_md5());
    }

    auto sha1_digest(
      memory::const_block data, memory::block dst) const noexcept {
        return do_data_digest(data, dst, this->message_digest_sha1());
    }

    auto sha224_digest(
      memory::const_block data, memory::block dst) const noexcept {
        return do_data_digest(data, dst, this->message_digest_sha224());
    }

    auto sha256_digest(
      memory::const_block data, memory::block dst) const noexcept {
        return do_data_digest(data, dst, this->message_digest_sha256());
    }

    auto sha384_digest(
      memory::const_block data, memory::block dst) const noexcept {
        return do_data_digest(data, dst, this->message_digest_sha384());
    }

    auto sha512_digest(
      memory::const_block data, memory::block dst) const noexcept {
        return do_data_digest(data, dst, this->message_digest_sha512());
    }

    memory::block sign_data_digest(
      memory::const_block data,
      memory::block dst,
      message_digest_type mdtype,
      pkey pky) const noexcept;

    bool verify_data_digest(
      memory::const_block data,
      memory::const_block sig,
      message_digest_type mdtype,
      pkey pky) const noexcept;

    combined_result<owned_pkey> parse_private_key(
      memory::const_block blk,
      password_callback get_passwd = {}) const noexcept;

    combined_result<owned_pkey> parse_public_key(
      memory::const_block blk,
      password_callback get_passwd = {}) const noexcept;

    combined_result<owned_x509> parse_x509(
      memory::const_block blk,
      password_callback get_passwd = {}) const noexcept;

    bool ca_verify_certificate(
      string_view ca_file_path, x509 cert) const noexcept;

    bool ca_verify_certificate(x509 ca_cert, x509 cert) const noexcept;
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
} // namespace eagine::sslp

#include <eagine/ssl_api.inl>

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

