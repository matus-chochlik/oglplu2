/**
 *  @file eglplus/egl_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_ENUM_TYPES_HPP
#define EGLPLUS_EGL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
struct egl_error_code : egl_enum_class<egl_error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

struct platform_type : egl_enum_class<platform_type, EAGINE_ID_V(PltfrmType)> {
    using enum_class::enum_class;
};

struct string_query : egl_enum_class<string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

struct config_caveat : egl_enum_class<config_caveat, EAGINE_ID_V(ConfCaveat)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_ENUM_TYPES_HPP

