#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

if [[ ! $(pgrep -f "xml_logs.py") ]]
then "$(dirname ${0})/xml_logs.py" "${@}"
fi
