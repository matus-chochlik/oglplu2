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

#include "../enum/indexed_types.hpp"
#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/boolean.hpp"

namespace oglplus {
namespace oper {

struct capability_state {
    static outcome<void> enable(capability cap) noexcept;

    static outcome<void> disable(capability cap) noexcept;

    static outcome<boolean> is_enabled(capability cap) noexcept;

#if defined(GL_VERSION_3_0)
    static outcome<void> enable(capability cap, GLenum index) noexcept;

    static outcome<void> disable(capability cap, GLenum index) noexcept;

    static outcome<boolean> is_enabled(capability cap, GLenum index) noexcept;
#endif

#if defined(GL_CLIP_DISTANCE0)
    static outcome<void> enable(clip_plane cap) noexcept;

    static outcome<void> disable(clip_plane cap) noexcept;

    static outcome<boolean> is_enabled(clip_plane cap) noexcept;
#endif

#if defined(GL_ARB_compatibility)
    static outcome<void> enable_client_state(client_capability cap) noexcept;

    static outcome<void> disable_client_state(client_capability cap) noexcept;

    static outcome<boolean> is_enabled(client_capability cap) noexcept;

    static outcome<GLint> get_red_bits(void) noexcept;

    static outcome<GLint> get_green_bits(void) noexcept;

    static outcome<GLint> get_blue_bits(void) noexcept;

    static outcome<GLint> get_alpha_bits(void) noexcept;

    static outcome<GLint> get_depth_bits(void) noexcept;

    static outcome<GLint> get_stencil_bits(void) noexcept;

    static outcome<boolean> has_doublebuffer(void) noexcept;

    static outcome<boolean> is_stereo(void) noexcept;
#endif

#if defined(GL_VERSION_4_5)
    static outcome<graphics_reset_status> get_graphics_reset_status(
      void) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/capabilities.inl>

#endif // include guard
