/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_c_realloc
#include <boost/test/unit_test.hpp>

#include <eagine/memory/c_realloc.hpp>
#include <cstdlib>
#include <deque>

BOOST_AUTO_TEST_SUITE(memory_c_realloc_tests)

template <typename T>
void eagine_test_memory_c_realloc_1_T(std::size_t n)
{
	using namespace eagine;

	memory::c_byte_reallocator<> a;

	const span_size_t ao = span_align_of<T>();
	const span_size_t sz = span_size_of<T>(n);

	BOOST_CHECK(a.max_size(ao) >= sz);

	memory::owned_block b1 = a.allocate(sz, ao);

	BOOST_CHECK_EQUAL(b1.empty(), n == 0);
	BOOST_CHECK(b1.size() >= sz);
	BOOST_CHECK(b1.is_aligned_to(ao));

	BOOST_CHECK(!!a.has_allocated(b1, ao));

	memory::owned_block b2 = a.reallocate(std::move(b1), sz, ao);

	BOOST_CHECK(b1.empty());
	BOOST_CHECK(b2.size() >= sz);

	a.deallocate(std::move(b2), ao);

	std::deque<memory::owned_block> blks;

	for(std::size_t i=0; i<n; ++i)
	{
		blks.emplace_back(a.allocate(sizeof(T), ao));
	}

	for(memory::owned_block& blk : blks)
	{
		BOOST_CHECK(blks.back().size() >= span_size_of<T>());
		BOOST_CHECK(blks.back().is_aligned_to(ao));
		BOOST_CHECK(a.has_allocated(blk, ao));
	}

	while(!blks.empty())
	{
		auto i = blks.begin() + std::rand()%int(blks.size());
		a.deallocate(std::move(*i), ao);
		blks.erase(i);
	}

	a.release();
}

BOOST_AUTO_TEST_CASE(memory_c_realloc_1)
{
	std::size_t f[2] = {0,1};

	for(int i=0; i<20; ++i)
	{
		std::size_t n = f[(i+0)%2]+f[(i+1)%2];
		f[i%2] = n;

		eagine_test_memory_c_realloc_1_T<char>(n);
		eagine_test_memory_c_realloc_1_T<short>(n);
		eagine_test_memory_c_realloc_1_T<int>(n);
		eagine_test_memory_c_realloc_1_T<float>(n);
		eagine_test_memory_c_realloc_1_T<double>(n);
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
