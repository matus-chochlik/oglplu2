/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_buffer
#include <boost/test/unit_test.hpp>

#include <eagine/memory/buffer.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(memory_buffer_tests)

BOOST_AUTO_TEST_CASE(memory_block_0)
{
	using namespace eagine;

	memory::buffer buf;

	BOOST_CHECK_EQUAL(buf.size(), 0);
	BOOST_CHECK_EQUAL(buf.capacity(), 0);

	memory::block blk = buf;

	BOOST_CHECK(!bool(blk));
	BOOST_CHECK(!blk);
	BOOST_CHECK(blk.empty());
	BOOST_CHECK(blk.size() == 0);
	BOOST_CHECK(blk.begin() == blk.end());
}

BOOST_AUTO_TEST_CASE(memory_block_1)
{
	using namespace eagine;

	memory::buffer buf;

	int r = 0;

	for(int i=0; i<1000; ++i)
	{
		std::size_t s = std::size_t(r*r);

		buf.resize(s);

		BOOST_CHECK_EQUAL(buf.size(), s);
		BOOST_CHECK(buf.capacity() >= s);

		memory::block blk = buf;

		if(buf.size() > 0)
		{
			BOOST_CHECK(bool(blk));
			BOOST_CHECK(!!blk);
			BOOST_CHECK(!blk.empty());
			BOOST_CHECK(blk.begin() != blk.end());
			BOOST_CHECK_EQUAL(blk.size(), buf.size());
		}
		else
		{
			BOOST_CHECK(!bool(blk));
			BOOST_CHECK(!blk);
			BOOST_CHECK(blk.empty());
			BOOST_CHECK(blk.size() == 0);
			BOOST_CHECK(blk.begin() == blk.end());
		}

		r = std::rand() % 1000;
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
