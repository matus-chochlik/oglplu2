/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_alloc_arena
#include <boost/test/unit_test.hpp>
#include <algorithm>
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
			switch(rg.get_int(0, 6)) {
				case 0: alc.allocate(
					rg.get_span_size(1,128),
					1 << rg.get_span_size(0, 4)
				); break;
				case 1: alc.make<char>(); break;
				case 2: alc.make<short>(); break;
				case 3: alc.make<int>(); break;
				case 4: alc.make<long>(); break;
				case 5: alc.make<test_struct_1>(); break;
				case 6: alc.make<test_struct_2>(); break;
			}
		}

		alc.clear();

		BOOST_CHECK(alc.empty());
	}
}

BOOST_AUTO_TEST_CASE(memory_owning_alloc_2)
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
			const span_size_t align = (1 << rg.get_span_size(0, 4));
			span_size_t align2 = 1;
			memory::const_address addr;

			switch(rg.get_int(0, 6)) {
				case 0: {
					memory::block b = alc.allocate(
						rg.get_span_size(1,128),
						align
					);
					addr = b.addr();
					break;
				}
				case 1: {
					align2 = span_align_of<char>();
					auto& x = alc.make_aligned<
						char
					>(align);
					addr = memory::as_address(&x);
					break;
				}
				case 2: {
					align2 = span_align_of<short>();
					auto& x = alc.make_aligned<
						short
					>(align);
					addr = memory::as_address(&x);
					break;
				}
				case 3: {
					align2 = span_align_of<int>();
					auto& x = alc.make_aligned<
						int
					>(align);
					addr = memory::as_address(&x);
					break;
				}
				case 4: {
					align2 = span_align_of<long>();
					auto& x = alc.make_aligned<
						long
					>(align);
					addr = memory::as_address(&x);
					break;
				}
				case 5: {
					align2 = span_align_of<test_struct_1>();
					auto& x = alc.make_aligned<
						test_struct_1
					>(align);
					addr = memory::as_address(&x);
					break;
				}
				case 6: {
					align2 = span_align_of<test_struct_2>();
					auto& x = alc.make_aligned<
						test_struct_2
					>(align);
					addr = memory::as_address(&x);
					break;
				}
			}
			BOOST_CHECK(addr.is_aligned_to(align));
			BOOST_CHECK(addr.is_aligned_to(align2));
		}

		alc.clear();

		BOOST_CHECK(alc.empty());
	}
}

BOOST_AUTO_TEST_CASE(memory_owning_alloc_3)
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
			std::vector<int> src(rg.get_std_size(1, 32));
			rg.fill(src);

			span<int> dst = alc.copy_aligned_array<int>(
				make_span(src), alignof(int)
			);

			BOOST_CHECK_EQUAL(src.size(), dst.size());
			BOOST_CHECK(std::equal(
				src.begin(),
				src.end(),
				dst.begin()
			));
		}

		alc.clear();

		BOOST_CHECK(alc.empty());
	}
}

BOOST_AUTO_TEST_CASE(memory_owning_alloc_4)
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
			std::string src(rg.get_string(1, 32));

			span<char> dst = alc.copy_aligned_array<char>(
				cstring_span(src), alignof(char)
			);

			BOOST_CHECK_EQUAL(src.size(), dst.size());
			BOOST_CHECK(std::equal(
				src.begin(),
				src.end(),
				dst.begin()
			));
		}

		alc.clear();

		BOOST_CHECK(alc.empty());
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
