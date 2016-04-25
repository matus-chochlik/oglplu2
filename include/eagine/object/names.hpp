/**
 *  @file eagine/object/names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_NAMES_1509260923_HPP
#define EAGINE_OBJECT_NAMES_1509260923_HPP

#include "name.hpp"
#include "../types.hpp"
#include "../iterator.hpp"
#include <array>
#include <vector>
#include <algorithm>
#include <cassert>

namespace eagine {

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
	typename _traits::name_type
	get_raw_name(const object_name_container& ctr)
	noexcept
	{
		assert(ctr._names.size() > 0);
		return *ctr._names.data();
	}

	friend inline
	span<typename _traits::name_type>
	get_raw_names(object_name_container& ctr)
	noexcept
	{
		return {ctr._names};
	}
};

template <typename NameT>
class object_name_base_and_count_view
{
private:
	NameT* _pbase;
	std::size_t _size;
public:
	constexpr
	object_name_base_and_count_view(NameT& base, std::size_t count)
	noexcept
	 : _pbase(&base)
	 , _size(count)
	{ }

	NameT base(void) const
	noexcept
	{
		assert(_pbase);
		return *_pbase;
	}

	void base(NameT name)
	noexcept
	{
		assert(_pbase);
		*_pbase = name;
	}

	std::size_t size(void) const
	noexcept
	{
		return _size;
	}
};

template <typename ObjTag>
class object_name_fake_array
{
private:
	typedef object_traits<ObjTag> _traits;
	typedef object_name_t<ObjTag> _name_type;

	_name_type _base;
	std::size_t _size;
public:
	constexpr
	object_name_fake_array(void)
	noexcept
	 : _base(_traits::invalid_name())
	 , _size(0)
	{ }

	constexpr
	object_name_fake_array(std::size_t count)
	noexcept
	 : _base(_traits::invalid_name())
	 , _size(count)
	{ }

	void swap(object_name_fake_array& that)
	noexcept
	{
		std::swap(this->_base, that._base);
		std::swap(this->_size, that._size);
	}

	bool empty(void) const
	noexcept
	{
		return !(_size > 0);
	}

	std::size_t size(void) const
	noexcept
	{
		return _size;
	}

	object_name<ObjTag>
	operator [](std::size_t index) const
	noexcept
	{
		assert(index < size());
		return object_name<ObjTag>(_name_type(_base+index));
	}

	object_name<ObjTag> at(std::size_t index) const
	noexcept
	{
		if(!(index < size()))
		{
			throw std::out_of_range(
			"Index exceeds object_name_fake_array bounds."
			);
		}
		return object_name<ObjTag>(_name_type(_base+index));
	}

	typedef noexcept_casting_iterator<
		selfref_iterator<_name_type>,
		const object_name<ObjTag>, object_name<ObjTag>
	> iterator;

	iterator begin(void) const
	noexcept
	{
		return iterator(_base);
	}

	iterator end(void) const
	noexcept
	{
		return iterator(_name_type(_base+_size));
	}

	friend inline constexpr
	typename _traits::name_type
	get_raw_name(const object_name_fake_array& onfa)
	noexcept
	{
		assert(onfa.size() > 0);
		return onfa._base;
	}

	friend inline
	object_name_base_and_count_view<_name_type>
	get_raw_names(object_name_fake_array& onfa)
	noexcept
	{
		return {onfa._base, onfa._size};
	}
};

template <typename ObjTag, std::size_t N>
class object_names<
	ObjTag,
	std::array<object_name_t<ObjTag>, N>
> : public object_name_container<
	ObjTag,
	std::array<object_name_t<ObjTag>, N>
>
{
public:
	using object_name_container<
		ObjTag,
		std::array<object_name_t<ObjTag>, N>
	>::object_name_container;
};

template <typename ObjTag, std::size_t N>
using object_name_array = object_names<
	ObjTag,
	std::array<object_name_t<ObjTag>, N>
>;

template <typename ObjTag>
using object_name_vector = object_names<
	ObjTag,
	std::vector<object_name_t<ObjTag>>
>;

} // namespace eagine

#endif // include guard
