/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_std_alloc
#include <boost/test/unit_test.hpp>

#include <eagine/memory/std_alloc.hpp>
#include <cstdlib>
#include <vector>

BOOST_AUTO_TEST_SUITE(memory_std_alloc_tests)

template <typename T>
void eagine_test_memory_std_alloc_1_T(std::size_t n)
{
	using namespace eagine;

	memory::std_allocator<T> a;

	T* p = a.allocate(n);
	BOOST_CHECK(p != nullptr);
	a.deallocate(p, n);

	std::vector<T, memory::std_allocator<T>> v;

	for(std::size_t i=1; i<=n; ++i)
	{
		v.reserve(i);
	}

	for(std::size_t i=1; i<=n; ++i)
	{
		v.push_back(T());
	}

	v.clear();

	for(std::size_t i=1; i<=n; ++i)
	{
		v.push_back(T());
	}
	BOOST_CHECK(v.size() == n);

}

BOOST_AUTO_TEST_CASE(memory_std_alloc_1)
{
	std::size_t f[2] = {0,1};

	for(int i=0; i<20; ++i)
	{
		std::size_t n = f[(i+0)%2]+f[(i+1)%2];
		f[i%2] = n;

		eagine_test_memory_std_alloc_1_T<char>(n);
		eagine_test_memory_std_alloc_1_T<short>(n);
		eagine_test_memory_std_alloc_1_T<int>(n);
		eagine_test_memory_std_alloc_1_T<float>(n);
		eagine_test_memory_std_alloc_1_T<double>(n);
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
