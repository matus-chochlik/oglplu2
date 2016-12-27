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
#include <cassert>
#include <utility>
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

	block _do_allocate(
		const span_size_t size,
		const span_size_t align
	) {
		owned_block b = _alloc.allocate(size, align);

		if(b.empty()) { return {}; }

		assert(b.is_aligned_to(align));
		assert(b.size() >= size);

		_blks.push_back(std::move(b));
		_alns.push_back(align);

		return _blks.back();
	}

	template <typename T>
	block _allocate(
		const span_size_t count,
		const span_size_t align
	) {
		return _do_allocate(
			span_size_of<T>(count),
			std::max(align, span_align_of<T>())
		);
	}

	template <typename T>
	T* _make_n(const span_size_t count, const span_size_t align) {
		block b = _allocate<T>(count, align);
		return new(b.data()) T[std_size(count)];
	}

	template <typename T, typename ... Args>
	T* _make_1(const span_size_t align, Args&& ... args) {
		block b = _allocate<T>(1, align);
		return new(b.data()) T(std::forward<Args>(args)...);
	}

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

	~basic_allocation_arena(void) {
		clear();
	}

	bool empty(void) const
	noexcept {
		assert(_blks.empty() == _alns.empty());
		return _blks.empty();
	}

	void clear(void) {
		assert(_blks.size() == _alns.size());

		for(std_size_t i=0; i<_blks.size(); ++i) {
			_alloc.deallocate(std::move(_blks[i]), _alns[i]);
		}
		_blks.clear();
		_alns.clear();
	}

	block allocate(span_size_t size, span_size_t align) {
		_blks.push_back(_alloc.allocate(size, align));
		_alns.push_back(align);
		return _blks.back();
	}

	template <typename T, typename ... Arg>
	span<T> make_aligned_array(
		const span_size_t count,
		const span_size_t align
	) {
		if(count < 1) { return {nullptr, span_size_t{0}}; }

		T* p = _make_n<T>(count, align);
		if(!p) { throw std::bad_alloc(); }
		return {p, count};
	}

	template <typename T, typename ... Args>
	T& make_aligned(const span_size_t align, Args&& ... args) {

		T* p = _make_1<T>(align, std::forward<Args>(args)...);
		if(!p) { throw std::bad_alloc(); }

		return *p;
	}

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

#endif // include guard
