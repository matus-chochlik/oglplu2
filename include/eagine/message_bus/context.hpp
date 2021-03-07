/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_CONTEXT_HPP
#define EAGINE_MESSAGE_BUS_CONTEXT_HPP

#include "../flat_map.hpp"
#include "../main_ctx_object.hpp"
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
/// @brief Class holding common message bus utility objects.
/// @ingroup msgbus
class context : main_ctx_object {
public:
    context(main_ctx_parent parent);

    /// @brief Not move constructible.
    context(context&&) = delete;

    /// @brief Not copy constructible.
    context(const context&) = delete;

    /// @brief Not move assignable.
    auto operator=(context&&) = delete;

    /// @brief Not copy assignable.
    auto operator=(const context&) = delete;

    ~context() noexcept;

    /// @brief Returns a reference to the SSL API wrapper.
    auto ssl() noexcept -> sslp::ssl_api& {
        return _ssl;
    }

    /// @brief Returns the next sequence number value for the specified message type.
    auto next_sequence_no(message_id) noexcept -> message_sequence_t;

    /// @brief Verifies the specified x509 certificate.
    auto verify_certificate(sslp::x509 cert) -> bool;

    /// @brief Sets this bus node certificate encoded in PEM format.
    /// @see get_own_certificate_pem
    /// @see add_ca_certificate_pem
    /// @see add_remote_certificate_pem
    /// @see add_router_certificate_pem
    auto add_own_certificate_pem(memory::const_block) -> bool;

    /// @brief Sets a CA certificate encoded in PEM format.
    /// @see get_ca_certificate_pem
    /// @see add_own_certificate_pem
    /// @see add_remote_certificate_pem
    /// @see add_router_certificate_pem
    auto add_ca_certificate_pem(memory::const_block) -> bool;

    /// @brief Sets remote bus node certificate encoded in PEM format.
    /// @see get_remote_certificate_pem
    /// @see add_ca_certificate_pem
    /// @see add_remote_certificate_pem
    /// @see add_router_certificate_pem
    auto add_remote_certificate_pem(identifier_t node_id, memory::const_block)
      -> bool;

    /// @brief Sets the router certificate encoded in PEM format.
    /// @see get_router_certificate_pem
    /// @see add_own_certificate_pem
    /// @see add_ca_certificate_pem
    /// @see add_remote_certificate_pem
    auto add_router_certificate_pem(memory::const_block blk) -> bool {
        return add_remote_certificate_pem(0, blk);
    }

    /// @brief Gets this bus node certificate encoded in PEM format.
    /// @see add_own_certificate_pem
    /// @see get_ca_certificate_pem
    /// @see get_remote_certificate_pem
    /// @see get_router_certificate_pem
    auto get_own_certificate_pem() const noexcept -> memory::const_block {
        return view(_own_cert_pem);
    }

    /// @brief Gets the CA certificate encoded in PEM format.
    /// @see add_ca_certificate_pem
    /// @see get_own_certificate_pem
    /// @see get_remote_certificate_pem
    /// @see get_router_certificate_pem
    auto get_ca_certificate_pem() const noexcept -> memory::const_block {
        return view(_ca_cert_pem);
    }

    /// @brief Gets remote bus node certificate encoded in PEM format.
    /// @see add_remote_certificate_pem
    /// @see get_ca_certificate_pem
    /// @see get_remote_certificate_pem
    /// @see get_router_certificate_pem
    auto get_remote_certificate_pem(identifier_t) const noexcept
      -> memory::const_block;

    /// @brief Gets the router certificate encoded in PEM format.
    /// @see add_router_certificate_pem
    /// @see get_own_certificate_pem
    /// @see get_ca_certificate_pem
    /// @see get_remote_certificate_pem
    auto get_router_certificate_pem() const noexcept -> memory::const_block {
        return get_remote_certificate_pem(0);
    }

    auto get_remote_nonce(identifier_t) const noexcept -> memory::const_block;

    /// @brief Indicates if the private key of a remote node was verified.
    auto verified_remote_key(identifier_t) const noexcept -> bool;

    /// @brief Returns the default message digest type.
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

    /// @brief Signs the specified memory block and returns the signature.
    auto get_own_signature(memory::const_block) -> memory::const_block;

    auto verify_remote_signature(
      memory::const_block data,
      memory::const_block sig,
      identifier_t,
      bool = false) -> verification_bits;

    /// @brief Verifies the signature on a data block from a remote node.
    auto verify_remote_signature(memory::const_block sig, identifier_t) -> bool;

private:
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
