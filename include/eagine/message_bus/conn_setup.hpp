/**
 *  @file eagine/message_bus/conn_setup.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_CONN_SETUP_HPP
#define EAGINE_MESSAGE_BUS_CONN_SETUP_HPP

#include "../enum_map.hpp"
#include "../logging/logger.hpp"
#include "../program_args.hpp"
#include "conn_factory.hpp"
#include <memory>
#include <mutex>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class connection_setup;
void connection_setup_default_init(connection_setup&);
void connection_setup_default_init(connection_setup&, const program_args&);
//------------------------------------------------------------------------------
static inline auto adapt_log_entry_arg(
  identifier name, const std::unique_ptr<connection_factory>& value) {
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
class connection_setup {
    std::mutex _mutex{};
    logger _log{};

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
      acceptor_user& target, string_view address, _factory_list& factories);

    void _do_setup_connectors(
      connection_user& target, string_view address, _factory_list& factories);

    auto _make_call_setup_acceptors(acceptor_user&, string_view address);
    auto _make_call_setup_connectors(connection_user&, string_view address);

public:
    connection_setup() noexcept = default;

    connection_setup(logger& parent) noexcept
      : _log{EAGINE_ID(ConnSetup), parent} {
    }

    connection_setup(logger& parent, const program_args& args) noexcept
      : connection_setup{parent} {
        default_init(args);
    }

    void setup_acceptors(acceptor_user& target, string_view address);

    void setup_acceptors(acceptor_user& target, identifier address) {
        setup_acceptors(target, address.name());
    }

    void setup_acceptors(acceptor_user& target) {
        setup_acceptors(target, string_view{});
    }

    void setup_acceptors(
      acceptor_user& target, connection_kinds kinds, string_view address);

    void setup_acceptors(
      acceptor_user& target, connection_kinds kinds, identifier address) {
        setup_acceptors(target, kinds, address.name());
    }

    void setup_acceptors(acceptor_user& target, connection_kinds kinds) {
        setup_acceptors(target, kinds, string_view{});
    }

    void setup_acceptors(
      acceptor_user& target, connection_kind kind, string_view address);

    void setup_acceptors(
      acceptor_user& target, connection_kind kind, identifier address) {
        setup_acceptors(target, kind, address.name());
    }

    void setup_acceptors(acceptor_user& target, connection_kind kind) {
        setup_acceptors(target, kind, string_view{});
    }

    void setup_connectors(connection_user& target, string_view address);

    void setup_connectors(connection_user& target, identifier address) {
        setup_connectors(target, address.name());
    }

    void setup_connectors(connection_user& target) {
        setup_connectors(target, string_view{});
    }

    void setup_connectors(
      connection_user& target, connection_kinds kinds, string_view address);

    void setup_connectors(
      connection_user& target, connection_kinds kinds, identifier address) {
        setup_connectors(target, kinds, address.name());
    }

    void setup_connectors(connection_user& target, connection_kinds kinds) {
        setup_connectors(target, kinds, string_view{});
    }

    void setup_connectors(
      connection_user& target, connection_kind kind, string_view address);

    void setup_connectors(
      connection_user& target, connection_kind kind, identifier address) {
        setup_connectors(target, kind, address.name());
    }

    void setup_connectors(connection_user& target, connection_kind kind) {
        setup_connectors(target, kind, string_view{});
    }

    void add_factory(std::unique_ptr<connection_factory> factory);

    template <typename Factory, typename... Args>
    std::enable_if_t<std::is_base_of_v<connection_factory, Factory>, void>
    make_factory(Args&&... args) {
        add_factory(
          std::make_unique<Factory>(_log, std::forward<Args>(args)...));
    }

    void default_init() {
        connection_setup_default_init(*this);
    }

    void default_init(const program_args& args) {
        connection_setup_default_init(*this, args);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/conn_setup.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_CONN_SETUP_HPP

