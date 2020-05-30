///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/logging/logger.hpp>
#include <eagine/memory/buffer.hpp>
#include <eagine/program_args.hpp>

namespace eagine {
//------------------------------------------------------------------------------
memory::const_block ca_certificate_pem(
  memory::buffer&, const program_args&, logger&);

memory::const_block msgbus_router_certificate_pem(
  memory::buffer&, const program_args&, logger&);

memory::const_block msgbus_bridge_certificate_pem(
  memory::buffer&, const program_args&, logger&);
//------------------------------------------------------------------------------
} // namespace eagine
