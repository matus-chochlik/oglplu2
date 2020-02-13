/**
 *  @file oglplus/gl_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_ENUM_TYPES_HPP
#define OGLPLUS_GL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
struct error_code : gl_enum_class<error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_ENUM_TYPES_HPP

