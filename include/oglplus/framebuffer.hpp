/**
 *  @file oglplus/framebuffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_FRAMEBUFFER_1509260923_HPP
#define OGLPLUS_FRAMEBUFFER_1509260923_HPP

#include "enum/combined_types.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "framebuffer_name.hpp"
#include "object/owner.hpp"
#include "renderbuffer_name.hpp"
#include "texture_name.hpp"
#include "utils/boolean.hpp"
#include "utils/gl_func.hpp"

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) || \
  defined(GL_EXT_direct_state_access)
#define OGLPLUS_DSA_FRAMEBUFFER 1
#endif

namespace oglplus {

binding_query get_binding_query(framebuffer_target tgt) noexcept;

namespace oper {

struct framebuffer_ops {
    static outcome<void> bind_framebuffer(
      framebuffer_target target, framebuffer_name fbo) noexcept;

    static outcome<framebuffer_name> framebuffer_binding(
      framebuffer_target target) noexcept;

    static outcome<framebuffer_status> check_framebuffer_status(
      framebuffer_target target) noexcept;

    static outcome<bool> is_framebuffer_complete(
      framebuffer_target target) noexcept;

#ifdef OGLPLUS_DSA_FRAMEBUFFER
    static outcome<framebuffer_status> check_framebuffer_status(
      framebuffer_name, framebuffer_target target) noexcept;

    static outcome<bool> is_framebuffer_complete(
      framebuffer_name fb, framebuffer_target target) noexcept;
#endif

#if defined(GL_VERSION_4_3)
    static outcome<void> framebuffer_parameter_i(
      framebuffer_target fb_target,
      framebuffer_parameter param,
      GLint value) noexcept;
#endif

#if defined(GL_VERSION_4_5)
    static outcome<void> framebuffer_parameter_i(
      framebuffer_name fbo, framebuffer_parameter param, GLint value) noexcept;
#endif

    static outcome<void> framebuffer_renderbuffer(
      framebuffer_target fb_target,
      framebuffer_attachment fb_attch,
      renderbuffer_target rb_target,
      renderbuffer_name rbo) noexcept;

#ifdef OGLPLUS_DSA_FRAMEBUFFER
    static outcome<void> framebuffer_renderbuffer(
      framebuffer_name fbo,
      framebuffer_attachment fb_attch,
      renderbuffer_target rb_target,
      renderbuffer_name rbo) noexcept;
#endif

#if defined(GL_VERSION_3_0)
    static outcome<void> framebuffer_texture_1d(
      framebuffer_target fb_target,
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept;

#if defined(GL_EXT_direct_state_access)
    static outcome<void> framebuffer_texture_1d(
      framebuffer_name fbo,
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept;
#endif
#endif // GL_VERSION_3_0

    static outcome<void> framebuffer_texture_2d(
      framebuffer_target fb_target,
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept;

#if defined(GL_EXT_direct_state_access)
    static outcome<void> framebuffer_texture_2d(
      framebuffer_name fbo,
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept;
#endif

#if defined(GL_VERSION_3_0)
    static outcome<void> framebuffer_texture_3d(
      framebuffer_target fb_target,
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level,
      GLint layer) noexcept;

#if defined(GL_EXT_direct_state_access)
    static outcome<void> framebuffer_texture_3d(
      framebuffer_name fbo,
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level,
      GLint layer) noexcept;
#endif
#endif // GL_VERSION_3_0

#if defined(GL_VERSION_3_0)
    static outcome<void> framebuffer_texture_layer(
      framebuffer_target fb_target,
      framebuffer_attachment fb_attch,
      texture_name tex,
      GLint level,
      GLint layer) noexcept;

#ifdef OGLPLUS_DSA_FRAMEBUFFER
    static outcome<void> framebuffer_texture_layer(
      framebuffer_name fbo,
      framebuffer_attachment fb_attch,
      texture_name tex,
      GLint level,
      GLint layer) noexcept;
#endif
#endif

#if defined(GL_VERSION_3_2)
    static outcome<void> framebuffer_texture(
      framebuffer_target fb_target,
      framebuffer_attachment fb_attch,
      texture_name tex,
      GLint level) noexcept;

#ifdef OGLPLUS_DSA_FRAMEBUFFER
    static outcome<void> framebuffer_texture(
      framebuffer_name fbo,
      framebuffer_attachment fb_attch,
      texture_name tex,
      GLint level) noexcept;
#endif
#endif // GL_VERSION_3_2

#if defined(GL_VERSION_3_0)
    static outcome<void> draw_buffer(color_buffer buf) noexcept;

    static outcome<void> draw_buffers(enum_span<color_buffer> bufs) noexcept;

#ifdef OGLPLUS_DSA_FRAMEBUFFER
    static outcome<void> framebuffer_draw_buffer(
      framebuffer_name fbo, framebuffer_color_attachment buf) noexcept;
    // TODO GL_NONE

    static outcome<void> framebuffer_draw_buffers(
      framebuffer_name fbo, enum_span<framebuffer_attachment> bufs) noexcept;
#endif
#endif // GL_VERSION_3_0

    static outcome<void> read_buffer(color_buffer buf) noexcept;

#ifdef OGLPLUS_DSA_FRAMEBUFFER
    static outcome<void> framebuffer_read_buffer(
      framebuffer_name fbo, framebuffer_color_attachment buf) noexcept;
    // TODO GL_NONE
#endif

#if defined(GL_VERSION_3_0)
    static outcome<void> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLint> values) noexcept;

    static outcome<void> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLuint> values) noexcept;

    static outcome<void> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLfloat> values) noexcept;

    static outcome<void> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      GLfloat depth,
      GLint stencil) noexcept;

    static outcome<void> blit_framebuffer(
      GLint srcX0,
      GLint srcY0,
      GLint srcX1,
      GLint srcY1,
      GLint dstX0,
      GLint dstY0,
      GLint dstX1,
      GLint dstY1,
      enum_bitfield<buffer_select_bits> mask,
      blit_filter filter) noexcept;
#endif

#if defined(GL_VERSION_4_3)
    static outcome<void> invalidate_framebuffer_data(
      framebuffer_target tgt,
      enum_span<framebuffer_attachment> attachments) noexcept;

    static outcome<void> invalidate_framebuffer_sub_data(
      framebuffer_target tgt,
      enum_span<framebuffer_attachment> attachments,
      GLint x,
      GLint y,
      GLint width,
      GLint height) noexcept;
#endif

#if defined(GL_VERSION_4_5)
    static outcome<void> clear_framebuffer(
      framebuffer_name fbo,
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLint> values) noexcept;

    static outcome<void> clear_framebuffer(
      framebuffer_name fbo,
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLuint> values) noexcept;

    static outcome<void> clear_framebuffer(
      framebuffer_name fbo,
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLfloat> values) noexcept;

    static outcome<void> clear_framebuffer(
      framebuffer_name fbo,
      framebuffer_buffer buf,
      GLint draw_buffer,
      GLfloat depth,
      GLint stencil) noexcept;

    static outcome<void> invalidate_framebuffer_data(
      framebuffer_name fbo,
      enum_span<framebuffer_attachment> attachments) noexcept;

    static outcome<void> invalidate_framebuffer_sub_data(
      framebuffer_name fbo,
      enum_span<framebuffer_attachment> attachments,
      GLint x,
      GLint y,
      GLint width,
      GLint height) noexcept;

    static outcome<void> blit_framebuffer(
      framebuffer_name srcfbo,
      framebuffer_name dstfbo,
      GLint srcX0,
      GLint srcY0,
      GLint srcX1,
      GLint srcY1,
      GLint dstX0,
      GLint dstY0,
      GLint dstX1,
      GLint dstY1,
      enum_bitfield<buffer_select_bits> mask,
      blit_filter filter) noexcept;
#endif
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::framebuffer, Derived, Base> : Base {
private:
    Derived& _self() noexcept {
        return *static_cast<Derived*>(this);
    }

    typedef oper::framebuffer_ops _ops;

protected:
    using Base::Base;

public:
    outcome<Derived&> renderbuffer(
      framebuffer_attachment fb_attch,
      renderbuffer_target rb_target,
      renderbuffer_name rbo) noexcept {
        return {_ops::framebuffer_renderbuffer(*this, fb_attch, rb_target, rbo),
                _self()};
    }

#if defined(GL_VERSION_3_2)
    outcome<Derived&> texture(
      framebuffer_attachment fb_attch, texture_name tex, GLint level) noexcept {
        return {_ops::framebuffer_texture(*this, fb_attch, tex, level),
                _self()};
    }
#endif
};

template <>
struct object_binding<tag::framebuffer>
  : obj_member_ops<
      tag::framebuffer,
      object_binding<tag::framebuffer>,
      framebuffer_target> {
    using obj_member_ops<
      tag::framebuffer,
      object_binding<tag::framebuffer>,
      framebuffer_target>::obj_member_ops;

    typedef oper::framebuffer_ops _ops;

    outcome<framebuffer_status> check_status(void) noexcept {
        return _ops::check_framebuffer_status(*this);
    }

    outcome<bool> is_complete(void) noexcept {
        return _ops::is_framebuffer_complete(*this);
    }

#if defined(GL_VERSION_3_0)
    outcome<object_binding&> texture_1d(
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept {
        return {
          _ops::framebuffer_texture_1d(*this, fb_attch, tx_target, tex, level),
          *this};
    }
#endif

    outcome<object_binding&> texture_2d(
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept {
        return {
          _ops::framebuffer_texture_2d(*this, fb_attch, tx_target, tex, level),
          *this};
    }

#if defined(GL_VERSION_3_0)
    outcome<object_binding&> texture_3d(
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level,
      GLint layer) noexcept {
        return {_ops::framebuffer_texture_3d(
                  *this, fb_attch, tx_target, tex, level, layer),
                *this};
    }
#endif
};

#ifdef OGLPLUS_DSA_FRAMEBUFFER
template <>
struct obj_dsa_ops<tag::framebuffer>
  : obj_member_ops<
      tag::framebuffer,
      obj_dsa_ops<tag::framebuffer>,
      obj_zero_dsa_ops<tag::framebuffer>> {
    using obj_member_ops<
      tag::framebuffer,
      obj_dsa_ops<tag::framebuffer>,
      obj_zero_dsa_ops<tag::framebuffer>>::obj_member_ops;

    typedef oper::framebuffer_ops _ops;

    outcome<framebuffer_status> check_status(
      framebuffer_target target) noexcept {
        return _ops::check_framebuffer_status(*this, target);
    }

    outcome<bool> is_complete(framebuffer_target target) noexcept {
        return _ops::is_framebuffer_complete(*this, target);
    }

#if defined(GL_EXT_direct_state_access)
    outcome<obj_dsa_ops&> texture_1d(
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept {
        return {
          _ops::framebuffer_texture_1d(*this, fb_attch, tx_target, tex, level),
          *this};
    }

    outcome<obj_dsa_ops&> texture_2d(
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level) noexcept {
        return {
          _ops::framebuffer_texture_2d(*this, fb_attch, tx_target, tex, level),
          *this};
    }

    outcome<obj_dsa_ops&> texture_3d(
      framebuffer_attachment fb_attch,
      texture_target tx_target,
      texture_name tex,
      GLint level,
      GLint layer) noexcept {
        return {_ops::framebuffer_texture_3d(
                  *this, fb_attch, tx_target, tex, level, layer),
                *this};
    }
#endif

    outcome<obj_dsa_ops&> draw_buffer(
      framebuffer_color_attachment buf) noexcept {
        return {_ops::framebuffer_draw_buffer(*this, buf), *this};
    }

    outcome<obj_dsa_ops&> read_buffer(
      framebuffer_color_attachment buf) noexcept {
        return {_ops::framebuffer_read_buffer(*this, buf), *this};
    }

#if defined(GL_VERSION_4_5)
    outcome<obj_dsa_ops&> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLint> values) noexcept {
        return {_ops::clear_framebuffer(*this, buf, draw_buffer, values),
                *this};
    }

    outcome<obj_dsa_ops&> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLuint> values) noexcept {
        return {_ops::clear_framebuffer(*this, buf, draw_buffer, values),
                *this};
    }

    outcome<obj_dsa_ops&> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      span<const GLfloat> values) noexcept {
        return {_ops::clear_framebuffer(*this, buf, draw_buffer, values),
                *this};
    }

    outcome<obj_dsa_ops&> clear_buffer(
      framebuffer_buffer buf,
      GLint draw_buffer,
      GLfloat depth,
      GLint stencil) noexcept {
        return {
          _ops::clear_framebuffer(*this, buf, draw_buffer, depth, stencil),
          *this};
    }

    outcome<obj_dsa_ops&> invalidate_data(
      enum_span<framebuffer_attachment> attchs) noexcept {
        return {_ops::invalidate_framebuffer_data(*this, attchs), *this};
    }

    outcome<obj_dsa_ops&> invalidate_sub_data(
      enum_span<framebuffer_attachment> attchs,
      GLint x,
      GLint y,
      GLint width,
      GLint height) noexcept {
        return {_ops::invalidate_framebuffer_sub_data(
                  *this, attchs, x, y, width, height),
                *this};
    }
#endif
};
#endif

template <>
struct obj_gen_del_ops<tag::framebuffer> {
    static deferred_error_handler _gen(span<GLuint> names) noexcept;

#if defined(GL_VERSION_4_5)
    static deferred_error_handler _create(span<GLuint> names) noexcept;
#endif

    static deferred_error_handler _delete(span<GLuint> names) noexcept;

    static outcome<boolean> _is_a(GLuint name) noexcept;
};

using framebuffer = object_owner<tag::framebuffer>;
using bound_framebuffer = object_binding<tag::framebuffer>;
template <std::size_t N>
using framebuffer_array = object_array_owner<tag::framebuffer, N>;

static const object_zero_and_ops<tag::framebuffer> default_framebuffer = {};

} // namespace oglplus

#include <oglplus/framebuffer.inl>

#ifdef OGLPLUS_DSA_FRAMEBUFFER
#undef OGLPLUS_DSA_FRAMEBUFFER
#endif

#endif // include guard
