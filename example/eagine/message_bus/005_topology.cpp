/**
 *  @example eagine/message_bus/004_topology.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "lib_common_pki.hpp"
#include <eagine/main.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/topology.hpp>
#include <eagine/signal_switch.hpp>
#include <iostream>
#include <set>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using topology_printer_base =
  service_composition<network_topology<shutdown_target<>>>;

class topology_printer : public topology_printer_base {
    using base = topology_printer_base;

public:
    topology_printer(endpoint& bus)
      : base{bus}
      , _log{EAGINE_ID(TopoPrint), bus.log()} {}

    void print_topology() {
        std::cout << "graph EMB {\n";

        std::cout << "	node [shape=egg]\n";
        for(auto id : _routers) {
            std::cout << "	n" << id << "[label=Router-" << id << "]\n";
        }
        std::cout << "\n";

        std::cout << "	node [shape=invtrapezium]\n";
        for(auto id : _bridges) {
            std::cout << "	n" << id << " [label=Bridge-" << id << "]\n";
        }
        std::cout << "\n";

        std::cout << "	node [shape=invhouse]\n";
        for(auto id : _endpoints) {
            std::cout << "	n" << id << "[label=Endpoint-" << id << "]\n";
        }
        std::cout << "\n";

        std::cout << "	edge [style=solid,penwidth=2]\n";
        for(auto [l, r] : _connections) {
            std::cout << "	n" << l << " - n" << r << "\n";
        }

        std::cout << "}\n";
    }

    void router_appeared(const router_topology_info& info) final {
        _log.info("found connection ${router} - ${remote} on message bus")
          .arg(EAGINE_ID(remote), info.remote_id)
          .arg(EAGINE_ID(router), info.router_id);

        _routers.emplace(info.router_id);
        _connections.emplace(info.router_id, info.remote_id);
    }

    void bridge_appeared(const bridge_topology_info& info) final {
        if(info.opposite_id) {
            _log.info("found connection ${bridge} - ${remote} on message bus")
              .arg(EAGINE_ID(remote), info.opposite_id)
              .arg(EAGINE_ID(bridge), info.bridge_id);

            _bridges.emplace(info.opposite_id);
            _connections.emplace(info.bridge_id, info.opposite_id);
        } else {
            _log.info("found bridge ${bridge} on message bus")
              .arg(EAGINE_ID(bridge), info.bridge_id);
        }

        _bridges.emplace(info.bridge_id);
    }

    void endpoint_appeared(const endpoint_topology_info& info) final {
        _log.info("found endpoint ${endpoint} on message bus")
          .arg(EAGINE_ID(endpoint), info.endpoint_id);

        _endpoints.emplace(info.endpoint_id);
    }

    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t subscriber_id,
      verification_bits verified) final {
        _log.info("received ${age} old shutdown request from ${subscrbr}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(subscrbr), subscriber_id)
          .arg(EAGINE_ID(verified), verified);
    }

private:
    std::set<identifier_t> _routers;
    std::set<identifier_t> _bridges;
    std::set<identifier_t> _endpoints;
    std::set<std::pair<identifier_t, identifier_t>> _connections;
    logger _log{};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    signal_switch interrupted;

    msgbus::router_address address{ctx.log(), ctx.args()};
    msgbus::connection_setup conn_setup(ctx.log(), ctx.args());

    msgbus::endpoint bus{logger{EAGINE_ID(DiscoverEx), ctx.log()}};
    bus.add_ca_certificate_pem(ca_certificate_pem(ctx));
    bus.add_certificate_pem(msgbus_endpoint_certificate_pem(ctx));

    msgbus::topology_printer topo_prn{bus};

    conn_setup.setup_connectors(topo_prn, address);
    timeout waited_enough{std::chrono::seconds(30)};

    topo_prn.discover_topology();

    while(!(interrupted || waited_enough)) {
        topo_prn.update();
        if(!topo_prn.process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
    }

    topo_prn.print_topology();

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
