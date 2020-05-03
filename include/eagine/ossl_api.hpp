/**
 *  @file eagine/ossl_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_HPP
#define EAGINE_OSSL_API_HPP

#include "memory/block.hpp"
#include "ossl_api/api.hpp"
#include "ossl_api/api_traits.hpp"
#include "ossl_api/constants.hpp"
#include "ossl_api_fwd.hpp"

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_ossl_api
  : protected ApiTraits
  , public basic_ossl_operations<ApiTraits>
  , public basic_ossl_constants<ApiTraits> {
public:
    using evp_md_type = ossl_types::evp_md_type;

    basic_ossl_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_ossl_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_ossl_constants<ApiTraits>{
          *static_cast<ApiTraits*>(this),
          *static_cast<basic_ossl_operations<ApiTraits>*>(this)} {
    }

    basic_ossl_api()
      : basic_ossl_api{ApiTraits{}} {
    }

    memory::block data_digest(
      memory::const_block data, memory::block dst, const evp_md_type* mdtype) {
        if(mdtype) {
            if(dst.size() >= span_size(this->evp_md_size(mdtype))) {
                if(auto optmdctx = this->message_digest_new()) {
                    auto mdctx{extract(optmdctx)};
                    auto cleanup{this->message_digest_free.raii(mdctx)};
                    this->message_digest_init(mdctx, mdtype);
                    this->message_digest_update(mdctx, data);
                    return extract_or(
                      this->message_digest_final(mdctx, dst), memory::block{});
                }
            }
        }
        return {};
    }

    auto md5_digest(memory::const_block data, memory::block dst) {
        return data_digest(data, dst, this->evp_md5());
    }

    auto sha1_digest(memory::const_block data, memory::block dst) {
        return data_digest(data, dst, this->evp_sha1());
    }

    auto sha224_digest(memory::const_block data, memory::block dst) {
        return data_digest(data, dst, this->evp_sha224());
    }

    auto sha256_digest(memory::const_block data, memory::block dst) {
        return data_digest(data, dst, this->evp_sha256());
    }

    auto sha384_digest(memory::const_block data, memory::block dst) {
        return data_digest(data, dst, this->evp_sha384());
    }

    auto sha512_digest(memory::const_block data, memory::block dst) {
        return data_digest(data, dst, this->evp_sha512());
    }
};
//------------------------------------------------------------------------------
template <std::size_t I, typename ApiTraits>
typename std::tuple_element<I, basic_ossl_api<ApiTraits>>::type& get(
  basic_ossl_api<ApiTraits>& x) noexcept {
    return x;
}

template <std::size_t I, typename ApiTraits>
const typename std::tuple_element<I, basic_ossl_api<ApiTraits>>::type& get(
  const basic_ossl_api<ApiTraits>& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct tuple_size<eagine::osslp::basic_ossl_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

template <typename ApiTraits>
struct tuple_element<0, eagine::osslp::basic_ossl_api<ApiTraits>> {
    using type = eagine::osslp::basic_ossl_operations<ApiTraits>;
};

template <typename ApiTraits>
struct tuple_element<1, eagine::osslp::basic_ossl_api<ApiTraits>> {
    using type = eagine::osslp::basic_ossl_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

#endif // EAGINE_OSSL_API_HPP

