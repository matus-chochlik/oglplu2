/**
 *  @file oglplus/ctxt/capabilities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_CAPABILITIES_1509260923_HPP
#define OGLPLUS_CTXT_CAPABILITIES_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

namespace oglplus {
namespace ctxt {

struct capabilities
{
	static
	outcome<void>
	enable(capability cap)
	noexcept
	{
		OGLPLUS_GLFUNC(Enable)(GLenum(cap));
		OGLPLUS_VERIFY_SIMPLE(Enable, warning);
		return {};
	}

	static
	outcome<void>
	disable(capability cap)
	noexcept
	{
		OGLPLUS_GLFUNC(Disable)(GLenum(cap));
		OGLPLUS_VERIFY_SIMPLE(Disable, warning);
		return {};
	}

	static
	outcome<bool>
	is_enabled(capability cap)
	noexcept
	{
		GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(cap));
		OGLPLUS_VERIFY_SIMPLE(IsEnabled, warning);
		return {result == GL_TRUE};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
