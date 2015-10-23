/**
 *  @file oglplus/limited_value.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_LIMITED_VALUE_1509260923_HPP
#define OGLPLUS_LIMITED_VALUE_1509260923_HPP

#include "utils/gl_func.hpp"
#include "utils/indexed_enum.hpp"
#include "utils/identity.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "enum/types.hpp"

namespace oglplus {

template <GLenum Query, typename T>
struct limited_value
{
	T _value;

	limited_value(void) = default;

	constexpr
	limited_value(T value)
	noexcept
	 : _value(value)
	{ }

	explicit constexpr
	operator T (void) const
	noexcept
	{
		return _value;
	}
};

template <GLenum Query, GLenum Base>
struct limited_value<Query, indexed_enum_value<Base>>
 : indexed_enum_value<Base>
{
	limited_value(void) = default;

	constexpr
	limited_value(indexed_enum_value<Base> iev)
	noexcept
	 : indexed_enum_value<Base>(iev)
	{ }

	constexpr
	limited_value(indexed_enum_base<Base> ieb)
	noexcept
	 : indexed_enum_value<Base>(ieb)
	{ }

	explicit constexpr
	limited_value(unsigned offset)
	noexcept
	 : indexed_enum_value<Base>(offset)
	{ }
};

template <typename X>
struct is_limited_value
 : std::false_type
{ };

template <GLenum Query, typename T>
struct is_limited_value<limited_value<Query, T>>
 : std::true_type
{ };

template <
	GLenum Query,
	typename T,
	typename = typename std::enable_if<
		std::is_integral<T>::value
	>::type
>
static inline
outcome<T>
get_limit(identity<limited_value<Query, T>>)
noexcept
{
	GLint value = 0;
	OGLPLUS_GLFUNC(GetIntegerv)(Query, &value);
	OGLPLUS_VERIFY(
		GetIntegerv,
		gl_enum_value(limit_query(Query)),
		debug
	);
	return {T(value)};
}

template <GLenum Query, GLenum Base>
static inline
outcome<indexed_enum_value<Base>>
get_limit(identity<limited_value<Query, indexed_enum_value<Base>>>)
noexcept
{
	return outcome_cast<indexed_enum_value<Base>>(
		get_limit(identity<limited_value<Query, GLenum>>())
	);
}

template <
	typename LimitedValue,
	typename = typename std::enable_if<
		is_limited_value<LimitedValue>::value
	>::type
>
static inline
auto limit(void)
noexcept
{
	return get_limit(identity<LimitedValue>());
}

template <GLenum Query, typename T>
static inline
bool exceeds_limit(limited_value<Query, T> lv, T limit)
noexcept
{
	return T(lv) >= limit;
}

template <GLenum Query, GLenum Base>
static inline
bool exceeds_limit(
	limited_value<Query, indexed_enum_value<Base>> lv,
	indexed_enum_value<Base> limit
) noexcept
{
	return lv.offset() >= limit.offset();
}

template <GLenum Query, typename T>
static inline
outcome<void>
check_value(limited_value<Query, T> lv)
noexcept
{
	outcome<T> lim = get_limit(make_identity(lv));
	if(lim.failed())
	{
		return lim.release_handler();
	}
	if(exceeds_limit(lv, lim.get()))
	{
		return deferred_error_handler(std::move(
			error_info(GL_INVALID_VALUE)
				.gl_enum_value(limit_query(Query))
				.source_file(__FILE__)
				.source_line(__LINE__)
		));
	}
	return {};
}

} // namespace oglplus

#endif // include guard
