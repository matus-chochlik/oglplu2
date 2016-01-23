/**
 *  @file eagine/deep_copy_ptr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_DEEP_COPY_PTR_1509260923_HPP
#define EAGINE_DEEP_COPY_PTR_1509260923_HPP

#include <memory>
#include "type_traits.hpp"

namespace eagine {

template <typename T>
static inline
std::unique_ptr<T>
make_deep_ptr_copy(const std::unique_ptr<T>& that, std::true_type)
{
	return that?that->copy():std::unique_ptr<T>();
}

template <typename T>
static inline
std::unique_ptr<T>
make_deep_ptr_copy(const std::unique_ptr<T>& that, std::false_type)
{
	return std::unique_ptr<T>(that?new T(*that):nullptr);
}

template <typename T>
static inline
std::unique_ptr<T>
make_deep_ptr_copy(const std::unique_ptr<T>& that)
{
	return make_deep_ptr_copy(that, std::is_polymorphic_t<T>());
}

template <typename T>
class deep_copy_ptr
 : public std::unique_ptr<T>
{
private:
	typedef std::unique_ptr<T> _base;
	_base& _self(void) noexcept { return *this; }
public:
	deep_copy_ptr(void) = default;
	deep_copy_ptr(deep_copy_ptr&&) = default;
	deep_copy_ptr& operator = (deep_copy_ptr&&) = default;

	deep_copy_ptr(std::unique_ptr<T>&& temp)
	 : _base(std::move(temp))
	{ }

	deep_copy_ptr(const std::unique_ptr<T>& that)
	 : _base(make_deep_ptr_copy(that))
	{ }

	deep_copy_ptr(const deep_copy_ptr& that)
	 : _base(make_deep_ptr_copy(that))
	{ }

	template <
		typename D,
		typename = std::enable_if_t<std::is_base_of<T, D>::value>
	>
	deep_copy_ptr(deep_copy_ptr<D>&& that)
	 : _base(std::move(that))
	{ }

	template <
		typename D,
		typename = std::enable_if_t<std::is_base_of<T, D>::value>
	>
	deep_copy_ptr(const deep_copy_ptr<D>& that)
	 : _base(make_deep_ptr_copy(that))
	{ }

	deep_copy_ptr& operator = (const deep_copy_ptr& that)
	{
		_self() = make_deep_ptr_copy(that);
		return *this;
	}
};

template <typename T, typename ... P>
static inline
deep_copy_ptr<T> make_deep_copy_ptr(P&& ... p)
{
	return std::unique_ptr<T>(new T(std::forward<P>(p)...));
}

} // namespace eagine

#endif // include guard
