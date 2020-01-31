/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>

#include <eagine/message_bus/direct.hpp>
#if EAGINE_POSIX
#include <eagine/message_bus/posix_mqueue.hpp>
#endif

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup_default_init(connection_setup& setup) {
    setup.make_factory<direct_connection_factory>();
#if EAGINE_POSIX
    setup.make_factory<posix_mqueue_connection_factory>();
#endif
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine
