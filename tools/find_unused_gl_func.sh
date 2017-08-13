#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

rootdir="$(dirname ${0})/.."
srchdirs=("${rootdir}/include" "${rootdir}/implement")

cat "${rootdir}/config/gl/assert_GL_VER_symbols.ipp.in" |
sed -n 's/^.*GL_FUNC(gl\([^)]\+\));.*$/\1/p' |
while read function
do
	n=$(find ${srchdirs[@]} -type f | xargs cat | grep -c -e "${function}")
	if [[ ${n} -eq 0 ]]
	then echo ${function}
	fi
done
