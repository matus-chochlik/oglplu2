/**
 *  @file eagine/memory/stack_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_STACK_ALLOC_1509260923_HPP
#define EAGINE_MEMORY_STACK_ALLOC_1509260923_HPP

#include "byte_alloc.hpp"
#include <type_traits>
#include <cassert>

namespace eagine {
namespace memory {

// base_stack_allocator
// non-rebindable non-copyable stack allocator
// use with care!
template <typename T>
class base_stack_allocator
 : public block_owner
{
private:
	T* _btm;
	T* _top;
	T* _pos;
	T* _min;
	std::size_t _dif;

	const_block _store(void) const
	noexcept;

	const_block _allocated(void) const
	noexcept;

	const_block _available(void) const
	noexcept;
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

	base_stack_allocator(const base_stack_allocator&) = delete;

	base_stack_allocator(base_stack_allocator&& tmp)
	noexcept;

	base_stack_allocator(void)
	noexcept;

	base_stack_allocator(const block& blk, std::size_t align)
	noexcept;

	base_stack_allocator(const block& blk)
	noexcept;

	~base_stack_allocator(void)
	noexcept;

	size_type max_size(void) const
	noexcept
	{
		return _available().size();
	}

	size_type allocated_size(void) const
	noexcept
	{
		return _allocated().size();
	}

	tribool has_allocated(const owned_block& b) const
	noexcept;

	owned_block allocate(size_type n)
	noexcept;

	owned_block truncate(owned_block&& b, size_type nn)
	noexcept;

	void deallocate(owned_block&& b)
	noexcept;

	friend bool operator == (
		const base_stack_allocator& a,
		const base_stack_allocator& b
	) noexcept
	{
		if((a._btm == b._btm) && (a._top == b._top))
		{
			assert(a._pos == b._pos);
			assert(a._min == b._min);
			assert(a._dif == b._dif);

			return true;
		}
		return false;
	}
};

// stack_byte_allocator
template <typename Policy = default_byte_allocator_policy>
class stack_byte_allocator
 : public byte_allocator_impl<Policy, stack_byte_allocator>
{
private:
	base_stack_allocator<byte> _alloc;
public:
	typedef byte value_type;
	typedef std::size_t size_type;

	stack_byte_allocator(stack_byte_allocator&&) = default;
	stack_byte_allocator(const block& blk)
	 : _alloc(blk)
	{ }

	bool equal(byte_allocator* a) const
	noexcept
	override;

	size_type max_size(size_type a)
	noexcept
	override
	{
		return	_alloc.max_size()>a?
			_alloc.max_size()-a:0;
	}

	tribool has_allocated(const owned_block& b, std::size_t)
	noexcept
	override
	{
		return _alloc.has_allocated(b);
	}

	owned_block allocate(size_type n, size_type a)
	noexcept
	override;

	void deallocate(owned_block&& b, size_type)
	noexcept
	override;
};

// stack_aligned_byte_allocator
template <typename Policy = default_byte_allocator_policy>
class stack_aligned_byte_allocator
 : public byte_allocator_impl<Policy, stack_aligned_byte_allocator>
{
private:
	std::size_t _align;

	base_stack_allocator<byte> _alloc;
	typedef stack_aligned_byte_allocator _this_class;
public:
	typedef byte value_type;
	typedef std::size_t size_type;

	stack_aligned_byte_allocator(stack_aligned_byte_allocator&&) = default;

	stack_aligned_byte_allocator(const block& blk, std::size_t align)
	 : _align(align)
	 , _alloc(blk, _align)
	{ }

	bool equal(byte_allocator* a) const
	noexcept
	override;

	size_type max_size(size_type)
	noexcept
	override
	{
		return _alloc.max_size();
	}

	tribool has_allocated(const owned_block& b, std::size_t)
	noexcept
	override;

	owned_block allocate(size_type n, size_type a)
	noexcept
	override;

	void deallocate(owned_block&& b, size_type a)
	noexcept
	override;

	std::size_t _own_end_misalign(_this_class* p) const
	noexcept;

	byte_allocator* accomodate_self(void)
	noexcept;

	void eject_self(void)
	noexcept
	override;
};

} // namespace memory
} // namespace eagine

#include <eagine/memory/stack_alloc.inl>

#endif //include guard

