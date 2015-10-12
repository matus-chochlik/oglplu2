/**
 *  @file oglplus/ctxt/uniform.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_UNIFORM_1509260923_HPP
#define OGLPLUS_CTXT_UNIFORM_1509260923_HPP

#include "../uniform.hpp"


namespace oglplus {
namespace ctxt {

struct uniform_ops
{
	template <
		typename T,
		bool D,
		typename V0
	>
	static inline
	outcome<void>
	uniform(
		prog_var_wrapper<prog_var_loc<tag::uniform, D>, T> loc,
		V0 v0
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<T>(),
			loc,
			v0
		);
	}

	template <
		typename T,
		bool D,
		typename V0,
		typename V1
	>
	static inline
	outcome<void>
	uniform(
		prog_var_wrapper<prog_var_loc<tag::uniform, D>, T> loc,
		V0 v0, V1 v1
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<T>(),
			loc,
			v0, v1
		);
	}

	template <
		typename T,
		bool D,
		typename V0,
		typename V1,
		typename V2
	>
	static inline
	outcome<void>
	uniform(
		prog_var_wrapper<prog_var_loc<tag::uniform, D>, T> loc,
		V0 v0, V1 v1, V2 v2
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<T>(),
			loc,
			v0, v1, v2
		);
	}

	template <
		typename T,
		bool D,
		typename V0,
		typename V1,
		typename V2,
		typename V3
	>
	static inline
	outcome<void>
	uniform(
		prog_var_wrapper<prog_var_loc<tag::uniform, D>, T> loc,
		V0 v0, V1 v1, V2 v2, V3 v3
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<T>(),
			loc,
			v0, v1, v2, v3
		);
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
