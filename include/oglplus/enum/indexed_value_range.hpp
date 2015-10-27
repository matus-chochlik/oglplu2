/**
 *  @file oglplus/enum/indexed_value_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_INDEXED_VALUE_RANGE_1509260923_HPP
#define OGLPLUS_ENUM_INDEXED_VALUE_RANGE_1509260923_HPP

#include "../utils/indexed_enum.hpp"
#include "../utils/limited_value.hpp"

namespace oglplus {

template <typename LimitedValue>
class limited_value_range;

template <GLenum Query, GLenum Base>
class limited_value_range<limited_value<Query, indexed_enum_value<Base>>>
{
private:
	GLenum _limit;

	typedef limited_value<Query, indexed_enum_value<Base>> _lv_t;

	static
	_lv_t _wrap_enum(GLenum e)
	noexcept
	{
		return _lv_t{e};
	}
	
public:
	limited_value_range(_lv_t limit)
	noexcept
	 : _limit(GLenum(limit))
	{ }

	limited_value_range(void)
	 : limited_value_range(get_limit(identity<_lv_t>()).get())
	{ }

	typedef eagine::transforming_iterator<
		eagine::selfref_iterator<GLenum>,
		_lv_t, _lv_t(*)(GLenum) noexcept
	> iterator;

	iterator begin(void) const
	noexcept
	{
		return iterator(Base, &_wrap_enum);
	}

	iterator end(void) const
	noexcept
	{
		return iterator(_limit, &_wrap_enum);
	}
};

template <
	typename LimitedValue,
	typename = typename std::enable_if<
		is_limited_value<LimitedValue>::value
	>::type
>
static inline
limited_value_range<LimitedValue>
enum_value_range(void)
{
	return {};
}

} // namespace oglplus

#endif // include guard
