# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
PARENT = ..
ROOT = $(PARENT)/../..
XSLTPROC = xsltproc

.PHONY: all
all: \
	$(ROOT)/config/gl/assert_GL_VER_symbols.ipp.in

$(ROOT)/config/gl/assert_GL_VER_symbols.ipp.in: \
	assert_GL_VER_symbols.xsl ../gl.xml
	$(XSLTPROC) $^ > $@

