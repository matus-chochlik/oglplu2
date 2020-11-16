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
  application_config& cfg,
  logger& log) {
    return fetch_resource(
      string_view{"message bus router certificate"},
      string_view{"msg_bus.router_cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block bridge_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) {
    return fetch_resource(
      string_view{"message bus bridge certificate"},
      string_view{"msg_bus.bridge_cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
memory::const_block endpoint_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer& buf,
  application_config& cfg,
  logger& log) {
    return fetch_resource(
      string_view{"message bus endpoint certificate"},
      string_view{"msg_bus.endpoint_cert_path"},
      embedded_blk,
      buf,
      cfg,
      log);
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

