/**
 *  @file oglplus/oper/buffer_masking.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_BUFFER_MASKING_1509260923_HPP
#define OGLPLUS_OPER_BUFFER_MASKING_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/boolean.hpp"

namespace oglplus {
namespace oper {

struct rgba_mask {
    GLboolean _v[4];

    rgba_mask(void) = default;

    rgba_mask(boolean r, boolean g, boolean b, boolean a) noexcept {
	_v[0] = GLboolean(r);
	_v[1] = GLboolean(g);
	_v[2] = GLboolean(b);
	_v[3] = GLboolean(a);
    }

    boolean red(void) const noexcept {
	return boolean{_v[0]};
    }

    boolean green(void) const noexcept {
	return boolean{_v[1]};
    }

    boolean blue(void) const noexcept {
	return boolean{_v[2]};
    }

    boolean alpha(void) const noexcept {
	return boolean{_v[3]};
    }
};

struct buffer_masking_state {
    static outcome<void> color_mask(
      boolean r, boolean g, boolean b, boolean a) noexcept;

    static outcome<void> color_mask(const rgba_mask& m) noexcept;

#if defined(GL_VERSION_3_0)
    static outcome<void> color_mask_i(
      GLuint buffer, boolean r, boolean g, boolean b, boolean a) noexcept;

    static outcome<void> color_mask_i(
      GLuint buffer, const rgba_mask& m) noexcept;
#endif

    static outcome<void> depth_mask(boolean mask) noexcept;

    static outcome<void> stencil_mask(GLuint mask) noexcept;

    static outcome<void> stencil_mask_separate(
      single_face face, GLuint mask) noexcept;

    static outcome<rgba_mask> get_color_writemask(void) noexcept;

    static outcome<boolean> get_depth_writemask(void) noexcept;

    static outcome<boolean> get_stencil_writemask(void) noexcept;

    static outcome<boolean> get_stencil_back_writemask(void) noexcept;

    // TODO: getters
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/buffer_masking.inl>

#endif // include guard
