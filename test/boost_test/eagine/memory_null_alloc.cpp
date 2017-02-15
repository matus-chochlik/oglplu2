/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/null_alloc.hpp>
#define BOOST_TEST_MODULE EAGINE_memory_null_alloc
#include "../unit_test.inl"

BOOST_AUTO_TEST_SUITE(memory_null_alloc_tests)

template <typename T>
void eagine_test_memory_null_alloc_1_T(std::size_t n)
{
	using namespace eagine;

	memory::null_byte_allocator<> na;

	const span_size_t ao = span_align_of<T>();
	const span_size_t sz = span_size_of<T>(n);

	BOOST_CHECK_EQUAL(na.max_size(ao), 0);

	memory::owned_block b1 = na.allocate(sz, ao);

	BOOST_CHECK(b1.empty());
	BOOST_CHECK(b1.is_aligned_to(ao));

	BOOST_CHECK(!!na.has_allocated(b1, ao));

	memory::owned_block b2 = na.reallocate(std::move(b1), sz, ao);

	na.deallocate(std::move(b2), ao);

	na.release();
}

BOOST_AUTO_TEST_CASE(memory_null_alloc_1)
{
	std::size_t f[2] = {0,1};

	for(int i=0; i<20; ++i)
	{
		std::size_t n = f[(i+0)%2]+f[(i+1)%2];
		f[i%2] = n;

		eagine_test_memory_null_alloc_1_T<char>(n);
		eagine_test_memory_null_alloc_1_T<short>(n);
		eagine_test_memory_null_alloc_1_T<int>(n);
		eagine_test_memory_null_alloc_1_T<float>(n);
		eagine_test_memory_null_alloc_1_T<double>(n);
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
