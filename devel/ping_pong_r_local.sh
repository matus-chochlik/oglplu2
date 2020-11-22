#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
variant=${1:-007}
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--use-asio-log" "--min-log-severity" "stat")
conn_type="--msg-bus-asio-local-stream"
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
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-${variant}_ping \
	"${log_args[@]}" \
	--ping-count ${2:-1M} \
	${conn_type} \
	& pids+=($!)
sleep 5
${install_prefix}/share/oglplus/examples/eagine-${variant}_pong \
	--pingable-id 1111 \
	"${log_args[@]}" \
	${conn_type} \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done

