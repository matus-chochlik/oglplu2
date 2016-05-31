/**
 *  @file eagine/ecs/storage_caps.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_STORAGE_CAPS_1509260923_HPP
#define EAGINE_ECS_STORAGE_CAPS_1509260923_HPP

#include "../bitfield.hpp"

namespace eagine {
namespace ecs {

enum class storage_cap_bit
 : unsigned short
{
	hide   = 1 << 0,
	erase  = 1 << 1,
	store  = 1 << 2,
	modify = 1 << 3
};

static inline
bitfield<storage_cap_bit>
operator | (storage_cap_bit a, storage_cap_bit b)
noexcept
{
	return {a, b};
}

class storage_caps
 : public bitfield<storage_cap_bit>
{
private:
	typedef bitfield<storage_cap_bit> _base;
public:
	storage_caps(void) = default;

	storage_caps(bitfield<storage_cap_bit> base)
	 : _base(base)
	{ }

	bool can_hide(void) const
	noexcept
	{
		return has(storage_cap_bit::hide);
	}

	bool can_erase(void) const
	noexcept
	{
		return has(storage_cap_bit::erase);
	}

	bool can_store(void) const
	noexcept
	{
		return has(storage_cap_bit::store);
	}

	bool can_modify(void) const
	noexcept
	{
		return has(storage_cap_bit::modify);
	}
};

} // namespace ecs
} // namespace eagine

#endif //include guard

