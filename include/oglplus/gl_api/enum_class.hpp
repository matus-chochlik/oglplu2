/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_ENUM_CLASS_HPP
#define OGLPLUS_GL_API_ENUM_CLASS_HPP

#include "config.hpp"
#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>
#include <eagine/identifier.hpp>
#include <eagine/logging/backend.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Typed wrapper class for GLenum constants/values.
/// @ingroup gl_api_wrap
/// @see gl_bitfield_class
/// @see gl_ubyte_class
/// @see gl_bool_class
/// @see gl_any_enum_class
///
/// This wrapper uses the specified Id to group various GL constants logically
/// belonging together and prevents accidental mismatches and use of GL constants
/// from unrelated groups. For example using a shader type constant in place
/// of texture type constants. Such mismatches result in compilation errors.
template <typename Self, identifier_t Id>
using gl_enum_class =
  enum_class<Self, gl_types::enum_type, EAGINE_ID_V(GL), Id>;

/// @brief Typed wrapper class for GLbitfield constants/values.
/// @ingroup gl_api_wrap
/// @see gl_enum_class
/// @see gl_ubyte_class
/// @see gl_bool_class
/// @see gl_any_enum_class
///
/// This wrapper uses the specified Id to group various GL constants logically
/// belonging together and prevents accidental mismatches and use of GL constanst
/// from unrelated groups. For example using a context attribute bits in place
/// of memory barrier bit constants. Such mismatches result in compilation errors.
template <typename Self, identifier_t Id>
using gl_bitfield_class =
  enum_class<Self, gl_types::bitfield_type, EAGINE_ID_V(GL), Id>;

/// @brief Typed wrapper class for GLubyte constants/values.
/// @ingroup gl_api_wrap
/// @see gl_enum_class
/// @see gl_bitfield_class
/// @see gl_bool_class
/// @see gl_any_enum_class
///
/// This wrapper uses the specified Id to group various GL constants logically
/// belonging together and prevents accidental mismatches and use of GL constanst
/// from unrelated groups. Such mismatches result in compilation errors.
template <typename Self, identifier_t Id>
using gl_ubyte_class =
  enum_class<Self, gl_types::ubyte_type, EAGINE_ID_V(GL), Id>;

/// @brief Typed wrapper class for GLboolean constants/values.
/// @ingroup gl_api_wrap
/// @see gl_enum_class
/// @see gl_bitfield_class
/// @see gl_ubyte_class
/// @see gl_any_enum_class
template <typename Self, identifier_t Id>
using gl_bool_class =
  enum_class<Self, gl_types::bool_type, EAGINE_ID_V(GL), Id>;

/// @brief Type erasure alias for GL enum classes.
/// @ingroup gl_api_wrap
/// @see gl_enum_class
/// @see gl_bitfield_class
/// @see gl_ubyte_class
/// @see gl_bool_class
using gl_any_enum_class = any_enum_class<EAGINE_ID_V(GL)>;

/// @brief Type erasure alias for GL enum values.
/// @ingroup gl_api_wrap
using gl_any_enum_value = any_enum_value<EAGINE_ID_V(GL)>;

static constexpr auto
same_enum_class(gl_any_enum_class a, gl_any_enum_class b) noexcept -> bool {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
template <
  typename ParameterEnumClass,
  typename Parameter,
  typename ValueType,
  typename Value>
constexpr static bool is_enum_parameter_value_v =
  is_enum_class_value_v<ParameterEnumClass, Parameter>&&
      std::is_same_v<typename Parameter::tag_type, nothing_t>
    ? std::is_convertible_v<Value, ValueType>
    : is_enum_class_value_v<typename Parameter::tag_type, Value>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_ENUM_CLASS_HPP
