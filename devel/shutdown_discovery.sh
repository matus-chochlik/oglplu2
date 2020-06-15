#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
install_prefix="$(<$(dirname ${0})/../INSTALL_PREFIX)"
log_args=("--use-asio-log" "--min-log-severity" "debug")
conn_args=("--msg-bus-asio-local-stream")
ssl_args=(
	"${EAGINE_SSL_ENGINE_ID:+--msg-bus-ssl-engine}"
	"${EAGINE_SSL_ENGINE_ID}"
	"${EAGINE_SSL_PKEY_ID:+--msg-bus-pkey-id}"
	"${EAGINE_SSL_PKEY_ID}"
)
#
pids=()
#
${install_prefix}/bin/eagine-message_bus-router \
	"${log_args[@]}" \
	"${conn_args[@]}" \
	& pids+=($!)
sleep 1
${install_prefix}/share/oglplus/examples/eagine-003_shutdown \
	"${log_args[@]}" \
	"${ssl_args[@]}" \
	"${conn_args[@]}" \
	& pids+=($!)
sleep 10
valgrind ${install_prefix}/share/oglplus/examples/eagine-004_discovery \
	"${log_args[@]}" \
	"${conn_args[@]}" \
	& pids+=($!)

for pid in ${pids[@]}
do wait ${pid}
done

