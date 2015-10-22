/**
 *  @file eagine/indexed_enum.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INDEXED_ENUM_1509260923_HPP
#define EAGINE_INDEXED_ENUM_1509260923_HPP

namespace eagine {

template <typename T, T Base, unsigned LibId>
struct indexed_enum_base
{ };

template <typename T, T Base, unsigned LibId>
struct indexed_enum_class
{
	typedef T value_type;

	unsigned _offset;

	constexpr inline
	indexed_enum_class(indexed_enum_base<T, Base, LibId>)
	noexcept
	 : _offset(0u)
	{ }

	explicit constexpr inline
	indexed_enum_class(unsigned offset)
	noexcept
	 : _offset(offset)
	{ }

	explicit constexpr inline
	operator value_type (void) const
	noexcept
	{
		return value_type(Base+_offset);
	}

	friend constexpr inline
	bool operator == (indexed_enum_class a, indexed_enum_class b)
	noexcept
	{
		return a._offset == b._offset;
	}

	friend constexpr inline
	bool operator != (indexed_enum_class a, indexed_enum_class b)
	noexcept
	{
		return a._offset != b._offset;
	}

	friend constexpr inline
	bool operator < (indexed_enum_class a, indexed_enum_class b)
	noexcept
	{
		return a._offset < b._offset;
	}
};

template <typename T, T Base, unsigned LibId>
static inline
indexed_enum_class<T, Base, LibId>
operator + (indexed_enum_base<T, Base, LibId>, unsigned offset)
noexcept
{
	return indexed_enum_class<T, Base, LibId>{offset};
}

} // namespace eagine

#endif // include guard
