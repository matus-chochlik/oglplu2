/**
 *  @file oglplus/oper/stencil_test.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_STENCIL_TEST_1509260923_HPP
#define OGLPLUS_OPER_STENCIL_TEST_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/gl_func.hpp"

namespace oglplus {
namespace oper {

struct stencil_func_args {
    compare_function _func;
    GLint _refv;
    GLuint _mask;

    stencil_func_args(void) = default;

    stencil_func_args(compare_function func,
      GLint refv = GLint(0),
      GLuint mask = ~GLuint(0)) noexcept
      : _func(func)
      , _refv(refv)
      , _mask(mask) {
    }

    compare_function func(void) const noexcept {
	return _func;
    }

    GLint ref(void) const noexcept {
	return _refv;
    }

    GLuint value_mask(void) const noexcept {
	return _mask;
    }
};

struct stencil_operations {
    stencil_operation _sfail;
    stencil_operation _dfail;
    stencil_operation _dpass;

    stencil_operations(void) = default;

    stencil_operations(stencil_operation sfail,
      stencil_operation dfail,
      stencil_operation dpass) noexcept
      : _sfail(sfail)
      , _dfail(dfail)
      , _dpass(dpass) {
    }

    stencil_operation stencil_fail(void) const noexcept {
	return _sfail;
    }

    stencil_operation depth_fail(void) const noexcept {
	return _dfail;
    }

    stencil_operation depth_pass(void) const noexcept {
	return _dpass;
    }
};

struct stencil_test_state {
    static outcome<void> stencil_func(compare_function func,
      GLint ref = GLint(0),
      GLuint mask = ~GLuint(0)) noexcept;

    static outcome<void> stencil_func(const stencil_func_args& fa) noexcept {
	return stencil_func(fa.func(), fa.ref(), fa.value_mask());
    }

    static outcome<void> stencil_func_separate(single_face face,
      compare_function func,
      GLint ref = GLint(0),
      GLuint mask = ~GLuint(0)) noexcept;

    static outcome<void> stencil_func_separate(
      single_face face, const stencil_func_args& fa) noexcept {
	return stencil_func_separate(
	  face, fa.func(), fa.ref(), fa.value_mask());
    }

    static outcome<void> stencil_op(stencil_operation sfail,
      stencil_operation dfail,
      stencil_operation dpass) noexcept;

    static outcome<void> stencil_op(const stencil_operations& so) noexcept {
	return stencil_op(so.stencil_fail(), so.depth_fail(), so.depth_pass());
    }

    static outcome<void> stencil_op_separate(single_face face,
      stencil_operation sfail,
      stencil_operation dfail,
      stencil_operation dpass) noexcept;

    static outcome<void> stencil_op_separate(
      single_face face, const stencil_operations& so) noexcept {
	return stencil_op_separate(
	  face, so.stencil_fail(), so.depth_fail(), so.depth_pass());
    }

    // TODO: getters
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/stencil_test.inl>

#endif // include guard
