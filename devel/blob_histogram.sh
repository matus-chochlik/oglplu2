#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--use-asio-nw-log" "--min-log-severity" "debug")
conn_type="--msg-bus-asio-local-stream"
#
pids=()
termpids=()
#
"$(dirname ${0})/../tools/xml_logs-opt.sh" \
	"--plot-charts" \
	& pids+=($!)
sleep 1
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	${conn_type} \
	--msg-bus-router-shutdown-verify false \
	& termpids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-005_byte_histogram\
	"${log_args[@]}" \
	${conn_type} \
	& pids+=($!)
sleep 3

if [[ $# -eq 0 ]]
then set $(find /etc/ -maxdepth 1 -type f -readable | head -20)
fi
for f
do
	${install_prefix}/share/oglplus/examples/eagine-005_broadcast_blob "${f}" \
		"${log_args[@]}" \
		${conn_type}
	sleep 5
done

for pid in ${pids[@]}
do wait ${pid}
done

kill -TERM ${termpids[@]}

for pid in ${termpids[@]}
do wait ${pid}
done

