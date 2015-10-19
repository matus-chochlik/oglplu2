# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
LIBRARY = oglplus
LIB_PREFIX = GL
PARENT = ..
ROOT = $(PARENT)/../..
MAKE_CODE = $(PARENT)/make_code.py

.PHONY: all
all: \
	$(ROOT)/implement/$(LIBRARY)/vertex_attrib_get_set.inl \
	$(ROOT)/implement/$(LIBRARY)/uniform_get_set.inl

$(ROOT)/implement/$(LIBRARY)/uniform_get_set.inl: $(MAKE_CODE)
	$(MAKE_CODE) \
		--library $(LIBRARY) \
		--base-lib-prefix $(LIB_PREFIX)\
		--action gl_uniform_get_set \
		--output "$@"
	git add "$@"

$(ROOT)/implement/$(LIBRARY)/vertex_attrib_get_set.inl: $(MAKE_CODE)
	$(MAKE_CODE) \
		--library $(LIBRARY) \
		--base-lib-prefix $(LIB_PREFIX)\
		--action gl_vertex_attrib_get_set \
		--output "$@"
	git add "$@"

