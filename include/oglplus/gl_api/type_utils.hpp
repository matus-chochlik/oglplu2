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

namespace eagine::oglp {
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
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_TYPE_UTILS_HPP
