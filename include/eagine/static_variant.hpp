/**
 *  @file eagine/static_variant.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STATIC_VARIANT_1509260923_HPP
#define EAGINE_STATIC_VARIANT_1509260923_HPP

#include "type_traits.hpp"
#include "memory/address.hpp"
#include <functional>
#include <tuple>

namespace eagine {

template <std::ptrdiff_t Offset, typename ... T>
struct static_variant
{
private:
	static_assert(sizeof...(T) > 0, "No types in static_variant!");

	const int _variant_id;

	template <typename X>
	const X& _as(void) const
	noexcept
	{
		return *static_cast<const X*>(memory::as_address(this)+Offset);
	}

	template <typename V, int I>
	inline
	auto _do_accept(
		V& visit,
		std::integral_constant<int, I>,
		std::integral_constant<int, I>
	) const
	{
		typedef std::tuple<T...> TT;
		typedef typename std::tuple_element<I, TT>::type TI;
		return visit(_as<TI>());
	}

	template <typename V, int L, int H>
	inline
	auto _do_accept(
		V& v,
		std::integral_constant<int, L> l,
		std::integral_constant<int, H> h
	) const
	{
		constexpr int M = (L+H)/2;
		constexpr std::integral_constant<int, M+0> ml = {};
		constexpr std::integral_constant<int, M+1> mh = {};

		return (_variant_id <= M)?
			_do_accept(v, l, ml):
			_do_accept(v, mh, h);
	}

	template <typename Visitor>
	inline
	auto _do_accept_ref(Visitor& v) const
	{
		return _do_accept(v,
			std::integral_constant<int, 0>(),
			std::integral_constant<int, sizeof...(T)-1>()
		);
	}
public:
	constexpr
	static_variant(void)
	noexcept
	 : _variant_id(-1)
	{ }

	constexpr
	bool is_valid(void) const
	noexcept
	{
		return _variant_id >= 0;
	}

	constexpr
	int variant_id(void) const
	noexcept
	{
		return _variant_id;
	}

	template <typename Visitor>
	auto accept_visitor(Visitor visit) const
	{
		return _do_accept_ref(visit);
	}

	template <typename Visitor>
	auto accept_visitor(std::reference_wrapper<Visitor> visit) const
	{
		return _do_accept_ref(visit.get());
	}
};

template <typename Visitor, std::ptrdiff_t Offset, typename ... T>
static inline
auto apply_visitor(Visitor& visitor, const static_variant<Offset, T...>& var)
{
	return var.template accept_visitor(std::ref(visitor));
}

template <typename Visitor, std::ptrdiff_t Offset, typename ... T>
static inline
auto apply_visitor(Visitor visitor, const static_variant<Offset, T...>& var)
{
	return var.template accept_visitor(std::ref(visitor));
}

} // namespace eagine

#endif // include guard
