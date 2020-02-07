/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>

#include <eagine/message_bus/asio.hpp>
#include <eagine/message_bus/direct.hpp>
#if EAGINE_POSIX
#include <eagine/message_bus/posix_mqueue.hpp>
#endif

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup_default_init(connection_setup& setup) {
    setup.make_factory<asio_tcp_ipv4_connection_factory>();
#if EAGINE_POSIX
    setup.make_factory<asio_local_stream_connection_factory>();
    setup.make_factory<posix_mqueue_connection_factory>();
#endif
    setup.make_factory<direct_connection_factory>();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void connection_setup_default_init(
  connection_setup& setup, const program_args& args) {
    for(auto& arg : args) {
        if(arg.is_tag("--msg-bus-asio-tcp-ipv4")) {
            setup.make_factory<asio_tcp_ipv4_connection_factory>();
#if EAGINE_POSIX
        } else if(arg.is_tag("--msg-bus-asio-local-stream")) {
            setup.make_factory<asio_local_stream_connection_factory>();
        } else if(arg.is_tag("--msg-bus-posix-mqueue")) {
            setup.make_factory<posix_mqueue_connection_factory>();
#endif
        } else if(arg.is_tag("--msg-bus-direct")) {
            setup.make_factory<direct_connection_factory>();
        }
    }
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

