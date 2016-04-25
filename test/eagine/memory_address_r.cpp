/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_address
#include <boost/test/unit_test.hpp>

#include <eagine/memory/address.hpp>
#include <cstdlib>
#include <type_traits>

BOOST_AUTO_TEST_SUITE(memory_address_tests)

template <bool is_const>
void eagine_test_memory_address_0(void)
{
	using namespace eagine;

	typedef const void* cptr;
	typedef typename std::conditional<is_const, cptr, void*>::type ptr;

	memory::basic_address<is_const> bma1;
	memory::basic_address<is_const> bma2(nullptr);
	memory::basic_address<is_const> bma3 = bma1;

	BOOST_CHECK(!bool(bma1));
	BOOST_CHECK(!bool(bma2));
	BOOST_CHECK(!bool(bma3));
	BOOST_CHECK(bool(!bma1));
	BOOST_CHECK(bool(!bma2));
	BOOST_CHECK(bool(!bma3));
	BOOST_CHECK(static_cast<ptr>(bma1) == nullptr);
	BOOST_CHECK(static_cast<ptr>(bma2) == nullptr);
	BOOST_CHECK(static_cast<ptr>(bma3) == nullptr);
	BOOST_CHECK(static_cast<cptr>(bma1) == nullptr);
	BOOST_CHECK(static_cast<cptr>(bma2) == nullptr);
	BOOST_CHECK(static_cast<cptr>(bma3) == nullptr);
	BOOST_CHECK(bma1.get() == nullptr);
	BOOST_CHECK(bma2.get() == nullptr);
	BOOST_CHECK(bma3.get() == nullptr);
	BOOST_CHECK_EQUAL(bma1.value(), 0);
	BOOST_CHECK_EQUAL(bma2.value(), 0);
	BOOST_CHECK_EQUAL(bma3.value(), 0);
	BOOST_CHECK_EQUAL(bma1 - bma2, 0);
	BOOST_CHECK_EQUAL(bma2 - bma1, 0);
	BOOST_CHECK_EQUAL(bma1 - bma3, 0);
	BOOST_CHECK(bma1 == bma1);
	BOOST_CHECK(bma2 == bma2);
	BOOST_CHECK(bma3 == bma3);
	BOOST_CHECK(bma1 == bma2);
	BOOST_CHECK(bma1 == bma3);
	BOOST_CHECK(bma2 == bma1);
	BOOST_CHECK(!(bma1 != bma2));
	BOOST_CHECK(!(bma1 != bma3));
	BOOST_CHECK(!(bma2 != bma1));
	BOOST_CHECK(!(bma1 != bma1));
	BOOST_CHECK(!(bma2 != bma2));
	BOOST_CHECK(!(bma3 != bma3));
	BOOST_CHECK_EQUAL(bma1.misalignment(1), 0);
	BOOST_CHECK_EQUAL(bma1.misalignment(2), 0);
	BOOST_CHECK_EQUAL(bma1.misalignment(4), 0);
	BOOST_CHECK_EQUAL(bma1.misalignment(8), 0);
	BOOST_CHECK(bma2.is_aligned_to(1));
	BOOST_CHECK(bma2.is_aligned_to(2));
	BOOST_CHECK(bma2.is_aligned_to(4));
	BOOST_CHECK(bma2.is_aligned_to(8));
}

BOOST_AUTO_TEST_CASE(memory_address_0)
{
	eagine_test_memory_address_0<true>();
	eagine_test_memory_address_0<false>();
}

template <bool is_const>
void eagine_test_memory_address_1(void)
{
	using namespace eagine;

	typedef const void* cptr;
	typedef typename std::conditional<is_const, cptr, void*>::type ptr;

	char c;
	int i;
	double d;

	memory::basic_address<is_const> bma1(&c);
	memory::basic_address<is_const> bma2(&i);
	memory::basic_address<is_const> bma3(&d);

	BOOST_CHECK(bool(bma1));
	BOOST_CHECK(bool(bma2));
	BOOST_CHECK(bool(bma3));
	BOOST_CHECK(!!bma1);
	BOOST_CHECK(!!bma2);
	BOOST_CHECK(!!bma3);
	BOOST_CHECK(static_cast<ptr>(bma1) == &c);
	BOOST_CHECK(static_cast<ptr>(bma2) == &i);
	BOOST_CHECK(static_cast<ptr>(bma3) == &d);
	BOOST_CHECK(static_cast<cptr>(bma1) == &c);
	BOOST_CHECK(static_cast<cptr>(bma2) == &i);
	BOOST_CHECK(static_cast<cptr>(bma3) == &d);
	BOOST_CHECK_EQUAL(bma1.value(), reinterpret_cast<std::uintptr_t>(&c));
	BOOST_CHECK_EQUAL(bma2.value(), reinterpret_cast<std::uintptr_t>(&i));
	BOOST_CHECK_EQUAL(bma3.value(), reinterpret_cast<std::uintptr_t>(&d));
	BOOST_CHECK_EQUAL(bma1 - bma2, bma1.ptr() - bma2.ptr());
	BOOST_CHECK_EQUAL(bma1 - bma3, bma1.ptr() - bma3.ptr());
	BOOST_CHECK_EQUAL(bma2 - bma3, bma2.ptr() - bma3.ptr());
	BOOST_CHECK(bma1 == bma1);
	BOOST_CHECK(bma2 == bma2);
	BOOST_CHECK(bma3 == bma3);
	BOOST_CHECK(bma1 != bma2);
	BOOST_CHECK(bma1 != bma3);
	BOOST_CHECK(bma2 != bma3);
	BOOST_CHECK(bma2 != bma1);
	BOOST_CHECK(bma3 != bma1);
	BOOST_CHECK(bma3 != bma2);
	BOOST_CHECK_EQUAL(bma1.misalignment(alignof(char)), 0);
	BOOST_CHECK_EQUAL(bma2.misalignment(alignof(int)), 0);
	BOOST_CHECK_EQUAL(bma3.misalignment(alignof(double)), 0);
	BOOST_CHECK(bma1.is_aligned_to(alignof(char)));
	BOOST_CHECK(bma2.is_aligned_to(alignof(int)));
	BOOST_CHECK(bma3.is_aligned_to(alignof(double)));
}

BOOST_AUTO_TEST_CASE(memory_address_1)
{
	eagine_test_memory_address_1<true>();
	eagine_test_memory_address_1<false>();
}

template <bool is_const>
void eagine_test_memory_address_2(void)
{
	using namespace eagine;

	for(int i=0; i<100; ++i)
	{
		int offs = std::rand()%1000 - std::rand()%1000;

		memory::basic_address<is_const> bma1(&i);
		memory::basic_address<is_const> bma2 = bma1+offs;
		memory::basic_address<is_const> bma3 = bma1-offs;

		BOOST_CHECK(bma1 == bma2-offs);
		BOOST_CHECK(bma1 == bma3+offs);
	}
}

BOOST_AUTO_TEST_CASE(memory_address_2)
{
	eagine_test_memory_address_2<true>();
	eagine_test_memory_address_2<false>();
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
