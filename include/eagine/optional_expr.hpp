/**
 *  @file eagine/optional_expr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OPTIONAL_EXPR_1509260923_HPP
#define EAGINE_OPTIONAL_EXPR_1509260923_HPP

#include "valid_if.hpp"

namespace eagine {

template <typename Derived, typename ... P>
struct nary_optional_expr;

template <typename Derived, typename L, typename R>
struct nary_optional_expr<Derived, L, R>
{
private:
	L _l;
	R _r;

	const Derived& _self(void) const
	noexcept
	{
		return *static_cast<const Derived*>(this);
	}

	template <typename T, typename P>
	static
	bool _is_valid(const valid_if<T, P>& v)
	noexcept
	{
		return v.is_valid();
	}

	template <typename ... P>
	static
	bool _is_valid(const nary_optional_expr<P...>& e)
	noexcept
	{
		return e.is_valid();
	}

	template <typename T>
	static
	bool _is_valid(const T&)
	noexcept
	{
		return true;
	}

	template <typename T, typename P>
	static
	const T& _get(const valid_if<T, P>& v)
	{
		return v.value();
	}

	template <typename ... P>
	static
	auto _get(const nary_optional_expr<P...>& e)
	{
		return e.value();
	}

	template <typename T>
	static
	const T& _get(const T& v)
	{
		return v;
	}
protected:
	auto _get_l(void) const
	{
		return _get(_l);
	}

	auto _get_r(void) const
	{
		return _get(_r);
	}
public:
	nary_optional_expr(L l, R r)
	 : _l(l)
	 , _r(r)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _is_valid(_l) && _is_valid(_r);
	}

	explicit
	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
	}

	auto value(void) const
	{
		assert(is_valid());
		return _self().evaluate();
	}

	template <typename T>
	auto value_or(const T& v) const
	{
		return is_valid()?_self().evaluate():v;
	}

	template <typename Func>
	void then(Func func) const
	{
		if(is_valid())
		{
			func(value());
		}
	}
};

template <typename L, typename R>
class optional_binary_slash_expr
 : public nary_optional_expr<optional_binary_slash_expr<L, R>, L, R>
{
public:
	using	nary_optional_expr<optional_binary_slash_expr, L, R>::
		nary_optional_expr;

	auto evaluate(void) const
	{
		return this->_get_l() / this->_get_r();
	}
};

template <typename T1, typename T2, typename P2>
static inline
optional_binary_slash_expr<T1, valid_if<T2, P2>>
operator / (const T1& v1, const valid_if<T2, P2>& v2)
noexcept
{
	return {v1, v2};
}

} // namespace eagine

#endif // include guard
