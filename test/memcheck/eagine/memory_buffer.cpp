/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "../memcheck.inl"
#include <cassert>
#include <eagine/memory/buffer.hpp>

static eagine::test_random_generator rg;

void
eagine_test_memory_buffer_1(void) {
    using namespace eagine;

    memory::buffer buf;

    int r = 0;

    for(int i = 0; i < 1000; ++i) {
	span_size_t s = span_size_t(r * r);

	buf.resize(s);

	assert(buf.size() == s);
	assert(buf.capacity() >= s);

	memory::block blk = buf;

	if(buf.size() > 0) {
	    assert(bool(blk));
	    assert(!!blk);
	    assert(!blk.empty());
	    assert(blk.begin() != blk.end());
	    assert(blk.size() == buf.size());
	} else {
	    assert(!bool(blk));
	    assert(!blk);
	    assert(blk.empty());
	    assert(blk.size() == 0);
	    assert(blk.begin() == blk.end());
	}

	r = rg.get_int(0, 1000);
    }
}

int
main(void) {
    eagine_test_memory_buffer_1();
    return 0;
}
