/**
 *  @file oglplus/oper/vertex_attrib.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_VERTEX_ATTRIB_1509260923_HPP
#define OGLPLUS_OPER_VERTEX_ATTRIB_1509260923_HPP

#include "../vertex_attrib.hpp"
#include "../utils/boolean.hpp"
#include "../utils/vec_mat_traits.hpp"
#include <type_traits>

namespace oglplus {
namespace oper {

struct vertex_attrib_ops
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
	vertex_attrib(
		prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
		V0 v0,
		bool check_error
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::vertex_attrib>::set(
			identity<T>(),
			loc,
			check_error,
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
	vertex_attrib(
		prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
		V0 v0, V1 v1,
		bool check_error
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::vertex_attrib>::set(
			identity<T>(),
			loc,
			check_error,
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
	vertex_attrib(
		prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
		V0 v0, V1 v1, V2 v2,
		bool check_error
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::vertex_attrib>::set(
			identity<T>(),
			loc,
			check_error,
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
	vertex_attrib(
		prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
		V0 v0, V1 v1, V2 v2, V3 v3,
		bool check_error
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::vertex_attrib>::set(
			identity<T>(),
			loc,
			check_error,
			v0, v1, v2, v3
		);
	}

	template <typename T, std::size_t N, bool D>
	static inline
	outcome<void>
	vertex_attrib(
		prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T[N]> loc,
		const array_view<const T>& v,
		bool check_error
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::vertex_attrib>::set(
			identity<T[N]>(),
			loc,
			check_error,
			v
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
	vertex_attrib(
		prog_var_loc<tag::vertex_attrib, D> loc,
		const X& x,
		bool check_error
	) noexcept
	{
		return oglplus::prog_var_get_set_ops<tag::vertex_attrib>::set(
			canonical_compound_type<X>(),
			loc,
			check_error,
			element_view(x)
		);
	}

	static
	outcome<void>
	pointer(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLsizei stride,
		const void* pointer
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribPointer)(
			loc.index(),
			values_per_vertex,
			GLenum(type),
			normalized,
			stride,
			pointer
		);
		OGLPLUS_VERIFY(
			VertexAttribPointer,
			gl_enum_value(type).
			gl_index(loc.index()),
			always
		);
		return {};	
	}

	// TODO

#ifdef GL_VERSION_3_3
	static
	outcome<void>
	divisor(vertex_attrib_location va, GLuint div)
	noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribDivisor)(
			va.index(),
			div
		);
		OGLPLUS_VERIFY(
			VertexAttribDivisor,
			gl_index(va.index()),
			always
		);
		return {};
	}
#endif
};

} // namespace oper
} // namespace oglplus

#endif // include guard
