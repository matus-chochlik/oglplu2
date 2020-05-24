/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/stack_alloc.hpp>
#define BOOST_TEST_MODULE EAGINE_memory_stack_alloc
#include "../unit_test_begin.inl"

#include <eagine/identity.hpp>
#include <deque>

BOOST_AUTO_TEST_SUITE(memory_stack_alloc_tests)

static eagine::test_random_generator rg;

template <typename T, typename Alloc>
void eagine_test_memory_stack_alloc_TA(std::size_t n, Alloc& a) {
    using namespace eagine;

    const span_size_t ao = span_align_of<T>();
    const span_size_t sz = span_size_of<T>(n);

    BOOST_CHECK(a.max_size(ao) > 0);

    memory::owned_block b1 = a.allocate(sz, ao);

    BOOST_CHECK(!b1.empty());
    BOOST_CHECK(b1.size() >= sz);
    BOOST_CHECK(is_aligned_to(b1.addr(), ao));

    BOOST_CHECK(a.has_allocated(b1, ao));

    memory::owned_block b2 = a.reallocate(std::move(b1), sz, ao);

    BOOST_CHECK(a.has_allocated(b2, ao));

    a.deallocate(std::move(b2), ao);

    std::deque<memory::owned_block> blks;

    for(std::size_t i = 0; i < n; ++i) {
        blks.emplace_back(a.allocate(span_size_of<T>(), ao));
    }

    for(memory::owned_block& blk : blks) {
        BOOST_CHECK(blks.back().size() >= span_size_of<T>());
        BOOST_CHECK(is_aligned_to(blks.back().addr(), ao));
        BOOST_CHECK(a.has_allocated(blk, ao));
    }

    while(!blks.empty()) {
        auto i = blks.begin() + rg.get_int(0, int(blks.size() - 1));
        a.deallocate(std::move(*i), ao);
        blks.erase(i);
    }
}

template <typename T>
void eagine_test_memory_stack_alloc_TA(
  eagine::memory::block& b,
  std::size_t n,
  eagine::identity<eagine::memory::stack_byte_allocator<>>) {
    using namespace eagine;

    memory::stack_byte_allocator<> a(b);

    eagine_test_memory_stack_alloc_TA<T>(n, a);

    a.release();
}

template <typename Alloc>
void eagine_test_memory_stack_alloc_A() {
    eagine::identity<Alloc> ai;

    static char buf[1024 * 1024];

    eagine::memory::block b = as_bytes(eagine::cover(buf));

    std::size_t f[2] = {0, 1};

    for(int i = 0; i < eagine::test_repeats(10, 20); ++i) {
        std::size_t n = f[(i + 0) % 2] + f[(i + 1) % 2];
        f[i % 2] = n;

        eagine_test_memory_stack_alloc_TA<char>(b, n, ai);
        eagine_test_memory_stack_alloc_TA<short>(b, n, ai);
        eagine_test_memory_stack_alloc_TA<int>(b, n, ai);
        eagine_test_memory_stack_alloc_TA<float>(b, n, ai);
        eagine_test_memory_stack_alloc_TA<double>(b, n, ai);
    }
}

BOOST_AUTO_TEST_CASE(memory_stack_alloc_1) {
    eagine_test_memory_stack_alloc_A<eagine::memory::stack_byte_allocator<>>();
}

BOOST_AUTO_TEST_CASE(memory_stack_alloc_2) {
    eagine_test_memory_stack_alloc_A<eagine::memory::stack_byte_allocator<>>();
}

template <typename T>
void test_mem_stack_alloc_3_hlp(
  std::deque<eagine::memory::owned_block>& blks,
  eagine::memory::stack_byte_allocator<>& a,
  std::size_t n) {
    blks.emplace_back(
      a.allocate(eagine::span_size_of<T>(n), eagine::span_align_of<T>()));
}

BOOST_AUTO_TEST_CASE(memory_stack_alloc_3) {
    using namespace eagine;

    static char buf[1024 * 1024];

    memory::stack_byte_allocator<> a(as_bytes(cover(buf)));

    std::deque<memory::owned_block> blks;

    for(int i = 0; i < eagine::test_repeats(40, 100); ++i) {
        std::size_t n = rg.get<std::size_t>(0, 10);

        switch(rg.get<std::size_t>(0, 10)) {
            case 0:
                test_mem_stack_alloc_3_hlp<int>(blks, a, n);
                break;
            case 1:
                test_mem_stack_alloc_3_hlp<long>(blks, a, n);
                break;
            case 2:
                test_mem_stack_alloc_3_hlp<float>(blks, a, n);
                break;
            case 3:
                test_mem_stack_alloc_3_hlp<double>(blks, a, n);
                break;
            case 4:
                test_mem_stack_alloc_3_hlp<short>(blks, a, n);
                break;
            default:
                test_mem_stack_alloc_3_hlp<char>(blks, a, n);
        }
    }

    for(std::size_t n = blks.size(), i = 0; i < n; ++i) {
        BOOST_CHECK(a.has_allocated(blks[i], 0));

        for(std::size_t j = i; j < n; ++j) {
            BOOST_CHECK(blks[i].overlaps(blks[j]) == (i == j));
        }
    }

    while(!blks.empty()) {
        auto i = blks.begin() + rg.get_int(0, int(blks.size() - 1));
        a.deallocate(std::move(*i), 0);
        blks.erase(i);
    }

    a.release();
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
