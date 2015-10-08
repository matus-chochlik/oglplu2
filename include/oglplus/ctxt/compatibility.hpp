/**
 *  @file oglplus/ctxt/compatibility.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_COMPATIBILITY_1509260923_HPP
#define OGLPLUS_CTXT_COMPATIBILITY_1509260923_HPP

#ifdef GL_ARB_compatibility
#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

#include "compat_matrix.hpp"
#include "compat_drawing.hpp"
#endif // ARB_compatibility

namespace oglplus {
namespace ctxt {

struct compatibility_ops
#ifdef GL_ARB_compatibility
 : compatibility_matrix_ops
 , compatibility_drawing_ops
{
};
#else
{ };
#endif // ARB_compatibility

} // namespace ctxt
} // namespace oglplus

#endif // include guard
