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
#include "conn_factory.hpp"
#include <memory>
#include <mutex>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class connection_setup;
void connection_setup_default_init(connection_setup&);
//------------------------------------------------------------------------------
class connection_setup {
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
      acceptor_user& target, string_view address, _factory_list& factories) {
        for(auto& factory : factories) {
            EAGINE_ASSERT(factory);
            if(auto acceptor = factory->make_acceptor(address)) {
                target.add_acceptor(std::move(acceptor));
            }
        }
    }

    void _do_setup_connectors(
      connection_user& target, string_view address, _factory_list& factories) {
        for(auto& factory : factories) {
            EAGINE_ASSERT(factory);
            if(auto connector = factory->make_connector(address)) {
                target.add_connection(std::move(connector));
            }
        }
    }

    auto _make_call_setup_acceptors(
      acceptor_user& target, string_view address) {
        return [this, &target, address](auto, auto& factories) {
            _do_setup_acceptors(target, address, factories);
        };
    }

    auto _make_call_setup_connectors(
      connection_user& target, string_view address) {
        return [this, &target, address](auto, auto& factories) {
            _do_setup_connectors(target, address, factories);
        };
    }

public:
    void setup_acceptors(acceptor_user& target, string_view address) {
        std::unique_lock lock{_mutex};
        _factory_map.visit_all(_make_call_setup_acceptors(target, address));
    }

    void setup_acceptors(acceptor_user& target, identifier address) {
        setup_acceptors(target, address.name());
    }

    void setup_acceptors(acceptor_user& target) {
        setup_acceptors(target, string_view{});
    }

    void setup_acceptors(
      acceptor_user& target, connection_kinds kinds, string_view address) {
        std::unique_lock lock{_mutex};
        _factory_map.visit(kinds, _make_call_setup_acceptors(target, address));
    }

    void setup_acceptors(
      acceptor_user& target, connection_kinds kinds, identifier address) {
        setup_acceptors(target, kinds, address.name());
    }

    void setup_acceptors(acceptor_user& target, connection_kinds kinds) {
        setup_acceptors(target, kinds, string_view{});
    }

    void setup_acceptors(
      acceptor_user& target, connection_kind kind, string_view address) {
        std::unique_lock lock{_mutex};
        _factory_map.visit(kind, _make_call_setup_acceptors(target, address));
    }

    void setup_acceptors(
      acceptor_user& target, connection_kind kind, identifier address) {
        setup_acceptors(target, kind, address.name());
    }

    void setup_acceptors(acceptor_user& target, connection_kind kind) {
        setup_acceptors(target, kind, string_view{});
    }

    void setup_connectors(connection_user& target, string_view address) {
        std::unique_lock lock{_mutex};
        _factory_map.visit_all(_make_call_setup_connectors(target, address));
    }

    void setup_connectors(connection_user& target, identifier address) {
        setup_connectors(target, address.name());
    }

    void setup_connectors(connection_user& target) {
        setup_connectors(target, string_view{});
    }

    void setup_connectors(
      connection_user& target, connection_kinds kinds, string_view address) {
        std::unique_lock lock{_mutex};
        _factory_map.visit(kinds, _make_call_setup_connectors(target, address));
    }

    void setup_connectors(
      connection_user& target, connection_kinds kinds, identifier address) {
        setup_connectors(target, kinds, address.name());
    }

    void setup_connectors(connection_user& target, connection_kinds kinds) {
        setup_connectors(target, kinds, string_view{});
    }

    void setup_connectors(
      connection_user& target, connection_kind kind, string_view address) {
        std::unique_lock lock{_mutex};
        _factory_map.visit(kind, _make_call_setup_connectors(target, address));
    }

    void setup_connectors(
      connection_user& target, connection_kind kind, identifier address) {
        setup_connectors(target, kind, address.name());
    }

    void setup_connectors(connection_user& target, connection_kind kind) {
        setup_connectors(target, kind, string_view{});
    }

    void add_factory(std::unique_ptr<connection_factory> factory) {
        std::unique_lock lock{_mutex};
        EAGINE_ASSERT(factory);
        const auto kind{factory->kind()};
        _factory_map.visit(
          kind, [factory{std::move(factory)}](auto, auto& factories) mutable {
              factories.emplace_back(std::move(factory));
          });
    }

    template <typename Factory, typename... Args>
    std::enable_if_t<std::is_base_of_v<connection_factory, Factory>, void>
    make_factory(Args&&... args) {
        add_factory(std::make_unique<Factory>(std::forward<Args>(args)...));
    }

    void default_init() {
        connection_setup_default_init(*this);
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/conn_setup.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_CONN_SETUP_HPP

