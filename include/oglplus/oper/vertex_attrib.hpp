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

#include "../utils/boolean.hpp"
#include "../utils/vec_mat_traits.hpp"
#include "../vertex_attrib.hpp"
#include <eagine/std/type_traits.hpp>

namespace oglplus {
namespace oper {

struct vertex_attrib_ops {
    template <typename T,
      bool D,
      typename V0,
      typename =
	std::enable_if_t<std::is_convertible_v<V0, T> && !std::is_array_v<T>>

      >
    static inline outcome<void> vertex_attrib(
      prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
      V0 v0,
      bool check_error) noexcept {
	return oglplus::prog_var_get_set_ops<tag::vertex_attrib, T>::set(
	  identity<T>(), loc, check_error, v0);
    }

    template <typename T,
      bool D,
      typename V0,
      typename V1,
      typename = std::enable_if_t<
	std::is_convertible_v<V0,
	  T> && std::is_convertible_v<V1, T> && !std::is_array_v<T>>

      >
    static inline outcome<void> vertex_attrib(
      prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
      V0 v0,
      V1 v1,
      bool check_error) noexcept {
	return oglplus::prog_var_get_set_ops<tag::vertex_attrib, T>::set(
	  identity<T>(), loc, check_error, v0, v1);
    }

    template <typename T,
      bool D,
      typename V0,
      typename V1,
      typename V2,
      typename = std::enable_if_t<
	std::is_convertible_v<V0,
	  T> && std::is_convertible_v<V1, T> && std::is_convertible_v<V2, T> && !std::is_array_v<T>>

      >
    static inline outcome<void> vertex_attrib(
      prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
      V0 v0,
      V1 v1,
      V2 v2,
      bool check_error) noexcept {
	return oglplus::prog_var_get_set_ops<tag::vertex_attrib, T>::set(
	  identity<T>(), loc, check_error, v0, v1, v2);
    }

    template <typename T,
      bool D,
      typename V0,
      typename V1,
      typename V2,
      typename V3,
      typename = std::enable_if_t<
	std::is_convertible_v<V0,
	  T> && std::is_convertible_v<V1, T> && std::is_convertible_v<V2, T> && std::is_convertible_v<V3, T> && !std::is_array_v<T>>

      >
    static inline outcome<void> vertex_attrib(
      prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T> loc,
      V0 v0,
      V1 v1,
      V2 v2,
      V3 v3,
      bool check_error) noexcept {
	return oglplus::prog_var_get_set_ops<tag::vertex_attrib, T>::set(
	  identity<T>(), loc, check_error, v0, v1, v2, v3);
    }

    template <typename T, span_size_t N, bool D>
    static inline outcome<void> vertex_attrib(
      prog_var_wrapper<prog_var_loc<tag::vertex_attrib, D>, T[N]> loc,
      const span<const T>& v,
      bool check_error) noexcept {
	return oglplus::prog_var_get_set_ops<tag::vertex_attrib, T>::set(
	  identity<T[N]>(), loc, check_error, v);
    }

    template <bool D,
      typename X,
      typename = std::enable_if_t<is_known_vector_type_v<X>>>
    static inline outcome<void> vertex_attrib(
      prog_var_loc<tag::vertex_attrib, D> loc,
      const X& x,
      bool check_error) noexcept {
	return oglplus::prog_var_get_set_ops<tag::vertex_attrib,
	  canonical_element_type_t<X>>::set(canonical_compound_type<X>(),
	  loc,
	  check_error,
	  element_view(x));
    }

#ifdef GL_VERSION_3_3
    static outcome<void> divisor(
      vertex_attrib_location va, GLuint div) noexcept {
	OGLPLUS_GLFUNC(VertexAttribDivisor)(va.index(), div);
	OGLPLUS_VERIFY(VertexAttribDivisor, gl_index(va.index()), always);
	return {};
    }
#endif
};

} // namespace oper
} // namespace oglplus

#endif // include guard
