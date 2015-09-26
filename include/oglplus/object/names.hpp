/**
 *  @file oglplus/object/names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_NAMES_1509260923_HPP
#define OGLPLUS_OBJECT_NAMES_1509260923_HPP

#include <array>
#include "fwd.hpp"

namespace oglplus {

template <typename ObjTag, std::size_t N>
class object_names<
	ObjTag,
	std::array<typename object_traits<ObjTag>::name_type, N>
>
{
private:
	typedef object_traits<ObjTag> _traits;
	std::array<typename _traits::name_type, N> _names;

	auto
	_release_names(void)
	noexcept
	{
		auto names = _names;
		_names.fill(_traits::invalid_name());
		return names;
	}
public:
	object_names(void)
	noexcept
	{
		_names.fill(_traits::invalid_name());
	}

	object_names(const object_names&) = default;
	object_names& operator = (const object_names&) = default;

	object_names(object_names&& temp)
	noexcept
	 : _names(temp._release_names())
	{ }

	object_names& operator = (object_names&& temp)
	noexcept
	{
		swap(temp, *this);
		return *this;
	}

	void swap(object_names& that)
	noexcept
	{
		std::swap(this->_names, that._names);
	}

	friend inline constexpr
	typename _traits::name_type*
	get_name_pointer(object_names& ntr)
	noexcept
	{
		return ntr._names.data();
	}

	friend inline constexpr
	std::size_t get_name_count(object_names)
	noexcept
	{
		return N;
	}
};

} // namespace oglplus

#endif // include guard
