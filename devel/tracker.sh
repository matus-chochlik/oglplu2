#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--min-log-severity" "info")
conn_type="--msg-bus-asio-local-stream"
l_addr=/tmp/eagmb-trk-l
r_addr=/tmp/eagmb-trk-r
#
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${l_addr} \
	--msg-bus-router-id-major 1000 \
	--msg-bus-router-id-count 1000 \
	--msg-bus-router-shutdown-verify false \
	& pids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${r_addr} \
	--msg-bus-router-id-major 2000 \
	--msg-bus-router-id-count 1000 \
	--msg-bus-router-shutdown-verify false \
	& pids+=($!)
sleep 5
${install_prefix}/bin/eagine-local-bridge \
	"${log_args[@]}" \
	${conn_type} \
	-c --msg-bus-bridge-shutdown-verify false \
	-l --msg-bus-router-address ${l_addr} \
	-r --msg-bus-router-address ${r_addr} \
	& pids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-pingable \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${r_addr} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-014_tracker \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${l_addr} \
	& pids+=($!)
sleep 2
${HOME}/.oglplus/bin/service_bridges "${@}"

for pid in ${pids[@]}
do wait ${pid}
done

