#!/bin/bash
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

find "$(dirname ${0})/.." -type f |\
grep -v -e '/third_party/' -e '/.git/' |\
xargs file |\
grep -i -e 'C++ source' -e 'C source' |\
cut -d: -f1
