# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

TESTS = $(patsubst test%.cpp,test%, $(wildcard *.cpp))

all: $(TESTS)

test%: test%.o
	$(CXX) -std=c++14 -g3 \
		-o $@ $<
test%.o: test%.cpp
	$(CXX) -std=c++14 -g3 \
		-Wall -Weverything -Werror \
		-Wno-padded \
		-Wno-weak-vtables \
		-Wno-c++98-compat \
		-Wno-c++98-compat-pedantic \
		-Wno-unused-function \
		-Wno-documentation \
		-Wno-documentation-unknown-command \
		-I../_build/include \
		-I../third_party/GSL/include \
		-I../third_party/include \
		-I../include \
		-I../implement \
		-I../source/utils \
		-c -o $@ $<

clean:
	rm -f $(TESTS)

.PHONY: all clean
