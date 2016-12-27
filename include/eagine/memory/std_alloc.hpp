/**
 *  @file eagine/memory/std_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_STD_ALLOC_1509260923_HPP
#define EAGINE_MEMORY_STD_ALLOC_1509260923_HPP

#include "shared_alloc.hpp"
#include "default_alloc.hpp"
#include <memory>

namespace eagine {
namespace memory {

// std_allocator
template <typename T>
class std_allocator
 : public block_owner
{
private:
	shared_byte_allocator _sba; 
public:
	const shared_byte_allocator& _get_sba(void) const { return _sba; }

	typedef T value_type;
	typedef span_size_t size_type;

	typedef std::true_type propagate_on_container_move_assignment;
	typedef std::true_type propagate_on_container_copy_assignment;
	typedef std::true_type propagate_on_container_swap;
	typedef std::false_type is_always_equal;

	template <typename U>
	struct rebind {
		typedef std_allocator<U> other;
	};

	template <typename U>
	std_allocator(const std_allocator<U>& that)
	 : _sba(that._get_sba())
	{ }

	std_allocator(shared_byte_allocator&& sba)
	noexcept
	 : _sba(std::move(sba))
	{ }

	std_allocator(void)
	noexcept
	 : _sba(default_byte_allocator())
	{ }

	template <typename ByteAlloc>
	ByteAlloc& as(void) {
		return _sba.as<ByteAlloc>();
	}

	T* address(T& r)
	noexcept {
		return std::allocator<T>().address(r);
	}

	const T* address(const T& r)
	noexcept {
		return std::allocator<T>().address(r);
	}

	size_type max_size(void) const
	noexcept {
		return _sba.max_size(alignof(T));
	}

	T* allocate(size_type n, const void* = nullptr) {
		owned_block b = _sba.allocate(
			span_size_of<T>(n),
			span_align_of<T>()
		);

		if(!b) {
			throw std::bad_alloc();
		}

		assert(b.is_aligned_to(span_align_of<T>()));
		assert(b.size() >= span_size_of<T>(n));

		T* p = static_cast<T*>(b.addr());

		release_block(std::move(b));

		return p;
	}

	void deallocate(T* p, size_type n) {
		_sba.deallocate(
			acquire_block({p, span_size_of<T>(n)}),
			span_align_of<T>()
		);
	}

	friend
	bool operator == (const std_allocator& a, const std_allocator& b)
	noexcept {
		return(a._sba == b._sba);
	}

	friend
	bool operator != (const std_allocator& a, const std_allocator& b)
	noexcept {
		return(a._sba != b._sba);
	}

	template <class U, class ... A>
	static inline
	void construct(U* p, A&& ... a) {
		::new(static_cast<void*>(p)) U(std::forward<A>(a)...);
	}

	template <typename U>
	static inline
	void destroy(U* p)
	noexcept(noexcept(p->~U())) {
		return p->~U();
	}
};

} // namespace memory
} // namespace eagine

#endif //include guard

