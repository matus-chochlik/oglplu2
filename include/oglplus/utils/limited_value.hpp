/**
 *  @file oglplus/utils/limited_value.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_LIMITED_VALUE_1509260923_HPP
#define OGLPLUS_UTILS_LIMITED_VALUE_1509260923_HPP

#include "gl_func.hpp"
#include "indexed_enum.hpp"
#include "identity.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

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
	limited_value(oglplus::indexed_enum_value<Base> iev)
	noexcept
	 : oglplus::indexed_enum_value<Base>(iev)
	{ }

	constexpr
	limited_value(oglplus::indexed_enum_base<Base> ieb)
	noexcept
	 : oglplus::indexed_enum_value<Base>(ieb)
	{ }

	constexpr explicit
	limited_value(GLenum value)
	noexcept
	 : oglplus::indexed_enum_value<Base>(value)
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

static inline
outcome<GLint>
get_integer_limit(limit_query lq)
noexcept
{
	GLint value = 0;
	OGLPLUS_GLFUNC(GetIntegerv)(GLenum(lq), &value);
	OGLPLUS_VERIFY(
		GetIntegerv,
		gl_enum_value(lq),
		debug
	);
	return {value};
}

template <
	GLenum Query,
	typename T,
	typename = std::enable_if_t<std::is_integral<T>::value>
>
static inline
outcome<T>
get_limit(identity<limited_value<Query, T>>)
noexcept
{
	return outcome_cast<T>(get_integer_limit(limit_query(Query)));
}

template <GLenum Query, GLenum Base>
static inline
outcome<indexed_enum_value<Base>>
get_limit(identity<limited_value<Query, indexed_enum_value<Base>>>)
noexcept
{
	return outcome_cast<indexed_enum_value<Base>>(
		get_limit(identity<limited_value<Query, GLenum>>())|
		[](GLenum& val) { val += Base; }
	);
}

template <
	typename LimitedValue,
	typename = std::enable_if_t<is_limited_value<LimitedValue>::value>
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
	return lv.index() >= limit.index();
}

static inline
deferred_error_handler
handle_above_limit(limit_query lq)
noexcept
{
	return deferred_error_handler(std::move(
		error_info(GL_INVALID_VALUE)
			.gl_enum_value(lq)
			.source_file(__FILE__)
			.source_line(__LINE__)
	));
}

template <GLenum Query, typename T>
static inline
outcome<void>
check_below_limit(limited_value<Query, T> lv)
noexcept
{
	outcome<T> lim = get_limit(make_identity(lv));
	if(lim.failed())
	{
		return lim.release_handler();
	}
	if(exceeds_limit(lv, lim.value()))
	{
		handle_above_limit(limit_query(Query));
	}
	return {};
}

} // namespace oglplus

#endif // include guard
