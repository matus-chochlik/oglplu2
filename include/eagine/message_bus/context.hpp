/**
 *  @file eagine/message_bus/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_CONTEXT_HPP
#define EAGINE_MESSAGE_BUS_CONTEXT_HPP

#include "../flat_map.hpp"
#include "../logging/logger.hpp"
#include "../memory/buffer.hpp"
#include "../message_id.hpp"
#include "../ssl.hpp"
#include "../ssl_api.hpp"
#include "context_fwd.hpp"
#include "types.hpp"
#include "verification.hpp"
#include <array>
#include <map>
#include <random>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct context_remote_node {
    std::array<byte, 256> nonce{};
    memory::buffer cert_pem;
    sslp::owned_x509 cert{};
    sslp::owned_pkey pubkey{};
    bool verified_key{false};
};
//------------------------------------------------------------------------------
class context {
public:
    context(logger& parent);
    context(logger& parent, const program_args& args);

    context(context&&) = delete;
    context(const context&) = delete;
    auto operator=(context&&) = delete;
    auto operator=(const context&) = delete;

    ~context() noexcept;

    auto ssl() noexcept -> sslp::ssl_api& {
        return _ssl;
    }

    auto next_sequence_no(message_id) noexcept -> message_sequence_t;

    auto verify_certificate(sslp::x509 cert) -> bool;

    auto add_own_certificate_pem(memory::const_block) -> bool;
    auto add_ca_certificate_pem(memory::const_block) -> bool;
    auto add_remote_certificate_pem(identifier_t node_id, memory::const_block)
      -> bool;
    auto add_router_certificate_pem(memory::const_block blk) -> bool {
        return add_remote_certificate_pem(0, blk);
    }

    auto get_own_certificate_pem() const noexcept -> memory::const_block {
        return view(_own_cert_pem);
    }

    auto get_ca_certificate_pem() const noexcept -> memory::const_block {
        return view(_ca_cert_pem);
    }

    auto get_remote_certificate_pem(identifier_t) const noexcept
      -> memory::const_block;

    auto get_router_certificate_pem() const noexcept -> memory::const_block {
        return get_remote_certificate_pem(0);
    }

    auto get_remote_nonce(identifier_t) const noexcept -> memory::const_block;
    auto verified_remote_key(identifier_t) const noexcept -> bool;

    auto default_message_digest() noexcept
      -> decltype(ssl().message_digest_sha256());

    auto message_digest_sign_init(
      sslp::message_digest mdc,
      sslp::message_digest_type mdt) noexcept
      -> decltype(ssl().message_digest_sign_init.fake());

    auto message_digest_verify_init(
      sslp::message_digest mdc,
      sslp::message_digest_type mdt,
      identifier_t node_id) noexcept
      -> decltype(ssl().message_digest_verify_init.fake());

    auto get_own_signature(memory::const_block) -> memory::const_block;

    auto verify_remote_signature(
      memory::const_block data,
      memory::const_block sig,
      identifier_t,
      bool = false) -> verification_bits;

    auto verify_remote_signature(memory::const_block sig, identifier_t) -> bool;

private:
    logger _log{};
    //
    std::mt19937_64 _rand_engine{std::random_device{}()};
    flat_map<message_id, message_sequence_t> _msg_id_seq{};
    //
    memory::buffer _scratch_space{};
    memory::buffer _own_cert_pem{};
    memory::buffer _ca_cert_pem{};
    //
    sslp::ssl_api _ssl{};
    sslp::owned_engine _ssl_engine{};
    sslp::owned_x509_store _ssl_store{};
    sslp::owned_x509 _own_cert{};
    sslp::owned_x509 _ca_cert{};
    sslp::owned_pkey _own_pkey{};
    //
    std::map<identifier_t, context_remote_node> _remotes{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/context.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_CONTEXT_HPP
