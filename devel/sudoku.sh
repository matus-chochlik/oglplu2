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
termpids=()
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	"${conn_type}" \
	--msg-bus-router-shutdown-verify false \
	--msg-bus-router-shutdown-when-idle true \
	--msg-bus-router-shutdown-delay 20s \
	& termpids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-sudoku_helper \
	"${log_args[@]}" \
	"${conn_type}" \
	--msg-bus-router-id-major 1000 \
	--msg-bus-router-id-count 1000 \
	& termpids+=($!)
sleep 1
rank=4
div=$((rank * (rank - 2)))
${install_prefix}/bin/eagine-message_bus-sudoku_tiling \
	"${log_args[@]}" \
	"${conn_type}" \
	--msg-bus-sudoku-solver-block-cells true \
	--msg-bus-sudoku-solver-print-incomplete true \
	--${rank} \
	--width  $(((COLUMNS / div) * div)) \
	--height $(((LINES / div) * div)) \
	& pids+=($!)
sleep 1
for ssh_host in "${@}"
do
	"${install_prefix}/bin/eagine-message_bus-bridge" \
		"${log_args[@]}" \
		"${conn_type}" \
		--msg-bus-bridge-shutdown-delay 15s \
		--ssh "${ssh_host}" \
	&  termpids+=($!)
done
${install_prefix}/bin/eagine-message_bus-pinger \
	"${log_args[@]}" \
	--ping-count 250k \
	--limit-count 1k \
	${conn_type} \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done

kill -INT ${termpids[@]}

for pid in ${termpids[@]}
do wait ${pid}
done

