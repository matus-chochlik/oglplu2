/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>

#include <eagine/message_bus/direct.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup_default_init(connection_setup& setup) {
    setup.make_factory<direct_connection_factory>();
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

