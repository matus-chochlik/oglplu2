/**
 *  @file oglplus/ctxt/synchronization.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_SYNCHRONIZATION_1509260923_HPP
#define OGLPLUS_CTXT_SYNCHRONIZATION_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

namespace oglplus {
namespace ctxt {

struct synchronization
{
#if defined(GL_VERSION_4_2) || defined(GL_ARB_shader_image_load_store)
	static
	outcome<void>
	memory_barrier(enum_bitfield<memory_barrier_bits> bits)
	noexcept
	{
		OGLPLUS_GLFUNC(MemoryBarrier)(GLbitfield(bits));
		OGLPLUS_VERIFY_SIMPLE(MemoryBarrier, warning);
		return {};
	}
#endif

	static
	outcome<void>
	flush(void)
	noexcept
	{
		OGLPLUS_GLFUNC(Flush)();
		OGLPLUS_VERIFY_SIMPLE(Flush, warning);
		return {};
	}

	static
	outcome<void>
	finish(void)
	noexcept
	{
		OGLPLUS_GLFUNC(Finish)();
		OGLPLUS_VERIFY_SIMPLE(Finish, warning);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
