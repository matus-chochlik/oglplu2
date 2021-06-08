#!/usr/bin/env bash
#
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

width=128
height=128
rank=4
gui=0
tile_size=16
ssh_hosts=()

while true
do
	case "${1}" in
		--width)
			let width=${2}
			shift;;
		--height)
			let height=${2}
			shift;;
		--size)
			let width=${2}
			let height=${2}
			shift;;
		--rank)
			let rank=${2}
			shift;;
		--tile-size)
			let tile_size=${2}
			shift;;
		--gui)
			let gui=1;;
		"") break;;
		*) ssh_hosts+=(${1});;
	esac
	shift
done
#
log_args=("--min-log-severity" "stat")
conn_args=("--msg-bus-asio-local-stream")
#
termpids=()
pids=()
#
"$(dirname ${0})/eagine-message_bus-router" \
	"${log_args[@]}" \
	"${conn_args[@]}" \
	--msg-bus-router-shutdown-verify false \
	--msg-bus-router-shutdown-when-idle true \
	--msg-bus-router-shutdown-delay 10s \
	& termpids+=($!)
sleep 1
"$(dirname ${0})/eagine-message_bus-sudoku_helper" \
	"${log_args[@]}" \
	"${conn_args[@]}" \
	--msg-bus-router-id-count 250 \
	& termpids+=($!)
sleep 1
div=$((rank * (rank - 2)))
if [[ ${gui} -ne 0 ]]
then
	"$(dirname ${0})/eagine-message_bus-tiling" \
		"${log_args[@]}" \
		"${conn_args[@]}" \
		--msg-bus-sudoku-solver-rank ${rank} \
		--msg-bus-sudoku-solver-width  $(((width / div) * div)) \
		--msg-bus-sudoku-solver-height $(((height/ div) * div)) \
		--msg-bus-sudoku-solver-gui-tile-size $((tile_size)) \
		& pids+=($!)
else
	"$(dirname ${0})/eagine-message_bus-sudoku_tiling" \
		"${log_args[@]}" \
		"${conn_args[@]}" \
		--msg-bus-sudoku-solver-block-cells false \
		--msg-bus-sudoku-solver-print-incomplete false \
		--msg-bus-sudoku-solver-print-progress true \
		--msg-bus-sudoku-solver-rank ${rank} \
		--msg-bus-sudoku-solver-width  $(((width / div) * div)) \
		--msg-bus-sudoku-solver-height $(((height/ div) * div)) \
		& pids+=($!)
fi
sleep 1
for ssh_host in "${ssh_hosts[@]}"
do
	"$(dirname ${0})/eagine-message_bus-bridge" \
		"${log_args[@]}" \
		"${conn_args[@]}" \
		--msg-bus-bridge-shutdown-delay 15s \
		--ssh "${ssh_host}" \
	&  termpids+=($!)
done

for pid in ${pids[@]}
do wait ${pid}
done

for pid in ${termpids[@]}
do kill -INT ${pid}
done

for pid in ${termpids[@]}
do wait ${pid}
done

