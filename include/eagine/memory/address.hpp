/**
 *  @file eagine/memory/address.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_ADDRESS_1510290655_HPP
#define EAGINE_MEMORY_ADDRESS_1510290655_HPP

#include "../types.hpp"
#include "../type_traits.hpp"
#include <cstddef>
#include <cassert>

namespace eagine {
namespace memory {

template <bool IsConst>
class basic_address
{
public:
	typedef std::conditional_t<
		IsConst,
		const void*,
		void*
	> pointer;

	typedef std::conditional_t<
		IsConst,
		const byte*,
		byte*
	> byte_pointer;
private:
	pointer _addr;
public:
	constexpr
	basic_address(void)
	noexcept
	 : _addr(nullptr)
	{ }

	constexpr
	basic_address(std::nullptr_t)
	noexcept
	 : _addr(nullptr)
	{ }

	basic_address(pointer addr)
	noexcept
	 : _addr(addr)
	{ }

	template <
		typename Int,
		typename = std::enable_if_t<
			std::is_integral<Int>::value &&
			std::is_convertible<Int, std::ptrdiff_t>::value
		>
	>
	basic_address(pointer addr, Int offs)
	noexcept
	 : _addr(static_cast<byte_pointer>(addr)+offs)
	{ }

	basic_address(const basic_address&) = default;
	basic_address& operator = (const basic_address&) = default;

	template <
		bool IsConst2,
		typename = std::enable_if_t<IsConst && !IsConst2>
	>
	basic_address(basic_address<IsConst2> a)
	noexcept
	 : _addr(pointer(a))
	{ }

	operator pointer (void) const
	noexcept
	{
		return _addr;
	}

	template <
		typename T,
		typename = std::enable_if_t<
			!std::is_void<T>::value && 
			(std::is_const<T>::value || !IsConst)
		>
	>
	explicit
	operator T* (void) const
	noexcept
	{
		assert(this->is_aligned_to(alignof(T)));
		return static_cast<T*>(_addr);
	}

	std::uintptr_t misalignment(std::uintptr_t alignment) const
	noexcept
	{
		return reinterpret_cast<std::uintptr_t>(_addr) % alignment;
	}

	bool is_aligned_to(std::uintptr_t alignment) const
	noexcept
	{
		return misalignment(alignment) == 0;
	}
};

typedef basic_address<true> const_address;
typedef basic_address<false> address;

static constexpr inline
std::uintptr_t misalignment(std::nullptr_t, std::uintptr_t)
noexcept
{
	return 0;
}

static inline
std::uintptr_t misalignment(const_address addr, std::uintptr_t alignment)
noexcept
{
	return addr.misalignment(alignment);
}

static constexpr inline
bool is_aligned_to(std::nullptr_t, std::uintptr_t)
noexcept
{
	return true;
}

static inline
bool is_aligned_to(const_address addr , std::uintptr_t alignment)
noexcept
{
	return addr.is_aligned_to(alignment);
}

template <bool IsConst>
static inline
basic_address<IsConst>
align_up(basic_address<IsConst> addr, std::uintptr_t align, std::size_t max)
noexcept
{
	std::uintptr_t ma = misalignment(addr, align);
	ma = (ma?align-ma:0);

	assert(ma <= max);
	return {addr, ma};
}

template <bool IsConst>
static inline
basic_address<IsConst>
align_down(basic_address<IsConst> addr, std::uintptr_t align, std::size_t max)
noexcept
{
	std::uintptr_t ma = misalignment(addr, align);

	assert(ma <= max);
	return {addr,-ma};
}

template <typename T>
static inline
T* align_up_to(
	basic_address<std::is_const<T>::value> addr,
	std::uintptr_t align = alignof(T),
	std::size_t max = sizeof(T)
) noexcept
{
	if(align < alignof(T)) { align = alignof(T); }

	return static_cast<T*>(align_up(addr, align, max));
}

template <typename T>
static inline
T* align_down_to(
	basic_address<std::is_const<T>::value> addr,
	std::uintptr_t align = alignof(T),
	std::size_t max = sizeof(T)
) noexcept
{
	if(align < alignof(T)) { align = alignof(T); }

	return static_cast<T*>(align_down(addr, align, max));
}

} // namespace memory
} // namespace eagine

#endif // include guard
