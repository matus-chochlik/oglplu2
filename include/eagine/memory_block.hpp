/**
 *  @file eagine/memory_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BLOCK_1509260923_HPP
#define EAGINE_MEMORY_BLOCK_1509260923_HPP

#include "types.hpp"
#include <type_traits>
#include <cstdint>

namespace eagine {

template <bool is_const>
class basic_memory_block
{
public:
	typedef typename std::conditional<
		is_const,
		const void*,
		void*
	>::type pointer;

	typedef typename std::conditional<
		is_const,
		const byte*,
		byte*
	>::type iterator;

	typedef std::size_t size_type;
private:
	pointer _addr;
	size_type _size;
public:
	template <typename T>
	explicit
	basic_memory_block(T& v)
	noexcept
	 : _addr(static_cast<pointer>(&v))
	 , _size(sizeof(T))
	{ }

	template <typename T, std::size_t N>
	explicit
	basic_memory_block(T (&a)[N])
	noexcept
	 : _addr(static_cast<pointer>(a))
	 , _size(sizeof(T)*N)
	{ }

	template <typename T>
	basic_memory_block(T *a, std::size_t count)
	noexcept
	 : _addr(static_cast<pointer>(a))
	 , _size(sizeof(T)*count)
	{ }

	basic_memory_block(pointer addr_, size_type size_)
	noexcept
	 : _addr(addr_)
	 , _size(size_)
	{ }

	constexpr
	basic_memory_block(void)
	noexcept
	 : _addr(nullptr)
	 , _size(0)
	{ }

	basic_memory_block(const basic_memory_block&) = default;
	basic_memory_block& operator = (const basic_memory_block&) = default;
	basic_memory_block(basic_memory_block&&) = default;
	basic_memory_block& operator = (basic_memory_block&&) = default;

	constexpr
	basic_memory_block(basic_memory_block<false> b)
	noexcept
	 : _addr(b.addr())
	 , _size(b.size())
	{ }

	pointer addr(void) const
	noexcept
	{
		return _addr;
	}

	iterator data(void) const
	noexcept
	{
		return static_cast<iterator>(addr());
	}

	size_type size(void) const
	noexcept
	{
		return _size;
	}

	bool empty(void) const
	noexcept
	{
		return !(size() > 0);
	}

	iterator begin(void) const
	noexcept
	{
		return data();
	}

	iterator end(void) const
	noexcept
	{
		return data()+size();
	}
};

typedef basic_memory_block<false> memory_block;
typedef basic_memory_block<true> const_memory_block;

class owned_memory_block
 : public memory_block
{
private:
	owned_memory_block(void* addr_, std::size_t size_)
	noexcept
	 : memory_block(addr_, size_)
	{ }
public:
	owned_memory_block(void) = default;
	owned_memory_block(owned_memory_block&&) = default;
	owned_memory_block& operator = (owned_memory_block&&) = default;
	owned_memory_block(const owned_memory_block&) = delete;
	owned_memory_block& operator = (const owned_memory_block&) = delete;
};

} // namespace eagine

#endif // include guard
