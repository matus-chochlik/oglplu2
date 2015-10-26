/**
 *  @file eagine/utils/iterator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UTILS_ITERATOR_1509260923_HPP
#define EAGINE_UTILS_ITERATOR_1509260923_HPP

#include <iterator>

namespace eagine {

template <typename T, typename Derived>
class basic_iterable_type
{
protected:
	T _value;

	Derived& self(void)
	noexcept
	{
		return *static_cast<Derived*>(this);
	}
public:
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;

	basic_iterable_type(void) = default;

	constexpr
	basic_iterable_type(T value)
	noexcept
	 : _value(value)
	{ }

	explicit constexpr
	operator T (void) const
	noexcept
	{
		return _value;
	}

	Derived& operator ++ (void)
	noexcept
	{
		++_value;
		return self();
	}

	Derived& operator += (difference_type d)
	noexcept
	{
		_value += d;
		return self();
	}

	Derived operator ++ (int)
	noexcept
	{
		Derived res(self());
		++_value;
		return res;
	}

	friend
	Derived operator + (basic_iterable_type a, difference_type d)
	noexcept
	{
		Derived res(a.self());
		res += d;
		return res;
	}

	Derived& operator -- (void)
	noexcept
	{
		--_value;
		return self();
	}

	Derived& operator -= (difference_type d)
	noexcept
	{
		_value -= d;
		return self();
	}

	Derived operator -- (int)
	noexcept
	{
		Derived res(self());
		--_value;
		return res;
	}

	friend
	Derived operator - (basic_iterable_type a, difference_type d)
	noexcept
	{
		Derived res(a.self());
		res -= d;
		return res;
	}

	constexpr friend
	difference_type
	operator - (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value - b._value;
	}

	constexpr friend
	bool operator == (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value == b._value;
	}

	constexpr friend
	bool operator != (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value != b._value;
	}

	constexpr friend
	bool operator <  (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value <  b._value;
	}

	constexpr friend
	bool operator <= (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value <= b._value;
	}

	constexpr friend
	bool operator >  (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value >  b._value;
	}

	constexpr friend
	bool operator >= (basic_iterable_type a, basic_iterable_type b)
	noexcept
	{
		return a._value >= b._value;
	}
};

template <typename T, typename Derived>
class basic_selfref_iterator
 : public basic_iterable_type<T, Derived>
{
public:
	typedef const T& reference;
	typedef const T* pointer;
	typedef std::random_access_iterator_tag iterator_category;

	using basic_iterable_type<T, Derived>::basic_iterable_type;

	const T& operator * (void) const
	noexcept
	{
		return this->_value;
	}
};

template <typename T>
struct selfref_iterator
 : basic_selfref_iterator<T, selfref_iterator<T>>
{
	using basic_selfref_iterator<T, selfref_iterator<T>>::
		basic_selfref_iterator;
};

template <typename Iterator, typename T, typename Transform, typename Derived>
class basic_transforming_iterator
 : public basic_selfref_iterator<Iterator, Derived>
{
private:
	typedef basic_selfref_iterator<Iterator, Derived> _base;
	Transform _transf;
	mutable T _tempval;
public:
	basic_transforming_iterator(void) = default;

	basic_transforming_iterator(Iterator&& iter, Transform&& transf)
	 : _base(std::move(iter))
	 , _transf(std::move(transf))
	 , _tempval()
	{ }

	typedef T value_type;
	typedef const T& reference;
	typedef const T* pointer;

	const T& operator * (void) const
	{
		_tempval = _transf(_base::operator*().operator*());
		return _tempval;
	}
};

template <typename Iterator, typename T, typename Transform>
struct transforming_iterator
 : basic_transforming_iterator<
	Iterator,
	T, Transform,
	transforming_iterator<Iterator, T, Transform>
>
{
	using basic_transforming_iterator<
		Iterator,
		T, Transform,
		transforming_iterator<Iterator, T, Transform>
	>::basic_transforming_iterator;
};

} // namespace eagine

#endif // include guard
