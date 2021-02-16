/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto router_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) -> memory::const_block {
    return fetch_resource(
      string_view{"message bus router certificate"},
      string_view{"msg_bus.router.cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto bridge_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) -> memory::const_block {
    return fetch_resource(
      string_view{"message bus bridge certificate"},
      string_view{"msg_bus.bridge.cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto endpoint_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) -> memory::const_block {
    return fetch_resource(
      string_view{"message bus endpoint certificate"},
      string_view{"msg_bus.endpoint.cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

