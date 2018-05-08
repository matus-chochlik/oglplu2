/**
 *  @file oglplus/oper/debugging.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_DEBUGGING_1509260923_HPP
#define OGLPLUS_OPER_DEBUGGING_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"

namespace oglplus {
namespace oper {

struct debugging {
#if defined(GL_VERSION_4_3)
    static outcome<void> push_debug_group(
      debug_output_source source, GLuint id, cstring_span message) noexcept;

    static outcome<void> pop_debug_group(void) noexcept;

    static outcome<void> debug_message_control(debug_output_source source,
      debug_output_type type,
      debug_output_severity severity,
      span<const GLuint> ids,
      boolean enabled) noexcept;

    static outcome<void> debug_message_insert(debug_output_source source,
      debug_output_type type,
      GLuint id,
      debug_output_severity severity,
      cstring_span message) noexcept;

    static outcome<void> debug_message_callback(
      GLDEBUGPROC callback, void* user_param) noexcept;

    static outcome<void> get_debug_message_log(GLuint count,
      span<debug_output_source> sources,
      span<debug_output_type> types,
      span<GLuint> ids,
      span<debug_output_severity> severities,
      span<GLsizei> lengths,
      span<GLchar> message_log) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/debugging.inl>

#endif // include guard
