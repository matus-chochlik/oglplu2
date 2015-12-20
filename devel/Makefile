# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

TESTS = $(patsubst test%.cpp,test%, $(wildcard *.cpp))

all: $(TESTS)

test%: test%.o
	$(CXX) -std=c++14 \
		-o $@ $<
test%.o: test%.cpp
	$(CXX) -std=c++14 \
		-I../_build/include \
		-I../third_party/GSL/include \
		-I../third_party/include \
		-I../include \
		-I../implement \
		-c -o $@ $<

clean:
	rm -f $(TESTS)

.PHONY: all clean
