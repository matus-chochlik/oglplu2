/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/config/platform.hpp>

#include <eagine/application_config.hpp>
#include <eagine/message_bus/asio.hpp>
#include <eagine/message_bus/direct.hpp>
#if EAGINE_POSIX
#include <eagine/message_bus/posix_mqueue.hpp>
#endif

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::_do_setup_acceptors(
  acceptor_user& target,
  string_view address,
  _factory_list& factories) {
    for(auto& factory : factories) {
        EAGINE_ASSERT(factory);
        log_debug(
          "setting up acceptors on address ${address} "
          "with factory type ${factory}")
          .arg(EAGINE_ID(factory), factory)
          .arg(EAGINE_ID(address), EAGINE_ID(MsgBusAddr), address);

        if(auto acceptor{factory->make_acceptor(address)}) {
            target.add_acceptor(std::move(acceptor));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::_do_setup_connectors(
  connection_user& target,
  string_view address,
  _factory_list& factories) {
    for(auto& factory : factories) {
        EAGINE_ASSERT(factory);
        log_debug(
          "setting up connectors on address ${address} "
          "with factory type ${factory}")
          .arg(EAGINE_ID(factory), factory)
          .arg(EAGINE_ID(address), EAGINE_ID(MsgBusAddr), address);

        if(auto connector{factory->make_connector(address)}) {
            target.add_connection(std::move(connector));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto connection_setup::_make_call_setup_acceptors(
  acceptor_user& target,
  string_view address) {
    return [this, &target, address](auto, auto& factories) {
        _do_setup_acceptors(target, address, factories);
    };
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::setup_acceptors(
  acceptor_user& target,
  string_view address) {
    std::unique_lock lock{_mutex};
    _factory_map.visit_all(_make_call_setup_acceptors(target, address));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::setup_acceptors(
  acceptor_user& target,
  connection_kinds kinds,
  string_view address) {
    std::unique_lock lock{_mutex};
    _factory_map.visit(kinds, _make_call_setup_acceptors(target, address));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::setup_acceptors(
  acceptor_user& target,
  connection_kind kind,
  string_view address) {
    std::unique_lock lock{_mutex};
    _factory_map.visit(kind, _make_call_setup_acceptors(target, address));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto connection_setup::_make_call_setup_connectors(
  connection_user& target,
  string_view address) {
    return [this, &target, address](auto, auto& factories) {
        _do_setup_connectors(target, address, factories);
    };
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::setup_connectors(
  connection_user& target,
  string_view address) {
    std::unique_lock lock{_mutex};
    _factory_map.visit_all(_make_call_setup_connectors(target, address));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::setup_connectors(
  connection_user& target,
  connection_kinds kinds,
  string_view address) {
    std::unique_lock lock{_mutex};
    _factory_map.visit(kinds, _make_call_setup_connectors(target, address));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::setup_connectors(
  connection_user& target,
  connection_kind kind,
  string_view address) {
    std::unique_lock lock{_mutex};
    _factory_map.visit(kind, _make_call_setup_connectors(target, address));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup::add_factory(std::unique_ptr<connection_factory> factory) {
    std::unique_lock lock{_mutex};
    EAGINE_ASSERT(factory);
    const auto kind{factory->kind()};

    log_debug("adding ${kind} connection factory ${factory}")
      .arg(EAGINE_ID(kind), kind)
      .arg(EAGINE_ID(addrKind), factory->addr_kind())
      .arg(EAGINE_ID(factory), factory);

    _factory_map.visit(
      kind, [factory{std::move(factory)}](auto, auto& factories) mutable {
          factories.emplace_back(std::move(factory));
      });
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup_configure(
  connection_setup& setup,
  application_config& config) {
    if(config.is_set("msg_bus.asio_tcp_ipv4")) {
        setup.make_factory<asio_tcp_ipv4_connection_factory>();
    }
    if(config.is_set("msg_bus.asio_udp_ipv4")) {
        setup.make_factory<asio_udp_ipv4_connection_factory>();
    }
#if EAGINE_POSIX
    if(config.is_set("msg_bus.asio_local_stream")) {
        setup.make_factory<asio_local_stream_connection_factory>();
    }
    if(config.is_set("msg_bus.posix_mqueue")) {
        setup.make_factory<posix_mqueue_connection_factory>();
    }
#endif
    if(config.is_set("msg_bus.direct")) {
        setup.make_factory<direct_connection_factory>();
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
