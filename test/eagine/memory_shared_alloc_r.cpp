/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_shared_alloc
#include <boost/test/unit_test.hpp>

#include <eagine/memory/shared_alloc.hpp>
#include <eagine/memory/c_realloc.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(memory_shared_alloc_tests)

template <typename T>
void eagine_test_memory_shared_alloc_1_T(void)
{
	using namespace eagine;

	memory::shared_byte_allocator a;

	const span_size_t ao = span_align_of<T>();

	BOOST_CHECK(!bool(a));
	BOOST_CHECK(!a);

	BOOST_CHECK(!(a.max_size(ao) > 0));

	memory::owned_block b = a.allocate(0, ao);

	BOOST_CHECK(!bool(b));
	BOOST_CHECK(!b);

	BOOST_CHECK(!!a.has_allocated(b, ao));

	BOOST_CHECK(a.can_reallocate(b, 0, ao));
	BOOST_CHECK(!a.can_reallocate(b, span_size_t(1+std::rand()%1000), ao));

	b = a.reallocate(std::move(b), 0, ao);

	BOOST_CHECK(!bool(b));
	BOOST_CHECK(!b);

	a.deallocate(std::move(b), ao);
}

BOOST_AUTO_TEST_CASE(memory_shared_alloc_1)
{
	eagine_test_memory_shared_alloc_1_T<char>();
	eagine_test_memory_shared_alloc_1_T<short>();
	eagine_test_memory_shared_alloc_1_T<int>();
	eagine_test_memory_shared_alloc_1_T<long>();
	eagine_test_memory_shared_alloc_1_T<double>();
}

template <typename T>
void eagine_test_memory_shared_alloc_2_T(std::size_t n)
{
	using namespace eagine;

	memory::shared_byte_allocator a((memory::c_byte_reallocator<>()));

	const span_size_t ao = span_align_of<T>();
	const span_size_t sz = span_size_of<T>(n);

	BOOST_CHECK(bool(a));
	BOOST_CHECK(!!a);

	BOOST_CHECK(a.max_size(ao) > 0);

	memory::owned_block b = a.allocate(sz, ao);

	BOOST_CHECK(bool(a));
	BOOST_CHECK(!!a);

	BOOST_CHECK(!!a.has_allocated(b, ao));

	BOOST_CHECK(a.can_reallocate(b, sz, ao));

	b = a.reallocate(std::move(b), sz, ao);

	BOOST_CHECK(bool(b));
	BOOST_CHECK(!!b);

	BOOST_CHECK(a.can_reallocate(b, sz*2, ao));

	b = a.reallocate(std::move(b), sz*2, ao);

	BOOST_CHECK(bool(b));
	BOOST_CHECK(!!b);

	BOOST_CHECK(a.can_reallocate(b, sz, ao));

	b = a.reallocate(std::move(b), sz, ao);

	BOOST_CHECK(bool(b));
	BOOST_CHECK(!!b);

	a.deallocate(std::move(b), ao);

	BOOST_CHECK(!bool(b));
	BOOST_CHECK(!b);
}

BOOST_AUTO_TEST_CASE(memory_shared_alloc_2)
{
	std::size_t f[2] = {0, 1};

	for(int i=0; i<20; ++i)
	{
		std::size_t n = f[(i+0)%2]+f[(i+1)%2];
		f[i%2] = n;

		eagine_test_memory_shared_alloc_2_T<char>(n);
		eagine_test_memory_shared_alloc_2_T<short>(n);
		eagine_test_memory_shared_alloc_2_T<int>(n);
		eagine_test_memory_shared_alloc_2_T<long>(n);
		eagine_test_memory_shared_alloc_2_T<double>(n);
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
