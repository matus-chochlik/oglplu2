/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/c_realloc.hpp>
#include "../memcheck.inl"

#include <deque>
#include <cassert>

static eagine::test_random_generator rg;

template <typename T>
void eagine_test_memory_c_realloc_1_T(std::size_t n) {
	using namespace eagine;

	memory::c_byte_reallocator<> a;

	const span_size_t ao = span_align_of<T>();
	const span_size_t sz = span_size_of<T>(n);

	assert(a.max_size(ao) >= sz);

	memory::owned_block b1 = a.allocate(sz, ao);

	assert(b1.empty() != bool(n));
	assert(b1.size() >= sz);
	assert(b1.is_aligned_to(ao));

	assert(!!a.has_allocated(b1, ao));

	memory::owned_block b2 = a.reallocate(std::move(b1), sz, ao);

	assert(b1.empty());
	assert(b2.size() >= sz);

	a.deallocate(std::move(b2), ao);

	std::deque<memory::owned_block> blks;

	for(std::size_t i=0; i<n; ++i) {
		blks.emplace_back(a.allocate(sizeof(T), ao));
	}

	assert(blks.back().size() >= span_size_of<T>());
	assert(blks.back().is_aligned_to(ao));

	for(memory::owned_block& blk : blks) {
		assert(!!a.has_allocated(blk, ao));
	}

	while(!blks.empty()) {
		auto i = blks.begin() + rg.get_int(0, int(blks.size())-1);
		a.deallocate(std::move(*i), ao);
		blks.erase(i);
	}

	a.release();
}

void eagine_test_memory_c_realloc_1(void) {
	std::size_t f[2] = {0,1};

	for(int i=0; i<16; ++i) {
		std::size_t n = f[(i+0)%2]+f[(i+1)%2];
		f[i%2] = n;

		eagine_test_memory_c_realloc_1_T<char>(n);
		eagine_test_memory_c_realloc_1_T<short>(n);
		eagine_test_memory_c_realloc_1_T<int>(n);
		eagine_test_memory_c_realloc_1_T<float>(n);
		eagine_test_memory_c_realloc_1_T<double>(n);
	}
}

int main(void) {
	eagine_test_memory_c_realloc_1();
	return 0;
}
