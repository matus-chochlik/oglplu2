/**
 *  @file eglplus/egl_api/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_ENUM_CLASS_HPP
#define EGLPLUS_EGL_API_ENUM_CLASS_HPP

#include "config.hpp"
#include <eagine/enum_class.hpp>
#include <eagine/identifier.hpp>

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
template <typename Self, identifier_t Id>
using egl_enum_class =
  enum_class<Self, egl_types::enum_type, EAGINE_ID_V(EGL), Id>;

using egl_any_enum_class = any_enum_class<EAGINE_ID_V(EGL)>;
using egl_any_enum_value = any_enum_value<EAGINE_ID_V(EGL)>;

static constexpr inline bool same_enum_class(
  egl_any_enum_class a, egl_any_enum_class b) noexcept {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_ENUM_CLASS_HPP

