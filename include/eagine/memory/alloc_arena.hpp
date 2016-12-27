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

#include "block.hpp"
#include <cassert>
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

	template <typename T>
	T& make(const span_size_t align = 1) {
		const span_size_t st = span_size_of<T>();
		const span_size_t al = span_align_of<T>();
		const span_size_t at = al>align?al:align;

		owned_block b = _alloc.allocate(st, at);

		if(!b) { throw std::bad_alloc(); }

		assert(b.is_aligned_to(at));
		assert(b.size() >= st);

		T* p = static_cast<T*>(b.addr());

		_blks.push_back(std::move(b));
		_alns.push_back(at);

		return *p;
	}

	template <typename T>
	void destroy(T& v) { v.~T(); }
};


} // namespace memory
} // namespace eagine

#endif // include guard
