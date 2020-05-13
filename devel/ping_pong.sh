#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
conn_type="--msg-bus-asio-local-stream"
ping_addr="/tmp/ping"
pong_addr="/tmp/pong"
#
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	${conn_type} \
	--msg-bus-router-address ${ping_addr} \
	--msg-bus-router-id-base 1000 \
	& pids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-router \
	${conn_type} \
	--msg-bus-router-address ${pong_addr} \
	--msg-bus-router-id-base 2000 \
	& pids+=($!)
sleep 1
${install_prefix}/bin/eagine-local-bridge \
	${conn_type} \
	-l --msg-bus-router-address ${ping_addr} \
	-r --msg-bus-router-address ${pong_addr} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-003_pong \
	${conn_type} \
	--msg-bus-router-address ${pong_addr} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-003_ping \
	${conn_type} \
	--msg-bus-router-address ${ping_addr} \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done

