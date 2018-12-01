/**
 *  @file oglplus/prog_var/location.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROG_VAR_LOCATION_1509260923_HPP
#define OGLPLUS_PROG_VAR_LOCATION_1509260923_HPP

#include "../program_name.hpp"
#include "fwd.hpp"

namespace oglplus {

template <typename VarTag>
class prog_var_loc<VarTag, false> {
protected:
    GLint _loc;

    static constexpr inline GLint _invalid_loc(void) noexcept {
        return -1;
    }

public:
    typedef VarTag tag;

    constexpr prog_var_loc(void) noexcept
      : _loc(_invalid_loc()) {
    }

    constexpr explicit prog_var_loc(GLint loc) noexcept
      : _loc(loc) {
    }

    constexpr GLint location(void) const noexcept {
        return _loc;
    }

    GLuint index(void) const noexcept {
        if(_loc < 0) {
            return GL_INVALID_INDEX;
        }
        return GLuint(_loc);
    }

    constexpr bool is_active(void) const noexcept {
        return _loc >= 0;
    }

    explicit constexpr operator bool(void) const noexcept {
        return is_active();
    }

    constexpr bool operator!(void) const noexcept {
        return !is_active();
    }

    friend constexpr bool operator==(prog_var_loc a, prog_var_loc b) noexcept {
        return a._loc == b._loc;
    }

    friend constexpr bool operator!=(prog_var_loc a, prog_var_loc b) noexcept {
        return a._loc != b._loc;
    }

    friend constexpr bool operator<(prog_var_loc a, prog_var_loc b) noexcept {
        return a._loc < b._loc;
    }
};

} // namespace oglplus

#endif // include guard
