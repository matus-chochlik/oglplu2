/**
 *  @file oglplus/debug_output.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_DEBUG_OUTPUT_HPP
#define OGLPLUS_DEBUG_OUTPUT_HPP

#include "enum/types.hpp"
#include "oper/capabilities.hpp"
#include "oper/debugging.hpp"
#include "utils/string_span.hpp"
#include <eagine/callable_ref.hpp>
#include <eagine/maybe_unused.hpp>

namespace oglplus {

class debug_output {
public:
    using user_callback_func = void(
      debug_output_source,
      debug_output_type,
      GLuint,
      debug_output_severity,
      string_view);

#if GL_VERSION_4_3
    debug_output(eagine::callable_ref<user_callback_func> callback)
      : _user_callback(callback) {
        // TODO: remember previous state
        oper::capability_state::enable(capability(GL_DEBUG_OUTPUT));
        oper::debugging::debug_message_callback(
          &_callback, static_cast<void*>(this));
    }
#else
    debug_output(eagine::callable_ref<user_callback_func>) {
    }
#endif

    debug_output(debug_output&&) = delete;
    debug_output(const debug_output&) = delete;
    debug_output& operator=(debug_output&&) = delete;
    debug_output& operator=(const debug_output&) = delete;

#if GL_VERSION_4_3
    ~debug_output() noexcept {
        try {
            // TODO: restore previous state
            oper::capability_state::disable(capability(GL_DEBUG_OUTPUT));
            oper::debugging::debug_message_callback(nullptr, nullptr);

        } catch(...) {
        }
    }
#else
    ~debug_output() noexcept = default;
#endif

    void send_message(
      debug_output_source source,
      debug_output_type type,
      GLuint source_id,
      debug_output_severity severity,
      string_view message) const {
#if GL_VERSION_4_3
        oper::debugging::debug_message_insert(
          source, type, source_id, severity, message);
#else
        EAGINE_MAYBE_UNUSED(source);
        EAGINE_MAYBE_UNUSED(type);
        EAGINE_MAYBE_UNUSED(source_id);
        EAGINE_MAYBE_UNUSED(severity);
        EAGINE_MAYBE_UNUSED(message);
#endif
    }

    void send_message(
      debug_output_type type,
      GLuint source_id,
      debug_output_severity severity,
      string_view message) const {
#if GL_VERSION_4_3
        oper::debugging::debug_message_insert(
          debug_output_source(GL_DEBUG_SOURCE_APPLICATION),
          type,
          source_id,
          severity,
          message);
#else
        EAGINE_MAYBE_UNUSED(type);
        EAGINE_MAYBE_UNUSED(source_id);
        EAGINE_MAYBE_UNUSED(severity);
        EAGINE_MAYBE_UNUSED(message);
#endif
    }

    void set_notification_marker(
      string_view message, GLuint source_id = 0) const {
#if GL_VERSION_4_3
        oper::debugging::debug_message_insert(
          debug_output_source(GL_DEBUG_SOURCE_APPLICATION),
          debug_output_type(GL_DEBUG_TYPE_MARKER),
          source_id,
          debug_output_severity(GL_DEBUG_SEVERITY_NOTIFICATION),
          message);
#else
        EAGINE_MAYBE_UNUSED(source_id);
        EAGINE_MAYBE_UNUSED(message);
#endif
    }

private:
#if GL_VERSION_4_3
    eagine::callable_ref<user_callback_func> _user_callback;

    void _handle_message(
      debug_output_source source,
      debug_output_type type,
      GLuint source_id,
      debug_output_severity severity,
      string_view message) const {
        if(_user_callback) {
            _user_callback(source, type, source_id, severity, message);
        }
    }

    static void APIENTRY _callback(
      GLenum source,
      GLenum type,
      GLuint source_id,
      GLenum severity,
      GLsizei length,
      const GLchar* message,
      const void* param) {
        if(auto* that = static_cast<const debug_output*>(param)) {
            that->_handle_message(
              debug_output_source(source),
              debug_output_type(type),
              source_id,
              debug_output_severity(severity),
              (length < 0) ? string_view(message)
                           : string_view(message, span_size(length)));
        }
    }
#endif
};

} // namespace oglplus

#endif // OGLPLUS_DEBUG_OUTPUT_HPP
