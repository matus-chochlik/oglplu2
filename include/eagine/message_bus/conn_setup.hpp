/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_CONN_SETUP_HPP
#define EAGINE_MESSAGE_BUS_CONN_SETUP_HPP

#include "../enum_map.hpp"
#include "../main_ctx_object.hpp"
#include "conn_factory.hpp"
#include <memory>
#include <mutex>
#include <vector>

namespace eagine {
class application_config;
namespace msgbus {
//------------------------------------------------------------------------------
class connection_setup;
void connection_setup_default_init(connection_setup&);
//------------------------------------------------------------------------------
static inline auto adapt_log_entry_arg(
  identifier name,
  const std::unique_ptr<connection_factory>& value) {
    return [name, &value](logger_backend& backend) {
        if(value) {
            backend.add_identifier(
              name, EAGINE_ID(ConnFactry), value->type_id());
        } else {
            backend.add_nothing(name, EAGINE_ID(ConnFactry));
        }
    };
}
//------------------------------------------------------------------------------
/// @brief Class setting up connections based from configuration
/// @ingroup msgbus
/// @see connection_kind
/// @see connection
/// @see acceptor
/// @see application_config
class connection_setup : public main_ctx_object {
public:
    /// @brief Construction from a parent main context object.
    connection_setup(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(ConnSetup), parent} {
        default_init();
    }

    /// @brief Sets up acceptors listening on the specified address.
    void setup_acceptors(acceptor_user& target, string_view address);

    /// @brief Sets up acceptors listening on the specified address.
    void setup_acceptors(acceptor_user& target, identifier address) {
        setup_acceptors(target, address.name());
    }

    /// @brief Sets up acceptors listening on the default address.
    void setup_acceptors(acceptor_user& target) {
        setup_acceptors(target, string_view{});
    }

    /// @brief Sets up acceptors listening on the specified address.
    void setup_acceptors(
      acceptor_user& target,
      connection_kinds kinds,
      string_view address);

    /// @brief Sets up acceptors listening on the specified address.
    void setup_acceptors(
      acceptor_user& target,
      connection_kinds kinds,
      identifier address) {
        setup_acceptors(target, kinds, address.name());
    }

    /// @brief Sets up acceptors listening on the default address.
    void setup_acceptors(acceptor_user& target, connection_kinds kinds) {
        setup_acceptors(target, kinds, string_view{});
    }

    /// @brief Sets up acceptors listening on the specified address.
    void setup_acceptors(
      acceptor_user& target,
      connection_kind kind,
      string_view address);

    /// @brief Sets up acceptors listening on the specified address.
    void setup_acceptors(
      acceptor_user& target,
      connection_kind kind,
      identifier address) {
        setup_acceptors(target, kind, address.name());
    }

    /// @brief Sets up acceptors listening on the default address.
    void setup_acceptors(acceptor_user& target, connection_kind kind) {
        setup_acceptors(target, kind, string_view{});
    }

    /// @brief Sets up connectors connecting to the specified address.
    void setup_connectors(connection_user& target, string_view address);

    /// @brief Sets up connectors connecting to the specified address.
    void setup_connectors(connection_user& target, identifier address) {
        setup_connectors(target, address.name());
    }

    /// @brief Sets up connectors connecting to the default address.
    void setup_connectors(connection_user& target) {
        setup_connectors(target, string_view{});
    }

    /// @brief Sets up connectors connecting to the specified address.
    void setup_connectors(
      connection_user& target,
      connection_kinds kinds,
      string_view address);

    /// @brief Sets up connectors connecting to the specified address.
    void setup_connectors(
      connection_user& target,
      connection_kinds kinds,
      identifier address) {
        setup_connectors(target, kinds, address.name());
    }

    /// @brief Sets up connectors connecting to the default address.
    void setup_connectors(connection_user& target, connection_kinds kinds) {
        setup_connectors(target, kinds, string_view{});
    }

    /// @brief Sets up connectors connecting to the specified address.
    void setup_connectors(
      connection_user& target,
      connection_kind kind,
      string_view address);

    /// @brief Sets up connectors connecting to the specified address.
    void setup_connectors(
      connection_user& target,
      connection_kind kind,
      identifier address) {
        setup_connectors(target, kind, address.name());
    }

    /// @brief Sets up connectors connecting to the default address.
    void setup_connectors(connection_user& target, connection_kind kind) {
        setup_connectors(target, kind, string_view{});
    }

    /// @brief Adds a new connection factory.
    void add_factory(std::unique_ptr<connection_factory> factory);

    template <typename Factory, typename... Args>
    auto make_factory(Args&&... args)
      -> std::enable_if_t<std::is_base_of_v<connection_factory, Factory>> {
        add_factory(
          std::make_unique<Factory>(*this, std::forward<Args>(args)...));
    }

    /// @brief Uses the configuration to do initialization of this setup.
    void default_init() {
        connection_setup_default_init(*this);
    }

private:
    std::mutex _mutex{};

    using _factory_list = std::vector<std::unique_ptr<connection_factory>>;

    template <connection_kind Kind>
    using _enum_map_unit = _factory_list;

    static_enum_map<
      connection_kind,
      _enum_map_unit,
      connection_kind::in_process,
      connection_kind::local_interprocess,
      connection_kind::remote_interprocess>
      _factory_map{};

    void _do_setup_acceptors(
      acceptor_user& target,
      string_view address,
      _factory_list& factories);

    void _do_setup_connectors(
      connection_user& target,
      string_view address,
      _factory_list& factories);

    auto _make_call_setup_acceptors(acceptor_user&, string_view address);
    auto _make_call_setup_connectors(connection_user&, string_view address);
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/conn_setup.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_CONN_SETUP_HPP
