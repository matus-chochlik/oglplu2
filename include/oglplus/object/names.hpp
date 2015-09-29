/**
 *  @file oglplus/object/names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_NAMES_1509260923_HPP
#define OGLPLUS_OBJECT_NAMES_1509260923_HPP

#include <array>
#include <algorithm>
#include "name.hpp"

namespace oglplus {

template <typename ObjTag, typename Iterator>
class object_name_const_iterator
{
private:
	Iterator _iter;
	object_name<ObjTag> _name;
public:
	object_name_const_iterator(void) = default;

	object_name_const_iterator(Iterator iter)
	noexcept
	 : _iter(iter)
	{ }

	typedef object_name<ObjTag> value_type;
	typedef const object_name<ObjTag>& reference;

	void swap(object_name_const_iterator& that)
	noexcept
	{
		using std::swap;
		swap(_iter, that._iter);
		swap(_name, that._name);
	}

	object_name_const_iterator&
	operator ++ (void)
	{
		++_iter;
		return *this;
	}

	reference operator * (void)
	{
		_name = object_name<ObjTag>(*_iter);
		return _name;
	}

	friend inline
	bool operator == (
		const object_name_const_iterator& a,
		const object_name_const_iterator& b
	) noexcept
	{
		return a._iter == b._iter;
	}

	friend inline
	bool operator != (
		const object_name_const_iterator& a,
		const object_name_const_iterator& b
	) noexcept
	{
		return a._iter != b._iter;
	}

	friend inline
	bool operator <  (
		const object_name_const_iterator& a,
		const object_name_const_iterator& b
	) noexcept
	{
		return a._iter <  b._iter;
	}
};

template <typename ObjTag, typename Container>
class object_name_container
{
private:
	typedef object_traits<ObjTag> _traits;
	Container _names;

	static
	void _invalidate_names(Container& names)
	{
		using std::fill;
		using std::begin;
		using std::end;
		fill(begin(names), end(names), _traits::invalid_name());
	}

	auto _release_names(void)
	noexcept
	{
		Container names = std::move(_names);
		_invalidate_names(_names);
		return names;
	}
public:
	object_name_container(void)
	noexcept
	{
		_invalidate_names(_names);
	}

	object_name_container(const object_name_container&) = default;
	object_name_container& operator = (const object_name_container&) = default;

	object_name_container(object_name_container&& temp)
	noexcept
	 : _names(temp._release_names())
	{ }

	object_name_container& operator = (object_name_container&& temp)
	noexcept
	{
		swap(temp, *this);
		return *this;
	}

	void swap(object_name_container& that)
	noexcept
	{
		std::swap(this->_names, that._names);
	}

	bool empty(void) const
	noexcept
	{
		return _names.empty();
	}

	std::size_t size(void) const
	noexcept
	{
		return _names.size();
	}

	object_name<ObjTag>
	operator [](std::size_t index) const
	noexcept
	{
		return object_name<ObjTag>(_names[index]);
	}

	object_name<ObjTag> at(std::size_t index) const
	noexcept
	{
		return object_name<ObjTag>(_names.at(index));
	}

	typedef object_name_const_iterator<
		ObjTag,
		typename Container::const_iterator
	> iterator;

	iterator begin(void) const
	noexcept
	{
		return _names.begin();
	}

	iterator end(void) const
	noexcept
	{
		return _names.end();
	}

	friend inline constexpr
	array_view<typename _traits::name_type>
	get_raw_names(object_name_container& ntr)
	noexcept
	{
		return {ntr._names.data(), ntr._names.size()};
	}
};

template <typename ObjTag, std::size_t N>
class object_names<
	ObjTag,
	std::array<typename object_traits<ObjTag>::name_type, N>
> : public object_name_container<
	ObjTag,
	std::array<typename object_traits<ObjTag>::name_type, N>
>
{
public:
	using object_name_container<
		ObjTag,
		std::array<typename object_traits<ObjTag>::name_type, N>
	>::object_name_container;
};

template <typename ObjTag, std::size_t N>
using object_name_array = object_names<
	ObjTag,
	std::array<typename object_traits<ObjTag>::name_type, N>
>;

} // namespace oglplus

#endif // include guard
