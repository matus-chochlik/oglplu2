/**
 *  @file oglplus/utils/boolean.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_BOOLEAN_HPP
#define OGLPLUS_UTILS_BOOLEAN_HPP

#include "../enum/types.hpp"
#include <eagine/assert.hpp>

namespace oglplus {

struct boolean {
    GLboolean _v{GL_FALSE};

    constexpr boolean() noexcept = default;

    explicit inline boolean(GLboolean v) noexcept
      : _v(v) {
        EAGINE_ASSERT((_v == GL_TRUE) || (_v == GL_FALSE));
    }

    constexpr inline boolean(bool v) noexcept
      : _v(v ? GL_TRUE : GL_FALSE) {
    }

    constexpr inline boolean(true_false v) noexcept
      : _v(GLboolean(v)) {
    }

    explicit constexpr inline operator bool() const noexcept {
        return _v == GL_TRUE;
    }

    constexpr inline bool operator!() const noexcept {
        return _v == GL_FALSE;
    }

    constexpr inline operator GLboolean() const noexcept {
        return _v;
    }
};

} // namespace oglplus

#endif // OGLPLUS_UTILS_BOOLEAN_HPP
