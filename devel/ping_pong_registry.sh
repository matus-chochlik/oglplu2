#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--use-asio-log" "--min-log-severity" "stat")
conn_type="--msg-bus-asio-local-stream"
#
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-id-base 1000 \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-007_ping \
	"${log_args[@]}" \
	${conn_type} \
	--ping-count ${1:-1M} \
	& pids+=($!)
sleep 5
${install_prefix}/share/oglplus/examples/eagine-008_pong_registry \
	"${log_args[@]}" \
	${conn_type} \
	--ponger-count ${2:-4} \
	--msg-bus-router-id-base 2000 \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done

