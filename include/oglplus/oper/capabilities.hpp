/**
 *  @file oglplus/oper/capabilities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_CAPABILITIES_1509260923_HPP
#define OGLPLUS_OPER_CAPABILITIES_1509260923_HPP

#include "../utils/boolean.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"
#include "../enum/indexed_types.hpp"

namespace oglplus {
namespace oper {

struct capability_state
{
	static
	outcome<void>
	enable(capability cap)
	noexcept;

	static
	outcome<void>
	disable(capability cap)
	noexcept;

	static
	outcome<boolean>
	is_enabled(capability cap)
	noexcept;

	static
	outcome<void>
	enable(clip_plane cap)
	noexcept;

	static
	outcome<void>
	disable(clip_plane cap)
	noexcept;

	static
	outcome<boolean>
	is_enabled(clip_plane cap)
	noexcept;

	static
	outcome<void>
	enable_client_state(client_capability cap)
	noexcept;

	static
	outcome<void>
	disable_client_state(client_capability cap)
	noexcept;

	static
	outcome<boolean>
	is_enabled(client_capability cap)
	noexcept;

	static
	outcome<GLint>
	red_bits(void)
	noexcept;

	static
	outcome<GLint>
	green_bits(void)
	noexcept;

	static
	outcome<GLint>
	blue_bits(void)
	noexcept;

	static
	outcome<GLint>
	alpha_bits(void)
	noexcept;

	static
	outcome<GLint>
	depth_bits(void)
	noexcept;

	static
	outcome<GLint>
	stencil_bits(void)
	noexcept;

	static
	outcome<boolean>
	doublebuffer(void)
	noexcept;

	static
	outcome<boolean>
	stereo(void)
	noexcept;
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/capabilities.inl>

#endif // include guard
