/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/copy.hpp>
#include <eagine/message_bus/context.hpp>
#include <eagine/random_bytes.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::context(logger& parent)
  : _log{EAGINE_ID(MsgBusCtxt), parent} {

    if(ok make_result{_ssl.new_x509_store()}) {
        _ssl_store = std::move(make_result.get());
    } else {
        _log.error("failed to create certificate store: ${reason}")
          .arg(EAGINE_ID(reason), (!make_result).message());
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::context(logger& parent, const program_args& args)
  : context{parent} {
    std::string temp;
    for(auto arg = args.first(); arg; arg = arg.next()) {
        if(arg.is_tag("--msg-bus-ssl-engine")) {
            if(arg.next().parse(temp, _log.error_stream())) {
                _ssl.load_builtin_engines();

                if(ok open_result{_ssl.open_engine(temp)}) {
                    _ssl_engine = std::move(open_result.get());
                    if(ok init_result{_ssl.init_engine(_ssl_engine)}) {
                        _log.info("successfully loaded ssl engine ${name}")
                          .arg(EAGINE_ID(name), temp);
                    } else {
                        _log
                          .error("failed to init ssl engine ${name}: ${reason}")
                          .arg(EAGINE_ID(name), temp)
                          .arg(EAGINE_ID(reason), (!init_result).message());
                    }
                } else {
                    _log.error("failed to load ssl engine ${name}: ${reason}")
                      .arg(EAGINE_ID(name), temp)
                      .arg(EAGINE_ID(reason), (!open_result).message());
                }
                arg = arg.next();
            }
        } else if(arg.is_tag("--msg-bus-pkey-id")) {
            if(arg.next().parse(temp, _log.error_stream())) {
                if(ok uim_result{_ssl.openssl_ui()}) {
                    if(ok pkey_result{_ssl.load_engine_private_key(
                         _ssl_engine, temp, uim_result)}) {
                        if(_own_pkey) {
                            _ssl.delete_pkey(_own_pkey);
                        }
                        _own_pkey = std::move(pkey_result.get());
                        _log.info("successfully loaded ssl key ${keyId}")
                          .arg(EAGINE_ID(keyId), temp);
                    } else {
                        _log.error("failed load ssl key ${keyId}: ${reason}")
                          .arg(EAGINE_ID(keyId), temp)
                          .arg(EAGINE_ID(reason), (!pkey_result).message());
                    }
                } else {
                    _log.error("failed get ssl ui method: ${reason}")
                      .arg(EAGINE_ID(reason), (!uim_result).message());
                }
                arg = arg.next();
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::~context() noexcept {
    for(auto& remote : _remotes) {
        auto& info = std::get<1>(remote);
        _ssl.delete_pkey(info.pubkey);
        _ssl.delete_x509(info.cert);
    }

    if(_own_pkey) {
        _ssl.delete_pkey(_own_pkey);
    }

    if(_ca_cert) {
        _ssl.delete_x509(_ca_cert);
    }

    if(_own_cert) {
        _ssl.delete_x509(_own_cert);
    }

    if(_ssl_store) {
        _ssl.delete_x509_store(_ssl_store);
    }

    if(_ssl_engine) {
        _ssl.finish_engine(_ssl_engine);
        _ssl.delete_engine(_ssl_engine);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
message_sequence_t context::next_sequence_no(message_id msg_id) noexcept {

    auto [pos, newone] = _msg_id_seq.try_emplace(msg_id);

    if(newone) {
        std::get<1>(*pos) = 0U;
        _log.debug("creating sequence for message type ${message}")
          .arg(EAGINE_ID(message), msg_id);
    }
    return std::get<1>(*pos)++;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::verify_certificate(sslp::x509 cert) {
    if(ok vrfy_ctx{_ssl.new_x509_store_ctx()}) {
        auto del_vrfy{_ssl.delete_x509_store_ctx.raii(vrfy_ctx)};

        if(_ssl.init_x509_store_ctx(vrfy_ctx, _ssl_store, cert)) {
            if(ok verify_res{_ssl.x509_verify_certificate(vrfy_ctx)}) {
                return verify_res.get();
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::add_own_certificate_pem(memory::const_block blk) {
    if(blk) {
        if(ok cert{_ssl.parse_x509(blk, {})}) {
            if(_own_cert) {
                _ssl.delete_x509(_own_cert);
            }
            _own_cert = std::move(cert.get());
            memory::copy_into(blk, _own_cert_pem);
            return verify_certificate(_own_cert);
        } else {
            _log.error("failed to parse own x509 certificate from pem")
              .arg(EAGINE_ID(reason), (!cert).message())
              .arg(EAGINE_ID(pem), blk);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::add_ca_certificate_pem(memory::const_block blk) {
    if(blk) {
        if(ok cert{_ssl.parse_x509(blk, {})}) {
            if(_ssl.add_cert_into_x509_store(_ssl_store, cert)) {
                if(_ca_cert) {
                    _ssl.delete_x509(_ca_cert);
                }
                _ca_cert = std::move(cert.get());
                memory::copy_into(blk, _ca_cert_pem);
                return verify_certificate(_own_cert);
            } else {
                _log.error("failed to add x509 CA certificate to store")
                  .arg(EAGINE_ID(reason), (!cert).message())
                  .arg(EAGINE_ID(pem), blk);
            }
        } else {
            _log.error("failed to parse CA x509 certificate from pem")
              .arg(EAGINE_ID(reason), (!cert).message())
              .arg(EAGINE_ID(pem), blk);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::add_remote_certificate_pem(
  identifier_t node_id, memory::const_block blk) {
    if(blk) {
        if(ok cert{_ssl.parse_x509(blk, {})}) {
            auto& info = _remotes[node_id];
            if(info.cert) {
                _ssl.delete_x509(info.cert);
            }
            if(info.pubkey) {
                _ssl.delete_pkey(info.pubkey);
            }
            info.cert = std::move(cert.get());
            memory::copy_into(blk, info.cert_pem);
            if(verify_certificate(info.cert)) {
                if(ok pubkey{_ssl.get_x509_pubkey(info.cert)}) {
                    info.pubkey = std::move(pubkey.get());
                    fill_with_random_bytes(
                      cover(info.nonce), any_random_engine{_rand_engine});
                    return true;
                } else {
                    _log.error("failed to get remote node x509 public key")
                      .arg(EAGINE_ID(nodeId), node_id)
                      .arg(EAGINE_ID(reason), (!pubkey).message())
                      .arg(EAGINE_ID(pem), blk);
                }
            }
        } else {
            _log.error("failed to parse remote node x509 certificate from pem")
              .arg(EAGINE_ID(nodeId), node_id)
              .arg(EAGINE_ID(reason), (!cert).message())
              .arg(EAGINE_ID(pem), blk);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block context::get_remote_certificate_pem(
  identifier_t node_id) const noexcept {
    auto pos = _remotes.find(node_id);
    if(pos != _remotes.end()) {
        return view(std::get<1>(*pos).cert_pem);
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block context::get_remote_nonce(identifier_t node_id) const
  noexcept {
    auto pos = _remotes.find(node_id);
    if(pos != _remotes.end()) {
        return view(std::get<1>(*pos).nonce);
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::verified_remote_key(identifier_t node_id) const noexcept {
    auto pos = _remotes.find(node_id);
    if(pos != _remotes.end()) {
        return std::get<1>(*pos).verified_key;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
decltype(std::declval<sslp::ssl_api&>().message_digest_sha256())
context::default_message_digest() noexcept {
    return _ssl.message_digest_sha256();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
decltype(std::declval<sslp::ssl_api&>().message_digest_sign_init.fake())
context::message_digest_sign_init(
  sslp::message_digest mdc, sslp::message_digest_type mdt) noexcept {
    if(_own_pkey) {
        return _ssl.message_digest_sign_init(mdc, mdt, _own_pkey);
    }
    return _ssl.message_digest_sign_init.fake();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
decltype(std::declval<sslp::ssl_api&>().message_digest_verify_init.fake())
context::message_digest_verify_init(
  sslp::message_digest mdc,
  sslp::message_digest_type mdt,
  identifier_t node_id) noexcept {
    auto pos = _remotes.find(node_id);
    if(pos != _remotes.end()) {
        return _ssl.message_digest_verify_init(
          mdc, mdt, std::get<1>(*pos).pubkey);
    } else {
        _log.debug("could not find remote node ${endpoint} for verification")
          .arg(EAGINE_ID(endpoint), node_id);
    }
    return _ssl.message_digest_verify_init.fake();
}
//------------------------------------------------------------------------------
memory::const_block context::get_own_signature(memory::const_block nonce) {
    if(ok md_type{default_message_digest()}) {
        if(ok md_ctx{_ssl.new_message_digest()}) {
            auto cleanup{_ssl.delete_message_digest.raii(md_ctx)};

            if(EAGINE_LIKELY(message_digest_sign_init(md_ctx, md_type))) {
                if(EAGINE_LIKELY(
                     _ssl.message_digest_sign_update(md_ctx, nonce))) {
                    const auto req_size{
                      _ssl.message_digest_sign_final.required_size(md_ctx)};

                    _scratch_space.ensure(extract_or(req_size, 0));
                    auto free{cover(_scratch_space)};

                    if(ok sig{_ssl.message_digest_sign_final(md_ctx, free)}) {
                        return sig.get();
                    } else {
                        _log.debug("failed to finish ssl signature")
                          .arg(EAGINE_ID(freeSize), free.size())
                          .arg(EAGINE_ID(reason), (!sig).message());
                    }
                } else {
                    _log.debug("failed to update ssl signature");
                }
            } else {
                _log.debug("failed to init ssl sign context");
            }
        } else {
            _log.debug("failed to create ssl message digest")
              .arg(EAGINE_ID(reason), (!md_ctx).message());
        }
    } else {
        _log.debug("failed to get ssl message digest type")
          .arg(EAGINE_ID(reason), (!md_type).message());
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
verification_bits context::verify_remote_signature(
  memory::const_block content,
  memory::const_block signature,
  identifier_t node_id,
  bool verified_key) {
    verification_bits result{};

    if(ok md_type{default_message_digest()}) {
        if(ok md_ctx{_ssl.new_message_digest()}) {
            auto cleanup{_ssl.delete_message_digest.raii(md_ctx)};

            if(EAGINE_LIKELY(
                 message_digest_verify_init(md_ctx, md_type, node_id))) {
                if(EAGINE_LIKELY(
                     _ssl.message_digest_verify_update(md_ctx, content))) {
                    if(extract_or(
                         _ssl.message_digest_verify_final(md_ctx, signature),
                         false)) {

                        if(verified_key || verified_remote_key(node_id)) {
                            result |= verification_bit::source_private_key;
                        }

                        result |= verification_bit::source_certificate;
                        result |= verification_bit::message_content;

                    } else {
                        _log.debug("failed to finish ssl verification");
                    }
                } else {
                    _log.debug("failed to update ssl verify context");
                }
            } else {
                _log.debug("failed to init ssl verify context");
            }
        } else {
            _log.debug("failed to create ssl message digest")
              .arg(EAGINE_ID(reason), (!md_ctx).message());
        }
    } else {
        _log.debug("failed to get ssl message digest type")
          .arg(EAGINE_ID(reason), (!md_type).message());
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool context::verify_remote_signature(
  memory::const_block sig, identifier_t node_id) {
    auto pos = _remotes.find(node_id);
    if(pos != _remotes.end()) {
        auto& remote{std::get<1>(*pos)};
        const auto result{
          verify_remote_signature(view(remote.nonce), sig, node_id, true)};
        if(result.has(verification_bit::message_content)) {
            remote.verified_key = true;
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::shared_ptr<context> make_context(logger& parent) {
    return std::make_shared<context>(parent);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC std::shared_ptr<context> make_context(
  logger& parent, const program_args& args) {
    return std::make_shared<context>(parent, args);
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine
