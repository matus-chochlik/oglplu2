/**
 *  @file eagine/message_bus/resources.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block router_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  const program_args& args,
  logger& log) {
    return fetch_resource(
      string_view{"message bus router certificate"},
      string_view{"EAGINE_ROUTER_CERT_PATH"},
      string_view{"--msg-bus-router-cert-path"},
      embedded_blk,
      buf,
      args,
      log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block bridge_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  const program_args& args,
  logger& log) {
    return fetch_resource(
      string_view{"message bus bridge certificate"},
      string_view{"EAGINE_ROUTER_CERT_PATH"},
      string_view{"--msg-bus-bridge-cert-path"},
      embedded_blk,
      buf,
      args,
      log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block endpoint_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  const program_args& args,
  logger& log) {
    return fetch_resource(
      string_view{"message bus endpoint certificate"},
      string_view{"EAGINE_ENDPOINT_CERT_PATH"},
      string_view{"--msg-bus-endpoint-cert-path"},
      embedded_blk,
      buf,
      args,
      log);
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

