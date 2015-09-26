/**
 *  @file oglplus/object/name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_NAME_1509260923_HPP
#define OGLPLUS_OBJECT_NAME_1509260923_HPP

#include <utility>
#include <cstddef>
#include "fwd.hpp"

namespace oglplus {

template <typename ObjTag>
class object_names<ObjTag, typename object_traits<ObjTag>::name_type>
{
private:
	typedef object_traits<ObjTag> _traits;
	typename _traits::name_type _name;

	typename _traits::name_type
	_release_name(void)
	noexcept
	{
		auto name = _name;
		_name = _traits::invalid_name();
		return name;
	}
public:
	constexpr
	object_names(void)
	noexcept
	 : _name(_traits::invalid_name())
	{ }

	object_names(const object_names&) = default;
	object_names& operator = (const object_names&) = default;

	object_names(object_names&& temp)
	noexcept
	 : _name(temp._release_name())
	{ }

	object_names& operator = (object_names&& temp)
	noexcept
	{
		swap(temp, *this);
		return *this;
	}

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return _name != _traits::invalid_name();
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return _name == _traits::invalid_name();
	}

	friend constexpr inline
	bool operator == (object_names a, object_names b)
	noexcept
	{
		return a._name == b._name;
	}

	friend constexpr inline
	bool operator != (object_names a, object_names b)
	noexcept
	{
		return a._name != b._name;
	}

	friend constexpr inline
	bool operator <  (object_names a, object_names b)
	noexcept
	{
		return a._name <  b._name;
	}

	friend constexpr inline
	bool operator >  (object_names a, object_names b)
	noexcept
	{
		return a._name >  b._name;
	}

	friend constexpr inline
	bool operator <= (object_names a, object_names b)
	noexcept
	{
		return a._name <= b._name;
	}

	friend constexpr inline
	bool operator >= (object_names a, object_names b)
	noexcept
	{
		return a._name >= b._name;
	}

	void swap(object_names& that)
	noexcept
	{
		std::swap(this->_name, that._name);
	}

	friend inline constexpr
	typename _traits::name_type
	get_name(object_names nt)
	noexcept
	{
		return nt._name;
	}

	friend inline constexpr
	typename _traits::name_type*
	get_name_pointer(object_names& ntr)
	noexcept
	{
		return &ntr._name;
	}

	friend inline constexpr
	std::size_t get_name_count(object_names)
	noexcept
	{
		return 1;
	}
};

} // namespace oglplus

#endif // include guard
