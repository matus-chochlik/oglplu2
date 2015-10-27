/**
 *  @file oglplus/enum/value_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_VALUE_RANGE_1509260923_HPP
#define OGLPLUS_ENUM_VALUE_RANGE_1509260923_HPP

#include "../utils/enum_class.hpp"
#include "../utils/array_view.hpp"
#include "../config/basic.hpp"

namespace oglplus {

std::pair<const void*, std::size_t>
get_enum_value_range(const any_enum_class&)
noexcept;

template <typename EnumClass>
class enumerated_value_range;

template <typename EnumClass, typename T, unsigned EnumId>
class enumerated_value_range<enum_class<EnumClass, T, EnumId>>
{
private:
	const GLenum* _begin;
	const GLenum* _end;

	typedef enum_class<EnumClass, T, EnumId> _ec_t;

	static
	_ec_t _wrap_enum(GLenum e)
	noexcept
	{
		return _ec_t{e};
	}

	explicit
	enumerated_value_range(array_view<const T> v)
	noexcept
	 : _begin(v.data())
	 , _end(v.data()+v.size())
	{ }

	explicit
	enumerated_value_range(std::pair<const void*, std::size_t> p)
	noexcept
	 : enumerated_value_range(
		array_view<const T>{static_cast<const T*>(p.first), p.second}
	)
	{ }
public:
	enumerated_value_range(void)
	noexcept
	 : enumerated_value_range(get_enum_value_range(_ec_t()))
	{ }

	typedef eagine::transforming_iterator<
		const GLenum*,
		_ec_t, _ec_t(*)(GLenum) noexcept
	> iterator;

	iterator begin(void) const
	noexcept
	{
		return iterator(_begin, &_wrap_enum);
	}

	iterator end(void) const
	noexcept
	{
		return iterator(_end, &_wrap_enum);
	}
};

template <
	typename EnumClass,
	typename = typename std::enable_if<
		is_enum_class<typename EnumClass::type>::value
	>::type
>
static inline
enumerated_value_range<typename EnumClass::type>
enum_value_range(void)
noexcept
{
	return {};
}

} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/enum/value_range.inl>
#endif

#endif // include guard
