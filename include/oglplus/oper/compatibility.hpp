/**
 *  @file oglplus/oper/compatibility.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_COMPATIBILITY_1509260923_HPP
#define OGLPLUS_OPER_COMPATIBILITY_1509260923_HPP

#ifdef GL_ARB_compatibility
#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/gl_func.hpp"

#include "compat_drawing.hpp"
#include "compat_matrix.hpp"
#endif // ARB_compatibility

namespace oglplus {
namespace oper {

struct compatibility
#ifdef GL_ARB_compatibility
  : compatibility_matrix
  , compatibility_drawing {
};
#else
{
};
#endif // ARB_compatibility

} // namespace oper
} // namespace oglplus

#endif // include guard
