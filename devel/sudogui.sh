#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--min-log-severity" "stat")
conn_type="--msg-bus-asio-local-stream"
#
termpids=()
hlprpids=()
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	"${conn_type}" \
	--msg-bus-router-address /tmp/sudoku_t \
	--msg-bus-router-id-major 0 \
	--msg-bus-router-id-count 500 \
	--msg-bus-router-shutdown-verify false \
	--msg-bus-router-shutdown-when-idle true \
	--msg-bus-router-shutdown-delay 20s \
	& termpids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-sudoku_helper \
	"${log_args[@]}" \
	"${conn_type}" \
	--msg-bus-router-address /tmp/sudoku_t \
	--msg-bus-router-id-major 1000 \
	--msg-bus-router-id-count 500 \
	& hlprpids+=($!)
sleep 1
${install_prefix}/bin/eagine-message_bus-tiling \
	"${log_args[@]}" \
	"${conn_type}" \
	--msg-bus-router-address /tmp/sudoku_t \
	& pids+=($!)
sleep 1
for ssh_host in "${@}"
do
	"${install_prefix}/bin/eagine-message_bus-bridge" \
		"${log_args[@]}" \
		"${conn_type}" \
		--msg-bus-router-address /tmp/sudoku_t \
		--msg-bus-bridge-shutdown-delay 15s \
		--ssh "${ssh_host}" \
	&  hlprpids+=($!)
done

for pid in ${pids[@]}
do wait ${pid}
done

for pid in ${hlprpids[@]}
do kill -INT ${pid}
done

for pid in ${hlprpids[@]}
do wait ${pid}
done

sleep 5

for pid in ${termpids[@]}
do kill -INT ${pid} $(ps --ppid ${pid} -o pid=)
done

for pid in ${termpids[@]}
do wait ${pid}
done

