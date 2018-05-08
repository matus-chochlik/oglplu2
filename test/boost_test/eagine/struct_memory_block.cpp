/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/struct_memory_block.hpp>
#define BOOST_TEST_MODULE EAGINE_struct_memory_block
#include "../unit_test_begin.inl"

#include <tuple>
#include <utility>
#include <vector>

BOOST_AUTO_TEST_SUITE(struct_memory_block_tests)

static eagine::test_random_generator rg;

template <typename T>
void
eagine_test_struct_memory_block_1(void) {
    using namespace eagine;

    std::vector<unsigned char> buf(2 * span_size_of<T>());

    for(int i = 0; i < 100; ++i) {
	memory_block blk(
	  buf.data(), rg.get<span_size_t>(0, span_size(buf.size()) - 1));

	BOOST_CHECK_EQUAL(structured_memory_block<T>::is_valid_block(blk),
	  blk.size() >= span_size(span_size_of<T>()));
    }
    BOOST_CHECK_EQUAL(
      structured_memory_block<T>::is_valid_block(memory_block()), false);
}

BOOST_AUTO_TEST_CASE(struct_memory_block_1) {
    eagine_test_struct_memory_block_1<unsigned long>();
    eagine_test_struct_memory_block_1<std::pair<float, double>>();
    eagine_test_struct_memory_block_1<std::tuple<bool, char, int, short>>();
}

template <typename T>
void
eagine_test_struct_memory_block_2_T(T& value) {
    using namespace eagine;

    structured_memory_block<T> smb(memory::block_of(value));

    BOOST_CHECK_EQUAL(smb.get().first.first, value.first.first);
    BOOST_CHECK_EQUAL(smb.get().first.second, value.first.second);
    BOOST_CHECK_EQUAL(smb.get().second.first, value.second.first);
    BOOST_CHECK_EQUAL(smb.get().second.second, value.second.second);

    BOOST_CHECK_EQUAL(smb.get().first.first, smb->first.first);
    BOOST_CHECK_EQUAL(smb.get().first.second, smb->first.second);
    BOOST_CHECK_EQUAL(smb.get().second.first, smb->second.first);
    BOOST_CHECK_EQUAL(smb.get().second.second, smb->second.second);
}

template <typename T>
void
eagine_test_struct_memory_block_2(T&& value) {
    eagine_test_struct_memory_block_2_T<T>(value);
    eagine_test_struct_memory_block_2_T<const T>(value);
}

BOOST_AUTO_TEST_CASE(struct_memory_block_2) {
    eagine_test_struct_memory_block_2(
      std::make_pair(std::make_pair('c', 1), std::make_pair(0u, true)));
    eagine_test_struct_memory_block_2(
      std::make_pair(std::make_pair(1.0, 1L), std::make_pair(2.f, 10ULL)));
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
