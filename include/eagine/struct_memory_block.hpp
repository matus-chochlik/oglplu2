/**
 *  @file eagine/struct_memory_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRUCT_MEMORY_BLOCK_1509260923_HPP
#define EAGINE_STRUCT_MEMORY_BLOCK_1509260923_HPP

#include "memory_block.hpp"
#include "type_traits.hpp"

namespace eagine {

template <typename T>
class structured_memory_block
{
private:
	memory::basic_block<std::is_const<T>::value> _blk;

	template <
		typename X = T,
		typename = std::enable_if_t<!std::is_const<X>::value>
	>
	X* _ptr(void)
	noexcept
	{
		assert(valid_block(_blk));
		return static_cast<X*>(_blk.addr());
	}

	const T* _cptr(void) const
	noexcept
	{
		assert(valid_block(_blk));
		return static_cast<const T*>(_blk.addr());
	}
public:
	static
	bool valid_block(const_memory_block blk)
	noexcept
	{
		return (blk.data() != nullptr) &&
			(blk.addr().is_aligned_to(alignof(T))) &&
			(blk.size() >= sizeof(T));
	}

	structured_memory_block(
		memory::basic_block<std::is_const<T>::value> blk
	) noexcept
	 : _blk(blk)
	{
		assert(valid_block(_blk));
	}

	template <
		typename X = T,
		typename = std::enable_if_t<
			!std::is_const<X>::value &&
			std::is_same<X, T>::value
		>
	>
	X& get(void)
	noexcept
	{
		return *_ptr();
	}

	template <
		typename X = T,
		typename = std::enable_if_t<
			!std::is_const<X>::value &&
			std::is_same<X, T>::value
		>
	>
  	X* operator -> (void)
	noexcept
	{
		return _ptr();
	}

	const T& get(void) const
	noexcept
	{
		return *_cptr();
	}

	const T* operator -> (void) const
	noexcept
	{
		return _cptr();
	}
};

} // namespace eagine

#endif // include guard
