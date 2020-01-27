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
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class connection_setup {
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

    template <typename Target>
    void _do_setup_acceptors(
      Target& target, string_view address, _factory_list& factories) {
        for(auto& factory : factories) {
            EAGINE_ASSERT(factory);
            if(auto acceptor = factory->make_acceptor(address)) {
                target.add_acceptor(std::move(acceptor));
            }
        }
    }

    template <typename Target>
    void _do_setup_connectors(
      Target& target, string_view address, _factory_list& factories) {
        for(auto& factory : factories) {
            EAGINE_ASSERT(factory);
            if(auto connector = factory->make_connector(address)) {
                target.add_connection(std::move(connector));
            }
        }
    }

    template <typename Target>
    auto _make_call_setup_acceptors(Target& target, string_view address) {
        return [this, &target, address](auto, auto& factories) {
            _do_setup_acceptors(target, address, factories);
        };
    }

    template <typename Target>
    auto _make_call_setup_connectors(Target& target, string_view address) {
        return [this, &target, address](auto, auto& factories) {
            _do_setup_connectors(target, address, factories);
        };
    }

public:
    template <typename Target>
    void setup_acceptors(Target& target, string_view address) {
        _factory_map.visit_all(_make_call_setup_acceptors(target, address));
    }

    template <typename Target>
    void setup_acceptors(Target& target, identifier address) {
        setup_acceptors(target, address.name());
    }

    template <typename Target>
    void setup_acceptors(
      Target& target, connection_kinds kinds, string_view address) {
        _factory_map.visit(kinds, _make_call_setup_acceptors(target, address));
    }

    template <typename Target>
    void setup_acceptors(
      Target& target, connection_kinds kinds, identifier address) {
        setup_acceptors(target, kinds, address.name());
    }

    template <typename Target>
    void setup_acceptors(
      Target& target, connection_kind kind, string_view address) {
        _factory_map.visit(kind, _make_call_setup_acceptors(target, address));
    }

    template <typename Target>
    void setup_acceptors(
      Target& target, connection_kind kind, identifier address) {
        setup_acceptors(target, kind, address.name());
    }

    template <typename Target>
    void setup_connectors(Target& target, string_view address) {
        _factory_map.visit_all(_make_call_setup_connectors(target, address));
    }

    template <typename Target>
    void setup_connectors(Target& target, identifier address) {
        setup_connectors(target, address.name());
    }

    template <typename Target>
    void setup_connectors(
      Target& target, connection_kinds kinds, string_view address) {
        _factory_map.visit(kinds, _make_call_setup_connectors(target, address));
    }

    template <typename Target>
    void setup_connectors(
      Target& target, connection_kinds kinds, identifier address) {
        setup_connectors(target, kinds, address.name());
    }

    template <typename Target>
    void setup_connectors(
      Target& target, connection_kind kind, string_view address) {
        _factory_map.visit(kind, _make_call_setup_connectors(target, address));
    }

    template <typename Target>
    void setup_connectors(
      Target& target, connection_kind kind, identifier address) {
        setup_connectors(target, kind, address.name());
    }

    void add_factory(std::unique_ptr<connection_factory> factory) {
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
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_CONN_SETUP_HPP

