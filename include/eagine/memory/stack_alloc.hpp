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
	noexcept
	{
		assert(_btm <= _top);
		return const_block(_btm, _top);
	}

	const_block _allocated(void) const
	noexcept
	{
		assert(_btm <= _pos);
		return const_block(_btm, _pos);
	}

	const_block _available(void) const
	noexcept
	{	
		assert(_pos <= _top);
		return const_block(_pos, _top);
	}
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
	noexcept
	 : _btm(tmp._btm)
	 , _top(tmp._top)
	 , _pos(tmp._pos)
	 , _min(tmp._min)
	 , _dif(tmp._dif)
	{
		tmp._btm = nullptr;
		tmp._top = nullptr;
		tmp._pos = nullptr;
		tmp._min = nullptr;
		tmp._dif = 0;
	}

	base_stack_allocator(void)
	noexcept
	 : _btm(nullptr)
	 , _top(nullptr)
	 , _pos(nullptr)
	 , _min(nullptr)
	 , _dif(0)
	{ }

	base_stack_allocator(const block& blk, std::size_t align)
	noexcept
	 : _btm(align_up_to<T>(blk.begin(), align))
	 , _top(align_down_to<T>(blk.end(), align))
	 , _pos(_btm)
	 , _min(_btm)
	 , _dif(0)
	{ }

	base_stack_allocator(const block& blk)
	noexcept
	 : base_stack_allocator(blk, alignof(T))
	{ }

	~base_stack_allocator(void)
	noexcept
	{
		if(!std::is_trivially_destructible<T>())
		{
			assert(_allocated().empty());
		}
	}

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
	noexcept
	{
		if(_store().contains(b))
		{
			assert(_allocated().contains(b));
			return true;
		}
		return false;
	}

	owned_block allocate(size_type n)
	noexcept
	{
		if(n > max_size())
		{
			return {};
		}

		pointer result = static_cast<pointer>(_pos);

		assert(_min <= _pos);
		if(_min == _pos)
		{
			_min += n;
		}
		else
		{
			_dif += n;
		}

		_pos += n;
		return acquire_block({result, n});
	}

	owned_block truncate(owned_block&& b, size_type nn)
	noexcept
	{
		pointer p = static_cast<pointer>(b.addr());
		size_type pn = b.size();
		release_block(std::move(b));

		assert(pn >= nn);

		if(p+pn == _pos)
		{
			difference_type d = difference_type(pn - nn);
			assert(_min <= _pos);
			if(_min == _pos)
			{
				_min -= d;
			}
			else
			{
				_dif -= d;
			}

			_pos -= d;
		}
		return acquire_block({p, nn});
	}

	void deallocate(owned_block&& b)
	noexcept
	{
		pointer p = static_cast<pointer>(b.addr());
		size_type n = b.size();
		release_block(std::move(b));

		assert(p+n <= _pos);
		if(p+n == _pos)
		{
			assert(_min <= _pos);
			if(_min == _pos)
			{
				_min -= n;
			}
			else
			{
				_dif -= n;
			}

			_pos -= n;
		}
		else
		{
			if(p+n == _min)
			{
				_min -= n;
			}
			else if(p+n > _min)
			{
				_dif -= n;
			}
			else
			{
				_dif += size_type(_min-p)-n;
				_min = p;
			}
		}
		if(_dif == 0)
		{
			_pos = _min;
		}
	}

	friend bool operator == (
		const base_stack_allocator& a,
		const base_stack_allocator& b
	)
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
	override
	{
		stack_byte_allocator* sba =
			dynamic_cast<stack_byte_allocator*>(a);

		return (sba != nullptr) && (this->_alloc == sba->_alloc);
	}

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
	override
	{
		size_type m = a - _alloc.allocated_size() % a;

		assert((m < 255) && "must fit into a byte"); 

		owned_block b = _alloc.allocate(m+n);

		if(b)
		{
			assert(is_aligned_to(b.begin()+m, a));
			b[m-1] = byte(m);
		}

		assert(m <= b.size());

		owned_block r = this->acquire_block({b.begin()+m, b.end()});

		this->release_block(std::move(b));

		return std::move(r);
	}

	void deallocate(owned_block&& b, size_type)
	noexcept
	override
	{
		assert(_alloc.has_allocated(b));

		byte* p = b.data();

		assert(reinterpret_cast<std::uintptr_t>(p) >= 1);

		size_type m = size_type(p[-1]);

		assert(reinterpret_cast<std::uintptr_t>(p) >= m);

		_alloc.deallocate(this->acquire_block({p-m, b.size()+m}));

		this->release_block(std::move(b));
	}
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
	override
	{
		auto* sba = dynamic_cast<_this_class*>(a);

		return (sba != nullptr) && (this->_alloc == sba->_alloc);
	}

	size_type max_size(size_type)
	noexcept
	override
	{
		return _alloc.max_size();
	}

	tribool has_allocated(const owned_block& b, std::size_t)
	noexcept
	override
	{
		return _alloc.has_allocated(b);
	}

	owned_block allocate(size_type n, size_type a)
	noexcept
	override
	{
		auto b = _alloc.allocate(n, a);

		assert(b.is_aligned_to(a));

		return std::move(b);
	}

	void deallocate(owned_block&& b, size_type a)
	noexcept
	override
	{
		assert(b.is_aligned_to(a));
		_alloc.deallocate(std::move(b));
	}

	std::size_t _own_end_misalign(_this_class* p) const
	noexcept
	{
		std::uintptr_t e =
			reinterpret_cast<std::uintptr_t>(p)+
			sizeof(_this_class);

		return (_align - (e % _align)) % _align;
	}

	byte_allocator* accomodate_self(void)
	noexcept
	{
		auto* ba = this->accomodate_derived(*this);

		if(std::size_t m = _own_end_misalign(ba))
		{
			this->release_block(ba->_alloc.allocate(m));
		}

		return ba;
	}

	void eject_self(void)
	noexcept
	override
	{
		if(std::size_t m = _own_end_misalign(this))
		{
			byte* p = reinterpret_cast<byte*>(this);
			p += sizeof(_this_class);

			_alloc.deallocate(this->acquire_block({p, m}));
		}

		this->eject_derived(*this);
	}
};

} // namespace memory
} // namespace eagine

#endif //include guard

