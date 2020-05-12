#!/usr/bin/env bash
#
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

common_args=()
router_0_args=()
router_1_args=()
dst_args=common_args

for arg
do
	case "${arg}" in
	-c) dst_args=common_args;;
	-0|-l) dst_args=router_0_args;;
	-1|-r) dst_args=router_1_args;;
	*) eval "${dst_args}+=(${arg})";;
	esac
done

coproc \
$(dirname ${0})/eagine-message_bus-bridge \
	"${common_args[@]}" "${router_0_args[@]}"

$(dirname ${0})/eagine-message_bus-bridge \
	"${common_args[@]}" "${router_1_args[@]}" \
	<&${COPROC[0]} >&${COPROC[1]}

wait ${COPROC_PID}
