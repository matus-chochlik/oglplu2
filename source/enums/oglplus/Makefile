# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
LIB_PREFIX = GL
LIBRARY = oglplus
EXTENSIONS = ARB_compatibility NV_path_rendering
SOURCES = $(wildcard *.txt) $(foreach EXT,$(EXTENSIONS),$(wildcard $(EXT)/*.txt))
PARENT = ..

sinclude ../common.mk
