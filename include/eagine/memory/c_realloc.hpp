/**
 *  @file eagine/memory/c_realloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_C_REALLOC_1509260923_HPP
#define EAGINE_MEMORY_C_REALLOC_1509260923_HPP

#include "byte_alloc.hpp"
#include <cassert>

namespace eagine {
namespace memory {

// c_byte_reallocator
template <typename Policy = default_byte_allocator_policy>
class c_byte_reallocator
 : public byte_allocator_impl<Policy, c_byte_reallocator>
{
public:
	typedef std::size_t size_type;

	bool equal(byte_allocator* a) const
	noexcept override
	{
		return dynamic_cast<c_byte_reallocator*>(a) != nullptr;
	}

	size_type max_size(size_type)
	noexcept
	override
	{
		return std::numeric_limits<size_type>::max();
	}

	tribool has_allocated(const owned_block&, size_type)
	noexcept
	override
	{
		return indeterminate;
	}

	owned_block allocate(size_type n, size_type a)
	noexcept
	override
	{
		assert(a > 0);

		if(n == 0)
		{
			return {};
		}

		void* p = std::malloc(n);

		// TODO fix if misaligned ?
		assert((reinterpret_cast<std::uintptr_t>(p) % a) == 0);

		return this->acquire_block({p, n});
	}

	void deallocate(owned_block&& b, size_type)
	noexcept
	override
	{
		if(!b.empty())
		{
			std::free(b.addr());
			this->release_block(std::move(b));
		}
	}

	bool can_reallocate(const owned_block&, size_type, size_type)
	noexcept
	override
	{
		return true;
	}

	owned_block reallocate(owned_block&& b, size_type n, size_type a)
	noexcept
	override
	{
		assert(a > 0);

		if(n == 0)
		{
			deallocate(std::move(b), a);
			return {};
		}

		void* p = std::realloc(b.addr(), n);

		this->release_block(std::move(b));

		// TODO fix if misaligned ?
		assert((reinterpret_cast<std::uintptr_t>(p) % a) == 0);

		return this->acquire_block({p, n});
	}
};

} // namespace memory
} // namespace eagine

#endif //include guard

