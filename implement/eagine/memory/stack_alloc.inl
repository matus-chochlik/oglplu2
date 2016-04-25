/**
 *  @file eagine/stack_alloc.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
template <typename T>
inline
const_block
base_stack_allocator<T>::
_store(void) const
noexcept
{
	assert(_btm <= _top);
	return const_block(_btm, _top);
}
//------------------------------------------------------------------------------
template <typename T>
inline
const_block
base_stack_allocator<T>::
_allocated(void) const
noexcept
{
	assert(_btm <= _pos);
	return const_block(_btm, _pos);
}
//------------------------------------------------------------------------------
template <typename T>
inline
const_block
base_stack_allocator<T>::
_available(void) const
noexcept
{	
	assert(_pos <= _top);
	return const_block(_pos, _top);
}
//------------------------------------------------------------------------------
template <typename T>
inline
base_stack_allocator<T>::
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
//------------------------------------------------------------------------------
template <typename T>
inline
base_stack_allocator<T>::
base_stack_allocator(void)
noexcept
 : _btm(nullptr)
 , _top(nullptr)
 , _pos(nullptr)
 , _min(nullptr)
 , _dif(0)
{ }
//------------------------------------------------------------------------------
template <typename T>
inline
base_stack_allocator<T>::
base_stack_allocator(const block& blk, std::size_t align)
noexcept
 : _btm(align_up_to<T>(blk.addr(), align))
 , _top(align_down_to<T>(blk.end_addr(), align))
 , _pos(_btm)
 , _min(_btm)
 , _dif(0)
{ }
//------------------------------------------------------------------------------
template <typename T>
inline
base_stack_allocator<T>::
base_stack_allocator(const block& blk)
noexcept
 : base_stack_allocator(blk, alignof(T))
{ }
//------------------------------------------------------------------------------
template <typename T>
inline
base_stack_allocator<T>::
~base_stack_allocator(void)
noexcept
{
	if(!std::is_trivially_destructible<T>())
	{
		assert(_allocated().empty());
	}
}
//------------------------------------------------------------------------------
template <typename T>
inline
tribool
base_stack_allocator<T>::
has_allocated(const owned_block& b) const
noexcept
{
	if(_store().contains(b))
	{
		assert(_allocated().contains(b));
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
template <typename T>
inline
owned_block
base_stack_allocator<T>::
allocate(size_type n)
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
//------------------------------------------------------------------------------
template <typename T>
inline
owned_block
base_stack_allocator<T>::
truncate(owned_block&& b, size_type nn)
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
//------------------------------------------------------------------------------
template <typename T>
inline
void
base_stack_allocator<T>::
deallocate(owned_block&& b)
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
//------------------------------------------------------------------------------
template <typename Policy>
inline
bool
stack_byte_allocator<Policy>::
equal(byte_allocator* a) const
noexcept
{
	stack_byte_allocator* sba =
		dynamic_cast<stack_byte_allocator*>(a);

	return (sba != nullptr) && (this->_alloc == sba->_alloc);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
owned_block
stack_byte_allocator<Policy>::
allocate(size_type n, size_type a)
noexcept
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
//------------------------------------------------------------------------------
template <typename Policy>
inline
void
stack_byte_allocator<Policy>::
deallocate(owned_block&& b, size_type)
noexcept
{
	assert(_alloc.has_allocated(b));

	byte* p = b.data();

	assert(reinterpret_cast<std::uintptr_t>(p) >= 1);

	size_type m = size_type(p[-1]);

	assert(reinterpret_cast<std::uintptr_t>(p) >= m);

	_alloc.deallocate(this->acquire_block({p-m, b.size()+m}));

	this->release_block(std::move(b));
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
bool
stack_aligned_byte_allocator<Policy>::
equal(byte_allocator* a) const
noexcept
{
	auto* sba = dynamic_cast<_this_class*>(a);

	return (sba != nullptr) && (this->_alloc == sba->_alloc);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
tribool
stack_aligned_byte_allocator<Policy>::
has_allocated(const owned_block& b, std::size_t)
noexcept
{
	return _alloc.has_allocated(b);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
owned_block
stack_aligned_byte_allocator<Policy>::
allocate(size_type n, size_type a)
noexcept
{
	auto b = _alloc.allocate(n);

	assert(b.is_aligned_to(a));

	return std::move(b);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
void
stack_aligned_byte_allocator<Policy>::
deallocate(owned_block&& b, size_type a)
noexcept
{
	assert(b.is_aligned_to(a));
	_alloc.deallocate(std::move(b));
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
std::size_t
stack_aligned_byte_allocator<Policy>::
_own_end_misalign(_this_class* p) const
noexcept
{
	std::uintptr_t e =
		reinterpret_cast<std::uintptr_t>(p)+
		sizeof(_this_class);

	return (_align - (e % _align)) % _align;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
byte_allocator*
stack_aligned_byte_allocator<Policy>::
accomodate_self(void)
noexcept
{
	auto* ba = this->accomodate_derived(*this);

	if(std::size_t m = _own_end_misalign(ba))
	{
		this->release_block(ba->_alloc.allocate(m));
	}

	return ba;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline
void
stack_aligned_byte_allocator<Policy>::
eject_self(void)
noexcept
{
	if(std::size_t m = _own_end_misalign(this))
	{
		byte* p = reinterpret_cast<byte*>(this);
		p += sizeof(_this_class);

		_alloc.deallocate(this->acquire_block({p, m}));
	}

	this->eject_derived(*this);
}
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine
