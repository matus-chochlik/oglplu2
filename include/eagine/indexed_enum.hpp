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

template <typename T, unsigned LibId>
struct any_indexed_enum_value;

template <typename T, T Base, unsigned LibId>
struct indexed_enum_value
{
	typedef T value_type;

	unsigned _offset;

	indexed_enum_value(void) = default;

	constexpr inline
	indexed_enum_value(indexed_enum_base<T, Base, LibId>)
	noexcept
	 : _offset(0u)
	{ }

	explicit constexpr inline
	indexed_enum_value(unsigned offset)
	noexcept
	 : _offset(offset)
	{ }

	constexpr
	indexed_enum_value(const any_indexed_enum_value<T, LibId>& aiev)
	noexcept
	 : _offset(aiev._offset)
	{
		assert(aiev._base_id == Base);
	}

	explicit constexpr inline
	operator value_type (void) const
	noexcept
	{
		return value_type(Base+_offset);
	}

	friend constexpr inline
	bool operator == (indexed_enum_value a, indexed_enum_value b)
	noexcept
	{
		return a._offset == b._offset;
	}

	friend constexpr inline
	bool operator != (indexed_enum_value a, indexed_enum_value b)
	noexcept
	{
		return a._offset != b._offset;
	}

	friend constexpr inline
	bool operator < (indexed_enum_value a, indexed_enum_value b)
	noexcept
	{
		return a._offset < b._offset;
	}

	static constexpr inline
	T base(void)
	noexcept
	{
		return Base;
	}

	constexpr inline
	unsigned offset(void) const
	noexcept
	{
		return _offset;
	}
};

template <typename T, T Base, unsigned LibId>
static inline
indexed_enum_value<T, Base, LibId>
operator + (indexed_enum_base<T, Base, LibId>, unsigned offset)
noexcept
{
	return indexed_enum_value<T, Base, LibId>{offset};
}

template <typename T, unsigned LibId>
struct any_indexed_enum_value
{
	unsigned _offset;
	T _base_id;

	constexpr inline
	any_indexed_enum_value(void)
	noexcept
	 : _offset(0u)
	 , _base_id(~T(0))
	{ }

	template <T Base>
	constexpr inline
	any_indexed_enum_value(indexed_enum_value<T, Base, LibId> iec)
	noexcept
	 : _offset(iec._offset)
	 , _base_id(Base)
	{ }

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return _base_id != ~T(0);
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return _base_id == ~T(0);
	}

	friend constexpr inline
	bool operator == (any_indexed_enum_value a, any_indexed_enum_value b)
	noexcept
	{
		return (a._offset == b._offset) && (a._base_id == b._base_id);
	}

	friend constexpr inline
	bool operator != (any_indexed_enum_value a, any_indexed_enum_value b)
	noexcept
	{
		return (a._offset != b._offset) || (a._base_id |= b._base_id);
	}

	constexpr inline
	T base(void) const
	noexcept
	{
		return _base_id;
	}

	constexpr inline
	unsigned offset(void) const
	noexcept
	{
		return _offset;
	}
};

template <typename T, unsigned LibId>
static constexpr inline
bool same_enum_class(
	any_indexed_enum_value<T, LibId> a,
	any_indexed_enum_value<T, LibId> b
) noexcept
{
	return a._base_id == b._base_id;
}

} // namespace eagine

#endif // include guard
