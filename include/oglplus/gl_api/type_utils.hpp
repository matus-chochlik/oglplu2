/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_TYPE_UTILS_HPP
#define OGLPLUS_GL_API_TYPE_UTILS_HPP

#include "../math/vector.hpp"
#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/type_identity.hpp>
#include <type_traits>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Trait indicating that T is one of GL basic (pixel) data types.
/// @ingroup gl_api_wrap
template <typename T>
constexpr const auto is_gl_data_type_v =
  (std::is_same_v<T, gl_types::ubyte_type> ||
   std::is_same_v<T, gl_types::byte_type> ||
   std::is_same_v<T, gl_types::ushort_type> ||
   std::is_same_v<T, gl_types::short_type> ||
   std::is_same_v<T, gl_types::uint_type> ||
   std::is_same_v<T, gl_types::int_type> ||
   std::is_same_v<T, gl_types::float_type> ||
   std::is_same_v<T, gl_types::double_type>);
//------------------------------------------------------------------------------
// data_type_of
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::ubyte_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_UNSIGNED_BYTE
    return GL_UNSIGNED_BYTE;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::byte_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_BYTE
    return GL_BYTE;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::ushort_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_UNSIGNED_SHORT
    return GL_UNSIGNED_SHORT;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::short_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_SHORT
    return GL_SHORT;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::uint_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_UNSIGNED_INT
    return GL_UNSIGNED_INT;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::int_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_INT
    return GL_INT;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::float_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_FLOAT
    return GL_FLOAT;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto data_type_of(type_identity<gl_types::double_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_DOUBLE
    return GL_DOUBLE;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <typename T, int N, bool V>
constexpr auto data_type_of(type_identity<vector<T, N, V>>) noexcept {
    return data_type_of(type_identity<T>{});
}
//------------------------------------------------------------------------------
template <typename T, int N, bool V>
constexpr auto data_type_of(type_identity<tvec<T, N, V>>) noexcept {
    return data_type_of(type_identity<T>{});
}
//------------------------------------------------------------------------------
/// @brief Returns a data type for the specified C++ type T.
/// @ingroup gl_api_wrap
/// @see sl_data_type_of
/// @see pixel_data_type_of
template <typename T>
constexpr auto data_type_of() noexcept -> data_type {
    return data_type{data_type_of(type_identity<T>{})};
}
//------------------------------------------------------------------------------
/// @brief Returns a pixel data type for the specified C++ type T.
/// @ingroup gl_api_wrap
/// @see data_type_of
/// @see sl_data_type_of
/// @see pixel_format_of
/// @see internal_format_of
template <typename T>
constexpr auto pixel_data_type_of() noexcept -> pixel_data_type {
    return pixel_data_type{data_type_of(type_identity<T>{})};
}
//------------------------------------------------------------------------------
/// @brief Returns a shading language data type for the specified C++ type T.
/// @ingroup gl_api_wrap
/// @see data_type_of
/// @see pixel_data_type_of
template <typename T>
constexpr auto sl_data_type_of() noexcept -> sl_data_type {
    return sl_data_type{data_type_of(type_identity<T>{})};
}
//------------------------------------------------------------------------------
// pixel_format_of
//------------------------------------------------------------------------------
template <typename T, typename = std::enable_if_t<is_gl_data_type_v<T>>>
constexpr auto pixel_format_of(type_identity<T>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RED
    return GL_RED;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <typename T, bool V, typename = std::enable_if_t<is_gl_data_type_v<T>>>
constexpr auto pixel_format_of(type_identity<vector<T, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG
    return GL_RG;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <typename T, bool V, typename = std::enable_if_t<is_gl_data_type_v<T>>>
constexpr auto pixel_format_of(type_identity<vector<T, 3, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGB
    return GL_RGB;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <typename T, bool V, typename = std::enable_if_t<is_gl_data_type_v<T>>>
constexpr auto pixel_format_of(type_identity<vector<T, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA
    return GL_RGBA;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <
  typename T,
  int N,
  bool V,
  typename = std::enable_if_t<is_gl_data_type_v<T>>>
constexpr auto pixel_format_of(type_identity<tvec<T, N, V>>) noexcept
  -> gl_types::enum_type {
    return pixel_format_of(type_identity<vector<T, N, V>>{});
}
//------------------------------------------------------------------------------
/// @brief Returns the default pixel format for the specified C++ type T.
/// @ingroup gl_api_wrap
/// @see pixel_data_type_of
/// @see internal_format_of
template <typename T>
constexpr auto pixel_format_of() noexcept -> pixel_format {
    return pixel_format{pixel_format_of(type_identity<T>{})};
}
//------------------------------------------------------------------------------
// internal_format_of
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::ubyte_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R8UI
    return GL_R8UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::ubyte_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG8UI
    return GL_RG8UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::ubyte_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA8UI
    return GL_RGBA8UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::byte_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R8I
    return GL_R8I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::byte_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG8I
    return GL_RG8I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::byte_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA8I
    return GL_RGBA8I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::ushort_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R16UI
    return GL_R16UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::ushort_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG16UI
    return GL_RG16UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::ushort_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA16UI
    return GL_RGBA16UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::short_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R16I
    return GL_R16I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::short_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG16I
    return GL_RG16I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::short_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA16I
    return GL_RGBA16I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::uint_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R32UI
    return GL_R32UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::uint_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG32UI
    return GL_RG32UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::uint_type, 3, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGB32UI
    return GL_RGB32UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::uint_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA32UI
    return GL_RGBA32UI;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::int_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R32I
    return GL_R32I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::int_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG32I
    return GL_RG32I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::int_type, 3, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGB32I
    return GL_RGB32I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::int_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA32I
    return GL_RGBA32I;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
constexpr auto internal_format_of(type_identity<gl_types::float_type>) noexcept
  -> gl_types::enum_type {
#ifdef GL_R32F
    return GL_R32F;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::float_type, 2, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RG32F
    return GL_RG32F;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::float_type, 3, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGB32F
    return GL_RGB32F;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
template <bool V>
constexpr auto
internal_format_of(type_identity<vector<gl_types::float_type, 4, V>>) noexcept
  -> gl_types::enum_type {
#ifdef GL_RGBA32F
    return GL_RGBA32F;
#else
    return 0;
#endif
}
//------------------------------------------------------------------------------
/// @brief Returns the default pixel internal format for the specified C++ type T.
/// @ingroup gl_api_wrap
/// @see pixel_data_type_of
/// @see pixel_format_of
template <typename T>
constexpr auto internal_format_of() noexcept -> pixel_internal_format {
    return pixel_internal_format{internal_format_of(type_identity<T>{})};
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_TYPE_UTILS_HPP
