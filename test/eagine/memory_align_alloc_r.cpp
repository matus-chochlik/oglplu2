/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_align_alloc
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include <eagine/memory/align_alloc.hpp>
#include <eagine/memory/stack_alloc.hpp>
#include <vector>
#include <deque>

BOOST_AUTO_TEST_SUITE(memory_align_alloc_tests)

static eagine::test_random_generator rg;

template <typename T>
void eagine_test_memory_align_alloc_T(std::size_t n)
{
	using namespace eagine;

	std::vector<char> buf1( 32*1024);
	std::vector<char> buf2( 64*1024);
	std::vector<char> buf4(128*1024);
	std::vector<char> buf8(256*1024);

	memory::block blk1(buf1.data(), span_size(buf1.size()));
	memory::block blk2(buf2.data(), span_size(buf2.size()));
	memory::block blk4(buf4.data(), span_size(buf4.size()));
	memory::block blk8(buf8.data(), span_size(buf8.size()));

	memory::multi_align_byte_allocator<std::index_sequence<1,2,4,8>> a(
		memory::stack_aligned_byte_allocator<>(blk1, 1),
		memory::stack_aligned_byte_allocator<>(blk2, 2),
		memory::stack_aligned_byte_allocator<>(blk4, 4),
		memory::stack_aligned_byte_allocator<>(blk8, 8)
	);

	const span_size_t ao = span_align_of<T>();
	const span_size_t sz = span_size_of<T>(n);

	BOOST_CHECK(a.max_size(ao) > 0);

	memory::owned_block b1 = a.allocate(sz, ao);

	BOOST_CHECK(!b1.empty());
	BOOST_CHECK(b1.size() >= sz);
	BOOST_CHECK(b1.is_aligned_to(ao));

	BOOST_CHECK(a.has_allocated(b1, ao));

	memory::owned_block b2 = a.reallocate(std::move(b1), sz, ao);

	BOOST_CHECK(a.has_allocated(b2, ao));

	a.deallocate(std::move(b2), ao);

	std::deque<memory::owned_block> blks;

	for(std::size_t i=0; i<n; ++i)
	{
		blks.emplace_back(a.allocate(span_size_of<T>(), ao));
	}

	for(memory::owned_block& blk : blks)
	{
		BOOST_CHECK(blks.back().size() >= span_size_of<T>());
		BOOST_CHECK(blks.back().is_aligned_to(ao));
		BOOST_CHECK(!!a.has_allocated(blk, ao));
	}

	while(!blks.empty())
	{
		auto i = blks.begin() + rg.get_int(0, int(blks.size())-1);
		a.deallocate(std::move(*i), ao);
		blks.erase(i);
	}

	a.release();
}

BOOST_AUTO_TEST_CASE(memory_align_alloc_1)
{
	std::size_t f[2] = {0,1};

	for(int i=0; i<20; ++i)
	{
		std::size_t n = f[(i+0)%2]+f[(i+1)%2];
		f[i%2] = n;

		eagine_test_memory_align_alloc_T<char>(n);
		eagine_test_memory_align_alloc_T<short>(n);
		eagine_test_memory_align_alloc_T<int>(n);
		eagine_test_memory_align_alloc_T<float>(n);
		eagine_test_memory_align_alloc_T<double>(n);
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
