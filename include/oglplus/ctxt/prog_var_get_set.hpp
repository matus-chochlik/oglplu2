/**
 *  @file oglplus/ctxt/prog_var_get_set.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_PROG_VAR_GET_SET_1509260923_HPP
#define OGLPLUS_CTXT_PROG_VAR_GET_SET_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/identity.hpp"
#include "../prog_var/dsa_location.hpp"
#include "../prog_var/wrapper.hpp"

namespace oglplus {
namespace ctxt {

struct prog_var_get_set_ops
{
	template <typename T, typename ProgVarLoc>
	static inline
	outcome<void>
	set(
		prog_var_wrapper<ProgVarLoc, T> loc,
		T v0
	) noexcept
	{
		typedef typename ProgVarLoc::tag tag;
		return oglplus::prog_var_get_set_ops<tag>::set(
			identity<T>(),
			loc,
			v0
		);
	}

	template <typename T, typename ProgVarLoc>
	static inline
	outcome<void>
	set(
		prog_var_wrapper<ProgVarLoc, T> loc,
		T v0, T v1
	) noexcept
	{
		typedef typename ProgVarLoc::tag tag;
		return oglplus::prog_var_get_set_ops<tag>::set(
			identity<T>(),
			loc,
			v0, v1
		);
	}

	template <typename T, typename ProgVarLoc>
	static inline
	outcome<void>
	set(
		prog_var_wrapper<ProgVarLoc, T> loc,
		T v0, T v1, T v2
	) noexcept
	{
		typedef typename ProgVarLoc::tag tag;
		return oglplus::prog_var_get_set_ops<tag>::set(
			identity<T>(),
			loc,
			v0, v1, v2
		);
	}

	template <typename T, typename ProgVarLoc>
	static inline
	outcome<void>
	set(
		prog_var_wrapper<ProgVarLoc, T> loc,
		T v0, T v1, T v2, T v3
	) noexcept
	{
		typedef typename ProgVarLoc::tag tag;
		return oglplus::prog_var_get_set_ops<tag>::set(
			identity<T>(),
			loc,
			v0, v1, v2, v3
		);
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
