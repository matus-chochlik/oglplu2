/**
 *  @file eagine/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_RESOURCES_HPP
#define EAGINE_RESOURCES_HPP

#include "embed.hpp"
#include "logging/logger.hpp"
#include "main_ctx.hpp"
#include "memory/buffer_fwd.hpp"
#include "program_args.hpp"
#include "string_span.hpp"

namespace eagine {
//------------------------------------------------------------------------------
memory::const_block fetch_resource(
  string_view description,
  string_view env_var_name,
  string_view prog_arg_name,
  memory::const_block embedded_blk,
  memory::buffer& buf,
  const program_args& args,
  logger& log);
//------------------------------------------------------------------------------
inline memory::const_block fetch_resource(
  string_view description,
  string_view env_var_name,
  string_view prog_arg_name,
  memory::const_block embedded_blk,
  main_ctx& ctx) {
    return fetch_resource(
      description,
      env_var_name,
      prog_arg_name,
      embedded_blk,
      ctx.scratch_space(),
      ctx.args(),
      ctx.log());
}
//------------------------------------------------------------------------------
memory::const_block ca_certificate_pem(
  memory::const_block embedded_blk,
  memory::buffer&,
  const program_args&,
  logger&);
//------------------------------------------------------------------------------
inline memory::const_block
ca_certificate_pem(memory::const_block embedded_blk, main_ctx& ctx) {
    return ca_certificate_pem(
      embedded_blk, ctx.scratch_space(), ctx.args(), ctx.log());
}
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/resources.inl>
#endif

#endif // EAGINE_RESOURCES_HPP
