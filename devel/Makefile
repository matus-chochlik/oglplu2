# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

TESTS = $(patsubst test%.cpp,test%, $(wildcard *.cpp))
ROOT_DIR = ..
BINARY_DIR = $(shell cat $(ROOT_DIR)/BINARY_DIR)

all: $(TESTS)

check%: test%
	./$<

test%: test%.o
	$(CXX) -std=c++17 -g3 \
		-ldl -lrt \
		$(shell pkg-config --libs openssl) \
		$(shell pkg-config --libs openal) \
		$(shell pkg-config --libs egl) \
		$(shell pkg-config --libs gl) \
		-rdynamic \
		-pthread \
		-o $@ $<

test%.o: test%.cpp
	$(CXX) -std=c++17 -g3 \
		-Wall -Wextra -Werror \
		-Wno-unknown-warning-option \
		-Wno-address \
		-Wno-padded \
		-Wno-weak-vtables \
		-Wno-c++98-compat \
		-Wno-c++98-compat-pedantic \
		-Wno-unused-function \
		-Wno-documentation \
		-Wno-documentation-unknown-command \
		-I$(BINARY_DIR)/include \
		-I../include \
		-I../implement \
		-I../source/utils \
		-I../third_party/include \
		-I../third_party/asio/asio/include \
		$(shell pkg-config --cflags openssl) \
		$(shell pkg-config --cflags openal) \
		$(shell pkg-config --cflags egl) \
		$(shell pkg-config --cflags gl) \
		-c -o $@ $<

clean:
	rm -f $(TESTS)

.PHONY: all clean
