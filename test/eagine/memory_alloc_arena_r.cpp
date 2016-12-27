/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_alloc_arena
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

#include <eagine/memory/alloc_arena.hpp>
#include <eagine/memory/c_realloc.hpp>

BOOST_AUTO_TEST_SUITE(memory_owning_alloc_tests)

static eagine::test_random_generator rg;

struct test_struct_1 { int a; bool b; char c; };
struct test_struct_2 { double d; float f; };

BOOST_AUTO_TEST_CASE(memory_owning_alloc_1)
{
	using namespace eagine;

	memory::basic_allocation_arena<
		memory::c_byte_reallocator<
			memory::byte_alloc_managed_policy
		>
	> alc;

	BOOST_CHECK(alc.empty());

	for(int j=0; j<10; ++j) {

		for(int i=0; i<100; ++i) {
			switch(rg.get_int(0, 5)) {
				case 0: alc.make<char>(); break;
				case 1: alc.make<short>(); break;
				case 2: alc.make<int>(); break;
				case 3: alc.make<long>(); break;
				case 4: alc.make<test_struct_1>(); break;
				case 5: alc.make<test_struct_2>(); break;
			}
		}

		alc.clear();

		BOOST_CHECK(alc.empty());
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
