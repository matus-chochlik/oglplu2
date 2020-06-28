///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main_ctx.hpp>

namespace eagine {
//------------------------------------------------------------------------------
memory::const_block ca_certificate_pem(main_ctx&);
memory::const_block msgbus_router_certificate_pem(main_ctx&);
memory::const_block msgbus_bridge_certificate_pem(main_ctx&);
memory::const_block msgbus_endpoint_certificate_pem(main_ctx&);
//------------------------------------------------------------------------------
} // namespace eagine
