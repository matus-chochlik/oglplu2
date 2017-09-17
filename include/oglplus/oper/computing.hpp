/**
 *  @file oglplus/oper/computing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_COMPUTING_1509260923_HPP
#define OGLPLUS_OPER_COMPUTING_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct computing_ops
{
#if defined(GL_VERSION_4_2)
	static
	outcome<void>
	dispatch_compute(GLuint x_groups, GLuint y_groups, GLuint z_groups)
	noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/computing.inl>

#endif // include guard
