/**
 *  @file oglplus/oper/debugging.inl
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
#if defined(GL_VERSION_4_3)
inline
outcome<void>
debugging::
push_debug_group(
	debug_output_source source,
	GLuint id,
	cstring_span message
) noexcept {
	OGLPLUS_GLFUNC(PushDebugGroup)(
		GLenum(source),
		id,
		GLsizei(message.size()),
		message.data()
	);
	OGLPLUS_VERIFY(
		PushDebugGroup,
		gl_enum_value(source),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
debugging::
pop_debug_group(void)
noexcept {
	OGLPLUS_GLFUNC(PopDebugGroup)();
	OGLPLUS_VERIFY_SIMPLE(PopDebugGroup, debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
debugging::
debug_message_control(
	debug_output_source source,
	debug_output_type type,
	debug_output_severity severity,
	span<const GLuint> ids,
	boolean enabled
) noexcept {
	OGLPLUS_GLFUNC(DebugMessageControl)(
		GLenum(source),
		GLenum(type),
		GLenum(severity),
		GLsizei(ids.size()),
		ids.data(),
		GLboolean(enabled)
	);
	OGLPLUS_VERIFY(
		DebugMessageControl,
		gl_enum_value(source),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
debugging::
debug_message_insert(
	debug_output_source source,
	debug_output_type type,
	GLuint id,
	debug_output_severity severity,
	cstring_span message
) noexcept {
	OGLPLUS_GLFUNC(DebugMessageInsert)(
		GLenum(source),
		GLenum(type),
		id,
		GLenum(severity),
		GLsizei(message.size()),
		message.data()
	);
	OGLPLUS_VERIFY(
		DebugMessageInsert,
		gl_enum_value(source),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
debugging::
debug_message_callback(
	GLDEBUGPROC callback,
	void* user_param
) noexcept {
	OGLPLUS_GLFUNC(DebugMessageCallback)(callback, user_param);
	OGLPLUS_VERIFY_SIMPLE(DebugMessageCallback, debug);
	return {};

}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
