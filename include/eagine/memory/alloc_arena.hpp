/**
 *  @file eagine/memory/alloc_arena.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_ALLOC_ARENA_1510290655_HPP
#define EAGINE_MEMORY_ALLOC_ARENA_1510290655_HPP

#include "c_realloc.hpp"
#include "../span.hpp"
#include "../string_span.hpp"
#include <cassert>
#include <utility>
#include <algorithm>
#include <vector>

namespace eagine {
namespace memory {

template <typename Alloc>
class basic_allocation_arena
 : public block_owner
{
private:
	Alloc _alloc; 
	std::vector<owned_block> _blks;
	std::vector<span_size_t> _alns;

	block _do_allocate(const span_size_t size, const span_size_t align);

	template <typename T>
	block _allocate(const span_size_t count, const span_size_t align);

	template <typename T>
	T* _make_n(const span_size_t count, const span_size_t align);

	template <typename T, typename ... Args>
	T* _make_1(const span_size_t align, Args&& ... args);
public:
	basic_allocation_arena(void) = default;

	template <typename ... P>
	explicit
	basic_allocation_arena(P&& ... p)
	 : _alloc(std::forward<P>(p)...)
	{ }

	explicit
	basic_allocation_arena(Alloc&& alloc)
	 : _alloc(std::move(alloc))
	{ }

	~basic_allocation_arena(void) { clear(); }

	bool empty(void) const
	noexcept {
		assert(_blks.empty() == _alns.empty());
		return _blks.empty();
	}

	void clear(void);

	block allocate(span_size_t size, span_size_t align) {
		_blks.push_back(_alloc.allocate(size, align));
		_alns.push_back(align);
		return _blks.back();
	}

	template <typename T>
	span<T> make_aligned_array(
		const span_size_t count,
		const span_size_t align
	);

	template <typename T>
	span<T> make_array(const span_size_t count) {
		return make_aligned_array<T>(count, 1);
	}

	template <typename T, typename U, span_size_t N>
	span<T> copy_aligned_array(
		span<U, N> src,
		const span_size_t align
	) {
		span<T> dst = make_aligned_array<T>(src.size(), align);
		std::copy(src.begin(), src.end(), dst.begin());
		return dst;
	}

	template <typename T, typename U, span_size_t N>
	span<T> copy_array(span<U, N> src) {
		return copy_aligned_array<T>(src, 1);
	}

	template <typename T, typename U, span_size_t N>
	span<T> copy_aligned_array(
		basic_string_span<U, N> src,
		const span_size_t align
	) {
		span<T> dst = make_aligned_array<T>(src.size(), align);
		std::copy(src.begin(), src.end(), dst.begin());
		return dst;
	}

	template <typename T, typename U, span_size_t N>
	span<T> copy_array(basic_string_span<U, N> src) {
		return copy_aligned_array<T>(src, 1);
	}

	template <typename T, typename ... Args>
	T& make_aligned(const span_size_t align, Args&& ... args);

	template <typename T, typename ... Args>
	T& make(Args&& ... args) {
		return make_aligned<T>(1, std::forward<Args>(args)...);
	}

	template <typename T>
	void destroy(T& v) { v.~T(); }
};

using system_allocation_arena = basic_allocation_arena<
	c_byte_reallocator<byte_alloc_managed_policy>
>;

} // namespace memory
} // namespace eagine

#include <eagine/memory/alloc_arena.inl>

#endif // include guard
