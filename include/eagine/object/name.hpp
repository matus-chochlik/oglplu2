/**
 *  @file eagine/object/name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_NAME_1509260923_HPP
#define EAGINE_OBJECT_NAME_1509260923_HPP

#include <utility>
#include <cstddef>
#include "fwd.hpp"
#include "../array_view.hpp"

namespace eagine {

template <typename ObjTag>
class object_names<ObjTag, typename object_traits<ObjTag>::name_type>
{
private:
	typedef object_traits<ObjTag> _traits;
	typedef typename _traits::name_type _name_type;
	_name_type _name;

	_name_type _release_name(void)
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

	explicit constexpr
	object_names(_name_type name)
	noexcept
	 : _name(name)
	{ }

	template <typename TypeT, _name_type In, TypeT It>
	explicit constexpr
	object_names(const any_object_name<_name_type, TypeT, In, It>& name)
	noexcept
	 : _name(name._name)
	{
		assert(name._type == _traits::get_type());
	}

	object_names(const object_names&) = default;
	object_names& operator = (const object_names&) = default;

	object_names(object_names&& temp)
	noexcept
	 : _name(temp._release_name())
	{ }

	object_names& operator = (object_names&& temp)
	noexcept
	{
		swap(temp);
		return *this;
	}

	constexpr inline
	bool is_valid(void) const
	noexcept
	{
		return _name != _traits::invalid_name();
	}

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
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
	_name_type
	get_raw_name(object_names nt)
	noexcept
	{
		return nt._name;
	}

	friend inline constexpr
	array_view<_name_type>
	get_raw_names(object_names& ntr)
	noexcept
	{
		return {&ntr._name, 1};
	}
};

template <typename ObjTag>
class object_zero
 : public object_name<ObjTag>
{
public:
	constexpr inline
	object_zero(void)
	noexcept
	 : object_name<ObjTag>(0)
	{ }
};

template <typename NameT, typename TypeT, NameT InvalidName, TypeT InvalidType>
struct any_object_name
{
	NameT _name;
	TypeT _type;

	constexpr inline
	any_object_name(void)
	noexcept
	 : _name(InvalidName)
	 , _type(InvalidType)
	{ }

	template <typename ObjTag>
	constexpr
	any_object_name(object_names<ObjTag, NameT> name)
	noexcept
	 : _name(get_raw_name(name))
	 , _type(object_traits<ObjTag>::get_type())
	{ }

	constexpr inline
	bool is_valid(void) const
	noexcept
	{
		return (_name != InvalidName) && (_type != InvalidType);
	}

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
	}

	friend constexpr inline
	bool operator == (const any_object_name& a, const any_object_name& b)
	noexcept
	{
		return (a._name == b._name) && (a._type == b._type);
	}

	friend constexpr inline
	bool operator != (const any_object_name& a, const any_object_name& b)
	noexcept
	{
		return (a._name != b._name) || (a._type != b._type);
	}
};

template <typename NameT, typename TypeT, NameT In, TypeT It>
static constexpr inline
bool same_object_type(
	const any_object_name<NameT, TypeT, In, It>& a,
	const any_object_name<NameT, TypeT, In, It>& b
) noexcept
{
	return a._type == b._type;
}

} // namespace eagine

#endif // include guard
