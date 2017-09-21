/**
 *  @file oglplus/oper/computing.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2)
inline
outcome<void>
computing_ops::
dispatch_compute(GLuint x_groups, GLuint y_groups, GLuint z_groups)
noexcept
{
	OGLPLUS_GLFUNC(DispatchCompute)(x_groups, y_groups, z_groups);
	OGLPLUS_VERIFY_SIMPLE(DispatchCompute, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
