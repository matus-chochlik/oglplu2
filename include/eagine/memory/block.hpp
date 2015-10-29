/**
 *  @file eagine/memory/block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BLOCK_1510290655_HPP
#define EAGINE_MEMORY_BLOCK_1510290655_HPP

#include "../types.hpp"
#include <type_traits>
#include <cstdint>

namespace eagine {
namespace memory {

template <bool is_const>
class basic_block
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
	template <
		typename T,
		typename = typename std::enable_if<
			!std::is_same<T, basic_block>::value
		>::type
	>
	explicit
	basic_block(T& v)
	noexcept
	 : _addr(static_cast<pointer>(&v))
	 , _size(sizeof(T))
	{ }

	template <typename T, std::size_t N>
	explicit
	basic_block(T (&a)[N])
	noexcept
	 : _addr(static_cast<pointer>(a))
	 , _size(sizeof(T)*N)
	{ }

	template <typename T>
	basic_block(T *a, std::size_t count)
	noexcept
	 : _addr(static_cast<pointer>(a))
	 , _size(sizeof(T)*count)
	{ }

	basic_block(pointer addr_, size_type size_)
	noexcept
	 : _addr(addr_)
	 , _size(size_)
	{ }

	constexpr
	basic_block(void)
	noexcept
	 : _addr(nullptr)
	 , _size(0)
	{ }

	basic_block(const basic_block&) = default;
	basic_block& operator = (const basic_block&) = default;

	basic_block(basic_block&& temp)
	noexcept
	 : _addr(temp._addr)
	 , _size(temp._size)
	{
		temp.clear();
	}

	basic_block& operator = (basic_block&& temp)
	noexcept
	{
		using std::swap;
		swap(_addr, temp._addr);
		swap(_size, temp._size);
		return *this;
	}

	constexpr
	basic_block(basic_block<false> b)
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

	void clear(void)
	noexcept
	{
		_addr = nullptr;
		_size = 0;
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

	friend
	bool operator == (const basic_block& a, const basic_block& b)
	noexcept
	{
		return (a._addr == b._addr) && (a._size == b._size);
	}

	friend
	bool operator != (const basic_block& a, const basic_block& b)
	noexcept
	{
		return (a._addr != b._addr) || (a._size != b._size);
	}
};

typedef basic_block<false> block;
typedef basic_block<true> const_block;

class block_owner;

class owned_block
 : public block
{
private:
	friend class block_owner;

	owned_block(block b)
	noexcept
	 : block(b)
	{ }

protected:
	using block::clear;

public:
	owned_block(void) = default;
	owned_block(owned_block&&) = default;
	owned_block& operator = (owned_block&&) = default;
	owned_block(const owned_block&) = delete;
	owned_block& operator = (const owned_block&) = delete;

	~owned_block(void)
	noexcept
	{
		assert(empty());
	}
};

class block_owner
{
protected:
	static inline
	owned_block
	acquire_block(block b)
	noexcept
	{
		return {b};
	}

	static inline
	void
	release_block(owned_block&& b)
	noexcept
	{
		b.clear();
	}
};

} // namespace memory
} // namespace eagine

#endif // include guard
