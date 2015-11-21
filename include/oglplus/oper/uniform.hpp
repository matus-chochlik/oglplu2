/**
 *  @file oglplus/oper/uniform.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_UNIFORM_1509260923_HPP
#define OGLPLUS_OPER_UNIFORM_1509260923_HPP

#include "../uniform.hpp"
#include "../utils/boolean.hpp"
#include "../utils/vec_mat_traits.hpp"
#include <type_traits>

namespace oglplus {
namespace oper {

struct uniform_ops
{
	template <
		typename T,
		bool D,
		typename V0,
		typename = typename std::enable_if<
			std::is_convertible<V0, T>::value &&
			!std::is_array<T>::value
		>::type
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
		typename V1,
		typename = typename std::enable_if<
			std::is_convertible<V0, T>::value &&
			std::is_convertible<V1, T>::value &&
			!std::is_array<T>::value
		>::type
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
		typename V2,
		typename = typename std::enable_if<
			std::is_convertible<V0, T>::value &&
			std::is_convertible<V1, T>::value &&
			std::is_convertible<V2, T>::value &&
			!std::is_array<T>::value
		>::type
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
		typename V3,
		typename = typename std::enable_if<
			std::is_convertible<V0, T>::value &&
			std::is_convertible<V1, T>::value &&
			std::is_convertible<V2, T>::value &&
			std::is_convertible<V3, T>::value &&
			!std::is_array<T>::value
		>::type
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

	template <typename T, std::size_t N, bool D>
	static inline
	outcome<void>
	uniform(
		prog_var_wrapper<prog_var_loc<tag::uniform, D>, T[N]> loc,
		GLsizei count,
		const span<const T>& v
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<T[N]>(),
			loc,
			count, v
		);
	}

	template <typename T, std::size_t C, std::size_t R, bool D>
	static inline
	outcome<void>
	uniform(
		prog_var_wrapper<prog_var_loc<tag::uniform, D>, T[C][R]> loc,
		GLsizei count,
		boolean transpose,
		const span<const T>& v
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<T[C][R]>(),
			loc,
			count, transpose, v
		);
	}

	template <
		bool D,
		typename X,
		typename = typename std::enable_if<
			is_gl_data_type<X>::value
		>::type
	>
	static inline
	outcome<void>
	_uniform_vm(
		prog_var_loc<tag::uniform, D> loc,
		const X& x,
		std::false_type,
		std::false_type
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			identity<X>(),
			loc,
			x
		);
	}

	template <
		bool D,
		typename X,
		typename = typename std::enable_if<
			is_known_vector_type<X>::value
		>::type
	>
	static inline
	outcome<void>
	_uniform_vm(
		prog_var_loc<tag::uniform, D> loc,
		const X& x,
		std::true_type,
		std::false_type
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			canonical_compound_type<X>(),
			loc,
			1, element_view(x)
		);
	}

	template <
		bool D,
		typename X,
		typename = typename std::enable_if<
			is_known_matrix_type<X>::value
		>::type
	>
	static inline
	outcome<void>
	_uniform_vm(
		prog_var_loc<tag::uniform, D> loc,
		const X& x,
		std::false_type,
		std::true_type
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::uniform>::set(
			canonical_compound_type<X>(),
			loc,
			1, is_row_major<X>::value, element_view(x)
		);
	}

	template <
		bool D,
		typename X,
		typename = typename std::enable_if<
			is_gl_data_type<X>::value ||
			is_known_vector_type<X>::value ||
			is_known_matrix_type<X>::value
		>::type
	>
	static inline
	outcome<void>
	uniform(
		prog_var_loc<tag::uniform, D> loc,
		const X& x
	) noexcept
	{
		return _uniform_vm(
			loc, x,
			is_known_vector_type<X>(),
			is_known_matrix_type<X>()
		);
	}
};

} // namespace oper
} // namespace oglplus

#endif // include guard
