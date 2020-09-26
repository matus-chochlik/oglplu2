/**
 *  @file eagine/ssl_api.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::sslp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
inline auto basic_ssl_api<ApiTraits>::data_digest(
  memory::const_block data,
  memory::block dst,
  message_digest_type mdtype) const noexcept -> memory::block {
    if(mdtype) {
        const auto req_size = extract_or(this->message_digest_size(mdtype), 0);

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
//------------------------------------------------------------------------------
template <typename ApiTraits>
inline auto basic_ssl_api<ApiTraits>::sign_data_digest(
  memory::const_block data,
  memory::block dst,
  message_digest_type mdtype,
  pkey pky) const noexcept -> memory::block {
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
//------------------------------------------------------------------------------
template <typename ApiTraits>
inline auto basic_ssl_api<ApiTraits>::verify_data_digest(
  memory::const_block data,
  memory::const_block sig,
  message_digest_type mdtype,
  pkey pky) const noexcept -> bool {
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
//------------------------------------------------------------------------------
template <typename ApiTraits>
auto basic_ssl_api<ApiTraits>::parse_private_key(
  memory::const_block blk,
  password_callback get_passwd) const noexcept -> combined_result<owned_pkey> {
    if(ok mbio{this->new_block_basic_io(blk)}) {
        auto del_bio{this->delete_basic_io.raii(mbio)};

        return this->read_bio_private_key(mbio, get_passwd);
    }

    return {owned_pkey{}};
}
//------------------------------------------------------------------------------
template <typename ApiTraits>
auto basic_ssl_api<ApiTraits>::parse_public_key(
  memory::const_block blk,
  password_callback get_passwd) const noexcept -> combined_result<owned_pkey> {
    if(ok mbio{this->new_block_basic_io(blk)}) {
        auto del_bio{this->delete_basic_io.raii(mbio)};

        return this->read_bio_public_key(mbio, get_passwd);
    }

    return {owned_pkey{}};
}
//------------------------------------------------------------------------------
template <typename ApiTraits>
auto basic_ssl_api<ApiTraits>::parse_x509(
  memory::const_block blk,
  password_callback get_passwd) const noexcept -> combined_result<owned_x509> {
    if(ok mbio{this->new_block_basic_io(blk)}) {
        auto del_bio{this->delete_basic_io.raii(mbio)};

        return this->read_bio_x509(mbio, get_passwd);
    }

    return {owned_x509{}};
}
//------------------------------------------------------------------------------
template <typename ApiTraits>
auto basic_ssl_api<ApiTraits>::ca_verify_certificate(
  string_view ca_file_path,
  x509 cert) const noexcept -> bool {
    if(ok store{this->new_x509_store()}) {
        auto del_store{this->delete_x509_store.raii(store)};

        if(this->load_into_x509_store(store, ca_file_path)) {
            if(ok vrfy_ctx{this->new_x509_store_ctx()}) {
                auto del_vrfy{this->delete_x509_store_ctx.raii(vrfy_ctx)};

                if(this->init_x509_store_ctx(vrfy_ctx, store, cert)) {
                    if(ok verify_res{this->x509_verify_certificate(vrfy_ctx)}) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename ApiTraits>
auto basic_ssl_api<ApiTraits>::ca_verify_certificate(x509 ca_cert, x509 cert)
  const noexcept -> bool {
    if(ok store{this->new_x509_store()}) {
        auto del_store{this->delete_x509_store.raii(store)};

        if(this->add_cert_into_x509_store(store, ca_cert)) {
            if(ok vrfy_ctx{this->new_x509_store_ctx()}) {
                auto del_vrfy{this->delete_x509_store_ctx.raii(vrfy_ctx)};

                if(this->init_x509_store_ctx(vrfy_ctx, store, cert)) {
                    if(ok verify_res{this->x509_verify_certificate(vrfy_ctx)}) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine::sslp
