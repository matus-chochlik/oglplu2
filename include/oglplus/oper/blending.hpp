/**
 *  @file oglplus/oper/blending.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_BLENDING_1509260923_HPP
#define OGLPLUS_OPER_BLENDING_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct blending_state
{
	static
	outcome<void>
	blend_equation(oglplus::blend_equation equation)
	noexcept;

#if defined(GL_VERSION_4_0)
	static
	outcome<void>
	blend_equation(GLuint buf, oglplus::blend_equation equation)
	noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/blending.inl>

#endif // include guard
