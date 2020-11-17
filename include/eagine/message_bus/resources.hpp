/**
 *  @file eagine/message_bus/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_RESOURCES_HPP
#define EAGINE_MESSAGE_BUS_RESOURCES_HPP

#include "../resources.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
memory::const_block router_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer&,
  application_config&,
  logger&);
//------------------------------------------------------------------------------
inline memory::const_block
router_certificate_pem(memory::const_block embedded_blk, main_ctx& ctx) {
    return router_certificate_pem(
      embedded_blk, ctx.scratch_space(), ctx.config(), ctx.log());
}
//------------------------------------------------------------------------------
memory::const_block bridge_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer&,
  application_config&,
  logger&);
//------------------------------------------------------------------------------
inline memory::const_block
bridge_certificate_pem(memory::const_block embedded_blk, main_ctx& ctx) {
    return bridge_certificate_pem(
      embedded_blk, ctx.scratch_space(), ctx.config(), ctx.log());
}
//------------------------------------------------------------------------------
memory::const_block endpoint_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer&,
  application_config&,
  logger&);
//------------------------------------------------------------------------------
inline memory::const_block
endpoint_certificate_pem(memory::const_block embedded_blk, main_ctx& ctx) {
    return endpoint_certificate_pem(
      embedded_blk, ctx.scratch_space(), ctx.config(), ctx.log());
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/resources.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_RESOURCES_HPP
