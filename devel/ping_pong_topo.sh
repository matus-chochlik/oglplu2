#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
variant=${1:-007}
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--use-asio-nw-log" "--min-log-severity" "stat")
conn_type="--msg-bus-asio-local-stream"
ping_addr="/tmp/ping"
pong_addr="/tmp/pong"
#
pids=()
#
"$(dirname ${0})/../tools/xml_logs-opt.sh" \
	"--plot-charts" \
	& pids+=($!)
sleep 1
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${ping_addr} \
	--msg-bus-router-id-major 1000 \
	--msg-bus-router-id-count 1000 \
	--msg-bus-router-shutdown-verify false \
	& pids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${pong_addr} \
	--msg-bus-router-id-major 2000 \
	--msg-bus-router-id-count 1000 \
	--msg-bus-router-shutdown-verify false \
	& pids+=($!)
sleep 1
${install_prefix}/bin/eagine-local-bridge \
	"${log_args[@]}" \
	${conn_type} \
	-l --msg-bus-router-address ${ping_addr} \
	-r --msg-bus-router-address ${pong_addr} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-${variant}_pong \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${pong_addr} \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-${variant}_ping \
	"${log_args[@]}" \
	--ping-count ${2:-300k} \
	${conn_type} \
	--msg-bus-router-address ${ping_addr} \
	& pids+=($!)
sleep 10
${install_prefix}/share/oglplus/examples/eagine-005_topology \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-address ${pong_addr} > /tmp/oglp-mb-topo.dot \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done
