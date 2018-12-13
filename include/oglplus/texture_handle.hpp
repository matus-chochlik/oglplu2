/**
 *  @file oglplus/texture_handle.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXTURE_HANDLE_1509260923_HPP
#define OGLPLUS_TEXTURE_HANDLE_1509260923_HPP

#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "object/owner.hpp"
#include "sampler_name.hpp"
#include "texture_name.hpp"
#include "utils/gl_func.hpp"

namespace oglplus {

template <unsigned Tag>
struct texture_handle_tpl {
    GLuint64 _value;
};

template <unsigned Tag>
static inline GLuint64 get_raw_handle(texture_handle_tpl<Tag> tht) noexcept {
    return tht._value;
}

#if defined(GL_ARB_bindless_texture)
using texture_handle_arb = texture_handle_tpl<0>;
#endif

#if defined(GL_NV_bindless_texture)
using texture_handle_nv = texture_handle_tpl<1>;
#endif

#if defined(GL_ARB_bindless_texture)
using texture_handle = texture_handle_arb;
#elif defined(GL_NV_bindless_texture)
using texture_handle = texture_handle_nv;
#endif

namespace oper {

struct texture_handle_ops {
#if defined(GL_ARB_bindless_texture)
    static outcome<texture_handle_arb> get_texture_handle_arb(
      texture_name tex) noexcept;

    static outcome<texture_handle_arb> get_texture_sampler_handle_arb(
      texture_name tex, sampler_name sam) noexcept;
#endif

#if defined(GL_NV_bindless_texture)
    static outcome<texture_handle_nv> get_texture_handle_nv(
      texture_name tex) noexcept;

    static outcome<texture_handle_nv> get_texture_sampler_handle_nv(
      texture_name tex, sampler_name sam) noexcept;
#endif

#if defined(GL_ARB_bindless_texture)
    static outcome<texture_handle> get_texture_handle(
      texture_name tex) noexcept {
        return get_texture_handle_arb(tex);
    }

    static outcome<texture_handle> get_texture_sampler_handle(
      texture_name tex, sampler_name sam) noexcept {
        return get_texture_sampler_handle_arb(tex, sam);
    }
#elif defined(GL_NV_bindless_texture)
    static outcome<texture_handle> get_texture_handle(
      texture_name tex) noexcept {
        return get_texture_handle_nv(tex);
    }

    static outcome<texture_handle> get_texture_sampler_handle(
      texture_name tex, sampler_name sam) noexcept {
        return get_texture_sampler_handle_nv(tex, sam);
    }
#endif

#if defined(GL_ARB_bindless_texture)
    static outcome<void> make_texture_handle_resident(
      texture_handle_arb th) noexcept;
#endif

#if defined(GL_NV_bindless_texture)
    static outcome<void> make_texture_handle_resident(
      texture_handle_nv th) noexcept;
#endif

#if defined(GL_ARB_bindless_texture)
    static outcome<void> make_texture_handle_non_resident(
      texture_handle_arb th) noexcept;
#endif

#if defined(GL_NV_bindless_texture)
    static outcome<void> make_texture_handle_non_resident(
      texture_handle_nv th) noexcept;
#endif

#if defined(GL_ARB_bindless_texture)
    static outcome<boolean> is_texture_handle_resident(
      texture_handle_arb th) noexcept;
#endif

#if defined(GL_NV_bindless_texture)
    static outcome<boolean> is_texture_handle_resident(
      texture_handle_nv th) noexcept;
#endif
};

} // namespace oper

} // namespace oglplus

#include <oglplus/texture_handle.inl>

#endif // include guard
