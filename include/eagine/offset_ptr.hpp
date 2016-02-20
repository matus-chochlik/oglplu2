/**
 *  @file eagine/offset_ptr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OFFSET_PTR_1509260923_HPP
#define EAGINE_OFFSET_PTR_1509260923_HPP

#include "types.hpp"
#include "memory/address.hpp"
#include <cassert>

namespace eagine {

// basic_offset_ptr
template <typename T, typename OffsT>
class basic_offset_ptr
{
private:
	static_assert(std::is_signed<OffsT>::value, "");

	OffsT _offs;
	typedef memory::basic_address<std::is_const<T>::value> _memaddr;

	template <typename T1, typename T2>
	static
	OffsT _get_offs(T1* p1, T2* p2)
	noexcept
	{
		return memory::as_address(p1) - memory::as_address(p2);
	}
public:
	constexpr inline
	basic_offset_ptr(void)
	noexcept
	 : _offs(0)
	{ }

	explicit constexpr inline
	basic_offset_ptr(OffsT offs)
	noexcept
	 : _offs(offs)
	{ }

	basic_offset_ptr(T* ptr)
	noexcept
	 : _offs(_get_offs(ptr, this))
	{ }

	basic_offset_ptr(const basic_offset_ptr& that)
	noexcept
	 : _offs(that._offs + _get_offs(&that,this))
	{ }

	basic_offset_ptr& operator = (const basic_offset_ptr& that)
	{
		_offs = that._offs + _get_offs(&that,this);
		return *this;
	}

	constexpr inline
	bool is_null(void) const
	noexcept
	{
		return _offs == OffsT(0);
	}

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return !is_null();
	}

	constexpr inline
	bool operator !(void) const
	noexcept
	{
		return is_null();
	}

	memory::basic_address<std::is_const<T>::value>
	address(void) const
	noexcept
	{
		return is_null()?_memaddr():_memaddr(this, _offs);
	}

	inline
	T* addr(void) const
	noexcept
	{
		return static_cast<T*>(address());
	}

	inline
	T* get(void) const
	noexcept
	{
		return addr();
	}

	inline
	operator T* (void) const
	noexcept
	{
		return get();
	}

	const T& operator * (void) const
	noexcept
	{
		assert(!is_null());
		return *addr();
	}

	const T* operator -> (void) const
	noexcept
	{
		assert(!is_null());
		return addr();
	}
};

template <typename T>
using offset_ptr = basic_offset_ptr<T, std::ptrdiff_t>;

template <typename T>
using short_offset_ptr = basic_offset_ptr<T, short>;

// basic_offset_array
template <typename T, typename OffsT>
class basic_offset_array
{
public:
	typedef T value_type;
	typedef std::size_t size_type;
private:
	size_type _size;
	basic_offset_ptr<T, OffsT> _addr;
public:
	constexpr inline
	basic_offset_array(void)
	noexcept
	 : _size(0)
	 , _addr()
	{ }

	constexpr inline
	basic_offset_array(OffsT offs, size_type len)
	noexcept
	 : _size(len)
	 , _addr(offs)
	{ }

	basic_offset_array(T* ptr, size_type len)
	noexcept
	 : _size(len)
	 , _addr(ptr)
	{ }

	constexpr inline
	size_type size(void) const
	noexcept
	{
		return _size;
	}

	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef const T& const_reference;

	iterator addr(void)
	noexcept
	{
		return _addr.addr();
	}

	iterator begin(void)
	noexcept
	{
		return addr();
	}

	iterator end(void)
	noexcept
	{
		return begin()+size();
	}

	const_iterator addr(void) const
	noexcept
	{
		return _addr.addr();
	}

	const_iterator begin(void) const
	noexcept
	{
		return addr();
	}

	const_iterator end(void) const
	noexcept
	{
		return begin()+size();
	}

	reference operator [] (size_type index)
	noexcept
	{
		assert(index >= size_type(0) && index < size());
		return begin()[index];
	}

	const_reference operator [] (size_type index) const
	noexcept
	{
		assert(index >= size_type(0) && index < size());
		return begin()[index];
	}
};

template <typename T>
using offset_array = basic_offset_array<T, std::ptrdiff_t>;

template <typename T>
using short_offset_array = basic_offset_array<T, short>;

} // namespace eagine

#endif // include guard
